#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void main()
{
    char name[32];
    char *names[5];
    int count = 0;
    //woody >>>
    int test1 = 0;
    int test2 = 1;
    int test3 = 2;
    //woody <<<

    for(count=0;count<5;count++)
    {
        printf("Enter a name %d: ", count+1);
        scanf("%s",name);
        names[count] = (char*) malloc(strlen(name)+1);
        strcpy(names[count],name);
    }
    //woody >>>
    printf("test1 = %d: ", test1);
    printf("test2 = %d: ", test2);
    printf("test3 = %d: ", test3);
    //woody <<<

    for(count=0;count<5;count++)
    {
        printf("%s   %p\n",names[count],names[count]);
    }
}