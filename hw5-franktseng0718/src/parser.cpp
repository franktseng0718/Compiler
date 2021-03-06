/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "AST/ast.hpp"
#include "AST/program.hpp"
#include "AST/declaration.hpp"
#include "AST/variable.hpp"
#include "AST/constant_value.hpp"
#include "AST/function.hpp"
#include "AST/compound_statement.hpp"
#include "AST/assignment.hpp"
#include "AST/print.hpp"
#include "AST/read.hpp"
#include "AST/variable_reference.hpp"
#include "AST/binary_operator.hpp"
#include "AST/unary_operator.hpp"
#include "AST/if.hpp"
#include "AST/while.hpp"
#include "AST/for.hpp"
#include "AST/return.hpp"
#include "AST/function_call.hpp"
#include "AST/ASTDumper.hpp"
#include "semantic/SemanticAnalyzer.hpp"
#include "semantic/SymbolTable.hpp"
#include "semantic/ErrorMsg.hpp"
#include "semantic/DumpSymbolTable.hpp"
#include "semantic/cg.hpp"
#include "core/error.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstring>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

using namespace std;

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
extern int32_t OptDum;

/* Declared by lex */
extern FILE *yyin;
extern char *yytext;

extern "C" int yylex(void);
extern "C" int yyparse();

static void yyerror(const char *msg);

extern int yylex_destroy(void); // Memory_Free

/* Datatype for Return Non-terminals */
struct id_info{
    string name;
    uint32_t line_number;
    uint32_t col_number;
};

static Node AST;


#line 140 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 75 "parser.y" /* yacc.c:355  */
 #include "AST/ast.hpp" 
#line 76 "parser.y" /* yacc.c:355  */
 #include "AST/program.hpp" 
#line 77 "parser.y" /* yacc.c:355  */
 #include "AST/declaration.hpp" 
#line 78 "parser.y" /* yacc.c:355  */
 #include "AST/variable.hpp" 
#line 79 "parser.y" /* yacc.c:355  */
 #include "AST/constant_value.hpp" 
#line 80 "parser.y" /* yacc.c:355  */
 #include "AST/function.hpp" 
#line 81 "parser.y" /* yacc.c:355  */
 #include "AST/compound_statement.hpp" 
#line 82 "parser.y" /* yacc.c:355  */
 #include "AST/assignment.hpp" 
#line 83 "parser.y" /* yacc.c:355  */
 #include "AST/print.hpp" 
#line 84 "parser.y" /* yacc.c:355  */
 #include "AST/read.hpp" 
#line 85 "parser.y" /* yacc.c:355  */
 #include "AST/variable_reference.hpp" 
#line 86 "parser.y" /* yacc.c:355  */
 #include "AST/binary_operator.hpp" 
#line 87 "parser.y" /* yacc.c:355  */
 #include "AST/unary_operator.hpp" 
#line 88 "parser.y" /* yacc.c:355  */
 #include "AST/if.hpp" 
#line 89 "parser.y" /* yacc.c:355  */
 #include "AST/while.hpp" 
#line 90 "parser.y" /* yacc.c:355  */
 #include "AST/for.hpp" 
#line 91 "parser.y" /* yacc.c:355  */
 #include "AST/return.hpp" 
#line 92 "parser.y" /* yacc.c:355  */
 #include "AST/function_call.hpp" 
#line 93 "parser.y" /* yacc.c:355  */
 #include "visitor/visitor.hpp" 
#line 94 "parser.y" /* yacc.c:355  */
 #include "semantic/SemanticAnalyzer.hpp" 
#line 95 "parser.y" /* yacc.c:355  */
 #include "semantic/SymbolTable.hpp" 
#line 96 "parser.y" /* yacc.c:355  */
 #include "semantic/ErrorMsg.hpp" 
#line 97 "parser.y" /* yacc.c:355  */
 #include "semantic/DumpSymbolTable.hpp" 

#line 217 "parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMA = 258,
    SEMICOLON = 259,
    COLON = 260,
    L_PARENTHESIS = 261,
    R_PARENTHESIS = 262,
    L_BRACKET = 263,
    R_BRACKET = 264,
    ASSIGN = 265,
    OR = 266,
    AND = 267,
    NOT = 268,
    LESS = 269,
    LESS_OR_EQUAL = 270,
    EQUAL = 271,
    GREATER = 272,
    GREATER_OR_EQUAL = 273,
    NOT_EQUAL = 274,
    PLUS = 275,
    MINUS = 276,
    MULTIPLY = 277,
    DIVIDE = 278,
    MOD = 279,
    UNARY_MINUS = 280,
    ARRAY = 281,
    BOOLEAN = 282,
    INTEGER = 283,
    REAL = 284,
    STRING = 285,
    END = 286,
    BEGIN_ = 287,
    DO = 288,
    ELSE = 289,
    FOR = 290,
    IF = 291,
    THEN = 292,
    WHILE = 293,
    DEF = 294,
    OF = 295,
    TO = 296,
    RETURN = 297,
    VAR = 298,
    FALSE = 299,
    TRUE = 300,
    PRINT = 301,
    READ = 302,
    ID = 303,
    INT_LITERAL = 304,
    REAL_LITERAL = 305,
    STRING_LITERAL = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 100 "parser.y" /* yacc.c:355  */

    int    val;
    double dval;
    char*  text;

    enum enumOperator op_type;

    Node      node;
    NodeList* node_list_ptr;

    struct NodeWithTypeList*           node_w_type_list_ptr;
    vector<struct NodeWithTypeList*>*  node_w_type_list_ptr_list_ptr;

    vector<struct id_info>* id_list_ptr;
    VariableInfo*           variable_info_ptr;

