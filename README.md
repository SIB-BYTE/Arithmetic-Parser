# Arithmetic-Parser:
# How to use install it:

```ocaml
git clone https://github.com/SIB-BYTE/Arithmetic-Parser/ ; make ; ./main
```

# Logic break-down:
LL(1) parser with a hand-written lexer. (I plan on also implementing the shunting-yard algorithm to also parse arithmetic expressions)

Here is the backus-naur form metasyntax to describe how the recursive-descent parser will accept it's context-free grammars and what it will do with them:
```bnf
<integer> ::= [0-9]
<expr>    ::= <term> ( + | - ) <expr> | <term>
<term>    ::= <power> ( * | / | % ) <term> | <power>
<power>   ::= <unary> ^ <power> | <unary>
<unary>   ::= - <unary> | <factor>
<factor>  ::= ( <expr> ) | <integer>
```

Each non-terminal terminal is flexible, therefore you can adjust it to your liking and understanding. But for the sake of good practice and normalized standards I 
just used what other people regularly defined their non-terminal naming convention as. Anyways, the LL(1) parsing algorithm is what's known as recursive-desecent 
parsing which is a form of top-down parsing. This parsing algorithm that is built off of the idea of mutual recursion which is a type of recursion that has 
specific procedures call other procedures in a recursive-nature, this can be expressed like this: Function A() calls function B() which calls function C() which calls function A() once more, it's almost like a recursive circle that's led through the nature of mutual recursion.

# Resources:

https://en.wikipedia.org/wiki/Recursive_descent_parser

https://www.sparknotes.com/cs/recursion/whatisrecursion/section2/


# API Usage:
The parser will only take given set of context-free grammar sets that include valid integers and valid operators that have support from the lexer like so:
```c
#include <stdio.h>
#include "parser.h"

int main(void)
{
    char expr[] = "10 + 5 * (20 / 10)"; // This cannot be a pointer to a string because pointers only hold string literals that however cannot be modified.
    lexer_t *tokenize = lexer(expr);
    printf("Result of evaluation : %d\n", parse(expr));
    
    destroy_lexer(tokenize);
    free_all_tokens(tokenize);
}
```

"expr" in this case can be any given expression that is valid and able to be accepted by our grammar.
