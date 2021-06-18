#include <stdio.h>
#include <stdlib.h>

int admin_sifre =1234;
int deneme_hakki=2;

void adminSifreGir(){
    printf("Admin Yeni Sifresi Giriniz:");
    scanf("%d",&admin_sifre);
    printf("Sifre kaydedildi\n");
    return;
}

void gercelSayiGir(){
    float dizi[5];
    int i;

    for(i=0; i<5; i++){
        printf("%d. eleman icin deger giriniz:",i+1);
        scanf("%f",&dizi[i]);
    }
    float negatif_toplam=0,adet=0;
     for(i=0; i<5; i++){
         if(dizi[i] < 0){
             negatif_toplam+=dizi[i];
             adet++;
         }
     }
     float negatif_ortalama = negatif_toplam / adet;
     printf("Negatif elemanlarin ortalamsi: %.2f\n",negatif_ortalama);
}

void sifreGir(){

    printf("Sifre Giriniz:");
    int sifre;
    scanf("%d",&sifre);
    int deneme=1;
    if(sifre == admin_sifre){
        printf("Sifre dogru\n");
        gercelSayiGir();
        return;
    }

    while (deneme < deneme_hakki)
    {
        printf("Tekrar sifre giriniz:");
        int sifre;
        scanf("%d",&sifre);
        if(sifre == admin_sifre){
            printf("Sifre dogru\n");
            gercelSayiGir();
            return;
        }
        deneme++;
    }
    printf("%d kez hatali sifre girisi yapildi.\n",deneme_hakki);
    exit(0);
}

void menu();

int main(){

    menu();
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
        adminSifreGir();
        break;
    case 2:
        sifreGir();
        break;
    case 3:
        printf("2-10 arasinda bir sayi giriniz:");
        int sayi;
        scanf("%d",&sayi);
        if(sayi >=2 && sayi <= 10)
            deneme_hakki = sayi;
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
