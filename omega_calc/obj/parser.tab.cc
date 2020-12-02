
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 15 "../src/parser.yy"


#include <basic/Dynamic_Array.h>
#include <basic/Iterator.h>
#include <omega_calc/AST.h>
#include <omega/hull.h>
#include <omega/closure.h>
#include <omega/reach.h>
#include <string>
#include <iostream>
#include <fstream>
#include "parser.tab.hh"
#include <omega_calc/myflex.h>

#if defined __USE_POSIX
#include <unistd.h>
#elif defined  __WIN32
#include <io.h>
#endif
  
#ifdef BUILD_CODEGEN  
#include <code_gen/codegen.h>
#endif

extern myFlexLexer mylexer;
#define yylex mylexer.yylex
extern bool is_interactive;
extern const char *PROMPT_STRING;
  
using namespace omega;

extern std::string err_msg;
bool need_coef;

namespace {
  int redundant_conj_level = 2;  // default maximum 2
  int redundant_constr_level = 4;  // default maximum 4
}

std::map<std::string, Relation *> relationMap;
int argCount = 0;
int tuplePos = 0;
Argument_Tuple currentTuple = Input_Tuple;

Relation LexForward(int n);
reachable_information *reachable_info;

void yyerror(const std::string &s);
void flushScanBuffer();



/* Line 189 of yacc.c  */
#line 126 "parser.tab.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     INT = 259,
     COEF = 260,
     STRING = 261,
     OPEN_BRACE = 262,
     CLOSE_BRACE = 263,
     SYMBOLIC = 264,
     OR = 265,
     AND = 266,
     NOT = 267,
     ST = 268,
     APPROX = 269,
     IS_ASSIGNED = 270,
     FORALL = 271,
     EXISTS = 272,
     DOMAIN = 273,
     RANGE = 274,
     DIFFERENCE = 275,
     DIFFERENCE_TO_RELATION = 276,
     GIST = 277,
     GIVEN = 278,
     HULL = 279,
     WITHIN = 280,
     MAXIMIZE = 281,
     MINIMIZE = 282,
     AFFINE_HULL = 283,
     VENN = 284,
     CONVEX_COMBINATION = 285,
     POSITIVE_COMBINATION = 286,
     LINEAR_COMBINATION = 287,
     AFFINE_COMBINATION = 288,
     CONVEX_HULL = 289,
     CONIC_HULL = 290,
     LINEAR_HULL = 291,
     QUICK_HULL = 292,
     PAIRWISE_CHECK = 293,
     CONVEX_CHECK = 294,
     CONVEX_REPRESENTATION = 295,
     RECT_HULL = 296,
     SIMPLE_HULL = 297,
     DECOUPLED_CONVEX_HULL = 298,
     MAXIMIZE_RANGE = 299,
     MINIMIZE_RANGE = 300,
     MAXIMIZE_DOMAIN = 301,
     MINIMIZE_DOMAIN = 302,
     LEQ = 303,
     GEQ = 304,
     NEQ = 305,
     GOES_TO = 306,
     COMPOSE = 307,
     JOIN = 308,
     INVERSE = 309,
     COMPLEMENT = 310,
     IN = 311,
     CARRIED_BY = 312,
     UNION = 313,
     INTERSECTION = 314,
     VERTICAL_BAR = 315,
     SUCH_THAT = 316,
     SUBSET = 317,
     CODEGEN = 318,
     DECOUPLED_FARKAS = 319,
     FARKAS = 320,
     MAKE_UPPER_BOUND = 321,
     MAKE_LOWER_BOUND = 322,
     REL_OP = 323,
     RESTRICT_DOMAIN = 324,
     RESTRICT_RANGE = 325,
     SUPERSETOF = 326,
     SUBSETOF = 327,
     SAMPLE = 328,
     SYM_SAMPLE = 329,
     PROJECT_AWAY_SYMBOLS = 330,
     PROJECT_ON_SYMBOLS = 331,
     REACHABLE_FROM = 332,
     REACHABLE_OF = 333,
     ASSERT_UNSAT = 334,
     PARSE_EXPRESSION = 335,
     PARSE_FORMULA = 336,
     PARSE_RELATION = 337,
     p1 = 338,
     p2 = 339,
     p3 = 340,
     p4 = 341,
     p5 = 342,
     p6 = 343,
     p7 = 344,
     p8 = 345,
     p9 = 346,
     p10 = 347
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 67 "../src/parser.yy"

  int INT_VALUE;
  omega::coef_t COEF_VALUE;
  Rel_Op REL_OPERATOR;
  char *VAR_NAME;
  std::set<char *> *VAR_LIST;
  Exp *EXP;
  std::set<Exp *> *EXP_LIST;
  AST *ASTP;
  omega::Argument_Tuple ARGUMENT_TUPLE;
  AST_constraints *ASTCP;
  Declaration_Site *DECLARATION_SITE;
  omega::Relation *RELATION;
  tupleDescriptor *TUPLE_DESCRIPTOR;
  std::pair<std::vector<omega::Relation>, std::vector<omega::Relation> > *REL_TUPLE_PAIR;
  omega::Dynamic_Array1<omega::Relation> * RELATION_ARRAY_1D;
  std::string *STRING_VALUE;



