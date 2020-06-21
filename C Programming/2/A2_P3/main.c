/*
JTSK-320111
a2 p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <string.h>
#include <stdio.h>
int main ()
{
    int weeks;
    int days;
    int hours;
    scanf("%i", &weeks);
    scanf("%i", &days);
    scanf("%i", &hours);
    printf("total number of hours=%d\n", (weeks*7*24) + (days*24) + (hours));
    /*Total number of hours needs to be calculated by adding hours from all weeks and days as well*/
    return 0;
}
