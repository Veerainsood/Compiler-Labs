%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "y.tab.h"
int yylex();
extern int yylineno;
extern FILE* yyin;
int eflag=0;
int flagError=0;
int yyerror(char*);
%}

%token STR; 

%union
{
	char* str;
}

%type <str> STR

%%
strlist:STR ';'   
	{	
		int lena = 0;
		int lenb = 0;
		int lenc = 0;
		char* strng = $1;
		int i=0,len = strlen($1);
		while(i<len && strng[i] =='a')
		{
			lena++;
			i++;				
		}
		
		while(i<len && strng[i] =='b')
		{
			lenb++;
			i++;
		}
		
		while(i<len && strng[i] =='c')
		{
			lenc++;
			i++;
		}
		if(lena!=lenb && lenb!=lenc)
		{
			printf("%s \t\t|\t Accepted\n", $1);
		}
		else
		{
		    printf("%s \t\t|\t Rejected number of a's and b's and c's are not different\n", $1);
		    flagError=1;
		}
	}
	strlist
	|error ';' {
			eflag=1;
			yyerrok;
			if(flagError==0)
			{
				printf("\t\t|\t There are some unknown chars in this\n");
			}
		} strlist
	;

%%

int yyerror(char* s)
{
    return 0;
}

int main(int argc, char* arguments[])
{
	FILE* inp;
	if(argc>1)
	{	
		printf("---------------------------------------------------\n");
		inp = fopen(arguments[1],"r");
		if(inp)
		{
			yyin =  inp;
		}
		else
		{
			printf("Please try again runnig the command as ./parser \$fname");
		}
	}
	yyparse();
	fclose(inp);
	return 0;
}
