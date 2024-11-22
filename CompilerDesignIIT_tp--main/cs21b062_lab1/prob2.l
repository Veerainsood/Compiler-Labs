%{
 int pos = 0;
// declaration 
%}

DIGIT [0-9]
letter [a-d]
KEYWORDS { "." ,""}   //some common things 

%%
{letter}+{letter}[^abcd]{letter}+{letter} {
  for ( int i = 0 ; i < yyleng ; i++)
   { if ( yytext[i] != 'a' && yytext[i] != 'b' &&  yytext[i] != 'c' &&  yytext[i] != 'd')
      { 
        pos = i-1;
      }
   }

   if (yytext[pos] == yytext[yyleng -1])
    {
        printf ("%s : valid", yytext);
    }
    
    else 
     {
        printf ("%s : not valid",yytext);
     }
}

.+ {  ("%s : not valid",yytext);
}

%%

int main() 
{ yylex(); return 0;
}