#line 298 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 329 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   204,   204,   227,   242,   246,   252,   257,   264,   268,
     274,   279,   286,   336,   345,   349,   355,   360,   367,   409,
     417,   427,   431,   443,   522,   526,   532,   536,   542,   548,
     554,   560,   568,   581,   588,   595,   602,   609,   619,   626,
     639,   643,   647,   651,   655,   659,   663,   669,   684,   694,
     703,   714,   727,   741,   746,   753,   769,   774,   780,   794,
     872,   883,   889,   904,   908,   914,   919,   926,   930,   936,
     941,   948,   952,   962,   973,   984,   995,  1006,  1017,  1028,
    1039,  1050,  1061,  1072,  1083,  1093,  1104,  1115,  1124,  1129,
    1138
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "SEMICOLON", "COLON",
  "L_PARENTHESIS", "R_PARENTHESIS", "L_BRACKET", "R_BRACKET", "ASSIGN",
  "OR", "AND", "NOT", "LESS", "LESS_OR_EQUAL", "EQUAL", "GREATER",
  "GREATER_OR_EQUAL", "NOT_EQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "MOD", "UNARY_MINUS", "ARRAY", "BOOLEAN", "INTEGER", "REAL", "STRING",
  "END", "BEGIN_", "DO", "ELSE", "FOR", "IF", "THEN", "WHILE", "DEF", "OF",
  "TO", "RETURN", "VAR", "FALSE", "TRUE", "PRINT", "READ", "ID",
  "INT_LITERAL", "REAL_LITERAL", "STRING_LITERAL", "$accept", "Program",
  "ProgramName", "DeclarationList", "Declarations", "FunctionList",
  "Functions", "FunctionDeclaration", "FunctionName", "FormalArgList",
  "FormalArgs", "FormalArg", "IdList", "ReturnType", "Declaration",
  "TypeOrConstant", "Type", "ScalarType", "ArrType", "ArrDecl",
  "LiteralConstant", "Statement", "CompoundStatement", "Simple",
  "VariableReference", "ArrForm", "Condition", "ElseOrNot", "While", "For",
  "Return", "FunctionInvokation", "FunctionCall", "ExpressionList",
  "Expressions", "StatementList", "Statements", "Expression", "Epsilon", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,  -116,    28,    27,  -116,    -1,     0,     1,    -1,  -116,
    -116,  -116,    13,  -116,     6,     1,  -116,    37,  -116,  -116,
       8,    -4,    -1,     2,  -116,     0,  -116,     9,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,    40,  -116,  -116,
    -116,   -15,  -116,    82,   -27,    50,    59,  -116,    24,  -116,
      26,  -116,    16,  -116,    20,    60,    60,    60,    60,    21,
      31,  -116,  -116,  -116,    70,  -116,  -116,  -116,  -116,  -116,
      83,    71,    82,  -116,  -116,    81,     0,    25,    54,    65,
      97,    60,    60,    60,  -116,  -116,  -116,   137,   161,   184,
     205,   105,   111,    60,    60,   108,    60,  -116,  -116,  -116,
     104,   115,  -116,  -116,  -116,    86,    72,    73,   244,   314,
    -116,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    82,    82,  -116,  -116,  -116,   131,
     136,   290,  -116,   260,    60,   226,  -116,     6,  -116,   100,
     101,  -116,   303,   314,    55,    55,    55,    55,    55,    55,
     -16,   -16,  -116,  -116,  -116,   107,   112,  -116,    60,  -116,
     276,  -116,   113,  -116,    96,    82,   116,  -116,   129,   290,
    -116,     1,   130,  -116,   110,  -116,  -116,    82,  -116,   133,
     132,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,    90,     0,    90,     5,     6,
       4,    19,     0,    13,     0,     9,    10,     0,     8,     7,
       0,     0,    90,     0,    11,    90,    20,     0,    31,    28,
      29,    30,    39,    38,    35,    36,    37,     0,    24,    26,
      27,     0,    25,    90,     0,     0,    15,    16,     0,    14,
       0,    23,     0,    32,     0,     0,     0,     0,     0,     0,
      51,    69,    40,    41,     0,    42,    43,    44,    45,    46,
       0,     0,    68,    67,     2,    90,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,     0,     0,     0,
       0,    51,     0,    90,     0,    52,     0,    61,    47,    70,
       0,     0,    22,    17,    18,     0,     0,     0,     0,    84,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    90,    60,    49,    50,     0,
      64,    65,    63,     0,     0,     0,    21,     0,    33,     0,
       0,    71,    86,    85,    78,    79,    82,    80,    81,    83,
      76,    77,    73,    74,    75,    90,     0,    62,     0,    53,
       0,    48,     0,    34,     0,    90,     0,    57,     0,    66,
      54,     0,     0,    56,     0,    58,    12,    90,    55,     0,
       0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   122,   145,  -116,  -116,  -116,   153,    -2,  -116,
    -116,    94,   165,  -116,   178,  -116,   114,   -36,  -116,  -116,
     166,   117,   -10,  -116,   -40,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,   -42,  -116,  -116,  -115,  -116,   -22,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    14,    15,    16,    17,    45,
      46,    47,    48,   101,     9,    37,    38,    39,    40,    41,
      84,    61,    62,    63,    85,    95,    65,   166,    66,    67,
      68,    69,    86,   129,   130,    71,    72,    87,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    70,    18,    64,    23,    53,   121,   122,   123,   155,
     156,    52,    28,    29,    30,    31,    20,    10,    21,    92,
      49,     1,    27,    28,    29,    30,    31,    20,     4,    77,
      70,     5,    64,    44,    88,    89,    90,    93,    22,    94,
      32,    33,     6,    25,    51,    34,    35,    36,    11,    13,
     173,    27,    28,    29,    30,    31,    26,    75,    50,   108,
     109,   110,   179,    76,   136,    79,    81,    78,    80,    91,
     102,   131,   133,    82,   135,   119,   120,   121,   122,   123,
      96,    83,    70,    70,    64,    64,   100,    97,   132,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    98,   105,    32,    33,   106,   107,    60,    34,
      35,    36,   160,    94,    22,   128,   134,    54,    55,   137,
      56,   139,   140,    70,    57,    64,   138,   162,    58,    59,
      60,    28,    29,    30,    31,    70,   169,    64,   157,   158,
     163,   165,   164,   168,   171,   172,   178,   174,   111,   112,
     167,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   175,   177,   180,   181,    74,    43,    24,   176,
     103,    12,   111,   112,   124,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    19,    42,   126,    99,
       0,   104,     0,     0,   125,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   127,
       0,     0,     0,     0,     0,     0,   111,   112,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     161,     0,     0,     0,     0,     0,     0,   111,   112,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   141,     0,     0,     0,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   159,
       0,   111,   112,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   170,     0,   111,   112,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   111,   112,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   112,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123
};

