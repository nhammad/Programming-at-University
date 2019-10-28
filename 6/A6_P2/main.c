/*
JTSK-320111
a6 p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
void divby5(float arr[], int size);
int main()
{
    float arr[6]= {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};
    int i;
    printf("Before:\n");
    for(i = 0; i<6; i++)
        /*6 numbers in total*/
        printf ("%0.3f ", arr[i]);
    divby5(arr,6);
    printf("\nAfter:\n");
    for(i = 0; i<6; i++)
        printf ("%0.3f ", arr[i]);
    printf("\n");
    /*Add 0.3 before f because answers are supposed to be in 3 decimal places*/
    return 0;
}

void divby5(float arr[], int size)
{
    int i;
    for (i=0; i<6 ; i++)
    {
        arr[i]=arr[i]/5.0;
        /*division of each number of 5*/
    }

}
