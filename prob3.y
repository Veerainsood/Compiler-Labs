%{
    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    #include "y.tab.h"

    int yyerror(char*);
    extern FILE* yyin;
    int eflag = 0;  // Ensure correct comparison with == in Assignments rule
    extern int yylex();
    int yydebug=0;
%}

%union{
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
%nonassoc INC DEC  /* For handling increment and decrement */

%%
S:	Assignments S 
    | { printf("!!Done\n"); }
    ;

Assignments:    VAR ASSIGN Expr SC 
                {
                    if (eflag == 0)  // Fix this comparison
                    {
                        printf("\t\t Accepted!\n");
                    }
                    else if(eflag==1){
                        printf("  float not to be used with modulo symbol\n");
                    }
                    else
                    {
                        printf("\t\t Operands not found\n");
                    }
                    eflag=0;
                }
                |
                error SC 
                {
                    yyerror("");
                    printf("\t\tExpression not assignable...\n");
                    yyerrok;
                    yyclearin;
                } 
                ;
Op: '+'|'-'|'/'|'*'|'%';
Expr:           Expr '+' Expr
                | 
                Expr '-' Expr
                |
                Expr '*' Expr
                |
                Expr '/' Expr
                |
                Expr '%' Expr
                {
                    if(strchr($3,'.')==0 || strchr($3,'.')==0)
                    {
                        eflag=1;
                    }
                    else
                    {
                        eflag=0;
                    }
                }
                |
                Expr Op
                {
                    eflag=2;
                }
                |
                Fact
                ;

Fact:           VAR INC  /* Postfix increment */
                |'-' VAR INC{;}
                | VAR DEC  /* Postfix decrement */
                | '-' VAR DEC  /* Postfix decrement */{;}
                | INC VAR  /* Prefix increment */
                | '-' INC VAR  /* Prefix increment */{;}
                | DEC VAR  /* Prefix decrement */
                | VAR C
                | '-' VAR C
                {;}
                | Floats C
                | '-' Floats C
                {;}
                | Floats INC error
                {
                	yyerror("");
                    printf("\t\tcannot increment a constant\n");
                    yyerrok;
                    yyclearin;
                }
                | Floats DEC error
                {
                	yyerror("");
                    printf("\t\tcannot increment a constant\n");
                    yyerrok;
                    yyclearin;
                }
                | DEC Floats error
                {
                	yyerror("");
                    printf("\t\tcannot increment a constant\n");
                    yyerrok;
                    yyclearin;
                }
                | INC Floats error
                {
                	yyerror("");
                    printf("\t\tcannot increment a constant\n");
                    yyerrok;
                    yyclearin;
                }
                | LP Expr RP
                | LP Expr error
                {
                	yyerror("");
                    printf("\t\tno ) detected after (\n");
                    yyerrok;
                    yyclearin;
                }
                ;
C:      VAR error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n");
            yyerrok;
            yyclearin;
        }
        |
        Floats error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n");
            yyerrok;
            yyclearin;
        }
        |;
                
%%
int yyerror(char* err) {
    return 0;
}

int main(int arg, char* files[]) {
    // yydebug =1;
    if (arg > 1) {
        FILE* inp = fopen(files[1], "r");
        if (inp != NULL) {
            yyin = inp;
        }
    }
    yyparse();
    fclose(yyin);
    return 0;
}

