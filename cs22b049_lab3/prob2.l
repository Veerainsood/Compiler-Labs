%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h" 
%}

Float 	[0-9]+|[0-9]*\.[0-9]+
PLUS	\+
MINUS   -
IOTA	i

%%

{Float}  { yylval.Floats = atof(yytext); return Float;}
{PLUS}	 { yylval.Chars = yytext[0]; return PLUS;}
{MINUS} { yylval.Chars = yytext[0];return MINUS;}
{IOTA}    { yylval.Chars = yytext[0]; return IOTA;} 
[ \t\n]+  ;  
"$" 	{return 0;}
.	{ return yytext[0];}
%%

int yywrap() {
    return 1;  
}



