### note: I have no idea what version of omega this is.
###       If it's not 0.1.0, feel free to change it
AC_INIT([omega],[0.1.0])
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([-Wall -Werror no-dependencies foreign subdir-objects])

### Use the C++ compiler for linking (C is default) ###
AC_SUBST([CCLD],["$""(CXX)"])
AC_DEFINE([OMEGA_VERSION],["0.1.0"],[Omega version])

: ${CFLAGS="-O0 -g"}
: ${CXXFLAGS="-O0 -g"}

AM_PROG_AR
AM_PROG_LEX
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB
AC_PROG_YACC

AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_FILES([
    omega_lib/obj/Makefile
    omega_calc/obj/Makefile
    code_gen/obj/Makefile
    basic/obj/Makefile])

AC_OUTPUT
    

