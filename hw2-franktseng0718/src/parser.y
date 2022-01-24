%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "error.h"

extern int32_t LineNum;   /* declared in scanner.l */
extern char Buffer[512];  /* declared in scanner.l */
extern FILE *yyin;        /* declared by lex */
extern char *yytext;      /* declared by lex */

extern int yylex(void); 
static void yyerror(const char *msg);
%}

%token END VAR ARRAY OF TO BG ASSIGN PRINT READ ID
%token WHILE DO FOR RETURN
%token ID TYPE MOD LE GE NE NOT AND OR IF THEN ELSE INT FLOAT SCI OCTAL TRUE FALSE STRING

%left OR
%left AND
%left NOT
%left '>' '<'
%left '+' '-'
%left '*' '/'
%left NEG
%left PARENTHESES
%%

program_name: programname ';' programbody END programname
		;
programname: identifier
		;
identifier: ID
		;
programbody     :varible_list function_list compound
				;
idList				: /*epsilon*/
					|nonEmptyidList
					;
nonEmptyidList:       identifier  SE
			;
SE :   ',' nonEmptyidList
	|
	;
					
literal_constant	:number
				 	|STRING
					|const_boolean
					;
const_boolean		:TRUE
			   		|FALSE
					;
number		:INT
		 	|OCTAL
			|SCI
			|FLOAT
			;
varible_list	: /*epsilon*/
				|nonEmptyvaribles
				;
nonEmptyvaribles:nonEmptyvaribles varible
				|varible
				;
function_list : /*epsilon*/
			  |nonEmptyfunctions
			  ;
nonEmptyfunctions : function nonEmptyfunctions
				  |function
				  ;
function	: functionName '(' arguments ')' body
			;
body : ':' TYPE ';' functionBody END ID
	|';' functionBody END ID
	;
functionBody: compound
			;
functionName :identifier
			 ;
arguments	: /*epsilon*/
		  | nonEmptyDeclar
			;
nonEmptyDeclar : idList ':' TYPE EMP
			   ;
EMP : nonEmptyDeclar
	| 
	;
varible			:VAR idList ':' DE
				;
DE : TYPE ';'
	| ARRAY int_constant TO int_constant OF array_types ';'
	| literal_constant ';'
	;
array_types		:ARRAY int_constant TO int_constant OF array_types
			 	| TYPE
				;
int_constant	:INT
				;
statements: nonEmptystatements
		  |/*epsilon*/
		  ;
nonEmptystatements : nonEmptystatements statement
				   | statement
				   ;
statement :	compound
		  |	simple
		  | conditional
		  |	while
		  | for
		  | return
		  | function_invocation ';'
		   ;
compound	: BG varible_list statements END
		 ;
simple		:varible_reference ASSIGN expressions ';'
			| PRINT VE ';'
			| READ varible_reference ';'
			;
VE: varible_reference 
	| expressions 
	|STRING 
	;
array_reference		:identifier array_reference_list
				 ;
array_reference_list : /*epsilon*/ /*so only idenfifier in array_reference*/
					 |'[' expression ']' array_reference_list
					 ;
varible_reference : array_reference
				  ;

expressions : expression
			|integer_expression
			|boolean_expr
			;
expression	: '-' expression %prec NEG
		   | expression '+' expression
		   | expression '-' expression
		   | expression '*' expression
		   | expression '/' expression
		   | expression MOD expression %prec '*'
		   | number
		   | identifier
		   | function_invocation
		   | '(' expression ')' %prec PARENTHESES 
		   | array_reference
		   ;

integer_expression : int_constant
				   | identifier
			| '(' integer_expression ')'
				   ;

boolean_expr:expression '>' expression
			|expression '<' expression
			|expression LE expression %prec '>'
			|expression GE expression %prec '>'
			|expression '=' expression
			|expression NE expression %prec '>'
			|expression AND expression %prec AND
			|expression OR  expression %prec OR
			|NOT expression %prec NOT
			|const_boolean
			|identifier
			|function_invocation
			|'(' boolean_expr ')'
			;
function_invocation : identifier'(' expression_list ')'
					;
expression_list 	:/*epsilon*/
				 	|expression
					|expression_list ',' expression
					;
conditional			:IF boolean_expr THEN conditional_body END IF
				| IF '(' boolean_expr ')' THEN  conditional_body END IF
			  ;
conditional_body 	:statements
				  |statements ELSE statements
				;
while				:WHILE boolean_expr DO statements END DO

for					:FOR identifier ASSIGN int_constant TO int_constant DO statements END DO
		;
return 				: RETURN expressions ';'
				/*| RETURN '(' expressions ')' ';'*/
		   ;


%%

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
    CHECK(argc == 2, "Usage: ./parser <filename>\n");

    FILE *fp = fopen(argv[1], "r");

    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    yyparse();

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
