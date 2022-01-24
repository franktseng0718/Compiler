#include "semantic/cg.hpp"
#include "AST/assignment.hpp"
#include "AST/ast.hpp"
#include "AST/binary_operator.hpp"
#include "AST/compound_statement.hpp"
#include "AST/constant_value.hpp"
#include "AST/declaration.hpp"
#include "AST/for.hpp"
#include "AST/function.hpp"
#include "AST/function_call.hpp"
#include "AST/if.hpp"
#include "AST/print.hpp"
#include "AST/program.hpp"
#include "AST/read.hpp"
#include "AST/return.hpp"
#include "AST/unary_operator.hpp"
#include "AST/variable.hpp"
#include "AST/variable_reference.hpp"
#include "AST/while.hpp"
#include "semantic/DumpSymbolTable.hpp"
#include "semantic/ErrorMsg.hpp"
#include "semantic/SymbolTable.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

//
// TODO: implementations of visit(xxxxNode *)
//
Codegenerator::Codegenerator(string _filename, FILE *_fp) {
    this->level = 0;

    _filename = _filename.substr(0, _filename.length() - 2);
    for (int i = _filename.length() - 1; i >= 0; i--) {
        if (_filename[i] == '/') {
            _filename = _filename.substr(i + 1, _filename.length() - i);
            break;
        }
    }
    this->filename = _filename;
    this->fp = _fp;

    
}
void Codegenerator::visit(ProgramNode *m) {
    string first;
    first+=".file \""+filename+".p"+"\"";
    output.push_back(first);
    output.push_back(".option nopic");

    if (m->declaration_node_list != nullptr)
        for (uint i = 0; i < m->declaration_node_list->size(); i++) {
            (*(m->declaration_node_list))[i]->accept(*this);
        }

    if (m->function_node_list != nullptr)
        for (uint i = 0; i < m->function_node_list->size(); i++) {
            (*(m->function_node_list))[i]->accept(*this);
        }

    if (m->compound_statement_node != nullptr)
        m->compound_statement_node->accept(*this);

    
}

void Codegenerator::visit(DeclarationNode *m) {
    // Visit Child Nodes

    if (m->variables_node_list != nullptr)
        for (uint i = 0; i < m->variables_node_list->size(); i++) {
            (*(m->variables_node_list))[i]->accept(*this);
        }
}

void Codegenerator::visit(VariableNode *m) {
    if(level==0){
    	if(m->constant_value_node==nullptr){
		output.push_back(".bss");
		string push;
    		push+=m->variable_name+":";	
    		output.push_back(push);
		output.push_back(".word 0");
	}
	else{
		output.push_back(".text");
		string push;
		push+=m->variable_name+":";
		output.push_back(push);
		Attribute a(*(m->type));
		push.clear();
		push+=".word "+to_string(a.value_of_constant.int_literal);
		output.push_back(push);
	}
      
    }
    else{
       if(in_func){
             int num=-20-4*var_count;
	     string push;
             if(var_count<8)
	     push+="sw a"+to_string(var_count)+", "+to_string(num)+"(s0)";
             else if(var_count>7){
		int temp=var_count-8+2;
		push+="sw s"+to_string(temp)+", "+to_string(num)+"(s0)";
	     }      
             output.push_back(push);
             symbolentry a(m->variable_name,level,var_count);
             var_count++;
             table.push_back(a);
	     return;
       }
       if(m->constant_value_node!=nullptr){
             
             Attribute b(*(m->type));
             int num=-20-4*var_count;
             string push;
             push+="li t0, "+to_string(b.value_of_constant.int_literal);
             output.push_back(push);
             push.clear();
             push+="sw t0, "+to_string(num)+"(s0)";
             output.push_back(push);
             symbolentry a(m->variable_name,level,var_count);
             table.push_back(a);
             var_count++;
	}
        else{
	     symbolentry a(m->variable_name,level,var_count);
	     table.push_back(a);
             var_count++;
        }
    } 
    
}

void Codegenerator::visit(ConstantValueNode *m) { // EXPRESSION
    string push;
    if(reg<=6)
    push+="li t"+to_string(reg)+", "+to_string(m->constant_value->int_literal);
    else
	push+="li s"+to_string(reg-5)+", "+to_string(m->constant_value->int_literal);
    output.push_back(push);
}

