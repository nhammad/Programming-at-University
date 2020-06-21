/*
JTSK-320111
a3 p9.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    char c;
    scanf("%c", &c);
    int n;
    scanf("%d", &n);
    double sum=0;

    double temperature[100];
    for(int i=0; i<n; i++)
    {
        scanf ("%lf", &temperature [i]);
    }

    switch (c)
    {
    case 's':
        for(int i=0; i<n; i++)
        {
            sum += temperature [i];
        }
        printf("Sum of the temperatures= %lf\n", sum);
        break;
    case 'p':
        for(int i=0; i<n; i++)
        {
            printf ("List of all temperatures in Celsius= %lf\n", temperature [i]);
        }
        break;
    case 't':
        for(int i=0; i<n; i++)
        {
            double F;
            F= ((9*temperature[i])/5) + 32;
            /*converting celsius to F*/
            printf ("List of all temperatures in Fahrenheit= %lf\n", F);
        }
        break;
    default:
        for(int i=0; i<n; i++)
        {
            sum += temperature[i];
        }
        printf ("Arithmetic mean= %lf\n", sum/n);
        /*calculating mean here*/
    }
    return 0;
}