static const yytype_int16 yycheck[] =
{
       5,    43,     7,    43,    14,    41,    22,    23,    24,   124,
     125,    26,    27,    28,    29,    30,     3,    22,     5,    59,
      25,    48,    26,    27,    28,    29,    30,     3,     0,     5,
      72,     4,    72,    31,    56,    57,    58,     6,    32,     8,
      44,    45,    43,     6,     4,    49,    50,    51,    48,    48,
     165,    26,    27,    28,    29,    30,    48,     7,    49,    81,
      82,    83,   177,     4,   100,    49,     6,    41,    48,    48,
      75,    93,    94,    13,    96,    20,    21,    22,    23,    24,
      10,    21,   124,   125,   124,   125,     5,     4,    93,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    31,    49,    44,    45,    41,    10,    48,    49,
      50,    51,   134,     8,    32,     4,     8,    35,    36,     4,
      38,    49,    49,   165,    42,   165,    40,   137,    46,    47,
      48,    27,    28,    29,    30,   177,   158,   177,     7,     3,
      40,    34,    41,    31,    31,    49,    36,    31,    11,    12,
     155,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    33,    33,    31,    33,    44,    22,    15,   171,
      76,     6,    11,    12,    37,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     8,    21,     4,    72,
      -1,    77,    -1,    -1,    33,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     7,    -1,    -1,    -1,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     9,
      -1,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     9,    -1,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    53,    54,     0,     4,    43,    55,    56,    66,
      90,    48,    64,    48,    57,    58,    59,    60,    90,    66,
       3,     5,    32,    74,    59,     6,    48,    26,    27,    28,
      29,    30,    44,    45,    49,    50,    51,    67,    68,    69,
      70,    71,    72,    55,    31,    61,    62,    63,    64,    90,
      49,     4,    26,    69,    35,    36,    38,    42,    46,    47,
      48,    73,    74,    75,    76,    78,    80,    81,    82,    83,
      84,    87,    88,    90,    54,     7,     4,     5,    41,    49,
      48,     6,    13,    21,    72,    76,    84,    89,    89,    89,
      89,    48,    76,     6,     8,    77,    10,     4,    31,    73,
       5,    65,    90,    63,    68,    49,    41,    10,    89,    89,
      89,    11,    12,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    37,    33,     4,     4,     4,    85,
      86,    89,    90,    89,     8,    89,    69,     4,    40,    49,
      49,     7,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    87,    87,     7,     3,     9,
      89,     4,    74,    40,    41,    34,    79,    90,    31,    89,
       9,    31,    49,    87,    31,    33,    60,    33,    36,    87,
      31,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    75,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    81,
      82,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     9,     1,     1,     1,     1,     3,     3,     1,
       3,     2,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       3,     1,     2,     3,     4,     7,     2,     1,     6,    10,
       3,     2,     4,     1,     1,     1,     3,     1,     1,     1,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     1,     1,     1,
       0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 204 "parser.y" /* yacc.c:1646  */
    {
        // Program Node (Also root Node)
        string return_type = "void";
        AST = new ProgramNode(
            (yylsp[-6]).first_line,
            (yylsp[-6]).first_column,
            string((yyvsp[-6].text)),
            return_type,
            (yyvsp[-4].node_list_ptr),
            (yyvsp[-3].node_list_ptr),
            (yyvsp[-2].node),
            (yylsp[0]).first_line,
            (yylsp[0]).first_column,
            string((yyvsp[0].text))
        );

        // Memory_Free
        free((yyvsp[-6].text));
        free((yyvsp[0].text));
    }
#line 1685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 227 "parser.y" /* yacc.c:1646  */
    {
        (yyval.text) = strdup((yyvsp[0].text));

        // Memory_Free
        free((yyvsp[0].text));
    }
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 242 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = nullptr;
    }
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 246 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = (yyvsp[0].node_list_ptr);
    }
