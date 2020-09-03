#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sirala(int sayilar[],int boyut){
	int i,j;
	for(i=0; i<boyut; i++){
		for(j=0; j<boyut; j++){
			if(sayilar[i] < sayilar[j]){
				int gecici = sayilar[j];
				sayilar[j] = sayilar[i];
				sayilar[i] = gecici;
			}
		}
	}
	return;
}


int main(){
	srand(time(NULL));

	int sayilar[8];

	int i;
	for(i=0; i<8; i++){
		sayilar[i] = 1 + rand() % 49;
	}
	Sirala(sayilar,8);
	printf("Tahmin edilen sayilar >>\n");
	for(i=0; i<8; i++){
		printf("%5d",sayilar[i]);
	}
	printf("\n");
}