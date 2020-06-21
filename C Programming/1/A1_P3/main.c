/*
JTSK-320111
a1 p3.c
nhammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    float result;
    /* The result of the division */
    float a = 5.0;
    float b = 13.5;
    result = a / b;
    printf("The result is %f\n", result);
    /*A hashtag before the word include was missing. 
	We were supposed to use the word float instead of 
	integers since b is a value with decimals. 
	%d needed to be changed to %f. The symbols used 
	for the comment were also wrong
    */
    return 0;
}
