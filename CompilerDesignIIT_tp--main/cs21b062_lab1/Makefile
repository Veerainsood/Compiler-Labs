CFLAGS=-g -DDEBUG 
CC=gcc

mylexer: lex.yy.c 
	$(CC) $(CFLAGS) lex.yy.c -lfl -o mylexer  #here we have files 

lex.yy.c: ${fname}
	lex ${fname}   #here just change the input file name 

clean: 
	rm -f *.o lex.yy.c