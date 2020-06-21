/*
JTSK-320111
a3 p5.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    int n;

    do{
            scanf("%d", &n);
            if (n<1)
                printf("Input is invalid, reenter value\n");
    }while(n<1);

    if(n>=1)
    {
        printf("1 day = 24 hours\n");
    }
    for(int i=2;i<=n;i++)
        /*i++ adds one number each time*/
    {
        printf("%d days = %d hours\n", i, i*24);
        /*i is the number of days and i*24 is the number of hours*/
    }
    return 0;
}
