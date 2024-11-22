%{


int count_x;
int count_y;
int i =0;
// declaration 
%}

DIGIT [0-9]
LETTER [a-zA-Z]
KEYWORDS { "." ,""}   //some common things 

letter_allowed [x-zX-Z]
%%

{letter_allowed}+ {for( int i = 0; i < yyleng ; i++)   
                    { 
                        if (yytext[i] == 'X' || yytext[i] == 'x')
                         { count_x++ ; }
                         if ( yytext[i] == 'Y' || yytext[i] == 'y')
                         { count_y++ ;}
                    }


        if ( count_x %2 == count_y %3)
         {
            printf ( " %s: valid", yytext);
         }
        else 
          {
            printf ("%s: not count valid", yytext);
          }
}
.+ { printf ("%s: not valid character" , yytext );}
%%

int main() 
{ yylex(); return 0;
}

