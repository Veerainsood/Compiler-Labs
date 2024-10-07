parser: y.tab.c y.tab.h lex.yy.c
	gcc -w y.tab.c lex.yy.c -o -ll -o parser

lex.yy.c: ${fname}.l
	lex ${fname}.l

y.tab.c: ${fname}.y
	bison -v -d ${fname}.y --debug -o y.tab.c

clean:
	rm y.* parser lex.yy.c
