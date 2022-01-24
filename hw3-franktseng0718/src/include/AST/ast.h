#ifndef __AST_H
#define __AST_H
#include <vector>
#include <string>
#include <string.h>
#include <bits/stdc++.h>
//#include "visitor/visitor.h"
//class ASTNodeVisitorBase;
class ASTNodeVisitorBase{
        public:
        virtual void visit(class tempnode *m)=0;
        virtual void visit(class ProgramNode *m)=0;
        virtual void visit(class DeclarationNode *m)=0;
        virtual void visit(class variableNode *m)=0;
        virtual void visit(class Constant_value_Node *m)=0;
        virtual void visit(class FunctionNode *m)=0;
        virtual void visit(class Compound_Statement *m)=0;
        virtual void visit(class Assignment_Node *m)=0;
        virtual void visit(class PrintNode *m)=0;
        virtual void visit(class ReadNode *m)=0;
        virtual void visit(class Variable_Reference_Node *m)=0;
        virtual void visit(class Binary_Operator_Node *m)=0;
        virtual void visit(class Unary_Operator_Node *m)=0;
        virtual void visit(class ifNode *m)=0;
        virtual void visit(class WhileNode *m)=0;
        virtual void visit(class forNode *m)=0;
        virtual void visit(class returnNode *m)=0;
        virtual void visit(class functioncallNode *m)=0;
        virtual void visit(class Arrform *m)=0;
	virtual void visit(class elsenode *m)=0;
	virtual void visit(class rbreaket *m)=0;
	virtual void visit(class lbreaket *m)=0;
};
class Nodebase{
	public:
		int line;
		int col;
		int dep;
		std::vector<Nodebase *> child;
		std::vector<std::string> arg;
		std::vector<int> column;
		virtual void accept(class ASTNodeVisitorBase &v)=0;
};
class tempnode:public Nodebase{
	public:
		char* Name;
		char* Type;
		void accept(ASTNodeVisitorBase &v){
                v.visit(this);
		                                                                                                  
		}
		tempnode(){dep=2;}                      
};
class ProgramNode: public Nodebase{
  // TODO
  public:
	char* Name;
	char* Return_type;
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
};
class DeclarationNode: public Nodebase{                                                                                                       // TODO
  public:
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
 };
class variableNode:public Nodebase{
	public:
		std::string Name;
		char* Type;
		void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
};
class Constant_value_Node: public Nodebase{                                                                                                       // TODO
  public:
	char* value;
	int type;
	int ivalue;
	double fvalue;
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
};
class FunctionNode: public Nodebase{                                                                                                       // TODO
  public:
	char* Name;
	char* Prototype;
	char* return_type;
	//std::vector<std::string> arg;
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                               };
 
class Compound_Statement: public Nodebase{                                                                                                       // TODO
  public:
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                               };

class Assignment_Node: public Nodebase{                                                                                                       // TODO
  public:
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
 };

class PrintNode: public Nodebase{                                                                                                       // TODO
  public:
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                                        
};

class ReadNode:public Nodebase{                                                                                                       // TODO
  public:
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                                       
};

class Variable_Reference_Node: public Nodebase{                                                                                                       // TODO
  public:
	char *Name;
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                           
 };

class Binary_Operator_Node: public Nodebase {                                                                                                       // TODO
  public:
	char * op;
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                               };

class Unary_Operator_Node:public Nodebase {                                                                                                       // TODO
  public:
	char* op;
	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                                };

class  ifNode: public Nodebase{                                                                                                       // TODO 
       public:

	void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                                                                                                                        
};

class  WhileNode:public Nodebase{                                                                                                       //
        public:
		void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
};

class  forNode: public Nodebase{                                                                                                       //
        public:
		void accept(ASTNodeVisitorBase &v){
                v.visit(this);                                                                                                  }                      
};

class  returnNode: public Nodebase{                                                                                                       //
        public:
		void accept(ASTNodeVisitorBase &v){
                	v.visit(this);                                                                                                  }	                      
};

class  functioncallNode: public Nodebase{                                                                                                       //
        public:
		char* Name;
		void accept(ASTNodeVisitorBase &v){
                	v.visit(this);                                                                                                  }                      
};
class Arrform:public Nodebase{
	public:
		void accept(ASTNodeVisitorBase &v){                                
		v.visit(this);                     
		}
		Arrform(){dep=2;}
};
class elsenode:public Nodebase{
	public:
		void accept(ASTNodeVisitorBase &v){
			v.visit(this);
		}

};
class rbreaket:public Nodebase{
	public:
		void accept(ASTNodeVisitorBase &v){
			v.visit(this);
		}
		rbreaket(){dep=1;}
};
class lbreaket:public Nodebase{
	public:
		void accept(ASTNodeVisitorBase &v){
			v.visit(this);
		}
		lbreaket(){dep=1;}
};

#endif
