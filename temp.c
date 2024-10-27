#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main(int argv, char*argc)
{
    char* temp = (char*)malloc(SIZE*sizeof(char)), *t1;
    sprintf(temp,"t%d = %s;\n", 0, "lulu"); 
    strcpy(t1,temp);
    
    free(temp);
    printf("%s",t1);
}
