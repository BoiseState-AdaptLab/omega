
noinst_LIBRARIES =libcodegen.a

codegen_includes =-I$(srcdir)/../../..
codegen_includes+=-I$(srcdir)/../include
codegen_includes+=-I$(srcdir)/../../../include/chill
codegen_includes+=-I$(srcdir)/../../omega_lib/include
codegen_includes+=-I$(srcdir)/../../basic/include

libcodegen_a_SOURCES    =../src/codegen.cc
libcodegen_a_SOURCES   +=../src/CG_stringBuilder.cc
libcodegen_a_SOURCES   +=../src/CG.cc
libcodegen_a_SOURCES   +=../src/CG_utils.cc
libcodegen_a_CXXFLAGS   =-std=c++11
libcodegen_a_CPPFLAGS   =-DFRONTEND_ROSE $(codegen_includes)

