%{
#define LIST               strcat(buf, yytext)
#define token(t)           {LIST; if (Opt_T) printf("<%s>\n", #t);}
#define tokenChar(t)       {LIST; if (Opt_T) printf("<%c>\n", (t));}
#define tokenInteger(t, i) {LIST; if (Opt_T) printf("<%s: %d>\n", #t, (i));}
#define tokenString(t, s)  {LIST; if (Opt_T) printf("<%s: %s>\n", #t, (s));}
// Define your token macros here
//  for example :
//    #define tokenScientific(t, s)   <definition>
//    #define tokenFloat(ts)          <definition>
//    #define <any other macros you needed>

#define MAX_LINE_LENG      256

int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf[MAX_LINE_LENG];
char temp[MAX_LINE_LENG];
int i=0;
%}
identifier          [a-zA-Z][a-zA-Z0-9]*
integer	            [-+]?[0]|[1-9][0-9]*
oct_integer         [-+]?[0][0-7][0-7]*
float_num           ([-+]?[0]|[1-9][0-9]*)\.([0-9]*[1-9]|[0])
scientific         (([-+]?([0]|[1-9][0-9]*)\.([0-9]*[1-9]|[0]))|([-+]?([0]|[1-9][0-9]*)))[eE][-+]?([0]|[1-9][0-9]*)
string_constant      ["]([^\n])*["]
c_style_comment    ("//"[^\r\n]*)

%x String C_comment Cpp_comment
%%
"("     { tokenChar('('); }
")"     { tokenChar(')'); }
","     { tokenChar(','); }
";"     { tokenChar(';'); }
":"     { tokenChar(':'); }
"["     { tokenChar('['); }
"]"     { tokenChar(']'); }
"+"     { tokenChar('+'); }
"-"     { tokenChar('-'); }
"*"     { tokenChar('*'); }
"/"     { tokenChar('/'); }
"mod"     { token(mod); }
":="     { token(:=); }
"<"     { token(<); }
"<="     { token(<=); }
"<>"     { token(<>); }
">="     { token(>=); }
">"     { token(>); }
"="     { token(=); }
"and"     { token(and); }
"or"     { token(or); }
"not"     { token(not); }
"array"     { token(KWarray); }
"begin"     { token(KWbegin); }
"boolean"     { token(KWboolean); }
"def"     { token(KWdef); }
"do"     { token(KWdo); }
"else"     { token(KWelse); }
"end"     { token(KWend); }
"false"     { token(KWfalse); }
"for"     { token(KWfor); }
"integer"     { token(KWinteger); }
"if"     { token(KWif); }
"of"     { token(KWof); }
"print"     { token(KWprint); }
"read"     { token(KWread); }
"real"     { token(KWreal); }
"string"     { token(KWstring); }
"then"     { token(KWthen); }
"to"     { token(KWto); }
"true"     { token(KWtrue); }
"return"     { token(KWreturn); }
"var"     { token(KWvar); }
"while"     { token(KWwhile); }
{identifier}  {tokenString(id,yytext);}
{integer}   {tokenString(integer,yytext);}
{oct_integer}  {tokenString(oct_integer,yytext);}
{float_num}   {tokenString(float,yytext);}
{scientific} {tokenString(scientific,yytext);}
(.)*"//&S+"(.)*[\n] {
	Opt_S=1;
	printf("%d: %s",linenum,yytext);
	linenum++;
	memset(buf,0,sizeof(char)*256);	
	buf[0]='\0';
}
(.)*"//&S-"(.)*[\n] {
	Opt_S=0;
	linenum++;
	memset(buf,0,sizeof(char)*256);
	buf[0]='\0';
}
(.)*"//&T-"(.)*[\n] {
	Opt_T=0;
	if(Opt_S)printf("%d: %s",linenum,yytext);
	linenum++;
	memset(buf,0,sizeof(char)*256);
	buf[0]='\0';
}
(.)*"//&T+"(.)*[\n] {
	Opt_T=1;
	if(Opt_S)printf("%d: %s",linenum,yytext);
	linenum++;
	memset(buf,0,sizeof(char)*256);
	buf[0]='\0';
}   
<INITIAL>"\"" {
	LIST;
	BEGIN String;
	i=0;
}
<String>"\"\"" {
	LIST;
	temp[i++]='"';			

}
<String>"\"" {
	
	tokenString(string,temp);
	temp[0]='\0';
	BEGIN INITIAL;
}
<String>. {
	LIST;
	temp[i++]=yytext[0];
	
}
"//" {
	LIST;
	BEGIN Cpp_comment;

}

<Cpp_comment>\n {
	
	LIST;
	if(Opt_S)printf("%d: %s",linenum,buf);
	linenum++;
	memset(buf,0,sizeof(char)*256);
	buf[0]='\0';
	BEGIN INITIAL;

}
<Cpp_comment>. {LIST;}
"/*" {
	LIST;
	BEGIN C_comment;
}
<C_comment>"*/" {
	LIST;
	BEGIN INITIAL;
}
<C_comment>\n {
	LIST;
	if(Opt_S)printf("%d: %s",linenum,buf);
	memset(buf,0,sizeof(char)*256);
	linenum++;
	buf[0]='\0';
}
<C_comment>. {LIST;}










\n      {
          LIST;
          if (Opt_S)
            printf("%d: %s", linenum, buf);
          linenum++;
	memset(buf,0,sizeof(char)*256);
          buf[0] = '\0';
        }
[ \t] {LIST;}
.       {
          /* error */
          printf("Error at line %d: bad character \"%s\"\n", linenum, yytext );
          exit(-1);
        }
%%
int main( int argc, char **argv )
{
  if( argc != 2 ) {
    fprintf( stderr, "Usage: ./scanner [filename]\n" );
    exit(0);
  }
	
  FILE *fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    fprintf( stderr, "Open file error\n" );
    exit(-1);
  }
	
  yyin = fp;

  yylex();

  exit(0);
}
