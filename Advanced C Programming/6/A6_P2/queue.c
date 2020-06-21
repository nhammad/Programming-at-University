/*
JTSK-320112
a6_p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

//static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
    return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
    return pq->items;
}
//--------Steps for enqueue:
//1)create a new node.2)Copy item to the node
//3)Set next pointer to NULL. 4)Set front node
//if queue was empty

//already exists.7)Set rear pointer to new node
//8)Add 1 to item count

int enqueue(Item item, Queue *pq)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->item = item;
    new_node->next = NULL;
    if (pq->rear==NULL)
    {
        pq->front = pq->rear = new_node;
    }
    else
    {
        pq->rear->next=new_node;
        pq->rear=new_node;
    }
    return pq->items++;
}

//first we delete the val at front
//then we shift all values behind

//-----------Steps for dequeue:
//Copy item to waiting variable
//Reset front pointer to the next item in queue
//Free memory
//Reset front and rear pointers to NULL, if last item is removed
//last item is when count/items==1
//Decrement item count

int dequeue(Item *pitem, Queue *pq)
{
    copy_to_item(pq->front,pitem);
    pq->front = pq->front->next;
    if (pq->items == 1) //only 1 element left
    {
        pq->front = pq->rear = NULL;
    }
    return pq->items--;
}
void empty_queue(Queue *pq)
{
    Item dummy;
    while (!queue_is_empty(pq)) {
        dequeue(&dummy, pq);
    }
}

/*static void copy_to_node(Item item, Node *pn)
{
    pn->item = item;
}*/

static void copy_to_item(Node *pn, Item *pi)
{
    *pi = pn->item;
}

/*void printing(Queue *pq)
{
    printf("content of the queue: ");
    for(int i=0; i<=pq->rear; i++)
        printf("%d ",pq[i]);
}*/
