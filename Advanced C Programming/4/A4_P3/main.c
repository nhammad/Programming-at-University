/*
JTSK-320112
a4_p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int ascending(const void *first, const void *second)
{
    int *a=(int*)first; //casting
    int *b=(int*)second;
    if (*a>*b) //comparing elements pointed by a&b
        return +1;
    else if(*b>*a)
        return -1;
    else
        return 0;
}
//qsort is a built in func
//3 parameters:array,number of elements,
//comparison function

void bubble_ass(int *array, int n)
{
    qsort(array,n,sizeof(int),ascending);
}

void printing(int array[],int n)
{
    for (int i=0; i<n; i++) //don't use <=n
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int descending(const void *first, const void *second)
{
    int *a=(int*)first;
    int *b=(int*)second;
    if (*a<*b)
        return +1;
    else if(*b<*a)
        return -1;
    else
        return 0;
}
void bubble_des(int *array, int n)
{
    qsort(array,n,sizeof(int),descending);
}

void fct_quit(int array[])
{
    exit(1);
}

//sizeof(int) gives size of each #

int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    char letter=0;
    void(*func[3])(int[], int); //#of func pointers
    func[0] =bubble_ass; //pointing to function
    func[1]=printing;
    //func[2]=descending;
    for (int i=0; i<=n; i++)
    {
        scanf("%d", &array[i]);
    }
    while (1)
    {
        scanf("%c",&letter);
        switch(letter)
        {
        case 'a': //ascending order
            func[0](array,n);
            func[1](array,n);
            break;
        case 'd': //alternative method used for knowledge
            qsort(array,n,sizeof(int),descending);
            //func[2](array,n);
            func[1](array,n);
            break;
        case 'e':
            return 0;
            break;
        }
    }
    return 0;
}
