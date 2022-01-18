/*
<expr> ::= <term> ( + | - ) <expr> | <term>
<term> ::= <power> ( * | / | % ) <term> | <power>
<power> ::= <unary> ^ <power> | <unary>
<unary> ::= - <unary> | <factor>
<factor> ::= ( <expr> ) | <integer>
*/

#include <stdio.h>
#include "parser.h"

int main(void)
{
	char expr[64];

	printf("Provide a grammar: ");
	fgets(expr, sizeof(expr), stdin);

	lexer_t *tokenize = lexer(expr);
	printf("Result of grammar -> {%d}\n", parse(tokenize));

	destroy_all_tokens(tokenize);
	lexer_destroy(tokenize);
}
