#include "AST/ASTDumper.hpp"
#include "AST/program.hpp"
#include "AST/declaration.hpp"
#include "AST/variable.hpp"
#include "AST/constant_value.hpp"
#include "AST/function.hpp"
#include "AST/compound_statement.hpp"
#include "AST/assignment.hpp"
#include "AST/print.hpp"
#include "AST/read.hpp"
#include "AST/variable_reference.hpp"
#include "AST/binary_operator.hpp"
#include "AST/unary_operator.hpp"
#include "AST/if.hpp"
#include "AST/while.hpp"
#include "AST/for.hpp"
#include "AST/return.hpp"
#include "AST/function_call.hpp"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void symbolTableCreator::visit(ProgramNode *m){
	this->level=0;
	SymbolTable global;
	global.level=level;
	vector<VariableInfo*> BF;
	global.addsymbol(m->program_name,"program",this->level,m->return_type,BF,true);
	manager.pushScope(global);	
        if (m->declaration_node_list != nullptr)
            for(uint i=0; i< m->declaration_node_list->size(); i++){
                (*(m->declaration_node_list))[i]->accept(*this);
            }
	
        if (m->function_node_list != nullptr)
            for(uint i=0; i< m->function_node_list->size(); i++){
                (*(m->function_node_list))[i]->accept(*this);
            }
        if (m->compound_statement_node != nullptr)
            m->compound_statement_node->accept(*this);
	manager.level=level;
	//printf("pop\n");
	manager.popScope();
	std::size_t found = filename.find(m->program_name);
	if(found==std::string::npos){
                fprintf(stderr,"<Error> Found in line %d, column %d: program name must be the same as filename\n",m->line_number,m->col_number);
                printerror(m->line_number,m->col_number);
        }
        if(m->program_name!=m->end_name){
                fprintf(stderr,"<Error> Found in line %d, column %d: identifier at the end of program must be the same as identifier at the beginning of program\n",m->end_line_number,m->end_col_number);
                printerror(m->end_line_number,m->end_col_number);
        }
	
}

void symbolTableCreator::visit(DeclarationNode *m) {
        
        if (m->variables_node_list != nullptr)
            for(uint i=0; i< m->variables_node_list->size(); i++){
                (*(m->variables_node_list))[i]->accept(*this);
            }
}

void symbolTableCreator::visit(VariableNode *m) {
	SymbolTable T=manager.tables.top();
	bool legal=true;
	for(int i=0;i<T.entries.size();i++){
		if(m->variable_name==T.entries[i].Name&&T.entries[i].kind=="parameter")legal=false;
		if(m->variable_name==T.entries[i].Name&&T.entries[i].kind=="loop_var")legal=false;
		if(m->variable_name==T.entries[i].Name&&T.entries[i].level==level)legal=false;
	}
	if(legal==false){
                fprintf(stderr,"<Error> Found in line %d, column %d: symbol '%s' is redeclared\n",m->line_number,m->col_number,m->variable_name.c_str());
                printerror(m->line_number,m->col_number);
		return;
        }
	if(m->type->type_set==SET_ACCUMLATED){
                for(int i=0;i<m->type->array_range.size();i++)
                        if(m->type->array_range[i].start>m->type->array_range[i].end){
                                fprintf(stderr,"<Error> Found in line %d, column %d: '%s' declared as an array with a lower bound greater or equal to upper bound\n",m->line_number,m->col_number,m->variable_name.c_str());
                                printerror(m->line_number,m->col_number);
				legal=false;
                        }

        }
	vector<VariableInfo*> V;
	V.push_back(m->type);
	if(manager.para==1){
		if(m->type->type_set==SET_CONSTANT_LITERAL)
			T.addsymbol(m->variable_name,"constant",this->level,getType(m->type),V,legal);
		else
			T.addsymbol(m->variable_name,"variable",this->level,getType(m->type),V,legal);
	}
	else if(manager.para==2)
		T.addsymbol(m->variable_name,"parameter",this->level,getType(m->type),V,legal);
	manager.tables.pop();
	manager.tables.push(T);
        if (m->constant_value_node != nullptr){
            m->constant_value_node->accept(*this);
	}
    
}

