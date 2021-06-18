#include <stdio.h>


int main(){
	
	int satirSayisi,i,j,k;

	printf("Satir Sayisi : ");
	scanf("%d",&satirSayisi);

	 for (i = 0; i <= satirSayisi; i++)
     {
        for (j = i; j < satirSayisi; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("x ");
        }
        printf("\n");
    }  

}