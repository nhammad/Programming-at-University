/*
JTSK-320111
a2 p4.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <string.h>
#include <stdio.h>
int main () {
    float a;
    float b;
    float h;
    float area1, area2;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &h);
    area1 =  a * h / 2;
    area2 = (a+b)* h/2;
    printf("square area=%f\n", a * a);
    printf("rectangle area=%f\n", a * b);
    printf("triangle area=%f\n", area1);
    printf("trapezoid area=%f\n", area2);
    /*Use f because float values are required*/
    return 0;
}
