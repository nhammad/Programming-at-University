/*
JTSK-320112
a4_p2.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ascii values of lower case letters
//range from 97 to 122
//by adding 32, we get the upper letter

void to_upper(char string[100])
{
    for (int i=0; i<strlen(string)-1; i++)
        if(string[i]>=97 && string[i]<=122)
        {
            printf("%c", string[i]-32);
        }
        else
            printf("%c",string[i]);
}

//Ascii values of upper case letters
//range from 65 to 90

void to_lower(char string[100])
{
    for (int i=0; i<strlen(string)-1; i++)
        if(string[i]>=65 && string[i]<=90)
        {
            printf("%c",string[i]+32);
        }
        else
            printf("%c",string[i]);
}

//we add 32 while printing because otherwise,
//every time, we'll change the previously changed
//list, instead of the original one

void opposite(char string[100])
{
    for (int i=0; i<strlen(string)-1; i++)
        if(string[i]>=65 && string[i]<=90)
        {
            printf("%c",string[i]+32);
        }
        else if(string[i]>=97 && string[i]<=122)
        {
            printf("%c",string[i]-32);
        }
        else
            printf("%c",string[i]); //for spaces
}
//if 4 is entered, program should quit:

void fct_quit(char string[100])
{
    exit(1);
}

int main()
{
    char string[100];
    int number=0;
    fgets(string, sizeof(string),stdin);
    void(*func[4])(char[100]);
    func[0] = to_upper;
    func[1]=to_lower;
    func[2]=opposite;
    func[3] =fct_quit;
    while (number!=4)
    {
        scanf("%d",&number);
        func[number-1](string);
        printf("\n");
    }
    return 0;
}
//void(*func[4])(char[100]):
//we create an array of 4 function pointers
//func[number-1](string):
//^ function and parameter
