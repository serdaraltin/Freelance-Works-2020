#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "lib/imeiuret.h"
#include "lib/tcnouret.h"
#include "lib/teluret.h"
#include "lib/yasuret.h"
#include "lib/kisiuret.h"

void kuret(int sayi) {
    int i;
    FILE *dosya;

    dosya = fopen("src/Kisiler.txt", "w");

    for (i = 0; i < sayi; i++) {
        
        Kisi* k = (Kisi*) malloc(sizeof (Kisi));
        kisiuret(k);
        if(i+1 == sayi)
            fprintf(dosya, "%s %s %d %s (%s)", k->tcno, k->isimSoyisim, k->yas, k->telefon, k->imei);
        else
            fprintf(dosya, "%s %s %d %s (%s)\n", k->tcno, k->isimSoyisim, k->yas, k->telefon, k->imei);
        free(k);
    }

    fclose(dosya);
    printf("Kayit Eklendi...\n");
    return;
}



void dosyakontrol() {
    if (!fopen("src/Kisiler.txt", "r")) {
        printf("OKUMA HATASI\n");
        return;
    }

    int dogruimei = 0, hataliimei = 0, dogrutc = 0, hatalitc = 0;
    FILE *dosya;
    dosya = fopen("src/Kisiler.txt", "r");

    while (!feof(dosya)) {
        char tcno[15];
        char telefon[15];
        int yas = -1;
        char imei[20];
        char isim[20];
        char soyisim[20];

        fscanf(dosya, "%s %s %s %d %s (%s)", tcno, isim, soyisim, &yas, telefon, imei);

        imei[strlen(imei) - 1] = '\0';

       
        if (imeidogrula(imei) == 1)
            dogruimei++;
        else
            hataliimei++;


        if (tcdogrula(tcno) == 1)
            dogrutc++;
        else
            hatalitc++;


    }
    fclose(dosya);


    printf("\nT.C Kimlik Kontrol\n%d Gecerli\n%d Gecersiz\n", dogrutc, hatalitc);
    printf("\nIMEI Kontrol\n%d Gecerli\n%d Gecersiz\n", dogruimei, hataliimei);

    return;
}

int main() {
   
    while (1) {
        printf("\n1 - Rastgele Kisi Uret\n2 - Uretilmis Dosya Kontrol Et\n3 - Cikis\n");
        printf("Secim : ");
        int secenek;
        scanf("%d", &secenek);

        if (secenek == 1) {
            printf("Uretilecek Kisi Sayisi : ");
            int sayi;
            scanf("%d", &sayi);
         
            kuret(sayi);

        } else if (secenek == 2) {
            dosyakontrol();
        } else if (secenek == 3) {
            printf("Cikis yapildi...\n");
            break;
        } else {
            printf("Lutfen Gecerli Degerler Giriniz\n");
        }
    }
}
