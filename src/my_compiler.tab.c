/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 ".\\my_compiler.y"

/* code : GB2312
* 基于bison的c语言语法分析器
* 用于语法检查和制导生成抽象语法树
* 作者：dongzj1997
* 参考：http://www.quut.com/c/ANSI-C-grammar-y-1995.html
* 具体每种短语代表的含义以及他们的关系，请查看 .\compiler.vsdx （Visio格式）
*/
#include "AST.h"
#include "Praser.h"


extern char *yytext;
extern FILE * yyin;
extern int yylineno;
struct AST *root;

int yylex(void);
void yyerror(const char*); 


/* Line 371 of yacc.c  */
#line 90 "my_compiler.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "my_compiler.tab.h".  */
#ifndef YY_YY_MY_COMPILER_TAB_H_INCLUDED
# define YY_YY_MY_COMPILER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     CONSTANT_INT = 262,
     CONSTANT_DOUBLE = 263,
     PTR_OP = 264,
     INC_OP = 265,
     DEC_OP = 266,
     LEFT_OP = 267,
     RIGHT_OP = 268,
     LE_OP = 269,
     GE_OP = 270,
     EQ_OP = 271,
     NE_OP = 272,
     AND_OP = 273,
     OR_OP = 274,
     MUL_ASSIGN = 275,
     DIV_ASSIGN = 276,
     MOD_ASSIGN = 277,
     ADD_ASSIGN = 278,
     SUB_ASSIGN = 279,
     LEFT_ASSIGN = 280,
     RIGHT_ASSIGN = 281,
     AND_ASSIGN = 282,
     XOR_ASSIGN = 283,
     OR_ASSIGN = 284,
     TYPE_NAME = 285,
     CHAR = 286,
     INT = 287,
     DOUBLE = 288,
     VOID = 289,
     FLOAT = 290,
     AUTO = 291,
     CONST = 292,
     DEFAULT = 293,
     ENUM = 294,
     EXTERN = 295,
     INLINE = 296,
     LONG = 297,
     REGISTER = 298,
     SHORT = 299,
     SIGNED = 300,
     STATIC = 301,
     TYPEDEF = 302,
     UNION = 303,
     STRUCT = 304,
     UNSIGNED = 305,
     ELLIPSIS = 306,
     VOLATILE = 307,
     CASE = 308,
     IF = 309,
     ELSE = 310,
     SWITCH = 311,
     WHILE = 312,
     DO = 313,
     FOR = 314,
     GOTO = 315,
     CONTINUE = 316,
     BREAK = 317,
     RETURN = 318,
     THE_FIRST_IF_IN_FRONT = 319
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 24 ".\\my_compiler.y"

	struct AST* node;


