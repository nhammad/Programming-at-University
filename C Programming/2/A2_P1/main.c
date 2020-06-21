/*
JTSK-320111
a2 p1.c
nhammad
n.hammad@jacobs-university.de
*/

#include <string.h>
#include <stdio.h>
int main () {
double num1;
double num2;
//printf ("Enter a Number: ");
scanf("%lf", &num1);
scanf("%lf", &num2);
//printf("You entered : %lf\n%lf\n", num1, num2);
printf("sum of doubles=%lf\n", num1+num2);
printf("difference of doubles=%lf\n", num1-num2);
printf("square=%lf\n", num1*num1);
int no1;
int no2;
scanf("%i", &no1);
scanf("%i", &no2);
printf("sum of integers=%i\n", no1+no2);
printf("product of integers=%i\n", no1*no2);
char a;
char b;
getchar();
scanf("%c", &a);
getchar();
scanf("%c", &b);
printf("sum of chars=%i\n", a+b);
printf("product of chars=%i\n", a*b);
printf("sum of chars=%c\n", a+b);
printf("product of chars=%c\n", a*b);
return 0;
}