void Codegenerator::visit(FunctionNode *m) {
    // Part 1:
    // Redeclare Check (current_scope still is global)
    var_count=0;
    table.clear();
    output.push_back(".text");
    output.push_back(".align 2");
    string push;
    push+=".global "+m->function_name;
    output.push_back(push);
    push.clear();
    push+=".type "+m->function_name+", @function";
    output.push_back(push);
    push.clear();
    push+=m->function_name+":";
    output.push_back(push);
    output.push_back("addi sp, sp, -64");
    output.push_back("sd ra, 56(sp)");
    output.push_back("sd s0, 48(sp)");
    output.push_back("addi s0, sp, 64");
    
    // Part 2:
    // Push Scope
    level++;
    if (m->parameters != nullptr)
        for (uint i = 0; i < m->parameters->size(); i++){
            in_func=true;
            (*(m->parameters))[i]->node->accept(*this);
            in_func=false;        
        }
    

    if (m->body != nullptr)
        m->body->accept(*this);

    output.push_back("ld ra, 56(sp)");
    output.push_back("ld s0, 48(sp)");
    output.push_back("addi sp, sp, 64");
    output.push_back("jr ra");
    push.clear();
    push+=".size "+m->function_name+", .-"+m->function_name;
    output.push_back(push);   

    
    level--;
}

void Codegenerator::visit(CompoundStatementNode *m) { // STATEMENT
    if(level==0){
     	var_count=0;
        table.clear();
	output.push_back(".text");
	output.push_back(".align 2");
	output.push_back(".global main");
        output.push_back(".type main, @function");
	output.push_back("main:");
	output.push_back("addi sp, sp, -64");
	output.push_back("sd ra, 56(sp)");
	output.push_back("sd s0, 48(sp)");
	output.push_back("addi s0, sp, 64");

    }
    level++; 
    if (m->declaration_node_list != nullptr)
        for (uint i = 0; i < m->declaration_node_list->size(); i++) {
            (*(m->declaration_node_list))[i]->accept(*this);
        }

    if (m->statement_node_list != nullptr)
        for (uint i = 0; i < m->statement_node_list->size(); i++) {
            (*(m->statement_node_list))[i]->accept(*this);
        }
    
    
    for(int i=0;i<table.size();i++){
    	if(table[i].level==level)table.erase(table.begin()+i);
    }
    level--;
    if(level==0){
    	output.push_back("ld ra, 56(sp)");
	output.push_back("ld s0, 48(sp)");
	output.push_back("addi sp, sp, 64");
	output.push_back("jr ra");
	output.push_back(".size main, .-main");
    }
    
}

void Codegenerator::visit(AssignmentNode *m) { // STATEMENT
    // Visit Child Node
    reg=0;
    if (m->expression_node != nullptr)
        m->expression_node->accept(*this);

    ass=true;
    if (m->variable_reference_node != nullptr)
        m->variable_reference_node->accept(*this);
    ass=false;
    

    string push;
    if(ass_addr==0){
    	push+="la t1, "+var_name;
        output.push_back(push);
        push.clear();
        push+="sw t0, 0(t1)";
        output.push_back(push);
    }
    else{
    	push+="sw t0, "+to_string(ass_addr)+"(s0)";
        output.push_back(push);
    }
    

    

    

    
   
         
}

void Codegenerator::visit(PrintNode *m) { // STATEMENT
    // Visit Child Node
    reg=0;
    if (m->expression_node != nullptr)
        m->expression_node->accept(*this);

    string push;
    output.push_back("mv a0, t0");
    output.push_back("jal ra, print");
}

void Codegenerator::visit(ReadNode *m) { // STATEMENT
   
    ass=true;
    if (m->variable_reference_node != nullptr)
        m->variable_reference_node->accept(*this);
    ass=false;
    output.push_back("jal ra, read");
    string push;
    if(ass_addr==0){
        push+="la t0, "+var_name;
        output.push_back(push);
        push.clear();
        push+="sw a0, 0(t0)";
        output.push_back(push);
    }
    else{
        push+="sw a0, "+to_string(ass_addr)+"(s0)";
        output.push_back(push);
    }

    

    
        
}

void Codegenerator::visit(VariableReferenceNode *m) { // EXPRESSION
    if(ass){
     	for(int i=table.size()-1;i>=0;i--){
     		if(table[i].name==m->variable_name&&table[i].level<=level){
            		ass_addr=-20-table[i].var_count*4;
			var_name=m->variable_name;
 			return;
        	}
     	}
        ass_addr=0;
	var_name=m->variable_name;
	return;
    }

    else{
       for(int i=table.size()-1;i>=0;i--){
               if(table[i].name==m->variable_name&&table[i].level<=level){
			ass_addr=-20-table[i].var_count*4;
                	string push;
			if(reg<=6)
			push+="lw t"+to_string(reg)+", "+to_string(ass_addr)+"(s0)";
			else
				push+="lw s"+to_string(reg-5)+", "+to_string(ass_addr)+"(s0)";
			output.push_back(push);
			return;
		}
       	
    	}
	ass_addr=0;
        if(reg<6){
	string push;
	push+="la t"+to_string(reg)+", "+m->variable_name;
	output.push_back(push);
	push.clear();
	push+="lw t"+to_string(reg+1)+", 0(t"+to_string(reg)+")";
	output.push_back(push);
	push.clear();
	push+="mv t"+to_string(reg)+", t"+to_string(reg+1);
	output.push_back(push);
	}
	else if(reg==6){
		string push;
        push+="la t"+to_string(reg)+", "+m->variable_name;
        output.push_back(push);
        push.clear();
        push+="lw s"+to_string(reg+1-5)+", 0(t6)";
        output.push_back(push);
        push.clear();
        push+="mv t"+to_string(reg)+", s"+to_string(reg+1-5);
        output.push_back(push);
	}
	else{
		string push;
        push+="la s"+to_string(reg-5)+", "+m->variable_name;
        output.push_back(push);
        push.clear();
        push+="lw s"+to_string(reg+1-5)+", 0(s"+to_string(reg-5)+")";
        output.push_back(push);
        push.clear();
        push+="mv s"+to_string(reg-5)+", s"+to_string(reg+1-5);
        output.push_back(push);
	}
    }

 

    
                    
   
}