/* Line 387 of yacc.c  */
#line 202 "my_compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MY_COMPILER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 230 "my_compiler.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNRULES -- Number of states.  */
#define YYNSTATES  345

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    78,    71,     2,
      86,    87,    76,    75,    65,    74,    70,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    64,
      79,    67,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    82,    85,    73,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    88
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    17,    19,
      24,    28,    33,    37,    41,    44,    47,    49,    53,    55,
      58,    61,    64,    67,    72,    74,    76,    78,    80,    82,
      84,    86,    91,    93,    97,   101,   105,   107,   111,   115,
     117,   121,   125,   127,   131,   135,   139,   143,   145,   149,
     153,   155,   159,   161,   165,   167,   171,   173,   177,   179,
     183,   185,   191,   193,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   225,   227,   230,
     234,   236,   239,   241,   244,   246,   249,   251,   255,   257,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   293,   298,   301,   303,   305,   307,
     310,   314,   317,   319,   322,   324,   326,   330,   332,   335,
     339,   344,   350,   353,   355,   359,   361,   365,   367,   369,
     372,   374,   376,   380,   385,   389,   394,   399,   403,   405,
     408,   411,   415,   417,   421,   424,   427,   429,   431,   435,
     437,   440,   442,   444,   447,   451,   454,   458,   462,   467,
     470,   474,   478,   483,   485,   489,   494,   496,   500,   502,
     504,   506,   508,   510,   512,   516,   521,   525,   528,   532,
     534,   537,   539,   541,   543,   546,   552,   560,   566,   572,
     580,   587,   595,   602,   610,   614,   617,   620,   623,   627,
     629,   632,   634,   636,   641,   645,   647
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,   149,    -1,     3,    -1,     7,    -1,     8,
      -1,     5,    -1,    86,   110,    87,    -1,    91,    -1,    92,
      68,   110,    69,    -1,    92,    86,    87,    -1,    92,    86,
      93,    87,    -1,    92,    70,     3,    -1,    92,     9,     3,
      -1,    92,    10,    -1,    92,    11,    -1,   108,    -1,    93,
      65,   108,    -1,    92,    -1,    10,    94,    -1,    11,    94,
      -1,    95,    96,    -1,     6,    94,    -1,     6,    86,   135,
      87,    -1,    71,    -1,    76,    -1,    75,    -1,    74,    -1,
      73,    -1,    72,    -1,    94,    -1,    86,   135,    87,    96,
      -1,    96,    -1,    97,    76,    96,    -1,    97,    77,    96,
      -1,    97,    78,    96,    -1,    97,    -1,    98,    75,    97,
      -1,    98,    74,    97,    -1,    98,    -1,    99,    12,    98,
      -1,    99,    13,    98,    -1,    99,    -1,   100,    79,    99,
      -1,   100,    80,    99,    -1,   100,    14,    99,    -1,   100,
      15,    99,    -1,   100,    -1,   101,    16,   100,    -1,   101,
      17,   100,    -1,   101,    -1,   102,    71,   101,    -1,   102,
      -1,   103,    81,   102,    -1,   103,    -1,   104,    82,   103,
      -1,   104,    -1,   105,    18,   104,    -1,   105,    -1,   106,
      19,   105,    -1,   106,    -1,   106,    83,   110,    66,   107,
      -1,   107,    -1,    94,   109,   108,    -1,    67,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,   108,
      -1,   110,    65,   108,    -1,   107,    -1,   113,    64,    -1,
     113,   114,    64,    -1,   116,    -1,   116,   113,    -1,   117,
      -1,   117,   113,    -1,   128,    -1,   128,   113,    -1,   115,
      -1,   114,    65,   115,    -1,   129,    -1,   129,    67,   138,
      -1,    47,    -1,    40,    -1,    46,    -1,    36,    -1,    43,
      -1,    34,    -1,    31,    -1,    32,    -1,    33,    -1,    45,
      -1,   118,    -1,   125,    -1,    30,    -1,   119,     3,    84,
     120,    85,    -1,   119,    84,   120,    85,    -1,   119,     3,
      -1,    49,    -1,    48,    -1,   121,    -1,   120,   121,    -1,
     122,   123,    64,    -1,   117,   122,    -1,   117,    -1,   128,
     122,    -1,   128,    -1,   124,    -1,   123,    65,   124,    -1,
     129,    -1,    66,   111,    -1,   129,    66,   111,    -1,    39,
      84,   126,    85,    -1,    39,     3,    84,   126,    85,    -1,
      39,     3,    -1,   127,    -1,   126,    65,   127,    -1,     3,
      -1,     3,    67,   111,    -1,    37,    -1,    52,    -1,   131,
     130,    -1,   130,    -1,     3,    -1,    86,   129,    87,    -1,
     130,    68,   111,    69,    -1,   130,    68,    69,    -1,   130,
      86,   132,    87,    -1,   130,    86,   134,    87,    -1,   130,
      86,    87,    -1,    76,    -1,    76,   128,    -1,    76,   131,
      -1,    76,   128,   131,    -1,   133,    -1,   132,    65,   133,
      -1,   117,   129,    -1,   117,   136,    -1,   117,    -1,     3,
      -1,   134,    65,     3,    -1,   122,    -1,   122,   136,    -1,
     131,    -1,   137,    -1,   131,   137,    -1,    86,   136,    87,
      -1,    68,    69,    -1,    68,   111,    69,    -1,   137,    68,
      69,    -1,   137,    68,   111,    69,    -1,    86,    87,    -1,
      86,   132,    87,    -1,   137,    86,    87,    -1,   137,    86,
     132,    87,    -1,   108,    -1,    84,   139,    85,    -1,    84,
     139,    65,    85,    -1,   138,    -1,   139,    65,   138,    -1,
     141,    -1,   142,    -1,   145,    -1,   146,    -1,   147,    -1,
     148,    -1,     3,    66,   140,    -1,    53,   106,    66,   140,
      -1,    38,    66,   140,    -1,    84,    85,    -1,    84,   143,
      85,    -1,   144,    -1,   143,   144,    -1,   112,    -1,   140,
      -1,    64,    -1,   110,    64,    -1,    54,    86,   110,    87,
     140,    -1,    54,    86,   110,    87,   140,    55,   140,    -1,
      56,    86,   110,    87,   140,    -1,    57,    86,   110,    87,
     140,    -1,    58,   140,    57,    86,   110,    87,    64,    -1,
      59,    86,   145,   145,    87,   140,    -1,    59,    86,   145,
     145,   110,    87,   140,    -1,    59,    86,   112,   145,    87,
     140,    -1,    59,    86,   112,   145,   110,    87,   140,    -1,
      60,     3,    64,    -1,    61,    64,    -1,    62,    64,    -1,
      63,    64,    -1,    63,   110,    64,    -1,   150,    -1,   149,
     150,    -1,   151,    -1,   112,    -1,   113,   129,   152,   142,
      -1,   113,   129,   142,    -1,   112,    -1,   152,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    68,    71,    74,    77,    80,    86,    89,
      92,    96,   100,   103,   107,   111,   118,   121,   127,   130,
     134,   138,   141,   144,   151,   154,   157,   160,   163,   166,
     172,   175,   181,   184,   187,   190,   196,   199,   202,   208,
     211,   215,   222,   225,   228,   231,   235,   242,   245,   249,
     256,   259,   265,   268,   275,   278,   284,   287,   293,   296,
     302,   305,   312,   315,   321,   324,   328,   332,   336,   340,
     344,   348,   352,   356,   360,   367,   370,   376,   383,   387,
     393,   396,   399,   402,   405,   408,   414,   417,   423,   426,
     432,   435,   438,   441,   444,   450,   453,   456,   459,   462,
     465,   469,   472,   478,   481,   484,   490,   493,   499,   502,
     508,   514,   517,   520,   523,   529,   532,   538,   541,   544,
     551,   554,   557,   563,   567,   573,   576,   582,   585,   591,
     594,   601,   605,   609,   613,   617,   621,   625,   632,   635,
     638,   641,   648,   651,   657,   660,   663,   669,   672,   678,
     681,   687,   690,   693,   699,   702,   705,   708,   711,   714,
     717,   720,   723,   729,   732,   736,   743,   746,   753,   756,
     759,   762,   765,   768,   774,   777,   780,   786,   789,   795,
     798,   804,   807,   813,   816,   822,   825,   828,   834,   837,
     840,   843,   846,   849,   855,   858,   861,   864,   867,   873,
     876,   882,   885,   891,   894,   900,   903
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "CONSTANT_INT", "CONSTANT_DOUBLE", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "CHAR", "INT", "DOUBLE", "VOID",
  "FLOAT", "AUTO", "CONST", "DEFAULT", "ENUM", "EXTERN", "INLINE", "LONG",
  "REGISTER", "SHORT", "SIGNED", "STATIC", "TYPEDEF", "UNION", "STRUCT",
  "UNSIGNED", "ELLIPSIS", "VOLATILE", "CASE", "IF", "ELSE", "SWITCH",
  "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "';'",
  "','", "':'", "'='", "'['", "']'", "'.'", "'&'", "'!'", "'~'", "'-'",
  "'+'", "'*'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'{'",
  "'}'", "'('", "')'", "THE_FIRST_IF_IN_FRONT", "$accept", "Program",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    59,    44,    58,    61,    91,    93,
      46,    38,    33,   126,    45,    43,    42,    47,    37,    60,
      62,    94,   124,    63,   123,   125,    40,    41,   319
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   122,   122,   123,   123,   124,   124,   124,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   138,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   148,   148,   148,   148,   148,   149,
     149,   150,   150,   151,   151,   152,   152
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     1,     1,     1,     2,
       3,     2,     1,     2,     1,     1,     3,     1,     2,     3,
       4,     5,     2,     1,     3,     1,     3,     1,     1,     2,
       1,     1,     3,     4,     3,     4,     4,     3,     1,     2,
       2,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     1,
       2,     1,     1,     1,     2,     5,     7,     5,     5,     7,
       6,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,    96,    97,    98,    95,    93,   127,     0,    91,
      94,    99,    92,    90,   107,   106,   128,     0,   202,     0,
      80,    82,   100,     0,   101,    84,     2,   199,   201,   122,
       0,     1,   131,    78,   138,     0,     0,    86,    88,   130,
       0,    81,    83,   105,     0,    85,   200,     0,   125,     0,
     123,   139,   140,     0,    79,     0,     0,     0,   205,     0,
     204,     0,     0,     0,   129,     0,   112,     0,   108,     0,
     114,     0,     0,     0,   120,   141,   132,    87,    88,     3,
       6,     0,     4,     5,     0,     0,    24,    29,    28,    27,
      26,    25,     0,     0,     8,    18,    30,     0,    32,    36,
      39,    42,    47,    50,    52,    54,    56,    58,    60,    62,
     163,    89,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   177,    75,     0,   181,   182,
     168,   169,     0,   179,   170,   171,   172,   173,   206,   203,
     134,    30,    77,     0,   147,   137,   146,     0,   142,     0,
       0,   111,   104,   109,     0,     0,   115,   117,   113,   121,
     126,   124,     0,    22,     0,    19,    20,   166,     0,     0,
     149,     0,     0,    14,    15,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    64,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
     196,   197,     0,   184,     0,   178,   180,   133,     0,     0,
     144,   151,   145,   152,     0,   135,     0,   136,   103,   118,
     110,     0,     0,     0,     0,   164,     7,     0,   151,   150,
       0,    13,     0,    12,    10,     0,    16,    63,    33,    34,
      35,    38,    37,    40,    41,    45,    46,    43,    44,    48,
      49,    51,    53,    55,    57,    59,     0,   174,   176,     0,
       0,     0,     0,     0,     0,     0,   194,   198,    76,   155,
       0,   159,     0,     0,   153,     0,     0,   143,   148,   116,
     119,    23,   165,   167,    31,     9,     0,    11,     0,   175,
       0,     0,     0,     0,     0,     0,   156,   160,   154,   157,
       0,   161,     0,    17,    61,   185,   187,   188,     0,     0,
       0,     0,     0,   158,   162,     0,     0,   192,     0,   190,
       0,   186,   189,   193,   191
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    94,    95,   255,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   126,
     189,   127,   143,    18,    59,    36,    37,    20,    21,    22,
      23,    67,    68,    69,   155,   156,    24,    49,    50,    25,
      53,    39,    40,   292,   148,   149,   171,   293,   233,   111,
     168,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      26,    27,    28,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -202
