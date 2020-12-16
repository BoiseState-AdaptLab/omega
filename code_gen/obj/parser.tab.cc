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
#line 15 "../src/parser/parser.yy" /* yacc.c:339  */


#include <basic/Dynamic_Array.h>
#include <basic/Iterator.h>
#include <parser/AST.h>
#include <omega/hull.h>
#include <omega/closure.h>
#include <omega/reach.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.tab.hh"
#include <parser/myflex.h>

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
namespace omega{
  Relation * relation_result = NULL; 
}
Relation * ParseRelation(std::string relationString);
std::map<std::string, Relation *> relationMap;
int argCount = 0;
int tuplePos = 0;
Argument_Tuple currentTuple = Input_Tuple;

Relation LexForward(int n);
reachable_information *reachable_info;

void yyerror(const std::string &s);
void flushScanBuffer();


#line 122 "parser.tab.cc" /* yacc.c:339  */

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
   by #include "parser.tab.hh".  */
#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "../src/parser/parser.yy" /* yacc.c:355  */

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

#line 274 "parser.tab.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 291 "parser.tab.cc" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   677

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

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
      96,   101,    88,    84,    99,    85,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   100,    98,
       2,     2,     2,     2,    89,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    86,
      87,    90,    91,    92,    93,    94,    95,    97
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   166,   166,   170,   171,   181,   182,   195,
     201,   217,   240,   263,   282,   283,   286,   302,   316,   333,
     350,   350,   359,   369,   370,   383,   397,   412,   425,   438,
     454,   470,   486,   502,   518,   534,   547,   560,   573,   586,
     599,   612,   625,   638,   651,   666,   679,   692,   705,   718,
     731,   744,   757,   770,   783,   796,   809,   822,   835,   848,
     861,   874,   889,   902,   915,   928,   941,   956,   971,   986,
    1000,  1015,  1030,  1045,  1060,  1075,  1090,  1105,  1118,  1131,
    1144,  1157,  1170,  1183,  1184,  1194,  1195,  1194,  1228,  1249,
    1258,  1259,  1262,  1263,  1264,  1267,  1267,  1272,  1273,  1274,
    1277,  1296,  1297,  1301,  1305,  1311,  1312,  1315,  1323,  1324,
    1327,  1328,  1331,  1332,  1338,  1339,  1340,  1341,  1342,  1343,
    1344,  1347,  1348,  1351,  1352,  1353,  1356,  1357,  1360,  1363,
    1366,  1367,  1370,  1371,  1374,  1384,  1384,  1398,  1401,  1417,
    1435,  1436,  1437,  1438,  1439,  1440,  1441,  1453,  1459,  1477,
    1485,  1489,  1497,  1541,  1555,  1580,  1605
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "PARSE_EXPRESSION", "PARSE_FORMULA", "PARSE_RELATION", "p1", "'+'",
  "'-'", "p2", "p3", "'*'", "'@'", "p4", "p5", "p6", "p7", "p8", "p9",
  "'('", "p10", "';'", "','", "':'", "')'", "'^'", "'['", "']'", "$accept",
  "inputSequence", "$@1", "inputItem", "context", "relPairList",
  "relation", "$@2", "builtRelation", "$@3", "$@4", "optionalFormula",
  "formula_sep", "tupleDeclaration", "$@5", "optionalTupleVarList",
  "tupleVar", "varList", "varDecl", "varDeclOptBrackets", "globVarList",
  "globVar", "formula", "start_exists", "exists_sep", "start_forall",
  "forall_sep", "end_quant", "expList", "constraintChain", "simpleExp",
  "$@6", "argumentList", "exp", "reachable", "reachable_of",
  "nodeNameList", "realNodeNameList", "nodeSpecificationList",
  "realNodeSpecificationList", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,    43,    45,   339,   340,    42,    64,
     341,   342,   343,   344,   345,   346,    40,   347,    59,    44,
      58,    41,    94,    91,    93
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -101

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,    87,  -136,   163,   -50,    73,  -136,    93,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   271,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
      12,   103,   350,   350,  -136,  -136,   399,    16,  -136,  -136,
     350,    49,    24,    80,  -136,  -136,   -25,   -25,   -25,   -25,
     -25,   378,    46,   -25,   -25,   -25,    63,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   350,    39,   162,
     -25,   -25,   -25,   -25,   572,   572,   -25,   -25,   -25,   -25,
     125,   122,    75,   551,   420,   350,   350,   136,   350,   350,
     350,   350,   350,   132,   350,   350,  -136,   350,  -136,   -11,
    -136,   441,    51,     1,    49,    65,    72,    77,    67,   167,
      30,    83,    89,    -2,    -2,   112,  -136,  -136,   184,   207,
    -136,    93,   350,   350,   350,    39,   350,   350,    90,   350,
    -136,    40,   209,  -136,    12,  -136,   -25,   -25,  -136,   572,
     227,   475,   575,   575,   350,   227,   227,   496,  -136,  -136,
    -136,  -136,    77,  -136,  -136,  -136,  -136,  -136,    65,    72,
      45,   164,  -136,  -136,  -136,  -136,  -136,  -136,    49,    48,
      49,    49,  -136,   210,   117,  -136,    32,   123,    77,    77,
      77,    77,    77,   121,  -136,   -25,   -25,   -25,   126,   551,
     517,  -136,   551,   222,  -136,     7,    28,   122,  -136,   -25,
    -136,   230,    10,  -136,  -136,  -136,    89,     6,  -136,    56,
    -136,   182,   232,  -136,   140,   242,  -136,  -136,  -136,    49,
    -136,    49,   112,  -136,   165,   165,  -136,  -136,  -136,  -136,
     350,  -136,   251,   350,  -136,   252,  -136,  -136,    68,  -136,
      48,  -136,    77,  -136,  -136,    57,    57,   551,   156,   551,
       9,   268,  -136,    43,  -136,   275,  -136,  -136,  -136,   350,
     270,   350,  -136,  -136,   272,   551,   176,   551,  -136,   350,
     551
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   139,   190,    -3,  -136,  -136,  -136,
    -136,    36,  -136,    85,  -136,  -136,    11,  -136,   118,   178,
    -136,   173,   -75,  -136,  -136,  -136,  -136,    52,  -123,   119,
     197,  -136,  -136,  -135,  -136,  -136,   168,  -136,   104,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    55,   158,    98,    99,    61,   139,   235,
     283,   197,   198,   140,   141,   239,   240,   204,   205,   206,
      63,    64,   142,   143,   249,   144,   251,   287,   145,   146,
     147,   231,   268,   148,    57,    58,   111,   161,   163,   226
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   202,   187,   191,   132,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   264,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   232,    59,   113,
     114,   237,   132,   133,   133,   200,   201,   131,   262,   184,
     290,   134,   156,   190,   241,   135,   136,   200,   201,   153,
     132,   127,   133,   178,   254,   255,   256,   129,   179,   134,
     132,   193,   133,   188,   189,   252,   154,     2,    60,   257,
     194,   195,   246,   247,   209,   210,    62,   182,   211,   200,
     201,   203,   181,   194,   195,  -100,   112,   263,   110,   291,
    -100,   234,   166,   167,   130,   169,   170,   171,   172,   173,
     149,   175,   176,   236,   177,   242,   243,   265,   160,   162,
     196,   164,   248,   137,   137,   241,   238,   285,   157,   223,
     168,   224,   127,   196,   182,   138,   233,   181,   129,   215,
     216,   217,   137,   219,   220,   270,   222,   174,   286,   127,
     271,   185,   137,   138,     4,   129,     5,   281,   186,   282,
       6,   229,     7,   182,   275,   192,   276,     8,   150,   151,
     208,     9,    10,    11,    12,    13,   199,    14,   221,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   213,   225,   202,   115,   116,   245,    37,    38,   117,
     118,   119,   258,   250,   259,   261,    39,    40,    41,    42,
      43,   121,   122,   267,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   201,   273,   274,   123,   124,   209,   210,
     125,   126,   211,   211,   278,   280,   289,   277,   127,    53,
     279,    54,   159,   212,   129,   234,   209,   210,   209,   210,
     211,   292,   211,   296,    65,    97,   299,   298,     6,   115,
     116,   284,   272,   212,   117,     8,   295,   155,   297,     9,
      10,    11,    12,    13,   218,    14,   300,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,   293,
     269,   244,   207,   127,   214,    37,    38,   253,   288,   129,
     183,   266,   227,     0,     0,    40,    41,    42,    43,     0,
       0,     0,    44,    45,    46,    47,    48,    49,     0,    51,
      52,     0,     0,    65,     0,     0,     0,     6,     0,   209,
     210,     0,     0,   211,     8,     0,     0,    53,     9,    10,
      11,    12,    13,     0,    14,   294,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,   152,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,    42,    43,     0,     0,
       0,    44,    45,    46,    47,    48,    49,     0,    51,    52,
     115,   116,     0,     0,     0,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,    53,   121,   122,     0,
       0,   115,   116,     0,     0,     0,   117,   118,   119,     0,
       0,   120,   123,   124,     0,     0,   125,   126,   121,   122,
       0,     0,   115,   116,   127,     0,     0,   117,   118,   119,
     129,     0,     0,   123,   124,     0,     0,   125,   126,   121,
     122,     0,     0,   115,   116,   127,     0,   128,   117,   118,
     119,   129,     0,     0,   123,   124,     0,     0,   125,   126,
     121,   122,     0,     0,     0,     0,   127,     0,     0,     0,
       0,   165,   129,     0,     0,   123,   124,   115,   116,   125,
     126,     0,   117,   118,   119,     0,     0,   127,     0,   180,
       0,     0,     0,   129,   121,   122,     0,     0,   115,   116,
       0,     0,     0,   117,   118,   119,     0,     0,     0,   123,
     124,     0,     0,   125,   126,   121,   122,     0,     0,   115,
     116,   127,     0,   228,   117,   118,   119,   129,     0,     0,
     123,   124,     0,     0,   125,   126,   121,   122,     0,     0,
       0,     0,   127,     0,     0,     0,     0,   230,   129,     0,
       0,   123,   124,   115,   116,   125,   126,     0,   117,   118,
     119,     0,     0,   127,     0,     0,     0,   260,     0,   129,
     121,   122,     0,     0,   115,   116,     0,   115,   116,   117,
       0,   119,   117,     0,   119,   123,   124,     0,     0,   125,
     126,   121,   122,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
     125,   126,     0,   125,   126,     0,     0,     0,   127,     0,
       0,   127,     0,     0,   129,     0,     0,   129
};

