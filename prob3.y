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

    typedef struct Node{
        char* val;
        struct Node* left;
        struct Node* right;
    } node;

    node* nodeMaker(char* op, node*left,node*right)
    {
        node* root = (node*)malloc(sizeof(node));
        root->val = strdup(op);
        root->left = left;
        root->right = right;
        return root;
    }

    node* PostOrder(node* root)
    {
        if(root==NULL) return NULL;
        PostOrder(root->left);
        PostOrder(root->right);
        printf(" %s ",root->val);
    }
%}

%union{
    char* str;
    struct Node* nodee;
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
%type<nodee> Expr
%type<nodee> Fact
%left '+' '-'
%left '*' '/' '%'
%nonassoc INC DEC  

%%
S:	Assignments S 
    | { printf("!!Done\n"); }
    ;

Assignments:    VAR ASSIGN Expr SC 
                {
                    if (eflag == 0) 
                    {
                        printf("\t\t Accepted!\n\n");
                        printf("Printing Post Order:\n");
                        node* left = nodeMaker(strdup($1),NULL,NULL);
                        node* root = nodeMaker(strdup($2),left,$3);
                        PostOrder(root);
                        printf("\n\n");
                    }
                    else if(eflag==1){
                        printf("  float not to be used with modulo symbol\n\n");
                    }
                    else
                    {
                        printf("\t\t Operands not found\n\n");
                    }
                    eflag=0;
                }
                |
                error SC 
                {
                    yyerror("");
                    printf("\t\tExpression not assignable...\n\n");
                    yyerrok;
                    yyclearin;
                } 
                ;
Op: '+'|'-'|'/'|'*'|'%';
Expr:           Expr '+' Expr { $$ = nodeMaker("+",$1,$3);}
                | 
                Expr '-' Expr { $$ = nodeMaker("-",$1,$3);}
                |
                Expr '*' Expr { $$ = nodeMaker("*",$1,$3);}
                |
                Expr '/' Expr { $$ = nodeMaker("/",$1,$3);}
                |
                Expr '%' Expr
                {
                    if(strchr($3->val,'.')==0 || strchr($3->val,'.')==0)
                    {
                        eflag=1;
                    }
                    else
                    {
                        eflag=0;
                        $$ = nodeMaker("\%",$1,$3);
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

Fact:           VAR INC { $$ = nodeMaker(strcat(strdup($1),strdup($2)),NULL,NULL); } /* Postfix increment */
                | VAR DEC { $$ = nodeMaker(strcat(strdup($1),strdup($2)),NULL,NULL); } /* Postfix decrement */
                | INC VAR { $$ = nodeMaker(strcat(strdup($1),strdup($2)),NULL,NULL); } /* Prefix increment */
                | DEC VAR { $$ = nodeMaker(strcat(strdup($1),strdup($2)),NULL,NULL); } /* Prefix decrement */
                | VAR C { $$ = nodeMaker(strdup($1),NULL,NULL); }
                | Floats C { $$ = nodeMaker(strdup($1),NULL,NULL); }
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
                | LP Expr RP { $$ = $2; }
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

