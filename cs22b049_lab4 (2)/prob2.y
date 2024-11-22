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
        char* error = checkYearDay($1,$5);
        (error != NULL) ?printf("%d - %s - %d %s", $1, $3, $5, error) : printf("%d - %s - %d \t\t|\t Accepted\n", $1, $3, $5);
        flag=0;
    } Dates 
    |
    Num MINUS Month30 MINUS Num ';' 
    {
        char* error = checkYearDay($1,$5);
        (error != NULL) ? printf("%d - %s - %d %s", $1, $3, $5, error) : printf("%d - %s - %d \t\t|\t Accepted\n", $1, $3, $5); 
        flag=0;
    } Dates
    |
    Num MINUS Feb MINUS Num ';' 
    {	
        if($1 <= 0 || $1 > 29 )
        {
            flag = 1;
            printf("%d - %s - %d \t\t|\t Rejected Due to day issues\n", $1, $3, $5);
        }
        else if($5 < 0 || $5 > 9999)
        {
        	printf("%d - %s - %d \t\t|\t Rejected Due to year issues\n", $1, $3, $5);
        } 
        else if ($1 == 29 && ($5 % 4 != 0 || ($5 % 100 == 0 && $5 % 400 != 0)))
	{
		flag = 1;
		printf("%d - %s - %d \t\t|\t Rejected Due to NON LEAP YEAR\n", $1, $3, $5);
	}
        (flag == 1) ? : printf("%d - %s - %d \t\t|\t Accepted\n", $1, $3, $5);
        flag = 0;
    } Dates
    |error ';' { printf("\t\t\t\t|\t Rejected Due to invalid format\n"); eflag = 1; yyerrok;} Dates
    |{ printf("\t\t\t\t\t Done\n"); }
    ;

%%
char* checkYearDay(int day, int year)
{
	if(day <= 0 || day > 31 )
        {
            return "\t\t\t|\t Rejected Due to day issues\n";
        }
        else if(year < 0 || year > 9999)
        {
        	return "\t\t\t|\t Rejected Due to year issues\n";
        }
        return NULL;
}
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

