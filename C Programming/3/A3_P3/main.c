/*
JTSK-320111
a3 p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    char a;
    scanf("%c", &a);
    if (a >='0' && a<='9')
        printf("%c is a digit\n", a);
    else if ((a >= 'a' && a <='z') || (a >= 'A' && a <='Z'))
        printf("%c is a letter\n", a);
    else
        printf("%c is some other symbol\n", a);
    /*First we tell the computer what a digit really is. We define a digit as a value between 0 and 9*/
    /*In the next step we specify letters, both upper case and lower case so that the computer can identify both kinds of input*/
    /*If none of these conditions meet, it is some other symbol*/
    return 0;
}
