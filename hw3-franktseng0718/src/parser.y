%{
#define YYSTYPE char*
#include "include/visitor/visitor.h"
#include "include/AST/program.h"
#include "include/core/error.h"
#include "include/AST/ast.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#define YYLTYPE yyltype

typedef struct YYLTYPE {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} yyltype;

/* Declared by scanner.l */
extern int32_t LineNum;
extern char Buffer[512];
int countid=0;
std::vector<int> len;
int type;
char *scalartype;
std::stack<tempnode *> statements_stack;
std::stack<Compound_Statement *>compound_stack;
/* Declared by lex */
extern FILE *yyin;
extern char *yytext;

extern "C" int yylex(void);
extern "C" int yyparse();
static void yyerror(const char *msg);

static ProgramNode*root;static tempnode *ProgramBody,*DeclarationList;
static tempnode *Declarations,*FunctionList,*Functions,*formalarglist,*formalargs,*idList,*TypeOrConstant;
static tempnode *StatementList,*E;
static tempnode *Statements,*Statement,*EList,*Es,*Eornot,*simple,*formalarg;
	static DeclarationNode *Declaration;
	static FunctionNode *FunctionDeclaration;
	static variableNode *var;
	static Constant_value_Node *constant;
	static Compound_Statement *compound;
	static PrintNode *print;
	static Assignment_Node *assign;
	static ReadNode *read;
	static Variable_Reference_Node *VR;
	static Binary_Operator_Node *BO;
	static Unary_Operator_Node *UO;
	static ifNode *If;
	static WhileNode  *WH;
	static forNode *F;
	static returnNode  *RE;
	static functioncallNode  *CALL;
	static Arrform  *AF;
	static elsenode *EL;

/*char* strdup (const char* s){
        size_t slen = strlen(s);
        char* result = malloc(slen + 1);
        if(result == NULL)
        {
                return NULL;
        }
        memcpy(result, s, slen+1);
        return result;
}*/		
%}

