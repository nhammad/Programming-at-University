/*
JTSK-320111
a4 p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
float convert(int cm)
{
    float km;
    km = (cm*1.0)/100000;
    /*Multiply cm with 1.0 so that the answer is a float value*/
    return km;
}

int main()
{
    int cm;
    scanf("%d", &cm);
    printf("Result of conversion: %0.6f\n", convert(cm));
    /*Calling the cm value and printing it*/
    return 0;
}
