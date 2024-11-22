%{
/* Definition section */
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}

Months { "Jan"| "Feb" |"Mar"| "Apr" | "May" | "Jun" | "Jul"| "Aug" | "Sep" | "Oct" | "Nov" | "Dec" }


/* Rule Section */
%%
[0-9][0-9]? { yylval=atoi(yytext);  return DD;}
{Months} { yylval=atoi(yytext); return MM;}
[0-9][0-9][0-9][0-9] { yylval=atoi(yytext);  return YYYY;}
[;] {return ';';}
[-] {return '-';}
             
[\t] ;
[\n] return 0;
. return yytext[0];

%%

int yywrap()
{
return 1;
}
