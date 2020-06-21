/*
JTSK-320112
a5_p3.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int empty_or_not(struct stack* pile)
{

    if(pile->top == 0)
        return 1;
    else
        return 0;
}
void push(struct stack *pile, char* content)
{
    if(pile->top > 100)
    {
        printf("Pushing Stack Overflow\n");
    }
    else
    {
        pile->top++;
        strcpy(pile->array[pile->top], content);
    }
}
char* pop(struct stack *pile)
{
    if(pile->top != 0)
    {
        pile->top--;
    }
    else
    {
        printf("Popping Stack Underflow\n");
        return NULL;
    }
    return pile->array[pile->top];
}