static const yytype_int16 yycheck[] =
{
       3,     3,   137,   138,     3,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     8,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   182,    98,    52,
      53,     3,     3,     5,     5,    10,    11,    60,    51,   134,
      51,    12,    23,   138,   199,    16,    17,    10,    11,    23,
       3,    96,     5,    84,   209,   210,   211,   102,    89,    12,
       3,    51,     5,    16,    17,   208,    23,     0,    15,   212,
      60,    61,    60,    61,    84,    85,     3,    96,    88,    10,
      11,   103,    96,    60,    61,    99,     3,   100,    96,   100,
     104,   101,   115,   116,    98,   118,   119,   120,   121,   122,
      96,   124,   125,   198,   127,   200,   201,    99,     3,     7,
     100,    56,   100,    85,    85,   270,    88,   272,    99,    99,
       4,   101,    96,   100,    96,    96,   101,    96,   102,   152,
     153,   154,    85,   156,   157,    99,   159,    25,   101,    96,
     104,    96,    85,    96,     1,   102,     3,    99,    96,   101,
       7,   174,     9,    96,   249,     8,   251,    14,    98,    99,
      68,    18,    19,    20,    21,    22,   103,    24,    98,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     4,     3,     3,    52,    53,    99,    54,    55,    57,
      58,    59,   101,   100,    98,     3,    63,    64,    65,    66,
      67,    69,    70,     3,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    11,   104,     3,    84,    85,    84,    85,
      88,    89,    88,    88,     3,     3,   100,   260,    96,    96,
     263,    98,   100,    99,   102,   101,    84,    85,    84,    85,
      88,     3,    88,     3,     3,     4,   100,     5,     7,    52,
      53,   270,   100,    99,    57,    14,   289,    97,   291,    18,
      19,    20,    21,    22,   155,    24,   299,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   283,
     235,   203,   144,    96,   151,    54,    55,   208,   276,   102,
     133,   227,   164,    -1,    -1,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    -1,     3,    -1,    -1,    -1,     7,    -1,    84,
      85,    -1,    -1,    88,    14,    -1,    -1,    96,    18,    19,
      20,    21,    22,    -1,    24,   100,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    23,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    69,    70,    -1,
      -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    84,    85,    -1,    -1,    88,    89,    69,    70,
      -1,    -1,    52,    53,    96,    -1,    -1,    57,    58,    59,
     102,    -1,    -1,    84,    85,    -1,    -1,    88,    89,    69,
      70,    -1,    -1,    52,    53,    96,    -1,    98,    57,    58,
      59,   102,    -1,    -1,    84,    85,    -1,    -1,    88,    89,
      69,    70,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,    84,    85,    52,    53,    88,
      89,    -1,    57,    58,    59,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,   102,    69,    70,    -1,    -1,    52,    53,
      -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,    84,
      85,    -1,    -1,    88,    89,    69,    70,    -1,    -1,    52,
      53,    96,    -1,    98,    57,    58,    59,   102,    -1,    -1,
      84,    85,    -1,    -1,    88,    89,    69,    70,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,    84,    85,    52,    53,    88,    89,    -1,    57,    58,
      59,    -1,    -1,    96,    -1,    -1,    -1,   100,    -1,   102,
      69,    70,    -1,    -1,    52,    53,    -1,    52,    53,    57,
      -1,    59,    57,    -1,    59,    84,    85,    -1,    -1,    88,
      89,    69,    70,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    88,    89,    -1,    -1,    -1,    96,    -1,
      -1,    96,    -1,    -1,   102,    -1,    -1,   102
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
      62,    69,    70,    84,    85,    88,    89,    96,    98,   102,
      98,   111,     3,     5,    12,    16,    17,    85,    96,   113,
     118,   119,   127,   128,   130,   133,   134,   135,   138,    96,
      98,    99,    23,    23,    23,   110,    23,    99,   109,   100,
       3,   142,     7,   143,    56,   101,   111,   111,     4,   111,
     111,   111,   111,   111,    25,   111,   111,   111,    84,    89,
      98,    96,    96,   135,   127,    96,    96,   138,    16,    17,
     127,   138,     8,    51,    60,    61,   100,   116,   117,   103,
      10,    11,     3,   103,   122,   123,   124,   124,    68,    84,
      85,    88,    99,     4,   126,   111,   111,   111,   109,   111,
     111,    98,   111,    99,   101,     3,   144,   141,    98,   111,
     101,   136,   138,   101,   101,   114,   127,     3,    88,   120,
     121,   138,   127,   127,   123,    99,    60,    61,   100,   129,
     100,   131,   133,   134,   138,   138,   138,   133,   101,    98,
     100,     3,    51,   100,     8,    99,   143,     3,   137,   118,
      99,   104,   100,   104,     3,   127,   127,   111,     3,   111,
       3,    99,   101,   115,   121,   138,   101,   132,   132,   100,
      51,   100,     3,   116,   100,   111,     3,   111,     5,   100,
     111
};

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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* VAR  */
#line 133 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete []((*yyvaluep).VAR_NAME);}
#line 1423 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 6: /* STRING  */
#line 134 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).STRING_VALUE);}
#line 1429 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 109: /* context  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1435 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 110: /* relPairList  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).REL_TUPLE_PAIR);}
#line 1441 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 111: /* relation  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1447 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 113: /* builtRelation  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1453 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 116: /* optionalFormula  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).ASTP);}
#line 1459 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 118: /* tupleDeclaration  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).TUPLE_DESCRIPTOR);}
#line 1465 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 122: /* varList  */
#line 142 "../src/parser/parser.yy" /* yacc.c:1257  */
      {
  for (std::set<char *>::iterator i = ((*yyvaluep).VAR_LIST)->begin(); i != ((*yyvaluep).VAR_LIST)->end(); i++)
    delete []*i;
  delete ((*yyvaluep).VAR_LIST);
 }
