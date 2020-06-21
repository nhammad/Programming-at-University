#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//top=count
//stack is empty when top=-1
// Stack is full when top is equal to the last index

void empty_all(struct stack* pile)
{
    printf("Emptying Stack ");
    for (int i=pile->top - 1; i >= 0; i--)
    {
            printf("%d ",pile -> array[i]);
    }
    printf("\n");
    pile->top = 0;
}
void push(struct stack* pile)
{
    //struct stack;
    int item;
    scanf("%d",&item);
    getchar();
     int i = pile -> top;
    if(i>11)
    {
        printf("Pushing Stack Overflow\n");
        //printf("Pushing Stack Overflow\n");
    }
    else
    {
        pile->array[i]=item;
        pile -> top = i+1;
        printf("Pushing %d\n",item);
    }
}

int empty_or_not(struct stack* pile)
{

    if(pile->top == 0)
        return 1;
    else
        return 0;
}

void pop(struct stack* pile)
{
    int item;
    if(!empty_or_not(pile))
    {
        item = pile->array[pile->top - 1];
        (pile -> top) --;
        printf("Popping %d\n",item);
        //return item;
    }
    else
        printf("Popping Stack Underflow\n");
}
