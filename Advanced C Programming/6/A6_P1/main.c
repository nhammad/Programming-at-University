/*
JTSK-320112
a6_p1.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE * pointer;
    char name[100];
    fgets(name, 100, stdin);
    //filename,size,stdin
    //fgets takes last value as newline
    //we do this to replace new line with end of line:
    name[strlen(name)-1] = '\0';
    char word[100];
    int count=0;
    pointer=fopen(name,"r");
    //r=read
    //feof tests the end-of-file indicator
    while (!feof(pointer))
    {
        //fscanf automatically skips \n,spaces etc
        fscanf(pointer, "%s",word);
        count++;
    }
    printf("The file contains %d words.",count);
    getchar();
    fclose(pointer);
    return 0;
}
