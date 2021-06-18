#include <stdio.h>

int main()
{
    int sayi1 = 0, sayi2 = 0;
    int tek_adet = 0, cift_adet = 0, tek_toplam = 0, cift_toplam = 0;
    float tek_ortalama = 0, cift_ortalama = 0;

    printf("Sayi 1 giriniz: ");
    scanf("%d", &sayi1);

    printf("Sayi 2 giriniz: ");
    scanf("%d", &sayi2);

    int kucuk = sayi1, buyuk = sayi2;

    if (sayi1 > sayi2)
    {
        kucuk = sayi2;
        buyuk = sayi1;
    }

    int sayac, adim = 1;

    printf("\n\nSayi 1 = %d\tSayi 2 = %d\n\n", sayi1, sayi2);

    for (sayac = kucuk; sayac <= buyuk; sayac++)
    {

        printf("%d.adim\tTek Toplam = %4d\tTek Adet = %4d\tCift Toplam = %4d\tCift Adet = %4d\tTek Ortalama = %.2f\tCift Ortalama = %.2f\n"
        ,adim,tek_toplam,tek_adet,cift_toplam,cift_adet,tek_ortalama,cift_ortalama);

        if (sayac % 2 == 0)
        {
            cift_adet++;
            cift_toplam += sayac;
        }
        else
        {
            tek_adet++;
            tek_toplam += sayac;
        }

        tek_ortalama = (float)tek_toplam / tek_adet;
        cift_ortalama = (float)cift_toplam / cift_adet;

        adim++;
    }
}
