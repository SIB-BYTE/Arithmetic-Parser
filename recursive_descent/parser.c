/*
<expr> ::= <term> ( + | - ) <expr> | <term>
<term> ::= <power> ( * | / | % ) <term> | <power>
<power> ::= <unary> ^ <power> | <unary>
<unary> ::= - <unary> | <factor>
<factor> ::= ( <expr> ) | <integer>
*/

#include "parser.h"

token_t *current_token = 0;

void consume_token(int type)
{
    LASSERT(current_token || current_token->fd, "No current token || End of the token stream");
    LASSERT(current_token->type == type, "Parser error: Excepted token a proper token!");

    if(current_token->fd)
        current_token = current_token->fd;
}

float parse(lexer_t *token)
{
	LASSERT(token->head, "Invalid token!");

    current_token = token->head;
    return (expr());
}

float expr(void)
{
	LASSERT(current_token->type != -1, "Invalid token passed!");

    float res = term();

    if(current_token->type == ADD_OP)
    {
        consume_token(ADD_OP);
        res += expr();
    }

    else if(current_token->type == SUB_OP)
    {
        consume_token(SUB_OP);
        res -= expr();
    }

    return (res);
}

float term(void)
{
	LASSERT(current_token->type != -1, "Invalid token passed!");

    float res = power();

    if(current_token->type == MUL_OP)
    {
        consume_token(MUL_OP);
        res *= term();
    }

    else if(current_token->type == DIV_OP)
    {
		consume_token(DIV_OP);
		res /= term();
    }

    return (res);
}

float power(void)
{
	LASSERT(current_token->type != -1, "Invalid token passed!");

    float res = unary();

    if(current_token->type == POWER_OF)
    {
        consume_token(POWER_OF);
        res = pow(res, power());
    }

    return (res);
}

float unary(void)
{
	LASSERT(current_token->type != -1, "Invalid token passed!");

    if(current_token->type == SUB_OP)
    {
        consume_token(SUB_OP);
        return (-unary() - 0);
    }
    else
        return (factor());
}

float factor(void)
{
    float res = 0.00;

    if(current_token->type == L_PAR)
    {
        consume_token(L_PAR);
        res = expr();
        consume_token(R_PAR);

        return (res);
    }
    else if(current_token->type == 1)
    {
        int tmp = current_token->value;
        consume_token(1);

        return (tmp);
    }

    return (res);
}

