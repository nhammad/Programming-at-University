/*
JTSK-320112
a3_p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list
{
    char info ;
    struct list * next ;
    struct list * previous;
    //next=pointer to list
};

//pushing all values forward
//putting a new value at the beginning

struct list * push_front ( struct list * my_list, char character )
{
    struct list * newel ;
    newel = ( struct list *) malloc ( sizeof ( struct list ));
    if ( newel == NULL )
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel-> info = character ;
    newel -> next = my_list ;
    if (my_list!=NULL) //if reaches till end
        my_list -> previous = newel;
    newel -> previous = NULL;
    return newel ;
}
void print_list ( struct list * my_list )
{
    while ( my_list != NULL )
    {
        printf ("%c ", my_list -> info );
        my_list = my_list -> next ;
    }
    printf("\n");
}

//*my_list is the head
//"first" points to the head
//when we delete the first node, we lose the link
//that contains address of the next nodes so
//before deleting a node, we store the address
//of the next node in temp. after deleting a node,
//p then points to the next node,whose address was in temp
//last iteration:store holds the address value of NULL
//so p points to NULL and condition is no longer valid

void delete_all( struct list * my_list )
{
    struct list *first;
    struct list *temp;
    first = my_list;
    while (first!=NULL)
    {
        temp=first->next;
        free(first);
        first=temp;
    }
}

void reverse_print( struct list * my_list )
{
    struct list * cursor = my_list;
    while(cursor->next!=NULL)//stops at last element
    {
        cursor=cursor->next; //iterates
    }
    while(cursor!=NULL)
    {
        printf("%c ",cursor->info);
        cursor=cursor->previous; //going back
    }
    printf("\n");
}

//find is a pointer to the head(1st element i.e my_list)
struct list* search_delete(struct list * my_list,char character)
{
    struct list *find = my_list;
    int found=0;
    // Case 1: list is empty
    if (find==NULL)
        return my_list;
    // Case 2: list has 1 element
    else if (find->next==NULL) {
        if (find->info == character){
            free(find);
            found=1;
            my_list=NULL;
            return my_list;
        }
        else
            return my_list; //unchanged list
    }
    // Case 3: list has at least 2 elements
    else {
        struct list *left;
        struct list *right;
        left=NULL; //start
        find=my_list; //first
        right=find->next; //2nd element
        while(find!=NULL)
        {
            if (find->info==character)//checking data in current node
            {
                found = 1;
                free(find);
                if (left!=NULL)
                    left -> next = right;
                else
                    my_list=right;
                if (right!=NULL) //if we delete last char
                    right -> previous = left;
                find=right;
                if (right!=NULL)
                    right=right->next;
            }
            else {
                left=find;
                find=find->next;
                if (right!=NULL)
                    right=right->next;
            }
        }
        if (!found)
            printf("The element is not in the list!\n");
        return my_list;
    }
}
int main()
{
    int num;
    char character;
    struct list * my_list = NULL ;
    while (1)
    {
        scanf("%d",&num);
        getchar();
        switch(num)
        {
        case 1:
            scanf("%c",&character);
            getchar();
            my_list = push_front(my_list, character);
            break;
        case 2:
            scanf("%c",&character);
            getchar();
            my_list=search_delete(my_list,character);
            break;
        case 3:
            print_list(my_list);
            break;
        case 4:
            reverse_print(my_list);
            break;
        case 5:
            delete_all(my_list);
            return 0;
            break;
        }
    }
}
