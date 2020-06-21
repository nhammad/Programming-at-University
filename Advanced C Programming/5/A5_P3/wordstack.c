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

int main()
{
    char sentence[100];

    //creating 2 structs and dynamically allocating memory:

    struct stack *pile = NULL;
    pile = (struct stack *)malloc(sizeof(struct stack ));

    struct stack *newpile = NULL;
    newpile = (struct stack *)malloc(sizeof(struct stack ));

    //setting count to 0
    pile -> top = 0;
    newpile -> top = 0;

    //until "exit" is entered:
    while(strcmp(sentence, "exit"))
    {
        //reading:
        //using fgets so all words are read,despite of spaces
        fgets(sentence, sizeof(sentence), stdin);
        //replacing newline with end of line
        sentence[strlen(sentence)-1] = '\0';
        //allows reading as separate words (by space " ")
        char* temp = strtok(sentence, " ");
        //pushing words to the first pile:
        while(temp)
        {
            push(pile, temp);
            temp = strtok(NULL, " ");
        }
        //diving into 2 halves:
        int left = pile->top/ 2;
        //popping out of pile to bring out in reversed order:
        while(left != 0)
        {
            char temp1[50];
            strcpy(temp1, pile->array[pile->top]);
            push(newpile, temp1); //pushing into new pile
            pop(pile);
            left--;                //decrementing
        }

        if(pile->top > newpile->top)
            pop(pile);

        left = pile->top;           //back to count

        int num = 1;
        while(left != 0)
        {
            char store1[100];
            //copying contents of pile into store1
            strcpy(store1, pile -> array[pile -> top]);
            pop(pile);

            char store2[100];
            strcpy(store2, newpile -> array[newpile -> top]);
            pop(newpile);

            //comparing words of the two halves.
            if(strcmp(store1, store2) != 0)
            {
                num = 0;
            }
            left--;
        }
        //strcmp is used to compare
        if(num == 1 && strcmp(sentence, "exit"))
        {
            printf("The sentence is palindromic by words!\n");
        }
        else if(strcmp(sentence, "exit"))
        {
            printf("The sentence is not palindromic by words!\n");
        }
    }
    free(pile);
    free(newpile);
    return 0;
}
