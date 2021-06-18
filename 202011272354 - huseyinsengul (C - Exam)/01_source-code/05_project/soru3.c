#include <stdio.h>
#include <stdlib.h>

int dizi1[8] = {11,-98,7,765,-900,0,-6,456};
int dizi2[9] = {345,-908,765,-678,0,-900,987,-543,456};
int dizi3[15] = {3,9,-98,-5,-6,9,7,4,-678,1,-5,-900,-4,6,-7};


void diziGoruntule(int dizi[],int boyut){
    int i;
    printf("Dizi Elemanlari: ");
    for(i=0; i<boyut; i++){
        printf("%d ",dizi[i]);
    }
    printf("\n");
    return;
}

void negatifElemanSayisi(int dizi[],int boyut){
    int i,negatif_sayisi=0;
    
    for(i=0; i<boyut; i++){
        if(dizi[i] < 0)
            negatif_sayisi++;
    }
    printf("Negatif Eleman Sayisi: %d\n",negatif_sayisi);
    return;
}

void pozififElemanlarinEnKucugu(int dizi[],int boyut){
    int i,min=dizi[0];
    
    for(i=1; i<boyut; i++){
        if(dizi[0] < 0)
            min=dizi[i];
        if(dizi[i] > 0 && dizi[i] < min){
            min=dizi[i];
        }
    }
    printf("Pozitif En Kucuk Sayi: %d\n",min);
    return;
}

void ayniElemanlar(int _dizi1[],int _dizi2[],int boyut1,int boyut2){
    int ayni_adedi=0;
    int i,j;
    
    for(i=0; i<boyut1; i++){
        for(j=0; j<boyut2; j++){
            if(_dizi1[i] == _dizi2[j])
                ayni_adedi++;
        }
    }
    printf("Ayni Eleman Sayisi: %d\n",ayni_adedi);
}

void menu();
void altmenu(){
    char secim[2];
    printf("Alt Menu (a,b,c):");
    scanf("%s",secim);
    if(secim[0] == 'a')
        ayniElemanlar(dizi1,dizi2,8,9);
    if(secim[0] == 'b')
        ayniElemanlar(dizi1,dizi3,8,15);
    if(secim[0] == 'c')
        ayniElemanlar(dizi2,dizi3,9,15);
    return;
}

int main(){
    menu();
}

void menu(){
    printf("1-Hangi diziyi goruntulemek istersiniz(1-3)\n");
    printf("2-Hangi dizinin negatif eleman sayisini goruntulemek istersiniz(1-3)\n");
    printf("3-Hangi dizinin pozitif elemanlarinin en kucugunu goruntulemek istersiniz(1-3)\n");
    printf("4-Aynı elemanlarinin sayisini goruntulemek istediginiz iki dizi seciniz\n");
    printf("5-Cikis\n\n");
    printf("Seciminiz:");
    int secim;
    scanf("%d",&secim);
    int dizino1,dizino2;
    switch (secim)
    {
    case 1:
        printf("Dizi No:");
        scanf("%d",&dizino1);
        if(dizino1 == 1)
            diziGoruntule(dizi1,8);
        else if(dizino1 == 2)
            diziGoruntule(dizi2,9);
        else if(dizino1 == 3)
            diziGoruntule(dizi3,15);
        break;
    case 2:
        printf("Dizi No:");
        scanf("%d",&dizino1);
        if(dizino1 == 1)
            negatifElemanSayisi(dizi1,8);
        else if(dizino1 == 2)
            negatifElemanSayisi(dizi2,9);
        else if(dizino1 == 3)
            negatifElemanSayisi(dizi3,15);
        break;
    case 3:
        printf("Dizi No:");
        scanf("%d",&dizino1);
        if(dizino1 == 1)
            pozififElemanlarinEnKucugu(dizi1,8);
        else if(dizino1 == 2)
            pozififElemanlarinEnKucugu(dizi2,9);
        else if(dizino1 == 3)
            pozififElemanlarinEnKucugu(dizi3,15);
        break;
    case 4:
        altmenu();
        break;
    default:
        printf("Hatali secim, tekrar deneyiniz\n");
        break;
    }
    printf("\n");
    menu();

}