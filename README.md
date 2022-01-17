# Arithmetic-Parser
LL(1) parser with a hand-written lexer.

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
