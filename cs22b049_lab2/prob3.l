%{

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define MAX_TOKENS 1000  // Adjust based on expected number of unique tokens

typedef struct {
    char token[MAX_LEN];
} Token;

Token uniqueTokens[MAX_TOKENS];
int tokenCount = 0;

FILE* input1;
FILE* output1;

bool isUnique(const char* token) {
    for (int i = 0; i < tokenCount; i++) {
        if (strcmp(uniqueTokens[i].token, token) == 0) {
            return false;
        }
    }
    return true;
}

void addToken(const char* description) {
    if (tokenCount < MAX_TOKENS && isUnique(description)) {
        strncpy(uniqueTokens[tokenCount].token, description, MAX_LEN - 1);
        uniqueTokens[tokenCount].token[MAX_LEN - 1] = '\0'; // Ensure null termination
        tokenCount++;
        fprintf(output1, "Lexeme:\"%s\"\n", description);
    }
}

%}

ws                                 	[ \t\n]+
alphabets_                 		[a-zA-Z_]
numbers                        		[0-9]
identifiers                        	{alphabets_}({alphabets_}|{numbers})*		 
floatingPointConst			({numbers}+(\.{numbers}+)?|\.[0-9]+)
integerConst				{numbers}+
keywords 			 ("#include"|"#define"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while")
stringConstants          			\"([^\\\n]|\\.)*\"
characterConstants   			\'([^\\\n]|\\.)\'
bitWiseOperators			"<<"|">>"|&|[\|]|[\^]|[\~]
Incremental_DecrementalOperator 	\+\+|--
LogicalOperators			!|"&&"|"||"
RelationalOperators   			<=|>=|<|>|!=
AssignmentOperators			\+=|\-=|\*=|\/=|\%=
ternaryOperator         			\?: 
ArithmaticOperators			[\+\-\*\/\%]
SpecialSymbols				[;,{}\(\)\[\]]
header					[<][a-zA-Z]*[\.][\h][>]
Comments 				\/\*([^"]|\".*\")*\*\/|\/\/.*

%%

{Comments} ;
"=="        		{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "== Logical Comparison Operator"); addToken(constant); }
"="			{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "= Assignment Operator"); addToken(constant); }
{header}		{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Header File", yytext); addToken(constant); }
{keywords}		{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Keyword", yytext); addToken(constant); }
{bitWiseOperators}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Bitwise Operator", yytext); addToken(constant); }
{LogicalOperators}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Logical Operator", yytext); addToken(constant); }
{RelationalOperators}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Relational Operator", yytext); addToken(constant); }
{AssignmentOperators}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Assignment Operator", yytext); addToken(constant); }
{integerConst}		{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Integer Constant", yytext); addToken(constant); }
{floatingPointConst}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Floating Point Constant", yytext); addToken(constant); }
{stringConstants}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s String Constant", yytext); addToken(constant); }
{SpecialSymbols}	{ char constant[MAX_LEN]; snprintf(constant, sizeof(constant), "%s Special Symbol", yytext); addToken(constant); }
{ArithmaticOperators}	{
				char constant[MAX_LEN];
				strncpy(constant, yytext, yyleng);
				constant[yyleng] = '\0';
				fprintf(output1,"Lexeme:\"%s\"        Arithmatic Operator.\n", constant);
			}
{identifiers}		{
				char constant[MAX_LEN];
				strncpy(constant, yytext, yyleng);
				constant[yyleng] = '\0';
				fprintf(output1,"Lexeme:\"%s\"        Identifiers found.\n", constant);
			}
{ws}+ ;  // Skip whitespace

%%

int main()
{	
    input1 = fopen("inp3.txt", "r");
    output1 = fopen("SymbolTable.txt", "w");
    if (input1 == NULL) 
    {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }
    
    yyin = input1;  
    yylex();  
    fclose(input1);
    fclose(output1);
    return 0;
}

