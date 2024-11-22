parser: y.tab.c y.tab.h lex.yy.c
	gcc  -g -w y.tab.c lex.yy.c -o -ll -o parser

lex.yy.c: ${fname}.l
	lex ${fname}.l

y.tab.c: ${fname}.y
	yacc -v -d ${fname}.y --debug -o y.tab.c

clean:
	rm y.* parser lex.yy.c
