#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(){
	srand(time(NULL));
	printf("*********************************************\n");
	printf("Ogrenci Bilgileri : Ad Soyad 00000000 NO\n");
	printf("*********************************************\n");
	printf("Lutfen matrisin satir sayisini (M) giriniz: ");
	int M;
	scanf("%d",&M);
	printf("Lutfen matrisin satir sayisini (N) giriniz: ");
	int N;
	scanf("%d",&N);
	printf("Lutfen matrisin sahi olacagi en kucuk eleman degerini giriniz: ");
	int min;
	scanf("%d",&min);
	printf("Lutfen matrisin sahi olacagi en buyuk eleman degerini giriniz: ");
	int max;
	scanf("%d",&max);
	printf("*********************************************\n");
	int matris[M][N];
	int a,i,j;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			matris[i][j] = min + rand() %(max+1 - min);
		}
	}
	printf("Matrix:\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%3d",matris[i][j]);
		}
		printf("\n");
	}
	printf("*********************************************\n");
	for(a=min; a<=max; a++){
		int adet = 0;
		for(i=0; i<M; i++){
			for(j=0; j<N; j++){
				if(matris[i][j] == a){
					adet++;
				}
			}
		}
		printf("%2d:", a);
		for(i=0; i<adet; i++){
			printf(" * ");
		}
		printf("%d\n",adet);

	}

}