#line 1475 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 123: /* varDecl  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).DECLARATION_SITE);}
#line 1481 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 124: /* varDeclOptBrackets  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).DECLARATION_SITE);}
#line 1487 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 127: /* formula  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).ASTP);}
#line 1493 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 133: /* expList  */
#line 137 "../src/parser/parser.yy" /* yacc.c:1257  */
      {
  for (std::set<Exp *>::iterator i = ((*yyvaluep).EXP_LIST)->begin(); i != ((*yyvaluep).EXP_LIST)->end(); i++)
    delete *i;
  delete ((*yyvaluep).EXP_LIST);
 }
#line 1503 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 134: /* constraintChain  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).ASTCP);}
#line 1509 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 135: /* simpleExp  */
#line 136 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).EXP);}
#line 1515 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 138: /* exp  */
#line 136 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).EXP);}
#line 1521 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 139: /* reachable  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION_ARRAY_1D);}
#line 1527 "parser.tab.cc" /* yacc.c:1257  */
        break;

    case 140: /* reachable_of  */
#line 135 "../src/parser/parser.yy" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1533 "parser.tab.cc" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 166 "../src/parser/parser.yy" /* yacc.c:1646  */
    { assert( current_Declaration_Site == globalDecls);}
#line 1797 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 171 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
            std::cout << err_msg;
            err_msg.clear();
            current_Declaration_Site = globalDecls;
            need_coef = false;
            std::cout << "...skipping to statement end..." << std::endl;
            delete relationDecl;
            relationDecl = NULL;
          }
