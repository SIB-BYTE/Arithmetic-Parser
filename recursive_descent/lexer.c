#include "lexer.h"

/*
//Sanity test:
int main(void)
{
	char expression[] = "1 + 1";
	lexer_t *lexer_test = lexer(expression);
	destroy_all_tokens(lexer_test);
	lexer_destroy(lexer_test);
}
*/

// Construct a token token structure.
token_t *new_token(char type, int value)
{
	token_t *token = calloc(1, sizeof(token_t));
	LASSERT(token != NULL, "Token: Failed memory allocation!");

	token->type = type;
	token->value = value;
	token->fd = NULL;

	return (token);
}

// Iterates over the token structure data.
void lexer_iterator(token_t *head)
{
	for(token_t *tmp = head; tmp; tmp = tmp->fd)
		printf("Token type -> {%s}\nToken value -> {%d}\n", token_type(tmp->type), tmp->value);
}

// Iterates the enumeration structure to determine it's string value and returns that.
const char *token_type(int token_type)
{
	switch(token_type)
	{
		case 1:
			return "Floating point value";

		case 2:
			return "Integer value";

		case '(':
			return "Left parenthesis";

		case ')':
			return "Right parenthesis";

		case '+':
			return "Addition operator";

		case '-':
			return "Subtraction operator";

		case '*':
			return "Multiplication operator";

		case '/':
			return "Division operator";

		case '^':
			return "Power of operator";

		case ' ':
			return "Space white-space!";

		default:
			return "Not a valid token!";
	}
}

// Iterates through the linked list and deconstructs each node.
void destroy_all_tokens(lexer_t *tokens)
{
	token_t *tmp = tokens->head;
	token_t *next_ptr;

	while(tmp)
	{
		next_ptr = tmp->fd;
		free(tmp);
		tmp = next_ptr;
	}
}

// Constructs a lexer structure.
lexer_t *lexer_create(char *expr)
{
	lexer_t *lexer = calloc(1, sizeof(lexer_t));
	LASSERT(lexer != NULL, "Lexer: Memory allocation failed");

	lexer->expr = expr;

	return (lexer);
}

// Append token to the end of the linked list.
void lexer_add_token(lexer_t *lexer, token_t *token)
{
	if(!lexer->head)
	{
		lexer->head = token;
		return;
	}

	token_t *tmp = lexer->head;

	while(tmp->fd)
		tmp = tmp->fd;

	tmp->fd = token;
}

// Tokenizes the string inside of the "lexer" structure.
void parse_integer(lexer_t *lexer)
{
	char *end;
	errno = 0;

	long lexme = strtol(lexer->expr, &end, 10);
	
	LASSERT(errno == 0, "Strtol error!");
	LASSERT((lexme < MAX_SIZE && lexme > MIN_SIZE), "Not a valid integer!");
	LASSERT(lexer->expr != end, "Yeah this shouldn't happen lmfao");

	token_t *token = new_token(INTEGER, lexme);
	lexer_add_token(lexer, token);
	lexer->expr = end;
}

// Inserts the token and iterates over the lexers held expression.
void lexer_advance(lexer_t *lexer, char type)
{
	lexer_add_token(lexer, new_token(type, 0));
	lexer->expr++;
}

// Deconstructs the lexer structure.
void lexer_destroy(lexer_t *lexer)
{
	free(lexer);
}

lexer_t *lexer(char *tokens)
{
	// Construct a structure that holds the tokens as the "buffer".
	lexer_t *lexer = lexer_create(tokens);

	while(*lexer->expr) // Iterates over the tokens
	{
		// Checks to see if the tokens we are tokenizing are digits or not.
		if(isdigit(*lexer->expr))
			parse_integer(lexer);
		
		// If they aren't we'll append to our linked list.
		else 
		{
			// Appends the operator token to the linked list.
			switch(*lexer->expr)
			{
				case '+':
					lexer_advance(lexer, '+');
					break;

				case '-':
					lexer_advance(lexer, '-');
					break;

				case '*':
					lexer_advance(lexer, '*');
					break;

				case '/':
					lexer_advance(lexer, '/');
					break;

				case '(':
					lexer_advance(lexer, '(');
					break;

				case ')':
					lexer_advance(lexer, ')');
					break;

				case '^':
					lexer_advance(lexer, '^');
					break;

				default:
					lexer->expr++;
					break;
			}
		}
	}
	return(lexer);
}
