%{
#include <stdio.h>
int pos = 0;
// declaration
%}

letter [a-zA-Z]
ld [a-zA-Z0-9]
Schemas ("https"|"http"|"ftp"|"mailto"|"file")
domain_name  {letter}{ld}*
path  {domain_name}\/
website {ld}+\.{domain_name}\.{letter}+
query \?({domain_name}\={domain_name}\&{domain_name}\={domain_name})
port [0-9]+
web_link \/{path}+{domain_name}\.{letter}+
port_link \:{port}\/{path}+{domain_name}{query}

%%
{Schemas}\:(\/\/(({website}({web_link}|{port_link}))|\/{path}+{domain_name}\.{letter}+)|{domain_name}\@{domain_name}\.{letter}+) {printf("%s : value is valid", yytext);}
.+ {printf("%s is not valid", yytext);}
%%


int main()
{
    yylex();
    return 0;
}