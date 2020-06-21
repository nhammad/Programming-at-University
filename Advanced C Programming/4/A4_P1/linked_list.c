/*
JTSK-320112
a4_p1.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct list
{
    int info ;
    struct list * next ; /* self reference */

};
//pushing all values backwards
//putting a new value at the end
struct list * push_back ( struct list * my_list, int value )
{
    struct list * cursor, * newel ;
    cursor = my_list ;
    newel = ( struct list *) malloc ( sizeof ( struct list ));
    if ( newel == NULL )
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel -> info = value ;
    newel -> next = NULL ;
    if ( my_list == NULL )
        return newel ;
    while ( cursor -> next != NULL )
        cursor = cursor -> next ;
    cursor -> next = newel ;
    return my_list ;
}

//pushing all values forward
//putting a new value at the beginning

struct list * push_front ( struct list * my_list, int value )
{
    struct list * newel ;
    newel = ( struct list *) malloc ( sizeof ( struct list ));
    if ( newel == NULL )
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel-> info = value ;
    newel -> next = my_list ;
    return newel ;
}
void print_list ( struct list * my_list )
{
    while ( my_list != NULL )
    {
        printf ("%d ", my_list -> info );
        my_list = my_list -> next ;
    }
    printf("\n");
}
//freeing memory
void dispose_list ( struct list * my_list )
{
    struct list * nextelem ;
    while ( my_list != NULL )
    {
        nextelem = my_list -> next ;
        free ( my_list ) ;
        my_list = nextelem ;
    }
}
//deleting first element of the list
struct list* deleteFirstNode(struct list *my_list)
{
    struct list *toDelete;

    if(my_list != NULL)
    {
        toDelete = my_list; //assigning
        my_list = my_list->next; //moving
        //clears the memory occupied by first node
        free(toDelete);
        return my_list;
    }
    return my_list;
}
