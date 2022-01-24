#include "semantic/SemanticAnalyzer.hpp"
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
#include "AST/symboltable.hpp"

#include <bits/stdc++.h>

using namespace std;

//
// TODO: implementations of visit(xxxxNode *)
//

void SemanticAnalyzer::visit(ProgramNode *m) {
	this->level=0;
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

	if(m->program_name!=manager.file_name){
		printf("<Error> Found in line %d, column %d: program name must be the same as filename\n",m->line_number,m->column_number);
		printerror(m->line_number,m->column_number);
	}
	if(m->program_name!=m->end_name){
		printf("<Error> Found in line %d, column %d: identifier at the end of program must be the same as identifier at the beginning of program\n",m->end_line_number,m->end_column_number);
		printerror(m->end_line_number,m->end_column_number);
	}
}

void SemanticAnalyzer::visit(DeclarationNode *m) {
	if (m->variables_node_list != nullptr)
            for(uint i=0; i< m->variables_node_list->size(); i++){
                (*(m->variables_node_list))[i]->accept(*this);
            }	

}

void SemanticAnalyzer::visit(VariableNode *m) {
	
	if (m->constant_value_node != nullptr)
            m->constant_value_node->accept(*this);
}

void SemanticAnalyzer::visit(ConstantValueNode *m) {}

void SemanticAnalyzer::visit(FunctionNode *m) {
	if (m->parameters != nullptr)
            for(uint i=0; i< m->parameters->size(); i++){
                (*(m->parameters))[i]->node->accept(*this);
            }
        
        if (m->body != nullptr)
            m->body->accept(*this);
}

void SemanticAnalyzer::visit(CompoundStatementNode *m) {
	if (m->declaration_node_list != nullptr)
            for(uint i=0; i< m->declaration_node_list->size(); i++){
                (*(m->declaration_node_list))[i]->accept(*this);
            }
        if (m->statement_node_list != nullptr)
            for(uint i=0; i< m->statement_node_list->size(); i++){
                (*(m->statement_node_list))[i]->accept(*this);
            }

}

void SemanticAnalyzer::visit(AssignmentNode *m) {
	if (m->variable_reference_node != nullptr)
            m->variable_reference_node->accept(*this);
        
        if (m->expression_node != nullptr)
            m->expression_node->accept(*this);

}

void SemanticAnalyzer::visit(PrintNode *m) {
	if (m->expression_node != nullptr)
            m->expression_node->accept(*this);

}

void SemanticAnalyzer::visit(ReadNode *m) {
	if (m->variable_reference_node != nullptr)
            m->variable_reference_node->accept(*this);
}

void SemanticAnalyzer::visit(VariableReferenceNode *m) {
	(*(m->expression_node_list))[i]->accept(*this);
}

void SemanticAnalyzer::visit(BinaryOperatorNode *m) {
	if (m->left_operand != nullptr)
            m->left_operand->accept(*this);

        if (m->right_operand != nullptr)
            m->right_operand->accept(*this);
}

void SemanticAnalyzer::visit(UnaryOperatorNode *m) {
	if (m->operand != nullptr)
            m->operand->accept(*this);

}

void SemanticAnalyzer::visit(IfNode *m) {
	 if (m->condition != nullptr)
            m->condition->accept(*this);

        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);

	if (m->body_of_else != nullptr)
		for(uint i=0; i< m->body_of_else->size(); i++)
                	(*(m->body_of_else))[i]->accept(*this);
}

void SemanticAnalyzer::visit(WhileNode *m) {
	if (m->condition != nullptr)
            m->condition->accept(*this);

        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);	

}

void SemanticAnalyzer::visit(ForNode *m) {
	if (m->loop_variable_declaration != nullptr)
            m->loop_variable_declaration->accept(*this);
        
        if (m->initial_statement != nullptr)
            m->initial_statement->accept(*this);

        if (m->condition != nullptr)
            m->condition->accept(*this);

        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);

}

void SemanticAnalyzer::visit(ReturnNode *m) {
	if (m->return_value != nullptr)
            m->return_value->accept(*this);

}

void SemanticAnalyzer::visit(FunctionCallNode *m) {
	if (m->arguments != nullptr)
            for(uint i=0; i< m->arguments->size(); i++)
                (*(m->arguments))[i]->accept(*this);
}
