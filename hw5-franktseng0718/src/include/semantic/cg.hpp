#pragma once
#include "AST/ast.hpp"
#include "semantic/SymbolTable.hpp"
#include "visitor/visitor.hpp"
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// FIXME: remember to replace ";" below with ";", or your implementations in
// .cpp won't be compiled.
class symbolentry{
        public:
        string name;
	int level=0;
        int var_count;
        symbolentry(string name,int level,int var_count){
                this->name=name;
                this->level=level;
   		this->var_count=var_count;
        }

};
class Codegenerator : public ASTVisitorBase {
  public:
    void visit(ProgramNode *m) override;
    void visit(DeclarationNode *m) override;
    void visit(VariableNode *m) override;
    void visit(ConstantValueNode *m) override;
    void visit(FunctionNode *m) override;
    void visit(CompoundStatementNode *m) override;
    void visit(AssignmentNode *m) override;
    void visit(PrintNode *m) override;
    void visit(ReadNode *m) override;
    void visit(VariableReferenceNode *m) override;
    void visit(BinaryOperatorNode *m) override;
    void visit(UnaryOperatorNode *m) override;
    void visit(IfNode *m) override;
    void visit(WhileNode *m) override;
    void visit(ForNode *m) override;
    void visit(ReturnNode *m) override;
    void visit(FunctionCallNode *m) override;

    Codegenerator(string _filename, FILE *_fp);

    
    
    

  // TODO
    class SymbolTable *symbol_table_root;
    class SymbolTable *current_scope;
    unsigned int level;
    int var_count=0;
    string filename;
    FILE *fp;
    vector<symbolentry> table; 
    vector<string> output;
    bool in_func=false;
    int reg=0;
    bool ass=false;
    int ass_addr;
    string op;
    string var_name;
    int loop_cnt=0;
    bool para=false;
  
};