%locations
%code requires{#include "AST/ast.h"}
    /* Delimiter */
%token COMMA SEMICOLON COLON
%token L_PARENTHESIS R_PARENTHESIS
%token L_BRACKET R_BRACKET

    /* Operator */
%token ASSIGN
%left OR
%left AND
%right NOT
%left LESS LESS_OR_EQUAL EQUAL GREATER GREATER_OR_EQUAL NOT_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%right UNARY_MINUS

    /* Keyword */
%token ARRAY BOOLEAN INTEGER REAL STRING
%token END BEGIN_ /* Use BEGIN_ since BEGIN is a keyword in lex */
%token DO ELSE FOR IF THEN WHILE
%token DEF OF TO RETURN VAR
%token FALSE TRUE
%token PRINT READ

    /* Identifier */
%token ID

    /* Literal */
%token INT_LITERAL
%token REAL_LITERAL
%token STRING_LITERAL

%%
    /*
       Program Units
                     */


Program:
    ProgramName SEMICOLON ProgramBody END ProgramName {
        root=new ProgramNode;
	root-> Name=strdup($1);
	root-> Return_type=strdup("void");
	root->col=@1.first_column;
	root->line=@1.first_line;
	root->child.push_back(ProgramBody);
	
    }
;

ProgramName:
    ID{$$=$1;}
;

ProgramBody:
    DeclarationList{
	ProgramBody=new tempnode;
        ProgramBody->child.push_back(DeclarationList);
	}
 FunctionList{
	 ProgramBody->child.push_back(FunctionList);
} CompoundStatement{
		ProgramBody->child.push_back(compound);
	}
;

DeclarationList:
    Epsilon{DeclarationList=new tempnode;}
    |
    Declarations{DeclarationList=new tempnode;
		DeclarationList->child.push_back(Declarations);
	}
;

Declarations:
    Declaration{
		Declarations=new tempnode;
		Declarations->child.push_back(Declaration);
		
	}
    |
    Declarations Declaration{
		Declarations->child.push_back(Declaration);
}
;

FunctionList:
    Epsilon{FunctionList=new tempnode;}
    |
    Functions{
		FunctionList=new tempnode;
		FunctionList->child.push_back(Functions);
	}
;

Functions:
	FunctionDeclaration{
	Functions=new tempnode;
	Functions->child.push_back(FunctionDeclaration);

}
    |
    Functions FunctionDeclaration{Functions->child.push_back(FunctionDeclaration);}
;

FunctionDeclaration:
    FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS{
	FunctionDeclaration=new FunctionNode;
	} ReturnType SEMICOLON
    CompoundStatement
    END FunctionName{
		FunctionDeclaration->Name=strdup($1);
		FunctionDeclaration->return_type=strdup($6);
		FunctionDeclaration->line=@1.first_line;
		FunctionDeclaration->col=@1.first_column;
		FunctionDeclaration->child.push_back(formalarglist);
		FunctionDeclaration->child.push_back(compound);
		FunctionDeclaration->arg.insert(FunctionDeclaration->arg.begin(),formalarglist->arg.begin(),formalarglist->arg.end());
	}
;

FunctionName:
    ID{$$=$1;}
;

FormalArgList:
    Epsilon{formalarglist=new tempnode;}
    |
    FormalArgs{
	formalarglist=new tempnode;
	formalarglist->child.push_back(formalargs);
	formalarglist->arg.insert(formalarglist->arg.begin(),formalargs->arg.begin(),formalargs->arg.end());
	}
;

FormalArgs:
    FormalArg{
	formalargs=new tempnode;
	formalargs->child.push_back(formalarg);
	formalargs->arg.insert(formalargs->arg.begin(),formalarg->arg.begin(),formalarg->arg.end());
	}
    |
    FormalArgs SEMICOLON FormalArg{
	formalargs->child.push_back(formalarg);
	formalargs->arg.insert(formalargs->arg.end(),formalarg->arg.begin(),formalarg->arg.end());
	}
;

FormalArg:
    IdList COLON Type{
		formalarg=new tempnode;
		for(int i=0;i<countid;i++){
			std::string str;
			str.assign($3);
			if(type==1)formalarg->arg.push_back(str);
			else{
				
				char *k;
				k=scalartype;
				for(int i=0;i<len.size();i++){
					strcat(k,"[");
					char *a=strdup("");
					a[0]=len[i]+48;
					strcat(k,a);
					strcat(k,"]");
				}
				std::string str;
				str.assign(k);
				formalarg->arg.push_back(str);
				len.clear();
			}
		}
		Declaration=new DeclarationNode;
        	Declaration->line=@1.first_line;
        	Declaration->col=@1.first_column;
		formalarg->child.push_back(Declaration);                                                                                Declaration->child.push_back(idList);                                                                                   for(int i=0;i<countid;i++){
                	var =new variableNode;
                	Declaration->child.push_back(var);
                	var->col=Declaration->child[0]->column[i];
                	var->line=@2.first_line;                                                                                                var->Name=Declaration->child[0]->arg[i];
                	var->Type=$3;
                //var->child.push_back(TypeOrConstant);
        	}
		countid=0;
}
;

IdList:
    ID{
	idList=new tempnode;
	std::string str;
	str.assign($1);
	//std::cout<<str<<std::endl;
	idList->arg.push_back(str);
	idList->column.push_back(@1.first_column);
	countid++;		
}
    |
    IdList COMMA ID{
		std::string str;
		str.assign($3);
		//std::cout <<str<<std::endl;
		idList->arg.push_back(str);
		idList->column.push_back(@3.first_column);
		countid++;
	}
;

ReturnType:
    COLON ScalarType{$$=$2;}
    |
    Epsilon{$$=strdup("void");}
;

    /*
       Data Types and Declarations
                                   */

Declaration:
    VAR IdList COLON TypeOrConstant SEMICOLON{
	Declaration=new DeclarationNode;
	Declaration->line=@1.first_line;
	Declaration->col=@1.first_column;
	Declaration->child.push_back(idList);
	for(int i=0;i<countid;i++){
		var =new variableNode;
		Declaration->child.push_back(var);
		var->col=Declaration->child[0]->column[i];
		var->line=@2.first_line;
		var->Name=Declaration->child[0]->arg[i];
		var->Type=$4;
		var->child.push_back(TypeOrConstant);		
	}
	countid=0;	 	
}
;

TypeOrConstant:
    Type{$$=$1;TypeOrConstant=new tempnode;}
    |
    LiteralConstant{
	$$=$1;
	TypeOrConstant=new tempnode;
	TypeOrConstant->child.push_back(constant);

}
;

Type:
    ScalarType{$$=$1;type=1;}
    |
    ArrType{$$=$1;type=2;}
;

ScalarType:
    INTEGER{$$=strdup("integer");}
    |
    REAL{$$=strdup("real");}
    |
    STRING{$$=strdup("string");}
    |
    BOOLEAN{$$=strdup("boolean");}
;

ArrType:
    ArrDecl ScalarType{scalartype=strdup($2);strcat($2,$1);$$=$2;}
;

ArrDecl:
    ARRAY INT_LITERAL TO INT_LITERAL OF{
	char *k=strdup("[");
	strcat(k,$2);
	strcat(k,"...");
	strcat(k,$4);
	strcat(k,"]");
	int s=atoi($4)-atoi($2);
	len.push_back(s);
	$$=k;
	//printf("%s\n",$$);
}
    |
    ArrDecl ARRAY INT_LITERAL TO INT_LITERAL OF{
        char *k=strdup("[");
        strcat(k,$3);
	strcat(k,"...");
	strcat(k,$5);                                                                                                         strcat(k,"]");
        $$=$1;
	int s=atoi($5)-atoi($3);
	len.push_back(s);
	strcat($$,k);
	//printf("%s\n",$$);
}
;

LiteralConstant:
    INT_LITERAL{
	$$=strdup("integer");
	constant=new Constant_value_Node;
	constant->type=1;
	if(atoi($1)>0&&!strncmp($1,"0",1))constant->ivalue=strtol($1,NULL,8);
	else constant->ivalue=atoi($1);
	constant->line=@1.first_line;                                                                                           constant->col=@1.first_column;

}

    |
    REAL_LITERAL{
	$$=strdup("real");
	constant=new Constant_value_Node;
	constant->fvalue=atof($1);                                                                                       	constant->type=2;
	constant->line=@1.first_line;                                                                                           constant->col=@1.first_column;
}
    |
    STRING_LITERAL{
	$$=strdup("string");
	constant=new Constant_value_Node;
	constant->type=3;                                                                                       
	constant->value=$1;
	constant->line=@1.first_line;                                                                                           constant->col=@1.first_column;
}
    |
    TRUE{$$=strdup("boolean");
	constant=new Constant_value_Node;
	constant->type=4;
	constant->line=@1.first_line;                                                                                           constant->col=@1.first_column;                                                                                       	constant->value=strdup("true");
}
    |
    FALSE{
	$$=strdup("boolean");
	constant=new Constant_value_Node;
	constant->type=5;
	constant->line=@1.first_line;                                                                                           constant->col=@1.first_column;                                                                                       
	constant->value=strdup("false");
}
;

    /*
       Statements
                  */

Statement:
    CompoundStatement{
	Statement=new tempnode;
	Statement->child.push_back(compound);
}
    |
    Simple{
	Statement=new tempnode;
        Statement->child.push_back(simple); 	
}
    |
    Condition{
	Statement=new tempnode;
        Statement->child.push_back(If); 
	Statement->child.push_back(Eornot);
}
    |
    While{
	Statement=new tempnode;
        Statement->child.push_back(WH); 
}
    |
    For{
	Statement=new tempnode;
        Statement->child.push_back(F); 
}
    |
    Return{
	Statement=new tempnode;
        Statement->child.push_back(RE); 
}
    |
    FunctionInvokation{
	Statement=new tempnode;
        Statement->child.push_back(CALL); 
}
;

CompoundStatement:
    BEGIN_
    DeclarationList{
	compound=new Compound_Statement;
	compound_stack.push(compound);
        compound->line=@1.first_line;                                                                                           compound->col=@1.first_column;                                                                                          compound->child.push_back(DeclarationList);
}
    StatementList
    END{
	compound=compound_stack.top();	
	compound->child.push_back(StatementList);
	compound_stack.pop();	
}
;

Simple:
    VariableReference ASSIGN Expression SEMICOLON{
	assign=new Assignment_Node;
	assign->line=@2.first_line;
	assign->col=@2.first_column;
	assign->child.push_back(VR);
	assign->child.push_back(E);
	simple=new tempnode;
	simple->child.push_back(assign);	
}
    |
    PRINT Expression SEMICOLON{
	print=new PrintNode;
	print->line=@1.first_line;
	print->col=@1.first_column;
	print->child.push_back(E);
	simple=new tempnode;
        simple->child.push_back(print);		
}
    |
    READ VariableReference SEMICOLON{
	read=new ReadNode;
	read->line=@1.first_line;
	read->col=@1.first_column;
	read->child.push_back(VR);
	simple=new tempnode;
        simple->child.push_back(read);
}
;

VariableReference:
    ID{
	VR=new Variable_Reference_Node;
	VR->line=@1.first_line;
	VR->col=@1.first_column;
	VR->Name=$1;
}
    |
    ID ArrForm{
	VR=new Variable_Reference_Node;                                                                                         VR->line=@1.first_line;
        VR->col=@1.first_column;
	VR->Name=$1;
	VR->child.push_back(AF);
}
;

ArrForm:
    L_BRACKET Expression R_BRACKET{
	AF=new Arrform;
	lbreaket *LB;
	LB=new lbreaket;
	AF->child.push_back(LB);
	AF->child.push_back(E);
	rbreaket *RB;
	RB=new rbreaket;
	AF->child.push_back(RB);		
	}
    |
    ArrForm L_BRACKET Expression R_BRACKET{
	lbreaket *LB;
        LB=new lbreaket;
        AF->child.push_back(LB);
	AF->child.push_back(E);
	rbreaket *RB;
        RB=new rbreaket;
        AF->child.push_back(RB);
}
;

Condition:
    IF Expression THEN
    StatementList{
	If=new ifNode;
	If->line=@1.first_line;
	If->col=@1.first_column;
	If->child.push_back(BO); 
	If->child.push_back(StatementList);
}
    ElseOrNot{
}
    END IF
;

ElseOrNot:
    ELSE
    StatementList{
	Eornot=new tempnode;
	EL=new elsenode;
	Eornot->child.push_back(EL);
	EL->child.push_back(StatementList);
}
    |
    Epsilon{
	Eornot=new tempnode;
}
;

While:
    WHILE Expression DO
    StatementList
    END DO{
	WH=new WhileNode;
	WH->line=@1.first_line;
	WH->col=@1.first_column;
	WH->child.push_back(BO);
	WH->child.push_back(StatementList);
}
;

For:
    FOR ID ASSIGN INT_LITERAL TO INT_LITERAL DO{
	F=new forNode;                                                                                                       F->line=@1.first_line;                                                                                                 F->col=@1.first_column;
	Declaration=new DeclarationNode;
	Declaration->line=@2.first_line;
	Declaration->col=@2.first_column;

	var=new variableNode;
	var->line=@2.first_line;
	var->col=@2.first_column;
	std::string str;
	str.assign($2);
	var->Name=str;
	var->Type=strdup("integer");
	Declaration->child.push_back(var);
	F->child.push_back(Declaration);

	assign=new Assignment_Node;
	assign->line=@3.first_line;
	assign->col=@3.first_column;
	F->child.push_back(assign);
	
	
 	VR=new Variable_Reference_Node;
	VR->line=@2.first_line;
	VR->col=@2.first_column;
	VR->Name=strdup($2);
	constant=new Constant_value_Node;
	constant->line=@4.first_line;
	constant->col=@4.first_column;
	constant->ivalue=atoi($4);
	constant->type=1;
	assign->child.push_back(VR);
	assign->child.push_back(constant);

	constant=new Constant_value_Node;
	constant->line=@6.first_line;
	constant->col=@6.first_column;
	constant->ivalue=atoi($6);
	constant->type=1;                                                                                          
	F->child.push_back(constant);
    }StatementList
    END DO{                                               
	F->child.push_back(StatementList);
}
;

Return:
    RETURN Expression SEMICOLON{
	RE=new returnNode;
	RE->line=@1.first_line;
	RE->col=@1.first_column;
	RE->child.push_back(E);
}
;

FunctionInvokation:
    FunctionCall SEMICOLON
;

FunctionCall:
    ID L_PARENTHESIS ExpressionList R_PARENTHESIS{
	CALL=new functioncallNode;
	CALL->line=@1.first_line;
	CALL->col=@1.first_column;
	CALL->Name=strdup($1);
	CALL->child.push_back(EList);
}
;

ExpressionList:
    Epsilon{
	EList=new tempnode;
}
    |
    Expressions{
	EList=new tempnode;
	EList->child.push_back(Es);
}
;

Expressions:
    Expression{
	Es=new tempnode;
	Es->child.push_back(E);
}
    |
    Expressions COMMA Expression{
	Es->child.push_back(E);
}
;

StatementList:
    Epsilon{
	StatementList=new tempnode;
	
}
    |
    Statements{
	StatementList=new tempnode;
	StatementList->child.push_back(Statements);
	statements_stack.pop();
}
;

Statements:
    Statement{
	Statements=new tempnode;
	statements_stack.push(Statements);
	Statements->child.push_back(Statement);
}
    |
    Statements Statement{
	Statements=statements_stack.top();
	Statements->child.push_back(Statement);
}
;

Expression:
    L_PARENTHESIS Expression R_PARENTHESIS
    |
    MINUS Expression %prec UNARY_MINUS{
	UO=new Unary_Operator_Node;
	UO->line=@2.first_line;
        UO->col=@1.first_column;
        UO->op=strdup("neg");
        UO->child.push_back(E);
        E=new tempnode;                                                                                                         E->child.push_back(UO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;
	BO->child.push_back(E);
	} MULTIPLY Expression{
	BO->child.push_back(E);
	BO->line=@1.first_line;
        BO->col=@3.first_column;
	BO->op=strdup("*");
	E=new tempnode;
	E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;
        BO->child.push_back(E);	
	} DIVIDE Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);
        BO->op=strdup("/");
        E=new tempnode;
        E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} MOD Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);
        BO->op=strdup("mod");
        E=new tempnode;
        E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	}PLUS Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("+");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} MINUS Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("-");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} LESS Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("<");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} LESS_OR_EQUAL Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("<=");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} GREATER Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup(">");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} GREATER_OR_EQUAL Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup(">=");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} EQUAL Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("=");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} NOT_EQUAL Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("<>");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    NOT Expression{
	UO=new Unary_Operator_Node;
	UO->line=@1.first_line;                                                                                                 UO->col=@1.first_column;
	UO->op=strdup("not");
	UO->child.push_back(E);
	E=new tempnode;
	E->child.push_back(UO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} AND Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("and");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    Expression{
	BO=new Binary_Operator_Node;                                                                                            BO->child.push_back(E);
	} OR Expression{
	BO->line=@1.first_line;                                                                                                 BO->col=@3.first_column;
	BO->child.push_back(E);                                                                                                 BO->op=strdup("or");                                                                                                             E=new tempnode;                                                                                                       E->child.push_back(BO);
}
    |
    LiteralConstant{
	E=new tempnode;
	E->child.push_back(constant);	
}
    |
    VariableReference{
	E=new tempnode;
	E->child.push_back(VR);
}
    |
    FunctionCall
;

    /*
       misc
            */
Epsilon:
;
%%
visitor nv;
void printsp(int n){
	for(int i=0;i<n;i++)printf("  ");
}
void dumpAST(Nodebase *m,int depth){
	if(m->dep==2){
	
        }else if(m->dep==1)printsp(depth-1);
	else{
                printsp(depth);
                depth++;
        }
	m->accept(nv);	
	for(int i=0;i<m->child.size();i++){
		//printf("i=%d\n",i);
		dumpAST(m->child[i],depth);
	}
}
void yyerror(const char *msg) {
    fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            LineNum, Buffer, yytext);
    exit(-1);
}

int main(int argc, const char *argv[]) {
    CHECK(argc==3||argc == 2, "Usage: ./parser <filename>\n");

    FILE *fp = fopen(argv[1], "r");

    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    yyparse();
	if(argc==3){
		dumpAST(root,0);
	}
    //freeProgramNode(root);

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