#line 1712 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 252 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = new NodeList();
        (yyval.node_list_ptr)->push_back((yyvsp[0].node));
    }
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 257 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1].node_list_ptr)->push_back((yyvsp[0].node));
        (yyval.node_list_ptr) = (yyvsp[-1].node_list_ptr);
    }
#line 1730 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 264 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = nullptr;
    }
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 268 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = (yyvsp[0].node_list_ptr);
    }
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 274 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = new NodeList();
        (yyval.node_list_ptr)->push_back((yyvsp[0].node));
    }
#line 1755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 279 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1].node_list_ptr)->push_back((yyvsp[0].node));
        (yyval.node_list_ptr) = (yyvsp[-1].node_list_ptr);
    }
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 288 "parser.y" /* yacc.c:1646  */
    {
        // Function Node
        vector<VariableInfo*> prototype;
        //NodeList* parameters = new NodeList();
        
        // Disassemble FormalArgList (node w type list ptr list ptr)
        if ((yyvsp[-6].node_w_type_list_ptr_list_ptr)!=nullptr)
            for(uint i=0; i<(yyvsp[-6].node_w_type_list_ptr_list_ptr)->size(); i++){
                for(uint j=0; j<(*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->counter; j++){
                    // put type (VariableInfo*)
                    // duplicate (eliminate hierarchy problem)
                    VariableInfo* dupTemp = new VariableInfo();
                    dupTemp->type_set = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->type_set;
                    dupTemp->type = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->type;
                    dupTemp->array_range = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->array_range;
                    dupTemp->int_literal = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->int_literal;
                    dupTemp->real_literal = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->real_literal;
                    dupTemp->string_literal = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->string_literal;
                    dupTemp->boolean_literal = (*(yyvsp[-6].node_w_type_list_ptr_list_ptr))[i]->type->boolean_literal;
                    
                    prototype.push_back(dupTemp);
                }   
            }
        else {
            //delete parameters;
            //parameters = nullptr;
        }

        (yyval.node) = new FunctionNode(
            (yylsp[-8]).first_line,
            (yylsp[-8]).first_column,
            string((yyvsp[-8].text)),
            (yyvsp[-6].node_w_type_list_ptr_list_ptr),
            (yyvsp[-4].variable_info_ptr),
            (yyvsp[-2].node),
            (yylsp[0]).first_line,
            (yylsp[0]).first_column,
            string((yyvsp[0].text)),
            prototype
        );

        // Memory_Free
        free((yyvsp[-8].text));
        free((yyvsp[0].text));
    }
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 336 "parser.y" /* yacc.c:1646  */
    {
        (yyval.text) = strdup((yyvsp[0].text));
        
        // Memory_Free
        free((yyvsp[0].text));
    }
#line 1825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 345 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_w_type_list_ptr_list_ptr) = nullptr;
    }
#line 1833 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 349 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_w_type_list_ptr_list_ptr) = (yyvsp[0].node_w_type_list_ptr_list_ptr);
    }
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 355 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_w_type_list_ptr_list_ptr) = new vector<NodeWithTypeList*>();
        (yyval.node_w_type_list_ptr_list_ptr)->push_back((yyvsp[0].node_w_type_list_ptr));
    }
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 360 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].node_w_type_list_ptr_list_ptr)->push_back((yyvsp[0].node_w_type_list_ptr));
        (yyval.node_w_type_list_ptr_list_ptr) = (yyvsp[-2].node_w_type_list_ptr_list_ptr);
    }