#line 1812 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 181 "../src/parser/parser.yy" /* yacc.c:1646  */
    {flushScanBuffer();}
#line 1818 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 182 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              (yyvsp[-1].RELATION)->simplify(redundant_conj_level, redundant_constr_level);
              Relation *r = relationMap[std::string((yyvsp[-3].VAR_NAME))];
              if (r != NULL) delete r;
              relationMap[std::string((yyvsp[-3].VAR_NAME))] = (yyvsp[-1].RELATION);
            }
            catch (const std::exception &e) {
             std::cout << e.what() << std::endl;
            }
            delete [](yyvsp[-3].VAR_NAME);
          }
#line 1836 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 195 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
            (yyvsp[-1].RELATION)->simplify(redundant_conj_level, redundant_constr_level);
            (yyvsp[-1].RELATION)->print_with_subs(stdout); 
            delete (yyvsp[-1].RELATION);
          }
#line 1847 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 201 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              if (Must_Be_Subset(copy(*(yyvsp[-3].RELATION)), copy(*(yyvsp[-1].RELATION))))
                std::cout << "True" << std::endl;
              else if (Might_Be_Subset(copy(*(yyvsp[-3].RELATION)), copy(*(yyvsp[-1].RELATION))))
                std::cout << "Possible" << std::endl;
              else
                std::cout << "False" << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[-3].RELATION);
            delete (yyvsp[-1].RELATION);
          }
#line 1868 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 217 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
#ifdef BUILD_CODEGEN
            try {
              CodeGen cg((yyvsp[-2].REL_TUPLE_PAIR)->first, (yyvsp[-2].REL_TUPLE_PAIR)->second, *(yyvsp[-1].RELATION));
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
            delete (yyvsp[-1].RELATION);
            delete (yyvsp[-2].REL_TUPLE_PAIR);
          }
#line 1896 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 240 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
#ifdef BUILD_CODEGEN
            try {
              CodeGen cg((yyvsp[-2].REL_TUPLE_PAIR)->first, (yyvsp[-2].REL_TUPLE_PAIR)->second, *(yyvsp[-1].RELATION));
              CG_result *cgr = cg.buildAST((yyvsp[-3].INT_VALUE));
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
            delete (yyvsp[-1].RELATION);
            delete (yyvsp[-2].REL_TUPLE_PAIR);
          }
#line 1924 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 263 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            flushScanBuffer();
            Dynamic_Array1<Relation> &final = *(yyvsp[-1].RELATION_ARRAY_1D);
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
            delete (yyvsp[-1].RELATION_ARRAY_1D);
            delete reachable_info;
          }
#line 1945 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 282 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.RELATION) = new Relation(); *(yyval.RELATION) = Relation::Null();}
#line 1951 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 283 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.RELATION) = (yyvsp[0].RELATION); }
#line 1957 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 286 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
              try {
                (yyvsp[-4].REL_TUPLE_PAIR)->first.push_back(*(yyvsp[-2].RELATION));
                (yyvsp[-4].REL_TUPLE_PAIR)->second.push_back(*(yyvsp[0].RELATION));
              }
              catch (const std::exception &e) {
                delete (yyvsp[-4].REL_TUPLE_PAIR);
                delete (yyvsp[-2].RELATION);
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[-2].RELATION);
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = (yyvsp[-4].REL_TUPLE_PAIR);
            }
#line 1978 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 302 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
              try {
                (yyvsp[-2].REL_TUPLE_PAIR)->first.push_back(Identity((yyvsp[0].RELATION)->n_set()));
                (yyvsp[-2].REL_TUPLE_PAIR)->second.push_back(*(yyvsp[0].RELATION));
              }
              catch (const std::exception &e) {
                delete (yyvsp[-2].REL_TUPLE_PAIR);
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = (yyvsp[-2].REL_TUPLE_PAIR);
            }
#line 1997 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 316 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
              std::pair<std::vector<Relation>, std::vector<Relation> > *rtp = new std::pair<std::vector<Relation>, std::vector<Relation> >();
              try {
                rtp->first.push_back(*(yyvsp[-2].RELATION));
                rtp->second.push_back(*(yyvsp[0].RELATION));
              }
              catch (const std::exception &e) {
                delete rtp;
                delete (yyvsp[-2].RELATION);
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[-2].RELATION);
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = rtp;
            }
#line 2019 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 333 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
              std::pair<std::vector<Relation>, std::vector<Relation> > *rtp = new std::pair<std::vector<Relation>, std::vector<Relation> >();
              try {
                rtp->first.push_back(Identity((yyvsp[0].RELATION)->n_set()));
                rtp->second.push_back(*(yyvsp[0].RELATION));
              }
              catch (const std::exception &e) {
                delete rtp;
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = rtp;
            }
#line 2039 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 350 "../src/parser/parser.yy" /* yacc.c:1646  */
    {need_coef = true; relationDecl = new Declaration_Site();}
