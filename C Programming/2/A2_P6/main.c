/*
JTSK-320111
a2 p6.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <string.h>
#include <stdio.h>
int main ()
{
    double x;
    double y;
    double *ptr_one;
    double *ptr_two;
    double *ptr_three;
    /*Assigning pointers*/
    scanf("%lf", &x);
    scanf("%lf", &y);
    /*%lf is used in case of double values*/
    ptr_one = &x;
    ptr_two = &x;
    ptr_three = &y;
    printf("Address of x: %p\n", ptr_one);
    printf("Address of x: %p\n", ptr_two);
    printf("Address of y: %p\n", ptr_three);
    return 0;
}
