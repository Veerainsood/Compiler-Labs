%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

INT [0-9]+
FLOAT [0-9]+"."[0-9]+

/* Rule Section */
%%
{INT}  return Int;
{FLOAT}  return Float;
"i" return I ;
"+" return add ;
"-" return sub;
";" return scol;
[ \t\n]+     {};      /* ignore white space */
.           {return yytext[0];}; /* ignore all other characters */

%%

int yywrap()
{
return 1;
}
