noinst_PROGRAMS=oc
bin_PROGRAMS = $(noinst_PROGRAMS)

OC_SRCDIR=$(srcdir)/../src


build_date = "\"`date +%m/%d/%Y`\""

AM_YFLAGS=-d -t
EXTRA_DIST=

calc_includes  =-I$(OC_SRCDIR)
calc_includes +=-I$(srcdir)/../include
calc_includes +=-I$(srcdir)/../../omega_lib/include
calc_includes +=-I$(srcdir)/../../code_gen/include
calc_includes +=-I$(srcdir)/../../basic/include
calc_includes +=-I$(srcdir)/../../..

#calc_libs =../../omega_lib/obj/libomega.a
#calc_libs+=../../code_gen/obj/libcodegen.a
calc_libs = -lcodegen -lomega
calc_lib_paths =-L../../omega_lib/obj -L../../code_gen/obj
#calc_lib_paths+=-L$(ROSEHOME)/lib -L$(BOOSTHOME)/lib

oc_SOURCES=../src/calc.cc
oc_LDADD=$(calc_libs)
oc_LDFLAGS=$(calc_lib_paths)
oc_CPPFLAGS=$(calc_includes) -DBUILD_CODEGEN -DOMEGA_BUILD_DATE=$(build_date) -DOC_BUILD_DATE=$(build_date)
oc_CXXFLAGS=-std=c++11


#../src/calc.o: ../src/calc.cc
#        $(CC) $(CFLAGS) -DOMEGA_BUILD_DATE="\"$(OMEGA_BUILD_DATE)\"" $(INCL_PATH) -c $<
