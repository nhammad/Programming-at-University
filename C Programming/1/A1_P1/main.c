#include <stdio.h>
#include <stdlib.h>
/*
JTSK-320111
al_pl.c
nhammad
n.hammad@jacobs-university.de
*/
int main()
{
    double result; /* The result of our calculation */
    result = (3.0+1.0) / 5.0;
    printf ("The value of 4/5 is %lf\n", result);
    return 0;
//When 3, 1 and 5 were not written to 2 significant figures (i.e with decimals),
//the final answer is 0, which is incorrect. We need to make sure those are values with decimal places */
}