#line 1859 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 367 "parser.y" /* yacc.c:1646  */
    {
        // Declaration Node (but location is not KWvar)
        (yyval.node_w_type_list_ptr) = new NodeWithTypeList();
        (yyval.node_w_type_list_ptr)->type = (yyvsp[0].variable_info_ptr);
        (yyval.node_w_type_list_ptr)->counter = 0;

        NodeList* var_list = new NodeList();
        for(uint i=0; i<(yyvsp[-2].id_list_ptr)->size(); i++){
            // Duplicate $3 (eliminate hierarchy problem)
            VariableInfo* dupTemp = new VariableInfo();
            dupTemp->type_set = (yyvsp[0].variable_info_ptr)->type_set;
            dupTemp->type = (yyvsp[0].variable_info_ptr)->type;
            dupTemp->array_range = (yyvsp[0].variable_info_ptr)->array_range;
            dupTemp->int_literal = (yyvsp[0].variable_info_ptr)->int_literal;
            dupTemp->real_literal = (yyvsp[0].variable_info_ptr)->real_literal;
            dupTemp->string_literal = (yyvsp[0].variable_info_ptr)->string_literal;
            dupTemp->boolean_literal = (yyvsp[0].variable_info_ptr)->boolean_literal;

            VariableNode* variable_node = new VariableNode(
                (*(yyvsp[-2].id_list_ptr))[i].line_number,
                (*(yyvsp[-2].id_list_ptr))[i].col_number,
                (*(yyvsp[-2].id_list_ptr))[i].name,
                dupTemp,
                nullptr
            );

            var_list->push_back(variable_node);
            (yyval.node_w_type_list_ptr)->counter++;
        }

        (yyval.node_w_type_list_ptr)->node = new DeclarationNode(
            (yylsp[-2]).first_line,
            (yylsp[-2]).first_column,
            var_list
        );

        // Memory_Free
        delete (yyvsp[-2].id_list_ptr);
    }
#line 1903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 409 "parser.y" /* yacc.c:1646  */
    {
        (yyval.id_list_ptr) = new vector<id_info>();
        (yyval.id_list_ptr)->push_back(id_info{string((yyvsp[0].text)), (yylsp[0]).first_line, (yylsp[0]).first_column});

        // Memory_Free
        free((yyvsp[0].text));
    }
#line 1915 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 417 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].id_list_ptr)->push_back(id_info{string((yyvsp[0].text)), (yylsp[0]).first_line, (yylsp[0]).first_column});
        (yyval.id_list_ptr) = (yyvsp[-2].id_list_ptr);

        // Memory_Free
        free((yyvsp[0].text));
    }
#line 1927 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 427 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = (yyvsp[0].variable_info_ptr);
    }
#line 1935 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 431 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = UNKNOWN_SET;
        (yyval.variable_info_ptr)->type = TYPE_VOID;
    }
#line 1945 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 443 "parser.y" /* yacc.c:1646  */
    {
        // Declaration Node
        NodeList* var_list = new NodeList();
        for(uint i=0; i<(yyvsp[-3].id_list_ptr)->size(); i++){
            if( (yyvsp[-1].variable_info_ptr)->type_set == SET_CONSTANT_LITERAL ){ 
                // Literal Constant
                // duplicate $4 (eliminate hierarchy problem)
                VariableInfo* dupTemp = new VariableInfo();
                dupTemp->type_set = (yyvsp[-1].variable_info_ptr)->type_set;
                dupTemp->type = (yyvsp[-1].variable_info_ptr)->type;
                dupTemp->array_range = (yyvsp[-1].variable_info_ptr)->array_range;
                dupTemp->int_literal = (yyvsp[-1].variable_info_ptr)->int_literal;
                dupTemp->real_literal = (yyvsp[-1].variable_info_ptr)->real_literal;
                dupTemp->string_literal = (yyvsp[-1].variable_info_ptr)->string_literal;
                dupTemp->boolean_literal = (yyvsp[-1].variable_info_ptr)->boolean_literal;

                ConstantValueNode* constant_value_node = new ConstantValueNode(
                    (yylsp[-1]).first_line,
                    (yylsp[-1]).first_column,
                    dupTemp
                );

                // duplicate $4 (eliminate hierarchy problem)
                VariableInfo* dupTemp2 = new VariableInfo();
                dupTemp2->type_set = (yyvsp[-1].variable_info_ptr)->type_set;
                dupTemp2->type = (yyvsp[-1].variable_info_ptr)->type;
                dupTemp2->array_range = (yyvsp[-1].variable_info_ptr)->array_range;
                dupTemp2->int_literal = (yyvsp[-1].variable_info_ptr)->int_literal;
                dupTemp2->real_literal = (yyvsp[-1].variable_info_ptr)->real_literal;
                dupTemp2->string_literal = (yyvsp[-1].variable_info_ptr)->string_literal;
                dupTemp2->boolean_literal = (yyvsp[-1].variable_info_ptr)->boolean_literal;

                VariableNode* variable_node = new VariableNode(
                    (*(yyvsp[-3].id_list_ptr))[i].line_number,
                    (*(yyvsp[-3].id_list_ptr))[i].col_number,
                    (*(yyvsp[-3].id_list_ptr))[i].name,
                    dupTemp2,
                    constant_value_node
                );

                var_list->push_back(variable_node);
                
            } else { 
                // Type
                // duplicate $4 (eliminate hierarchy problem)
                VariableInfo* dupTemp = new VariableInfo();
                dupTemp->type_set = (yyvsp[-1].variable_info_ptr)->type_set;
                dupTemp->type = (yyvsp[-1].variable_info_ptr)->type;
                dupTemp->array_range = (yyvsp[-1].variable_info_ptr)->array_range;
                dupTemp->int_literal = (yyvsp[-1].variable_info_ptr)->int_literal;
                dupTemp->real_literal = (yyvsp[-1].variable_info_ptr)->real_literal;
                dupTemp->string_literal = (yyvsp[-1].variable_info_ptr)->string_literal;
                dupTemp->boolean_literal = (yyvsp[-1].variable_info_ptr)->boolean_literal;

                VariableNode* variable_node = new VariableNode(
                    (*(yyvsp[-3].id_list_ptr))[i].line_number,
                    (*(yyvsp[-3].id_list_ptr))[i].col_number,
                    (*(yyvsp[-3].id_list_ptr))[i].name,
                    dupTemp,
                    nullptr
                );

                var_list->push_back(variable_node);
            }
        }

        (yyval.node) = new DeclarationNode(
            (yylsp[-4]).first_line,
            (yylsp[-4]).first_column,
            var_list
        );

        // Memory_Free
        delete (yyvsp[-3].id_list_ptr);
        delete (yyvsp[-1].variable_info_ptr);
    }
