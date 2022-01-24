#pragma once
#include "visitor/visitor.hpp"
#include "AST/symblotable.hpp"
using namespace std;
class ASTDumper : public ASTVisitorBase
{
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
};

class symbolTableCreator : public ASTVisitorBase
{
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
	int level;
	vector<string> srcode;
        bool symboldumper=true;
        string filename;
        string return_type;
        string para;
        bool check_return_type=false;
	bool check_print_read=false;
        bool check_arr=false;
        bool check_para=false;
        FILE *fp;
        string check_type;
        bool check_condition=false;
        bool check_int=false;
        bool check_type_ans=true;
        bool check_constant=false;
	bool in_func=false;
        bool ans=true;
	int line;
	int col;
        SymbolManager manager;
	string getType(VariableInfo* src){
                string variable_type;
                switch(src->type_set){
                        case SET_SCALAR:
                        case SET_CONSTANT_LITERAL:
                        switch(src->type){
                                case TYPE_INTEGER: variable_type = "integer"; break;
                                case TYPE_REAL:    variable_type = "real"; break;
                                case TYPE_STRING:  variable_type = "string"; break;
                                case TYPE_BOOLEAN: variable_type = "boolean"; break;
                                case TYPE_VOID:    variable_type = "void" ; break;
                                default:           variable_type = "unknown"; break;
                        }
                        break;
                        case SET_ACCUMLATED:
                        switch(src->type){
                                case TYPE_INTEGER: variable_type = "integer"; break;
                                case TYPE_REAL:    variable_type = "real"; break;
                                case TYPE_STRING:  variable_type = "string"; break;
                                case TYPE_BOOLEAN: variable_type = "boolean"; break;
                                default:           variable_type = "unknown"; break;
			}                                                                                                                       variable_type+=" ";
                        for(uint i=0; i<src->array_range.size(); i++){
                                variable_type += "[";
                                variable_type += to_string(src->array_range[i].end - src->array_range[i].start);
                                variable_type += "]";
                        }
                        break;
                        default:

                        variable_type = "default";
                        break;
                }
                return variable_type;
	}
	void getSrcode(){

                std::ifstream fin(filename);

                string s;

                while(getline(fin,s)){

                        srcode.push_back(s);


                                std::size_t found = s.find("//&D-");

                                if(found!=std::string::npos)

                                        manager.dump_symbol=false;


                }

        }
	
	void printerror(int a,int b){
                fprintf(stderr,"    %s\n",srcode[a-1].c_str());
                for(int i=0;i<b-1+4;i++)

                fprintf(stderr," ");

                fprintf(stderr,"^\n");
                ans=false;

        }
        string enumTOstring_op(int n){

                string op[15]={":=","or","and","not","<","<=","=",">",">=","<>","+","-","*","/","mod"};

                return op[n-500];

        }

	bool checktype(string type){
                if(check_type!=type&&check_type!="unknown"){
                        check_type="unknown";
                        return false;
                }
                else return true;
        }
        SymbolEntry* search_by_name(string name){
                SymbolTable T=manager.tables.top();
                for(int i=T.entries.size()-1;i>=0;i++){
                        if(name==T.entries[i].Name)return &(T.entries[i]);
                }
                return NULL;
        }

        void putAC(){
                
           printf("\n|---------------------------------------------|\n");
           printf("|  There is no syntactic and semantic error!  |\n");
           printf("|---------------------------------------------|\n");
        }
	
	

		
};
