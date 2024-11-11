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
arrayBrackRight    "]"
arrayBrackLeft    "["
IF          "if"
WHILE          "while"
ELSE        "else"
RELOP       \<|\>|">="|"<="|"!="|"=="
Booland     "&&"
Boolor     "||"
DtypeFlt       "float"
DtypeInt       "int"
DtypeChar      "char"
Comma          ","
FOR         "for"
%%

{Comma}  {
            yylval.str = strdup(yytext);
            return COMMA;
         }

{IF}  {
         // printf("%s ", yytext);
         yylval.str = strdup(yytext);
         return If;
}
{FOR}  {
      // printf("%s ", yytext);
      yylval.str = strdup(yytext);
      return For;
}
{WHILE}  {
         // printf("%s ", yytext);
         yylval.str = strdup(yytext);
         return While;
}
{ELSE}  {
         // printf("%s ", yytext);
         yylval.str = strdup(yytext);
         return Else;
}
{In} { 
      //   printf("%s ", yytext);
        yylval.str = strdup(yytext); 
        return INC;
}

{Dc} { 
      //   printf("%s ", yytext);
        yylval.str = strdup(yytext); 
        return DEC;
}

{DtypeFlt} { 
   //   printf("%s ", yytext);
      yylval.str = strdup(yytext); 
      return Float;
}

{DtypeInt} { 
   //   printf("%s ", yytext);
      yylval.str = strdup(yytext); 
      return Int;
}
{DtypeChar} { 
   //   printf("%s ", yytext);
      yylval.str = strdup(yytext); 
      return Char;
}

{variable}  { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // variable token
                return VAR;
}
{Assign}    { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // assignment token
                return ASSIGN;
             }
{Booland}   { 
               // printf("%s ", yytext);
               yylval.str = strdup(yytext);
               return BoolAnd; 
             }
{Boolor}    { 
               // printf("%s ", yytext);
                yylval.str = strdup(yytext);
               return BoolOr;  
             }
{operators}    { 
               //  printf("%s ", yytext);
                return yytext[0]; 
             }
{RELOP}      { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext);
                return RELOP; 
             }
{floats}    { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // float token
                return Floats;
             }
{SC}        { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // statement terminator
                return SC;
             }

{leftParen} { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // left parenthesis
                return LP;
             }
{rightParen} { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // right parenthesis
                return RP;
             }
{curlLeft} { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // left parenthesis
                return CL;
             }
{curlRight} { 
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // right parenthesis
                return CR;
             }
{arrayBrackRight} { 
               // printf("Detetect");
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // left parenthesis
                return arrRP;
             }
{arrayBrackLeft} { 
               // printf("Detetect");
               //  printf("%s ", yytext);
                yylval.str = strdup(yytext); // right parenthesis
                return arrLP;
             }
[\t ]+    ;
[\n]         {
                  printf("\n");
             }
.            { 
                fprintf(stderr, "Unrecognized character: %s \n", yytext);
                return yytext[0];
             }

%%
int yywrap() {
    return 1;
}
