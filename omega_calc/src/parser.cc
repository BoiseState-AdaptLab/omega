#include <basic/Dynamic_Array.h>
#include <basic/Iterator.h>
#include <omega_calc/AST.h>
#include <omega/hull.h>
#include <omega/closure.h>
#include <omega/reach.h>
#include <string>
#include <iostream>
#include <fstream>
#include "parser.tab.hh"
#include <omega_calc/myflex.h>

#if defined __USE_POSIX
#include <unistd.h>
#elif defined  __WIN32
#include <io.h>
#endif
  
#ifdef BUILD_CODEGEN  
#include <code_gen/codegen.h>
#endif

// Generated files from Yac would implement 
// this function. The file is added to the 
// build system.
extern int yyparse();
extern myFlexLexer mylexer;
extern bool is_interactive;
extern const char *PROMPT_STRING;
  
using namespace omega;

extern std::string err_msg;
bool need_coef;
int main(int argc, char **argv) {
  if (argc > 2){
    fprintf(stderr, "Usage: %s [script_file]\n", argv[0]);
    exit(1);
  }

  if (argc == 2) {
    std::ifstream *ifs = new std::ifstream;
    ifs->open(argv[1], std::ifstream::in);
    if (!ifs->is_open()) {
        fprintf(stderr, "can't open input file %s\n", argv[1]);
        exit(1);
    }
    yy_buffer_state *bs = mylexer.yy_create_buffer(ifs, 8092);
    mylexer.yypush_buffer_state(bs);
  }

  is_interactive = false;
  if (argc == 1) {
#if defined __USE_POSIX  
    if (isatty((int)fileno(stdin)))
      is_interactive = true;
#elif defined  __WIN32
    if (_isatty(_fileno(stdin)))
      is_interactive = true;
#endif
  }

  if (is_interactive) {
#ifdef BUILD_CODEGEN
    std::cout << "Omega+ and CodeGen+ ";
#else
    std::cout << "Omega+ ";
#endif
    std::cout << "v2.2.3 (built on " OMEGA_BUILD_DATE ")" << std::endl;
    std::cout << "Copyright (C) 1994-2000 the Omega Project Team" << std::endl;
    std::cout << "Copyright (C) 2005-2011 Chun Chen" << std::endl;
    std::cout << PROMPT_STRING << ' ';
    std::cout.flush();
  }

  need_coef = false;  
  current_Declaration_Site = globalDecls = new Global_Declaration_Site();

  if (yyparse() != 0) {
    if (!is_interactive)
      std::cout << "syntax error at the end of the file, missing ';'" << std::endl;
    else
      std::cout << std::endl;
    delete relationDecl;
    relationDecl = NULL;
  }
  else {
    if (is_interactive)
      std::cout << std::endl;
  }

  for (std::map<std::string, Relation *>::iterator i = relationMap.begin(); i != relationMap.end(); i++)
    delete (*i).second;
  delete globalDecls;  
  
  return 0;
}