void symbolTableCreator::visit(ConstantValueNode *m) {
	switch(m->constant_value->type){
        case TYPE_INTEGER: check_type="integer"; break;
        case TYPE_REAL:    check_type="real"; break;
        case TYPE_STRING:  check_type="string"; break;
        case TYPE_BOOLEAN:
            switch(m->constant_value->boolean_literal){
                case Boolean_TRUE: check_type="boolean"; break;
                case Boolean_FALSE: check_type="boolean";break;
		default : check_type="unknown";break;
            } 
            break;
        default: std::cout << "unknown"; break;
    }
	string type=check_type;
	if(check_int==true){
		if(!checktype("integer")){
			fprintf(stderr,"<Error> Found in line %d, column %d: index of array reference must be an integer\n",m->line_number,m->col_number);
			printerror(m->line_number,m->col_number);
			check_int=false;
		}
	}
	/*if(check_return_type==true){
		if(!checktype(return_type)){
			fprintf(stderr,"<Error> Found in line %d, column %d: return '%s' from a function with return type '%s'\n",m->line_number,m->col_number,type.c_str(),return_type.c_str());
			printerror(m->line_number,m->col_number);
			check_return_type=false;
		}
	}*/
	/*if(check_para==true){
		if(!checktype(para)){
			fprintf(stderr,"<Error> Found in line %d, column %d: incompatible types passing '%s' to parameter of type '%s'\n",m->line_number,m->col_number,type.c_str(),para.c_str());
			printerror(m->line_number,m->col_number);
			check_para=false;
		}
	}*/
	line=m->line_number;
	col=m->col_number;	
    
    // this->space_counter_increase();
    //     // this->space_counter_decrease(); 
}


void symbolTableCreator::visit(FunctionNode *m) {
	bool legal=true;
	return_type=getType(m->return_type);
	SymbolTable S=manager.tables.top();
	for(int i=0;i<S.entries.size();i++){
		if(m->function_name==S.entries[i].Name&&S.entries[i].level==this->level)legal=false;
	}
	string type;
	switch(m->return_type->type_set){
        case SET_SCALAR:
            switch(m->return_type->type){
                case TYPE_INTEGER: type="integer"; break;
                case TYPE_REAL:    type="real"; break;
                case TYPE_STRING:  type="string"; break;
                case TYPE_BOOLEAN: type="boolean"; break;
                default:           type="unknown"; break;
            }
            break;
        case UNKNOWN_SET:
            switch(m->return_type->type){
                case TYPE_VOID: type="void"; break;
                default:        type="unknown"; break;
            }
            break;
        default: type="unknown"; break; break;
	}
         
	SymbolTable T=manager.tables.top();
	T.addsymbol(m->function_name,"function",this->level,type,m->prototype,legal);
	manager.tables.pop();
	manager.pushScope(T);
	this->level++;
	SymbolTable F;
	manager.pushScope(F);	
        if (m->parameters != nullptr)
            for(uint i=0; i< m->parameters->size(); i++){
		manager.para=2;
               	(*(m->parameters))[i]->node->accept(*this);
		manager.para=1;
		
	    }
        if (m->body != nullptr){
		in_func=true;
		manager.in_func=true;
        	m->body->accept(*this);
		manager.in_func=false;
		in_func=false;
	}
	manager.level=level;
	this->level--;
	manager.popScope();
	if(legal==false){
		fprintf(stderr,"<Error> Found in line %d, column %d: symbol '%s' is redeclared\n",m->line_number,m->col_number,m->function_name.c_str());
		printerror(m->line_number,m->col_number);
	}
	if(m->function_name!=m->end_name){
		fprintf(stderr,"<Error> Found in line %d, column %d: identifier at the end of function must be the same as identifier at the beginning of function\n",m->end_line_number,m->end_col_number);
		printerror(m->end_line_number,m->end_col_number);
	}    
}

void symbolTableCreator::visit(CompoundStatementNode *m) {
	bool cp_in_func=false;
	if(manager.in_func==false){
		this->level++;
		SymbolTable CP;
		CP.level=level;
		manager.pushScope(CP);
	}
	if(manager.in_func==true){                                                                                                      cp_in_func=true;                                                                                                        manager.in_func=false;                                                                                          } 
	
        if (m->declaration_node_list != nullptr)
            for(uint i=0; i< m->declaration_node_list->size(); i++){
                (*(m->declaration_node_list))[i]->accept(*this);
            }
        if (m->statement_node_list != nullptr)
            for(uint i=0; i< m->statement_node_list->size(); i++){
                (*(m->statement_node_list))[i]->accept(*this);
            }
	if(cp_in_func==false){
		manager.level=level;
		manager.popScope();
		this->level--;
	}    
}

