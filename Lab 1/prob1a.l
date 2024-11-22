%{
#include<stdbool.h>
#include <stdio.h>
#include <string.h>

bool part_lang = false;
bool check(char*args);
void Runner(const char* inputFileName, const char* outputFileName);
%}

ws [ \t\n ]
%%
0?(10|1)*111(01|1)*0?  	{part_lang=true;} //if(check(yytext)) 
{ws}+ ;
.* ;
%%
bool check(char*args)
{
	bool seen0=false;
	while(*args)
	{
		if(*args == 0 && seen0) return false;
		else if(*args == 0) seen0=true;
		else{seen0=false;}
		args++;
	}
	return true;
}
int main()
{	
	Runner("input_prob1_a.txt","output_prob1_a.txt");
    	return 0;
}


void Runner(const char* inputFileName, const char* outputFileName)
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
		
		if (part_lang == true) {
	    		fprintf(output, "The String %s is in language\n", line);
		} else {
		    	fprintf(output, "The String %s is not in language\n", line);
		}
		part_lang = false;
	}
	fclose(input);
	fclose(output);
}
