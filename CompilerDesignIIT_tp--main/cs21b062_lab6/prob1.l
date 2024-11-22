%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

alpha [A-Za-z_]
digit [0-9]
%%
{alpha}({alpha}|{digit})*    	    return ID;
{digit}+ 							return NUMBER;
{digit}+\.{digit}+                  return RNUM;  
"++"                                return Inc;
"--"                                return Dec;
"+"      							return add;
"-"      							return sub;
"*"	 								return mul;
"/"     							return dIV;
"=" 								return eql;
"("									return obr;
")"									return cbr;
";"									return scol;
[\t\n ] ;      /* ignore white space and new line*/

"$"		{ return 0; }
.  		{ return yytext[0]; }
%%
