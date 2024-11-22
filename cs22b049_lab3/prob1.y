%{
#include <stdio.h>
#include <stdlib.h>

extern FILE* yyin;
int yyerror(char*);
void Runner(const char* inputFileName, const char* outputFileName);
int yylex();
int eflag = 0;
FILE* input, *output;
%}

%union 
{
	int number;
}

%token ZERO ONE
%type <number> ZERO
%type <number> ONE
%%
S : ZERO ZERO S ZERO ZERO  
  | ZERO ONE ZERO S ZERO ONE ZERO 
  | ONE S ONE { fprintf(output, "\t\tAccepted"); }
  | { fprintf(output, "\t\t Done"); }
  ;
%%

int yyerror(char* s) {
    printf("\n\nError: %s\n", s);
    return 0;
}

int main() {
    Runner("inp1.txt", "out1.txt");
    return 0;
}

void Runner(const char* inputFileName, const char* outputFileName) {
    input = fopen(inputFileName, "r");
    if (input == NULL) {
        printf("Input file is not existing in the current directory.\nPlease make a file called inp1.txt and enter the test cases each separated by a newline for processing.\n");
        return;
    }
    output = fopen(outputFileName, "w");

    yyin = input;
    yyparse();

    fclose(input);
    fclose(output);
}

