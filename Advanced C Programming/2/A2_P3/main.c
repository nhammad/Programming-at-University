/*
JTSK-320112
a2_p3.c
Neeha Hammad
n.hammad@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

void read(int row, int col, int **matrix)
{
    int i,j;
    for (i = 0; i < row ; i ++)
    {
        for (j = 0; j < col ; j ++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void print(int row, int col,int **matrix)
{
    int i,j;
    for ( i = 0; i < row ; i ++)
    {
        for ( j = 0; j < col ; j ++)
            printf ("%d ", matrix[ i ][ j ]);
        printf ("\n") ;
    }
}
void product(int n, int m, int p, int **p1, int **p2, int **p3)
{
    int sum = 0;
    int i, j, k;
    for(i=0; i < n; i++)
    {
        for(k=0; k < p; k++)
        {
            for(j=0; j<m; j++)
                sum += p1[i][j] * p2[j][k];
            p3[i][k] = sum;
            sum = 0;
        }
    }
}
//deallocation:
void setfree(int** matrix, int row)
{
    for (int i=0; i<row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

//if a matrix is[2][4] and 2nd is [4][2]
//4 & 4 are same so multiplication is possible
//resultant matrix's size will be [2][2]
//similarly, here matrix is [n][m] & [m][p]
//so, resultant's size=[n][p]

int main()
{
    int n,m,p;
    int **p1, **p2,**p3;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);
    p1 = (int **)malloc(sizeof(int *) * n); //memory allocation
    p2 = (int **)malloc(sizeof(int *) * m);
    p3 = (int **)malloc(sizeof(int *) * n); //result=n rows
    if ( p1== NULL )
        exit(1);
    if ( p2== NULL )
        exit(1);
    if ( p3== NULL )
        exit(1);
    for(int i=0; i<n; i++)
        p1[i] = (int *)malloc(sizeof(int) * m);
    for(int i=0; i<m; i++)
        p2[i] = (int *)malloc(sizeof(int) * p);
    for(int i=0; i<n; i++)
        p3[i] = (int *)malloc(sizeof(int) * p);//result=p columns
    read(n,m,p1);
    read(m,p,p2);
    printf("Matrix A:\n");
    print(n,m,p1);
    printf("Matrix B:\n");
    print(m,p,p2);
    printf("The multiplication result AxB:\n");
    product(n,m,p,p1,p2,p3);
    print(n,p,p3);
    setfree(p1,n);
    setfree(p2,m);
    setfree(p3,n);
    return 0;
}