void symbolTableCreator::visit(AssignmentNode *m) {
	string left_type,right_type;
	check_constant=true;
	check_arr=true;
        if (m->variable_reference_node != nullptr)
            m->variable_reference_node->accept(*this);
	if(check_arr==false||check_type=="unknown")return;
	left_type=check_type;
        check_constant=false;
        if (m->expression_node != nullptr)
            m->expression_node->accept(*this);
	
	right_type=check_type;
	if(left_type!="unknown"&&right_type!="unknown"&&check_arr==true){
		if(left_type!=right_type){
			fprintf(stderr,"<Error> Found in line %d, column %d: assigning to '%s' from incompatible type '%s'\n",m->line_number,m->col_number,left_type.c_str(),right_type.c_str());
			printerror(m->line_number,m->col_number+1);
		}
	}
	check_arr=false;  
}

void symbolTableCreator::visit(PrintNode *m) {
	check_arr=true;
	check_print_read=true;
        if (m->expression_node != nullptr)
            m->expression_node->accept(*this);
	check_print_read=false;
	if(check_arr==false&&check_type!="unknown"){
		fprintf(stderr,"<Error> Found in line %d, column %d: variable reference of print statement must be scalar type\n",m->line_number,m->col_number+6);
		printerror(m->line_number,m->col_number+6);
	}
	check_arr=false;  
}

void symbolTableCreator::visit(ReadNode *m) {
	check_arr=true;
	check_print_read=true;
	check_constant=true;
        if (m->variable_reference_node != nullptr)
            m->variable_reference_node->accept(*this);
	check_print_read=false;
	check_constant=false;
	//cout<<check_arr <<endl<<check_type<<endl;
	if(check_arr==false&&check_type!="unknown"){
		fprintf(stderr,"<Error> Found in line %d, column %d: variable reference of read statement must be scalar type\n",m->line_number,m->col_number+5);
		printerror(m->line_number,m->col_number+5);
	}
	check_arr=false;    
}

void symbolTableCreator::visit(VariableReferenceNode *m) {
	bool check=false;
	bool legal=true;
	SymbolTable D=manager.tables.top();
	for(int i=D.entries.size()-1;i>=0;i--){
		if(D.entries[i].Name==m->variable_name){
			break;
		}
		if(i==0)legal=false;
	}
	if(!legal){
		fprintf(stderr,"<Error> Found in line %d, column %d: use of undeclared identifier '%s'\n",m->line_number,m->col_number,m->variable_name.c_str());
                printerror(m->line_number,m->col_number);
		check_type="unknown";
		return;
	}
    if(check_return_type==true){
   	check=true;
	check_return_type=false;
	
	}
    if (m->expression_node_list != nullptr)
        for(uint i=0; i< m->expression_node_list->size(); i++){
        
            	
            	check_int=true;
                (*(m->expression_node_list))[i]->accept(*this);
		check_int=false;
        }

   if(check_type=="unknown"&&m->expression_node_list != nullptr)return;
   if(check==true)check_return_type=true; 
   SymbolTable T=manager.tables.top();

   for(int i=T.entries.size()-1;i>=0;i--){
   	if(T.entries[i].Name==m->variable_name&&T.entries[i].legal){
		if(T.entries[i].kind=="constant"&&(!check_print_read)&&check_constant){
			fprintf(stderr,"<Error> Found in line %d, column %d: cannot assign to variable '%s' which is a constant\n",m->line_number,m->col_number,m->variable_name.c_str());
        		printerror(m->line_number,m->col_number);
			check_type="unknown";
			return;
		}
		if(T.entries[i].kind=="constant"&&check_print_read&&check_constant){                                                           	fprintf(stderr,"<Error> Found in line %d, column %d: variable reference of read statement cannot be a constant variable reference\n",m->line_number,m->col_number);
                        printerror(m->line_number,m->col_number);
			check_type="unknown";
                        return;
                }              
		if(T.entries[i].kind=="loop_var"&&check_constant){
			fprintf(stderr,"<Error> Found in line %d, column %d: the value of loop variable cannot be modified inside the loop\n",m->line_number,m->col_number);
			printerror(m->line_number,m->col_number);
			check_type="unknown";
			return;
		}
		check_type=getType(T.entries[i].attribute[0]);
		string Type;
		int countarr=0;
		if(m->expression_node_list != nullptr){                                                                                         if(T.entries[i].attribute[0]->array_range.size()>=m->expression_node_list->size()){
				for(int j=0;j<check_type.length();j++){
					//cout <<check_type<<endl;
					if(check_type[j]=='['&&Type.length()==0){

						Type=check_type.substr(0,j-1);
						//cout<<Type<<endl;
					}
					if(check_type[j]==']')countarr++;
					if(countarr==m->expression_node_list->size()){
						check_type=check_type.substr(j+1,check_type.length()-j-1);
						if(check_type.length())
						check_type=Type+" "+check_type;
						else check_type=Type+check_type;
						break;
					}
				}
			}
		
		}
		string type=check_type;
		/*if(check_para==true){
                if(!checktype(para)){
                        fprintf(stderr,"<Error> Found in line %d, column %d: incompatible types passing '%s' to parameter of type '%s'\n",m->line_number,m->col_number,type.c_str(),para.c_str());
                        printerror(m->line_number,m->col_number);
                        check_para=false;
			return;
                }
        	}*/
		if(m->expression_node_list != nullptr){
                        if(T.entries[i].attribute[0]->array_range.size()<m->expression_node_list->size()){
                                fprintf(stderr,"<Error> Found in line %d, column %d: there is an over array subscript\n",m->line_number,m->col_number);                                                                                                                         printerror(m->line_number,m->col_number);
                                return;
                        }
                }
		
		if(check_arr==true){
			std::size_t found = check_type.find("[");
				if(found!=std::string::npos){
				if(check_print_read==false){
				fprintf(stderr,"<Error> Found in line %d, column %d: array assignment is not allowed\n",m->line_number,m->col_number);
				printerror(m->line_number,m->col_number);
				}
				check_arr=false;
				return;
			}
		}
		if(check_int==true){
			if(!checktype("integer")){
				fprintf(stderr,"<Error> Found in line %d, column %d: index of array reference must be an integer\n",m->line_number,m->col_number);
				printerror(m->line_number,m->col_number);
				check_int=false;
				return;			
			}
		}
		/*if(check_return_type==true){
			if(!checktype(return_type)){
				fprintf(stderr,"<Error> Found in line %d, column %d: return '%s' from a function with return type '%s'\n",m->line_number,m->col_number,type.c_str(),return_type.c_str());
				printerror(m->line_number,m->col_number);
				check_return_type=false;
				return;
			}
		}*/
		line=m->line_number;
		col=m->col_number;
		break;
	}
	
	
   } 
    	
}

