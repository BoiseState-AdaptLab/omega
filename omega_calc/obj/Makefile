# DON'T EDIT -- put any locally required changes in Makefile.config.

EXEC_TARGET=oc

all: $(EXEC_TARGET)
clean: clean_self
veryclean: veryclean_self

SRCS := ../src/calc.cc
OBJS := $(SRCS:../src/%.cc=%.o)



#YACC_SRCS := lex.yy.cc parser.tab.cc
#YACC_OBJS := $(YACC_SRCS:.cc=.o)

#depend: $(YACC_SRCS) depend_self

depend: depend_self

SRCS := $(SRCS) 
OBJS := $(OBJS)

BASEDIR=../..
include $(BASEDIR)/Makefile.config

LIB_PATH := $(LIB_PATH) -L../../omega_lib/obj
LIBS := $(LIBS) -lomega

ifeq ($(BUILD_CODEGEN), true)
LIB_PATH := $(LIB_PATH) -L../../code_gen/obj
LIBS := $(LIBS) -lcodegen
CFLAGS := $(CFLAGS) -DBUILD_CODEGEN
endif

CFLAGS := $(CFLAGS)
INCL_PATH := -I. $(INCL_PATH) -I../../omega_lib/include -I../../code_gen/include

include $(BASEDIR)/Makefile.rules

calc.o: ../src/calc.cc
	$(CC) $(CFLAGS) -DOMEGA_BUILD_DATE="\"$(OMEGA_BUILD_DATE)\"" $(INCL_PATH) -c $<

$(EXEC_TARGET):calc.o
	$(CC) $(LIB_PATH) $< -Wl,--start-group $(LIBS) -Wl,--end-group -o $@

ifeq ($(shell test -f Makefile.deps && echo "true"), true)
include Makefile.deps
endif
