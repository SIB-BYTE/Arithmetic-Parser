/*
<expr> ::= <term> ( + | - ) <expr> | <term>
<term> ::= <power> ( * | / | % ) <term> | <power>
<power> ::= <unary> ^ <power> | <unary>
<unary> ::= - <unary> | <factor>
<factor> ::= ( <expr> ) | <integer>
*/

#include <stdio.h>
#include "parser.h"

#define TRUE 1

int main(void)
{
	char expr[64];

	while(TRUE)
	{
		printf("Provide a valid grammar: ");
		fgets(expr, sizeof(expr), stdin);

		lexer_t *tokenize = lexer(expr);
		printf("Result of grammar -> {%lf}\n", parse(tokenize));

		destroy_all_tokens(tokenize);
		lexer_destroy(tokenize);
	}
}

