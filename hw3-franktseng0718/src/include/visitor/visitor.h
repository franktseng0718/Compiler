#ifndef __VISITOR_H
#define __VISITOR_H
#include "AST/ast.h"
#include "AST/program.h"

class visitor : public ASTNodeVisitorBase
{
	void visit(tempnode *m) override;
	void visit(ProgramNode *m) override;
		
	void visit(DeclarationNode *m) override;
		
	void visit(Constant_value_Node *m) override;
	
	void visit(FunctionNode *m) override;
	void visit(variableNode *m) override;
		
	void visit(Compound_Statement *m) override;
		
	void visit(Assignment_Node *m) override;
		
	void visit(PrintNode *m) override;

	void visit(ReadNode *m) override;
	
	void visit(Variable_Reference_Node *m) override;
	
	void visit(Binary_Operator_Node *m) override;
		
	void visit(Unary_Operator_Node *m) override;
	
	void visit(ifNode *m) override;
	
	void visit(WhileNode *m) override;
	
	void visit(forNode *m) override;
	
	void visit(returnNode *m) override;

	void visit(functioncallNode *m) override;
	
	void visit(Arrform *m) override;
	void visit(elsenode *m) override;
	void visit(rbreaket *m) override;
	void visit(lbreaket *m) override;	

};
#endif