void Codegenerator::visit(BinaryOperatorNode *m) { // EXPRESSION
    // Visit Child Node
    int regi=reg;
    string push;
    if (m->left_operand != nullptr)
        m->left_operand->accept(*this);
    output.push_back("sw t0, 0(sp)");
    output.push_back("addi sp, sp, -4"); 
    
    if (m->right_operand != nullptr)
        m->right_operand->accept(*this);

    
        switch (m->op) {
        case OP_OR:
        case OP_AND:
        case OP_NOT:
        

        case OP_LESS:
		op="bge";
		output.push_back("addi sp, sp, 4");
		output.push_back("mv t1, t0");
		output.push_back("lw t0, 0(sp)");
		break;
        case OP_LESS_OR_EQUAL:
		op="bgt";
		output.push_back("addi sp, sp, 4");
                output.push_back("mv t1, t0");                                                                                          output.push_back("lw t0, 0(sp)");                                                                      
		break;
        case OP_EQUAL:
		op="bne";
		output.push_back("addi sp, sp, 4");
                output.push_back("mv t1, t0");                                                                                          output.push_back("lw t0, 0(sp)");                                                                                       break;
		
        case OP_GREATER:
		op="ble";
		output.push_back("addi sp, sp, 4");
                output.push_back("mv t1, t0");                                                                                          output.push_back("lw t0, 0(sp)");                                                                                       break;
        case OP_GREATER_OR_EQUAL:
		op="blt";
		output.push_back("addi sp, sp, 4");
                output.push_back("mv t1, t0");                                                                                          output.push_back("lw t0, 0(sp)");                                                                                       break;
        case OP_NOT_EQUAL:
		op="beq";
		output.push_back("addi sp, sp, 4");
                output.push_back("mv t1, t0");                                                                                          output.push_back("lw t0, 0(sp)");                                                                                       break;
           

        case OP_PLUS: // Special Case
                output.push_back("addi sp, sp, 4");
                output.push_back("lw t1, 0(sp)");
                output.push_back("addw t0, t1, t0");
                break;        
	    
            // Forward Check
        case OP_MINUS:
		  output.push_back("addi sp, sp, 4");
                  output.push_back("lw t1, 0(sp)");
                output.push_back("subw t0, t1, t0");
                break;        
               
        case OP_MULTIPLY:
		
                
		output.push_back("addi sp, sp, 4");
                                                                                                        
		output.push_back("lw t1, 0(sp)");
                output.push_back("mulw t0, t1, t0");
                break;
	case OP_DIVIDE:
		 output.push_back("addi sp, sp, 4");
                output.push_back("lw t1, 0(sp)");
                output.push_back("divw t0, t1, t0");
	        break;
        case OP_MOD:
		output.push_back("addi sp, sp, 4");
                output.push_back("lw t1, 0(sp)");
                output.push_back("remw t0, t1, t0");
                break;
 		              
              

        default:
            break;
        }
	
    
}

void Codegenerator::visit(UnaryOperatorNode *m) { // EXPRESSION
    
    if (m->operand != nullptr)
        m->operand->accept(*this);
   

   string push;
        switch (m->op) {
        case OP_NOT:
 

        case OP_MINUS:
            	if(reg<7){
                	push+="li t"+to_string(reg+1)+", "+to_string(-1);
			output.push_back(push);
			push.clear();
			push+="mulw t"+to_string(reg)+", t"+to_string(reg)+", t"+to_string(reg+1);
			output.push_back(push);
			break;
		}                                            	
		else if(reg>=7){
		push+="muli s"+to_string(reg-5)+", s"+to_string(reg-5)+", "+to_string(-1);
		output.push_back(push);                                                                                                 push.clear();
                break;
		}

        default:
            break;
	}
       
}