void symbolTableCreator::visit(BinaryOperatorNode *m) {
	string left_type,right_type;
        if (m->left_operand != nullptr)
            m->left_operand->accept(*this);
	left_type=check_type;
        if (m->right_operand != nullptr)
            m->right_operand->accept(*this);
	right_type=check_type;
	if(m->op==OP_PLUS){
		if(left_type=="unknown"||right_type=="unknown")check_type="unknown";
		else if(left_type=="integer"&&right_type=="real")check_type="real";
		else if(left_type=="real"&&right_type=="integer")check_type="real";
		else if(left_type=="string"&&right_type=="string")check_type="string";
		else if(left_type=="integer"&&right_type=="integer")check_type="integer";
		else if(left_type=="real"&&right_type=="real")check_type="real";
		else{
			fprintf(stderr,"<Error> Found in line %d, column %d: invalid operands to binary operation '%s' ('%s' and '%s')\n",m->line_number,m->col_number,enumTOstring_op(m->op).c_str(),left_type.c_str(),right_type.c_str());
			printerror(m->line_number,m->col_number);
			check_type="unknown";
		}
	}
	else if(m->op==OP_MINUS || m->op==OP_MULTIPLY || m->op==OP_DIVIDE){
		if(left_type=="unknown"||right_type=="unknown")check_type="unknown";
		else if(left_type=="integer"&&right_type=="real")check_type="real";
                else if(left_type=="real"&&right_type=="integer")check_type="real";                                     
                else if(left_type=="integer"&&right_type=="integer")check_type="integer";
                else if(left_type=="real"&&right_type=="real")check_type="real";
                else{
                        fprintf(stderr,"<Error> Found in line %d, column %d: invalid operands to binary operation '%s' ('%s' and '%s')\n",m->line_number,m->col_number,enumTOstring_op(m->op).c_str(),left_type.c_str(),right_type.c_str());
                        printerror(m->line_number,m->col_number);
			check_type="unknown";
		}
	}
	else if(m->op==OP_MOD){
		if(left_type=="unknown"||right_type=="unknown")check_type="unknown";
		else if(left_type=="integer"&&right_type=="integer")check_type="integer";
		else{
			fprintf(stderr,"<Error> Found in line %d, column %d: invalid operands to binary operation '%s' ('%s' and '%s')\n",m->line_number,m->col_number,enumTOstring_op(m->op).c_str(),left_type.c_str(),right_type.c_str());
                        printerror(m->line_number,m->col_number);                                                                               check_type="unknown";
		}
	}
	else if(m->op==OP_LESS || m->op==OP_LESS_OR_EQUAL || m->op==OP_EQUAL || m->op==OP_NOT_EQUAL || m->op==OP_GREATER || m->op==OP_GREATER_OR_EQUAL){
		if(left_type=="unknown"||right_type=="unknown")check_type="unknown";
		else if(left_type=="real"&&right_type=="integer")check_type="boolean";
		else if(left_type=="integer"&&right_type=="real")check_type="boolean";
		else if(left_type=="integer"&&right_type=="integer")check_type="boolean";
		else if(left_type=="real"&&right_type=="real")check_type="boolean";
		else{
			fprintf(stderr,"<Error> Found in line %d, column %d: invalid operands to binary operation '%s' ('%s' and '%s')\n",m->line_number,m->col_number,enumTOstring_op(m->op).c_str(),left_type.c_str(),right_type.c_str());
                        printerror(m->line_number,m->col_number);
                        check_type="unknown";
		}
		
	}
	else if(m->op==OP_AND || m->op==OP_OR || m->op==OP_NOT){
		if(left_type=="boolean"&&right_type=="boolean")check_type="boolean";
		else{
			fprintf(stderr,"<Error> Found in line %d, column %d: invalid operands to binary operation '%s' ('%s' and '%s')\n",m->line_number,m->col_number,enumTOstring_op(m->op).c_str(),left_type.c_str(),right_type.c_str());
                        printerror(m->line_number,m->col_number);
                        check_type="unknown";
		}
		
	}
	
	line=m->line_number;
	col=m->col_number;
}

