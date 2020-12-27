noinst_LIBRARIES   = libomega.a
lib_LIBRARIES = $(noinst_LIBRARIES)

basic_src   =../../basic/src/ConstString.cc
basic_src  +=../../basic/src/Link.cc

oc_src   =../src/omega_core/oc.cc
oc_src  +=../src/omega_core/oc_eq.cc
oc_src  +=../src/omega_core/oc_exp_kill.cc
oc_src  +=../src/omega_core/oc_global.cc
oc_src  +=../src/omega_core/oc_print.cc
oc_src  +=../src/omega_core/oc_problems.cc
oc_src  +=../src/omega_core/oc_simple.cc
oc_src  +=../src/omega_core/oc_solve.cc
oc_src  +=../src/omega_core/oc_query.cc
oc_src  +=../src/omega_core/oc_quick_kill.cc
oc_src  +=../src/omega_core/oc_util.cc

pres_src   =../src/pres_beaut.cc
pres_src  +=../src/pres_cnstr.cc
pres_src  +=../src/pres_col.cc
pres_src  +=../src/pres_conj.cc
pres_src  +=../src/pres_decl.cc
pres_src  +=../src/pres_dnf.cc
pres_src  +=../src/pres_form.cc
pres_src  +=../src/pres_gen.cc
pres_src  +=../src/pres_logic.cc
pres_src  +=../src/pres_print.cc
pres_src  +=../src/pres_rear.cc
pres_src  +=../src/pres_quant.cc
pres_src  +=../src/pres_subs.cc
pres_src  +=../src/pres_var.cc

rel_src   =../src/evac.cc
rel_src  +=../src/farkas.cc
rel_src  +=../src/hull_legacy.cc
rel_src  +=../src/hull_simple.cc
rel_src  +=../src/Relation.cc
rel_src  +=../src/Relations.cc
rel_src  +=../src/RelBody.cc
rel_src  +=../src/RelVar.cc

fancy_src   =../src/closure.cc
fancy_src  +=../src/reach.cc


# Installation specifications.
nobase_include_HEADERS = ../include/omega/Relations.h   \
			 ../include/omega/pres_subs.h   \
			../include/omega/pres_conj.h   \
			../include/omega/pres_dnf.h   \
			../include/omega/Rel_map.h   \
			../include/omega/pres_form.h   \
			../include/omega/evac.h   \
			../include/omega/pres_logic.h   \
			../include/omega/pres_gen.h   \
			../include/omega/pres_quant.h   \
			../include/omega/pres_decl.h   \
			../include/omega/pres_cnstr.h   \
			../include/omega/omega_core/debugging.h   \
			../include/omega/omega_core/oc.h   \
			../include/omega/omega_core/oc_i.h   \
			../include/omega/Relation.h   \
			../include/omega/pres_var.h   \
			../include/omega/reach.h   \
			../include/omega/RelBody.h   \
			../include/omega/pres_tree.h   \
			../include/omega/farkas.h   \
			../include/omega/hull.h   \
			../include/omega/closure.h   \
			../include/omega/pres_cmpr.h   \
			../include/omega/omega_i.h   \
			../include/omega.h

libomega_a_SOURCES  =$(basic_src) $(oc_src) $(pres_src) $(rel_src) $(fancy_src)
libomega_a_CPPFLAGS =-I$(srcdir)/../include -I$(srcdir)/../../basic/include
libomega_a_CXXFLAGS =-std=c++11
