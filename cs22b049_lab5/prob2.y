%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYDEBUG 1
extern int yydebug;
extern int yylex();
int yyerror(char*);
int eflag=0;
extern FILE* yyin;
%}

%union{
    int INT;
    float FLOAT;
    char Oprtr;
    char* variable;
    struct Node* nodee;
}

%token <INT> INTs
%token <variable> VAR 
%token <FLOAT> FLOATs
%token <Oprtr> DIV MULT MOD ADD SUB OPENBRACK CLOSEBRACK ASSIGN UMINUS 



%left ADD SUB
%left MUL DIV MOD
%right UMINUS
%right ASSIGN


%%

Exp: ArithExpr ';' 
    {
        printf("%-40s\n" , "accepted\n");
        yyclearin;
    } Exp
    | AssignExpr ';'  
    {
        printf("%-40s\n" , "accepted\n");
        yyclearin;
    } Exp
    | {
        printf("Done\n");
        yyclearin;
    }
    ;

AssignExpr: VAR ASSIGN ArithExpr 
            ;

ArithExpr:  TERM ADD ArithExpr  
            |
            TERM SUB ArithExpr   
            |
            TERM
            |
            SUB TERM %prec UMINUS 
            // |ArithExpr ADD  error { printf("\t\t\t%-40s\n", "Rejected Due to Nothing on RHS of +\n"); eflag = 1; yyerrok;yyclearin;}
            // |ArithExpr SUB  error { printf("\t\t\t%-40s\n","Rejected Due to Nothing on RHS of -\n"); eflag = 1; yyerrok;yyclearin;}
            ;
TERM:   FACTOR MULT TERM   
        | 
        FACTOR DIV TERM  
        | 
        INTEGER_EXP MOD TERM   
        | 
        FACTOR 
        ;

INTEGER_EXP:    INTEGER_TERM ADD INTEGER_EXP 
                |
                INTEGER_TERM SUB INTEGER_EXP  
                |
                INTEGER_TERM
                // INTEGER_EXP ADD error { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of +\n"); eflag = 1; yyerrok;yyclearin;}
                // |
                // INTEGER_EXP SUB error { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of -\n"); eflag = 1; yyerrok;yyclearin;}
                ;

INTEGER_TERM:   INT_FACTOR MULT INTEGER_TERM %prec MULT
                |
                INT_FACTOR DIV INTEGER_TERM %prec DIV
                | 
                INT_FACTOR MOD INTEGER_TERM  %prec MOD
                | 
                INT_FACTOR 
                // INTEGER_TERM INT_FACTOR ';' error { printf("\t\t\t%-40s" ,"Rejected Due to no operator present *\n"); eflag = 1; yyerrok;yyclearin;}
                // |
                // INTEGER_TERM MULT error { printf("%-60s","Rejected Due to Nothing on RHS of *\n"); eflag = 1; yyerrok;yyclearin;}
                ;

INT_FACTOR: OPENBRACK INTEGER_EXP CLOSEBRACK  
            | INTs
            | VAR 
            // | FLOATs error { printf("\t\t\t%-40s\n","Rejected Due to Float cannot be used for modulus operator \n"); eflag = 1; yyerrok;yyclearin;}
            // | OPENBRACK INTEGER_EXP error ';' { printf("\t\t\t%-40s\n","Rejected Due to Closing Bracket not found"); eflag = 1; yyerrok;yyclearin;}
            // | OPENBRACK error { printf("\t\t\t%-40s\n" ,"Rejected Due to NO Integer found after opening bracket \n"); eflag = 1; yyerrok;yyclearin;}
            ;

FACTOR: OPENBRACK ArithExpr CLOSEBRACK 
        |
        FLOATs 
        |
        VAR
        |
        INTs 
        // OPENBRACK ArithExpr error { printf("\t\t\t%-40s\n","Rejected Due to Closing Bracket not found \n"); eflag = 1; yyerrok;yyclearin;}
        // | 
        // OPENBRACK error { printf("\t\t\t%-40s\n"," Rejected Due to NO Integer found after opening bracket \n"); eflag = 1; yyerrok;yyclearin;}
        ;
            
%%
int yyerror(char* s) {
    return 0;
}

int main(int arg, char* argc[])
{
    FILE* inpt;
    if(arg>1)
    {
        inpt = fopen(argc[1],"r");
        if(inpt)
        {
            yyin = inpt;
        }
    }

    yyparse();
    if (inpt) {
        fclose(inpt);
    }
    
    return 0;
}
