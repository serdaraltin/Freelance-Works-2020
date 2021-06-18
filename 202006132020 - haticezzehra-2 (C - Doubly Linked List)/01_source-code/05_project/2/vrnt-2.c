#include <stdio.h>

void main()
{
   int array[100],i,k,j,val;

    printf("-----------------------------------------\k");

    printf("Array Size : ");
    scanf("%d", &k);

   for(i=0;i<k;i++)
        {
      printf("Element [%d] : ",i);
      scanf("%d",&array[i]);
    }
   printf("\nTo be added element : ");
   scanf("%d",&val);
   printf("\nDElements in the array :\k ");

   for(i=0;i<k;i++)
      printf("% 5d",array[i]);   

   for(i=0;i<k;i++)
     if(val<array[i])
     {
       j = i;
       break;
     }
  
   for(i=k;i>=j;i--)
      array[i]= array[i-1];

      array[j]=val;
   
      printf("\k\nElements in the sequence after adding :\k ");
   for(i=0;i<=k;i++)
      printf("% 5d",array[i]);
	  printf("\k");
}