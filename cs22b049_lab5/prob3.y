%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYDEBUG 1
extern int yylex();
extern int yydebug;
int yyerror(char*);
int eflag=0;
extern FILE* yyin;
typedef struct Node{

    char* type;
    char* lexeme;
    int IntVal;
    float FloatVal;
    struct Node* left;
    struct Node* right;

} node;
node* Nodemaker(char* operator, char* var , int IntVal, float FloatVal , node* left , node* right);
void printPostOrder(node* root);
%}

%token FLOATs INTs DIV MULT MOD ADD SUB OPENBRACK CLOSEBRACK ASSIGN VAR

%union{
    int INT;
    float FLOAT;
    char Oprtr;
    char* variable;
    struct Node* nodee;
}


%type <nodee> ArithExpr AssignExpr TERM INTEGER_EXP INTEGER_TERM INT_FACTOR FACTOR
%type <INT> INTs
%type <variable> VAR 
%type <FLOAT> FLOATs
%type <Oprtr> DIV MULT MOD ADD SUB OPENBRACK CLOSEBRACK ASSIGN
%left ADD SUB MUL DIV MOD
%right UMINUS ASSIGN

%%

EXPRESSION: ArithExpr ';'       {
                                    printf("%-40s\n" , "accepted\n");
                                    printf("Printing Post order\n\n");
                                    printPostOrder($1); 
                                    printf("\n\n");
                                    yyclearin;
                                } EXPRESSION
            | AssignExpr ';'    {
                                    printf("%-40s\n" , "accepted\n");
                                    printf("Printing Post order\n\n");
                                    printPostOrder($1); 
                                    printf("\n\n");
                                    yyclearin;
                                } EXPRESSION
            | error ';' { 
                    printf("\t\t\t%-40s\n","Rejected Due to invalid syntax\n"); 
                    eflag = 1; 
                    yyerrok;
                    } EXPRESSION
            | {printf("Done!!\n");}
            ;
AssignExpr: ArithExpr ASSIGN ArithExpr {
                        $$ = Nodemaker("ASSIGN", "=", 0, 0, $1, $3);
                    }
            ;

ArithExpr:  ArithExpr ADD TERM 
            {
                $$ = Nodemaker("ADD", "+", 0, 0, $1, $3);
            }
            | ArithExpr SUB TERM 
            {
                $$ = Nodemaker("SUB", "-", 0, 0, $1, $3);
            }
            | TERM
            {
                $$ = $1;
            }
            | SUB TERM %prec UMINUS 
            {
            
                $$ = Nodemaker("UMINUS", "-", 0, 0, $2,NULL); //right node NULL as unary operator
            }
            |ArithExpr ADD  error {  printf("\t\t\t%-40s\n", "Rejected Due to Nothing on RHS of +\n"); eflag = 1; yyerrok;yyclearin;}
            |ArithExpr SUB  error {  printf("\t\t\t%-40s\n", "Rejected Due to Nothing on RHS of -\n"); eflag = 1; yyerrok;yyclearin;}
            ;
TERM:   TERM MULT FACTOR 
        {
            $$ = Nodemaker("MULT", "*", 0, 0, $1, $3);
        }
        | TERM DIV FACTOR 
        {
            $$ = Nodemaker("DIV","/", 0, 0, $1, $3);
        }
        | TERM MOD INTEGER_EXP 
        {
            $$ = Nodemaker("MOD", "\%", 0, 0, $1, $3);
        }
        | FACTOR 
        {
            $$ = $1;
        }
        ;

