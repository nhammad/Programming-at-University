/*
JTSK-320111
a3 p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    if ((x % 2 == 0) && (x % 7 == 0))
        printf("The number is divisible by 2 and 7\n");
    else
        printf("The number is NOT divisible by 2 and 7\n");
        /*When we write x%2 == 0, it checks whether this division would have a remainder or not. If there is a remainder, the number s not divisible by 2*/
    return 0;
}
