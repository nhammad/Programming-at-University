/*
JTSK-320111
a1 p6.c
nhammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char c='F';
    c = c + 3;
    printf("%c\n", c);
    /*when we say c+3, we are defining a new value for c, which is I. F, G, H, I. So, F+3 */
    return 0;
}
