#ifndef _PARSER_H
#define _PARSER_H

#include <omega.h>
#include <string>
using namespace omega;
namespace omega {
namespace parser {
   /**
    *This function returns an omega relation from a 
    * string.
    */
   Relation *ParseRelation(std::string relationString);
 } 
} // namespace omega

#endif