void symbolTableCreator::visit(UnaryOperatorNode *m) {
	string type;
        if (m->operand != nullptr)
            m->operand->accept(*this);
	type=check_type;
	if(m->op==OP_MINUS){
		if(type=="unknown")check_type="unknown";
		else if(type=="string"||type=="boolean"){
			fprintf(stderr,"<Error> Found in line %d, column %d: invalid operand to unary operation '-' ('%s')\n",m->line_number,m->col_number,type.c_str());
			printerror(m->line_number,m->col_number);
		check_type="unknown";
		}

		
	}
	else if(m->op==OP_NOT){
		if(type=="unknown")check_type="unknown";
		else if(type=="boolean"){
			check_type="boolean";
		}
		else{
			fprintf(stderr,"<Error> Found in line %d, column %d: invalid operand to unary operation 'not' ('%s')\n",m->line_number,m->col_number,type.c_str());
			printerror(m->line_number,m->col_number);
                	check_type="unknown";
		}
	}
	
	line=m->line_number;
	col=m->col_number;
}

void symbolTableCreator::visit(IfNode *m) {
        if (m->condition != nullptr)
            m->condition->accept(*this);
	string type=check_type;
	
        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);
   	if (m->body_of_else != nullptr){
            for(uint i=0; i< m->body_of_else->size(); i++)
                (*(m->body_of_else))[i]->accept(*this);
        }

	if(type!="boolean"&&type!="unknown"){
                fprintf(stderr,"<Error> Found in line %d, column %d: the expression of condition must be boolean type\n",line,col);
                printerror(line,col);
                check_type="unknown";                                                                                           }
	
	
}

void symbolTableCreator::visit(WhileNode *m) {
        if (m->condition != nullptr)
            m->condition->accept(*this);
	string type=check_type;
        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);
	if(type!="boolean"&&type!="unknown"){
                fprintf(stderr,"<Error> Found in line %d, column %d: the expression of condition must be boolean type\n",line,col);                                                                                                                             printerror(line,col);
                check_type="unknown";                                                                                           } 
}

