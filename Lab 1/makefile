
fname ?= default 
$(fname): $(fname).l
	rm -f lexer
	lex $(fname).l
	gcc lex.yy.c  -o lexer -ll
	rm -f lex.yy.c 
	
clean:
	rm -f lexer lex.yy.c *.txt
	

