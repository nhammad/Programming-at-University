/*
JTSK-320112
a2_p1.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    float array[n];
    //we create 2 pointers. 1st remains at the 1st position
    //2nd moves through the array
    float *array_ptr1 = &array[0];
    float*array_ptr2 = &array[0];
    for (int i=0; i<n; i++)
    {
        scanf("%f", &array[i]);
    }
    //moving ptr2 from position 0 till n numbers
    for (; ; array_ptr2++)
    {
        if (*array_ptr2<0)
        {
            //if value at the index where pointer is pointing
            //==0, break
            break;
        }
    }
    printf("Before the first negative value: %li elements\n",array_ptr2-array_ptr1);
    return 0;
}
