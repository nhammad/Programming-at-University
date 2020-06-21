/*
JTSK-320112
a5_p1.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//using switch statement
int main()
{
    struct stack *pile = NULL; //creating a stack
    //dynamic memory allocation:
    pile = (struct stack *)malloc(sizeof(struct stack ));
    pile -> top = 0;
    while(1)
    {
        char letter;
        scanf("%c",&letter);
        getchar();
        switch(letter)
        {
        case 's':
            push(pile);
            break;
        case 'p':
            pop(pile);
            break;
        case 'e':
            empty_all(pile);
            break;
        case 'q':
            printf("Quit\n");
            return 0;
            break;
        }
    }
    return 0;
}
