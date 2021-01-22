#ifndef DEBUG_H_H
#define DEBUG_H_H
#include <stdio.h>
#include <stdarg.h>


#ifndef DEBUG_PRINTF
#define DEBUG_PRINTF 0
#endif

#define debug_fprintf(f, ...)               do { if(DEBUG_PRINTF) { fprintf(f, __VA_ARGS__); } } while(false)
#endif
