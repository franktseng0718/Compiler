#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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
#line 33 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define END 257
#define VAR 258
#define ARRAY 259
#define OF 260
#define TO 261
#define BG 262
#define ASSIGN 263
#define PRINT 264
#define READ 265
#define ID 266
#define WHILE 267
#define DO 268
#define FOR 269
#define RETURN 270
#define TYPE 271
#define MOD 272
#define LE 273
#define GE 274
#define NE 275
#define NOT 276
#define AND 277
#define OR 278
#define IF 279
#define THEN 280
#define ELSE 281
#define INT 282
#define FLOAT 283
#define SCI 284
#define OCTAL 285
#define TRUE 286
#define FALSE 287
#define STRING 288
#define NEG 289
#define PARENTHESES 290
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    3,    2,    7,    7,    8,    8,    9,    9,
    9,   11,   11,   10,   10,   10,   10,    4,    4,   12,
   12,    5,    5,   14,   14,   15,   18,   18,   19,   16,
   17,   17,   20,   21,   21,   13,   22,   22,   22,   24,
   24,   23,   25,   25,   26,   26,   27,   27,   27,   27,
   27,   27,   27,    6,   28,   28,   28,   36,   36,   37,
   38,   38,   34,   35,   35,   35,   40,   40,   40,   40,
   40,   40,   40,   40,   40,   40,   40,   39,   39,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   33,   42,   42,   42,   29,   43,   43,   30,   31,
   32,
};
static const short yylen[] = {                            2,
    5,    1,    1,    3,    0,    1,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    0,    1,    2,
    1,    0,    1,    2,    1,    5,    6,    4,    1,    1,
    0,    1,    4,    1,    0,    4,    2,    7,    2,    6,
    1,    1,    1,    0,    2,    1,    1,    1,    1,    1,
    1,    1,    2,    4,    4,    3,    3,    2,    2,    2,
    0,    4,    1,    1,    1,    1,    2,    3,    3,    3,
    3,    3,    3,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    1,    4,    0,    1,    3,    6,    1,    3,    6,   10,
    3,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    2,    0,    0,    0,    0,    0,   21,
    8,    0,    0,    0,   30,    0,   23,    0,    0,   20,
    0,    0,    1,    0,    4,   24,    0,    0,    0,   14,
   17,   16,   15,   12,   13,   10,    0,    9,   11,   36,
    7,    0,    0,    0,   32,   42,    0,   37,   39,    0,
    0,    0,    0,    0,    0,    0,   47,    0,    0,   46,
   48,   49,   50,   51,   52,    0,    0,   63,    0,    0,
    0,    0,   14,    0,    0,    0,   74,   89,   78,    0,
    0,    0,    0,    0,   65,    0,   66,    0,    0,    0,
   77,    0,    0,    0,    0,    0,    0,    0,   60,   54,
   45,   53,    0,    0,    0,    0,   26,    0,    0,   76,
    0,    0,    0,   58,   59,   56,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
    0,    0,  101,    0,    0,    0,   79,    0,    0,   34,
   33,   29,    0,    0,    0,   73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   92,    0,   55,    0,    0,    0,
   41,    0,    0,    0,    0,    0,    0,   62,   28,    0,
    0,   38,   99,    0,   98,   96,    0,    0,    0,   27,
    0,    0,    0,    0,   40,  100,
};
static const short yydgoto[] = {                          2,
    3,    7,  109,    8,   16,   57,   43,   13,   37,   77,
   78,    9,   10,   17,   18,   19,   44,  107,  143,   45,
  141,   40,   79,  172,   58,   59,   60,   61,   62,   63,
   64,   65,  110,   67,   82,   83,   91,   99,   85,   86,
   87,  136,  163,
};
static const short yysindex[] = {                      -238,
    0,    0,  -29,    0, -215, -238, -222, -238, -215,    0,
    0,   -4,   21, -238,    0, -175,    0, -238,   58,    0,
  194, -238,    0, -215,    0,    0, -238, -156,   70,    0,
    0,    0,    0,    0,    0,    0,   72,    0,    0,    0,
    0,  295,   84,  109,    0,    0, -100,    0,    0,  -40,
 -238,  -28, -238,  -40,  -28,  -15,    0,  -94,  295,    0,
    0,    0,    0,    0,    0,  112,  -90,    0,  -96,   62,
 -156,  -32,    0,  -32,  -32,  -15,    0,    0,    0,    0,
  125,  132,  133,    0,    0,  127,    0,  116,  143,  -15,
    0,  127,  -58,  -50,  152,  -66,  -32, -235,    0,    0,
    0,    0,  -40, -238, -175,  -54,    0,  -45,  -15,    0,
  -41,  -53,  -23,    0,    0,    0,  -32,  -32,  -32,  -32,
  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,    0,
  295, -156,    0,  295,  -41,  -18,    0,  128,  163,    0,
    0,    0,  -34,  168, -223,    0,  -53,  -41,  -41,  -41,
  -41,  -41,  -41,  -41,  -33,  -33,  -53,  -53,  -41,  -27,
  -21,  -46,  -24,  -32,    0,  116,    0,  -37, -175, -156,
    0,  182,   -7, -156,  295,  -17,  -41,    0,    0,    7,
    2,    0,    0,   -2,    0,    0,    1, -156,  295,    0,
   13,   22, -223,   10,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -229,  226,    0,   27,  -61,    0,
    0,    0,  232,    0,    0,    0,    0,   29,    0,    0,
    0,    0,    0,  260,    0,    0,  -26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   38,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,    0,    0, -247,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  106,    0,    0,    0,   85,
    0,    0,    0,  117,    0,  242,    0,  243,    0,   96,
    0,    0,    0,    0,    0,    0,  111,    0,    0,    0,
    0,    0,    0,  -12,    0,    0,    0,    0,    8,    0,
  -56,   19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0, -236,  142,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   30,  -52,  -48,  -43,
  135,  138,  139,  140,   63,   74,   41,   52,  141,    0,
    0,   49,    0,    0,    0,   -3,    0,    0,    0,    0,
    0,    0,    0,    0,   38,    0,  149,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   38,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  298,    0,  416,  289,    0,   11,  311,    0,    0,  301,
  302,    0,  315,  310,    0,    0,    0,    0,  164,  230,
    0,    0,  240,  146,    6,    0,  276,    0,    0,    0,
    0,    0,  381,   59,   51,    0,  397,  178,  247,  377,
  130,    0,    0,
};
#define YYTABLESIZE 605
static const short yytable[] = {                         75,
  127,  125,   88,  126,   74,  128,   82,   75,  127,   43,
   83,   75,   74,  128,   31,   85,   74,  146,  127,  125,
   44,  126,  165,  128,   97,  164,   25,    1,   35,    5,
    1,    5,   18,   43,   14,  170,   18,   61,   61,   61,
   61,   61,    6,   61,   44,    5,   46,  171,   61,   61,
   61,   61,   61,   21,   61,   61,   61,   61,   61,   67,
   67,   67,   67,   67,   22,   67,   61,   61,   61,   61,
   72,   72,   72,   72,   72,   98,   72,   67,   67,   67,
   67,   70,   70,   70,   70,   70,   24,   70,   72,   72,
   72,   72,   71,   71,   71,   71,   71,   27,   71,   70,
   70,   70,   70,   68,   95,   68,   68,   68,   81,   89,
   71,   71,   71,   71,   69,  142,   69,   69,   69,  106,
  105,   68,   68,   68,   68,   46,   76,   76,   48,   76,
   49,   76,   69,   69,   69,   69,  160,   61,   61,  162,
   61,   69,   61,   76,   76,   76,   76,   61,   61,   70,
   61,   93,   61,  139,   93,   61,   61,   61,   77,   77,
   71,   77,  100,   77,   61,   61,   61,   61,  127,  125,
  102,  126,  103,  128,  104,   63,   77,   77,   77,  142,
  185,   93,   94,  114,   96,   94,  124,  129,  123,   95,
  115,  116,   95,   86,  192,   19,   87,   80,   81,   84,
   19,  130,   19,   19,   19,   19,   98,   19,   19,  131,
  133,   88,  132,  134,  145,   82,  144,   19,  117,   83,
  166,  167,  168,   88,   85,    1,  169,   82,  179,  173,
  117,   83,  176,    1,  175,   72,   85,    1,  117,  174,
  182,   73,   31,   32,   33,   34,   35,   72,  117,   30,
   31,   32,   33,   30,   31,   32,   33,   34,   35,   61,
  183,  186,  188,  187,   61,  189,  190,   47,   61,   61,
   61,   61,  193,   61,   61,   61,   61,  196,  194,   61,
   61,   61,   61,    5,   61,   61,   67,   61,   22,    6,
   25,   67,   67,   67,   44,   67,   67,   72,   67,   61,
   64,   61,   72,   72,   72,   97,   72,   72,   70,   72,
  108,   23,   42,   70,   70,   70,   12,   70,   70,   71,
   70,   38,   39,   20,   71,   71,   71,   26,   71,   71,
   68,   71,  180,  140,  101,   68,   68,   68,  195,   68,
   68,   69,   68,  178,  138,    0,   69,   69,   69,    0,
   69,   69,   91,   69,    0,    0,   76,   76,   76,   76,
    0,   76,   76,   90,   91,    0,    0,   61,   61,   61,
   61,  161,   61,   61,    0,   90,    0,   61,   61,   61,
   61,    0,   61,   61,    0,    0,    0,    0,   77,   77,
   77,   77,    0,   77,   77,    0,    0,    0,  117,  118,
  119,  120,   86,  121,  122,   87,   80,   81,   84,  181,
    0,    0,    0,  184,   86,    4,    0,   87,   80,   81,
   84,   11,   66,   15,    0,    0,    0,  191,   92,    4,
   80,   92,   80,   15,   80,   80,    0,   41,   68,   66,
    0,    0,   11,    0,    0,    0,   84,   68,  111,    0,
  112,  113,   28,    0,    0,   68,    0,   56,    0,    0,
    0,    0,    0,    0,   29,   76,   88,   90,   94,   76,
   90,    0,    0,  135,   56,   30,   31,   32,   33,   34,
   35,   36,    0,   80,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  147,  148,  149,  150,  151,  152,  153,
  154,  155,  156,  157,  158,  159,    0,    0,    0,    0,
    0,   66,    0,  137,   66,    0,   18,    0,   76,   11,
    0,   18,    0,   18,   18,   18,   18,   68,   18,   18,
   68,    0,    0,    0,    0,    0,    0,    0,   18,    0,
  177,    0,    0,    0,    0,    0,   56,    0,    0,   56,
    0,    0,    0,    0,    0,   66,   24,    0,   50,   51,
    1,   52,    0,   53,   54,    0,    0,    0,    0,   66,
    0,   68,    0,   55,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   68,    0,    0,    0,    0,
   56,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   56,
};
static const short yycheck[] = {                         40,
   42,   43,   59,   45,   45,   47,   59,   40,   42,  257,
   59,   40,   45,   47,   41,   59,   45,   41,   42,   43,
  257,   45,   41,   47,   40,   44,   16,  266,   41,   59,
  266,   58,  262,  281,  257,  259,  266,   41,   42,   43,
   44,   45,  258,   47,  281,   58,  282,  271,   41,   42,
   43,   44,   45,   58,   47,   59,   60,   61,   62,   41,
   42,   43,   44,   45,   44,   47,   59,   60,   61,   62,
   41,   42,   43,   44,   45,   91,   47,   59,   60,   61,
   62,   41,   42,   43,   44,   45,  262,   47,   59,   60,
   61,   62,   41,   42,   43,   44,   45,   40,   47,   59,
   60,   61,   62,   41,   54,   43,   44,   45,   50,   51,
   59,   60,   61,   62,   41,  105,   43,   44,   45,   58,
   59,   59,   60,   61,   62,  282,   42,   43,   59,   45,
   59,   47,   59,   60,   61,   62,  131,   42,   43,  134,
   45,   58,   47,   59,   60,   61,   62,   42,   43,   41,
   45,   41,   47,  103,   44,   60,   61,   62,   42,   43,
  261,   45,  257,   47,   59,   60,   61,   62,   42,   43,
   59,   45,  263,   47,  271,   59,   60,   61,   62,  169,
  175,   52,   41,   59,   55,   44,   60,   61,   62,   41,
   59,   59,   44,   59,  189,  257,   59,   59,   59,   59,
  262,   59,  264,  265,  266,  267,   91,  269,  270,  268,
   59,  268,  263,  280,  260,  268,  271,  279,  272,  268,
   93,   59,  257,  280,  268,  266,   59,  280,  266,  257,
  272,  280,  257,  266,  281,  276,  280,  266,  272,  261,
   59,  282,  283,  284,  285,  286,  287,  276,  272,  282,
  283,  284,  285,  282,  283,  284,  285,  286,  287,  263,
  268,  279,  261,  257,  268,  268,  266,   28,  272,  273,
  274,  275,  260,  277,  278,  268,  280,  268,  257,  272,
  273,  274,  275,   58,  277,  278,  268,  280,  262,   58,
  262,  273,  274,  275,  257,  277,  278,  268,  280,  263,
   59,   59,  273,  274,  275,  257,  277,  278,  268,  280,
   71,   14,   24,  273,  274,  275,    6,  277,  278,  268,
  280,   21,   21,    9,  273,  274,  275,   18,  277,  278,
  268,  280,  169,  104,   59,  273,  274,  275,  193,  277,
  278,  268,  280,  166,   98,   -1,  273,  274,  275,   -1,
  277,  278,  268,  280,   -1,   -1,  272,  273,  274,  275,
   -1,  277,  278,  268,  280,   -1,   -1,  272,  273,  274,
  275,  132,  277,  278,   -1,  280,   -1,  272,  273,  274,
  275,   -1,  277,  278,   -1,   -1,   -1,   -1,  272,  273,
  274,  275,   -1,  277,  278,   -1,   -1,   -1,  272,  273,
  274,  275,  268,  277,  278,  268,  268,  268,  268,  170,
   -1,   -1,   -1,  174,  280,    0,   -1,  280,  280,  280,
  280,    6,   42,    8,   -1,   -1,   -1,  188,   52,   14,
   50,   55,   52,   18,   54,   55,   -1,   22,   42,   59,
   -1,   -1,   27,   -1,   -1,   -1,   50,   51,   72,   -1,
   74,   75,  259,   -1,   -1,   59,   -1,   42,   -1,   -1,
   -1,   -1,   -1,   -1,  271,   50,   51,   52,   53,   54,
   55,   -1,   -1,   97,   59,  282,  283,  284,  285,  286,
  287,  288,   -1,  103,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  117,  118,  119,  120,  121,  122,  123,
  124,  125,  126,  127,  128,  129,   -1,   -1,   -1,   -1,
   -1,  131,   -1,   98,  134,   -1,  257,   -1,  103,  104,
   -1,  262,   -1,  264,  265,  266,  267,  131,  269,  270,
  134,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  279,   -1,
  164,   -1,   -1,   -1,   -1,   -1,  131,   -1,   -1,  134,
   -1,   -1,   -1,   -1,   -1,  175,  262,   -1,  264,  265,
  266,  267,   -1,  269,  270,   -1,   -1,   -1,   -1,  189,
   -1,  175,   -1,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  189,   -1,   -1,   -1,   -1,
  175,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  189,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"END","VAR","ARRAY","OF","TO","BG","ASSIGN","PRINT",
"READ","ID","WHILE","DO","FOR","RETURN","TYPE","MOD","LE","GE","NE","NOT","AND",
"OR","IF","THEN","ELSE","INT","FLOAT","SCI","OCTAL","TRUE","FALSE","STRING",
"NEG","PARENTHESES",
};
static const char *yyrule[] = {
"$accept : program_name",
"program_name : programname ';' programbody END programname",
"programname : identifier",
"identifier : ID",
"programbody : varible_list function_list compound",
"idList :",
"idList : nonEmptyidList",
"nonEmptyidList : nonEmptyidList ',' identifier",
"nonEmptyidList : identifier",
"literal_constant : number",
"literal_constant : STRING",
"literal_constant : const_boolean",
"const_boolean : TRUE",
"const_boolean : FALSE",
"number : INT",
"number : OCTAL",
"number : SCI",
"number : FLOAT",
"varible_list :",
"varible_list : nonEmptyvaribles",
"nonEmptyvaribles : nonEmptyvaribles varible",
"nonEmptyvaribles : varible",
"function_list :",
"function_list : nonEmptyfunctions",
"nonEmptyfunctions : function nonEmptyfunctions",
"nonEmptyfunctions : function",
"function : functionName '(' arguments ')' body",
"body : ':' TYPE ';' functionBody END ID",
"body : ';' functionBody END ID",
"functionBody : compound",
"functionName : identifier",
"arguments :",
"arguments : nonEmptyDeclar",
"nonEmptyDeclar : idList ':' TYPE EMP",
"EMP : nonEmptyDeclar",
"EMP :",
"varible : VAR idList ':' DE",
"DE : TYPE ';'",
"DE : ARRAY int_constant TO int_constant OF array_types ';'",
"DE : literal_constant ';'",
"array_types : ARRAY int_constant TO int_constant OF array_types",
"array_types : TYPE",
"int_constant : INT",
"statements : nonEmptystatements",
"statements :",
"nonEmptystatements : nonEmptystatements statement",
"nonEmptystatements : statement",
"statement : compound",
"statement : simple",
"statement : conditional",
"statement : while",
"statement : for",
"statement : return",
"statement : function_invocation ';'",
"compound : BG varible_list statements END",
"simple : varible_reference ASSIGN expressions ';'",
"simple : PRINT VE ';'",
"simple : READ varible_reference ';'",
"VE : varible_reference ';'",
"VE : expressions ';'",
"array_reference : identifier array_reference_list",
"array_reference_list :",
"array_reference_list : '[' integer_expression ']' array_reference_list",
"varible_reference : array_reference",
"expressions : expression",
"expressions : integer_expression",
"expressions : boolean_expr",
"expression : '-' expression",
"expression : expression '+' expression",
"expression : expression '-' expression",
"expression : expression '*' expression",
"expression : expression '/' expression",
"expression : expression MOD expression",
"expression : '(' expression ')'",
"expression : number",
"expression : identifier",
"expression : function_invocation",
"expression : array_reference",
"integer_expression : int_constant",
"integer_expression : identifier",
"boolean_expr : expression '>' expression",
"boolean_expr : expression '<' expression",
"boolean_expr : expression LE expression",
"boolean_expr : expression GE expression",
"boolean_expr : expression '=' expression",
"boolean_expr : expression NE expression",
"boolean_expr : expression AND expression",
"boolean_expr : expression OR expression",
"boolean_expr : NOT expression",
"boolean_expr : const_boolean",
"boolean_expr : identifier",
"boolean_expr : function_invocation",
"function_invocation : identifier '(' expression_list ')'",
"expression_list :",
"expression_list : expression",
"expression_list : expression_list ',' expression",
"conditional : IF boolean_expr THEN conditional_body END IF",
"conditional_body : statements",
"conditional_body : statements ELSE statements",
"while : WHILE boolean_expr DO statements END DO",
"for : FOR identifier ASSIGN int_constant TO int_constant DO statements END DO",
"return : RETURN expressions ';'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 181 "parser.y"

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
#line 529 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
