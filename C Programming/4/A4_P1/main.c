/*
JTSK-320111
a4 p1.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int position(char str[], char c)
{
    int idx;
    /* Loop until end of string */
    for (idx = 0; str[idx] != c && str[idx] != '\0'; ++idx)
    {
    }
    return idx;
    /*Without braces, there's an error. The program won't move towards the main (second) part unless we end the first one*/
}
int main()
{
    char line[80];
    while (1)
    {
        printf("Enter string:\n");
        fgets(line, sizeof(line), stdin);
        printf("", position(line, 'g'));
    }
}
