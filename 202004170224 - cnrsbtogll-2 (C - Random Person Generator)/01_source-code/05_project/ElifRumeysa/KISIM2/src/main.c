#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/IMEINo.h"
#include "../lib/KimlikNo.h"
#include "../lib/Telefon.h"
#include "../lib/RastgeleKisi.h"
void TcIMEIDogurlama() {
    int dimei = 0, himei = 0, dtc = 0, htc = 0;
    FILE *f_kisiler = fopen("../src/Kisiler.txt", "r");
    while (!feof(f_kisiler)) {
        char tno[20];char Telefon[20];int Yas = 0;char imno[30];char Ad[30];char Soyad[30];
        fscanf(f_kisiler, "%s %s %s %d %s (%s)", tno, Ad, Soyad, &Yas, Telefon, imno);
        imno[strlen(imno) - 1] = '\0';
        if (IMDogrula(imno) == 1)
            dimei++;
        else
            himei++;
        if (tcDogrula(tno) == 1)
            dtc++;
        else
            htc++;}fclose(f_kisiler);
    printf("\nT.C Kimlik Kontrol\n%d Gecerli\n%d Gecersiz\n", dtc, htc);
    printf("\nIMEI Kontrol\n%d Gecerli\n%d Gecersiz\n", dimei, himei);}
void RastgeleKisilerUret(int secimsonuc) {
    int i;FILE *f_kisiler = fopen("../src/Kisiler.txt", "w");
    for (i = 0; i < secimsonuc; i++) {
        Kisi* kisi = (Kisi*) malloc(sizeof (Kisi));
        kisiuret(kisi);
        char* cikti = (char*) malloc(sizeof (char)*100);
        sprintf(cikti, "%s %s %d %s (%s)", kisi->KimlikNo, kisi->AdSoyad, kisi->Yas, kisi->Telefon, kisi->IMEINo);
        if (i == secimsonuc - 1)
            fprintf(f_kisiler, "%s", cikti);
        else
            fprintf(f_kisiler, "%s\n", cikti);
        free(kisi); } printf("Kayit Eklendi...\n"); fclose(f_kisiler);}
int main() {while (1) {
        printf("\n1 - Rastgele Kisi Uret\n2 - Uretilmis Dosya Kontrol Et\n3 - Cikis\n");
        printf("Secim : ");
        int secimsonuc;scanf("%d", &secimsonuc);
        switch (secimsonuc) {
            case 1:
                printf("Uretilecek Kisi Sayisi : ");
                int secimsonuc; scanf("%d", &secimsonuc);
                RastgeleKisilerUret(secimsonuc);break;
            case 2:
                TcIMEIDogurlama();break;
            case 3:
                printf("Cikis yapildi...\n");exit(0);break;
            default:
                printf("Lutfen Gecerli Degerler Giriniz\n");break;}}}

