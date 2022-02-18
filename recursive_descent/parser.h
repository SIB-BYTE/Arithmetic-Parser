#ifndef __PARSER_H
#define __PARSER_H

#include "lexer.h"
#include <math.h>
#include <stdbool.h>

// debug tingz.
#define LASSERT(condition, message) \
    do \
    { \
        if(!(condition)) \
        { \
            puts("[*] Process terminated! LASSERT(); failed!"); \
            fprintf(stderr, "Condition\t: {%s}\nFunction\t: {%s}\nFailed in file\t: {%s}\nAt line \t: {%d}\n", #condition, __func__, __FILE__, __LINE__);\
            puts(message); \
            exit(1); \
        } \
    } while(0) \

// Parser aspects.
float parse(lexer_t *token);
void consume_token(int type);

// Mathematical operations.
float term(void);
float expr(void);
float unary(void);
float power(void);
float factor(void);

#endif
