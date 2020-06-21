/*
JTSK-320112
al_p7.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//this function sets bits but when it
//returns c, c is still in a character form
//to print, we have to convert into binary again

char set3bits(unsigned char c, int bit1, int bit2, int bit3)
{
    c|=(1 << bit1);
    c|=(1 << bit2);
    c|=(1 << bit3);
    return c;
}
//(1 << bit1):shifts left,last val of c bit2 times
// |= is bitwise OR assign
//(0 OR 1) gives 1.(1 OR 1) gives 1
//that's why we use OR operator
//1= 00000001 (8 bits)
//bit counting starts from right
int main()
{
    unsigned char c;
    scanf("%c", &c);
    int bit1,bit2,bit3;
    scanf("%d", &bit1);
    scanf("%d", &bit2);
    scanf("%d", &bit3);
    printf("The decimal representation is: %d\n",c);
    printf("The binary representation is: ");

    //original decimal representation:
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
    printf("After setting the bits: ");
    int newc=set3bits(c,bit1,bit2,bit3);

    //converting to binary again:
    unsigned int mask=128;
    while (mask>0)
    {
        if ((newc & mask) ==0)
            printf("0");
        else
            printf("1");
        mask=mask>>1;
    }
    printf("\n");
    return 0;
}
