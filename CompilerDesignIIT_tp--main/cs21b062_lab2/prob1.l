%{ //definitions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for symbol table entry
struct Symbol_table_entry
{
char lexeme[100];
char token[100];
};

struct Symbol_table_entry ST_value[1000]; // Symbol table
int table_index = 0; // Size of symbol table

void Adding_value(const char *lexeme, const char *token) // Adding value to symbol table
{
strcpy(ST_value[table_index].lexeme, lexeme);
strcpy(ST_value[table_index].token, token);
table_index++;
}

void Make_ST_file() // putting the table into the file
{

FILE *fp = fopen("symbol_table.txt", "w");

if (fp == NULL)
{
fprintf(stderr, "Error \n");
exit(1);
}
// printing the table
for (int i = 0; i < table_index; ++i)
{

fprintf(fp, "%s\t%s\n", ST_value[i].lexeme, ST_value[i].token);
}

fclose(fp);
}

%}



s_cmnt \/\*
e_cmnt \*\/

%%
\/\/(.*) ;
{s_cmnt}(.|[\r\n])*{e_cmnt} ;  // Remove comments
[\t\r]+ ;// remove whitespace and tabs
[\n] ; // Ignore newlines
"int" { Adding_value(yytext, "Keyword: int"); printf("%s\t%s\n", yytext, "Keyword: int"); }   //keywords 
"float" {  Adding_value(yytext, "Keyword: float"); printf("%s\t%s\n", yytext, "Keyword: float"); }
"double" { Adding_value(yytext, "Keyword: double"); printf("%s\t%s\n", yytext, "Keyword: double"); }
"char"  { Adding_value(yytext, "Keyword: char"); printf("%s\t%s\n", yytext, "Keyword: char"); }
"if"    { Adding_value(yytext, "Keyword: if"); printf("%s\t%s\n", yytext, "Keyword: if"); }
"else"  { Adding_value(yytext, "Keyword: else"); printf("%s\t%s\n", yytext, "Keyword: else") ;}
"switch"  { Adding_value(yytext, "Keyword: switch"); printf("%s\t%s\n", yytext, "Keyword: switch"); }
"case"  { Adding_value(yytext, "Keyword: case"); printf("%s\t%s\n", yytext, "Keyword: case") ;}
"while" { Adding_value(yytext, "Keyword: while"); printf("%s\t%s\n", yytext, "Keyword: while"); }
"for" {  Adding_value(yytext, "Keyword: for"); printf("%s\t%s\n", yytext, "Keyword: for"); }
"printf" { Adding_value(yytext, "Keyword: printf"); printf("%s\t%s\n", yytext, "Keyword: printf ");}
"scanf" { Adding_value(yytext, "Keyword: scanf"); printf("%s\t%s\n", yytext, "Keyword: scanf");}
"return" { Adding_value(yytext, "Keyword: return"); printf("%s\t%s\n", yytext, "Keyword: return");}
[\"][A-Za-z0-9]*[\"]  {Adding_value(yytext, "Constant: string "); printf("%s\t%s\n", yytext, "string Constant"); }
[\'][A-Za-z0-9]*[\']  {Adding_value(yytext, "Constant: char Constant"); printf("%s\t%s\n", yytext, "char Constant"); }
[A-Za-z][A-Za-z0-9]* { Adding_value(yytext, "basic: Identifier"); printf("%s\t%s\n", yytext, "basic: Identifier"); } //identifiers 
[0-9]+\.[0-9]+ { Adding_value(yytext, "Constant: Float Constant"); printf("%s\t%s\n", yytext, "Float Constant"); }  //constants 
[0-9]+ { Adding_value(yytext, "Constant: Integer Constant"); printf("%s\t%s\n", yytext, "Integer Constant"); }
[\;\,\{\}\(\)]  { Adding_value(yytext, "Seperator :list"); printf("Token: %s, Lexeme: %s\n", yytext ,"Seperator: list"); }  //seperators
[\-\>] { Adding_value(yytext, "pointer operator"); printf("Token: %s, Lexeme: %s\n", yytext ,"pointer operator"); } //pointor
[\+\-\*\/\=\%\!\>\<\^]   { Adding_value(yytext, "Operator"); printf("Token: %s, Lexeme: %s\n", yytext ,"Operator"); } //Operator
[\>\<\!\|\&|:]   { Adding_value(yytext, "Relational Operator"); printf("Token: %s, Lexeme: %s\n", yytext ,"Relational Operator"); } //Rel Operator
.; // Ignore some other characers

%%

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
return 1;
}

yyin = fopen(argv[1], "r");
if (yyin == NULL)
{
fprintf(stderr, "Error opening input file.\n");
return 1;
}

yylex();

Make_ST_file();

fclose(yyin);
return 0;
}