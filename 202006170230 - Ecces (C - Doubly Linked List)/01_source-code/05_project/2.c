#include <stdio.h>

void main()
{
   int array[50],i,size,j,val;
    printf("Size : ");
    scanf("%d", &size);
   for(i=0;i<size;i++){
		printf("[%d] value : ",i);
		scanf("%d",&array[i]);
   }
   printf("\nElement : ");
   scanf("%d",&val);
   printf("\nArray\t : ");
   for(i=0;i<size;i++)
      printf("% 2d",array[i]);   

   for(i=0;i<size;i++){
		if(val<array[i]){
		j = i;
		break;
		}
	}
   for(i=size;i>=j;i--){
		array[i]= array[i-1];
   }
   array[j]=val;
   printf("\n\nElements : ");
   for(i=0;i<=size;i++){
		printf("% 2d",array[i]);
    }
   printf("\n");
}