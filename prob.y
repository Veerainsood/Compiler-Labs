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
    char* string;
    int blockVar =0;
    int IFCOUNTER=0;
    int tempVar=0;
    int ifStmntPtr=0;
    char* getLabels()
    {
        char* tVar = (char*)malloc(10*sizeof(char));
        snprintf(tVar,10,"t%d",tempVar++);
        return tVar;
    }
    void handleClear(int val)
    {
        for(int i=0;i<3000;i++)
        {
            string[i] = '\0';
        }
        ifStmntPtr=0;
        if(val)
        {
            tempVar=0;
            blockVar=0;
        }
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
            if(IFCOUNTER==1)
            {
                printf("\t\t Accepted!\n\n");
                printf("\nProcessing Next Input\n");
                tempVar=0;
                blockVar=0;
            }
            else
            {
                blockVar-=2;
            }
            IFCOUNTER--;
        }
        else if(eflag == 1)
        {
            printf("  float not to be used with modulo symbol\n\n");
            handleClear(1);
        }
        else if( eflag==2)
        {
            printf("\t\t Operands not found\n\n");
            handleClear(1);
        }

    } S
    | Assignments {
        $$ = strdup($1);
    } S
    | { }
    ;

IfStatement:
    If LP BoolExp RP CL {
        printf("if t%d goto L%d\n goto L%d\n", tempVar-1,blockVar , blockVar+1); 
        printf("L%d:\n",blockVar);
        blockVar+=2;
        IFCOUNTER++;
        handleClear(0);
    } S CR {   
        printf("L%d:\n",blockVar-1);
        handleClear(0);
    }  ElseExpr
    |
    If BoolExp error CR
    {
        yyerror("");
        printf("\t\t error : Expected \'(\' before %s \n\n",$2);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    |
    If LP BoolExp CL error CR
    {
        yyerror("");
        printf("\t\t error : Expected \')\' after %s \n\n",$3);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    ;

ElseExpr:
    Else CL S CR 
    {   
        for(int i=0;i<ifStmntPtr;i++)
        {
            printf("%c",string[i]);
        }
    }
    | {}
    ;
BoolExp:
    Expr RELOP Expr {
        char* Label = getLabels();
        printf("%s = %s %s %s;\n",Label,$1,$2,$3);
        $$ = Label;
    }
    |
    Assignments {}
    |
    '!' Expr {
        char* Label = getLabels();
        printf("%s = ! ( %s );\n",Label,$2);
        $$ = Label;
    }
    |
    BoolExp BoolAnd BoolExp{
        char* Label = getLabels();
        printf("%s =  %s && %s;\n",Label,$1,$3);
        $$ = Label;
    } 
    |
    BoolExp BoolOr BoolExp  {
        char* Label = getLabels();
        printf("%s =  %s || %s;\n",Label,$1,$3);
        $$ = Label;
    } 
    |
    error SC{
        yyerror("");
        printf("\t\tBoolean Expression Issues\n\n");
        yyerrok;
        yyclearin;
        eflag = 3;
        handleClear(1);
    }
    ;

Assignments: 
    VAR ASSIGN Expr SC 
    {   
        char* Label = getLabels();
        printf("%s %s %s;\n",$1,$2,$3);
        printf("%s = %s;\n",Label,$1);
        $$ = Label;
    }
    |
    VAR INC SC { 
        char* Label = getLabels();
        printf("%s = %s\n",Label, $1);
        printf("%s = %s + 1\n",$1, $1);
        $$ = Label;
    } 
    | VAR DEC SC{ 
        char* Label = getLabels();
        printf("%s = %s\n",Label, $1);
        printf("%s = %s - 1\n",$1, $1);
        $$ = Label;
    } 
    | INC VAR SC{ 
        char* Label = getLabels();
        printf("%s = %s + 1\n",$1, $1);
        printf("%s = %s\n",Label, $1);
        $$ = Label;
    }
    | DEC VAR SC{ 
        char* Label = getLabels();
        printf("%s = %s - 1\n",$1, $1);
        printf("%s = %s\n",Label, $1);
        $$ = Label;
    }
    | error {
        yyerror("");
        printf("Missing \';\' !!");
        yyerrok;
        yyclearin;
        handleClear(1);
    }
    ;

Op: '+'|'-'|'/'|'%'|'*';

Expr: Expr '+' Expr 
    { 
        // Generate TAC for addition
        char* Label = getLabels();
        printf("%s = %s + %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '-' Expr 
    { 
        // Generate TAC for subtraction
        char* Label = getLabels();
        printf("%s = %s - %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '^' Expr 
    { 
        // Generate TAC for or
        char* Label = getLabels();
        printf("%s = %s ^ %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '*' Expr 
    { 
        // Generate TAC for multiplication
        char* Label = getLabels();
        printf("%s = %s * %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '/' Expr 
    {   
        // Generate TAC for division
        char* Label = getLabels();
        printf("%s = %s / %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '%' Expr
    {
        if (strchr($1, '.') == NULL && strchr($3, '.') == NULL)
        {
            char* Label = getLabels();
            printf("%s = %s \% %s\n",Label, $1, $3);
            $$ = Label;
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
            printf("%s = %s\n",Label, $1);
            printf("%s = %s + 1\n",$1, $1);
            $$ = Label;
        } 
        | VAR DEC { 
            char* Label = getLabels();
            printf("%s = %s\n",Label, $1);
            printf("%s = %s - 1\n",$1, $1);
            $$ = Label;
        } 
        | INC VAR { 
            char* Label = getLabels();
            printf("%s = %s + 1\n",$1, $1);
            printf("%s = %s\n",Label, $1);
            $$ = Label;
        }
        | DEC VAR { 
            char* Label = getLabels();
            printf("%s = %s - 1\n",$1, $1);
            printf("%s = %s\n",Label, $1);
            $$ = Label;
        }
        | VAR C { 
            char* Label = getLabels();
            printf("%s = %s;\n",Label,$1); 
            $$ = Label;
        }
        | Floats C { 
            char* Label = getLabels();
            printf("%s = %s;\n",Label,$1); 
            $$ = Label;
        }
        | Floats INC error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | Floats DEC error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | DEC Floats error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | INC Floats error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | LP Expr RP 
        { 
            $$ = strdup($2); 
        }
        | LP Expr error
        {
            yyerror("");
            printf("\t\tno ) detected after (\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        ;
C:      VAR error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        |
        Floats error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        |;
%%
int yyerror(char* err) {
    return 0;
}

int main(int argc, char* argv[]) {
    int yydebug = 1;
    string = (char*)malloc(3000*sizeof(char));
    handleClear(1);
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

    //handleClear(1); // Clean up before exiting
    return 0;
}
