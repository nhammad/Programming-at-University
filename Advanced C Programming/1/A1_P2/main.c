/*
JTSK-320112
al_p2.c
nhammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#define LSB(A)((A) & (1) ? (1) : (0))
//& symbol represents the last bit
//last bit is compared with "1"
//if it's == 1, it gives 1 as the output
//otherwise, it gives 0

int main()
{
    unsigned char c;
    scanf("%c", &c);
    //using %d to print int value (ascii code) of c
    printf("The decimal representation is: %d\n",c);
    printf("The least significant bit is: %d\n",LSB(c));
    return 0;
}
