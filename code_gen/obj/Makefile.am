
noinst_LIBRARIES =libcodegen.a

codegen_includes =-I$(srcdir)/../../..
codegen_includes+=-I$(srcdir)/../include
codegen_includes+=-I$(srcdir)/../../../include/chill
codegen_includes+=-I$(srcdir)/../../omega_lib/include
codegen_includes+=-I$(srcdir)/../../basic/include

parser_src = ../src/parser

libcodegen_a_SOURCES    =../src/codegen.cc
libcodegen_a_SOURCES   +=../src/CG_stringBuilder.cc
libcodegen_a_SOURCES   +=../src/CG.cc
libcodegen_a_SOURCES   +=../src/CG_utils.cc
libcodegen_a_SOURCES   += $(parser_src)/AST.cc $(parser_src)/myflex.cc\
			  $(parser_src)/lex.yy.cc $(parser_src)/parser.tab.cc

libcodegen_a_CXXFLAGS   =-std=c++11
libcodegen_a_CPPFLAGS   =$(codegen_includes)

EXTRA_DIST=$(parser_src)/lex.yy.cc
$(parser_src)/lex.yy.cc: $(parser_src)/parser.tab.cc $(parser_src)/parser.ll
	flex++ -o $(parser_src)/lex.yy.cc $(parser_src)/parser.ll

EXTRA_DIST+=$(parser_src)/parser.tab.cc
$(parser_src)/parser.tab.cc: $(parser_src)/parser.yy
	bison -t -d -o $(parser_src)/parser.tab.cc $(parser_src)/parser.yy

