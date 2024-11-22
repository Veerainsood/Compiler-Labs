%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    #define SIZE 100
    #define TABLE_SIZE 100
    int yyerror(char*);
    extern FILE* yyin;
    int eflag = 0;  // Error flag for certain expressions
    extern int yylex();
    int yydebug = 0;
    int wentInArray=0;
    int blockVar =0;
    int IFCOUNTER=0;
    int tempVar=0;
    char* allocations[1000];
    int allocated=0;
    int ifStmntPtr=0;
    int lineNumber=1;
    int forIncrementer;
    char* array;
    char* type;

    //////////////////////////////////////////// SYMBOL TABLE BEGIN /////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////// SYMBOL TABLE  END /////////////////////////////////////////////////////////////////

//////////////////////////////////////////// HASH MAP BEGIN /////////////////////////////////////////////////////////////////

    typedef struct Node {
        char *key;
        char *value;
        int index;
        struct Node *next;
    } Node;

    typedef struct package{
        char* value;
        int index;
    } pkg;

    // Hash map structure
    typedef struct HashMap {
        Node *table[TABLE_SIZE];
        int size;
    } HashMap;

    // Free all memory used by the hash map
    void free_hashmap(HashMap *map) {
        if (map == NULL) return;
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node *current = map->table[i];
            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp);
            }
            map->table[i] = NULL;  // Nullify after free
        }
        free(map);
    }

    // Hash function for strings
    unsigned int hash(const char *key) {
        unsigned long int hash_value = 0;
        int i = 0;

        while (key[i] != '\0') {
            hash_value = hash_value * 37 + key[i];
            i++;
        }

        return hash_value % TABLE_SIZE;
    }

    // Initialize hash map
    HashMap* create_hashmap() {
        HashMap *map = (HashMap *)malloc(sizeof(HashMap));
        if (!map) {
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        for (int i = 0; i < TABLE_SIZE; i++) {
            map->table[i] = NULL;
        }
        map->size = 0;
        return map;
    }

    // Create a new node for the hash map
    Node *create_node(const char *key, const char *value) {
        
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->key = key;      // Copy key string
        new_node->value = value;  // Copy value string
        new_node->next = NULL;
        return new_node;
    }

    // Insert a key-value pair into the hash map
    void insert(HashMap *map,char *key, char *value,int STableIndex) {
        unsigned int index = hash(key);
        Node *new_node = create_node(key, value);
        new_node->next = map->table[index];
        if(STableIndex==-1)
        {
            new_node->index = SymbTable->size-1;
        }
        else
        {
            new_node->index = STableIndex;
        }
        map->table[index] = new_node;
        map->size++;
    }

    // Search for a value by key in the hash map
    pkg* search(HashMap *map, const char *key) {
        unsigned int index = hash(key);
        Node *current = map->table[index];
        pkg* pack = (pkg*)malloc(sizeof(pkg));
        while (current != NULL) {
            if (strcmp(current->key, key) == 0) {
                pack->value = current->value;
                pack->index = current->index;
                return pack;
            }
            current = current->next;
        }
        free(pack);
        return NULL;  // Key not found
    }

    // Delete a key-value pair from the hash map
    void delete_key(HashMap *map, const char *key) {
        unsigned int index = hash(key);
        Node *current = map->table[index];
        Node *prev = NULL;

        while (current != NULL && strcmp(current->key, key) != 0) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;  // Key not found

        if (prev == NULL) {  // Key is in the first node
            map->table[index] = current->next;
        } else {
            prev->next = current->next;
        }
        map->size--;
        free(current);
    }
//////////////////////////////////////////// HASH MAP END /////////////////////////////////////////////////////////////////

//////////////////////////////////////////// STACK BEGIN /////////////////////////////////////////////////////////////////


    // Stack node definition
    typedef struct StackNode {
        HashMap *map;
        struct StackNode *next;
    } StackNode;

    // Stack structure
    typedef struct Stack {
        StackNode *top;
        int size;
    } Stack;
    // Function to create a new stack
    Stack *create_stack() {
        Stack *stack = (Stack *)malloc(sizeof(Stack));
        stack->top = NULL;
        stack->size = 0;
        return stack;
    }

    // Push a hash map onto the stack
    void push(Stack *stack, HashMap *map) {
        StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
        new_node->map = map;
        new_node->next = stack->top;
        stack->top = new_node;
        stack->size++;
    }

    // Pop a hash map from the stack
    HashMap *pop(Stack *stack) {
        if (stack->top == NULL) {
            printf("Stack is empty!\n");
            return NULL;
        }

        StackNode *top_node = stack->top;
        HashMap *map = top_node->map;
        stack->top = top_node->next;
        free(top_node);
        stack->size--;
        return map;
    }

    // Peek at the top hash map without removing it
    HashMap *peek(Stack *stack) {
        if (stack->top == NULL) {
            printf("Stack is empty!\n");
            return NULL;
        }
        return stack->top->map;
    }

    // Check if the stack is empty
    int is_empty(Stack *stack) {
        return stack->top == NULL;
    }

    // Free the entire stack
    void free_stack(Stack *stack) {
        while (!is_empty(stack)) {
            HashMap *map = pop(stack);
            free_hashmap(map);  // Free each hash map in the stack
        }
        free(stack);
    }

//////////////////////////////////////////// STACK END //////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Loop Stack Begin///////////////////////////////////////////////////////////////////

    typedef struct {
        int data[TABLE_SIZE];
        int top;
    } LoopStack;

    // Initialize a stack
    void initStack(LoopStack *stack) {
        stack->top = -1;
    }

    // Push an element onto the stack
    void pushLoop(LoopStack *stack, int value) {
        if (stack->top >= TABLE_SIZE - 1) {
            fprintf(stderr, "Stack overflow\n");
            exit(EXIT_FAILURE);
        }
        stack->data[++stack->top] = value;
    }

    // Pop an element from the stack
    int popLoop(LoopStack *stack) {
        if (stack->top < 0) {
            fprintf(stderr, "Stack underflow\n");
            exit(EXIT_FAILURE);
        }
        return stack->data[stack->top--];
    }

    // Peek the top element of the stack without popping
    int peekLoop(LoopStack *stack) {
        if (stack->top < 0) {
            fprintf(stderr, "Stack is empty\n");
            exit(EXIT_FAILURE);
        }
        return stack->data[stack->top];
    }

/////////////////////////////// Loop Stack Ends //////////////////////////////////////////////////////////////////////////////////

    Stack* globStack;
    HashMap* currMap;

    void restoreShitDone(Stack* tempStack,char* var)
    {
        push(globStack,currMap);//put the currMap back...
        while(!is_empty(tempStack))
        {
            push(globStack,pop(tempStack));
        } 
        printf("%s type -> %s\n",var,type);
        currMap = pop(globStack);//push in currMap...
        array = var;
    }

    char* getLabels()
    {
        char* tVar = (char*)malloc(10*sizeof(char));
        snprintf(tVar,10,"t%d",tempVar++);
        allocations[allocated++] = tVar;
        return tVar;

    }
    void handleClear(int val)
    {
        lineNumber=1;
        ifStmntPtr=0;
        if(val)
        {
            tempVar=0;
            blockVar=0;
        }
    }

    void checkDeclaration(char* var, int newDecl)
    {
        Stack* tempStack = create_stack();
        pkg* package = search(currMap,var);
        //  package->value -> gives type...
        //  package->index -> gives symbol table index...
        if(newDecl && package==NULL)
        {
            Sinsert(SymbTable,var,type);    //STable *Stable,char *token, char *type,int space
            restoreShitDone(tempStack,var);
            insert(currMap,var,type,-1);
            free_stack(tempStack);
            return;
        }
        while(!is_empty(globStack) && (package==NULL))
        {
            push(tempStack, currMap);
            currMap = pop(globStack);
            package = search(currMap,var);
        }
        if(package==NULL)
        {
            printf("Variable [`%s`]  not declared in all scopes\n",var);
            printf("I will add it anyways... sob sob weep weep\n");
            Sinsert(SymbTable,var,type);//STable *Stable,char *token, char *type,int space
            restoreShitDone(tempStack,var);
            insert(currMap,var,type,-1);
        }
        else if(newDecl)
        {
            char* val = package->value;
            printf("Error -> Redeclartion of variable [`%s`] !!\n",var);
            if(strcmp(val,type) !=0)
            {
                printf("Error -> Change of Type of variable [`%s`] !!\n",var);
                printf("I am a good compiler so I will change its type just like python\n");
                SymbTable->table[package->index]->type = type;
                delete_key(currMap,var);
                restoreShitDone(tempStack,var);
                insert(currMap,var,type,package->index);
            }
            else{
                restoreShitDone(tempStack,var);
                free(package);
                free_stack(tempStack);
                return;
            }
            free(package);
        }
        else{
            //means type is defined....
            char* prevType = package->value; 
            if(strcmp(prevType,type)!=0)
            {
                printf("%s = (%s)%s;//typeCasting on the fly!!!\n", var,type,var);
                free(package);
            }
            else
            {
                restoreShitDone(tempStack,var);
                free(package);
                free_stack(tempStack);
                return;//of same type no type conversion needed...
            }
            restoreShitDone(tempStack,var);
        }
        free_stack(tempStack);
    }
    int forStart=0,forIf=0;

    LoopStack forStartStack, forIfStack, forIncrementerStack;
    Stack whileStartStack, whileEndStack;
%}
%name parser

