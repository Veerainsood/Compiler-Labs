%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool E();
bool E1();
bool T();
bool T1();
bool F();
bool CheckToken(char token);

int pos = 0;
char * input_str = NULL;

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}


%}

identifier  [a-zA-Z0-9]+

%option noyywrap

%%
[ \t] ; // Ignore whitespace
\n ;
\*                        { return '*'; }   //pattern matching for * 
\+                        { return '+'; }  //pattern matching for + 
{identifier} { return yytext[0];}
\(                        { return '('; }
\)                        { return ')'; }
. { /* Handle unexpected characters */ yyerror("Unexpected character"); }

%%

bool E() {
    if (T() )
        if (E1()) {
        return true;
    }
    return false;
}

bool E1() {
    if (CheckToken('+'))
    if ( T())
      if (E1()) {
        return true;
    }
    return true;  // Epsilon
}

bool T() {
    if (F()) 
     if (T1()) {
        return true;
    }
    return false;
}

bool T1() {
    if (CheckToken('*'))
     if ( F()) 
      if  (T1()) {
        return true;
    }
    return true;  // Epsilon
}


bool F() {
    if (yytext[0] >= 'A' && yytext[0] <= 'Z') 
    {
        yylex(); //checking for the next token 
        return true;
    }

    else if (yytext[0] >= 'a' && yytext[0] <= 'z') {
        yylex(); //checked small letters
        return true;
    }
    else if (yytext[0] >= '0' && yytext[0] <= '9') {
        yylex(); //check the token 
        return true;
    }
    else if( (int)yytext[0] == 40 ){
        yylex();
        bool valid = E();
        if((int)yytext[0] == 41){
            yylex();
            return valid;
        }
    }
    return false;
}


bool CheckToken(char token) {
 
    if(yytext[0]== token)
       { yylex();
        return true;
    }
    return false;
}




int main(int argc, char *argv[]) {
    if (argc!=2){
printf("Usage: %s <input_file>\n", argv[0]);
return 1;
}
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error.\n");
    return 1;
    }
    yyin = fp;
    char ln[256];
    int ln_number = 1; 
while (fgets(ln, sizeof(ln), fp) != NULL) {
        if (ln[strlen(ln) - 1] == '\n') {
            ln[strlen(ln) - 1] = '\0';
        }
        yy_scan_string(ln); 
     yylex();

        if (E()) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        ln_number++;
    }

    return 0;
}