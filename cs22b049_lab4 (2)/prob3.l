%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "y.tab.h"
%}

ws [ \t\n]
%%
a*b*c*		{	
			yylval.str = yytext;
			return STR;
		}
ws+	;
"$" 	{return 0;}
.	{return yytext[0];}
%%
int yywrap(){
	return 1;
}
