%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
    #include "y.tab.h"
    #define SIZE 100
    int yyerror(char*);
    extern FILE* yyin;
    int eflag = 0;  // Error flag for certain expressions
    extern int yylex();
    int yydebug = 0;
    int blockVar =0;
    int IFCOUNTER=0;
    typedef struct SymbolNode {
        char *token;
        char *type;
        int size;
        struct SymbolNode *next;
    } SyNode;

    typedef struct SymbolTable {
        SyNode* table[TABLE_SIZE];
        int size;
    } STable;

    STable* createSymbTable(){
        
        STable *table = (STable *)malloc(sizeof(STable));
        if (!table) {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        for (int i = 0; i < TABLE_SIZE; i++) {
            table->table[i] = NULL;
        }
        table->size = 0;
        return table;
    }

    void Sinsert(STable *Stable,char *token, char *type) {
        int size =0;
        if(strcmp(type,"int")==0)
        {
            size=4;
        }
        else if(strcmp(type,"float")==0)
        {
            size=8;
        }
        else
        {
            size=1;
        }
        if(Stable->size < TABLE_SIZE)
        {
            SyNode* new_node = (SyNode*)malloc(sizeof(SyNode));
            new_node->size = size;
            new_node->token =token;
            new_node->type = type;
            Stable->table[Stable->size] = new_node;
            Stable->size++;
        }
        else
        {
            printf("Symbol Table out of Space!!!\n");
        }
    }

    STable* SymbTable;
    
    void freeSTable()
    {
        int n = SymbTable->size;
        for(int i=0;i<n;i++)
        {
            if(SymbTable->table[i]!=NULL)
            {
                free(SymbTable->table[i]);
            }
        }
    }

    void Sprint()
    {
        printf("////////////////////////// SYMBOL TABLE //////////////////////////\n");
        
        // Define the width for each column for better alignment
        const int addr_width = 8;
        const int token_width = 20;
        const int type_width = 15;
        
        // Print the header row
        printf("%-*s%-*s%-*s\n", addr_width, "Addr", token_width, "Token", type_width, "Type");

        int n = SymbTable->size;
        int size = 0;

        // Iterate through the symbol table and print the entries
        for (int i = 0; i < n; i++) {
            printf("%-*d%-*s%-*s\n", addr_width, size, token_width, SymbTable->table[i]->token, type_width, SymbTable->table[i]->type);
            size += SymbTable->table[i]->size;
        }
        
        printf("//////////////////////////// END SYMBOL TABLE ////////////////////////\n");
    }

%}

%token Ol Or Cl Cr Void Flt Int Sc Var Com Opt

%union{
char* str;
}


%%

Slist: S {
		printf("Accepted\n");
		} Slist
		|{ printf("Done\n");}
		;
S:		Assignment
		{
			$4 = $1;
		}
		| Func
		{
			$4 = $1;
		}
		|
		
