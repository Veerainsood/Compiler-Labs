%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int xs=0;
int ys=0;
void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang);
bool check(char* args);
bool part_lang = false;

%}

ws              		[ \t\n]
int             		"int"
float           		"float"
alphabets_      		[a-zA-Z_]
numbers         		[0-9]
varName         		{alphabets_}({alphabets_}|{numbers})*
equals          		"="
assignment_int  		(" ")*{varName}(" ")*{equals}(" ")*[-]?{numbers}+
multiple_assignment_int 	{int}(" ")+{assignment_int}(" ")*([,]{assignment_int}(" ")*)*;
assignment_float 		(" ")*{varName}(" ")*{equals}(" ")*[-]?{numbers}*([.]{numbers}+)?
multiple_assignment_float 	{float}(" ")+{assignment_float}(" ")*([,]{assignment_float}(" ")*)*;

%%
({multiple_assignment_int}|{multiple_assignment_float}) 	{ part_lang = true;}
{ws}+ ;
.* ;
%%
bool check(char*args)
{
	//unused
}
int main()
{	
	Runner("inp2.txt","out2.txt",&part_lang);
    	return 0;
}


void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang)
{
        FILE* input = fopen(inputFileName,"r");
	if(input==NULL)
	{
	printf("Input file is not exisiting in current directory,\nPlease make a file called input_prob_1_a.txt and enter in the testcases each seperated by newline for processing");
	}
	FILE* output = fopen(outputFileName,"w");
        char line[256];
    	while (fgets(line, sizeof(line), input)) {
		int len = strlen(line);
		if (len > 0 && line[len-1] == '\n') {
		    line[len-1] = '\0'; 	//making sure that the string is readable by lex scanner.
		}

		YY_BUFFER_STATE buffer = yy_scan_string(line);
		yylex();
		yy_delete_buffer(buffer);
		//reads and runs yylex and then this deletes the recorded cached buffer .
		
		if (*part_lang == true) {
	    		fprintf(output, "The String {%s} is in lang\n", line);
		} else {
		    fprintf(output, "The String {%s} is not in lang\n", line);
		}	
		*part_lang = false;
	}
	fclose(input);
	fclose(output);
}	
