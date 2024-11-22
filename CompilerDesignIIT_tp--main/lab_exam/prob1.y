%{
#include <stdio.h>
#include <string.h>
int yylex();
int flag = 0;
int yyerror(const char *);
extern FILE *yyin;

struct Dates {
    int dd, yyyy;
    char mm[20];
};

%}

%union {
    int dd;
    int yyyy;
    char mm[20];
    struct Dates *node;
}

%token <dd> day
%token <mm> month
%token <yyyy> year
%type <node> Slist Stmt

%%

Slist : Stmt { if( flag == 0 ){ printf("Accept\n"); }} Slist
        | error { printf("error\n"); } Slist
        | { printf("Completed\n"); }
        ;

Stmt : day month year 
        {
            struct Dates *dateNode = malloc(sizeof(struct Dates));
            dateNode->dd = $1;
            strcpy(dateNode->mm, $2);
            dateNode->yyyy = $3;

            printf("%i %s %i \n" , dateNode->dd , dateNode->mm , dateNode->yyyy );

            if (strcmp($2, "Mar") == 0 || strcmp($2, "Jan") == 0)
            {
                if (dateNode->dd > 31)
                {   flag =1 ;
                    yyerror("Wrong date");
                }
            }
            else if (strcmp($2, "Feb") == 0)
            {
                if ((dateNode->yyyy % 4 == 0 && dateNode->yyyy % 100 != 0) || (dateNode->yyyy % 400 == 0))
                {
                    if (dateNode->dd > 29 || dateNode->dd <= 0)
                    { flag = 1; 
                        yyerror("wrong leap date");
                    }
                }
                else
                {
                    if (dateNode->dd > 28 || dateNode->dd <= 0)
                    {  flag = 1;
                        yyerror("wrong non-leap date");
                    }
                }
            }
            else
            {
                if (dateNode->dd > 30)
                {  flag = 1;
                    yyerror("Wrong date");
                }
            }

            $$ = dateNode;
        }
        ;
%%

int yyerror(const char *s){
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        FILE *fp = fopen(argv[1], "r");
        if (fp)
            yyin = fp;
    }
    yyparse();
    return 0;
}