#line 2045 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 351 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           need_coef = false;
           (yyval.RELATION) = (yyvsp[-1].RELATION);
	   relation_result = (yyvsp[-1].RELATION); 
           current_Declaration_Site = globalDecls;
           delete relationDecl;
           relationDecl = NULL;
         }
#line 2058 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 359 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           Relation *r = relationMap[std::string((yyvsp[0].VAR_NAME))];
           if (r == NULL) {
             yyerror(std::string("relation ") + to_string((yyvsp[0].VAR_NAME)) + std::string(" not declared"));
             delete [](yyvsp[0].VAR_NAME);
             YYERROR;
           }
           (yyval.RELATION) = new Relation(*r);
           delete [](yyvsp[0].VAR_NAME);
         }
#line 2073 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 369 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.RELATION) = (yyvsp[-1].RELATION);}
#line 2079 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 370 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = TransitiveClosure(*(yyvsp[-1].RELATION), 1, Relation::Null());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-1].RELATION);
         }
#line 2097 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 383 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             int vars = (yyvsp[-1].RELATION)->n_inp();
             *(yyval.RELATION) = Union(Identity(vars), TransitiveClosure(*(yyvsp[-1].RELATION), 1, Relation::Null()));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[-1].RELATION);
         }
#line 2116 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 397 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION)= TransitiveClosure(*(yyvsp[-3].RELATION), 1, *(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-3].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[-3].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2136 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 412 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ApproxClosure(*(yyvsp[-2].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
         }
#line 2154 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 425 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = calculateTransitiveClosure(*(yyvsp[-2].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
         }
#line 2172 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 438 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(r,LexForward((yyvsp[0].RELATION)->n_out()));
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[0].RELATION);
         }
#line 2193 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 454 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(r,Inverse(LexForward((yyvsp[0].RELATION)->n_out())));
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2214 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 470 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(LexForward((yyvsp[0].RELATION)->n_inp()),r);
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2235 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 486 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(Inverse(LexForward((yyvsp[0].RELATION)->n_inp())),r);
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2256 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 502 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation c(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             *(yyval.RELATION) = Cross_Product(Relation(*(yyvsp[0].RELATION)),c);
             *(yyval.RELATION) = Difference(r,Domain(Intersection(*(yyval.RELATION),LexForward((yyval.RELATION)->n_inp()))));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2277 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 518 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation c(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             *(yyval.RELATION) = Cross_Product(Relation(*(yyvsp[0].RELATION)),c);
             *(yyval.RELATION) = Difference(r,Range(Intersection(*(yyval.RELATION),LexForward((yyval.RELATION)->n_inp()))));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);       
         }
#line 2298 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 534 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION), Basic_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2316 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 547 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION), Decoupled_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2334 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 560 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConicClosure(*(yyvsp[-1].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }             
           delete (yyvsp[-1].RELATION);
         }
#line 2352 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 573 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Project_Sym(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2370 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 586 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Project_On_Sym(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2388 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 599 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Deltas(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2406 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 612 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = DeltasToRelation(*(yyvsp[0].RELATION),(yyvsp[0].RELATION)->n_set(),(yyvsp[0].RELATION)->n_set());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2424 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 625 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Domain(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2442 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 638 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = VennDiagramForm(*(yyvsp[0].RELATION),Relation::True(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2460 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 651 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = VennDiagramForm(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2480 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 666 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConvexHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2498 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 679 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = DecoupledConvexHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2516 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 692 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Positive_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2534 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 705 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Linear_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2552 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 718 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Affine_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2570 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 731 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Convex_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[0].RELATION);
         }
#line 2588 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 744 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = CheckForConvexRepresentation(CheckForConvexPairs(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2606 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 757 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = CheckForConvexRepresentation(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2624 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 770 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConvexRepresentation(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2642 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 783 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = AffineHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2660 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 796 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConicHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2678 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 809 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = LinearHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2696 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 822 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = QuickHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2714 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 835 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = RectHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2732 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 848 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = SimpleHull(*(yyvsp[0].RELATION), true, true);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2750 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 861 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Hull(*(yyvsp[0].RELATION),true,1,Relation::Null());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2768 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 874 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Hull(*(yyvsp[-2].RELATION),true,1,*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2788 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 889 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Approximate(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2806 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 902 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Range(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2824 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 915 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Inverse(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2842 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 928 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Complement(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2860 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 941 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Gist(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION),1);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2880 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 956 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[-3].RELATION),*(yyvsp[-1].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-3].RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-3].RELATION);
           delete (yyvsp[-1].RELATION);
         }
#line 2900 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 971 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2920 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 986 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = After(*(yyvsp[-2].RELATION),(yyvsp[0].INT_VALUE),(yyvsp[0].INT_VALUE));
             (*(yyval.RELATION)).prefix_print(stdout);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
         }
#line 2939 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 1000 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[0].RELATION),*(yyvsp[-2].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2959 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 1015 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Restrict_Range(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2979 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 1030 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Restrict_Domain(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2999 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 1045 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Intersection(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3019 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 1060 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Difference(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3039 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 1075 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Union(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3059 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 1090 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Cross_Product(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3079 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 1105 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Union(*(yyvsp[0].RELATION), Relation::Unknown(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3097 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 1118 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Intersection(*(yyvsp[0].RELATION), Relation::Unknown(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3115 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 1131 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Upper_Bound(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3133 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 1144 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Lower_Bound(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3151 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 1157 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Sample_Solution(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3169 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 1170 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Symbolic_Solution(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3187 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 1183 "../src/parser/parser.yy" /* yacc.c:1646  */
    { (yyval.RELATION) = (yyvsp[0].RELATION); }
