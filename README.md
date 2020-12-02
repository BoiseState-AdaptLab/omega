# Omega 

This tool is a variation of Omega+ and CodeGen+ using suif as it's IR.

# Author
This project is originally authored by Chun Chen and contains references to the following repositories.

1. http://ctop.cs.utah.edu/downloads/omega.tar.gz2. 
2. https://github.com/CompOpt4Apps/Artifact-DataDepSimplify/tree/master/chill/omega3.  
3. https://github.com/BoiseState-AdaptLab/the-omega-project.git

Contributors to this repository: Tobi , Anna, Cathie





Omega+ and CodeGen+ 2.2 open source release
See LICENSE file for copyright information.

Omega+ is a mathematical library for manipulating integer linear
constraints over integer variables in first order logic, and
operations on integer sets and their mappings. CodeGen+ is a code
generation library by scanning the points in a union of polytopes.
A command-line interface to libraries is also included.


What is new?
============

version 2.2:
  * Redesigned polyhedra scanning which generates higher quality code
    than before especially for complex set of polyhedra.
  * New SimpleHull for hull approximation (deprecate Hull).
  * Command line editing and history support in calculator.

version 2.1:
  * Updated "effort" parameter's meaning in MMGenerateCode: value n
    (n >= 0, default to 1) means that control overheads are removed
    from all n-depth innermost loops.
  * Enhanced stride handling in the code generation.
  * Support code generation for a set of iteration spaces with different
    dimensionality.
  * New ConvexRepresentation that reduces the number of conjuncts in a union
    (deprecate CheckForConvexPairs and CheckForConvexRepresentation).
  * Handle floor/ceiling defined variables cleanly in output code.
  * Use namespace omega for the library.
  * New closure functions contributed by Klimek Tomasz (R^+ and R^@).

version 2.0:
  * Improved internal code generation interface so that it generates both
    string and suif ouput now, and more easily extendable for new compiler
    intermediate representations.
  * Improved gist function so that integer modular constraints are handled
    more gracefully.
  * Merge duplicate if-conditions in generated code, which might still miss
    a few opportunities due to the way AST is constructed.
  * Correct output/input variable substitution for non-unimodular
    mapping relations.
  * Deprecate Omega's assert/Exit interface.
  * Some fixing in calculator's parsing and interactive interface.

version 1.2 (Omega Project):
  * Support for code generation with memory mappings, as described in
    Tina Shen's MASPLAS '98 paper. This is available in oc via the
    tcodegen function; see examples/calc/mm* for examples.
  * Use of the compile-time flags -DSTILL_CHECK_MULT=1 -DNDEBUG turns off 
    all assertions and chechk _except_ some checks for integer overflow
    during variable elimination in the omega core. Unless you know a priori
    that overflow cannot occur, you should use this instead of just plain
    -DNDEBUG when optimizing.
  * You can now use "assertUnsatisfiable relation" to cause oc to quit if
    "relation" could be satisfiable. This is mainly useful when running oc
    in a script.

version 1.1 (Omega Project):
  * An exact convex hull computation.
  * An improved system for handling inexact relations, including taking
    upper and lower bounds, checking for subsets, and checking tautologies.
  * Better handling of existentially quantified variables: we can now
    negate and generate code for sets like:
    {[i]: 1 <= i <= n && exists (alpha: i <= 10*alpha <= i+k)}.
  * An Example operator, that gives a sample solution to set or relation.

version 0.90 (Omega Project):
  * Initial release.


DIRECTORIES 
===========

omega/
  omega_lib/     source files for the Omega+ library
  code_gen/      source files for the CodeGen+ library
  omega_calc/    source files for the calculator
  examples/      script examples using calculator 
    c_code/      code examples for using libraries
  bin/           links to executables: oc
  lib/           links to libraries: libomega.a, libcode_gen.a
  include/       links to header files


DOCUMENTATION AND QUESTIONS
===========================

There are only old documents from the Omega Project under doc/ subdirectory
for now.

Software website:
  http://www.chunchen.info/omega

For questions, bug reports or suggestions, please contact:
  mailto:riverofdreams@gmail.com
