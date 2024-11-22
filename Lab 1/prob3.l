%{
#include<stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 1024
bool part_lang = false;
void Runner(const char* inputFileName, const char* outputFileName, bool* part_lang);
char Scheme[MAX_LEN];
char UserNames[MAX_LEN];
char Passwords[MAX_LEN];
char Hosts[MAX_LEN];
char Ports[MAX_LEN];
char Paths[MAX_LEN];
char query[MAX_LEN];
char fragment[MAX_LEN];
void setter(char* host, char* port, char* path);
void clearArray(char* arr) {
    memset(arr, '\0', sizeof(arr));
}
%}

ws 			[ \t\n ]
Scheme			(("http")?|("https")?|("ftp")?|("file")?)
MailTo			("mailto")
Alphabets_ 		[a-zA-Z_]
Numbers			[0-9]
SpecialCharacters	[!@#$%^&*()_+\-=\[\]{};:,.<>?/]
UserName		{Alphabets_}+({Alphabets_}|{Numbers})*
Password		({SpecialCharacters}|{Alphabets_}|{Numbers}){1,25}
Host    	        ({Alphabets_}|{Numbers})+([.])(({Alphabets_}|{Numbers})+([.])?)*
PortNumber		{Numbers}{0,5}
Path            	([/]|{Alphabets_}|{Numbers}|([.])?)+
Queries			({SpecialCharacters}|{Alphabets_}|{Numbers})*
%%

{Scheme}("://")					{
							strncpy(Scheme, yytext,yyleng - 3);
							Scheme[yyleng - 3]='\0'; 
							printf("Scheme is %s\n", Scheme);
						}
{UserName}":"{Password}"@"			{	
							char str[MAX_LEN];
							strncpy(str, yytext,yyleng - 1);
							char* user = strtok(str, ":");
    							char* pass = strtok(NULL, ":");
							if (!strcmp(UserNames,"mailto") && UserNames !=NULL && Passwords != NULL) {
								strncpy(UserNames, user, strlen(yytext));
								UserNames[strlen(UserNames)]='\0';
								strncpy(Passwords, pass, MAX_LEN - 1);
								Passwords[strlen(Passwords)]='\0';
								printf("Username: %s\n", UserNames);
								printf("Password: %s\n", Passwords);
								clearArray(UserNames);
								clearArray(Passwords);
						    	}
						}
("www.")?{Host}(":")?{PortNumber}?{Path}*	{	//length of port Numbers can be at max 5 digit
							char str[MAX_LEN];
							strncpy(str,yytext,strlen(yytext));
							if(strchr(str, ':') != NULL)
							{
								char* host    = strtok(str, ":");
	    							char* portNum = strtok(NULL, "/");
	    							char* path = strtok(NULL, "");
	    							setter(host,portNum,path);	
    							}
    							else
    							{
    								char* host    = strtok(str, "/");
	    							char* path = strtok(NULL, "");
	    							char* portNum =NULL;
	    							setter(host,portNum,path);	
							}
							    							
						}
{Path}+						{
							char str[MAX_LEN];
				
							strncpy(str,yytext,strlen(yytext));
    							char* path = str;
    							setter(NULL,NULL,path);	
    						}
						

"?"{Queries}*					{	//length of port Numbers can be at max 5 digit
							char str[MAX_LEN];
							strncpy(str,yytext+1,strlen(yytext));
							int i=0;
							char* temp = strtok(str, "&");
							while(*str)
							{
								strncpy(query,temp,strlen(temp));
								i++;
								printf("Query %d is %s\n",i,query);
								temp = strtok(NULL, "&");
								if(temp==NULL){
									break;
								}
							}
							
						}
						
{ws}+;

%%

int main()
{	
	Runner("input_prob3.txt","output_prob3.txt",&part_lang);
    	return 0;
}

void setter(char* host, char* portNum, char* path)
{
	if (host != NULL) 
	{
		strncpy(Hosts, host, strlen(host));
		Hosts[strlen(host)] = '\0';  // Ensure null-termination
    	}
    	if (portNum != NULL) 
    	{
		strncpy(Ports, portNum, strlen(portNum));
		Ports[strlen(portNum)] = '\0';  // Ensure null-termination
    	}
    	if (path != NULL) 
    	{
		strncpy(Paths, path, strlen(path));
		Paths[strlen(path)] = '\0';  // Ensure null-termination
    	}
    	
	if (Hosts != NULL) {
		printf("Host name is %s\n", Hosts);
		clearArray(Hosts);
	}
	if (Ports != NULL ) {
		printf("Port is %s\n", Ports);
		clearArray(Ports);
	}
	if (Paths != NULL ) {
		printf("Path is %s\n", Paths);
		clearArray(Paths);
	}
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
