%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
		
%}

VAR 	[a-zA-Z_][a-zA-Z_0-9]*
OL	"("
OR	")"
CL	"{"
CR	"}"
VOID "void"
FLT	"float"
INT	"int"
SC	";"
Com	","
Oprt	[\+|-|\*|\/|\%]
%%

{OL} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Ol;
}
{OR} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Or;
}
{CL} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Cl;
}
{CR} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Cr;
}
{VOID} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Void;
}
{FLT} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Flt;
}
{INT} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Int;
}
{SC} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Sc;
}
{VAR} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Var;
}
{Com} 	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Com;
}
{Oprt}	{
	printf("%s ",yytext);
	yylval.str = strdup(yytext);
	return Opt;
}

%%
int main(int argv,char* argc[])
{
	FILE* inpt;
	if(argv>=2)
	{
		inpt = fopen(argc[1],"r");
		if(inpt!=NULL)
		{
			yyin = inpt;
			yylex();
			fclose(inpt);
		}
	}
	return 0;
}