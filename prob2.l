%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
%}

variable    [a-zA-Z_][a-zA-Z_0-9]*
operators   [+\-/*%]
floats      -?([0-9]+)?\.[0-9]+(E[-]?[0-9]+)?|[0-9]+
SC          \;
Assign      "="|"+="|"-="|"/="|"*="
In	    [-]?\+\+   
Dc	    \-\-   
leftParen   \(
rightParen  \)

%%

{In} { 
        printf("%s ", yytext);
        yylval.str = strdup(yytext); // Allocate memory for increment token
        return INC;
}

{Dc} { 
        printf("%s ", yytext);
        yylval.str = strdup(yytext); // Allocate memory for decrement token
        return DEC;
}

{variable}  { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // Allocate memory for variable token
                return VAR;
}
{Assign}    { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // Allocate memory for assignment token
                return ASSIGN;
             }
{operators} { 
                printf("%s ", yytext);
                return yytext[0]; // Change to return appropriate token types
             }

{floats}    { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // Allocate memory for float token
                return Floats;
             }
{SC}        { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // Allocate memory for statement terminator
                return SC;
             }

{leftParen} { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // Allocate memory for left parenthesis
                return LP;
             }
{rightParen} { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // Allocate memory for right parenthesis
                return RP;
             }
[\t\n ]+    ;
.            { 
                fprintf(stderr, "Unrecognized character: %s \n", yytext);
                return yytext[0]; // You may want to handle errors differently
             }

%%
int yywrap() {
    return 1;
}
