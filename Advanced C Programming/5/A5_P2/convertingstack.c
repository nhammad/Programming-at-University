/*
JTSK-320112
a5_p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    //creating a stack
    struct stack *pile = NULL;
    //dynamic memory allocation:
    pile = (struct stack *)malloc(sizeof(struct stack ));
    pile -> top = 0;
    int num;
    scanf("%d",&num);
    binary(pile,num);
    return 0;
}