void symbolTableCreator::visit(ForNode *m) {
    this->level++;
    string name;
    SymbolTable ForT;
    
	
        if (m->loop_variable_declaration != nullptr){
        	name=m->ID;
		SymbolTable T=manager.tables.top();
		for(int i=0;i<T.entries.size();i++){
			if(name==T.entries[i].Name){
				fprintf(stderr,"<Error> Found in line %d, column %d: symbol '%s' is redeclared\n",m->line_number,m->col_number+4,name.c_str());
				printerror(m->line_number,m->col_number+4);
				manager.level=level;
				manager.pushScope(ForT);
				manager.popScope();
				this->level--;
				return;
			}
			if(i==T.entries.size()-1){
				vector<VariableInfo*> N;
				ForT.addsymbol(name,"loop_var",this->level,"integer",N,true);
			}
		}
	manager.pushScope(ForT);
	}
    
        /*if (m->initial_statement != nullptr)
            m->initial_statement->accept(*this);

        if (m->condition != nullptr)
            m->condition->accept(*this);*/
        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);
    manager.level=level;
    manager.popScope();

    if(m->start>m->end){
    	fprintf(stderr,"<Error> Found in line %d, column %d: the lower bound of iteration count must be smaller than or equal to the upper bound\n",m->line_number,m->col_number);
	printerror(m->line_number,m->col_number);
    }
	this->level--;
	
}

void symbolTableCreator::visit(ReturnNode *m) {
	bool program;
	SymbolTable D=manager.tables.top();                                                                                     SymbolEntry A;
        for(int i=D.entries.size()-1;i>=0;i--){
                if(D.entries[i].kind=="function"){
                        A=D.entries[i];
                        break;
                }
	}
	if(!in_func||A.type=="void"){
                        fprintf(stderr,"<Error> Found in line %d, column %d: program/procedure should not return a value\n",m->line_number,m->col_number);
                        printerror(m->line_number,m->col_number);
		return;
        }
	if(A.legal==false)return;
        if (m->return_value != nullptr){
		check_return_type=false;            
		m->return_value->accept(*this);
		check_return_type=false;
	}
	string type=check_type;
                        if(!checktype(return_type)){
                                fprintf(stderr,"<Error> Found in line %d, column %d: return '%s' from a function with return type '%s'\n",m->line_number,m->col_number+7,type.c_str(),return_type.c_str());
                                printerror(m->line_number,m->col_number+7);
                                check_return_type=false;
                                return;
                        }
       
	
	
	
	
}

void symbolTableCreator::visit(FunctionCallNode *m) {
	//SymbolEntry *reference_entry = search_by_name(m->function_name);
	string type[10];
	int line[10],col[10];
	SymbolTable D=manager.tables.top();
	SymbolEntry A;
	for(int i=D.entries.size()-1;i>=0;i--){
		if(D.entries[i].Name==m->function_name){
			A=D.entries[i];
			break;
		}
		if(i==0){
			fprintf(stderr,"<Error> Found in line %d, column %d: used of undeclared function '%s'\n",m->line_number,m->col_number,m->function_name.c_str());
                	printerror(m->line_number,m->col_number);
			check_type="unknown";
                	return;
		}
	}
	check_type=A.type;
	int size;
	if(m->arguments==nullptr)size=0;
	else size=m->arguments->size();
	if(A.attribute.size()!=size){
		fprintf(stderr,"<Error> Found in line %d, column %d: too few/much arguments to function invocation\n",m->line_number,m->col_number);
		printerror(m->line_number,m->col_number);
		check_type="unknown";
		return;
	}
	VariableInfo *ref;
        if (m->arguments != nullptr){
            for(uint i=0; i< size; i++){
		check_para=true;
		ref=A.attribute[i];	
		para=getType(ref);                
		(*(m->arguments))[i]->accept(*this);
		check_para=false;
		type[i]=check_type;
		line[i]=this->line;
		col[i]=this->col;
		
	    }
	    for(uint i=0; i< size; i++){
	        ref=A.attribute[i];
		para=getType(ref);
		if(type[i]!=para&&type[i]!="unknown"){
			fprintf(stderr,"<Error> Found in line %d, column %d: return '%s' from a function with return type '%s'\n",line[i],col[i],type[i].c_str(),para.c_str());
                        printerror(line[i],col[i]);
			check_type="unlnown";                                                             
		}
	    }
	}
		
	
	if(check_int==true){
		if(!checktype("integer")){
			fprintf(stderr,"<Error> Found in line %d, column %d: index of array reference must be an integer\n",m->line_number,m->col_number);
			printerror(m->line_number,m->col_number);
		
			check_int=false;
		}
	}
	this->line=m->line_number;
	this->col=m->col_number;	
}


