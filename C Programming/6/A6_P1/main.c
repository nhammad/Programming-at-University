/*
JTSK-320111
a6 p1.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
void triangle(int n, char ch);
int main()
{
    char line[100] ;
    int n;
    char ch;
    fgets(line, sizeof(line),stdin);
    sscanf(line, "%d", &n);/*converting to integer*/
    fgets(line, sizeof(line),stdin);
    sscanf(line, "%c", &ch);
    triangle(n, ch);
    return 0;
}
void triangle(int n, char ch)
{
    int i;
    int j;
    for (i=0; i<n ; i++)
        /*Assume that i is the number of columns. To add more columns according to the value of n, we use i++*/
    {
        for (j=n-i; j>0; j--)
        /*Assume that j is the number of rows. To remove one more character from each next line, we use j--*/
        /*j=n-i where i can be considered the number of characters to be removed from the line. Make a table to see*/
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}