INTEGER_EXP:    INTEGER_EXP ADD INTEGER_TERM
                {
                    $$ = Nodemaker("ADD", "+", 0, 0, $1, $3);
                }
                | INTEGER_EXP SUB INTEGER_TERM 
                {
                    $$ = Nodemaker("SUB", "-", 0, 0, $1, $3);
                }
                | INTEGER_TERM 
                {
                    $$ = $1;
                }
                |INTEGER_EXP ADD error { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of +\n"); eflag = 1; yyerrok;yyclearin;}
                |INTEGER_EXP SUB error { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of -\n"); eflag = 1; yyerrok;yyclearin;}
                ;
INTEGER_TERM:   INTEGER_TERM MULT INT_FACTOR %prec MULT
                {
                    $$ = Nodemaker("MULT", "*", 0, 0, $1, $3);
                }
                | INTEGER_TERM DIV INT_FACTOR %prec DIV
                {
                    $$ = Nodemaker("DIV","/", 0, 0, $1, $3);
                }
                | INTEGER_TERM MOD INT_FACTOR %prec MOD
                {
                    $$ = Nodemaker("MOD", "\%", 0, 0, $1, $3);
                }
                | INT_FACTOR 
                {
                    $$ = $1;
                }
                |INTEGER_TERM INT_FACTOR ';' error { printf("\t\t\t%-40s" ,"Rejected Due to no operator present *\n"); eflag = 1; yyerrok;yyclearin;}
                |INTEGER_TERM MULT error { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of *\n"); eflag = 1; yyerrok;yyclearin;}
                // |INTEGER_TERM DIV error { printf("\t\t\t\t|\t Rejected Due to Nothing on RHS of /\n"); eflag = 1; yyerrok;}
                // |INTEGER_TERM MOD error { printf("\t\t\t\t|\t Rejected Due to Nothing on RHS of %%\n"); eflag = 1; yyerrok;}
                // |INTEGER_TERM INT_FACTOR error { printf("\t\t\t\t|\t Rejected Due to Nothing on RHS of %%\n"); eflag = 1; yyerrok;}
                ;

INT_FACTOR: OPENBRACK INTEGER_EXP CLOSEBRACK  
            {
                $$ = $2;
            }
            | INTs
            {
                $$ = Nodemaker("INT", "INT" , $1, 0, NULL, NULL); //leaf node
            } 
            | VAR 
            {
                $$ = Nodemaker("VAR", $1 , 0, 0, NULL, NULL); //leaf node
            }
            | FLOATs error { printf("\t\t\t%-40s\n","Rejected Due to Float cannot be used for modulus operator \n"); eflag = 1; yyerrok;yyclearin;}
            | OPENBRACK INTEGER_EXP error ';' { printf("\t\t\t%-40s\n","Rejected Due to Closing Bracket not found"); eflag = 1; yyerrok;yyclearin;}
            | OPENBRACK error { printf("\t\t\t%-40s\n" ,"Rejected Due to NO Integer found after opening bracket \n"); eflag = 1; yyerrok;yyclearin;}
            ;

FACTOR: OPENBRACK ArithExpr CLOSEBRACK 
        {
            $$ = $2;
        }
        | FLOATs 
        {
            $$ = Nodemaker("FLOAT", "FLOAT" , 0, $1, NULL, NULL); //leaf node
        }
        | VAR
        {
            $$ = Nodemaker("VAR", $1 , 0, 0, NULL, NULL); //leaf node
        } 
        | INTs 
        {
            $$ = Nodemaker("INT", "INT" , $1, 0, NULL, NULL); //leaf node
        }
        | OPENBRACK ArithExpr error { printf("\t\t\t%-40s\n","Rejected Due to Closing Bracket not found \n"); eflag = 1; yyerrok;yyclearin;}
        | OPENBRACK error { printf("\t\t\t%-40s\n"," Rejected Due to NO Integer found after opening bracket \n"); eflag = 1; yyerrok;yyclearin;}
        ;
            

%%
int yyerror(char* s) {
    return 0;
}
void printPostOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    if(strcmp("INT",root->lexeme)==0)
    {
        printf(" %d ",root->IntVal);
    }
    else if(strcmp("FLOAT",root->lexeme)==0)
    {
        printf(" %g ",root->FloatVal);
    }
    else
    {
        printf(" %s ",root->lexeme);
    }
}
node* Nodemaker(char* type, char* lexeme , int IntVal, float FloatVal , node* left , node* right)
{
    node* newNode = (node*)malloc(1*sizeof(node));
    newNode->type = type;
    newNode->lexeme = lexeme;
    newNode->IntVal = IntVal;
    newNode->FloatVal = FloatVal;
    newNode->left = left;
    newNode->right = right;
    return newNode;
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
    // yydebug = 1;
    yyparse();
    if (inpt) {
        fclose(inpt);
    }
    
    return 0;
}
