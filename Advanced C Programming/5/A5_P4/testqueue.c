/*
JTSK-320112
a5_p4.c
nhammad
n.hammad@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue line;
    Item temp;
    char ch;
    initialize_queue(&line);

    while (((ch = getchar()) != EOF))
    {
        switch (ch)
        {
        case 'a':
            printf("add int: ");
            scanf("%d", &temp);
            //If queue is full do not do anything
            if (!queue_is_full(&line))
            {
                printf("Putting %d into queue\n", temp);
                enqueue(temp, &line);
            }
            else
                puts("Queue is full");
            break;

        case 'd':
            if (queue_is_empty(&line))
                puts("Nothing to delete!");
            else
            {
                dequeue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
            break;
        /*case 'p':
            printing(line);*/
        case 'q':
            puts("Bye.");
            exit(1);
        default:
            printf("%d items in queue\n", queue_item_count(&line));
            puts("Type a to add, d to delete, q to quit:");
            break;
        }
        }
    }
