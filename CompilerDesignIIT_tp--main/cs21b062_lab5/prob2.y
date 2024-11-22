//yacc program to check valid dates 
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
  int yylex();
  int yyerror(char *);
  extern FILE *yyin;
  int flag=0;
%}
  
%token DD MM YYYY

%%
slist : 	date ';' {printf("\tAccepted\n\n");} slist | {printf("\n\n\tCompleted..!\n");} ;

date  : DD MM YYYY {if($1>31 || $1<1 || $3<1 || $3>9999)
				  {
					flag=1;
				  }
				  else if($2=="Feb") //checking for leap year 
				  {
					if($1>29)
					{
					  flag=1;
					}
					else if($1==29) //checking for leap year
					{
					  if($3%4!=0) //checking for leap year
					  {
						flag=1;
					  }
					  else if($3%100==0 && $3%400!=0)
					  {
						flag=1;
					  }
			
					}
				  }
				  else if($2=="Apr" || $2=="Jun" || $2=="Sep" || $2=="Nov") //checking for months with 30 days
				  {
					if($1>30)
					{
					  flag=1;
					}
				  }
				  else
				  {
					flag=0;
				  }
				}
	;

%%

int yyerror(char *s){
  printf("\n\nError: %s\n", s);
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
