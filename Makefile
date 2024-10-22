<<<<<<< HEAD
parser: y.tab.c lex.yy.c y.tab.h
	gcc -w y.tab.c lex.yy.c -ll -o parser
=======
parser: y.tab.c y.tab.h lex.yy.c
	gcc  -g -w y.tab.c lex.yy.c -o -ll -o parser

>>>>>>> main
lex.yy.c: ${fname}.l
	lex ${fname}.l

y.tab.c: ${fname}.y
<<<<<<< HEAD
	yacc --debug -v -d -t --verbose ${fname}.y 
=======
	bison -v -d ${fname}.y --debug -o y.tab.c
>>>>>>> main

clean:
	rm y.* parser lex.yy.c