#line 2026 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 522 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = (yyvsp[0].variable_info_ptr);
    }
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 526 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = (yyvsp[0].variable_info_ptr);
    }
#line 2042 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 532 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = (yyvsp[0].variable_info_ptr);
    }
#line 2050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 536 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = (yyvsp[0].variable_info_ptr);
    }
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 542 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = SET_SCALAR;
        (yyval.variable_info_ptr)->type = TYPE_INTEGER;
    }
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 548 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = SET_SCALAR;
        (yyval.variable_info_ptr)->type = TYPE_REAL;
    }
#line 2078 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 554 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = SET_SCALAR;
        (yyval.variable_info_ptr)->type = TYPE_STRING;
    }
#line 2088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 560 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = SET_SCALAR;
        (yyval.variable_info_ptr)->type = TYPE_BOOLEAN;
    }
#line 2098 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 568 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = SET_ACCUMLATED;
        (yyval.variable_info_ptr)->type = (yyvsp[0].variable_info_ptr)->type;
        (yyval.variable_info_ptr)->array_range = (yyvsp[-1].variable_info_ptr)->array_range;

        // Memory_Free
        delete (yyvsp[-1].variable_info_ptr);
        delete (yyvsp[0].variable_info_ptr);
    }
#line 2113 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 581 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set = SET_ACCUMLATED;
        (yyval.variable_info_ptr)->type = UNKNOWN_TYPE;
        (yyval.variable_info_ptr)->array_range.push_back(IntPair{(yyvsp[-3].val), (yyvsp[-1].val)});
    }
#line 2124 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 588 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-5].variable_info_ptr)->array_range.push_back(IntPair{(yyvsp[-3].val), (yyvsp[-1].val)});
        (yyval.variable_info_ptr) = (yyvsp[-5].variable_info_ptr);
    }
#line 2133 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 595 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set=SET_CONSTANT_LITERAL;
        (yyval.variable_info_ptr)->type=TYPE_INTEGER;
        (yyval.variable_info_ptr)->int_literal=(yyvsp[0].val);
    }
#line 2144 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 602 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set=SET_CONSTANT_LITERAL;
        (yyval.variable_info_ptr)->type=TYPE_REAL;
        (yyval.variable_info_ptr)->real_literal=(yyvsp[0].dval);
    }
#line 2155 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 609 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set=SET_CONSTANT_LITERAL;
        (yyval.variable_info_ptr)->type=TYPE_STRING;
        (yyval.variable_info_ptr)->string_literal=string((yyvsp[0].text));

        // Memory_Free
        free((yyvsp[0].text));
    }
#line 2169 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 619 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set=SET_CONSTANT_LITERAL;
        (yyval.variable_info_ptr)->type=TYPE_BOOLEAN;
        (yyval.variable_info_ptr)->boolean_literal=Boolean_TRUE;
    }
#line 2180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 626 "parser.y" /* yacc.c:1646  */
    {
        (yyval.variable_info_ptr) = new VariableInfo();
        (yyval.variable_info_ptr)->type_set=SET_CONSTANT_LITERAL;
        (yyval.variable_info_ptr)->type=TYPE_BOOLEAN;
        (yyval.variable_info_ptr)->boolean_literal=Boolean_FALSE;
    }
#line 2191 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 639 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2199 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 643 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2207 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 647 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2215 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 651 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2223 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 655 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2231 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 659 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 663 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2247 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 672 "parser.y" /* yacc.c:1646  */
    {
        // Compound Statement Node
        (yyval.node) = new CompoundStatementNode(
            (yylsp[-3]).first_line, 
            (yylsp[-3]).first_column, 
            (yyvsp[-2].node_list_ptr),
            (yyvsp[-1].node_list_ptr)
        );
    }
