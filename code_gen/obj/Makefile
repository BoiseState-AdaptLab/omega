# DON'T EDIT -- put any locally required changes in Makefile.config.

LIB_TARGET=libcodegen.a

all: $(LIB_TARGET)
depend:$(YACC_SRCS) depend_self
clean: clean_self
veryclean: veryclean_self

BASIC_SRC = ../src/codegen.cc ../src/CG_stringBuilder.cc ../src/CG.cc ../src/CG_utils.cc 
BASIC_OBJ = $(BASIC_SRC:../src/%.cc=%.o)

# Adding Parser to codegen
PARSER_SRC = ../src/parser/AST.cc ../src/parser/myflex.cc
PARSER_OBJS= $(PARSER_SRC:../src/parser/%.cc=%.o)

YACC_SRCS := lex.yy.cc parser.tab.cc
YACC_OBJS := $(YACC_SRCS:.cc=.o) 

SUIF_SRC = ../src/CG_suifRepr.cc ../src/CG_suifBuilder.cc
SUIF_OBJ = $(SUIF_SRC:../src/%.cc=%.o)

OBJS = ${BASIC_OBJ} ${PARSER_OBJS} ${YACC_OBJS}
SRCS = ${BASIC_SRC} ${YACC_SRCS} ${PARSER_SRC}

BASEDIR=../..
include $(BASEDIR)/Makefile.config

INCL_PATH :=-I../src/parser/ $(INCL_PATH) -I../../omega_lib/include

ifeq ($(BUILD_SUIF), true)
OBJS := $(OBJS) $(SUIF_OBJ)
SRCS := $(SRCS) $(SUIF_SRC)
INCL_PATH := $(INCL_PATH) -I${SUIFHOME}/include
endif

include $(BASEDIR)/Makefile.rules


# lex/yacc related
#.PHONY: parser.tab.o

lex.yy.cc: ../src/parser/parser.ll
	flex++ $<

parser.tab.hh parser.tab.cc: ../src/parser/parser.yy
	bison -t -d $<

parser.tab.o: parser.tab.cc
	$(CC) $(CFLAGS) -DOMEGA_BUILD_DATE="\"$(OMEGA_BUILD_DATE)\"" $(INCL_PATH) -c $<

# suppress warning of constant char * conversion nuiance in suif
$(SUIF_OBJ): %.o: ../src/%.cc
	$(CC) -Wno-write-strings $(CFLAGS) $(INCL_PATH) -c $< -o $@

%.o: ../src/parser/%.cc
	$(CC) -Wno-write-strings $(CFLAGS) $(INCL_PATH) -c $< -o $@


ifeq ($(shell test -f Makefile.deps && echo "true"), true)
include Makefile.deps
endif
