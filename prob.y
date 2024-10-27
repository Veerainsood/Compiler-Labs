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
    char str[2000];
    int blockVar =0;
    int tempVar=0;
    int ifStmntPtr=0;
    int genBlockLabel()
    {
        return blockVar++;
    }
    char* getLabels()
    {
        char* tVar = (char*)malloc(10*sizeof(char));
        snprintf(tVar,10,"t%d",tempVar++);
        return tVar;
    }
    // void //handleClear();
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
%token<str> BoolAnd
%token<str> BoolOr


%type<str> ElseExpr
%type<str> BoolExp
%type<str> Assignments
%type<str> Expr
%type<str> Fact
%type<str> S
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
    | Assignments {
    } S
    | { }
    ;

IfStatement:
    If LP BoolExp RP CL S CR ElseExpr {   
        printf("if %s goto L%d\n goto L%d\n", getLabels(), genBlockLabel(), genBlockLabel()); 
        printf("L%d",blockVar-2);
        // for(int i=0;i<2000;i++)
        // {
        //     printf("%c",str[i]);
        // }
    }  
    |
    If BoolExp error CR
    {
        yyerror("");
        printf("\t\t error : Expected \'(\' before %s \n\n",$2);
        yyerrok;
        yyclearin;
        // //handleClear();
        eflag = 3;
    }
    |
    If LP BoolExp CL error CR
    {
        yyerror("");
        printf("\t\t error : Expected \')\' after %s \n\n",$3);
        yyerrok;
        yyclearin;
        //handleClear();
        eflag = 3;
    }
    ;

ElseExpr:
    Else CL S CR 
    {   
        printf("L%d:\n",blockVar-1);
    }
    | {}
    ;
BoolExp:
    Expr RELOP Expr {
        char* Label = getLabels();
        strcat(str,Label);
        // ifStmntPtr+= strlen(Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,$2);
        strcat(str,$3);
        printf("%s;\n",str);
    }
    |
    Assignments
    {
        $$ = strdup($1);
    }
    |
    '!' Expr {
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,"!");
        strcat(str,$2);
        printf("%s;\n",str);
    }
    |
    BoolExp BoolAnd BoolExp {
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,$2);
        strcat(str,$3);
        printf("%s;\n",str);
    }
    |
    BoolExp BoolOr BoolExp {
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,$2);
        strcat(str,$3);
        printf("%s;\n",str);
    }
    |
    error SC{
        yyerror("");
        printf("\t\tBoolean Expression Issues\n\n");
        yyerrok;
        yyclearin;
        //handleClear();
        eflag = 3;
    }
    ;

Assignments: 
    VAR ASSIGN Expr SC 
    {
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$1);
        strcat(str,"=");
        strcat(str,$3);
        strcat(str,";\n");
        strcat(str,Label);
        strcat(str,"=");
        strcat(str,$1);
        printf("%s;\n",str);
    }
    |
    VAR INC SC { 
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"\n");
        strcat(str,$1);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"+");
        strcat(str,$1);
        printf("%s;\n",str);
    } 
    | VAR DEC SC{ 
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"\n");
        strcat(str,$1);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"-");
        strcat(str,$1);
        printf("%s;\n",str);
    } 
    | INC VAR SC{ 
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$1);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"+");
        strcat(str,$1);
        strcat(str,Label);
        strcat(str,"=");
        strcat(str,$1);
        printf("%s;\n",str);
    }
    | DEC VAR SC{ 
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$1);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"-");
        strcat(str,$1);
        strcat(str,Label);
        strcat(str,"=");
        strcat(str,$1);
        printf("%s;\n",str);
    }
    | error {
        yyerror("");
        printf("Missing \';\' !!");
        yyerrok;
        yyclearin;
        //handleClear();
    }
    ;

Op: '+'|'-'|'/'|'%'|'*';

Expr: Expr '+' Expr 
    { 
        // Generate TAC for addition
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"+");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '-' Expr 
    { 
        // Generate TAC for subtraction
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"-");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '|' Expr 
    { 
        // Generate TAC for multiplication
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"|");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '&' Expr 
    { 
        // Generate TAC for and
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"&");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '^' Expr 
    { 
        // Generate TAC for or
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"^");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '*' Expr 
    { 
        // Generate TAC for multiplication
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"*");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '/' Expr 
    {   
        // Generate TAC for division
        char* Label = getLabels();
        strcpy($$,Label);
        strcat(str,$$);
        strcat(str,"=");
        strcat(str,$1);
        strcat(str,"/");
        strcat(str,$3);
        printf("%s\n", str);
    }
    | Expr '%' Expr
    {
        if (strchr($1, '.') == NULL && strchr($3, '.') == NULL)
        {
            char* Label = getLabels();
            strcpy($$,Label);
            strcat(str,$$);
            strcat(str,"=");
            strcat(str,$1);
            strcat(str,"\%");
            strcat(str,$3);
            printf("%s\n", str);
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
    {
        $$ = strdup($1);
    }
    ;


Fact: VAR INC { 
            char* Label = getLabels();
            strcpy($$,Label);
            strcpy(str,$$);
            strcpy(str,"=");
            strcpy(str,$1);
            strcpy(str,"+");
            strcpy(str,$1);
            printf("%s", str);
        } 
        | VAR DEC { 
            
            char* Label = getLabels();
            strcpy($$,Label);
            strcpy(str,$$);
            strcpy(str,"=");
            strcpy(str,$1);
            strcpy(str,"-");
            strcpy(str,$1);
            printf("%s", str);
        } 
        | INC VAR { 
            char* Label = getLabels();
            strcpy(str,$1);
            strcpy(str,"=");
            strcpy(str,$1);
            strcpy(str,"+");
            strcpy(str,$1);
            strcpy($$,Label);
            
            printf("%s", str);
        }
        | DEC VAR { 
            char* Label = getLabels();
            strcpy($$,Label);
            printf("%s = %s - 1;\n", $2,$2);
            printf("%s = %s;\n",Label,$2); 
        }
        | VAR C { 
            char* Label = getLabels();
            strcpy($$,Label);
            printf("%s = %s;\n",Label,$1); 
        }
        | Floats C { 
            char* Label = getLabels();
            strcpy($$,Label);
            printf("%s = %s;\n",Label,$1); 
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
    int yydebug = 1;

    // Initialize finalAssignments
    // for (int i = 0; i < SIZE; i++) {
    //     finalAssignments[i] = (char*)malloc(SIZE * sizeof(char));
    //     if (finalAssignments[i] == NULL) {
    //         fprintf(stderr, "Memory allocation failed\n");
    //         return 1; // Exit if memory allocation fails
    //     }
    //     finalAssignments[i][0] = '\0'; // Initialize with empty string
    // }

    // Rest of the main function
    if (argc > 1) {
        FILE* inp = fopen(argv[1], "r");
        if (inp != NULL) {
            yyin = inp;
        } else {
            fprintf(stderr, "Failed to open file: %s\n", argv[1]);
            return 1;
        }
    }
    yyparse();
    fclose(yyin);

    //handleClear(); // Clean up before exiting
    return 0;
}

// void handleClear() {
//     for (int i = 0; i < SIZE; i++) {
//         free(finalAssignments[i]); // Free allocated memory
//         finalAssignments[i] = NULL; // Avoid dangling pointers
//     }
//     // Reset count variables
//     count = 0;
//     count2 = 0;
//     blockVar = 0;
//     eflag = 0;
// }