void Codegenerator::visit(IfNode *m) { // STATEMENT
    
    if (m->condition != nullptr)
        m->condition->accept(*this);
    string push;
    push+=op+" t0, t1, L"+to_string(loop_cnt+1);
    output.push_back(push);
    push.clear();
    push+="L"+to_string(loop_cnt)+":";
    output.push_back(push);
    int lo_cnt=loop_cnt;
    loop_cnt=loop_cnt+3;	
    if (m->body != nullptr)
        for (uint i = 0; i < m->body->size(); i++)
            (*(m->body))[i]->accept(*this);
    push.clear();
    push+="j L"+to_string(lo_cnt+2);
    output.push_back(push);
    push.clear();
    push+="L"+to_string(lo_cnt+1)+":";
    output.push_back(push);
    if (m->body_of_else != nullptr)
        for (uint i = 0; i < m->body_of_else->size(); i++)
            (*(m->body_of_else))[i]->accept(*this);
    
    push.clear();
    push+="L"+to_string(lo_cnt+2)+":";
    output.push_back(push);
    
   
}

void Codegenerator::visit(WhileNode *m) { // STATEMENT
    int lo_cnt=loop_cnt;
    loop_cnt+=2;
    string push;
    push+="j L"+to_string(lo_cnt+1);
    output.push_back(push);
    push.clear();
    push+="L"+to_string(lo_cnt)+":";
    output.push_back(push);

    if (m->body != nullptr)
        for (uint i = 0; i < m->body->size(); i++)
            (*(m->body))[i]->accept(*this);
    push.clear();
    push+="L"+to_string(lo_cnt+1)+":";
    output.push_back(push);
    reg=0;
    if (m->condition != nullptr)
        m->condition->accept(*this);
    push.clear();
    if(op=="ble")op="bgt";
    else if(op=="blt")op="bge";
    else if(op=="beq")op="bne";
    else if(op=="bne")op="beq";
    else if(op=="bgt")op="ble";
    else if(op=="bge")op="blt";
    push+=op+" t0, t1, L"+to_string(lo_cnt);
    output.push_back(push);
}

void Codegenerator::visit(ForNode *m) { // STATEMENT
    
    level++;
    if (m->loop_variable_declaration != nullptr)
        m->loop_variable_declaration->accept(*this);
   
    if (m->initial_statement != nullptr)
        m->initial_statement->accept(*this);
    int addr=ass_addr;
    int lo_cnt=loop_cnt;
    loop_cnt+=2;
    string push;
    push+="j L"+to_string(lo_cnt+1);
    output.push_back(push);
    push.clear();
    push+="L"+to_string(lo_cnt)+":";
    output.push_back(push);
    
   
    

    
    
    if (m->body != nullptr)
        for (uint i = 0; i < m->body->size(); i++)
            (*(m->body))[i]->accept(*this);
    push.clear();
    push+="L"+to_string(lo_cnt+1)+":";
    output.push_back(push);
    
    reg=1;
    if(m->condition != nullptr)
        m->condition->accept(*this);
    push.clear();
    push+="lw t0, "+to_string(addr)+"(s0)";
    output.push_back(push);
    push.clear();
    output.push_back("addi t2, t0, 1");
    output.push_back("mv t0, t2");
    push+="sw t0, "+to_string(addr)+"(s0)";
    output.push_back(push);
    push.clear();
    push+="ble t0, t1, L"+to_string(lo_cnt);
    output.push_back(push);
    for(int i=0;i<table.size();i++){
        if(table[i].level==level)table.erase(table.begin()+i);
    }
    level--;
}

void Codegenerator::visit(ReturnNode *m) { // STATEMENT
    reg=0;
    if (m->return_value != nullptr)
        m->return_value->accept(*this);
    output.push_back("mv a0, t0");

    
       
}

void Codegenerator::visit(FunctionCallNode *m) { // EXPRESSION //STATEMENT
    
    if (m->arguments != nullptr)
        for (int i =0; i < m->arguments->size(); i++){
	    
            (*(m->arguments))[i]->accept(*this);
	    string push;
	    push+="sw t"+to_string(reg)+", 0(sp)";
	    output.push_back(push);
	    output.push_back("addi sp, sp, -4");
	}
    if(m->arguments!=nullptr)
	for(int i=m->arguments->size()-1;i>=0;i--){
    	    string push;
	    output.push_back("addi sp, sp, 4");
            if(i<8)push+="lw a"+to_string(i)+", 0(sp)";
            else push+="lw s"+to_string(i-6)+", 0(sp)";
            output.push_back(push);
	}
    string push;
    push+="jal ra, "+m->function_name;
    output.push_back(push);
    push.clear();
    if(reg<=6)
    push+="mv t"+to_string(reg)+", a0";
    else
    push+="mv s"+to_string(reg-5)+", a0";
    output.push_back(push);
    
        

        
                       
         
}
