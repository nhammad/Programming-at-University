#include <stdio.h>
#include <stdlib.h>

//for unsigned int, we can't use negative values
//top=count

struct stack
{
    unsigned int top;
    int array[12]; // Container
};

//declaring
void push(struct stack* pile,int item);
int empty_or_not(struct stack* pile);
void pop(struct stack* pile);
void empty_all(struct stack* pile);
void binary(struct stack* pile, int num);
