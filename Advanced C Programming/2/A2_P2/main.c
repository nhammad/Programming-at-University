/*
JTSK-320112
a2_p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char stringA[100];
    char stringB[100];

    //without fgets,spaces aren't read
    fgets(stringA, sizeof(stringA),stdin);
    fgets(stringB, sizeof(stringB),stdin);

    //last position is always len-1 (\0)
    // '\0' represents the end of string
    //we replace the new line by 'end of line'

    stringA[strlen(stringA)-1] = '\0';
    stringB[strlen(stringB)-1] = '\0';

    //dynamic allocation:
    char *string = malloc(sizeof(char)*(strlen(stringA)+strlen(stringB)+1));
    int count=0;
    for(int i = 0; stringA[i] != '\0'; i++)
    {
        string[i] = stringA[i];
        count ++;
    }
    //count+j:
    //starts from where previous string ended
    for(int j = 0; stringB[j] != '\0'; j++)
    {
        string[j + count] = stringB[j];
    }
    string[strlen(stringA) + strlen(stringB)] = '\0';
    printf("Result of concatenation: %s\n",string);
    free(string);
    return 0;
}
