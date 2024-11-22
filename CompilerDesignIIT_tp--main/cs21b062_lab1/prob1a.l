%{
void isValid(char*);
void isNotValid( char*);
// declaration 
%}

DIGIT [0-9]
LETTER [a-zA-Z]
KEYWORDS { "." ,""}   //some common things 

%%

(1|01)*0?111(01|1)* { isValid(yytext); }
.+ { isNotValid(yytext); }
%%

int main() 
{ yylex(); return 0;
}

void isValid( char* lexeme)
{
    printf( "%s: is fine", lexeme);
}

void isNotValid( char* lexeme)
{
    printf( "%s is not fine", lexeme);
}
