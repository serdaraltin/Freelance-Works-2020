#include <stdio.h>
#include <stdlib.h>

#define BOYUT 10

void Menu();
void UrunGirisi();
void UrunSil();
void ZamYap();
void IndirimYap();
void SatisYap();
void UrunleriListele();

int urunlerId[BOYUT] = {0};
int urunlerAdet[BOYUT] = {0};
float urunlerFiyat[BOYUT] = {0};
int mevcutAdet = 0;

int main()
{
    Menu();
}

void Menu()
{
    UrunleriListele();
    printf("1) Urun Girisi\n");
    printf("2) Urun Sil\n");
    printf("3) Zam Yap\n");
    printf("4) Indirim Yap\n");
    printf("5) Satis Yap\n");
    printf("-1) Cikis Yap\n\n");
    printf("Secim : ");
    int secim;
    scanf("%d", &secim);
    printf("\n");
    switch (secim)
    {
    case -1:
        printf("Programdan cikiliyor...\n");
        exit(0);
        break;
    case 1:
        UrunGirisi();
        break;
    case 2:
        UrunSil();
        break;
    case 3:
        ZamYap();
        break;
    case 4:
        IndirimYap();
        break;
    case 5:
        SatisYap();
        break;
    default:
        printf("Hatali secim !");
        break;
    }
    printf("\n");
    Menu();
}

void UrunleriListele(){
    printf("id\tadet\tfiyat\n");
    printf("---\t----\t----\n");
    int i;
    for (i = 0; i < 10; i++)
    {
        if(urunlerId[i] != 0)
            printf("%d\t%d\t%.2f\n",urunlerId[i],urunlerAdet[i],urunlerFiyat[i]);
    }
    printf("\n");
}

void UrunYazdir(int id){
    printf("\nUrun Bilgileri\n");
    printf("Id : %d\nAdet : %d\nBirim Fiyat : %.2f\n\n",urunlerId[id],urunlerAdet[id],urunlerFiyat[id]);
}

int UrunBul(int aranan)
{
    int i;
    for (i = 0; i < BOYUT; i++)
    {
        if(urunlerId[i] == aranan)
            return i;
    }
    return -1;
}

void UrunGirisi()
{
    printf("\n--- URUN GIR ---\n");
    printf("Urun Id/Urun Adet/Birim Fiyat : ");
    int urunId, urunAdet;
    float birimFiyat;
    scanf("%d %d %f", &urunId, &urunAdet, &birimFiyat);

    if (UrunBul(urunId) == -1 && mevcutAdet == 10)
    {
        printf("Maximum urun adedine ulasildi, daha fazla eklenemez !\n");
        return;
    }
    int sira = mevcutAdet, guncelleme = 0;
    if(UrunBul(urunId) != -1){
        sira = UrunBul(urunId);
        guncelleme++;
    }
            
    urunlerId[sira] = urunId;
    if(guncelleme == 1)
        urunlerAdet[sira] += urunAdet;
    else
        urunlerAdet[sira] = urunAdet;
    urunlerFiyat[sira] = birimFiyat;

    if(guncelleme == 1){
        printf(">> Urun guncellendi\n");
        UrunYazdir(sira);
        return;
    }
    printf(">> Urun eklendi\n");
    UrunYazdir(sira);
    mevcutAdet++;
}

void UrunSil()
{
    printf("\n--- URUN SIL ---\n");
    printf("Urun Id : ");
    int urunId;
    scanf("%d", &urunId);
    int sira = UrunBul(urunId);
    if(sira == -1){
        printf("Urun bulunamadi !");
        return;
    }
    printf(">> Urun silindi\n"); 
    UrunYazdir(sira);
    urunlerId[sira] = 0;
    urunlerAdet[sira] = 0;
    urunlerFiyat[sira] = 0;
  
    mevcutAdet--;
}

void ZamYap()
{   
    printf("\n--- ZAM YAP ---\n");
    printf("Urun Id/Zam Miktar : ");
    int urunId;
    float zamMiktar;
    scanf("%d %f", &urunId,&zamMiktar);
    int sira = UrunBul(urunId);
    if(urunId == -1){
        printf("Urun bulunamadi !\n");
        return;
    }
    urunlerFiyat[sira] += (urunlerFiyat[sira]/100)*zamMiktar;
    UrunYazdir(sira);
}

void IndirimYap()
{
    printf("\n--- INDIRIM YAP ---\n");
    printf("Urun Id/Indirim Miktar : ");
    int urunId;
    float indirimMiktar;
    scanf("%d %f", &urunId,&indirimMiktar);
    int sira = UrunBul(urunId);
    if(urunId == -1){
        printf("Urun bulunamadi !\n");
        return;
    }
    urunlerFiyat[sira] -= (urunlerFiyat[sira]/100)*indirimMiktar;
    UrunYazdir(sira);
}

void SatisYap()
{
    printf("\n--- SATIS YAP ---\n");
    printf("Urun Id/Adet : ");
    int urunId, satisMiktar;
    scanf("%d %d", &urunId,&satisMiktar);
    int sira = UrunBul(urunId);
    if(urunId == -1){
        printf("Urun bulunamadi !\n");
        return;
    }
    if(urunlerAdet[sira] < satisMiktar){
        printf("Yeterli adet bulunmuyor !\n");
        return;
    }
    urunlerAdet[sira] -= satisMiktar;
    if(urunlerAdet[sira] == 0)
    {
        printf(">> Urun bittiginden silindi\n");
        urunlerId[sira] = 0;
        urunlerAdet[sira] = 0;
        urunlerFiyat[sira] = 0;
        mevcutAdet--;
        return;
    }
    UrunYazdir(sira);
}
