%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}
  
%token Int Float I add sub scol


 //rules section for checking complex number
%%

slist : C_E scol {printf("VALID\n");} slist |  error { printf("INVALID\n"); } scol slist | {printf("\n\nCompleted..!\n");} ;
      ;

C_E : Img 
    | Real add Img 
    | Real sub Img  ;

Real: Int 
    | sub Int
    | sub Float
    | Float ; 

Img : Real I 
    | I 
    | I Real ;
%%


int yyerror(char *s){
    return 0;
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}
