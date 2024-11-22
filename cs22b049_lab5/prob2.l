%{
#include "y.tab.h"

%}

E		    [Ee]
FLOAT  		([0-9])*(\.[0-9]+)(E[+-]?[0-9]+)?
INT		    [0-9]+
VAR_        [-]?[a-zA-Z_]([a-zA-Z_0-9])*
DIV		    [\/]
MULT		[\*]
MOD		    [\%]
ADD 		[\+]
SUB		    [\-]
OPENBRACK	[\(]
CLOSEBRACK	[\)]
ASSIGN      [\=]

%%

{VAR_}          {printf("%s ",yytext);yylval.variable = strdup(yytext);return VAR;}
{FLOAT}	        {printf("%g ",atof(yytext));yylval.FLOAT = atof(yytext);return FLOATs;}
{INT}	        {printf("%d ",atoi(yytext));yylval.INT = atoi(yytext);return INTs;}
{DIV}	        {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return DIV;}
{MULT}	        {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return MULT;}
{MOD}	        {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return MOD;}
{ADD}	        {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return ADD;}
{SUB}	        {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return SUB;}
{OPENBRACK}	    {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return OPENBRACK;}
{CLOSEBRACK}	{printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return CLOSEBRACK;}
{ASSIGN}	    {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return ASSIGN;}
";"             {printf("%c ",yytext[0]);yylval.Oprtr = yytext[0];return ';';}
[ \t\n]+ ;
.	{ return yytext[0];}

%%

int yywrap() {
    return 1;
}