#line 3193 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 1184 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           if (((yyvsp[0].RELATION))->is_satisfiable()) {
             fprintf(stderr,"assert_unsatisfiable failed on ");
             ((yyvsp[0].RELATION))->print_with_subs(stderr);
             exit(1);
           }
           (yyval.RELATION)=(yyvsp[0].RELATION);
         }
#line 3206 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 1194 "../src/parser/parser.yy" /* yacc.c:1646  */
    {currentTuple = Output_Tuple;}
#line 3212 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 1195 "../src/parser/parser.yy" /* yacc.c:1646  */
    {currentTuple = Input_Tuple;}
#line 3218 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 1195 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                 Relation * r = new Relation((yyvsp[-5].TUPLE_DESCRIPTOR)->size,(yyvsp[-2].TUPLE_DESCRIPTOR)->size);
                 resetGlobals();
                 F_And *f = r->add_and();
                 for(int i = 1; i <= (yyvsp[-5].TUPLE_DESCRIPTOR)->size; i++) {
                   (yyvsp[-5].TUPLE_DESCRIPTOR)->vars[i-1]->vid = r->input_var(i);
                   if (!(yyvsp[-5].TUPLE_DESCRIPTOR)->vars[i-1]->anonymous) 
                     r->name_input_var(i, (yyvsp[-5].TUPLE_DESCRIPTOR)->vars[i-1]->stripped_name);
                 }
                 for(int i = 1; i <= (yyvsp[-2].TUPLE_DESCRIPTOR)->size; i++) {
                   (yyvsp[-2].TUPLE_DESCRIPTOR)->vars[i-1]->vid = r->output_var(i);
                   if (!(yyvsp[-2].TUPLE_DESCRIPTOR)->vars[i-1]->anonymous) 
                     r->name_output_var(i, (yyvsp[-2].TUPLE_DESCRIPTOR)->vars[i-1]->stripped_name);
                 }
                 r->setup_names();
                 for (std::set<Exp *>::iterator i = (yyvsp[-5].TUPLE_DESCRIPTOR)->eq_constraints.begin(); i != (yyvsp[-5].TUPLE_DESCRIPTOR)->eq_constraints.end(); i++)
                   install_eq(f, *i, 0);
                 for (std::set<Exp *>::iterator i = (yyvsp[-5].TUPLE_DESCRIPTOR)->geq_constraints.begin(); i != (yyvsp[-5].TUPLE_DESCRIPTOR)->geq_constraints.end(); i++)
                   install_geq(f, *i, 0);
                 for (std::set<strideConstraint *>::iterator i = (yyvsp[-5].TUPLE_DESCRIPTOR)->stride_constraints.begin(); i != (yyvsp[-5].TUPLE_DESCRIPTOR)->stride_constraints.end(); i++)
                   install_stride(f, *i);
                 for (std::set<Exp *>::iterator i = (yyvsp[-2].TUPLE_DESCRIPTOR)->eq_constraints.begin(); i != (yyvsp[-2].TUPLE_DESCRIPTOR)->eq_constraints.end(); i++)
                   install_eq(f, *i, 0);
                 for (std::set<Exp *>::iterator i = (yyvsp[-2].TUPLE_DESCRIPTOR)->geq_constraints.begin(); i != (yyvsp[-2].TUPLE_DESCRIPTOR)->geq_constraints.end(); i++)
                   install_geq(f, *i, 0);
                 for (std::set<strideConstraint *>::iterator i = (yyvsp[-2].TUPLE_DESCRIPTOR)->stride_constraints.begin(); i != (yyvsp[-2].TUPLE_DESCRIPTOR)->stride_constraints.end(); i++)
                   install_stride(f, *i);
                 if ((yyvsp[0].ASTP)) (yyvsp[0].ASTP)->install(f);
                 delete (yyvsp[-5].TUPLE_DESCRIPTOR);
                 delete (yyvsp[-2].TUPLE_DESCRIPTOR);
                 delete (yyvsp[0].ASTP);
                 (yyval.RELATION) = r;
               }
#line 3256 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 1228 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                 Relation * r = new Relation((yyvsp[-1].TUPLE_DESCRIPTOR)->size);
                 resetGlobals();
                 F_And *f = r->add_and();
                 for(int i = 1; i <= (yyvsp[-1].TUPLE_DESCRIPTOR)->size; i++) {
                   (yyvsp[-1].TUPLE_DESCRIPTOR)->vars[i-1]->vid = r->set_var(i);
                   if (!(yyvsp[-1].TUPLE_DESCRIPTOR)->vars[i-1]->anonymous) 
                     r->name_set_var(i, (yyvsp[-1].TUPLE_DESCRIPTOR)->vars[i-1]->stripped_name);
                 }
                 r->setup_names();
                 for (std::set<Exp *>::iterator i = (yyvsp[-1].TUPLE_DESCRIPTOR)->eq_constraints.begin(); i != (yyvsp[-1].TUPLE_DESCRIPTOR)->eq_constraints.end(); i++)
                   install_eq(f, *i, 0);
                 for (std::set<Exp *>::iterator i = (yyvsp[-1].TUPLE_DESCRIPTOR)->geq_constraints.begin(); i != (yyvsp[-1].TUPLE_DESCRIPTOR)->geq_constraints.end(); i++)
                   install_geq(f, *i, 0);
                 for (std::set<strideConstraint *>::iterator i = (yyvsp[-1].TUPLE_DESCRIPTOR)->stride_constraints.begin(); i != (yyvsp[-1].TUPLE_DESCRIPTOR)->stride_constraints.end(); i++)
                   install_stride(f, *i);
                 if ((yyvsp[0].ASTP)) (yyvsp[0].ASTP)->install(f);
                 delete (yyvsp[-1].TUPLE_DESCRIPTOR);
                 delete (yyvsp[0].ASTP);
                 (yyval.RELATION) = r;
               }
