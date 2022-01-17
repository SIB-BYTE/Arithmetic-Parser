build:
	gcc lexer.c parser.c main.c -o main -Og -g3 -lm

build_debug:
	gcc lexer.c parser.c main.c -o main -Og -g3 -fsanitize=address,undefined -lm

build_clean:
	rm main

lexer_build:
	gcc lexer.c -o lexer -Og -g3

lexer_debug:
	gcc lexer.c -o lexer -Og -fsanitize=address,undefined -g3

parser_debug:
	gcc parser.c -o parser -Og -g3 -lm

parser_build:
	gcc parser.c -o parser -Og -fsanitize=address,undefined -g3 -lm
	