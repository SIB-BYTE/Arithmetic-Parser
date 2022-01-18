#ifndef __PARSER_H
#define __PARSER_H

#include "lexer.h"
#include <math.h>

// Little debugging tingz.
#define LASSERT(condition, message) \
    do \
    { \
        if(!(condition)) \
        { \
            puts("[*] Process terminated! lassert() failed!"); \
            fprintf(stderr, "Condition\t: {%s}\nFunction\t: {%s}\nFailed in file\t: {%s}\nAt line \t: {%d}\n", #condition, __FUNCTION__, __FILE__, __LINE__);\
            puts(message); \
            exit(1); \
        } \
    } while(0) \


// Parser aspects.
int parse(lexer_t *token);
void consume_token(int type);

// Mathematical operations.
int term(void);
int expr(void);
int unary(void);
int power(void);
int factor(void);

#endif
