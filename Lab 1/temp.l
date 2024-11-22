%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int xs=0;
int ys=0;
void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang);
bool check(char* args);
bool part_lang = false;
FILE* output;
%}
ws [ \t\n ]
commentEnd 	"\"*/\""
%%
{commentEnd} ;
\/\*([^*]|\*+[^*/])*\*\/ {
    // Remove the leading /* and trailing */
    char* temp = yytext + 2; // Skip /* at the start
    temp[strlen(temp) - 2] = '\0'; // Remove */ at the end

    fprintf(output, "Found comment as: %s\n", temp);
}
{ws}+ ;
%%
int main()
{	
	Runner("temp","temp_out.txt",&part_lang);
    	return 0;
}


void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang)
{
        FILE* input = fopen(inputFileName,"r");
	if(input==NULL)
	{
	printf("Input file is not exisiting in current directory,\nPlease make a file called input_prob_1_a.txt and enter in the testcases each seperated by newline for processing");
	}
	output = fopen(outputFileName,"w");
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
		
	}
	fclose(input);
	fclose(output);
}
