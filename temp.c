#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Node for linked list to handle collisions, storing both key and value as strings
typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

// Hash map structure
typedef struct HashMap {
    Node *table[TABLE_SIZE];
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
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = map->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
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
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
    return map;
}

// Create a new node for the hash map
Node *create_node(const char *key, const char *value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = strdup(key);      // Copy key string
    new_node->value = strdup(value);  // Copy value string
    new_node->next = NULL;
    return new_node;
}

// Insert a key-value pair into the hash map
void insert(HashMap *map, const char *key, const char *value) {
    unsigned int index = hash(key);
    Node *new_node = create_node(key, value);
    new_node->next = map->table[index];
    map->table[index] = new_node;
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

    free(current->key);
    free(current->value);
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



// Main function to demonstrate stack usage
int main() {
    Stack *stack = create_stack();

    // Create and push hash maps onto the stack
    HashMap *map1 = create_hashmap();
    insert(map1, "apple", "fruit");
    insert(map1, "carrot", "vegetable");
    push(stack, map1);

    HashMap *map2 = create_hashmap();
    insert(map2, "dog", "animal");
    insert(map2, "cat", "animal");
    push(stack, map2);

    // Peek at the top hash map
    HashMap *top_map = peek(stack);
    if (top_map != NULL) {
        printf("Top hash map, 'dog' is a: %s\n", search(top_map, "dog"));
    }

    // Pop the top hash map and free resources
    HashMap *popped_map = pop(stack);
    if (popped_map != NULL) {
        printf("Popped hash map, 'cat' is a: %s\n", search(popped_map, "cat"));
        free_hashmap(popped_map);
    }

    // Free the stack
    free_stack(stack);

    return 0;
}