#line 3282 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 1249 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                 Relation * r = new Relation(0,0);
                 F_And *f = r->add_and();
                 (yyvsp[0].ASTP)->install(f);
                 delete (yyvsp[0].ASTP);
                 (yyval.RELATION) = r;
               }
#line 3294 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 1258 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = (yyvsp[0].ASTP);}
#line 3300 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 1259 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = 0;}
#line 3306 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 1267 "../src/parser/parser.yy" /* yacc.c:1646  */
    {currentTupleDescriptor = new tupleDescriptor; tuplePos = 1;}
#line 3312 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 1269 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.TUPLE_DESCRIPTOR) = currentTupleDescriptor; tuplePos = 0;}
#line 3318 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 1277 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
           Declaration_Site *ds = defined((yyvsp[0].VAR_NAME));
           if (!ds)
             currentTupleDescriptor->extend((yyvsp[0].VAR_NAME),currentTuple,tuplePos);
           else {
             Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
             if (v == NULL) {
               yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[0].VAR_NAME)));
               delete [](yyvsp[0].VAR_NAME);
               YYERROR;
             }
             if (ds != globalDecls)
               currentTupleDescriptor->extend((yyvsp[0].VAR_NAME), new Exp(v));
             else
               currentTupleDescriptor->extend(new Exp(v));
           }
           tuplePos++;
           delete [](yyvsp[0].VAR_NAME);
         }
#line 3342 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 1296 "../src/parser/parser.yy" /* yacc.c:1646  */
    {currentTupleDescriptor->extend(); tuplePos++;}
#line 3348 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 1297 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
             currentTupleDescriptor->extend((yyvsp[0].EXP));
             tuplePos++;
         }
#line 3357 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 1301 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
             currentTupleDescriptor->extend((yyvsp[-2].EXP),(yyvsp[0].EXP));
             tuplePos++;
         }
#line 3366 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 1305 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
             currentTupleDescriptor->extend((yyvsp[-4].EXP),(yyvsp[-2].EXP),(yyvsp[0].COEF_VALUE));
             tuplePos++;
         }
#line 3375 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 1311 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.VAR_LIST) = (yyvsp[-2].VAR_LIST); (yyval.VAR_LIST)->insert((yyvsp[0].VAR_NAME)); (yyvsp[0].VAR_NAME) = NULL;}
#line 3381 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 1312 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.VAR_LIST) = new std::set<char *>(); (yyval.VAR_LIST)->insert((yyvsp[0].VAR_NAME)); (yyvsp[0].VAR_NAME) = NULL;}
#line 3387 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 1315 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
          (yyval.DECLARATION_SITE) = current_Declaration_Site = new Declaration_Site((yyvsp[0].VAR_LIST));
          for (std::set<char *>::iterator i = (yyvsp[0].VAR_LIST)->begin(); i != (yyvsp[0].VAR_LIST)->end(); i++)
            delete [](*i);
          delete (yyvsp[0].VAR_LIST);
        }
#line 3398 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 1323 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.DECLARATION_SITE) = (yyvsp[0].DECLARATION_SITE);}
#line 3404 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 1324 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.DECLARATION_SITE) = (yyvsp[-1].DECLARATION_SITE);}
#line 3410 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 1331 "../src/parser/parser.yy" /* yacc.c:1646  */
    {globalDecls->extend_both_tuples((yyvsp[-3].VAR_NAME), (yyvsp[-1].INT_VALUE)); delete [](yyvsp[-3].VAR_NAME);}
#line 3416 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 1332 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
          globalDecls->extend((yyvsp[0].VAR_NAME));
          delete [](yyvsp[0].VAR_NAME);
        }
#line 3425 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 1338 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_And((yyvsp[-2].ASTP),(yyvsp[0].ASTP));}
#line 3431 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 1339 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_Or((yyvsp[-2].ASTP),(yyvsp[0].ASTP));}
#line 3437 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 1340 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = (yyvsp[0].ASTCP);}
#line 3443 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 1341 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = (yyvsp[-1].ASTP);}
#line 3449 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 1342 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_Not((yyvsp[0].ASTP));}
#line 3455 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 1343 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_exists((yyvsp[-3].DECLARATION_SITE),(yyvsp[-1].ASTP));}
#line 3461 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 1344 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_forall((yyvsp[-3].DECLARATION_SITE),(yyvsp[-1].ASTP));}
#line 3467 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 1363 "../src/parser/parser.yy" /* yacc.c:1646  */
    {popScope();}
#line 3473 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 1366 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP_LIST) = (yyvsp[0].EXP_LIST); (yyval.EXP_LIST)->insert((yyvsp[-2].EXP));}
#line 3479 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 1367 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP_LIST) = new std::set<Exp *>(); (yyval.EXP_LIST)->insert((yyvsp[0].EXP));}
#line 3485 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 1370 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTCP) = new AST_constraints((yyvsp[-2].EXP_LIST),(yyvsp[-1].REL_OPERATOR),(yyvsp[0].EXP_LIST));}
#line 3491 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 1371 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.ASTCP) = new AST_constraints((yyvsp[-2].EXP_LIST),(yyvsp[-1].REL_OPERATOR),(yyvsp[0].ASTCP));}
#line 3497 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 1374 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
            if (v == NULL) {
              yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[0].VAR_NAME)));
              delete [](yyvsp[0].VAR_NAME);
              YYERROR;
            }
            (yyval.EXP) = new Exp(v);
            delete [](yyvsp[0].VAR_NAME);
          }
#line 3512 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 1384 "../src/parser/parser.yy" /* yacc.c:1646  */
    {argCount = 1;}
