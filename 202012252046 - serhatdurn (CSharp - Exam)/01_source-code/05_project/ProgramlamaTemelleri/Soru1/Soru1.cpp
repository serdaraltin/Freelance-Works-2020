#include "stdafx.h"
#include <stdlib.h>

int adminSifresi = 1234;
int sifreDenemeHakki = 2;

void sifreDene() {
	printf("Admin Yeni Sifresi Giriniz:");
	scanf("%d", &adminSifresi);
	printf("Sifre kaydedildi\n");
	return;
}

void gercelSayiGirisi() {
	float elemanDizisi[5];
	int i;

	for (i = 0; i<5; i++) {
		printf("%d. eleman icin deger giriniz:", i + 1);
		scanf("%f", &elemanDizisi[i]);
	}
	float negatifToplami = 0, adet = 0;
	for (i = 0; i<5; i++) {
		if (elemanDizisi[i] < 0) {
			negatifToplami += elemanDizisi[i];
			adet++;
		}
	}
	float negatif_ortalama = negatifToplami / adet;
	printf("Negatif elemanlarin ortalamsi: %.2f\n", negatif_ortalama);
}

void sifreGirisi() {

	printf("Sifre Giriniz:");
	int sifre;
	scanf("%d", &sifre);
	int deneme = 1;
	if (sifre == adminSifresi) {
		printf("Sifre dogru\n");
		gercelSayiGirisi();
		return;
	}

	while (deneme < sifreDenemeHakki)
	{
		printf("Tekrar sifre giriniz:");
		int sifre;
		scanf("%d", &sifre);
		if (sifre == adminSifresi) {
			printf("Sifre dogru\n");
			gercelSayiGirisi();
			return;
		}
		deneme++;
	}
	printf("%d kez hatali sifre girisi yapildi.\n", sifreDenemeHakki);
	exit(0);
}

void menu();

int main()
{
	menu();
    return 0;
}

void menu(){
    printf("1.admin sifre gir\n");
    printf("2.sifre gir\n");
    printf("3.sifre girme hakki\n");
    printf("4.cikis\n\n");
    printf("Seciminizi Giriniz:");
    int secim;
    scanf("%d",&secim);
    switch (secim)
    {
    case 1:
        sifreDene();
        break;
    case 2:
        sifreGirisi();
        break;
    case 3:
        printf("2-10 arasinda bir sayi giriniz:");
        int sayi;
        scanf("%d",&sayi);
        if(sayi >=2 && sayi <= 10)
            sifreDenemeHakki = sayi;
        else
        {
            printf("2-10 arasinda bir deger girilmelidir !\n");
        }
        break;
    case 4:
        printf("Programdan cikiliyor...\n");
        exit(0);
        break;
    default:
        printf("Hatali secim, tekrar deneyiniz\n");
        break;
    }
    printf("\n");
    menu();

}

