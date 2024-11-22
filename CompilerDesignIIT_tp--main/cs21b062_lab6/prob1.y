%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}

%token ID NUMBER RNUM add sub mul dIV eql obr cbr scol Inc Dec eol eof
%left  add sub 

/* %union
{

}
%type <> slist */

%%

slist   : 	stmt scol {printf("\tVALID \n" );} slist | error{printf("\tINVALID\n" );}  scol slist  |{printf("\n\n\tCompleted..!\n");};
stmt    :   ID eql Ea | incF | incE 
Ea      :   E | add E | sub E |  
E       :   T add E | T sub E | T 
T       :   T dIV F | T mul E | F
F       :   Elem | sub Elem | obr E cbr | incF | incE 
incF    :   Inc ID | Dec ID
incE    :   ID Inc |  ID Dec 
Elem    :   NUMBER|ID|RNUM

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

