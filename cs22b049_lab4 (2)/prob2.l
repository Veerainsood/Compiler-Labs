%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h" 
%}

Num 	[0-9]+
Month31 [jJ]"an"|[mM]"arch"|[mM]"ay"|[jJ]"ly"|[aA]"ugust"|[oO]"ctober"|[dD]"ecember"
Month30 [aA]"pril"|[jJ]"une"|[sS]"eptember"|[nN]"ovember"
Febs	[fF]"eb"
MINUS 	-

%%

{Num} 	{	
		if((strlen(yytext)==2 && atoi(yytext) <32 && atoi(yytext) >0) || strlen(yytext)==4)
		{
			yylval.Ints = atoi(yytext); return Num;
		}
	}
{Month31} {yylval.str = yytext; return Month31;}
{Month30} {yylval.str = yytext; return Month30;}
{Febs}	{yytext[3]='\0';yylval.str = yytext;return Feb;}
{MINUS}	{yylval.str = yytext; return MINUS;}
[ \t\n]+ ;
.	{ return yytext[0];}
%%
int yywrap()
{
	return 1;
}
