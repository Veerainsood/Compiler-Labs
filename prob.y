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
    
    typedef struct list 
    {
        int addr;
        char* val;
        struct node* tlist;
        struct node* flist;
    } List;
    
    typedef struct Node
    {
        int indx;
        struct Node* next;
    } node;

    char** interMedCode;
    int instrPtr=0;
    int tempVar=0;
    int lineNumber=1;
    char* getLabels()
    {
        char* tVar = (char*)malloc(10*sizeof(char));
        snprintf(tVar,10,"t%d",tempVar++);
        return tVar;
    }
    void handleClear(int val)
    {
        for(int i=0;i<1000;i++)
        {
            if(interMedCode[i]!=NULL)
            {
                free(interMedCode[i]);
            }
            interMedCode[i] = (char*)malloc(100*sizeof(char));
        }
        lineNumber=1;
    }
    void BackPatch(List* patchlist,int addr)
    {   
        node* head = patchlist;
        while(head!=NULL)
        {
            snprintf(interMedCode[head->indx] + strlen(interMedCode[head->indx]) , " %d",addr);
            head = head->next;
        }
    }
%}
%name parser
%union {
    char* str;
    struct list * list;
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
%token<str> While
%token<str> BoolAnd
%token<str> BoolOr


%type<list> ElseExpr
%type<list> BoolExp
%type<list> Assignments
%type<list> WhileStatements
%type<list> Expr
%type<list> Fact
%type<list> S
%type<list> IfStatement
%type<list> M

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
S:  S M IfStatement { 
        
    } 
    | S M Assignments {
        
    } 
    | S M WhileStatements { 
        
    }  
    | {}
    ;

M:  {
        List* curr = $$;
        curr->addr = lineNumber;
    }
    ;

IfStatement:
    If LP BoolExp RP CL S CR M M ElseExpr{
        List* B = $3;
        List* M1 = $8;
        List* M2 = $9;
        BackPatch(B->tlist,M1->addr);
        BackPatch(B->flist,M2->addr);
    }  
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
    Else CL M S CR {   }
    | {}
    ;

WhileStatements:
    While LP BoolExp RP M M CL S CR {}
    |
    While BoolExp error CR
    {
        yyerror("");
        printf("\t\t error : Expected \'(\' before %s \n\n",$2);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    |
    While LP BoolExp CL error Else CL S CR
    {
        yyerror("");
        printf("\t\t error : Expected \')\' after %s \n\n",$3);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    ;

BoolExp:
    Expr RELOP Expr {
        char* Label = getLabels();
        sprintf(interMedCode[instrPtr++],"%d %s = (%s %s %s);\n",lineNumber,Label,$1->val,$2,$3->val);
        $$->val = Label; $$->tlist = NULL;
        $$->addr = lineNumber++; $$->tlist = NULL;
    }
    |
    Assignments {
        $$->val = strdup($1); $$->tlist = $1->tlist;
        $$->addr = $1->addr;  $$->flist = $1->flist;
    }
    |
    '!' Expr {
        char* Label = getLabels();
        sprintf(interMedCode[instrPtr++],"%d %s = !(%s);\n",lineNumber,Label,$2->val);
        $$->val = Label; $$->tlist = NULL;
        $$->addr = lineNumber++; $$->tlist = NULL;
    }
    |
    BoolExp BoolAnd BoolExp{
        char* Label = getLabels();
        sprintf(interMedCode[instrPtr++],"%d %s = %s %s %s;\n",lineNumber,Label,$1->val, $2, $3->val);
        $$->val = Label; $$->tlist = NULL;
        $$->addr = lineNumber++; $$->tlist = NULL;
    } 
    |
    BoolExp BoolOr BoolExp  {
        char* Label = getLabels();
        sprintf(interMedCode[instrPtr++],"%d %s = %s %s %s;\n",lineNumber,Label,$1->val, $2, $3->val);
        $$->val = Label; $$->tlist = NULL;
        $$->addr = lineNumber++; $$->tlist = NULL;
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
        sprintf(interMedCode[instrPtr++],"%d %s = %s %s %s;\n",lineNumber,Label,$1->val, $2, $3->val);
        $$->val = Label; $$->tlist = NULL;
        $$->addr = lineNumber++; $$->tlist = NULL;
    }
    |
    VAR INC SC { 
        
    } 
    | VAR DEC SC{ 
        
    } 
    | INC VAR SC{ 
        
    }
    | DEC VAR SC{ 
        
    }
    | error {
        yyerror("");
        printf("Missing \';\' or some syntax issue you have chanted ;) :) \n");
        yyerrok;
        yyclearin;
        handleClear(1);
    }
    ;

Op: '+'|'-'|'/'|'%'|'*';

Expr: Expr '+' Expr 
    { 
        // Generate TAC for addition
    }
    | Expr '-' Expr 
    { 
        // Generate TAC for subtraction
        
    }
    | Expr '^' Expr 
    { 
        // Generate TAC for or
        
    }
    | Expr '*' Expr 
    { 
        // Generate TAC for multiplication
        
    }
    | Expr '/' Expr 
    {   
        // Generate TAC for division
        
    }
    | Expr '%' Expr
    {
        if (strchr($1, '.') == NULL && strchr($3, '.') == NULL)
        {
            
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
            // $$ = Label;
        } 
        | VAR DEC { 
            
            // $$ = Label;
        } 
        | INC VAR { 
            
            // $$ = Label;
        }
        | DEC VAR { 
            
            // $$ = Label;
        }
        | VAR C { 
            
        }
        | Floats C { 
            
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
    interMedCode = (char**)malloc(1000*sizeof(char*));//map of lineNumber vs L
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
