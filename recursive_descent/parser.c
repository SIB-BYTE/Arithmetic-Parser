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
 
int parse(lexer_t *token)
{
    current_token = token->head;
    return (expr());
}
 
int expr(void)
{
    int res = term();
 
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
 
int term(void)
{
    int res = power();
 
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
 
int power(void)
{
    int res = unary();
 
    if(current_token->type == POWER_OF)
    {
        consume_token(POWER_OF);
        res = pow(res, power());
    }
 
    return (res);
}
 
int unary(void)
{
    if(current_token->type == SUB_OP)
        return (0 - unary());
    else
        return(factor());
}
 
int factor(void)
{
    int res = 0;
 
    if(current_token->type == L_PAR)
    {
        consume_token(L_PAR);
        res = expr();
        consume_token(R_PAR);
        return (res);
    }
    else if(current_token->type == 2)
    {
        int tmp = current_token->value;
        consume_token(2);
        return (tmp);
    }
    
    return (res);
}
 