#line 2261 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 684 "parser.y" /* yacc.c:1646  */
    {
        // Assignment Node
        (yyval.node) = new AssignmentNode(
            (yylsp[-2]).first_line,
            (yylsp[-2]).first_column,
            (yyvsp[-3].node),
            (yyvsp[-1].node)
        );
    }
#line 2275 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 694 "parser.y" /* yacc.c:1646  */
    {
        // Print Node
        (yyval.node) = new PrintNode(
            (yylsp[-2]).first_line,
            (yylsp[-2]).first_column,
            (yyvsp[-1].node)
        );
    }
#line 2288 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 703 "parser.y" /* yacc.c:1646  */
    {
        // Read Node
        (yyval.node) = new ReadNode(
            (yylsp[-2]).first_line,
            (yylsp[-2]).first_column,
            (yyvsp[-1].node)  
        );
    }
#line 2301 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 714 "parser.y" /* yacc.c:1646  */
    {
        // Variable Reference Node
        (yyval.node) = new VariableReferenceNode(
            (yylsp[0]).first_line,
            (yylsp[0]).first_column,
            string((yyvsp[0].text)),
            nullptr
        );

        // Memory_Free
        free((yyvsp[0].text));
    }
#line 2318 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 727 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = new VariableReferenceNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            string((yyvsp[-1].text)),
            (yyvsp[0].node_list_ptr)
        );

        // Memory_Free
        free((yyvsp[-1].text));
    }
#line 2334 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 741 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = new NodeList();
        (yyval.node_list_ptr)->push_back((yyvsp[-1].node));
    }
#line 2343 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 746 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-3].node_list_ptr)->push_back((yyvsp[-1].node));
        (yyval.node_list_ptr) = (yyvsp[-3].node_list_ptr);
    }
#line 2352 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 756 "parser.y" /* yacc.c:1646  */
    {
        // If Node
        (yyval.node) = new IfNode(
            (yylsp[-6]).first_line,
            (yylsp[-6]).first_column,
            (yyvsp[-5].node),
            (yyvsp[-3].node_list_ptr),
            (yyvsp[-2].node_list_ptr)
        );
    }
#line 2367 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 770 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = (yyvsp[0].node_list_ptr);
    }
#line 2375 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 774 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = nullptr;
    }
#line 2383 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 782 "parser.y" /* yacc.c:1646  */
    {
        // While Node
        (yyval.node) = new WhileNode(
            (yylsp[-5]).first_line,
            (yylsp[-5]).first_column,
            (yyvsp[-4].node),
            (yyvsp[-2].node_list_ptr)
        );
    }
#line 2397 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 796 "parser.y" /* yacc.c:1646  */
    {
        // loop_variable_declaration : a declaration node
        VariableInfo* var_info = new VariableInfo();
        var_info->type_set = SET_SCALAR;
        var_info->type = TYPE_INTEGER;
        VariableNode* variable_node = new VariableNode(
            (yylsp[-8]).first_line,
            (yylsp[-8]).first_column,
            string((yyvsp[-8].text)),
            var_info,
            nullptr
        );

        NodeList* var_list = new NodeList();
        var_list->push_back(variable_node);
        DeclarationNode* declaration_node = new DeclarationNode(
            (yylsp[-8]).first_line,
            (yylsp[-8]).first_column,
            var_list
        );

        // initial: an assignment node
        VariableReferenceNode* variable_reference_node = new VariableReferenceNode(
            (yylsp[-8]).first_line,
            (yylsp[-8]).first_column,
            string((yyvsp[-8].text)),
            nullptr
        );

        VariableInfo* constant_value_info = new VariableInfo();
        constant_value_info->type_set = SET_CONSTANT_LITERAL;
        constant_value_info->type = TYPE_INTEGER;
        constant_value_info->int_literal = (yyvsp[-6].val);
        ConstantValueNode* constant_value_node = new ConstantValueNode(
            (yylsp[-6]).first_line,
            (yylsp[-6]).first_column,
            constant_value_info
        );

        AssignmentNode* assignment_node = new AssignmentNode(
            (yylsp[-7]).first_line,
            (yylsp[-7]).first_column,
            variable_reference_node,
            constant_value_node // expression node
        );

        // condition: an expression node ( constant value node )
        VariableInfo* constant_value_info2 = new VariableInfo();
        constant_value_info2->type_set = SET_CONSTANT_LITERAL;
        constant_value_info2->type = TYPE_INTEGER;
        constant_value_info2->int_literal = (yyvsp[-4].val);
        ConstantValueNode* constant_value_node2 = new ConstantValueNode(
            (yylsp[-4]).first_line,
            (yylsp[-4]).first_column,
            constant_value_info2
        );

        // For Node
        (yyval.node) = new ForNode(
            (yylsp[-9]).first_line,
            (yylsp[-9]).first_column,
            declaration_node,
            assignment_node,
            constant_value_node2, // expression node
            (yyvsp[-2].node_list_ptr),
            string((yyvsp[-8].text)),
            (yyvsp[-6].val), // HW4 ADD
            (yyvsp[-4].val)  // HW4 ADD
        );

        // Memory_Free
        free((yyvsp[-8].text));
    }
