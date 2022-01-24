%{
#include <stdint.h>
#include "./y.tab.h"
#include "error.h"

#define LIST                strCat(yytext)
#define TOKEN(t)            {LIST; if (OptTok) printf("<%s>\n", #t);}
#define TOKEN_CHAR(t)       {LIST; if (OptTok) printf("<%c>\n", (t));}
#define TOKEN_STRING(t, s)  {LIST; if (OptTok) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG       512

int32_t LineNum = 1;
char Buffer[MAX_LINE_LENG];

static int32_t OptSrc = 1;
static int32_t OptTok = 1;
static char StringLiteral[MAX_LINE_LENG];
static char *BufferPtr = Buffer;

static void strCat(const char *Text);

%}

integer 0|[1-9][0-9]*
float {integer}\.(0|[0-9]*[1-9])

%x CCOMMENT

%%
    /* Delimiter */
"," { TOKEN_CHAR(','); return ',';}
";" { TOKEN_CHAR(';'); return  ';';}
":" { TOKEN_CHAR(':'); return  ':';}
"(" { TOKEN_CHAR('('); return  '(';}
")" { TOKEN_CHAR(')'); return   ')';}
"[" { TOKEN_CHAR('['); return   '[';}
"]" { TOKEN_CHAR(']'); return    ']';}

    /* Operator */
"+"   { TOKEN_CHAR('+'); return  '+';}
"-"   { TOKEN_CHAR('-'); return   '-';}
"*"   { TOKEN_CHAR('*'); return   '*';}
"/"   { TOKEN_CHAR('/'); return    '/';}
"mod" { TOKEN(mod); return  MOD;}
":="  { TOKEN(:=); return  ASSIGN;}
"<"   { TOKEN_CHAR('<'); return '<';}
"<="  { TOKEN(<=); return  LE;}
"<>"  { TOKEN(<>); return  NE;}
">="  { TOKEN(>=); return  GE;}
">"   { TOKEN_CHAR('>'); return '>';}
"="   { TOKEN_CHAR('='); return  '=';}
"and" { TOKEN(and); return AND;}
"or"  { TOKEN(or); return OR;}
"not" { TOKEN(not); return NOT;}

    /* Keyword */
"array"   { TOKEN(KWarray); return ARRAY;}
"begin"   { TOKEN(KWbegin); return BG;}
"boolean" { TOKEN(KWboolean); return TYPE;}
"def"     { TOKEN(KWdef); }
"do"      { TOKEN(KWdo); return DO;}
"else"    { TOKEN(KWelse); return ELSE;}
"end"     { TOKEN(KWend); return END;}
"false"   { TOKEN(KWfalse); return FALSE;}
"for"     { TOKEN(KWfor); return FOR;}
"integer" { TOKEN(KWinteger); return TYPE;}
"if"      { TOKEN(KWif); return IF;}
"of"      { TOKEN(KWof); return OF;}
"print"   { TOKEN(KWprint); return PRINT;}
"read"    { TOKEN(KWread); return READ;}
"real"    { TOKEN(KWreal); return TYPE;}
"string"  { TOKEN(KWstring); return TYPE;}
"then"    { TOKEN(KWthen); return THEN;}
"to"      { TOKEN(KWto); return TO;}
"true"    { TOKEN(KWtrue); return TRUE;}
"return"  { TOKEN(KWreturn); return RETURN;}
"var"     { TOKEN(KWvar); return VAR;}
"while"   { TOKEN(KWwhile); return WHILE;}

    /* Identifier */
[a-zA-Z][a-zA-Z0-9]* { TOKEN_STRING(id, yytext); return ID;}

    /* Integer (decimal/octal) */
{integer} { TOKEN_STRING(integer, yytext); return INT;}
0[0-7]+   { TOKEN_STRING(oct_integer, yytext); return OCTAL;}

    /* Floating-Point */
{float} { TOKEN_STRING(float, yytext); return FLOAT;}

    /* Scientific Notation [Ee][+-]?[0-9]+ */
({integer}|{float})[Ee][+-]?({integer}) { TOKEN_STRING(scientific, yytext); return SCI;}

    /* String */
\"([^"\n]|\"\")*\" {
    char *YytextPtr = yytext;
    char *StrPtr = StringLiteral;

    /* Condition guard of the end of string literal
       Check only when *YytextPtr == '"' */
    while (*(YytextPtr + 1) != '\0') {
        ++YytextPtr;

        /* Handle the situation of double quotes */
        if (*YytextPtr == '"' && *(YytextPtr + 1) != '\0')
            *StrPtr++ = *YytextPtr++;

        while (*YytextPtr != '"')
            *StrPtr++ = *YytextPtr++;
    }
    *StrPtr = '\0';
    TOKEN_STRING(string, StringLiteral);
	return STRING;
}
    /* Whitespace */
[ \t]+ { LIST; }

    /* Pseudocomment */
"//&"[ST][+-].* {
    LIST;
    char option = yytext[3];
    switch (option) {
    case 'S':
        OptSrc = (yytext[4] == '+') ? 1 : 0;
        break;
    case 'T':
        OptTok = (yytext[4] == '+') ? 1 : 0;
        break;
    }
}

    /* C++ Style Comment */
"//".* { LIST; }

    /* C Style Comment */
"/*"           { LIST; BEGIN(CCOMMENT); }
<CCOMMENT>"*/" { LIST; BEGIN(INITIAL); }
<CCOMMENT>.    { LIST; }

    /* Newline */
<INITIAL,CCOMMENT>\n {
    if (OptSrc)
        printf("%d: %s\n", LineNum, Buffer);
    ++LineNum;
    Buffer[0] = '\0';
    BufferPtr = Buffer;
}

    /* Catch the character which is not accepted by rules above */
. {
    printf("Error at line %d: bad character \"%s\"\n", LineNum, yytext);
    exit(-1);
}

%%

static void strCat(const char *Text) {
    while (*Text) {
        *BufferPtr++ = *Text++;
    }
    *BufferPtr = '\0';
}
