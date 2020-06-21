/*
JTSK-320111
a3 p7.c
nhammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
int main()
{
    char ch;
    int n;
    scanf("%c", &ch);
    scanf("%d", &n);
    getchar();

    printf("%c\n",ch);

    for(int i=1; i<=n; i++)
    {
        ch--;
        /*This will give us alphabets that come before the ch that we enter*/
        printf("%c\n",ch);
    }
    return 0;
}
