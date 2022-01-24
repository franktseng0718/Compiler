#pragma once
#include <bits/stdc++.h>
#include "AST/ast.hpp"
using namespace std;
class SymbolEntry {
   public:
	string Name;
	string kind;
	int level;
	string type;
	vector<VariableInfo*> attribute;
	bool legal;
	vector<string> attribute_string;
	void operator=(SymbolEntry S){
		Name=S.Name;
		kind=S.kind;
		level=S.level;
		type=S.type;
		attribute=S.attribute;
		legal=S.legal;
		attribute_string=S.attribute_string;
	}
	void getAttribute(){                                                                                                            attribute_string.clear();                                                                                               string temp;                                                                                                            if(this->kind=="function"){
                        for(int i=0;i<attribute.size();i++){
                                temp=getType(attribute[i]);                                         
                                attribute_string.push_back(temp);
                        }
                }
                else if(this->kind=="constant"){
                        switch(this->attribute[0]->type){                                                                                               case TYPE_INTEGER: temp = to_string(this->attribute[0]->int_literal); break;                                            case TYPE_REAL:    temp = to_string(this->attribute[0]->real_literal); break;
                                case TYPE_STRING:  temp = this->attribute[0]->string_literal; break;
                                case TYPE_BOOLEAN: temp = this->attribute[0]->boolean_literal==Boolean_TRUE?"true":"false"; break;
                                default:           temp = "unknown"; break;

                        }
                        attribute_string.push_back(temp);
                }
        }
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
			}
			variable_type+=" ";
			for(uint i=0; i<src->array_range.size(); i++){
				variable_type += "[";
				variable_type += to_string(src->array_range[i].end - src->array_range[i].start);
				variable_type += "]";
			}
			break;
			default:
			
			variable_type = "unknown";
			break;
		}
		return variable_type;
	}
};

class SymbolTable {
  public:
	void addsymbol(string Name,string kind,int level,string type,vector<VariableInfo*> attribute,bool legal)
	{
		SymbolEntry Sentry;
		Sentry.Name=Name;
		Sentry.kind=kind;
		Sentry.level=level;
		Sentry.type=type;
		Sentry.attribute=attribute;
		Sentry.legal=legal;
		entries.push_back(Sentry);
	}
	int level;
	void operator=(SymbolTable C){
		entries=C.entries;	
	}
	SymbolTable operator+(SymbolTable C){
		SymbolTable A;
		A.entries.reserve(C.entries.size());
		A.entries.insert(A.entries.end(),C.entries.begin(),C.entries.end());
		for(auto itr =entries.cbegin();itr!=entries.cend();++itr){
			SymbolEntry B=*itr;
			A.entries.push_back(B);
		}		
		return A;
		

	}
	
  public:
	vector <SymbolEntry> entries;
	
};

class SymbolManager {
  public:
	void pushScope(SymbolTable new_scope){
		if(tables.size()){
			tables.push(new_scope+tables.top());
		}
		else if(tables.size()==0)tables.push(new_scope);
	}
	void popScope(){dumpSymbol(&tables.top());savetables[level].push(tables.top());tables.pop();}

	stack <SymbolTable> tables;
	queue <SymbolTable> savetables[100];
	bool in_func=false;
	bool dump_symbol=true;
	int para=1;
	int level;
	void operator=(SymbolManager C){
		tables=C.tables;
		for(int i=0;i<100;i++)savetables[i]=C.savetables[i];
	} 
	void dumpDemarcation(const char chr){
		for(size_t i=0;i<110;++i){
			printf("%c",chr);
		}
		puts("");
	}
	void dumpSymbol(SymbolTable* ST){
		if(!dump_symbol)return;
		dumpDemarcation('=');
		printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type","Attribute");
		dumpDemarcation('-');
		for(int i=0;i<ST->entries.size();i++){
			if(ST->entries[i].level==level){
			if(ST->entries[i].legal){
				printf("%-33s", ST->entries[i].Name.c_str());
			
			printf("%-11s", ST->entries[i].kind.c_str());
			printf("%d%-10s", ST->entries[i].level, ST->entries[i].level==0?"(global)":"(local)");
			printf("%-17s", ST->entries[i].type.c_str());
			if(ST->entries[i].kind=="constant" || (ST->entries[i].kind=="function"&&(ST->entries[i].attribute).size()>0)){
				ST->entries[i].getAttribute();
				for(int j=0;j<ST->entries[i].attribute_string.size()-1;j++){
					printf("%s, ", ST->entries[i].attribute_string[j].c_str());
				}
				printf("%s", ST->entries[i].attribute_string[ST->entries[i].attribute_string.size()-1].c_str());
				
			}
			puts("");
			}
			}
		}
		dumpDemarcation('-');
		

	}
		
	
};
