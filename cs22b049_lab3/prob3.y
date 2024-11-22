%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
extern FILE* yyin;
int eflag = 0;
int flag = 0;
%}

%token Num Month31 Month30 Feb MINUS

%union
{
    int Ints;
    char* str;
}

%type <Ints> Num
%type <str> Month31
%type <str> Month30
%type <str> Feb
%type <str> MINUS 

%%

Dates:   Num MINUS Month31 MINUS Num ';' 
    {
        if($1 <= 0 || $1 > 31 || $5 < 0 || $5 > 9999)
        {
            flag = 1;
        }
        (flag == 1) ? printf("%d - %s - %d \t\t\t|\t\t Rejected\n", $1, $3, $5) : printf("%d - %s - %d \t\t|\t Accepted\n", $1, $3, $5);
        flag = 0;
    } Dates 
    |
    Num MINUS Month30 MINUS Num ';' 
    {
        if($1 <= 0 || $1 > 30 || $5 < 0 || $5 > 9999 )
        {
            flag = 1;
        }
        (flag == 1) ? printf("%d - %s - %d \t\t\t|\t\t Rejected\n", $1, $3, $5) : printf("%d - %s - %d \t\t|\t Accepted\n", $1, $3, $5);
        flag = 0;
    } Dates
    |
    Num MINUS Feb MINUS Num ';' 
    {	
        if($1 <= 0 || $1 > 29 || $5 < 0 || $5 > 9999 )
        {
            flag = 1;
        }
        else if ($1 == 29 && ($5 % 4 != 0 || ($5 % 100 == 0 && $5 % 400 != 0)))
	{
		flag = 1;
	}
        (flag == 1) ? printf("%d - %s - %d \t\t|\t Rejected\n", $1, $3, $5) : printf("%d - %s - %d \t\t|\t Accepted\n", $1, $3, $5);
        flag = 0;
    } Dates
    |error ';' { printf("\t\t\t\t|\t Rejected\n"); eflag = 1; } Dates
    |{ printf("\t\t\t\t\t Done\n"); }
    ;

%%

int yyerror(char* s) {
    return 0;
}

int main(int argc, char* argv[])
{
    if(argc > 1)
    {   
        printf("---------------------------------------------------\n");
        FILE* input = fopen(argv[1], "r");
        if(input)
            yyin = input;
    }
    yyparse();
    return 0;
}

