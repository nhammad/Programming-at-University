/*
JTSK-320111
a3 p6.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>
int main()
{
    float x;
    int n;
    scanf("%f", &x);

    scanf("%d", &n);

    while (n <= 0)
    {
        printf("Input is invalid, reenter value\n");
        scanf("%d", &n);
    }

    for(int i=1; i<=n; i++)
        /*This will allow us to print x n times. i++ adds 1 number each time*/
        printf ("%f\n", x);
    return 0;
}
