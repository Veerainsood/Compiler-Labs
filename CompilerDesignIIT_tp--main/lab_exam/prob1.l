%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

INT [0-9]
MONTH (Jan|Feb|Mar|Apr)

/* Rule Section */
%%
{INT}{INT}|{INT}   { yylval.dd = atoi(yytext)  ; return day;};
{INT}{INT}{INT}{INT}   { yylval.yyyy = atoi(yytext) ;return year;};
{MONTH}       { strcpy(yylval.mm , yytext ); return month;};
[ \t\n]+     {};      /* ignore white space */
.           {return yytext[0];}; /* ignore all other characters */

%%

int yywrap()
{
return 1;
}