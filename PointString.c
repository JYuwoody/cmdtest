#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void main()
{
    char name[32];
    char *names[5];
    int count = 0;

    for(count=0;count<5;count++)
    {
        printf("Enter a name %d: ", count+1);
        scanf("%s",name);
        names[count] = (char*) malloc(strlen(name)+1);
        strcpy(names[count],name);
    }
    for(count=0;count<5;count++)
    {
        printf("%s   %p\n",names[count],names[count]);
    }
}