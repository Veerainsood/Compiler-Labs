%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
 
/* definitions declared in the bison file */
%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"="     { return ASSIGN; }
"--"    { return DEC; }
"++"    { return INC; }
";"     { return SEMICOLON; }
[a-zA-Z][a-zA-Z0-9]*   { strcpy(yylval.lexeme, yytext) ; return IDENTIFIER; }
[0-9]+  { yylval.ival = atoi(yytext) ;return INTEGER; }
[ \t\n]+     {};     
.           {return yytext[0];}; 
<<EOF>>     { return 0; }

%%