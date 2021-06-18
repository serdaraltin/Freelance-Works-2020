#include <stdlib.h>
#include <stdio.h>

void partitionArr(int *z, int size ,int p);

int main(void)
{
    int i, x[8] = {4,6,2,9,1,7,3,10};

    partitionArr(x,8, 5);
    for(i=0;i<8;i++)
    {
        printf("%d ", x[i]);   
    }
    printf("\n");
    return 0;
}

void partitionArr(int a[],int size, int x)
{
    int i=0,j=0;

    for(i=0;i<size;i++)
    {
        if(a[i]<x) 
        {
            int tmp = a[j];
            a[j] =a[i];
            a[i] = tmp;
            j++;
        }
    }   

    return;
}   
