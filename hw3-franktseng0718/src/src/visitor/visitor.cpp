#include "visitor/visitor.h"
#include "AST/ast.h"
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <string>
void visitor::visit(tempnode* m){
			
}

void visitor::visit(ProgramNode* m){
	printf("program <line: %d, col: %d> %s void\n",m->line,m->col,m->Name);
}

void visitor::visit(DeclarationNode* m){
        printf("declaration <line: %d, col: %d>\n",m->line,m->col);
}   

void visitor::visit(variableNode* m){                                                                                
	printf("variable <line: %d, col: %d> %s %s\n",m->line,m->col,m->Name.c_str(),m->Type);                                                         
} 

void visitor::visit(Constant_value_Node* m){
	if(m->type>2)printf("constant <line: %d, col: %d> %s\n",m->line,m->col,m->value);
	else if(m->type==1)printf("constant <line: %d, col: %d> %d\n",m->line,m->col,m->ivalue);
	else if(m->type==2)printf("constant <line: %d, col: %d> %.6f\n",m->line,m->col,m->fvalue);                                                         
} 

 void visitor::visit(FunctionNode* m){                                                                                
	printf("function declaration <line: %d, col: %d> %s %s (",m->line,m->col,m->Name,m->return_type);
	if(m->arg.size()>1){
		for(unsigned int i=0;i<(m->arg.size()-1);i++)
			printf("%s, ",m->arg[i].c_str());
	}
	if(m->arg.size()>0)printf("%s)\n",m->arg[m->arg.size()-1].c_str());
	else printf(")\n");                                                         
}

void visitor::visit(Compound_Statement* m){                                                                                printf("compound statement <line: %d, col: %d>\n",m->line,m->col);                                         
}

void visitor::visit(Assignment_Node* m){                                                                                printf("assignment statement <line: %d, col: %d>\n",m->line,m->col);                                         
}

void visitor::visit(ReadNode* m){
	printf("read statement <line: %d, col: %d>\n",m->line,m->col);
}
void visitor::visit(PrintNode* m){                                                                                
	printf("print statement <line: %d, col: %d>\n",m->line,m->col);                                         
}

void visitor::visit(Variable_Reference_Node* m){                                                                                printf("variable reference <line: %d, col: %d> %s\n",m->line,m->col,m->Name);                                         
}

void visitor::visit(Binary_Operator_Node* m){                                                                                printf("binary operator <line: %d, col: %d> %s\n",m->line,m->col,m->op);
}

void visitor::visit(Unary_Operator_Node* m){                                                                                printf("unary operator <line: %d, col: %d> %s\n",m->line,m->col,m->op);
}

void visitor::visit(ifNode* m){                                                                                
	printf("if statement <line: %d, col: %d>\n",m->line,m->col);
}

 void visitor::visit(WhileNode* m){                                                                                
	printf("while statement <line: %d, col: %d>\n",m->line,m->col);
}

void visitor::visit(forNode* m){                                                                                
	printf("for statement <line: %d, col: %d>\n",m->line,m->col);                                         
}
void visitor::visit(returnNode* m){ 
      printf("return statement <line: %d, col: %d>\n",m->line,m->col);                                         
}

void visitor::visit(functioncallNode* m){                                                                                printf("function call statement <line: %d, col: %d> %s\n",m->line,m->col,m->Name);
}
void visitor::visit(Arrform* m){                                                                                	
		//printf("[\n");
}
void visitor::visit(elsenode *m){
		printf("else\n");
}
void visitor::visit(rbreaket *m){
		printf("]\n");
}
void visitor::visit(lbreaket *m){
		printf("[\n");
}
                                                                                                                                                                                                                        
