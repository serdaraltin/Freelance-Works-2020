#include <stdio.h>
#include <stdlib.h>


int Arastir(int sayi1,int sayi2){

	int sayi1Gecici=sayi1,sayi2Gecici=sayi2,sayi1Toplam=0,sayi2Toplam=0;
	while(sayi1>0){
		sayi1Toplam += sayi1--;
	}
	while(sayi2>0){
		sayi2Toplam += sayi2--;
	}
	printf("Sayi1 Toplam : %d\nSayi2 Toplam : %d\n",sayi1Toplam,sayi2Toplam);
	if(sayi1Gecici == sayi2Toplam && sayi2Gecici == sayi1Toplam)
		return 0;

	return -1;
}

int main(){
	printf("Sayi 1 : ");
	int sayi1;
	scanf("%d",&sayi1);

	printf("Sayi 2 : ");
	int sayi2;
	scanf("%d",&sayi2);

	if(Arastir(sayi1,sayi2) == 0){
		printf("BARISCIL SAYIYI BULDUN. TEBRIKLER!!!!\n");
	}
	else{
		printf("SADECE IKI ADET SAYI GIRDINIZ\n");
	}
}