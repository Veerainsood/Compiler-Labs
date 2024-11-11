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
    char* array;
    char* type;
    typedef struct Node {
        char *key;
        char *value;
        struct Node *next;
    } Node;

    // Hash map structure
    typedef struct HashMap {
        Node *table[TABLE_SIZE];
        int size;
    } HashMap;

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
    void insert(HashMap *map,char *key, char *value) {
        unsigned int index = hash(key);
        Node *new_node = create_node(key, value);
        new_node->next = map->table[index];
        map->table[index] = new_node;
        map->size++;
    }

    // Search for a value by key in the hash map
    char *search(HashMap *map, const char *key) {
        unsigned int index = hash(key);
        Node *current = map->table[index];

        while (current != NULL) {
            if (strcmp(current->key, key) == 0) {
                return current->value;
            }
            current = current->next;
        }

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

    Stack* globStack;
    HashMap* currMap;

    void checkDeclaration(char* var, int newDecl)
    {
        Stack* tempStack = create_stack();
        if(newDecl && search(currMap,var)==NULL)
        {
            printf("%s type -> %s\n",var,type);
            array = var;
            insert(currMap,var,type);
            free_stack(tempStack);
            return;
        }
        while(!is_empty(globStack) && (search(currMap,var)==NULL))
        {
            push(tempStack, currMap);
            currMap = pop(globStack);
        }
        if((search(currMap,var)==NULL))
        {
            if(newDecl==0)
            {
                printf("Variable [`%s`]  not declared in all scopes\n",var);
                printf("I will add it anyways... sob sob weep weep\n");
            }
        }
        else if(newDecl)
        {
            char* val = search(currMap, var);
            printf("Error -> Redeclartion of variable [`%s`] !!\n",var);
            if(strcmp(val,type) !=0)
            {
                printf("Error -> Change of Type of variable [`%s`] !!\n",var);
                printf("I am a good compiler so I will change its type just like python\n");
                delete_key(currMap,var);
            }
        }
        else{
            //means type is defined....
            char* prevType = search(currMap,var);
            if(strcmp(prevType,type)!=0)
            {
                printf("%s = (%s)%s;\n", var,type,var);
            }
        }
        push(globStack,currMap);//put the currMap back...
        while(!is_empty(tempStack))
        {
            push(globStack,pop(tempStack));
        } 
        currMap = pop(globStack);//push in currMap...
        printf("%s type -> %s\n",var,type);
        array = var;
        insert(currMap,var,type);
        free_stack(tempStack);
    }

%}
%name parser

%union {
    char* str;
}

%token<str> VAR Floats ASSIGN SC LP RP CL CR INC  RELOP Else DEC Int If While BoolAnd BoolOr Float Char COMMA arrRP arrLP

%type<str> ElseExpr BoolExp Assignments WhileStatements Expr Fact S IfStatement DeclType VarDecl Arrays

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
    | Assignments {
        $$ = $1;
    } S
    | WhileStatements { 
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
    } C 
    ;
IfStatement:
    If LP BoolExp RP CL {
        printf("if t%d goto L%d\n goto L%d\n",tempVar-1,blockVar , blockVar+1);
        printf("L%d:\n",blockVar);
        free($1);// a way to reduce mem leaks
        blockVar+=2;
        IFCOUNTER++;
        handleClear(0);
    } S CR {   
        printf("L%d:\n",blockVar-1);
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

WhileStatements:
    While LP BoolExp RP CL {
        printf("if t%d goto L%d\n goto L%d\n", tempVar-1,blockVar , blockVar+1); 
        printf("L%d:\n",blockVar);
        blockVar+=2;
        IFCOUNTER++;
        handleClear(0);
    } S CR {   
        printf("goto%d:\n",blockVar-2);
        handleClear(0);
    }
    |
    While BoolExp error CR
    {
        yyerror("");
        printf("\t\t error : Expected \'(\' before %s \n\n",$2);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
    }
    |
    While LP BoolExp CL error Else CL S CR
    {
        yyerror("");
        printf("\t\t error : Expected \')\' after %s \n\n",$3);
        yyerrok;
        yyclearin;
        handleClear(1);
        eflag = 3;
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
    VAR ASSIGN Expr SC 
    {   
        checkDeclaration($1,0);
        char* Label = getLabels();
        printf("%s %s %s;\n",$1,$2,$3);
        printf("%s = %s;\n",Label,$1);
        $$ = Label;
    }
    | TypeDecl VAR ASSIGN Expr SC 
    {   
        checkDeclaration($2,1);
        insert(currMap,$2,type);
        char* Label = getLabels();
        printf("%s %s %s %s;\n",type,$2,$3, $4);
        printf("%s = %s;\n",Label,$2);
        $$ = Label;
    }
    |
    VAR INC SC { 
        checkDeclaration($1,0);
        char* Label = getLabels();
        printf("%s = %s\n",Label, $1);
        printf("%s = %s + 1\n",$1, $1);
        $$ = Label;
    } 
    | VAR DEC SC{ 
        checkDeclaration($1,0);
        char* Label = getLabels();
        printf("%s = %s\n",Label, $1);
        printf("%s = %s - 1\n",$1, $1);
        $$ = Label;
    } 
    | INC VAR SC{ 
        checkDeclaration($2,0);
        char* Label = getLabels();
        printf("%s = %s + 1\n",$1, $1);
        printf("%s = %s\n",Label, $1);
        $$ = Label;
    }
    | DEC VAR SC{ 
        checkDeclaration($2,0);
        char* Label = getLabels();
        printf("%s = %s - 1\n",$1, $1);
        printf("%s = %s\n",Label, $1);
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

Fact:   VAR INC { 
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
        | VAR { 
            checkDeclaration($1,0);
            char* Label = getLabels();
            printf("%s = %s;\n",Label,$1); 
            $$ = Label;
            array = $1;
        } C 
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

C:      Arrays
        {
            if(wentInArray)
            {
                printf("%s %s\n",array,$1);
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
                    $$ = sending;
                } else {
                    printf("Error: Memory allocation failed for 'sending'.\n");
                    $$ = NULL;
                    YYABORT;
                }
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
    free_stack(globStack);
    fclose(yyin);

    //handleClear(1); // Clean up before exiting
    return 0;
}