%union {
    char* str;
}

%token<str> VAR Floats ASSIGN SC LP RP CL CR INC  RELOP Else DEC Int If While BoolAnd BoolOr Float Char COMMA arrRP arrLP For

%type<str> ElseExpr BoolExp Assignments WhileStatements Expr Fact S IfStatement DeclType VarDecl Arrays ForStatements Increments MegAssign

%left BoolOr
%left BoolAnd
%left '|'
%left '^'
%left '&'
%left  RELOP
%left '+' '-'
%left '*' '/' '%'
%nonassoc INC DEC  

%%

S:  IfStatement { 
        if(eflag == 0) 
        {
            if(IFCOUNTER==1)
            {
                printf("\t\t Accepted!\n\n");
                printf("\nProcessing Next Input\n");
                tempVar=0;
                blockVar=0;
            }
            else
            {
                blockVar-=2;
            }
            IFCOUNTER--;
        }
        else if(eflag == 1)
        {
            printf("float not to be used with modulo symbol\n\n");
            handleClear(1);
        }
        else if( eflag==2)
        {
            printf("\t\t Operands not found\n\n");
            handleClear(1);
        }

    } S
    | MegAssign SC {
        $$ = $1;
    } S
    | WhileStatements { 
        $$ = $1;
    }  S
    | ForStatements { 
        $$ = $1;
    }  S
    | VarDecl
    {
        $$ = $1;
    } S
    | CL {
        push(globStack,currMap);
        currMap = create_hashmap();
    } S CR {
        $$ = $1;
        if(currMap!=NULL)
        {
            free_hashmap(currMap);
        }
        if(globStack->size>0)
        {
            currMap = pop(globStack);//restore old type info...
        }
    } S
    | {}
    ;

