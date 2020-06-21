/*
JTSK-320112
al_pl.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//defining the macro
#define SWAP(v1,v2,type) {type temp = v1;\
                                    v1 = v2; v2 = temp;};

//temp is used to store the values temporarily
int main()
{
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    //floats changed to doubles to pass testcases
    double c,d;
    scanf("%lf", &c);
    scanf("%lf", &d);
    //calling the macro
    SWAP(a,b, int);
    SWAP(c,d, double);
    printf("After swapping:\n");
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%lf\n",c);
    printf("%lf\n",d);
    return 0;
}
}
