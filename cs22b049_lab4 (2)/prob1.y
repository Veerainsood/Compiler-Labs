%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
int eflag = 0;
extern FILE * yyin;
extern int yylineno;
//int yydebug =1;
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
		|REAL MINUS IMG ';'{printf("%f %c %fi \t|\t Accepted\n",$1,$2,$3);}  ComplexList
		|error ';' { printf("\t\t\t|\t Rejected invalid format\n");eflag=1; yyerrok; }
		|{printf("\t\t\t|\t Done\n");} 
		;
REAL: 	Float {$$ = (float)$1;}
	|MINUS Float {$$ = -(float)$2;}
	|error IOTA ';'{printf("\t\t\t|\t Float Missing in start\n");eflag=1;yyclearin; yyerrok;}
	;
IMG: 	Float IOTA {$$ = (float)$1;}
	|IOTA Float {$$ = (float)$2;}
	|Float error { 
			printf("\t\t\t|\t Rejected Iota not there with Float %f\n",$1);
			eflag = 1;
			yyerrok;
			}
	|IOTA error  { 
		printf("\t\t\t|\t Rejected Float not there with Iota %c \n", $1);
		eflag = 1;
		yyerrok;
		} 
	;

%%
int yyerror(char*s){ 
	return 0;
}

int main(int argc, char* argv[])
{
	FILE* input;
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