/* Line 214 of yacc.c  */
#line 275 "parser.tab.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 287 "parser.tab.cc"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   684

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  301

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      96,   101,    87,    83,    99,    84,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   100,    98,
       2,     2,     2,     2,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   103,     2,   104,   102,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    85,    86,
      89,    90,    91,    92,    93,    94,    95,    97
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     9,    11,    14,    18,    23,
      26,    31,    36,    42,    45,    46,    49,    55,    59,    63,
      65,    66,    71,    73,    77,    80,    83,    88,    92,    96,
      99,   102,   105,   108,   111,   114,   117,   120,   123,   126,
     129,   132,   135,   138,   141,   146,   149,   152,   155,   158,
     161,   164,   167,   170,   173,   176,   179,   182,   185,   188,
     191,   194,   199,   202,   205,   208,   211,   216,   221,   225,
     229,   233,   237,   241,   245,   249,   253,   257,   260,   263,
     266,   269,   272,   275,   277,   280,   281,   282,   289,   292,
     294,   297,   298,   300,   302,   304,   305,   310,   311,   313,
     317,   319,   321,   323,   327,   333,   337,   339,   341,   343,
     347,   351,   353,   358,   360,   364,   368,   370,   374,   377,
     383,   389,   392,   395,   397,   399,   401,   404,   407,   409,
     411,   415,   417,   421,   425,   427,   428,   434,   438,   442,
     444,   446,   449,   451,   454,   458,   462,   466,   470,   476,
     480,   484,   486,   490,   496,   504,   510
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,    -1,    -1,   106,   107,   108,    -1,    98,
      -1,     1,    98,    -1,     9,   125,    98,    -1,     3,    15,
     111,    98,    -1,   111,    98,    -1,   111,    62,   111,    98,
      -1,    63,   110,   109,    98,    -1,    63,     4,   110,   109,
      98,    -1,   139,    98,    -1,    -1,    23,   111,    -1,   110,
      99,   111,   100,   111,    -1,   110,    99,   111,    -1,   111,
     100,   111,    -1,   111,    -1,    -1,     7,   112,   113,     8,
      -1,     3,    -1,    96,   111,   101,    -1,   111,    83,    -1,
     111,    87,    -1,   111,    83,    25,   111,    -1,   111,   102,
      88,    -1,   111,   102,    83,    -1,    45,   111,    -1,    44,
     111,    -1,    47,   111,    -1,    46,   111,    -1,    26,   111,
      -1,    27,   111,    -1,    65,   111,    -1,    64,   111,    -1,
     111,    88,    -1,    75,   111,    -1,    76,   111,    -1,    20,
     111,    -1,    21,   111,    -1,    18,   111,    -1,    29,   111,
      -1,    29,   111,    23,   111,    -1,    34,   111,    -1,    43,
     111,    -1,    31,   111,    -1,    32,   111,    -1,    33,   111,
      -1,    30,   111,    -1,    38,   111,    -1,    39,   111,    -1,
      40,   111,    -1,    28,   111,    -1,    35,   111,    -1,    36,
     111,    -1,    37,   111,    -1,    41,   111,    -1,    42,   111,
      -1,    24,   111,    -1,    24,   111,    23,   111,    -1,    14,
     111,    -1,    19,   111,    -1,    54,   111,    -1,    55,   111,
      -1,    22,   111,    23,   111,    -1,   111,    96,   111,   101,
      -1,   111,    52,   111,    -1,   111,    57,     4,    -1,   111,
      53,   111,    -1,   111,    70,   111,    -1,   111,    69,   111,
      -1,   111,    59,   111,    -1,   111,    84,   111,    -1,   111,
      58,   111,    -1,   111,    87,   111,    -1,    71,   111,    -1,
      72,   111,    -1,    66,   111,    -1,    67,   111,    -1,    73,
     111,    -1,    74,   111,    -1,   140,    -1,    79,   111,    -1,
      -1,    -1,   118,    51,   114,   118,   115,   116,    -1,   118,
     116,    -1,   127,    -1,   117,   127,    -1,    -1,   100,    -1,
      60,    -1,    61,    -1,    -1,   119,   103,   120,   104,    -1,
      -1,   121,    -1,   120,    99,   121,    -1,     3,    -1,    87,
      -1,   138,    -1,   138,   100,   138,    -1,   138,   100,   138,
     100,     5,    -1,   122,    99,     3,    -1,     3,    -1,   122,
      -1,   123,    -1,   103,   123,   104,    -1,   125,    99,   126,
      -1,   126,    -1,     3,    96,     4,   101,    -1,     3,    -1,
     127,    11,   127,    -1,   127,    10,   127,    -1,   134,    -1,
      96,   127,   101,    -1,    12,   127,    -1,   128,   124,   129,
     127,   132,    -1,   130,   124,   131,   127,   132,    -1,    96,
      17,    -1,    17,    96,    -1,   100,    -1,    60,    -1,    61,
      -1,    96,    16,    -1,    16,    96,    -1,   100,    -1,   101,
      -1,   138,    99,   133,    -1,   138,    -1,   133,    68,   133,
      -1,   133,    68,   134,    -1,     3,    -1,    -1,     3,    96,
     136,   137,   101,    -1,    96,   138,   101,    -1,   137,    99,
       3,    -1,     3,    -1,     5,    -1,     5,   135,    -1,   135,
      -1,    84,   138,    -1,   138,    83,   138,    -1,   138,    84,
     138,    -1,   138,    87,   138,    -1,    77,   141,   143,    -1,
      78,     3,    56,   141,   143,    -1,    96,   142,   101,    -1,
     142,    99,     3,    -1,     3,    -1,     7,   144,     8,    -1,
     144,    99,     3,   100,   111,    -1,   144,    99,     3,    51,
       3,   100,   111,    -1,     3,    51,     3,   100,   111,    -1,
       3,   100,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   161,   161,   162,   162,   166,   167,   177,   178,   191,
     197,   213,   236,   259,   278,   279,   282,   298,   312,   329,
     346,   346,   354,   364,   365,   378,   392,   407,   420,   433,
     449,   465,   481,   497,   513,   529,   542,   555,   568,   581,
     594,   607,   620,   633,   646,   661,   674,   687,   700,   713,
     726,   739,   752,   765,   778,   791,   804,   817,   830,   843,
     856,   869,   884,   897,   910,   923,   936,   951,   966,   981,
     995,  1010,  1025,  1040,  1055,  1070,  1085,  1100,  1113,  1126,
    1139,  1152,  1165,  1178,  1179,  1189,  1190,  1189,  1223,  1244,
    1253,  1254,  1257,  1258,  1259,  1262,  1262,  1267,  1268,  1269,
    1272,  1291,  1292,  1296,  1300,  1306,  1307,  1310,  1318,  1319,
    1322,  1323,  1326,  1327,  1333,  1334,  1335,  1336,  1337,  1338,
    1339,  1342,  1343,  1346,  1347,  1348,  1351,  1352,  1355,  1358,
    1361,  1362,  1365,  1366,  1369,  1379,  1379,  1393,  1396,  1412,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1448,  1454,  1472,
    1480,  1484,  1492,  1536,  1550,  1575,  1600
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "COEF", "STRING",
  "OPEN_BRACE", "CLOSE_BRACE", "SYMBOLIC", "OR", "AND", "NOT", "ST",
  "APPROX", "IS_ASSIGNED", "FORALL", "EXISTS", "DOMAIN", "RANGE",
  "DIFFERENCE", "DIFFERENCE_TO_RELATION", "GIST", "GIVEN", "HULL",
  "WITHIN", "MAXIMIZE", "MINIMIZE", "AFFINE_HULL", "VENN",
  "CONVEX_COMBINATION", "POSITIVE_COMBINATION", "LINEAR_COMBINATION",
  "AFFINE_COMBINATION", "CONVEX_HULL", "CONIC_HULL", "LINEAR_HULL",
  "QUICK_HULL", "PAIRWISE_CHECK", "CONVEX_CHECK", "CONVEX_REPRESENTATION",
  "RECT_HULL", "SIMPLE_HULL", "DECOUPLED_CONVEX_HULL", "MAXIMIZE_RANGE",
  "MINIMIZE_RANGE", "MAXIMIZE_DOMAIN", "MINIMIZE_DOMAIN", "LEQ", "GEQ",
  "NEQ", "GOES_TO", "COMPOSE", "JOIN", "INVERSE", "COMPLEMENT", "IN",
  "CARRIED_BY", "UNION", "INTERSECTION", "VERTICAL_BAR", "SUCH_THAT",
  "SUBSET", "CODEGEN", "DECOUPLED_FARKAS", "FARKAS", "MAKE_UPPER_BOUND",
  "MAKE_LOWER_BOUND", "REL_OP", "RESTRICT_DOMAIN", "RESTRICT_RANGE",
  "SUPERSETOF", "SUBSETOF", "SAMPLE", "SYM_SAMPLE", "PROJECT_AWAY_SYMBOLS",
  "PROJECT_ON_SYMBOLS", "REACHABLE_FROM", "REACHABLE_OF", "ASSERT_UNSAT",
  "PARSE_EXPRESSION", "PARSE_FORMULA", "PARSE_RELATION", "'+'", "'-'",
  "p1", "p2", "'*'", "'@'", "p3", "p4", "p5", "p6", "p7", "p8", "p9",
  "'('", "p10", "';'", "','", "':'", "')'", "'^'", "'['", "']'", "$accept",
  "inputSequence", "$@1", "inputItem", "context", "relPairList",
  "relation", "$@2", "builtRelation", "$@3", "$@4", "optionalFormula",
  "formula_sep", "tupleDeclaration", "$@5", "optionalTupleVarList",
  "tupleVar", "varList", "varDecl", "varDeclOptBrackets", "globVarList",
  "globVar", "formula", "start_exists", "exists_sep", "start_forall",
  "forall_sep", "end_quant", "expList", "constraintChain", "simpleExp",
  "$@6", "argumentList", "exp", "reachable", "reachable_of",
  "nodeNameList", "realNodeNameList", "nodeSpecificationList",
  "realNodeSpecificationList", 0
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,    43,    45,   338,   339,    42,    64,   340,
     341,   342,   343,   344,   345,   346,    40,   347,    59,    44,
      58,    41,    94,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   107,   106,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   110,   110,
     112,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   114,   115,   113,   113,   113,
     116,   116,   117,   117,   117,   119,   118,   120,   120,   120,
     121,   121,   121,   121,   121,   122,   122,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   129,   129,   129,   130,   130,   131,   132,
     133,   133,   134,   134,   135,   136,   135,   135,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   139,   140,   141,
     142,   142,   143,   144,   144,   144,   144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     1,     2,     3,     4,     2,
       4,     4,     5,     2,     0,     2,     5,     3,     3,     1,
       0,     4,     1,     3,     2,     2,     4,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     2,     2,     2,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     1,     2,     0,     0,     6,     2,     1,
       2,     0,     1,     1,     1,     0,     4,     0,     1,     3,
       1,     1,     1,     3,     5,     3,     1,     1,     1,     3,
       3,     1,     4,     1,     3,     3,     1,     3,     2,     5,
       5,     2,     2,     1,     1,     1,     2,     2,     1,     1,
       3,     1,     3,     3,     1,     0,     5,     3,     3,     1,
       1,     2,     1,     2,     3,     3,     3,     3,     5,     3,
       3,     1,     3,     5,     7,     5,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     1,     0,     0,    22,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     4,     0,     0,    83,     6,
       0,    95,   113,     0,   111,    22,    62,    42,    63,    40,
      41,     0,    60,    33,    34,    54,    43,    50,    47,    48,
      49,    45,    55,    56,    57,    51,    52,    53,    58,    59,
      46,    30,    29,    32,    31,    64,    65,     0,    14,    19,
      36,    35,    79,    80,    77,    78,    81,    82,    38,    39,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    25,    37,     0,     9,     0,
      13,     0,   134,   140,     0,     0,     0,     0,     0,     0,
      91,     0,    89,     0,     0,     0,   116,   142,   131,     0,
       7,     0,     0,     0,     0,    14,     0,     0,     0,     0,
     151,     0,     0,   147,     0,    23,    68,    70,    69,    75,
      73,     0,    72,    71,     0,    74,    76,     0,    28,    27,
       8,   135,     0,   141,   118,   127,   122,   143,   126,   121,
       0,   131,    21,    85,    93,    94,    92,    88,     0,    97,
       0,     0,   106,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,   110,    66,    61,    44,     0,    15,
      17,    11,    18,     0,   149,     0,     0,     0,    10,    26,
      67,     0,     0,   117,   137,    95,    90,   134,   101,     0,
      98,   102,   115,   114,     0,     0,   124,   125,   123,     0,
     128,     0,   132,   133,   144,   145,   146,   130,   112,    12,
       0,   150,     0,     0,   152,     0,   148,   139,     0,    86,
       0,    96,     0,   109,   105,     0,     0,    16,     0,   156,
       0,     0,   136,    91,    99,   103,   129,   119,   120,     0,
       0,     0,   138,    87,     0,   155,     0,   153,   104,     0,
     154
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    55,   158,    98,    99,    61,   139,   235,
     283,   197,   198,   140,   141,   239,   240,   204,   205,   206,
      63,    64,   142,   143,   249,   144,   251,   287,   145,   146,
     147,   231,   268,   148,    57,    58,   111,   161,   163,   226
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
    -136,    48,  -136,   163,   -40,    72,  -136,    93,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   271,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
      14,   117,   350,   350,  -136,  -136,   398,    40,  -136,  -136,
     350,    49,    45,    30,  -136,  -136,   -23,   -23,   -23,   -23,
     -23,   378,    61,   -23,   -23,   -23,    63,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   350,    37,   418,
     -23,   -23,   -23,   -23,   460,   460,   -23,   -23,   -23,   -23,
     141,   145,   106,   562,   440,   350,   350,   174,   350,   350,
     350,   350,   350,   143,   350,   350,  -136,   350,  -136,     2,
    -136,   480,    84,     1,    49,    90,    92,    50,    77,   212,
      11,   118,   202,    -2,    -2,   154,  -136,  -136,    56,   220,
    -136,    93,   350,   350,   350,    37,   350,   350,   134,   350,
    -136,     3,   222,  -136,    14,  -136,   -23,   -23,  -136,   460,
      46,   500,   582,   582,   350,    46,    46,   522,  -136,  -136,
    -136,  -136,    50,  -136,  -136,  -136,  -136,  -136,    90,    92,
      57,   132,  -136,  -136,  -136,  -136,  -136,  -136,    49,   127,
      49,    49,  -136,   240,   151,  -136,    31,   144,    50,    50,
      50,    50,    50,   152,  -136,   -23,   -23,   -23,   156,   562,
     542,  -136,   562,   249,  -136,     0,    28,   145,  -136,   -23,
    -136,   252,    -6,  -136,  -136,  -136,   202,    10,  -136,   -16,
    -136,   162,   245,  -136,   159,   255,  -136,  -136,  -136,    49,
    -136,    49,   154,  -136,   178,   178,  -136,  -136,  -136,  -136,
     350,  -136,   263,   350,  -136,   264,  -136,  -136,    68,  -136,
     127,  -136,    50,  -136,  -136,    59,    59,   562,   168,   562,
       5,   266,  -136,    47,  -136,   164,  -136,  -136,  -136,   350,
     267,   350,  -136,  -136,   268,   562,   171,   562,  -136,   350,
     562
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   121,   175,    -3,  -136,  -136,  -136,
    -136,    -4,  -136,    42,  -136,  -136,    12,  -136,    78,   136,
    -136,   133,   -75,  -136,  -136,  -136,  -136,     7,   -33,    79,
     161,  -136,  -136,  -135,  -136,  -136,   155,  -136,    94,  -136
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -101
static const yytype_int16 yytable[] =
{
      56,   202,   187,   191,   132,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   264,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   232,     2,   113,
     114,   262,   132,   132,   133,   133,   290,   131,    59,   184,
     156,   134,   193,   190,   241,   135,   136,   200,   201,   200,
     201,   194,   195,   127,   254,   255,   256,   209,   210,   129,
     132,   211,   133,   270,   153,   178,   154,    60,   271,   134,
     179,   246,   247,   188,   189,   234,    62,   182,   115,   116,
     263,   203,   223,   117,   224,   291,   181,   194,   195,  -100,
     110,   196,   166,   167,  -100,   169,   170,   171,   172,   173,
     112,   175,   176,   236,   177,   242,   243,   265,   150,   151,
     237,   248,   133,   137,   137,   241,   157,   285,   130,   209,
     210,   149,   127,   211,   160,   138,   182,   196,   129,   215,
     216,   217,   162,   219,   220,   212,   222,   127,   233,   127,
     286,   137,   164,   129,     4,   129,     5,   281,   174,   282,
       6,   229,     7,   138,   275,   252,   276,     8,   168,   257,
     181,     9,    10,    11,    12,    13,   185,    14,   186,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   137,   200,   201,   238,   209,   210,    37,    38,   211,
     192,   199,   208,   182,   213,   225,    39,    40,    41,    42,
      43,   212,   221,   234,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   202,   250,   209,   210,   209,   210,   211,
     245,   211,   261,   258,   259,   267,   201,   277,   274,    53,
     279,    54,   272,   273,   294,   211,   278,   280,   289,   292,
     296,   299,   155,   298,    65,    97,   218,   269,     6,   293,
     207,   244,   284,   288,   214,     8,   295,   253,   297,     9,
      10,    11,    12,    13,   183,    14,   300,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,   227,
       0,   266,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    41,    42,    43,     0,
       0,     0,    44,    45,    46,    47,    48,    49,     0,    51,
      52,     0,     0,    65,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     8,     0,     0,    53,     9,    10,
      11,    12,    13,     0,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,   152,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,    42,    43,     0,     0,
       0,    44,    45,    46,    47,    48,    49,     0,    51,    52,
     115,   116,     0,     0,     0,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,    53,   121,   122,     0,
     115,   116,     0,     0,     0,   117,   118,   119,     0,     0,
     120,   123,   124,     0,     0,   125,   126,   121,   122,     0,
     115,   116,     0,     0,   127,   117,   118,   119,     0,     0,
     129,   123,   124,     0,     0,   125,   126,   121,   122,     0,
       0,     0,   115,   116,   127,     0,   128,   117,   118,   119,
     129,   123,   124,     0,     0,   125,   126,     0,     0,   121,
     122,     0,   115,   116,   127,     0,     0,   117,   159,   119,
     129,     0,     0,   123,   124,     0,     0,   125,   126,   121,
     122,     0,   115,   116,     0,     0,   127,   117,   118,   119,
       0,   165,   129,     0,     0,     0,     0,   125,   126,   121,
     122,     0,   115,   116,     0,     0,   127,   117,   118,   119,
       0,     0,   129,   123,   124,     0,     0,   125,   126,   121,
     122,     0,     0,     0,   115,   116,   127,     0,   180,   117,
     118,   119,   129,   123,   124,     0,     0,   125,   126,     0,
       0,   121,   122,     0,   115,   116,   127,     0,   228,   117,
     118,   119,   129,     0,     0,   123,   124,     0,     0,   125,
     126,   121,   122,     0,   115,   116,     0,     0,   127,   117,
     118,   119,     0,   230,   129,   123,   124,     0,     0,   125,
     126,   121,   122,     0,   115,   116,     0,     0,   127,   117,
       0,   119,   260,     0,   129,   123,   124,     0,     0,   125,
     126,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,     0,     0,   129,     0,     0,     0,     0,   125,
     126,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,     0,     0,   129
};

