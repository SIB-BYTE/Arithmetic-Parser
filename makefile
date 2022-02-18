CC = gcc
CFLAGS = -Wall -Wextra -Ofast -lm -o
CFLAGS_DEBUG = -Wall -Wextra -fsanitize=address,undefined -g3 -Ofast -D DEBUG -lm -o

# Final build
BUILD = recursive_descent/parser.c recursive_descent/lexer.c recursive_descent/main.c
BIN = main

# Final build debug
BIN_DEBUG = main_debug

# Lexer debugging build
LEXER = recursive_descent/lexer.c
LEXER_BIN = lexer_debug

# Parser debugging build
PARSER = recursive_descent/parser.c
PARSER_BIN = parser_debug

build:
	$(CC) $(BUILD) $(CFLAGS) $(BIN)

build_debug:
	$(CC) $(BUILD) $(CFLAGS_DEBUG) $(BIN_DEBUG)

lexer_debug:
	$(CC) $(LEXER) $(CFLAGS_DEBUG) $(LEXER_BIN)

parser_debug:
	$(CC) $(PARSER) $(CFLAGS_DEBUG) $(PARSER_BIN)

