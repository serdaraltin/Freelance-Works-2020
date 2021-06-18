#include <stdlib.h>
#include <stdio.h>

int * partitionArr(int *z, int size ,int p);

int main(void)
{
    int i, x[8] = {4,6,2,9,1,7,3,10};
    //int i, x[10] = {3,3,3,3,3,8,8,8,8,8};
    int *y;
    int partition;

    printf("enter a number from 0 to 10\n");
    scanf("%d", &partition);

    y = malloc(sizeof(int) * sizeof(x)/sizeof(x[0])+1); //+1 for inserting partition
    y = partitionArr(x, 8,partition);

    printf("Partition is: %d\n\n", partition);  
    for(i=0;i<sizeof(x)/sizeof(x[0]);i++)
    {
        printf("y[%d] == %d\n", i, y[i]);   
    }
    getchar();
    getchar();

    return 0;
}

int * partitionArr(int *z,int size, int p)
{
    int i=0,j=0;
    int x[size];

    //load y with x
    for(i=0;i<sizeof(x)/sizeof(x[0]);i++) 
    	x[i] = z[i];

    for(i=0;i<sizeof(x)/sizeof(x[0]);i++)
    {
        if(x[i]<p) 
        {
            z[j] = x[i];
            j++;
        }
    }   
    for(i=0;i<sizeof(x)/sizeof(x[0]);i++)
    {
        if(x[i]==p) 
        {
            z[j] = x[i];
            j++;
        }
    }   
    for(i=0;i<sizeof(x)/sizeof(x[0]);i++)
    {
        if(x[i]>p) 
        {
            z[j] = x[i];
            j++;
        }
    }
    return z;
}   

