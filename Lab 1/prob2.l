%{
#include<stdbool.h>
#include <stdio.h>
#include <string.h>

bool part_lang = false;
void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang);
%}
ws [ \t\n ]
%%

(a|b|c|d)+(a)[^abcd](a|b|c|d)+a { part_lang = true; }
(a|b|c|d)+(b)[^abcd](a|b|c|d)+b { part_lang = true; }
(a|b|c|d)+(c)[^abcd](a|b|c|d)+c { part_lang = true; }
(a|b|c|d)+(d)[^abcd](a|b|c|d)+d { part_lang = true; }
{ws}+ ;
.* ;

%%
int main()
{	
	Runner("input_prob2.txt","output_prob2.txt",&part_lang);
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
		//these are inbuilt in lex and they read the incoming lines and run the yylex() fn and then this deletes the recorded cached buffer .
		
		if (*part_lang == true) {
	    		fprintf(output, "The String %s is in lang\n", line);
		} else {
		    fprintf(output, "The String %s is not in lang\n", line);
		}
		*part_lang = false;
	}
	fclose(input);
	fclose(output);
}
