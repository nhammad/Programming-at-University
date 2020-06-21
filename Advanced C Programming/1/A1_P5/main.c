/*
JTSK-320112
al_p5.c
nhammad
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
    printf("The backwards binary representation is: ");
    while (c>0)
    {
        if ((c & 1) ==1)
            printf("1");
        else
            printf("0");
        c>>=1;
    }
    printf("\n");
    return 0;
}

//The last val of c is compared with 1,
//if it is equal to 1, we print 1
//since we start from the end, we get
//backward results
//c>>=1; shifts c towards right
//& again compares the last digit with 1
