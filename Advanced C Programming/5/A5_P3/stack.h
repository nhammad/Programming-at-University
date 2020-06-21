/*
JTSK-320112
a5_p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//conditional compiling:
#ifndef _STACK_H
#define _STACK_H

//top=count
//stack is empty when top=-1
// Stack is full when top is equal to the last index

struct stack {
    unsigned int top ;
    char array [50][100]; // Container
};

int empty_or_not(struct stack* pile);
void push(struct stack *pile, char* content);
char* pop(struct stack *pile);

#endif // _STACK_H
