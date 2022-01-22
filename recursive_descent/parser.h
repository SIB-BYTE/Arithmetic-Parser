#ifndef __PARSER_H
#define __PARSER_H

#include "lexer.h"
#include <math.h>

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
