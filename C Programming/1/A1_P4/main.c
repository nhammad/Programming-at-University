/*
JTSK-320111
a1 p4.c
nhammad
n.hammad@jacobs-university.de
*/

#include <string.h>
#include <stdio.h>
int main ()
{
    int x=17;
    int y=4;
    printf("x=%i\n", x);
    printf("y=%i\n", y);
    printf("sum=%i\n", x+y);
    printf("product=%i\n", x*y);
    printf("difference=%i\n", x-y);
    printf("division=%f\n", x*1.0/y);
    printf("remainder of division=%i\n", x%y);
    /*For the division section, I multiplied x with 1.0 so that the answer is in floating numbers as well. Otherwise there is an error*/
    return 0;
}
