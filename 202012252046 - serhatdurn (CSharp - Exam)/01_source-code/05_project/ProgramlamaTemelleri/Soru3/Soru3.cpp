

#include "stdafx.h"

int sayilar1[8] = { 11,-98,7,765,-900,0,-6,456 };
int sayilar2[9] = { 345,-908,765,-678,0,-900,987,-543,456 };
int sayilar3[15] = { 3,9,-98,-5,-6,9,7,4,-678,1,-5,-900,-4,6,-7 };

void menu();

void DiziYazdir(int elemanDizisi[], int boyut) {
	int i;
	printf("Dizi Elemanlari: ");
	for (i = 0; i<boyut; i++) {
		printf("%d ", elemanDizisi[i]);
	}
	printf("\n");
	return;
}

void NegatifSayi(int elemanDizisi[], int boyut) {
	int i, negatifAdeti = 0;

	for (i = 0; i<boyut; i++) {
		if (elemanDizisi[i] < 0)
			negatifAdeti++;
	}
	printf("Negatif Eleman Sayisi: %d\n", negatifAdeti);
	return;
}

void EnKucukPozitif(int elemanDizisi[], int boyut) {
	int i, min = elemanDizisi[0];

	for (i = 1; i<boyut; i++) {
		if (elemanDizisi[0] < 0)
			min = elemanDizisi[i];
		if (elemanDizisi[i] > 0 && elemanDizisi[i] < min) {
			min = elemanDizisi[i];
		}
	}
	printf("Pozitif En Kucuk Sayi: %d\n", min);
	return;
}

void AyniSayi(int _dizi1[], int _dizi2[], int boyut1, int boyut2) {
	int aynilar = 0;
	int i, j;

	for (i = 0; i<boyut1; i++) {
		for (j = 0; j<boyut2; j++) {
			if (_dizi1[i] == _dizi2[j])
				aynilar++;
		}
	}
	printf("Ayni Eleman Sayisi: %d\n", aynilar);
}

void menu();

void AltMenu() {
	char secim[2];
	printf("Alt Menu (a[1,2], b[1,3], c[2,3]):");
	scanf("%s", secim);
	if (secim[0] == 'a')
		AyniSayi(sayilar1, sayilar2, 8, 9);
	if (secim[0] == 'b')
		AyniSayi(sayilar1, sayilar3, 8, 15);
	if (secim[0] == 'c')
		AyniSayi(sayilar2, sayilar3, 9, 15);
	return;
}


int main()
{
	menu();
    return 0;
}

void menu() {
	printf("1-Hangi diziyi goruntulemek istersiniz(1-3)\n");
	printf("2-Hangi dizinin negatif eleman sayisini goruntulemek istersiniz(1-3)\n");
	printf("3-Hangi dizinin pozitif elemanlarinin en kucugunu goruntulemek istersiniz(1-3)\n");
	printf("4-Ayni elemanlarinin sayisini goruntulemek istediginiz iki elemanDizisi seciniz\n");
	printf("5-Cikis\n\n");
	printf("Seciminiz:");
	int secim;
	scanf("%d", &secim);
	int dizino1, dizino2;
	switch (secim)
	{
	case 1:
		printf("Dizi No:");
		scanf("%d", &dizino1);
		if (dizino1 == 1)
			DiziYazdir(sayilar1, 8);
		else if (dizino1 == 2)
			DiziYazdir(sayilar2, 9);
		else if (dizino1 == 3)
			DiziYazdir(sayilar3, 15);
		break;
	case 2:
		printf("Dizi No:");
		scanf("%d", &dizino1);
		if (dizino1 == 1)
			NegatifSayi(sayilar1, 8);
		else if (dizino1 == 2)
			NegatifSayi(sayilar2, 9);
		else if (dizino1 == 3)
			NegatifSayi(sayilar3, 15);
		break;
	case 3:
		printf("Dizi No:");
		scanf("%d", &dizino1);
		if (dizino1 == 1)
			EnKucukPozitif(sayilar1, 8);
		else if (dizino1 == 2)
			EnKucukPozitif(sayilar2, 9);
		else if (dizino1 == 3)
			EnKucukPozitif(sayilar3, 15);
		break;
	case 4:
		AltMenu();
		break;
	default:
		printf("Hatali secim, tekrar deneyiniz\n");
		break;
	}
	printf("\n");
	menu();

}