/*
JTSK-320112
a2_p4.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void read(int r,int c,int d, int ***matrix)
{
    int i,j,k, el;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k=0; k < d; k++)
            {
                scanf("%d", &el);
                matrix[i][j][k] =el;
            }
        }
    }
}
void print(int row, int col, int depth, int ***matrix)
{
    int i,j,k;
    for (i = 0; i < depth ; i++)
    {
        printf("Section %d:\n", i+1);
        for (j = 0; j < row ; j++)
        {
            for (k = 0; k < col ; k++)
                printf("%d ", matrix[j][k][i]);
            printf("\n") ;
        }
    }
}
int main()
{
    int row,col,depth,i,j;
    int ***p1;
    scanf("%d", &row);
    scanf("%d", &col);
    scanf("%d", &depth);
    p1 = (int ***)malloc(sizeof(int **) * depth);
    if (p1==NULL) {
        printf("Error with malloc\n");
        exit(1);
    }
    for(i = 0; i < depth; i++){
        p1[i] = (int**)malloc(sizeof(int*) * row);
        if (p1[i]==NULL) {
            printf("Error with malloc\n");
            exit(1);
        }
    }
    for(i = 0; i < depth; i++)
        for(j = 0; j < row; j++){
            p1[i][j] = (int*)malloc(sizeof(int) * col);
            if (p1[i][j]==NULL) {
                printf("Error with malloc\n");
                exit(1);
            }
        }
    read(row,col,depth,p1);
    print(row,col,depth,p1);
    //deallocation:
    for (i=0; i<depth; i++)
        for(j=0; j<row; j++)
            free(p1[i][j]);
    for(i=0; i<depth; i++)
        free(p1[i]);
    free(p1);
    return 0;
}

//Explanation of output: r=2, c=2, d=3
//see d as 3 layers of indexes from 0-2
//in each layer, there will be 2 rows&cols
//indexes will start from 0 again
//now, values are stored in each layer
//output= values stored in each layer
