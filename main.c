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
#define BLUE printf("\x1b[1;34m")
#define CONSTRUCTOR __attribute__((constructor))

// Yes I know that a banner is kinda useless and not-needed but I felt like doing one so why not?
void CONSTRUCTOR banner_display(void)
{
	char *banner[] = {
	"  ██████╗  █████╗ ██╗   ██╗ ",
	" ██╔════╝ ██╔══██╗╚██╗ ██╔╝ ",
	" ██║  ███╗███████║ ╚████╔╝  ",
	" ██║   ██║██╔══██║  ╚██╔╝   ",
	" ╚██████╔╝██║  ██║   ██║    ",
 	"  ╚═════╝ ╚═╝  ╚═╝   ╚═╝    "
	};

	int len = sizeof(banner) / sizeof((*banner));

	BLUE;
	for(int i = 0; i < len; i++)
		printf("%s\n", banner[i]);
}

int main(void)
{
	char expr[64];

	while(TRUE)
	{
		printf("Provide a valid grammar: ");
		fgets(expr, sizeof(expr), stdin);

		lexer_t *tokenize = lexer(expr);
		printf("Result of grammar -> {%d}\n", parse(tokenize));

		destroy_all_tokens(tokenize);
		lexer_destroy(tokenize);
	}
}
