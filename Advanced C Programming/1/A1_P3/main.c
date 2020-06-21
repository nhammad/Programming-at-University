/*
JTSK-320112
al_p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
//defining macros
//following function calls 2 other functions:
#define mid_range(A,B,C) ((float)(MAX(A,B,C) + MIN(A,B,C))/2)
//comparing values for min & max
#define MIN(A, B, C) ((C) < ((A) < (B) ? \
                             (A) : (B)) ? (C) : ((A) < (B) ? (A) : (B)))
#define MAX(A, B, C) ((C) > ((A) > (B) \
                             ? (A) : (B)) ? (C) : ((A) > (B) ? (A) : (B)))
int main()
{
    int x,y,z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    printf("The mid-range is: %f\n",(float)mid_range(x,y,z));
    return 0;
}
