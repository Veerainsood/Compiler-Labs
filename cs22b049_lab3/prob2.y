%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
int eflag = 0;
extern FILE * yyin;
FILE* input, *output;
%}

%token Float IOTA PLUS MINUS
%union
{
	float Floats;
	char Chars;
}
%type <Floats> Float
%type <Chars> IOTA
%type <Chars> PLUS
%type <Chars> MINUS
%type <Floats> IMG
%type <Floats> REAL
%%

ComplexList:	REAL PLUS IMG ';' {printf("%f %c %fi \t|\t Accepted\n",$1,$2,$3);} ComplexList
		| REAL MINUS IMG ';'{printf("%f %c %fi \t|\t Accepted\n",$1,$2,$3);}  ComplexList  
		| error ';' { printf("\t\t\t|\t Rejected\n"); eflag = 1; } ComplexList 
		|{printf("\t\t\t|\t Done\n");} 
		;
REAL: 	Float { $$ = (float)$1;}
	| MINUS Float {$$ = -(float)$2;}
	;
IMG: 	Float IOTA { $$ = (float)$1;}
	| IOTA Float { $$ = (float)$2;}
	;

%%
int yyerror(char*s){
	return 0;
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{	
		printf("---------------------------------------------------\n");
		input = fopen(argv[1], "r");
		if(input)
			yyin = input;
	}
	yyparse();
	fclose(input);

	return 0;
}

