
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 165 "parser.tab.hh"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


