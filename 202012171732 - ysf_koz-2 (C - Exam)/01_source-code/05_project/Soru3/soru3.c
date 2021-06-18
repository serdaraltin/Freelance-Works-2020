#include <stdio.h>

int main()
{

    float gunluk_ucret = 0, gelir_vergisi = 0, vergi_orani = 0, aylik_brut_gelir = 0, net_aylik_maas = 0;
    int calisilan_gun_sayisi = 0;

    printf("Calisan gunluk ucret (TL): ");
    scanf("%f", &gunluk_ucret);

    printf("Calisilan gun sayisi: ");
    scanf("%d", &calisilan_gun_sayisi);

    aylik_brut_gelir = gunluk_ucret * calisilan_gun_sayisi;

    gelir_vergisi = (aylik_brut_gelir / 100) * 20;

    if (aylik_brut_gelir > 5000)
    {
        gelir_vergisi = (aylik_brut_gelir / 100) * 25;
    }

    net_aylik_maas = aylik_brut_gelir - gelir_vergisi;

    printf("\nAylik brut gelir = %.2f TL\n",aylik_brut_gelir);
    printf("Gelir vergisi    = %.2f TL\n",gelir_vergisi);
    printf("Net maas         = %.2f TL\n",net_aylik_maas);
}
