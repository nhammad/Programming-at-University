/*
JTSK-320112
a4_p4.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct person
{
    char name[30];
    int age;
};
int ascending_alpha(struct person first, struct person second);

int ascending_num(struct person first, struct person second)
{

    if (first.age> second.age)
        return +1;
    else if(first.age< second.age)
        return -1;
    else
        return ascending_alpha(first, second);
}

int ascending_alpha(struct person first, struct person second)
{

    if (strcmp(first.name,second.name)>0)
        return +1;
    else if (strcmp(first.name,second.name)<0)
        return -1;
    else
        return 0;
}
//how bubble sort in general works:
//we compare 2 consecutive numbers
//if the number at back is greater, we store it
//temporarily and then swap them:

//3 parameters: person variable, #of elements
//func(either ascending or descending)

void bubble_sort(struct person *store, int num, int (*func)(struct person,struct person)) {

    int swapped = 1;

    while(swapped == 1)
    {
        swapped=0;

       for (int j = 1; j < (num); j++)
       { // last i elements are sorted already
            if (func(store[j-1], store[j])> 0)
            {
                struct person helper = store[j-1];
                  store[j-1] = store[j];
                   store[j] = helper;

                swapped = 1;
           }
       }
     }
}

void printing(struct person *arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("{%s, %d}; ", arr[i].name, arr[i].age);
    }

    printf("\n");
}

int main()
{
    int num;
    scanf("%d",&num);
    struct person howmany[num];
    for (int i=0; i<num; i++)
    {
        scanf("%s", howmany[i].name);

        scanf("%d", &howmany[i].age);

    }
    //Printing Alphabetically
    bubble_sort(howmany,num,ascending_alpha);
    printing(howmany,num);
    //Printing by Ascending Ages
    bubble_sort(howmany,num,ascending_num);
    printing(howmany,num);
    return 0;
}