static const yytype_int16 yycheck[] =
{
       3,     3,   137,   138,     3,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     8,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   182,     0,    52,
      53,    51,     3,     3,     5,     5,    51,    60,    98,   134,
      23,    12,    51,   138,   199,    16,    17,    10,    11,    10,
      11,    60,    61,    96,   209,   210,   211,    83,    84,   102,
       3,    87,     5,    99,    23,    83,    23,    15,   104,    12,
      88,    60,    61,    16,    17,   101,     3,    96,    52,    53,
     100,   103,    99,    57,   101,   100,    96,    60,    61,    99,
      96,   100,   115,   116,   104,   118,   119,   120,   121,   122,
       3,   124,   125,   198,   127,   200,   201,    99,    98,    99,
       3,   100,     5,    84,    84,   270,    99,   272,    98,    83,
      84,    96,    96,    87,     3,    96,    96,   100,   102,   152,
     153,   154,     7,   156,   157,    99,   159,    96,   101,    96,
     101,    84,    56,   102,     1,   102,     3,    99,    25,   101,
       7,   174,     9,    96,   249,   208,   251,    14,     4,   212,
      96,    18,    19,    20,    21,    22,    96,    24,    96,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    84,    10,    11,    87,    83,    84,    54,    55,    87,
       8,   103,    68,    96,     4,     3,    63,    64,    65,    66,
      67,    99,    98,   101,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     3,   100,    83,    84,    83,    84,    87,
      99,    87,     3,   101,    98,     3,    11,   260,     3,    96,
     263,    98,   100,   104,   100,    87,     3,     3,   100,     3,
       3,   100,    97,     5,     3,     4,   155,   235,     7,   283,
     144,   203,   270,   276,   151,    14,   289,   208,   291,    18,
      19,    20,    21,    22,   133,    24,   299,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   164,
      -1,   227,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    -1,     3,    -1,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    96,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    23,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    69,    70,    -1,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    83,    84,    -1,    -1,    87,    88,    69,    70,    -1,
      52,    53,    -1,    -1,    96,    57,    58,    59,    -1,    -1,
     102,    83,    84,    -1,    -1,    87,    88,    69,    70,    -1,
      -1,    -1,    52,    53,    96,    -1,    98,    57,    58,    59,
     102,    83,    84,    -1,    -1,    87,    88,    -1,    -1,    69,
      70,    -1,    52,    53,    96,    -1,    -1,    57,   100,    59,
     102,    -1,    -1,    83,    84,    -1,    -1,    87,    88,    69,
      70,    -1,    52,    53,    -1,    -1,    96,    57,    58,    59,
      -1,   101,   102,    -1,    -1,    -1,    -1,    87,    88,    69,
      70,    -1,    52,    53,    -1,    -1,    96,    57,    58,    59,
      -1,    -1,   102,    83,    84,    -1,    -1,    87,    88,    69,
      70,    -1,    -1,    -1,    52,    53,    96,    -1,    98,    57,
      58,    59,   102,    83,    84,    -1,    -1,    87,    88,    -1,
      -1,    69,    70,    -1,    52,    53,    96,    -1,    98,    57,
      58,    59,   102,    -1,    -1,    83,    84,    -1,    -1,    87,
      88,    69,    70,    -1,    52,    53,    -1,    -1,    96,    57,
      58,    59,    -1,   101,   102,    83,    84,    -1,    -1,    87,
      88,    69,    70,    -1,    52,    53,    -1,    -1,    96,    57,
      -1,    59,   100,    -1,   102,    83,    84,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   106,     0,   107,     1,     3,     7,     9,    14,    18,
      19,    20,    21,    22,    24,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    54,    55,    63,
      64,    65,    66,    67,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    96,    98,   108,   111,   139,   140,    98,
      15,   112,     3,   125,   126,     3,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,     4,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
      96,   141,     3,   111,   111,    52,    53,    57,    58,    59,
      62,    69,    70,    83,    84,    87,    88,    96,    98,   102,
      98,   111,     3,     5,    12,    16,    17,    84,    96,   113,
     118,   119,   127,   128,   130,   133,   134,   135,   138,    96,
      98,    99,    23,    23,    23,   110,    23,    99,   109,   100,
       3,   142,     7,   143,    56,   101,   111,   111,     4,   111,
     111,   111,   111,   111,    25,   111,   111,   111,    83,    88,
      98,    96,    96,   135,   127,    96,    96,   138,    16,    17,
     127,   138,     8,    51,    60,    61,   100,   116,   117,   103,
      10,    11,     3,   103,   122,   123,   124,   124,    68,    83,
      84,    87,    99,     4,   126,   111,   111,   111,   109,   111,
     111,    98,   111,    99,   101,     3,   144,   141,    98,   111,
     101,   136,   138,   101,   101,   114,   127,     3,    87,   120,
     121,   138,   127,   127,   123,    99,    60,    61,   100,   129,
     100,   131,   133,   134,   138,   138,   138,   133,   101,    98,
     100,     3,    51,   100,     8,    99,   143,     3,   137,   118,
      99,   104,   100,   104,     3,   127,   127,   111,     3,   111,
       3,    99,   101,   115,   121,   138,   101,   132,   132,   100,
      51,   100,     3,   116,   100,   111,     3,   111,     5,   100,
     111
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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
      case 3: /* "VAR" */

/* Line 1000 of yacc.c  */
#line 129 "../src/parser.yy"
	{delete [](yyvaluep->VAR_NAME);};

/* Line 1000 of yacc.c  */
#line 1556 "parser.tab.cc"
	break;
      case 6: /* "STRING" */

/* Line 1000 of yacc.c  */
#line 130 "../src/parser.yy"
	{delete (yyvaluep->STRING_VALUE);};

/* Line 1000 of yacc.c  */
#line 1565 "parser.tab.cc"
	break;
      case 109: /* "context" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->RELATION);};

/* Line 1000 of yacc.c  */
#line 1574 "parser.tab.cc"
	break;
      case 110: /* "relPairList" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->REL_TUPLE_PAIR);};

/* Line 1000 of yacc.c  */
#line 1583 "parser.tab.cc"
	break;
      case 111: /* "relation" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->RELATION);};

/* Line 1000 of yacc.c  */
#line 1592 "parser.tab.cc"
	break;
      case 113: /* "builtRelation" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->RELATION);};

/* Line 1000 of yacc.c  */
#line 1601 "parser.tab.cc"
	break;
      case 116: /* "optionalFormula" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->ASTP);};

/* Line 1000 of yacc.c  */
#line 1610 "parser.tab.cc"
	break;
      case 118: /* "tupleDeclaration" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->TUPLE_DESCRIPTOR);};

/* Line 1000 of yacc.c  */
#line 1619 "parser.tab.cc"
	break;
      case 122: /* "varList" */

/* Line 1000 of yacc.c  */
#line 138 "../src/parser.yy"
	{
  for (std::set<char *>::iterator i = (yyvaluep->VAR_LIST)->begin(); i != (yyvaluep->VAR_LIST)->end(); i++)
    delete []*i;
  delete (yyvaluep->VAR_LIST);
 };

/* Line 1000 of yacc.c  */
#line 1632 "parser.tab.cc"
	break;
      case 123: /* "varDecl" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->DECLARATION_SITE);};

/* Line 1000 of yacc.c  */
#line 1641 "parser.tab.cc"
	break;
      case 124: /* "varDeclOptBrackets" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->DECLARATION_SITE);};

/* Line 1000 of yacc.c  */
#line 1650 "parser.tab.cc"
	break;
      case 127: /* "formula" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->ASTP);};

/* Line 1000 of yacc.c  */
#line 1659 "parser.tab.cc"
	break;
      case 133: /* "expList" */

/* Line 1000 of yacc.c  */
#line 133 "../src/parser.yy"
	{
  for (std::set<Exp *>::iterator i = (yyvaluep->EXP_LIST)->begin(); i != (yyvaluep->EXP_LIST)->end(); i++)
    delete *i;
  delete (yyvaluep->EXP_LIST);
 };

/* Line 1000 of yacc.c  */
#line 1672 "parser.tab.cc"
	break;
      case 134: /* "constraintChain" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->ASTCP);};

/* Line 1000 of yacc.c  */
#line 1681 "parser.tab.cc"
	break;
      case 135: /* "simpleExp" */

/* Line 1000 of yacc.c  */
#line 132 "../src/parser.yy"
	{delete (yyvaluep->EXP);};

/* Line 1000 of yacc.c  */
#line 1690 "parser.tab.cc"
	break;
      case 138: /* "exp" */

/* Line 1000 of yacc.c  */
#line 132 "../src/parser.yy"
	{delete (yyvaluep->EXP);};

/* Line 1000 of yacc.c  */
#line 1699 "parser.tab.cc"
	break;
      case 139: /* "reachable" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->RELATION_ARRAY_1D);};

/* Line 1000 of yacc.c  */
#line 1708 "parser.tab.cc"
	break;
      case 140: /* "reachable_of" */

/* Line 1000 of yacc.c  */
#line 131 "../src/parser.yy"
	{delete (yyvaluep->RELATION);};

/* Line 1000 of yacc.c  */
#line 1717 "parser.tab.cc"
	break;

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
        case 3:

/* Line 1455 of yacc.c  */
#line 162 "../src/parser.yy"
    { assert( current_Declaration_Site == globalDecls);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 167 "../src/parser.yy"
    {
            flushScanBuffer();
            std::cout << err_msg;
            err_msg.clear();
            current_Declaration_Site = globalDecls;
            need_coef = false;
            std::cout << "...skipping to statement end..." << std::endl;
            delete relationDecl;
            relationDecl = NULL;
          ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 177 "../src/parser.yy"
    {flushScanBuffer();;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 178 "../src/parser.yy"
    {
            flushScanBuffer();
            try {
              (yyvsp[(3) - (4)].RELATION)->simplify(redundant_conj_level, redundant_constr_level);
              Relation *r = relationMap[std::string((yyvsp[(1) - (4)].VAR_NAME))];
              if (r != NULL) delete r;
              relationMap[std::string((yyvsp[(1) - (4)].VAR_NAME))] = (yyvsp[(3) - (4)].RELATION);
            }
            catch (const std::exception &e) {
             std::cout << e.what() << std::endl;
            }
            delete [](yyvsp[(1) - (4)].VAR_NAME);
          ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 191 "../src/parser.yy"
    {
            flushScanBuffer();
            (yyvsp[(1) - (2)].RELATION)->simplify(redundant_conj_level, redundant_constr_level);
            (yyvsp[(1) - (2)].RELATION)->print_with_subs(stdout); 
            delete (yyvsp[(1) - (2)].RELATION);
          ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 197 "../src/parser.yy"
    {
            flushScanBuffer();
            try {
              if (Must_Be_Subset(copy(*(yyvsp[(1) - (4)].RELATION)), copy(*(yyvsp[(3) - (4)].RELATION))))
                std::cout << "True" << std::endl;
              else if (Might_Be_Subset(copy(*(yyvsp[(1) - (4)].RELATION)), copy(*(yyvsp[(3) - (4)].RELATION))))
                std::cout << "Possible" << std::endl;
              else
                std::cout << "False" << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[(1) - (4)].RELATION);
            delete (yyvsp[(3) - (4)].RELATION);
          ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 213 "../src/parser.yy"
    {
            flushScanBuffer();
#ifdef BUILD_CODEGEN
            try {
              CodeGen cg((yyvsp[(2) - (4)].REL_TUPLE_PAIR)->first, (yyvsp[(2) - (4)].REL_TUPLE_PAIR)->second, *(yyvsp[(3) - (4)].RELATION));
              CG_result *cgr = cg.buildAST();
              if (cgr != NULL) {
                std::string s = cgr->printString();
                std::cout << s << std::endl;
                delete cgr;
              }
              else
                std::cout << "/* empty */" << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
#else
            std::cout << "CodeGen package not built" << std::endl;
#endif
            delete (yyvsp[(3) - (4)].RELATION);
            delete (yyvsp[(2) - (4)].REL_TUPLE_PAIR);
          ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 236 "../src/parser.yy"
    {
            flushScanBuffer();
#ifdef BUILD_CODEGEN
            try {
              CodeGen cg((yyvsp[(3) - (5)].REL_TUPLE_PAIR)->first, (yyvsp[(3) - (5)].REL_TUPLE_PAIR)->second, *(yyvsp[(4) - (5)].RELATION));
              CG_result *cgr = cg.buildAST((yyvsp[(2) - (5)].INT_VALUE));
              if (cgr != NULL) {
                std::string s = cgr->printString();
                std::cout << s << std::endl;
                delete cgr;
              }
              else
                std::cout << "/* empty */" << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
#else
            std::cout << "CodeGen package not built" << std::endl;
#endif
            delete (yyvsp[(4) - (5)].RELATION);
            delete (yyvsp[(3) - (5)].REL_TUPLE_PAIR);
          ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 259 "../src/parser.yy"
    {
            flushScanBuffer();
            Dynamic_Array1<Relation> &final = *(yyvsp[(1) - (2)].RELATION_ARRAY_1D);
            bool any_sat = false;
            int i,n_nodes = reachable_info->node_names.size();
            for(i = 1; i <= n_nodes; i++)
              if(final[i].is_upper_bound_satisfiable()) {
                any_sat = true;
                std::cout << "Node " << reachable_info->node_names[i] << ": ";
                final[i].print_with_subs(stdout);
              }
            if(!any_sat)
              std::cout << "No nodes reachable.\n";
            delete (yyvsp[(1) - (2)].RELATION_ARRAY_1D);
            delete reachable_info;
          ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 278 "../src/parser.yy"
    {(yyval.RELATION) = new Relation(); *(yyval.RELATION) = Relation::Null();;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 279 "../src/parser.yy"
    {(yyval.RELATION) = (yyvsp[(2) - (2)].RELATION); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 282 "../src/parser.yy"
    {
              try {
                (yyvsp[(1) - (5)].REL_TUPLE_PAIR)->first.push_back(*(yyvsp[(3) - (5)].RELATION));
                (yyvsp[(1) - (5)].REL_TUPLE_PAIR)->second.push_back(*(yyvsp[(5) - (5)].RELATION));
              }
              catch (const std::exception &e) {
                delete (yyvsp[(1) - (5)].REL_TUPLE_PAIR);
                delete (yyvsp[(3) - (5)].RELATION);
                delete (yyvsp[(5) - (5)].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[(3) - (5)].RELATION);
              delete (yyvsp[(5) - (5)].RELATION);
              (yyval.REL_TUPLE_PAIR) = (yyvsp[(1) - (5)].REL_TUPLE_PAIR);
            ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 298 "../src/parser.yy"
    {
              try {
                (yyvsp[(1) - (3)].REL_TUPLE_PAIR)->first.push_back(Identity((yyvsp[(3) - (3)].RELATION)->n_set()));
                (yyvsp[(1) - (3)].REL_TUPLE_PAIR)->second.push_back(*(yyvsp[(3) - (3)].RELATION));
              }
              catch (const std::exception &e) {
                delete (yyvsp[(1) - (3)].REL_TUPLE_PAIR);
                delete (yyvsp[(3) - (3)].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[(3) - (3)].RELATION);
              (yyval.REL_TUPLE_PAIR) = (yyvsp[(1) - (3)].REL_TUPLE_PAIR);
            ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 312 "../src/parser.yy"
    {
              std::pair<std::vector<Relation>, std::vector<Relation> > *rtp = new std::pair<std::vector<Relation>, std::vector<Relation> >();
              try {
                rtp->first.push_back(*(yyvsp[(1) - (3)].RELATION));
                rtp->second.push_back(*(yyvsp[(3) - (3)].RELATION));
              }
              catch (const std::exception &e) {
                delete rtp;
                delete (yyvsp[(1) - (3)].RELATION);
                delete (yyvsp[(3) - (3)].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[(1) - (3)].RELATION);
              delete (yyvsp[(3) - (3)].RELATION);
              (yyval.REL_TUPLE_PAIR) = rtp;
            ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 329 "../src/parser.yy"
    {
              std::pair<std::vector<Relation>, std::vector<Relation> > *rtp = new std::pair<std::vector<Relation>, std::vector<Relation> >();
              try {
                rtp->first.push_back(Identity((yyvsp[(1) - (1)].RELATION)->n_set()));
                rtp->second.push_back(*(yyvsp[(1) - (1)].RELATION));
              }
              catch (const std::exception &e) {
                delete rtp;
                delete (yyvsp[(1) - (1)].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[(1) - (1)].RELATION);
              (yyval.REL_TUPLE_PAIR) = rtp;
            ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 346 "../src/parser.yy"
    {need_coef = true; relationDecl = new Declaration_Site();;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 347 "../src/parser.yy"
    {
           need_coef = false;
           (yyval.RELATION) = (yyvsp[(3) - (4)].RELATION); 
           current_Declaration_Site = globalDecls;
           delete relationDecl;
           relationDecl = NULL;
         ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 354 "../src/parser.yy"
    {
           Relation *r = relationMap[std::string((yyvsp[(1) - (1)].VAR_NAME))];
           if (r == NULL) {
             yyerror(std::string("relation ") + to_string((yyvsp[(1) - (1)].VAR_NAME)) + std::string(" not declared"));
             delete [](yyvsp[(1) - (1)].VAR_NAME);
             YYERROR;
           }
           (yyval.RELATION) = new Relation(*r);
           delete [](yyvsp[(1) - (1)].VAR_NAME);
         ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 364 "../src/parser.yy"
    {(yyval.RELATION) = (yyvsp[(2) - (3)].RELATION);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 365 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = TransitiveClosure(*(yyvsp[(1) - (2)].RELATION), 1, Relation::Null());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (2)].RELATION);
         ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 378 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             int vars = (yyvsp[(1) - (2)].RELATION)->n_inp();
             *(yyval.RELATION) = Union(Identity(vars), TransitiveClosure(*(yyvsp[(1) - (2)].RELATION), 1, Relation::Null()));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[(1) - (2)].RELATION);
         ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 392 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION)= TransitiveClosure(*(yyvsp[(1) - (4)].RELATION), 1, *(yyvsp[(4) - (4)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (4)].RELATION);
             delete (yyvsp[(4) - (4)].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[(1) - (4)].RELATION);
           delete (yyvsp[(4) - (4)].RELATION);
         ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 407 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ApproxClosure(*(yyvsp[(1) - (3)].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
         ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 420 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = calculateTransitiveClosure(*(yyvsp[(1) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
         ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 433 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[(2) - (2)].RELATION));
             Relation r(*(yyvsp[(2) - (2)].RELATION));
             r = Join(r,LexForward((yyvsp[(2) - (2)].RELATION)->n_out()));
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 449 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[(2) - (2)].RELATION));
             Relation r(*(yyvsp[(2) - (2)].RELATION));
             r = Join(r,Inverse(LexForward((yyvsp[(2) - (2)].RELATION)->n_out())));
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 465 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[(2) - (2)].RELATION));
             Relation r(*(yyvsp[(2) - (2)].RELATION));
             r = Join(LexForward((yyvsp[(2) - (2)].RELATION)->n_inp()),r);
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 481 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[(2) - (2)].RELATION));
             Relation r(*(yyvsp[(2) - (2)].RELATION));
             r = Join(Inverse(LexForward((yyvsp[(2) - (2)].RELATION)->n_inp())),r);
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 497 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation c(*(yyvsp[(2) - (2)].RELATION));
             Relation r(*(yyvsp[(2) - (2)].RELATION));
             *(yyval.RELATION) = Cross_Product(Relation(*(yyvsp[(2) - (2)].RELATION)),c);
             *(yyval.RELATION) = Difference(r,Domain(Intersection(*(yyval.RELATION),LexForward((yyval.RELATION)->n_inp()))));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 513 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation c(*(yyvsp[(2) - (2)].RELATION));
             Relation r(*(yyvsp[(2) - (2)].RELATION));
             *(yyval.RELATION) = Cross_Product(Relation(*(yyvsp[(2) - (2)].RELATION)),c);
             *(yyval.RELATION) = Difference(r,Range(Intersection(*(yyval.RELATION),LexForward((yyval.RELATION)->n_inp()))));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);       
         ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 529 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[(2) - (2)].RELATION), Basic_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 542 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[(2) - (2)].RELATION), Decoupled_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 555 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConicClosure(*(yyvsp[(1) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }             
           delete (yyvsp[(1) - (2)].RELATION);
         ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 568 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Project_Sym(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 581 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Project_On_Sym(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 594 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Deltas(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 607 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = DeltasToRelation(*(yyvsp[(2) - (2)].RELATION),(yyvsp[(2) - (2)].RELATION)->n_set(),(yyvsp[(2) - (2)].RELATION)->n_set());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 620 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Domain(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 633 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = VennDiagramForm(*(yyvsp[(2) - (2)].RELATION),Relation::True(*(yyvsp[(2) - (2)].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 646 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = VennDiagramForm(*(yyvsp[(2) - (4)].RELATION),*(yyvsp[(4) - (4)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (4)].RELATION);
             delete (yyvsp[(4) - (4)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (4)].RELATION);
           delete (yyvsp[(4) - (4)].RELATION);
         ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 661 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConvexHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 674 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = DecoupledConvexHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 687 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[(2) - (2)].RELATION),Positive_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 700 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[(2) - (2)].RELATION),Linear_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 713 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[(2) - (2)].RELATION),Affine_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 726 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[(2) - (2)].RELATION),Convex_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 739 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = CheckForConvexRepresentation(CheckForConvexPairs(*(yyvsp[(2) - (2)].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 752 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = CheckForConvexRepresentation(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 765 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConvexRepresentation(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 778 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = AffineHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 791 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConicHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 804 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = LinearHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 817 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = QuickHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 830 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = RectHull(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 843 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = SimpleHull(*(yyvsp[(2) - (2)].RELATION), true, true);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 856 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Hull(*(yyvsp[(2) - (2)].RELATION),true,1,Relation::Null());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 869 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Hull(*(yyvsp[(2) - (4)].RELATION),true,1,*(yyvsp[(4) - (4)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (4)].RELATION);
             delete (yyvsp[(4) - (4)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (4)].RELATION);
           delete (yyvsp[(4) - (4)].RELATION);
         ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 884 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Approximate(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 897 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Range(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 910 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Inverse(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 923 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Complement(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 936 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Gist(*(yyvsp[(2) - (4)].RELATION),*(yyvsp[(4) - (4)].RELATION),1);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (4)].RELATION);
             delete (yyvsp[(4) - (4)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (4)].RELATION);
           delete (yyvsp[(4) - (4)].RELATION);
         ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 951 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[(1) - (4)].RELATION),*(yyvsp[(3) - (4)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (4)].RELATION);
             delete (yyvsp[(3) - (4)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (4)].RELATION);
           delete (yyvsp[(3) - (4)].RELATION);
         ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 966 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 981 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = After(*(yyvsp[(1) - (3)].RELATION),(yyvsp[(3) - (3)].INT_VALUE),(yyvsp[(3) - (3)].INT_VALUE));
             (*(yyval.RELATION)).prefix_print(stdout);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
         ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 995 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[(3) - (3)].RELATION),*(yyvsp[(1) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1010 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Restrict_Range(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1025 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Restrict_Domain(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1040 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Intersection(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1055 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Difference(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1070 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Union(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1085 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Cross_Product(*(yyvsp[(1) - (3)].RELATION),*(yyvsp[(3) - (3)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(1) - (3)].RELATION);
             delete (yyvsp[(3) - (3)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(1) - (3)].RELATION);
           delete (yyvsp[(3) - (3)].RELATION);
         ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1100 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Union(*(yyvsp[(2) - (2)].RELATION), Relation::Unknown(*(yyvsp[(2) - (2)].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1113 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Intersection(*(yyvsp[(2) - (2)].RELATION), Relation::Unknown(*(yyvsp[(2) - (2)].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1126 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Upper_Bound(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1139 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Lower_Bound(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1152 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Sample_Solution(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1165 "../src/parser.yy"
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Symbolic_Solution(*(yyvsp[(2) - (2)].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[(2) - (2)].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1178 "../src/parser.yy"
    { (yyval.RELATION) = (yyvsp[(1) - (1)].RELATION); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1179 "../src/parser.yy"
    {
           if (((yyvsp[(2) - (2)].RELATION))->is_satisfiable()) {
             fprintf(stderr,"assert_unsatisfiable failed on ");
             ((yyvsp[(2) - (2)].RELATION))->print_with_subs(stderr);
             exit(1);
           }
           (yyval.RELATION)=(yyvsp[(2) - (2)].RELATION);
         ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1189 "../src/parser.yy"
    {currentTuple = Output_Tuple;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1190 "../src/parser.yy"
    {currentTuple = Input_Tuple;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1190 "../src/parser.yy"
    {
                 Relation * r = new Relation((yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->size,(yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->size);
                 resetGlobals();
                 F_And *f = r->add_and();
                 for(int i = 1; i <= (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->size; i++) {
                   (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->vars[i-1]->vid = r->input_var(i);
                   if (!(yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->vars[i-1]->anonymous) 
                     r->name_input_var(i, (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->vars[i-1]->stripped_name);
                 }
                 for(int i = 1; i <= (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->size; i++) {
                   (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->vars[i-1]->vid = r->output_var(i);
                   if (!(yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->vars[i-1]->anonymous) 
                     r->name_output_var(i, (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->vars[i-1]->stripped_name);
                 }
                 r->setup_names();
                 for (std::set<Exp *>::iterator i = (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->eq_constraints.begin(); i != (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->eq_constraints.end(); i++)
                   install_eq(f, *i, 0);
                 for (std::set<Exp *>::iterator i = (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->geq_constraints.begin(); i != (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->geq_constraints.end(); i++)
                   install_geq(f, *i, 0);
                 for (std::set<strideConstraint *>::iterator i = (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->stride_constraints.begin(); i != (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR)->stride_constraints.end(); i++)
                   install_stride(f, *i);
                 for (std::set<Exp *>::iterator i = (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->eq_constraints.begin(); i != (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->eq_constraints.end(); i++)
                   install_eq(f, *i, 0);
                 for (std::set<Exp *>::iterator i = (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->geq_constraints.begin(); i != (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->geq_constraints.end(); i++)
                   install_geq(f, *i, 0);
                 for (std::set<strideConstraint *>::iterator i = (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->stride_constraints.begin(); i != (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR)->stride_constraints.end(); i++)
                   install_stride(f, *i);
                 if ((yyvsp[(6) - (6)].ASTP)) (yyvsp[(6) - (6)].ASTP)->install(f);
                 delete (yyvsp[(1) - (6)].TUPLE_DESCRIPTOR);
                 delete (yyvsp[(4) - (6)].TUPLE_DESCRIPTOR);
                 delete (yyvsp[(6) - (6)].ASTP);
                 (yyval.RELATION) = r;
               ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1223 "../src/parser.yy"
    {
                 Relation * r = new Relation((yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->size);
                 resetGlobals();
                 F_And *f = r->add_and();
                 for(int i = 1; i <= (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->size; i++) {
                   (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->vars[i-1]->vid = r->set_var(i);
                   if (!(yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->vars[i-1]->anonymous) 
                     r->name_set_var(i, (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->vars[i-1]->stripped_name);
                 }
                 r->setup_names();
                 for (std::set<Exp *>::iterator i = (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->eq_constraints.begin(); i != (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->eq_constraints.end(); i++)
                   install_eq(f, *i, 0);
                 for (std::set<Exp *>::iterator i = (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->geq_constraints.begin(); i != (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->geq_constraints.end(); i++)
                   install_geq(f, *i, 0);
                 for (std::set<strideConstraint *>::iterator i = (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->stride_constraints.begin(); i != (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR)->stride_constraints.end(); i++)
                   install_stride(f, *i);
                 if ((yyvsp[(2) - (2)].ASTP)) (yyvsp[(2) - (2)].ASTP)->install(f);
                 delete (yyvsp[(1) - (2)].TUPLE_DESCRIPTOR);
                 delete (yyvsp[(2) - (2)].ASTP);
                 (yyval.RELATION) = r;
               ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1244 "../src/parser.yy"
    {
                 Relation * r = new Relation(0,0);
                 F_And *f = r->add_and();
                 (yyvsp[(1) - (1)].ASTP)->install(f);
                 delete (yyvsp[(1) - (1)].ASTP);
                 (yyval.RELATION) = r;
               ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1253 "../src/parser.yy"
    {(yyval.ASTP) = (yyvsp[(2) - (2)].ASTP);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1254 "../src/parser.yy"
    {(yyval.ASTP) = 0;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1262 "../src/parser.yy"
    {currentTupleDescriptor = new tupleDescriptor; tuplePos = 1;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1264 "../src/parser.yy"
    {(yyval.TUPLE_DESCRIPTOR) = currentTupleDescriptor; tuplePos = 0;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1272 "../src/parser.yy"
    {
           Declaration_Site *ds = defined((yyvsp[(1) - (1)].VAR_NAME));
           if (!ds)
             currentTupleDescriptor->extend((yyvsp[(1) - (1)].VAR_NAME),currentTuple,tuplePos);
           else {
             Variable_Ref *v = lookupScalar((yyvsp[(1) - (1)].VAR_NAME));
             if (v == NULL) {
               yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[(1) - (1)].VAR_NAME)));
               delete [](yyvsp[(1) - (1)].VAR_NAME);
               YYERROR;
             }
             if (ds != globalDecls)
               currentTupleDescriptor->extend((yyvsp[(1) - (1)].VAR_NAME), new Exp(v));
             else
               currentTupleDescriptor->extend(new Exp(v));
           }
           tuplePos++;
           delete [](yyvsp[(1) - (1)].VAR_NAME);
         ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1291 "../src/parser.yy"
    {currentTupleDescriptor->extend(); tuplePos++;;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1292 "../src/parser.yy"
    {
             currentTupleDescriptor->extend((yyvsp[(1) - (1)].EXP));
             tuplePos++;
         ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1296 "../src/parser.yy"
    {
             currentTupleDescriptor->extend((yyvsp[(1) - (3)].EXP),(yyvsp[(3) - (3)].EXP));
             tuplePos++;
         ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1300 "../src/parser.yy"
    {
             currentTupleDescriptor->extend((yyvsp[(1) - (5)].EXP),(yyvsp[(3) - (5)].EXP),(yyvsp[(5) - (5)].COEF_VALUE));
             tuplePos++;
         ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1306 "../src/parser.yy"
    {(yyval.VAR_LIST) = (yyvsp[(1) - (3)].VAR_LIST); (yyval.VAR_LIST)->insert((yyvsp[(3) - (3)].VAR_NAME)); (yyvsp[(3) - (3)].VAR_NAME) = NULL;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1307 "../src/parser.yy"
    {(yyval.VAR_LIST) = new std::set<char *>(); (yyval.VAR_LIST)->insert((yyvsp[(1) - (1)].VAR_NAME)); (yyvsp[(1) - (1)].VAR_NAME) = NULL;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1310 "../src/parser.yy"
    {
          (yyval.DECLARATION_SITE) = current_Declaration_Site = new Declaration_Site((yyvsp[(1) - (1)].VAR_LIST));
          for (std::set<char *>::iterator i = (yyvsp[(1) - (1)].VAR_LIST)->begin(); i != (yyvsp[(1) - (1)].VAR_LIST)->end(); i++)
            delete [](*i);
          delete (yyvsp[(1) - (1)].VAR_LIST);
        ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1318 "../src/parser.yy"
    {(yyval.DECLARATION_SITE) = (yyvsp[(1) - (1)].DECLARATION_SITE);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1319 "../src/parser.yy"
    {(yyval.DECLARATION_SITE) = (yyvsp[(2) - (3)].DECLARATION_SITE);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1326 "../src/parser.yy"
    {globalDecls->extend_both_tuples((yyvsp[(1) - (4)].VAR_NAME), (yyvsp[(3) - (4)].INT_VALUE)); delete [](yyvsp[(1) - (4)].VAR_NAME);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1327 "../src/parser.yy"
    {
          globalDecls->extend((yyvsp[(1) - (1)].VAR_NAME));
          delete [](yyvsp[(1) - (1)].VAR_NAME);
        ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1333 "../src/parser.yy"
    {(yyval.ASTP) = new AST_And((yyvsp[(1) - (3)].ASTP),(yyvsp[(3) - (3)].ASTP));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1334 "../src/parser.yy"
    {(yyval.ASTP) = new AST_Or((yyvsp[(1) - (3)].ASTP),(yyvsp[(3) - (3)].ASTP));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1335 "../src/parser.yy"
    {(yyval.ASTP) = (yyvsp[(1) - (1)].ASTCP);;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1336 "../src/parser.yy"
    {(yyval.ASTP) = (yyvsp[(2) - (3)].ASTP);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1337 "../src/parser.yy"
    {(yyval.ASTP) = new AST_Not((yyvsp[(2) - (2)].ASTP));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1338 "../src/parser.yy"
    {(yyval.ASTP) = new AST_exists((yyvsp[(2) - (5)].DECLARATION_SITE),(yyvsp[(4) - (5)].ASTP));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1339 "../src/parser.yy"
    {(yyval.ASTP) = new AST_forall((yyvsp[(2) - (5)].DECLARATION_SITE),(yyvsp[(4) - (5)].ASTP));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1358 "../src/parser.yy"
    {popScope();;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1361 "../src/parser.yy"
    {(yyval.EXP_LIST) = (yyvsp[(3) - (3)].EXP_LIST); (yyval.EXP_LIST)->insert((yyvsp[(1) - (3)].EXP));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1362 "../src/parser.yy"
    {(yyval.EXP_LIST) = new std::set<Exp *>(); (yyval.EXP_LIST)->insert((yyvsp[(1) - (1)].EXP));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1365 "../src/parser.yy"
    {(yyval.ASTCP) = new AST_constraints((yyvsp[(1) - (3)].EXP_LIST),(yyvsp[(2) - (3)].REL_OPERATOR),(yyvsp[(3) - (3)].EXP_LIST));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1366 "../src/parser.yy"
    {(yyval.ASTCP) = new AST_constraints((yyvsp[(1) - (3)].EXP_LIST),(yyvsp[(2) - (3)].REL_OPERATOR),(yyvsp[(3) - (3)].ASTCP));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1369 "../src/parser.yy"
    {
            Variable_Ref *v = lookupScalar((yyvsp[(1) - (1)].VAR_NAME));
            if (v == NULL) {
              yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[(1) - (1)].VAR_NAME)));
              delete [](yyvsp[(1) - (1)].VAR_NAME);
              YYERROR;
            }
            (yyval.EXP) = new Exp(v);
            delete [](yyvsp[(1) - (1)].VAR_NAME);
          ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1379 "../src/parser.yy"
    {argCount = 1;;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1379 "../src/parser.yy"
    {
            Variable_Ref *v;
            if ((yyvsp[(4) - (5)].ARGUMENT_TUPLE) == Input_Tuple)
              v = functionOfInput[(yyvsp[(1) - (5)].VAR_NAME)];
            else
              v = functionOfOutput[(yyvsp[(1) - (5)].VAR_NAME)];
            if (v == NULL) {
              yyerror(std::string("Function ") + to_string((yyvsp[(1) - (5)].VAR_NAME)) + std::string(" not declared"));
              delete [](yyvsp[(1) - (5)].VAR_NAME);
              YYERROR;
            }
            (yyval.EXP) = new Exp(v);
            delete [](yyvsp[(1) - (5)].VAR_NAME);
          ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1393 "../src/parser.yy"
    { (yyval.EXP) = (yyvsp[(2) - (3)].EXP); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1396 "../src/parser.yy"
    {
               Variable_Ref *v = lookupScalar((yyvsp[(3) - (3)].VAR_NAME));
               if (v == NULL) {
                 yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[(1) - (3)].ARGUMENT_TUPLE)));
                 delete [](yyvsp[(3) - (3)].VAR_NAME);
                 YYERROR;
               }
               if (v->pos != argCount || v->of != (yyvsp[(1) - (3)].ARGUMENT_TUPLE) || (v->of != Input_Tuple && v->of != Output_Tuple)) {
                 yyerror("arguments to function must be prefix of input or output tuple");
                 delete [](yyvsp[(3) - (3)].VAR_NAME);
                 YYERROR;
               }
               (yyval.ARGUMENT_TUPLE) = v->of;
               argCount++;
               delete [](yyvsp[(3) - (3)].VAR_NAME);
             ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1412 "../src/parser.yy"
    {
               Variable_Ref *v = lookupScalar((yyvsp[(1) - (1)].VAR_NAME));
               if (v == NULL) {
                 yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[(1) - (1)].VAR_NAME)));
                 delete [](yyvsp[(1) - (1)].VAR_NAME);
                 YYERROR;
               }
               if (v->pos != argCount || (v->of != Input_Tuple && v->of != Output_Tuple)) {
                 yyerror("arguments to function must be prefix of input or output tuple");
                 delete [](yyvsp[(1) - (1)].VAR_NAME);
                 YYERROR;
               }
               (yyval.ARGUMENT_TUPLE) = v->of;
               argCount++;
               delete [](yyvsp[(1) - (1)].VAR_NAME);
             ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1430 "../src/parser.yy"
    {(yyval.EXP) = new Exp((yyvsp[(1) - (1)].COEF_VALUE));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1431 "../src/parser.yy"
    {(yyval.EXP) = multiply((yyvsp[(1) - (2)].COEF_VALUE),(yyvsp[(2) - (2)].EXP));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1432 "../src/parser.yy"
    {(yyval.EXP) = (yyvsp[(1) - (1)].EXP); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1433 "../src/parser.yy"
    {(yyval.EXP) = negate((yyvsp[(2) - (2)].EXP));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1434 "../src/parser.yy"
    {(yyval.EXP) = add((yyvsp[(1) - (3)].EXP),(yyvsp[(3) - (3)].EXP));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1435 "../src/parser.yy"
    {(yyval.EXP) = subtract((yyvsp[(1) - (3)].EXP),(yyvsp[(3) - (3)].EXP));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1436 "../src/parser.yy"
    {
      try {
        (yyval.EXP) = multiply((yyvsp[(1) - (3)].EXP),(yyvsp[(3) - (3)].EXP));
      }
      catch (const std::exception &e) {
        yyerror(e.what());
        YYERROR;
      }
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1448 "../src/parser.yy"
    {
            Dynamic_Array1<Relation> *final = Reachable_Nodes(reachable_info);
            (yyval.RELATION_ARRAY_1D) = final;
          ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1454 "../src/parser.yy"
    {
               Dynamic_Array1<Relation> *final = Reachable_Nodes(reachable_info);
               int index = reachable_info->node_names.index(std::string((yyvsp[(2) - (5)].VAR_NAME)));
               if (index == 0) {
                 yyerror(std::string("no such node ") + to_string((yyvsp[(2) - (5)].VAR_NAME)));
                 delete [](yyvsp[(2) - (5)].VAR_NAME);
                 delete final;
                 delete reachable_info;
                 YYERROR;
               }
               (yyval.RELATION) = new Relation; 
               *(yyval.RELATION) = (*final)[index];
               delete final;
               delete reachable_info;
               delete [](yyvsp[(2) - (5)].VAR_NAME);
             ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1472 "../src/parser.yy"
    {
               int sz = reachable_info->node_names.size();
               reachable_info->node_arity.reallocate(sz);
               reachable_info->transitions.resize(sz+1,sz+1);
               reachable_info->start_nodes.resize(sz+1);
             ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1480 "../src/parser.yy"
    {
                   reachable_info->node_names.append(std::string((yyvsp[(3) - (3)].VAR_NAME)));
                   delete [](yyvsp[(3) - (3)].VAR_NAME);
                 ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1484 "../src/parser.yy"
    {
                   reachable_info = new reachable_information;
                   reachable_info->node_names.append(std::string((yyvsp[(1) - (1)].VAR_NAME)));
                   delete [](yyvsp[(1) - (1)].VAR_NAME);
                 ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1492 "../src/parser.yy"
    {  
                        int i,j;
                        int n_nodes = reachable_info->node_names.size();
                        Tuple<int> &arity = reachable_info->node_arity;
                        Dynamic_Array2<Relation> &transitions = reachable_info->transitions;

                        /* fixup unspecified transitions to be false */
                        /* find arity */
                        for(i = 1; i <= n_nodes; i++) arity[i] = -1;
                        for(i = 1; i <= n_nodes; i++)
                          for(j = 1; j <= n_nodes; j++)
                            if(! transitions[i][j].is_null()) {
                              int in_arity = transitions[i][j].n_inp();
                              int out_arity = transitions[i][j].n_out();
                              if(arity[i] < 0) arity[i] = in_arity;
                              if(arity[j] < 0) arity[j] = out_arity;
                              if(in_arity != arity[i] || out_arity != arity[j]) {
                                yyerror(std::string("arity mismatch in node transition: ") + to_string(reachable_info->node_names[i]) + std::string(" -> ") + to_string(reachable_info->node_names[j]));
                                delete reachable_info;
                                YYERROR;
                              }
                            }
                        for(i = 1; i <= n_nodes; i++) 
                          if(arity[i] < 0) arity[i] = 0;
                        /* Fill in false relations */
                        for(i = 1; i <= n_nodes; i++)
                          for(j = 1; j <= n_nodes; j++)
                            if(transitions[i][j].is_null())
                              transitions[i][j] = Relation::False(arity[i],arity[j]);

                        /* fixup unused start node positions */
                        Dynamic_Array1<Relation> &nodes = reachable_info->start_nodes;
                        for(i = 1; i <= n_nodes; i++) 
                          if(nodes[i].is_null()) 
                            nodes[i] = Relation::False(arity[i]);
                          else
                            if(nodes[i].n_set() != arity[i]){
                              yyerror(std::string("arity mismatch in start node ") + to_string(reachable_info->node_names[i]));
                              delete reachable_info;
                              YYERROR;
                            }
                   ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1536 "../src/parser.yy"
    {
                            int n_nodes = reachable_info->node_names.size();
                            int index = reachable_info->node_names.index((yyvsp[(3) - (5)].VAR_NAME));
                            if (!(index > 0 && index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[(3) - (5)].VAR_NAME)));
                              delete (yyvsp[(5) - (5)].RELATION);
                              delete [](yyvsp[(3) - (5)].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->start_nodes[index] = *(yyvsp[(5) - (5)].RELATION);
                            delete (yyvsp[(5) - (5)].RELATION);
                            delete [](yyvsp[(3) - (5)].VAR_NAME);
                          ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1550 "../src/parser.yy"
    {
                            int n_nodes = reachable_info->node_names.size();
                            int from_index = reachable_info->node_names.index((yyvsp[(3) - (7)].VAR_NAME));
                            if (!(from_index > 0 && from_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[(3) - (7)].VAR_NAME)));
                              delete (yyvsp[(7) - (7)].RELATION);
                              delete [](yyvsp[(3) - (7)].VAR_NAME);
                              delete [](yyvsp[(5) - (7)].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            int to_index = reachable_info->node_names.index((yyvsp[(5) - (7)].VAR_NAME));
                            if (!(to_index > 0 && to_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[(5) - (7)].VAR_NAME)));
                              delete (yyvsp[(7) - (7)].RELATION);
                              delete [](yyvsp[(3) - (7)].VAR_NAME);
                              delete [](yyvsp[(5) - (7)].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->transitions[from_index][to_index] = *(yyvsp[(7) - (7)].RELATION);
                            delete (yyvsp[(7) - (7)].RELATION);
                            delete [](yyvsp[(3) - (7)].VAR_NAME);
                            delete [](yyvsp[(5) - (7)].VAR_NAME);
                          ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1575 "../src/parser.yy"
    {
                            int n_nodes = reachable_info->node_names.size();
                            int from_index = reachable_info->node_names.index((yyvsp[(1) - (5)].VAR_NAME));
                            if (!(from_index > 0 && from_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[(1) - (5)].VAR_NAME)));
                              delete (yyvsp[(5) - (5)].RELATION);
                              delete [](yyvsp[(1) - (5)].VAR_NAME);
                              delete [](yyvsp[(3) - (5)].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            int to_index = reachable_info->node_names.index((yyvsp[(3) - (5)].VAR_NAME));
                            if (!(to_index > 0 && to_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[(3) - (5)].VAR_NAME)));
                              delete (yyvsp[(5) - (5)].RELATION);
                              delete [](yyvsp[(1) - (5)].VAR_NAME);
                              delete [](yyvsp[(3) - (5)].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->transitions[from_index][to_index] = *(yyvsp[(5) - (5)].RELATION);
                            delete (yyvsp[(5) - (5)].RELATION);
                            delete [](yyvsp[(1) - (5)].VAR_NAME);
                            delete [](yyvsp[(3) - (5)].VAR_NAME);
                          ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1600 "../src/parser.yy"
    {
                            int n_nodes = reachable_info->node_names.size();
                            int index = reachable_info->node_names.index((yyvsp[(1) - (3)].VAR_NAME));
                            if (!(index > 0 && index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[(1) - (3)].VAR_NAME)));
                              delete (yyvsp[(3) - (3)].RELATION);
                              delete [](yyvsp[(1) - (3)].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->start_nodes[index] = *(yyvsp[(3) - (3)].RELATION);
                            delete (yyvsp[(3) - (3)].RELATION);
                            delete [](yyvsp[(1) - (3)].VAR_NAME);
                          ;}
    break;



/* Line 1455 of yacc.c  */
#line 4206 "parser.tab.cc"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 1616 "../src/parser.yy"


void yyerror(const std::string &s) {
  std::stringstream ss;
  if (is_interactive)
    ss << s << "\n";
  else
    ss << s << " at line " << mylexer.lineno() << "\n";
  err_msg = ss.str();
}


int main(int argc, char **argv) {
  if (argc > 2){
    fprintf(stderr, "Usage: %s [script_file]\n", argv[0]);
    exit(1);
  }

  if (argc == 2) {
    std::ifstream *ifs = new std::ifstream;
    ifs->open(argv[1], std::ifstream::in);
    if (!ifs->is_open()) {
        fprintf(stderr, "can't open input file %s\n", argv[1]);
        exit(1);
    }
    yy_buffer_state *bs = mylexer.yy_create_buffer(ifs, 8092);
    mylexer.yypush_buffer_state(bs);
  }

  is_interactive = false;
  if (argc == 1) {
#if defined __USE_POSIX  
    if (isatty((int)fileno(stdin)))
      is_interactive = true;
#elif defined  __WIN32
    if (_isatty(_fileno(stdin)))
      is_interactive = true;
#endif
  }

  if (is_interactive) {
#ifdef BUILD_CODEGEN
    std::cout << "Omega+ and CodeGen+ ";
#else
    std::cout << "Omega+ ";
#endif
    std::cout << "v2.2.3 (built on " OMEGA_BUILD_DATE ")" << std::endl;
    std::cout << "Copyright (C) 1994-2000 the Omega Project Team" << std::endl;
    std::cout << "Copyright (C) 2005-2011 Chun Chen" << std::endl;
    std::cout << PROMPT_STRING << ' ';
    std::cout.flush();
  }

  need_coef = false;  
  current_Declaration_Site = globalDecls = new Global_Declaration_Site();

  if (yyparse() != 0) {
    if (!is_interactive)
      std::cout << "syntax error at the end of the file, missing ';'" << std::endl;
    else
      std::cout << std::endl;
    delete relationDecl;
    relationDecl = NULL;
  }
  else {
    if (is_interactive)
      std::cout << std::endl;
  }

  for (std::map<std::string, Relation *>::iterator i = relationMap.begin(); i != relationMap.end(); i++)
    delete (*i).second;
  delete globalDecls;  
  
  return 0;
}

Relation LexForward(int n) {
  Relation r(n,n);
  F_Or *f = r.add_or();
  for (int i=1; i <= n; i++) {
    F_And *g = f->add_and();
    for(int j=1;j<i;j++) {
      EQ_Handle e = g->add_EQ();
      e.update_coef(r.input_var(j),-1);
      e.update_coef(r.output_var(j),1);
      e.finalize();
    }
    GEQ_Handle e = g->add_GEQ();
    e.update_coef(r.input_var(i),-1);
    e.update_coef(r.output_var(i),1);
    e.update_const(-1);
    e.finalize();
  }
  r.finalize();
  return r;
}

