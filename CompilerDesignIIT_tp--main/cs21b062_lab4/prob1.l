%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool E();
bool E1();
bool T();
bool T1();
bool F();
//bool CheckToken(char token);
%}



%%
[\t]                          /* Ignore whitespace */
\*                        { return '*'; }   //pattern matching for * 
\+                        { return '+'; }  //pattern matching for + 
[0-9A-Za-z_]+              { return yytext[0];}
\(                        { return '('; }
\)                        { return ')'; }
.                         { return yytext[0];}              // Ignore other characters 

%%



//function implementation to check the source codes 

bool InvalidToken() {
     if ( yytext[0] == '=' ){
        printf("Invalid token: %s\n", yytext);
        return false;
    }
    return true;
}

bool E() {
    return T() && E1() && InvalidToken();
}

bool E1() {
    if (yytext[0] == '+') {
        //pos++;  //lets use yylex instead to do the task 
        yylex(); 
        return T() && E1();
    }
    return true;
}

bool T() {
    return F() && T1();
}

bool T1() {
    if (yytext[0] == '*') {
        yylex(); // Advance to the next token
        return F() && T1();  // no if required here 
    }
    return true;
}






bool F() {
    if (yytext[0] >= 'A' && yytext[0] <= 'Z') 
    {
        yylex(); // checking for the next token 
        return true;
    }

    else if (yytext[0] >= 'a' && yytext[0] <= 'z') {
        yylex(); // checked small letters
        return true;
    }
    else if (yytext[0] >= '0' && yytext[0] <= '9') {
        yylex(); // check the token 
        return true;
    }
    else if(yytext[0] == '('){
        yylex();
        bool valid = E();
        if(yytext[0] == ')'){
            yylex();
            return valid;
        }
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