#line 2475 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 872 "parser.y" /* yacc.c:1646  */
    {
        // Return Node
        (yyval.node) = new ReturnNode(
            (yylsp[-2]).first_line,
            (yylsp[-2]).first_column,
            (yyvsp[-1].node)
        );
    }
#line 2488 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 883 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 889 "parser.y" /* yacc.c:1646  */
    {
        // Function Call Node
        (yyval.node) = new FunctionCallNode(
            (yylsp[-3]).first_line,
            (yylsp[-3]).first_column,
            string((yyvsp[-3].text)),
            (yyvsp[-1].node_list_ptr)
        );

        // Memory_Free
        free((yyvsp[-3].text));
    }
#line 2513 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 904 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = nullptr;
    }
#line 2521 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 908 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = (yyvsp[0].node_list_ptr);
    }
#line 2529 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 914 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = new NodeList();
        (yyval.node_list_ptr)->push_back((yyvsp[0].node));
    }
#line 2538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 919 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].node_list_ptr)->push_back((yyvsp[0].node));
        (yyval.node_list_ptr)=(yyvsp[-2].node_list_ptr);
    }
#line 2547 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 926 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = nullptr;
    }
#line 2555 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 930 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = (yyvsp[0].node_list_ptr);
    }
#line 2563 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 936 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node_list_ptr) = new NodeList();
        (yyval.node_list_ptr)->push_back((yyvsp[0].node));
    }
#line 2572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 941 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1].node_list_ptr)->push_back((yyvsp[0].node));
        (yyval.node_list_ptr)=(yyvsp[-1].node_list_ptr);
    }
#line 2581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 948 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 952 "parser.y" /* yacc.c:1646  */
    {
        // Unary Operator Node
        (yyval.node) = new UnaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[0].node)
        );
    }
#line 2603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 962 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 973 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 984 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 995 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1017 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1028 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1039 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2723 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1050 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1061 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1072 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
        // Unary Operator Node
        (yyval.node) = new UnaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[0].node)
        );
    }
#line 2782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1093 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1104 "parser.y" /* yacc.c:1646  */
    {
        // Binary Operator Node
        (yyval.node) = new BinaryOperatorNode(
            (yylsp[-1]).first_line,
            (yylsp[-1]).first_column,
            (yyvsp[-1].op_type),
            (yyvsp[-2].node),
            (yyvsp[0].node)
        );
    }
#line 2812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1115 "parser.y" /* yacc.c:1646  */
    {
        // Constant Value Node
        (yyval.node) = new ConstantValueNode(
            (yylsp[0]).first_line,
            (yylsp[0]).first_column,
            (yyvsp[0].variable_info_ptr)
        );
    }
#line 2825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1124 "parser.y" /* yacc.c:1646  */
    {
        // Variable Reference Node
        (yyval.node) = (yyvsp[0].node);
    }
#line 2834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1129 "parser.y" /* yacc.c:1646  */
    {
        // Function Call Node
        (yyval.node) = (yyvsp[0].node);
    }
#line 2843 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2847 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1140 "parser.y" /* yacc.c:1906  */


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

void dumpAST(ASTNodeBase* node){
    ASTDumper visitor;
    node->accept(visitor);
}

int main(int argc, const char *argv[]) {
    CHECK((argc >= 2) && (argc<=4), "Usage: ./parser <filename> [--dump-ast]\n");
    
    int isDumpNeed;
    if(argc == 3){
        isDumpNeed = strcmp(argv[2], "--dump-ast");
        if(isDumpNeed != 0){
            fprintf(stderr, "Usage: ./parser <filename> [--dump-ast]\n");
            exit(-1);                                                          
        }
    }
    
        
    FILE *fp = fopen(argv[1], "r");

    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    yyparse();
     
    if(argc == 3 && isDumpNeed == 0)
        dumpAST(AST);

	// TODO: construct a SemanticAnalyzer to analyze the AST
    SemanticAnalyzer semantic_analyzer(string(argv[1]), fp);
    AST->accept(semantic_analyzer);
    if(argc==4){
    	Codegenerator cg(string(argv[1]),fp);
        AST->accept(cg);
	fstream file;
        string fd;
        fd+=string(argv[3])+"/"+cg.filename+".s";
        file.open(fd.c_str(),ios::out);
	for(int i=0;i<cg.output.size();i++){
                file<<cg.output[i].c_str()<<endl;                                                                               }
	file.close();
    }
    if(OptDum == 1)
        semantic_analyzer.dump_symbol_table();
    
	if(semantic_analyzer.is_semantic_error() == 0)

       	     printf("\n"

            "|---------------------------------------------|\n"

            "|  There is no syntactic and semantic error!  |\n"

            "|---------------------------------------------|\n");

    	else

             semantic_analyzer.output_err_msg();    

    // Memory_Free
    delete AST;
    fclose(fp);
    yylex_destroy();
    // Memory_Free_END
    
    return 0;
}