static const yytype_int16 yypact[] =
{
    1043,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    11,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,    33,  -202,    35,
    1043,  1043,  -202,    12,  -202,  1043,  1043,  -202,  -202,   -18,
      79,  -202,  -202,  -202,    13,    85,    62,  -202,   997,   146,
      26,  -202,  -202,    51,  1066,  -202,  -202,    79,    91,   -14,
    -202,    94,  -202,    92,  -202,    85,   699,   390,  -202,    35,
    -202,  1020,   313,   330,   146,  1066,  1066,   950,  -202,    38,
    1066,     5,   824,    79,  -202,  -202,  -202,  -202,   109,  -202,
    -202,   833,  -202,  -202,   867,   867,  -202,  -202,  -202,  -202,
    -202,  -202,   699,   690,  -202,   210,   278,   824,  -202,   205,
     211,    50,    40,   273,   110,   121,   101,   192,    -2,  -202,
    -202,  -202,   158,   168,   824,   150,   157,   167,   608,   169,
     257,   215,   220,   738,  -202,  -202,  -202,   227,  -202,  -202,
    -202,  -202,   474,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,   196,  -202,  -202,    89,   -20,  -202,   -12,
     973,  -202,  -202,  -202,   824,   229,  -202,   231,  -202,  -202,
    -202,  -202,   690,  -202,   824,  -202,  -202,  -202,   102,    -8,
     147,   208,   306,  -202,  -202,   824,   314,   201,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,   824,
    -202,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     608,   608,     6,   824,   824,   824,   265,   558,   270,  -202,
    -202,  -202,   276,  -202,   824,  -202,  -202,  -202,   747,   305,
    -202,    37,  -202,   170,  1089,  -202,   354,  -202,  -202,  -202,
    -202,    38,   824,   271,   567,  -202,  -202,   881,   172,  -202,
     824,  -202,    63,  -202,  -202,    -1,  -202,  -202,  -202,  -202,
    -202,   205,   205,   211,   211,    50,    50,    50,    50,    40,
      40,   273,   110,   121,   101,   192,   281,  -202,  -202,   608,
      28,    90,    97,   279,   781,   781,  -202,  -202,  -202,  -202,
     290,  -202,    99,   280,   170,   790,   930,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,   824,  -202,   824,  -202,
     608,   608,   608,   824,   239,   256,  -202,  -202,  -202,  -202,
     297,  -202,   107,  -202,  -202,   315,  -202,  -202,   113,   608,
     126,   608,   130,  -202,  -202,   608,   304,  -202,   608,  -202,
     608,  -202,  -202,  -202,  -202
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,  -202,  -202,   -54,  -202,   -90,   154,   155,
      70,   153,   173,   166,   174,   165,   175,   260,   -60,   -55,
    -202,   -84,   -69,   -25,    48,  -202,   321,  -202,   -44,  -202,
    -202,   325,   -33,   -46,  -202,   161,  -202,   347,   331,    43,
     -13,   -30,    10,   -59,   171,  -202,   241,  -118,  -172,   -81,
    -202,  -113,  -202,    -3,  -202,   274,  -201,  -202,  -202,  -202,
    -202,   381,  -202,  -202
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      66,   110,   142,   160,   147,   216,    38,   190,   141,   169,
      64,   167,   142,    58,    29,    43,   285,   208,   141,   146,
     151,    66,    66,    66,   158,   208,    66,   163,   232,    32,
     165,   166,   128,    31,   153,    60,   138,   110,    32,   222,
      32,    32,    78,   141,    52,   234,    78,   170,    19,    66,
       7,    73,   249,   236,   198,   199,   157,   224,   139,   294,
     141,    75,   196,   197,   306,    16,    47,   235,    41,    42,
      73,    74,   279,    45,    19,   237,   294,    51,   169,   246,
     169,   209,    48,   314,   315,   239,   307,    70,    32,    34,
     159,   252,    32,   224,   142,    30,    44,   277,   278,    33,
     141,   258,   259,   260,   154,   228,    66,   128,    70,    70,
      70,    34,    35,    70,    34,   310,   170,   153,    66,   200,
     201,    35,   256,   229,    35,   276,    54,    55,   224,   280,
     281,   282,   305,   230,   257,    65,    70,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   224,   231,   228,    72,   290,
     304,    34,   224,   303,   234,    34,   309,   244,   142,   288,
      34,    35,   234,   300,   141,   229,    56,   311,   224,    76,
     248,   204,   142,   206,   312,   146,   317,   245,   141,   110,
     146,   224,   284,    70,   334,   224,   141,   325,   326,   327,
     336,    64,   205,   146,    79,    70,    80,    81,    82,    83,
     207,    84,    85,   338,    62,   228,   337,   340,   339,   172,
     173,   174,   341,    34,   210,   343,   320,   344,   157,   328,
     330,   332,    63,   247,   211,   142,   213,   322,   295,   231,
     228,   141,    79,   214,    80,    81,    82,    83,   324,    84,
      85,   323,   146,   215,   141,   217,   296,   248,   247,    79,
     218,    80,    81,    82,    83,   227,    84,    85,   265,   266,
     267,   268,    86,    87,    88,    89,    90,    91,   175,   219,
     176,   191,   192,   193,   220,   194,   195,    93,   254,   202,
     203,   223,   224,   240,   241,   250,   177,   242,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    32,   251,
      86,    87,    88,    89,    90,    91,    79,   253,    80,    81,
      82,    83,   283,    84,    85,    93,   329,    86,    87,    88,
      89,    90,    91,   144,   286,     1,     2,     3,     4,     5,
     287,   224,    93,   331,     8,   188,   224,   308,   261,   262,
      11,   263,   264,    14,    15,   269,   270,   298,   301,   316,
       1,     2,     3,     4,     5,   313,   333,   318,   342,     8,
     335,   272,   274,   228,   212,    11,    77,   271,    14,    15,
     273,    34,   140,   275,    86,    87,    88,    89,    90,    91,
     150,   229,   291,   112,    71,    80,    81,    82,    83,    93,
      84,    85,   299,   243,   161,   297,   226,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       1,     2,     3,     4,     5,     0,     6,     7,   113,     8,
       9,     0,     0,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,   114,   115,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    57,   125,    93,   112,     0,    80,
      81,    82,    83,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     0,
       6,     7,   113,     8,     9,     0,     0,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,   114,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    57,   225,
      93,    79,     0,    80,    81,    82,    83,     0,    84,    85,
      79,     0,    80,    81,    82,    83,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     6,     7,     0,     8,     9,     0,
       0,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,   112,     0,    80,    81,    82,    83,     0,    84,    85,
       0,     0,   124,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    93,     0,   113,     0,     0,     0,
       0,    92,   302,    93,     0,     0,     0,     0,     0,     0,
       0,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,    57,    79,    93,    80,    81,    82,    83,     0,
      84,    85,    79,     0,    80,    81,    82,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     0,     7,     0,     8,
       0,     0,     0,     0,     0,    11,     0,     0,    14,    15,
       0,    79,    16,    80,    81,    82,    83,     0,    84,    85,
      79,     0,    80,    81,    82,    83,     0,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    93,     0,     0,     0,
       0,     0,     0,    92,    79,    93,    80,    81,    82,    83,
       0,    84,    85,    79,     0,    80,    81,    82,    83,     0,
      84,    85,   221,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,   289,     0,    86,    87,
      88,    89,    90,    91,    93,     0,     0,    79,     0,    80,
      81,    82,    83,    93,    84,    85,    79,     0,    80,    81,
      82,    83,     0,    84,    85,   124,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,     0,   319,
       0,    86,    87,    88,    89,    90,    91,    93,     0,     0,
      79,     0,    80,    81,    82,    83,    93,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      93,     1,     2,     3,     4,     5,     0,     0,     0,   162,
       8,     0,     0,     0,     0,     0,    11,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,   228,
       0,     0,     0,   164,     0,     0,     0,    34,     0,     0,
       1,     2,     3,     4,     5,     0,     0,   247,   291,     8,
       0,     0,     0,     0,     0,    11,     0,     0,    14,    15,
       1,     2,     3,     4,     5,     0,     0,     7,     0,     8,
       0,     0,     0,     0,     0,    11,     0,     0,    14,    15,
       0,     0,    16,     1,     2,     3,     4,     5,     0,     0,
       7,     0,     8,     0,     0,     0,     0,   321,    11,     0,
       0,    14,    15,     0,     0,    16,     0,     1,     2,     3,
       4,     5,     0,     6,     7,   152,     8,     9,     0,     0,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
       1,     2,     3,     4,     5,     0,     6,     7,   238,     8,
       9,     0,     0,    10,    56,    11,    12,    13,    14,    15,
       0,     0,    16,     1,     2,     3,     4,     5,     0,     6,
       7,    57,     8,     9,     0,     0,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,     1,     2,     3,     4,
       5,     0,     0,     7,    57,     8,     0,     0,     0,     0,
       0,    11,     0,     0,    14,    15,     0,     0,    16,     1,
       2,     3,     4,     5,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    11,     0,     0,    14,    15
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-202)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      44,    56,    62,    72,    63,   118,    19,    97,    62,    93,
      40,    92,    72,    38,     3,     3,   217,    19,    72,    63,
      66,    65,    66,    67,    70,    19,    70,    81,   146,     3,
      84,    85,    57,     0,    67,    38,    61,    92,     3,   123,
       3,     3,    55,    97,    34,    65,    59,    93,     0,    93,
      37,    65,   170,    65,    14,    15,    69,    65,    61,   231,
     114,    51,    12,    13,    65,    52,    84,    87,    20,    21,
      65,    85,    66,    25,    26,    87,   248,    34,   162,    87,
     164,    83,     3,   284,   285,   154,    87,    44,     3,    76,
      85,   175,     3,    65,   154,    84,    84,   210,   211,    64,
     154,   191,   192,   193,    66,    68,   150,   132,    65,    66,
      67,    76,    86,    70,    76,    87,   162,   150,   162,    79,
      80,    86,   177,    86,    86,   209,    64,    65,    65,   213,
     214,   215,    69,   146,   189,    84,    93,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    65,   146,    68,    67,   228,
     250,    76,    65,   244,    65,    76,   279,    65,   228,   224,
      76,    86,    65,   242,   228,    86,    67,    87,    65,    87,
     170,    71,   242,    82,    87,   229,    87,    85,   242,   244,
     234,    65,   217,   150,    87,    65,   250,   310,   311,   312,
      87,   231,    81,   247,     3,   162,     5,     6,     7,     8,
      18,    10,    11,    87,    68,    68,   329,    87,   331,     9,
      10,    11,   335,    76,    66,   338,   295,   340,   241,   313,
     314,   315,    86,    86,    66,   295,    86,   296,    68,   229,
      68,   295,     3,    86,     5,     6,     7,     8,   308,    10,
      11,   306,   296,    86,   308,    86,    86,   247,    86,     3,
       3,     5,     6,     7,     8,    69,    10,    11,   198,   199,
     200,   201,    71,    72,    73,    74,    75,    76,    68,    64,
      70,    76,    77,    78,    64,    74,    75,    86,    87,    16,
      17,    64,    65,    64,    65,    87,    86,    66,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     3,     3,
      71,    72,    73,    74,    75,    76,     3,     3,     5,     6,
       7,     8,    57,    10,    11,    86,    87,    71,    72,    73,
      74,    75,    76,     3,    64,    30,    31,    32,    33,    34,
      64,    65,    86,    87,    39,    67,    65,    66,   194,   195,
      45,   196,   197,    48,    49,   202,   203,     3,    87,    69,
      30,    31,    32,    33,    34,    86,    69,    87,    64,    39,
      55,   205,   207,    68,   114,    45,    55,   204,    48,    49,
     206,    76,    69,   208,    71,    72,    73,    74,    75,    76,
      65,    86,    87,     3,    47,     5,     6,     7,     8,    86,
      10,    11,   241,   162,    73,   234,   132,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,     3,    -1,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,     3,    -1,     5,     6,     7,     8,    -1,    10,    11,
       3,    -1,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    -1,    36,    37,    -1,    39,    40,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    -1,    -1,
      52,     3,    -1,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    86,    -1,    38,    -1,    -1,    -1,
      -1,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,     3,    86,     5,     6,     7,     8,    -1,
      10,    11,     3,    -1,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,
      -1,     3,    52,     5,     6,     7,     8,    -1,    10,    11,
       3,    -1,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    84,     3,    86,     5,     6,     7,     8,
      -1,    10,    11,     3,    -1,     5,     6,     7,     8,    -1,
      10,    11,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    69,    -1,    71,    72,
      73,    74,    75,    76,    86,    -1,    -1,     3,    -1,     5,
       6,     7,     8,    86,    10,    11,     3,    -1,     5,     6,
       7,     8,    -1,    10,    11,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    69,
      -1,    71,    72,    73,    74,    75,    76,    86,    -1,    -1,
       3,    -1,     5,     6,     7,     8,    86,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      86,    30,    31,    32,    33,    34,    -1,    -1,    -1,    86,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    76,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    -1,    86,    87,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,
      30,    31,    32,    33,    34,    -1,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,
      -1,    -1,    52,    30,    31,    32,    33,    34,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    87,    45,    -1,
      -1,    48,    49,    -1,    -1,    52,    -1,    30,    31,    32,
      33,    34,    -1,    36,    37,    85,    39,    40,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    -1,    -1,    52,
      30,    31,    32,    33,    34,    -1,    36,    37,    85,    39,
      40,    -1,    -1,    43,    67,    45,    46,    47,    48,    49,
      -1,    -1,    52,    30,    31,    32,    33,    34,    -1,    36,
      37,    84,    39,    40,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    -1,    -1,    52,    30,    31,    32,    33,
      34,    -1,    -1,    37,    84,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    48,    49,    -1,    -1,    52,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    32,    33,    34,    36,    37,    39,    40,
      43,    45,    46,    47,    48,    49,    52,    90,   112,   113,
     116,   117,   118,   119,   125,   128,   149,   150,   151,     3,
      84,     0,     3,    64,    76,    86,   114,   115,   129,   130,
     131,   113,   113,     3,    84,   113,   150,    84,     3,   126,
     127,   128,   131,   129,    64,    65,    67,    84,   112,   113,
     142,   152,    68,    86,   130,    84,   117,   120,   121,   122,
     128,   126,    67,    65,    85,   131,    87,   115,   129,     3,
       5,     6,     7,     8,    10,    11,    71,    72,    73,    74,
      75,    76,    84,    86,    91,    92,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   138,     3,    38,    53,    54,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    85,   108,   110,   112,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   112,   142,
      69,    94,   107,   111,     3,    87,   117,   132,   133,   134,
     120,   122,    85,   121,    66,   123,   124,   129,   122,    85,
     111,   127,    86,    94,    86,    94,    94,   138,   139,   110,
     122,   135,     9,    10,    11,    68,    70,    86,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    67,   109,
      96,    76,    77,    78,    74,    75,    12,    13,    14,    15,
      79,    80,    16,    17,    71,    81,    82,    18,    19,    83,
      66,    66,   106,    86,    86,    86,   140,    86,     3,    64,
      64,    64,   110,    64,    65,    85,   144,    69,    68,    86,
     129,   131,   136,   137,    65,    87,    65,    87,    85,   111,
      64,    65,    66,   135,    65,    85,    87,    86,   131,   136,
      87,     3,   110,     3,    87,    93,   108,   108,    96,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,   100,
     100,   101,   102,   103,   104,   105,   110,   140,   140,    66,
     110,   110,   110,    57,   112,   145,    64,    64,   108,    69,
     111,    87,   132,   136,   137,    68,    86,   133,     3,   124,
     111,    87,    85,   138,    96,    69,    65,    87,    66,   140,
      87,    87,    87,    86,   145,   145,    69,    87,    87,    69,
     111,    87,   132,   108,   107,   140,   140,   140,   110,    87,
     110,    87,   110,    69,    87,    55,    87,   140,    87,   140,
      87,   140,    64,   140,   140
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 62 ".\\my_compiler.y"
    {
		root = new_node("Program",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 68 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("primary_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 71 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("primary_expression",1,(yyvsp[(1) - (1)].node));	
	}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 74 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("primary_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 77 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("primary_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 80 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("primary_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 86 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 89 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 92 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		//函数调用,不带参数
	}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 96 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
		//函数调用，带参数
	}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 100 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 103 ".\\my_compiler.y"
    {
		//a->b
		(yyval.node) = new_node("postfix_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 107 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
		//i++
	}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 111 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("postfix_expression",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
		//i--
	}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 118 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("argument_expression_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 121 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("argument_expression_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 127 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 130 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_expression",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
		//++i
	}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 134 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_expression",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
		//--i
	}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 138 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_expression",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 141 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_expression",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 144 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_expression",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 151 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 154 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 157 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 160 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 163 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 166 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("unary_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 172 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("cast_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 175 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("cast_expression",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 181 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("multiplicative_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 184 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("multiplicative_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 187 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("multiplicative_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 190 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("multiplicative_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 196 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("additive_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 199 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("additive_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 202 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("additive_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 208 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("shift_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 211 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("shift_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		// 左移<<
	}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 215 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("shift_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		// <<右移
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 222 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("relational_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 225 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("relational_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 228 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("relational_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 231 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("relational_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		// <= 
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 235 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("relational_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		// >=
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 242 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("equality_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 245 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("equality_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		// ==
	}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 249 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("equality_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		// !=
	}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 256 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("and_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 259 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("and_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 265 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("exclusive_or_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 268 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("exclusive_or_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		//异或表达式
	}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 275 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("inclusive_or_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 278 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("inclusive_or_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 284 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("logical_and_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 287 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("logical_and_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 293 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("logical_or_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 296 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("logical_or_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 302 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("conditional_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 305 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("conditional_expression",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
		//C语言唯一一个三目运算符
	}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 312 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("assignment_expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 315 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("assignment_expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 321 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 324 ".\\my_compiler.y"
    {
		//*=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 328 ".\\my_compiler.y"
    {
		// /=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 332 ".\\my_compiler.y"
    {
		// %=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 336 ".\\my_compiler.y"
    {
		// += 
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 340 ".\\my_compiler.y"
    {
		// -=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 344 ".\\my_compiler.y"
    {
		// <<=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 348 ".\\my_compiler.y"
    {
		// >>=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 352 ".\\my_compiler.y"
    {
		// &=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 356 ".\\my_compiler.y"
    {
		// ^=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 360 ".\\my_compiler.y"
    {
		// |=
		(yyval.node) = new_node("assignment_operator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 367 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("expression",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 370 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("expression",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 376 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("constant_expression",1,(yyvsp[(1) - (1)].node));
		//常量表达式-->条件表达式
	}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 383 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); 
		// int; 在C语言中是合法的
	}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 387 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 393 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_specifiers",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 396 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_specifiers",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); 
	}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 399 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_specifiers",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 402 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_specifiers",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); 
	}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 405 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_specifiers",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 408 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_specifiers",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); 
	}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 414 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("init_declarator_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 417 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("init_declarator_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 423 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("init_declarator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 426 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("init_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 432 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("storage_class_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 435 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("storage_class_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 438 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("storage_class_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 441 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("storage_class_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 444 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("storage_class_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 450 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 453 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 456 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 459 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));	
	}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 462 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 465 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
		//结构体
	}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 469 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 472 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_specifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 478 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_or_union_specifier",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
	}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 481 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_or_union_specifier",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 484 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_or_union_specifier",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 490 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_or_union",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 493 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_or_union",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 499 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declaration_list",1,(yyvsp[(1) - (1)].node));		
	}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 502 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declaration_list",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 508 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declaration",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 514 ".\\my_compiler.y"
    {	
		(yyval.node) = new_node("specifier_qualifier_list",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 517 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("specifier_qualifier_list",1,(yyvsp[(1) - (1)].node));	
	}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 520 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("specifier_qualifier_list",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 523 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("specifier_qualifier_list",1,(yyvsp[(1) - (1)].node));	
	}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 529 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declarator_list",1,(yyvsp[(1) - (1)].node));	
	}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 532 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declarator_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 538 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declarator",1,(yyvsp[(1) - (1)].node));	
	}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 541 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declarator",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 544 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("struct_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
		//形如 int a:1,结构体的空间分配
	}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 551 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("enum_specifier",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 554 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("enum_specifier",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(4) - (5)].node));
	}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 557 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("enum_specifier",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 563 ".\\my_compiler.y"
    {
		//枚举
		(yyval.node) = new_node("enumerator_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 567 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("enumerator_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 573 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("enumerator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 576 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("enumerator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 582 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_qualifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 585 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_qualifier",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 591 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declarator",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 594 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declarator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 601 ".\\my_compiler.y"
    {
		//变量     
		(yyval.node) = new_node("direct_declarator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 605 ".\\my_compiler.y"
    {
		//.....
		(yyval.node) = new_node("direct_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 609 ".\\my_compiler.y"
    {
		//数组
		(yyval.node) = new_node("direct_declarator",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 613 ".\\my_compiler.y"
    {
		//数组
		(yyval.node) = new_node("direct_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 617 ".\\my_compiler.y"
    {
		//函数
		(yyval.node) = new_node("direct_declarator",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 621 ".\\my_compiler.y"
    {
		//函数
		(yyval.node) = new_node("direct_declarator",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 625 ".\\my_compiler.y"
    {
		//函数
		(yyval.node) = new_node("direct_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 632 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("pointer",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 635 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("pointer",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 638 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("pointer",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 641 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("pointer",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 648 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("parameter_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 651 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("parameter_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 657 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("parameter_declaration",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 660 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("parameter_declaration",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 663 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("parameter_declaration",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 669 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("identifier_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 672 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("identifier_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 678 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_name",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 681 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("type_name",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 687 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("abstract_declarator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 690 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("abstract_declarator",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 693 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("abstract_declarator",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 699 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 702 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 705 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 708 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 711 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 714 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 717 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 720 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 723 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("direct_abstract_declarator",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 729 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("initializer",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 732 ".\\my_compiler.y"
    {
		//列表初始化 {1,1,1}
		(yyval.node) = new_node("initializer",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 736 ".\\my_compiler.y"
    {
		//列表初始化 {1,1,1,}
		(yyval.node) = new_node("initializer",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 743 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("initializer_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 746 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("initializer_list",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 753 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 756 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 759 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 762 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 765 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 768 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 774 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("labeled_statement",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 777 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("labeled_statement",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 780 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("labeled_statement",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 786 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("compound_statement",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 789 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("compound_statement",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 795 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("block_item_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 798 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("block_item_list",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 804 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("block_item",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 807 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("block_item",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 813 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("expression_statement",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 816 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("expression_statement",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 822 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("selection_statement",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
	}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 825 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("selection_statement",7,(yyvsp[(1) - (7)].node),(yyvsp[(2) - (7)].node),(yyvsp[(3) - (7)].node),(yyvsp[(4) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(6) - (7)].node),(yyvsp[(7) - (7)].node));
	}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 828 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("selection_statement",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
	}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 834 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("iteration_statement",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));
	}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 837 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("iteration_statement",7,(yyvsp[(1) - (7)].node),(yyvsp[(2) - (7)].node),(yyvsp[(3) - (7)].node),(yyvsp[(4) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(6) - (7)].node),(yyvsp[(7) - (7)].node));
	}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 840 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("iteration_statement",6,(yyvsp[(1) - (6)].node),(yyvsp[(2) - (6)].node),(yyvsp[(3) - (6)].node),(yyvsp[(4) - (6)].node),(yyvsp[(5) - (6)].node),(yyvsp[(6) - (6)].node));
	}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 843 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("iteration_statement",7,(yyvsp[(1) - (7)].node),(yyvsp[(2) - (7)].node),(yyvsp[(3) - (7)].node),(yyvsp[(4) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(6) - (7)].node),(yyvsp[(7) - (7)].node));
	}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 846 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("iteration_statement",6,(yyvsp[(1) - (6)].node),(yyvsp[(2) - (6)].node),(yyvsp[(3) - (6)].node),(yyvsp[(4) - (6)].node),(yyvsp[(5) - (6)].node),(yyvsp[(6) - (6)].node));
	}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 849 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("iteration_statement",7,(yyvsp[(1) - (7)].node),(yyvsp[(2) - (7)].node),(yyvsp[(3) - (7)].node),(yyvsp[(4) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(6) - (7)].node),(yyvsp[(7) - (7)].node));
	}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 855 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("jump_statement",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 858 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("jump_statement",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 861 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("jump_statement",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 864 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("jump_statement",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 867 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("jump_statement",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 873 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("translation_unit",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 876 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("translation_unit",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 882 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("external_declaration",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 885 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("external_declaration",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 891 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("function_definition",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));
	}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 894 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("function_definition",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
	}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 900 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_list",1,(yyvsp[(1) - (1)].node));
	}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 903 ".\\my_compiler.y"
    {
		(yyval.node) = new_node("declaration_list",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));
	}
    break;


/* Line 1792 of yacc.c  */
#line 3614 "my_compiler.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 909 ".\\my_compiler.y"


void yyerror(char const *s)
{
	printf("error_in_line_ %d：%s\n",yylineno,s);
}


int main(int argc,char* argv[]) {

	yyin=stdin;
	if(argc>1) {
		if((yyin=fopen(argv[1],"r"))==NULL) {
			printf("Can't open file %s\n",argv[1]);
			return -1;
		}
	}
	yyparse();
	printf("---------------------------lex_end----------------------------\n");

	print_AST(root,0);	//输出抽象语法树
	printf("-----------------------print_AST_end--------------------------\n");

	Praser praser(root);
	
	fclose(yyin);
	return 0;
}
