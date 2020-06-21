/*
JTSK-320111
a1 p5.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    int x=2138;
    float y=-52.358925;
    char z='G';
    double u=61.295339687;
    printf("x=%9i\n", x);
    printf("y=%11.5f\n", y);
    printf("z=%c\n", z);
    printf("u=%0.7f\n", u);
    /*Added 9 after the percentage sign so that the value is printed over 9 places*/
    return 0;
}
