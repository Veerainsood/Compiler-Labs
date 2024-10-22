%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    #define SIZE 100
    int yyerror(char*);
    extern FILE* yyin;
    int eflag = 0;  // Error flag for certain expressions
    extern int yylex();
    int yydebug = 0;
    
    int count = 0;  // Counter for temporary variables
    char* finalAssignments[SIZE]; 
    char* intermediate[SIZE];
    int count2=0;
	int blockVar =0;
    int genBlockLabel()
    {
        return blockVar++;
    }
    void handleClear()
    {
        for (int i = 0; i < 100; i++) {
            free(finalAssignments[i]);
            free(intermediate[i]);
        }
        for (int i = 0; i < 100; i++) {
            finalAssignments[i] = (char*)malloc(SIZE * sizeof(char));  // SIZE depends on how large each string should be
            intermediate[i] = (char*)malloc(SIZE * sizeof(char));
        }
        count=0;
        count2=0;
        eflag=0;
    }
%}
%name parser
%union {
    char* str;
}

%token<str> VAR
%token<str> Floats
%token<str> ASSIGN

%token<str> SC
%token<str> LP
%token<str> RP
%token<str> CL
%token<str> CR
%token<str> INC 
%token<str> RELOP
%token<str> Else
%token<str> DEC 
%token<str> If
%type<str> Expr
%type<str> Fact
%token<str> BoolAnd
%token<str> BoolOr
%type<str> BoolExp
%type<str> S
%type<str> Assignments
%type<str> IfStatement
%left BoolOr
%left BoolAnd
%left '|'
%left '^'
%left '&'
%left  RELOP
%left '+' '-'
%left '*' '/' '%'
%nonassoc INC DEC  

%%

S:  IfStatement { 
        if(eflag == 0) 
        {
            printf("\t\t Accepted!\n\n");
            for (int i = 0; i <count; i++) {
                printf("%s",intermediate[i]);
            }
            for (int i = 0; i <count2; i++) {
                printf("%s",finalAssignments[i]);
            }
            printf("\nProcessing Next Input\n");
        }
        else if(eflag == 1)
        {
            printf("  float not to be used with modulo symbol\n\n");
        }
        else if( eflag==2)
        {
            printf("\t\t Operands not found\n\n");
        }
    } S
    | Assignments S
    | {printf("\nDone!!\n");}
    ;

IfStatement:
    If LP BoolExp RP CL {
        printf("if %s goto %d\n goto %d", $3, genBlockLabel(), genBlockLabel()); 
    } S CR {   
        printf("L%d:\n",blockVar);
        printf("%s\n",$6);
    } ElseExpr
    |
    If BoolExp error CR
    {
        yyerror("");
        printf("\t\t error : Expected \'(\' before %s \n\n",$2);
        yyerrok;
        yyclearin;
        handleClear();
        eflag = 3;
    }
    |
    If LP BoolExp CL error CR
    {
        yyerror("");
        printf("\t\t error : Expected \')\' after %s \n\n",$3);
        yyerrok;
        yyclearin;
        handleClear();
        eflag = 3;
    }
    ;

ElseExpr:
     Else CL S CR 
    {   

    }
    | {}
    ;
BoolExp:
    Expr RELOP Expr {

    }
    |
    Assignments {

    }
    |
    '!' Expr {

    }
    |
    BoolExp BoolAnd BoolExp {

    }
    |
    BoolExp BoolOr BoolExp {

    }
    |
    error SC{
        yyerror("");
        printf("\t\tBoolean Expression Issues\n\n");
        yyerrok;
        yyclearin;
        handleClear();
        eflag = 3;
    }
    ;

Assignments: 
    VAR ASSIGN Expr SC 
    {
        snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $3); 
        snprintf(finalAssignments[count2],SIZE,"%s = t%d + 1;\n", $1, count); 
        count2++;
        count++;
    }
    |
    VAR INC SC{ 
        strcat($1,$2);
        $$ = strdup($1);
        snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $1); 
        snprintf(finalAssignments[count2],SIZE,"%s = t%d + 1;\n", $1, count); 
        count2++;
        count++;
    } 
    | VAR DEC SC{ 
        strcat($1,$2);
        $$ = strdup($1);
        snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $1); 
        snprintf(finalAssignments[count2],SIZE,"%s = t%d - 1;\n", $1, count); 
        count2++;
        count++;
    } 
    | INC VAR SC{ 
        strcat($1,$2);
        $$ = strdup($2);
        snprintf(intermediate[count],SIZE,"t%d = %s + 1;\n", count, $2); 
        snprintf(finalAssignments[count2],SIZE,"%s = t%d;\n", $2, count); 
        count2++;
        count++;
    }
    | DEC VAR SC{ 
        strcat($1,$2);
        $$ = strdup($2);
        snprintf(intermediate[count],SIZE,"t%d = %s - 1;\n", count, $2); 
        snprintf(finalAssignments[count2],SIZE,"%s = t%d;\n", $2, count); 
        count2++;
        count++;
    }
    | error {
        yyerror("");
        printf("Missing \';\' !!");
        yyerrok;
        yyclearin;
        handleClear();
    }
    ;

