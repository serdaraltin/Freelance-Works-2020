#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int icindeVarmi(int dizi[],int rakam){
	int i;
	for(i=0; i<4; i++){
		if(dizi[i] == rakam)
			return 1;
	}
	return 0;
}
int ayniYerdemi(int dizi1[],int dizi2[],int konum){
	if(dizi1[konum] == dizi2[konum])
		return 1;
	return 0;
}
int ayniMi(int dizi1[],int dizi2[]){
	int i;
	for(i=0; i<4; i++){
		if(dizi1[i] != dizi2[i])
			return 0;
	}
	return 1;
}
int main(){
	srand(time(NULL));
	printf("*********************************************\n");
	printf("Ogrenci Bilgileri : Ad Soyad 00000000 NO\n");
	printf("*********************************************\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++\n");
	int dizi[4],i,j,rastgeleRakam;
	dizi[0] = 1 + rand() % 9;
	for(i=1; i<4; i++){
		rastgeleRakam = 0+ rand() % 9;
		for(j=0; j<4; j++){
			while(rastgeleRakam == dizi[j]){
				rastgeleRakam = 0+ rand() % 9;
			}
		}
		dizi[i] = rastgeleRakam;
	}
	
	//test verisi
	/*
	dizi[0] = 2;
	dizi[1] = 0;
	dizi[2] = 7;
	dizi[3] = 3;
	*/
	//test verisi
	
	int tutulanSayi = 0;
	for(i=0; i<4; i++){
		tutulanSayi = 10*tutulanSayi+dizi[i];
	}
	
	printf("++++++++++++ Tutulan sayi : %d ++++++++++++\n",tutulanSayi);
	printf("+++++++++++++++++++++++++++++++++++++++++++++\n");
	int dogru,yanlis;
	int a=1;
	while(a <= 10){
		dogru = 0, yanlis = 0;
		printf("%d. tahmini giriniz (4 basamakli rakamlari farkli): ",a++);
		int tahmin=0,tahminDizi[4];
		scanf("%d",&tahmin);
		for (i = 0; i < 4; i++) {
		  tahminDizi[i] = tahmin%10;
		  tahmin = tahmin / 10;
		}

		int dizi2[4];
		for (i = 0; i < 4; i++) {
			dizi2[i] = tahminDizi[3-i];
		}

		for (i = 0; i < 4; i++) {
			if(icindeVarmi(dizi,dizi2[i]) == 1){
				if(ayniYerdemi(dizi,dizi2,i) == 1){
					dogru++;
				}else{
					yanlis++;
				}
			}
		}


		printf("\t+%d  -%d\n",dogru,yanlis );

		if(ayniMi(dizi,dizi2) == 1){
			printf("Tebrikler kazandiniz.\n");
			break;
		}

		if(a == 11){
			printf("Kaybettiniz :(\n");
			break;
		}
	}
}
