/*
JTSK-320111
a5 p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/


#include <stdio.h>
#include <string.h>
int main()
{
    char my_string[50];
    int i=0;

    fgets(my_string, sizeof(my_string),stdin);
    /*Strlen is used to determine the length of a string*/
    for (i=0; i<strlen(my_string)-1 ; i++)
    {
        if (i %2==0)  /*Checking if it is even or not*/
        {
            printf("%c\n", my_string[i]);
        }
        else
        {
            printf (" %c\n", my_string[i]);
        }
    }
    return 0;
}
