/*
JTSK-320112
a3_p4.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    char letter;
    int number;
    //sets list as empty:
    //should be outside loop
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
        case 'q':
            dispose_list ( my_list ) ;
            return 0;
            break;
        }
        getchar();
    }
}

//we use a while(1) loop so that we can keep entering
//characters that enter into diff cases
//it ends when we have a return 0

//scanf("%d",&number) is only used in some cases
//since in some, we only need to remove/print and not add
