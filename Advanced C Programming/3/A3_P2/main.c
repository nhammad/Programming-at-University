/*
JTSK-320112
a3_p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//defining:
struct list
{
    int info ;
    struct list * next ;
//next=pointer to list
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

int sizelist(struct list *my_list)
{
    int count = 0;
    struct list* current = my_list;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

//the new node that we create should be b/w the position
//and position-1
//later,we create a link from our new node forward to L
//then we break the previous link from L-1 to L
//and a bank link from L-1 to our new node:

struct list *PosInsert(struct list *my_list, int position, int number)
{
    if (position < 0 || position > (sizelist(my_list))) {
       printf("Invalid position!\n");
       return my_list; //no change in list
    }
    //type casting memory;alocating node: new_list is also a pointer
    struct list* new_list = (struct list*) malloc(sizeof(struct list));
    //assigning #:data part of memory pointed by new_list will get the #:
    new_list->info  = number;
    new_list->next=NULL;
    //new pointer to point at the start of the list:
    struct list *q;
    q=my_list;
    if (my_list!=NULL)
    {
        for (int i=0; i<position-1; i++)
    {
        q=q->next;
    }
    new_list->next=q->next;
    q->next=new_list; //L-1 to new node
    }

    if (position==0)
        return new_list;
    else
        return my_list;
}
//when we say only next,we refer to the local variable
//when we say current->next we refer to the "link" field
//in a node.
//one next is a pointer and the other refers to a node

struct list *reverse(struct list *my_list)
{
    struct list *current;
    struct list *behind;
    struct list *next;
    if ((my_list == NULL) || (my_list->next==NULL))
        return my_list;
    behind=my_list;
    current=my_list->next;
    next=current->next;
    behind->next=NULL;
    while(current!=NULL)
    {
        //storing address of next node before breaking link
        current->next=behind;
        behind=current;
        current=next;
        if (next!=NULL)
            next=next->next;
    }
    my_list=behind;
    return my_list;
}

int main()
{
    char letter;
    int number, position;
    //sets list as empty:
    //should be outside loop:
    struct list * my_list = NULL ;
    while (1)
    {
        scanf("%c",&letter);
        switch(letter)
        {
        case 'a':
            scanf("%d",&number);
            my_list = push_back ( my_list, number) ;
            break;
        case 'b':
            scanf("%d",&number);
            my_list = push_front( my_list, number) ;
            break;
        case 'p':
            print_list ( my_list ) ;
            break;
        case 'r':
            my_list=deleteFirstNode(my_list);
            break;
        case 'i':
            scanf("%d",&position);
            scanf("%d",&number);
            my_list=PosInsert(my_list,position,number);
            break;
        case 'R':
            my_list=reverse(my_list);
            break;
        case 'q':
            dispose_list ( my_list ) ;
            exit(0);
            break;
        }
        getchar();
    }
    return 0;
}
//we use a while(1) loop so that we can keep entering
//characters that enter into diff cases
//it ends when we have a return 0

//scanf("%d",&number) is only used in some cases
//since in some, we only need to remove/print and not add
