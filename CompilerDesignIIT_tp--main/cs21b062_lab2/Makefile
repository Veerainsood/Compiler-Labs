CFLAGS=-g -DDEBUG 
CC=gcc



# C_files=$(wildcard *.c)
# O_files=$(C_file.s:.c=o)

# test: $(O_files)
#   ./mylexer $(C_files) -o
 
mylexer: lex.yy.c 
	$(CC) $(CFLAGS) lex.yy.c -lfl -o mylexer  #here we have files 

lex.yy.c: prob1.l
	flex prob1.l   #here just change the input file name 

clean: 
	rm -f *.o lex.yy.c *.txt