/*
JTSK-320112
al_p4.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//defining MACRO, intermediate
#define INTERMEDIATE
int main()
{
    int n;
    int product=0;
    scanf("%d", &n);
    int Vector_X[n];
    int Vector_Y[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&Vector_X[i]);
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&Vector_Y[i]);
    }

    //conditional compilation:
    //if #define INTERMEDIATE isn't written at the top
    //intermediate values won't be printed

    #ifdef INTERMEDIATE
    int inter;
    printf("The intermediate product values are:\n");
    for (int i=0; i<n;i++)
    {
        inter=Vector_X[i]*Vector_Y[i];
        printf("%d\n",inter);
    }
    #endif // INTERMEDIATE
    for (int i=0;i<n;i++)
    {
        product+=Vector_X[i]*Vector_Y[i];
    }
    printf("The scalar product is: %d\n", product);

    //scalor product=sum of all intermediate products
    return 0;
}
