#include <stdio.h>
#include <stdlib.h>

int sirala(int *x, int N);

int main(){
	int i,boyut;
	printf("Dizi boyutu giriniz : ");
	scanf("%d",&boyut);

	int *dizi = (int*)malloc(sizeof(int)*boyut);

	for(i=0; i<boyut; i++){
		printf("Dizinin %d. elemani icin deger giriniz : ",i);
		scanf("%d",&dizi[i]);
	}

	*dizi = sirala(dizi,boyut);

	for (i = 0; i < boyut; i++)
		printf("%d ", dizi[i]);
	
	printf("\n");
	
}

int sirala(int *x, int N){
	int i,j,tek[N], cift[N],tekUzunluk=0,ciftUzunluk=0;
	for (i = 0; i < N; i++){
		tek[i] = '\0';
		cift[i] = '\0';
	}

	for (i = 0; i <N; i++){
		if(x[i] % 2 == 0)
			cift[ciftUzunluk++] = x[i];
		else
			tek[tekUzunluk++] = x[i];
	}

	for (i = 0; i <tekUzunluk; i++){
		for (j = 0; j <tekUzunluk; j++){
			if(tek[i] < tek[j]){
				int gecici = tek[j];
				tek[j] = tek[i];
				tek[i] = gecici;
			}
		}
	}
	for (i = 0; i <ciftUzunluk; i++){
		for (j = 0; j <tekUzunluk; j++){
			if(cift[i] < cift[j]){
				int gecici = cift[j];
				cift[j] = cift[i];
				cift[i] = gecici;
			}
		}
	}
	int eklenenUzunluk = 0;
	for (i = 0; i < tekUzunluk; i++)
		x[eklenenUzunluk++] = tek[i];
	for (i = 0; i < ciftUzunluk; i++)
		x[eklenenUzunluk++] = cift[i];



	return *x;
}