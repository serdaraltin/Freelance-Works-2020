#include <stdio.h>

int main()
{
    int sayac = 0, sayi, adet = 0, toplam = 0;
    float ortalama = 0;

    while (1)
    {
        printf("Bir sayi giriniz: ");
        scanf("%d", &sayi);

        if (sayi >= 0)
        {
            break;
        }

        printf("Sayac=%2d\tSayi=%3d\tAdet=%2d\tToplam=%3d\tOrtalama=%.2f\n",
               sayac, sayi, adet, toplam, ortalama);

        toplam += sayi;
        ortalama = (float)toplam / adet;
        adet++;
        sayac++;
    }
}
