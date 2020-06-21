/*
JTSK-320111
a5 p1.c
nhammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
int main()
{

    float v, lower, upper, step;
    scanf("%f", &lower);
    scanf("%f", &upper);
    scanf("%f", &step);
    for ( v=lower; v<=upper; v=v+step){
        printf ("%f %f %f\n", v, v*v*M_PI, 2*v*M_PI);
    }
        /*Writing %f thrice because 3 float values are to be printed with spaces in between*/
        /*Area of circle=v*v*M_PI */
        /*Perimeter=2*v*M_PI*/
return 0;
}
