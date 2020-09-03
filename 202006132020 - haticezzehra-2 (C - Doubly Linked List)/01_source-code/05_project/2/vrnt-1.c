#include <stdio.h>

void main()
{
   int arr1[100],i,n,p,inval;

    printf("-----------------------------------------\n");

    printf("Dizi boyutu : ");
    scanf("%d", &n);

   for(i=0;i<n;i++)
        {
      printf("Eleman [%d] icin deger : ",i);
      scanf("%d",&arr1[i]);
    }
   printf("\nDiziye eklenecek deger : ");
   scanf("%d",&inval);
   printf("\nDizideki elemanlar :\n ");

   for(i=0;i<n;i++)
      printf("% 5d",arr1[i]);   

   for(i=0;i<n;i++)
     if(inval<arr1[i])
     {
       p = i;
       break;
     }
  
   for(i=n;i>=p;i--)
      arr1[i]= arr1[i-1];

      arr1[p]=inval;
   
      printf("\n\nEklemeden sonraki dizideki elemanlar :\n ");
   for(i=0;i<=n;i++)
      printf("% 5d",arr1[i]);
	  printf("\n");
}