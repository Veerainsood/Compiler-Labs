# parser: y.tab.c lex.yy.c y.tab.h
# 	gcc -g -w y.tab.c lex.yy.c -ll -o parser
lexer: lex.yy.c
	gcc -o lexer lex.yy.c -ll
lex.yy.c: ${fname}.l
	lex ${fname}.l
# y.tab.c: ${fname}.y
# 	yacc --debug -v -d -t --verbose ${fname}.y 
clean:
	rm y.* parser lex.yy.c