Op: '+'|'-'|'/'|'%'|'*';

Expr: Expr '+' Expr 
    { 
        // Generate TAC for addition
        snprintf(intermediate[count],SIZE,"t%d = t%d + t%d;\n", count, count-2, count-1);
        sprintf($$,"%s + %s;\n",$1, $3);
        count++;
    }
    | Expr '-' Expr 
    { 
        // Generate TAC for subtraction
        snprintf(intermediate[count],SIZE,"t%d = t%d - t%d;\n", count, count-2, count-1 );
        sprintf($$,"%s - %s;\n", $1, $3);
        count++;
    }
    | Expr '|' Expr 
    { 
        // Generate TAC for multiplication
        snprintf(intermediate[count],SIZE,"t%d = t%d | t%d;\n", count, count-2, count-1);
        sprintf($$,"%s | %s;\n", $1, $3);
        count++;
    }
    | Expr '&' Expr 
    { 
        // Generate TAC for multiplication
        snprintf(intermediate[count],SIZE,"t%d = t%d & t%d;\n", count, count-2, count-1);
        sprintf($$,"%s & %s;\n", $1, $3);
        count++;
    }
    | Expr '^' Expr 
    { 
        // Generate TAC for multiplication
        snprintf(intermediate[count],SIZE,"t%d = t%d ^ t%d;\n", count, count-2, count-1);
        sprintf($$,"%s ^ %s;\n", $1, $3);
        count++;
    }
    | Expr '*' Expr 
    { 
        // Generate TAC for multiplication
        snprintf(intermediate[count],SIZE,"t%d = t%d * t%d;\n", count, count-2, count-1);
        sprintf($$,"%s * %s;\n", $1, $3);
        count++;
    }
    | Expr '/' Expr 
    {   
        // Generate TAC for division
        snprintf(intermediate[count],SIZE,"t%d = t%d / t%d;\n", count, count-2, count-1);
        sprintf($$,"%s / %s;\n", $1, $3);
        count++;
    }
    | Expr '%' Expr
    {
        if (strchr($1, '.') == NULL && strchr($3, '.') == NULL)
        {
            snprintf(intermediate[count],SIZE,"t%d = t%d \% t%d;\n", count, count-2, count-1);
            sprintf($$,"t%d = %s \% %s;\n",count, $1, $3);
            count++;
        }
        else
        {
            eflag = 1;  
        }
    }
    |
    Expr Op
    {
        eflag=2;
    }
    | Fact
    ;


Fact: VAR INC { 
        // strcat($1,$2);
            $$ = strdup($1);
            snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $1); 
            snprintf(finalAssignments[count2],SIZE,"%s = t%d + 1;\n", $1, count); 
            count2++;
            count++;
        } 
        | VAR DEC { 
            // strcat($1,$2);
            $$ = strdup($1);
            snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $1); 
            snprintf(finalAssignments[count2],SIZE,"%s = t%d - 1;\n", $1, count); 
            count2++;
            count++;
        } 
        | INC VAR { 
            // strcat($1,$2);
            $$ = strdup($2);
            snprintf(intermediate[count],SIZE,"t%d = %s + 1;\n", count, $2); 
            snprintf(finalAssignments[count2],SIZE,"%s = t%d;\n", $2, count); 
            count2++;
            count++;
        }
        | DEC VAR { 
            // strcat($1,$2);
            $$ = strdup($2);
            snprintf(intermediate[count],SIZE,"t%d = %s - 1;\n", count, $2); 
            snprintf(finalAssignments[count2],SIZE,"%s = t%d;\n", $2, count); 
            count2++;
            count++;
        }
        | VAR C { 
            $$ = strdup($1);
            snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $1); 
            // snprintf(finalAssignments[count2],SIZE,"%s = t%d;", $1, count); 
            // count2++;
            count++;
        }
        | Floats C { 
            $$ = strdup($1);
            snprintf(intermediate[count],SIZE,"t%d = %s;\n", count, $1); 
            // snprintf(finalAssignments[count2],SIZE,"%s = t%d;", $1, count); 
            // count2++;
            count++;
        }
        | Floats INC error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
        }
        | Floats DEC error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
        }
        | DEC Floats error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
        }
        | INC Floats error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
        }
        | LP Expr RP { $$ = strdup($2); }
        | LP Expr error
        {
            yyerror("");
            printf("\t\tno ) detected after (\n\n");
            yyerrok;
            yyclearin;
        }
        ;
C:      VAR error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n\n");
            yyerrok;
            yyclearin;
        }
        |
        Floats error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n\n");
            yyerrok;
            yyclearin;
        }
        |;
%%
int yyerror(char* err) {
    return 0;
}

int main(int argc, char* argv[]) {
    int yydebug=1;
    if (argc > 1) {
        FILE* inp = fopen(argv[1], "r");
        if (inp != NULL) {
            yyin = inp;
        }
    }
    for (int i = 0; i < 100; i++) {
        finalAssignments[i] = (char*)malloc(SIZE * sizeof(char)); 
        intermediate[i] = (char*)malloc(SIZE * sizeof(char));
    }
    yyparse();
    fclose(yyin);
    return 0;
}
