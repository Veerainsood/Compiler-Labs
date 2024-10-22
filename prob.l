%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    //
%}

variable    [a-zA-Z_][a-zA-Z_0-9]*
operators   [+\-/*%\&\|\^]
floats      -?([0-9]+)?\.[0-9]+(E[-]?[0-9]+)?|[0-9]+
SC          ";"
Assign      "="|"+="|"-="|"/="|"*="
In	         [-]?\+\+   
Dc	         \-\-   
leftParen   "("
rightParen  \)
curlLeft    \{
curlRight    \}
IF          "if"
RELOP       \<|\>|">="|"<="
BoolAnd     "&&"
BoolOr     "||"
%%

{IF}  {
         printf("%s ", yytext);
         yylval.str = strdup(yytext);
         return If;
}

{In} { 
        printf("%s ", yytext);
        yylval.str = strdup(yytext); 
        return INC;
}

{Dc} { 
        printf("%s ", yytext);
        yylval.str = strdup(yytext); 
        return DEC;
}

{variable}  { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // variable token
                return VAR;
}
{Assign}    { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // assignment token
                return ASSIGN;
             }
{operators}    { 
                printf("%s ", yytext);
                return yytext[0]; 
             }
{RELOP}      { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext);
                return RELOP; 
             }
{BoolAnd}   { 
               printf("%s ", yytext);
               return yytext[0]; 
             }
{BoolOr}    { 
               printf("%s ", yytext);
               return yytext[0]; 
             }

{floats}    { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // float token
                return Floats;
             }
{SC}        { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // statement terminator
                return SC;
             }

{leftParen} { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // left parenthesis
                return LP;
             }
{rightParen} { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // right parenthesis
                return RP;
             }
{curlLeft} { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // left parenthesis
                return CL;
             }
{curlRight} { 
                printf("%s ", yytext);
                yylval.str = strdup(yytext); // right parenthesis
                return CR;
             }
[\t\n ]+    ;
.            { 
                fprintf(stderr, "Unrecognized character: %s \n", yytext);
                return yytext[0];
             }

%%
int yywrap() {
    return 1;
}
