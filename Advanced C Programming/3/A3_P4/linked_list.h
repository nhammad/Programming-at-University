/*
JTSK-320112
a3_p4.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//defining struct:
struct list;
//defining functions:
struct list * push_back ( struct list *, int );
struct list * push_front ( struct list *, int);
void print_list ( struct list * );
void dispose_list ( struct list * );
struct list* deleteFirstNode(struct list *);
