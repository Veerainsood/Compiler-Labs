%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int xs=0;
int ys=0;
void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang);
bool check(char* args);
bool part_lang = false;
int zeros=0;
%}
ws [ \t\n ]
%%
(0|1)*  	{ 
			if(check(yytext)) {part_lang=true;} 
			else{part_lang=false;}
		}
{ws}+ ;
.* ;
%%
bool check(char*args)
{
	char* ptr_begin = args;
	char* ptr_end = args;
	while(*(ptr_end+1))
	{
		if(*ptr_end == '0')
		{
			zeros++;
		}
		ptr_end++;
	}	
	if(*ptr_end == '0')
	{
		
		zeros++;
	}
	while(*ptr_begin == *ptr_end && ptr_end - ptr_begin >=0)
	{
		ptr_begin++;
		ptr_end--;
	}
	if(zeros%4==0)
	{
		return true;
	}
	return false;
}
int main()
{	
	Runner("inp1.txt","out1.txt",&part_lang);
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
	    		fprintf(output, "The String %s is in lang\n", line);
		} else {
		    fprintf(output, "The String %s is not in lang\n", line);
		}
		fprintf(output, "the number of zeros is : %d\n", zeros);
		zeros=0;
		*part_lang = false;
	}
	fclose(input);
	fclose(output);
}	
