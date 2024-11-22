parser: y.tab.c lex.yy.c y.tab.h
	gcc -w y.tab.c lex.yy.c -ll -o parser
lex.yy.c: $(fname).l
	lex $(fname).l
y.tab.c: $(fname).y
	bison -d -t $(fname).y -o y.tab.c
clean:
	rm -f parser y.tab.c lex.yy.c tab.h y.output y.tab.h
