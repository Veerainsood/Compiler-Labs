%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"

    int yyerror(char*);
    extern FILE* yyin;
    int eflag = 0;  // Error flag for certain expressions
    extern int yylex();
    int yydebug = 0;

    int count = 0;  // Counter for temporary variables
%}

%union {
    char* str;
}

%token<str> VAR
%token<str> Floats
%token<str> ASSIGN
%token<str> SC
%token<str> LP
%token<str> RP
%token<str> INC 
%token<str> LEQ 
%token<str> GEQ
%token<str> DEC 
%type<str> Expr
%type<str> Fact
%left '+' '-'
%left '*' '/' '%'
%nonassoc INC DEC  

%%
S: Assignments S
    | { printf("!!Done\n"); }
    ;

Assignments: 
    VAR ASSIGN Expr SC 
    {
        if (eflag == 0) 
        {
            printf("\t\t Accepted!\n\n");

            char ans[100];  // Use a local buffer instead of dynamically creating it
            // Properly format the TAC output for assignment
            sprintf(ans, "t%d = %s %s %s;\n", count++, $1, $2, $3);
            printf("%s", ans);
        }
        else if(eflag == 1)
        {
            printf("  float not to be used with modulo symbol\n\n");
        }
        else
        {
            printf("\t\t Operands not found\n\n");
        }
        eflag = 0;
        count = 0;
    }
    | error SC 
    {
        yyerror("");
        printf("\t\tExpression not assignable...\n\n");
        yyerrok;
        yyclearin;
    }
    ;

Expr: Expr '+' Expr 
    { 
        char temp[100];
        // Generate TAC for addition
        sprintf(temp, "t%d = %s + %s;\n", count++, $1, $3);
        $$ = strdup(temp);
    }
    | Expr '-' Expr 
    { 
        char temp[100];
        // Generate TAC for subtraction
        sprintf(temp, "t%d = %s - %s;\n", count++, $1, $3);
        $$ = strdup(temp);
    }
    | Expr '*' Expr 
    { 
        char temp[100];
        // Generate TAC for multiplication
        printf("t%d = %s * %s;\n", count++, $1, $3);
        $$ = strdup(temp);
    }
    | Expr '/' Expr 
    { 
        char temp[100];
        // Generate TAC for division
        printf("t%d = %s / %s;\n", count++, $1, $3);
        $$ = strdup(temp);
    }
    | Expr '%' Expr
    {
        if (strchr($1, '.') == NULL && strchr($3, '.') == NULL)
        {
            char temp[100];
            // Generate TAC for modulo
            printf("t%d = %s %% %s;\n", count++, $1, $3);
            $$ = strdup(temp);
        }
        else
        {
            eflag = 1;  // Set error flag if modulo is used with floats
        }
    }
    | Fact
    ;


Fact: VAR INC { 
        
        printf("t%d = %s;\n%s = %s + 1;\n", count++, $1, $1, $1); 
    } 
    | VAR DEC { 
        $$ = (char*) malloc(256);
        printf("t%d = %s;\n%s = %s - 1;\n", count++, $1, $1, $1); 
    } 
    | INC VAR { 
        $$ = (char*) malloc(256);
        printf("%s = %s + 1;\nt%d = %s;\n", $2, $2, count++, $2); 
    }
    | DEC VAR { 
        $$ = (char*) malloc(256);
        printf("%s = %s - 1;\nt%d = %s;\n", $2, $2, count++, $2); 
    }
    | VAR { 
        $$ = (char*) malloc(256);
        printf("t%d = %s;\n", count++, $1); 
    }
    | Floats { 
        $$ = (char*) malloc(256);
        printf("t%d = %s;\n", count++, $1); 
    }
    | LP Expr RP { ; }
    ;

%%
int yyerror(char* err) {
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        FILE* inp = fopen(argv[1], "r");
        if (inp != NULL) {
            yyin = inp;
        }
    }

    yyparse();
    fclose(yyin);
    return 0;
}
