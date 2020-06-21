/*
JTSK-320111
a3 p4.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i = 2;
    if(n>=1)
    {
        printf("1 day = 24 hours\n");
    }
    while (i<=n)
    {
        printf("%d days = %d hours\n", i, i*24);
        /*i is the number of days and i*24 is the number of hours*/
        i++;
    }
    /*i++ adds a number to the previous value and we move to the +1 number of days*/
    return 0;
}
//Missing: Checking for positive/non-zero num
