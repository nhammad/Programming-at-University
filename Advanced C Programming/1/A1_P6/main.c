/*
JTSK-320112
al_p6.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

//if we print a character with %d,
//we get the int ascii code for it

int main()
{
    unsigned char c;
    scanf("%c", &c);
    printf("The decimal representation is: %d\n",c);
    printf("The binary representation is: ");
    //bitmask=[10 000 000]=8bit
    //binary to decimal=128
    unsigned int bitmask=128;
    while(bitmask > 0)
    {
        if((c & bitmask) == 0 )
            printf("0");
        else
            printf("1");
        bitmask = bitmask >> 1 ;
    }
    printf("\n");
    return 0;
}
//The values of c are compared with values of bitmask,
//if it is equal to 0, we print 0
//since we start from the end, we get
//bitmask>>=1; shifts bitmask towards right