#line 3518 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 1384 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            Variable_Ref *v;
            if ((yyvsp[-1].ARGUMENT_TUPLE) == Input_Tuple)
              v = functionOfInput[(yyvsp[-4].VAR_NAME)];
            else
              v = functionOfOutput[(yyvsp[-4].VAR_NAME)];
            if (v == NULL) {
              yyerror(std::string("Function ") + to_string((yyvsp[-4].VAR_NAME)) + std::string(" not declared"));
              delete [](yyvsp[-4].VAR_NAME);
              YYERROR;
            }
            (yyval.EXP) = new Exp(v);
            delete [](yyvsp[-4].VAR_NAME);
          }
#line 3537 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 1398 "../src/parser/parser.yy" /* yacc.c:1646  */
    { (yyval.EXP) = (yyvsp[-1].EXP); }
#line 3543 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 1401 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
               Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
               if (v == NULL) {
                 yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[-2].ARGUMENT_TUPLE)));
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               if (v->pos != argCount || v->of != (yyvsp[-2].ARGUMENT_TUPLE) || (v->of != Input_Tuple && v->of != Output_Tuple)) {
                 yyerror("arguments to function must be prefix of input or output tuple");
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               (yyval.ARGUMENT_TUPLE) = v->of;
               argCount++;
               delete [](yyvsp[0].VAR_NAME);
             }
#line 3564 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 1417 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
               Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
               if (v == NULL) {
                 yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[0].VAR_NAME)));
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               if (v->pos != argCount || (v->of != Input_Tuple && v->of != Output_Tuple)) {
                 yyerror("arguments to function must be prefix of input or output tuple");
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               (yyval.ARGUMENT_TUPLE) = v->of;
               argCount++;
               delete [](yyvsp[0].VAR_NAME);
             }
#line 3585 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 1435 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP) = new Exp((yyvsp[0].COEF_VALUE));}
#line 3591 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 1436 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP) = multiply((yyvsp[-1].COEF_VALUE),(yyvsp[0].EXP));}
#line 3597 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 1437 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP) = (yyvsp[0].EXP); }
#line 3603 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 1438 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP) = negate((yyvsp[0].EXP));}
#line 3609 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 1439 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP) = add((yyvsp[-2].EXP),(yyvsp[0].EXP));}
#line 3615 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 1440 "../src/parser/parser.yy" /* yacc.c:1646  */
    {(yyval.EXP) = subtract((yyvsp[-2].EXP),(yyvsp[0].EXP));}
#line 3621 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 1441 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
      try {
        (yyval.EXP) = multiply((yyvsp[-2].EXP),(yyvsp[0].EXP));
      }
      catch (const std::exception &e) {
        yyerror(e.what());
        YYERROR;
      }
    }
#line 3635 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 1453 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
            Dynamic_Array1<Relation> *final = Reachable_Nodes(reachable_info);
            (yyval.RELATION_ARRAY_1D) = final;
          }
#line 3644 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 1459 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
               Dynamic_Array1<Relation> *final = Reachable_Nodes(reachable_info);
               int index = reachable_info->node_names.index(std::string((yyvsp[-3].VAR_NAME)));
               if (index == 0) {
                 yyerror(std::string("no such node ") + to_string((yyvsp[-3].VAR_NAME)));
                 delete [](yyvsp[-3].VAR_NAME);
                 delete final;
                 delete reachable_info;
                 YYERROR;
               }
               (yyval.RELATION) = new Relation; 
               *(yyval.RELATION) = (*final)[index];
               delete final;
               delete reachable_info;
               delete [](yyvsp[-3].VAR_NAME);
             }
#line 3665 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 1477 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
               int sz = reachable_info->node_names.size();
               reachable_info->node_arity.reallocate(sz);
               reachable_info->transitions.resize(sz+1,sz+1);
               reachable_info->start_nodes.resize(sz+1);
             }
#line 3676 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 1485 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                   reachable_info->node_names.append(std::string((yyvsp[0].VAR_NAME)));
                   delete [](yyvsp[0].VAR_NAME);
                 }
#line 3685 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 1489 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                   reachable_info = new reachable_information;
                   reachable_info->node_names.append(std::string((yyvsp[0].VAR_NAME)));
                   delete [](yyvsp[0].VAR_NAME);
                 }
#line 3695 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 1497 "../src/parser/parser.yy" /* yacc.c:1646  */
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
                   }
#line 3742 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 1541 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(index > 0 && index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->start_nodes[index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 3761 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 1555 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int from_index = reachable_info->node_names.index((yyvsp[-4].VAR_NAME));
                            if (!(from_index > 0 && from_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-4].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            int to_index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(to_index > 0 && to_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->transitions[from_index][to_index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-4].VAR_NAME);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 3791 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 1580 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int from_index = reachable_info->node_names.index((yyvsp[-4].VAR_NAME));
                            if (!(from_index > 0 && from_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-4].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            int to_index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(to_index > 0 && to_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->transitions[from_index][to_index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-4].VAR_NAME);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 3821 "parser.tab.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 1605 "../src/parser/parser.yy" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(index > 0 && index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->start_nodes[index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 3840 "parser.tab.cc" /* yacc.c:1646  */
    break;


#line 3844 "parser.tab.cc" /* yacc.c:1646  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1621 "../src/parser/parser.yy" /* yacc.c:1906  */


void yyerror(const std::string &s) {
  std::stringstream ss;
  if (is_interactive)
    ss << s << "\n";
  else
    ss << s << " at line " << mylexer.lineno() << "\n";
  err_msg = ss.str();
}
 
Relation * ParseRelation(std::string relationString){
  std::istringstream iss(relationString);
  yy_buffer_state *bs = 
	mylexer.yy_create_buffer(&iss, 8092);
  mylexer.yypush_buffer_state(bs);
  omega::relation_result = NULL;
  yyparse();
  if(relation_result==NULL)
    return NULL;
  return omega::relation_result;
       
 
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
