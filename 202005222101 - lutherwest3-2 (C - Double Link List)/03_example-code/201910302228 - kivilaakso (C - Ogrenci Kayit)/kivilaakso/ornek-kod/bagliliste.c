/* 
 * File:   main.c
 * Author: cemserit
 *
 * Created on October 23, 2016, 5:43 AM
 */
 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct list {
    int veri;
    struct list *sonraki;
} liste;
 
liste *yeni, *ilk = NULL, *gecici, *silGecici;
 
void menu();
void ekle(int);
void listele();
void bekle();
int ara(int);
int sil(int);
void ekranTemizle();
 
int main() {
 
    while (1) {
        ekranTemizle();
        menu();
    }
    return 0;
}
 
void ekle(int sayi) {
 
    //Liste bos ise
    if (ilk == NULL) {
        ilk = (liste*) malloc(sizeof (liste));
        ilk->veri = sayi;
        ilk->sonraki = NULL;
    } else {
        //Girilen sayi ilk sayidan kucuk ise
        if ((ilk->veri) > (sayi)) {
            yeni = (liste*) malloc(sizeof (liste));
            yeni->veri = sayi;
            yeni->sonraki = ilk;
            ilk = yeni;
        } else {
            gecici = ilk;
            yeni = (liste*) malloc(sizeof (liste));
            yeni->veri = sayi;
            while (gecici != NULL) {
                //gecici elemaninin sonraki null ise ve son elemandan buyukse
                if (gecici->sonraki == NULL && (gecici->veri) <= (sayi)) {
                    yeni->sonraki = NULL;
                    gecici->sonraki = yeni;
                    break;
                }
                //Araya Ekleme
                if ((gecici->sonraki->veri) > (sayi)) {
                    yeni->sonraki = gecici->sonraki;
                    gecici->sonraki = yeni;
                    break;
                }
                gecici = gecici->sonraki;
            }
        }
    }
}
 
void listele() {
    //liste bos ise
    if (ilk == NULL) {
        printf("Liste Bos\n");
    } else {
        //ilk degeri kaybetmemek icin gecici kullanildi
        gecici = ilk;
        while (gecici != NULL) {
            printf("%d\n", gecici->veri);
            gecici = gecici->sonraki;
        }
    }
    bekle();
}
 
void menu() {
    int secim, sayi, sira, kontrol;
 
    printf("1-Ekleme\n");
    printf("2-Listeleme\n");
    printf("3-Arama\n");
    printf("4-Silme\n");
    printf("5-Cikis\n");
 
    scanf("%d", &secim);
 
    switch (secim) {
        case 1:
            ekranTemizle();
            printf("Sayi Giriniz: ");
            scanf("%d", &sayi);
            ekle(sayi);
            bekle();
            break;
        case 2:
            ekranTemizle();
            listele();
            break;
        case 3:
            ekranTemizle();
            if (ilk == NULL) {
                printf("Liste Bos!\n");
                bekle();
                break;
            }
            printf("Sayi Giriniz: ");
            scanf("%d", &sayi);
            sira = ara(sayi);
            if (sira == -1)
                printf("Girilen sayi bulunamadý!\n");
            else
                printf("%d sayisi listenin %d. sirasinda\n", sayi, sira);
            bekle();
            break;
        case 4:
            ekranTemizle();
            if(ilk == NULL){
                printf("Liste Bos!\n");
                bekle();
                break;
            }
            printf("Sayi Giriniz: ");
            scanf("%d", &sayi);
            kontrol = sil(sayi);
            if (kontrol == -1)
                printf("Liste Bos!\n");
            else if (kontrol == 0)
                printf("%d listede bulunamadi!\n", sayi);
            else
                printf("%d silindi\n", sayi);
            bekle();
 
            break;
        case 5:
            ekranTemizle();
            printf("Program Bitti!\n");
            exit(0);
            break;
        default:
            ekranTemizle();
            printf("Hatali Secim\n");
            bekle();
    }
}
 
int ara(int sayi) {
    int sayac = 0;
    gecici = ilk;
    while (gecici != NULL) {
        sayac++;
        if (gecici->veri == sayi)
            return sayac;
        gecici = gecici->sonraki;
    }
    return -1;
}
 
int sil(int sayi) {
    if (ilk == NULL)
        return -1;
    else if (ilk->veri == sayi) {
        silGecici = ilk;
        ilk = ilk->sonraki;
        free(silGecici);
        return 1;
    } else {
        gecici = ilk;
        while (gecici->sonraki != NULL) {
            if (gecici->sonraki->veri == sayi) {
                silGecici = gecici->sonraki;
                gecici->sonraki = silGecici->sonraki;
                free(silGecici);
                return 1;
            }
            gecici = gecici->sonraki;
        }
 
    }
    return 0;
}
 
//Kendi Yazdigimiz Ozel bekleme fonksiyonu
void bekle() {
    char temp;
    printf("Devam etmek icin Enter'a basiniz!\n");
 
    //klavyeden okuma atlamasinin onune gecmek icin 2 kere yazildi
    temp = getchar();
    temp = getchar();
    ekranTemizle();
 
}
//Ekrani temizleme fonksiyonu
//Not: windows icin "cls" linux icin "clear"
 
void ekranTemizle() {
    //Windows icin
    system("cls");
 
    //Linux icin
    //system("clear");
}