DeclType:
    Int
    {
        $$ = $1;
    }
    | Float 
    {
        $$ = $1;
    }
    | Char 
    {
        $$ = $1;
    }
    ;

TypeDecl:
    DeclType { type = $1; }
    ;

VarDecl:
    TypeDecl L SC {
        $$ = "";
    } 
    ;

L:  L COMMA VAR
    {
        checkDeclaration($3,1);
    }
    | VAR {
        checkDeclaration($1,1);
    } C {
            if(wentInArray)
            {
                pkg* pack = search(currMap,$1);
                SymbTable->table[pack->index]->type = "Array";
                wentInArray=0;
            }
    }
    ;
MegAssign:  Assignments
            {
                $$ = $1;
            }
            | Increments
            {
                $$ = $1;
            }
            ;

IfStatement:
    If LP BoolExp RP CL {
        push(globStack,currMap);
        currMap = create_hashmap();
        printf("if t%d goto L%d\n goto L%d\n",tempVar-1,blockVar , blockVar+1);
        printf("L%d:\n",blockVar);
        free($1);// a way to reduce mem leaks
        blockVar+=2;
        IFCOUNTER++;
        handleClear(0);
    } S CR {   
        printf("L%d:\n",blockVar-1);
        if(currMap!=NULL)
        {
            free_hashmap(currMap);
        }
        if(globStack->size>0)
        {
            currMap = pop(globStack);//restore old type info...
        }
        handleClear(0);
    }  ElseExpr
    |
    If BoolExp error CR
    {
        yyerror("");
        printf("\t\t error : Expected \'(\' before %s \n\n",$2);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    |
    If LP BoolExp CL error CR
    {
        yyerror("");
        printf("\t\t error : Expected \')\' after %s \n\n",$3);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    ;

ElseExpr:
    Else CL S CR {}
    | {}
    ;
ForStatements:
    For LP MegAssign SC {
        printf("L%d:\n", blockVar);
        pushLoop(&forIncrementerStack, blockVar);
        blockVar++;
    } BoolExp SC {
        printf("For Loop's IF statement begins here:\nif t%d goto L%d\n goto L%d\n", tempVar-1, blockVar, blockVar+1); 
        pushLoop(&forIfStack, blockVar);
        blockVar += 2;
        handleClear(0);
        printf("L%d:\n", blockVar);
        pushLoop(&forStartStack, blockVar);
    } MegAssign RP CL {
        int forIncrementer = popLoop(&forIncrementerStack);
        printf("goto L%d\n", forIncrementer);
        printf("L%d:\n", popLoop(&forIfStack));
        push(globStack,currMap);
        currMap = create_hashmap();
        blockVar++;
    } S CR {
        printf("goto L%d\n", popLoop(&forStartStack)); 
        if(currMap!=NULL)
        {
            free_hashmap(currMap);
        }
        if(globStack->size>0)
        {
            currMap = pop(globStack);//restore old type info...
        }
        handleClear(0);
    };


WhileStatements:
    While { 
        int whileStart = blockVar++;  // Label for the start of the loop
        printf("L%d:\n", whileStart);  // Emit label at the start of the loop
        push(&whileStartStack, whileStart); 
    } LP BoolExp RP CL {
        int whileEnd = blockVar;  // Label for the end of the loop's conditional check
        printf("While loop's IF statement begins here:\n");
        printf("if t%d goto L%d\n", tempVar-1, whileEnd); // Jump to loop body if condition is true
        printf("L%d:\n",whileEnd);
        push(&whileEndStack, blockVar + 1);
        blockVar += 2;
        handleClear(0);
    } S CR {
        int whileStart = pop(&whileStartStack);
        int whileEnd = pop(&whileEndStack);
        printf("goto L%d\n", whileStart);  // Jump back to the loop's start
        printf("L%d:\n", whileEnd);  // Emit label for the end of the loop
        handleClear(0);
    }
    ;

BoolExp:
    Expr RELOP Expr {
        char* Label = getLabels();
        printf("%s = (%s %s %s);\n",Label,$1,$2,$3);
        $$ = Label;
    }
    | Assignments {}
    | '!' Expr {
        char* Label = getLabels();
        printf("%s = ! ( %s );\n",Label,$2);
        $$ = Label;
    }
    | BoolExp BoolAnd BoolExp{
        char* Label = getLabels();
        printf("%s =  (%s && %s) ;\n",Label,$1,$3);
        $$ = Label;
    } 
    | BoolExp BoolOr BoolExp  {
        char* Label = getLabels();
        printf("%s =  (%s || %s) ;\n",Label,$1,$3);
        $$ = Label;
    } 
    ;

Assignments: 
    VAR ASSIGN Expr 
    {   
        checkDeclaration($1,0);
        char* Label = getLabels();
        printf("%s %s %s;\n",$1,$2,$3);
        printf("%s = %s;\n",Label,$1);
        $$ = Label;
    }
    | TypeDecl VAR ASSIGN Expr
    {   
        checkDeclaration($2,1);
        char* Label = getLabels();
        printf("%s %s %s %s;\n",type,$2,$3, $4);
        printf("%s = %s;\n",Label,$2);
        $$ = Label;
    }
    | error SC{
        yyerror("");
        printf("Missing \';\' or some syntax issue you have chanted ;) :) \n");
        yyerrok;
        yyclearin;
        handleClear(1);
    }
    ;

Op: '+'|'-'|'/'|'%'|'*';

Expr: Expr '+' Expr 
    { 
        // Generate TAC for addition
        char* Label = getLabels();
        printf("%s = %s + %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '-' Expr 
    { 
        // Generate TAC for subtraction
        char* Label = getLabels();
        printf("%s = %s - %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '^' Expr 
    { 
        // Generate TAC for or
        char* Label = getLabels();
        printf("%s = %s ^ %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '*' Expr 
    { 
        // Generate TAC for multiplication
        char* Label = getLabels();
        printf("%s = %s * %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '/' Expr 
    {   
        // Generate TAC for division
        char* Label = getLabels();
        printf("%s = %s / %s\n",Label, $1, $3);
        $$ = Label;
    }
    | Expr '%' Expr
    {
        if (strchr($1, '.') == NULL && strchr($3, '.') == NULL)
        {
            char* Label = getLabels();
            printf("%s = %s \% %s\n",Label, $1, $3);
            $$ = Label;
        }
        else
        {
            eflag = 1;  
        }
    }
    |
    Expr Op
    {
        eflag=2;
    }
    | Fact
    {
        $$ = $1;
    }
    ;

Fact:   Increments
        |
        VAR { 
            checkDeclaration($1,0);
            char* Label = getLabels();
            printf("%s = %s;\n",Label,$1); 
            $$ = Label;
            array = $1;
            
        } C {
            if(wentInArray)
            {
                pkg* pack = search(currMap,$1);
                SymbTable->table[pack->index]->type = "Array";
                wentInArray=0;
            }
        }
        | Floats C { 
            char* Label = getLabels();
            printf("%s = %s;\n",Label,$1); 
            $$ = Label;
            array = NULL;
        }
        | Floats INC error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | Floats DEC error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | DEC Floats error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | INC Floats error
        {
            yyerror("");
            printf("\t\tcannot increment a constant\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        | LP Expr RP 
        { 
            $$ = $2; 
        }
        | LP Expr error
        {
            yyerror("");
            printf("\t\tno ) detected after (\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        ;

Increments: VAR INC { 
                checkDeclaration($1,0);
                char* Label = getLabels();
                printf("%s = %s\n",Label, $1);
                printf("%s = %s + 1\n",$1, $1);
                $$ = Label;
            } 
            | VAR DEC { 
                checkDeclaration($1,0);
                char* Label = getLabels();
                printf("%s = %s\n",Label, $1);
                printf("%s = %s - 1\n",$1, $1);
                $$ = Label;
            } 
            | INC VAR { 
                checkDeclaration($2,0);
                char* Label = getLabels();
                printf("%s = %s + 1\n",$1, $1);
                printf("%s = %s\n",Label, $1);
                $$ = Label;
            }
            | DEC VAR { 
                checkDeclaration($2,0);
                char* Label = getLabels();
                printf("%s = %s - 1\n",$1, $1);
                printf("%s = %s\n",Label, $1);
                $$ = Label;
            }

C:      Arrays
        {
            if(wentInArray)
            {
                printf("%s %s\n",array,$1);
                free($1);
            }
        }
        |
        VAR error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        |
        Floats error
        {
            yyerror("");
            printf("\t\t no operators between Operands\n\n");
            yyerrok;
            yyclearin;
            handleClear(1);
        }
        ;

Arrays: arrLP Floats arrRP Arrays
        {
            // Copy the original number
            if(array == NULL)
            {
                printf("Error -> Please dont use array operations with floats...!!!\n");
                $$ = "";
            }
            else{
                wentInArray = 1;
                char* number = $2;
                if (number == NULL) {
                    printf("Error: Memory allocation failed for 'number'.\n");
                    YYABORT; // or handle error
                }

                if (strchr(number, '.') != NULL) {
                    printf("Error: Using floats as array indices is not allowed!\nTruncating...to integer..\n");

                    // Find the position of the decimal point
                    char* dot_position = strchr(number, '.');
                    int int_part_length = dot_position - number;

                    // Allocate memory for the integer part
                    char* integer_part = (char*)malloc(int_part_length + 1);
                    if (integer_part != NULL) {
                        strncpy(integer_part, number, int_part_length);
                        integer_part[int_part_length] = '\0';

                        // Free original number and assign integer_part to number
                        free(number);
                        number = integer_part;
                    } else {
                        // On memory allocation failure, set number to "0"
                        free(number);
                        number = "0";
                        if (number == NULL) {
                            printf("Error: Memory allocation failed for '0'.\n");
                            YYABORT;
                        }
                    }
                }

                // Create the output string
                char* sending = (char*)malloc(20000);
                if (sending != NULL) {
                    sprintf(sending, "array(%s , %s)", number, $4);
                    free($4);
                    $$ = sending;    
                } else {
                    printf("Error: Memory allocation failed for 'sending'.\n");
                    $$ = NULL;
                    YYABORT;
                }
                free(sending);
                // Clean up
                free(number);    
            }
            
        }
        | {
            $$ = "";
        } 
        ;

%%
int yyerror(char* err) {
    return 0;
}

int main(int argc, char* argv[]) {
    int yydebug = 1;
    globStack = create_stack();
    currMap = create_hashmap();
    SymbTable = createSymbTable();
    initStack(&forStartStack);
    initStack(&forIfStack);
    initStack(&forIncrementerStack);
    initStack(&whileStartStack);
    initStack(&whileEndStack);
    handleClear(1);
    // Rest of the main function
    if (argc > 1) {
        FILE* inp = fopen(argv[1], "r");
        if (inp != NULL) {
            yyin = inp;
        } else {
            fprintf(stderr, "Failed to open file: %s\n", argv[1]);
            return 1;
        }
    }
    for(int i=0;i<allocated;i++)
    {
        free(allocations[i]);
    }
    yyparse();
    Sprint(SymbTable);
    freeSTable();
    free(SymbTable);
    free_stack(globStack);
    fclose(yyin);

    //handleClear(1); // Clean up before exiting
    return 0;
}
