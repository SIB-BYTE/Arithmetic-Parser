#ifndef __LEXER_H
#define __LEXER_H

#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

#define MAX_SIZE 2147483647
#define MIN_SIZE -2147483648

// Token structure.
struct token {
	enum token_type {
		DOUBLE   = 1,
		INTEGER  = 2,
		R_PAR    = ')',
		L_PAR    = '(',
		ADD_OP   = '+',
		SUB_OP   = '-',
		MUL_OP   = '*',
		DIV_OP   = '/',
		POWER_OF = '^'
	} type;

	double value;
	struct token *fd;

} typedef token_t;

// Lexer structure.
struct lexer {
	char *expr;
	token_t *head;
} typedef lexer_t;

// Tokenizing functionalities.
void parse_integer(lexer_t *lexer);
const char *token_type(int token_type);
token_t *new_token(char token_type, double value);

// Lexer functionalities. 
lexer_t *lexer(char *tokens);
lexer_t *create_lexer(char *expr);
void lexer_iterator(token_t *head);
void lexer_advance(lexer_t *lexer, char type);
void lexer_add_token(lexer_t *lexer, token_t *token);
void lexer_destroy(lexer_t *lexer);

// Misc
void destroy_all_tokens(lexer_t *tokens);

#endif
