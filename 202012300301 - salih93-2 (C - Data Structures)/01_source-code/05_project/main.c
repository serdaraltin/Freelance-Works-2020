#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOYUT 10

typedef struct main
{
    int musteri_no;
    char ad[20], soyad[20];
} Musteri;

Musteri veri_liste[BOYUT];

/*
hash_tablo[x][0] ---- > musteri_no
hash_tablo[x][1] ---- > next
*/
int hash_tablo[BOYUT][2] = {-1, -1};

void diziHazirla();
void dosyaOku();
void menu();
int hashHesapla(int musteri_no);
int hashKontrol(int hash_no);
void yeniKayit(Musteri *musteri);
void veriListeEkle(Musteri *musteri, int index_no);
int nextDegeri(int hash_no);
int musteriAra(int musteri_no, int *index_no, int *adim);

void ekle();
void ara();
void sil();
void hashTablosuListele();
void veriListele();
void ortalamaAdimSayisi();

int main()
{
    diziHazirla();
    dosyaOku();

    menu();
}

void menu()
{
    int i = 1;
    printf("%d) Ekleme Islemi\n", i++);
    printf("%d) Arama Islemi\n", i++);
    printf("%d) Silme Islemi\n", i++);
    printf("%d) Hash Tablosunu Listeleme\n", i++);
    printf("%d) Veri Listesini Listeleme\n", i++);
    printf("%d) Ortalama Adim Sayisi\n", i++);
    printf("0) Cikis\n\n");
    printf("Secim : ");
    int secim;
    scanf("%d", &secim);
    printf("\n");
    switch (secim)
    {
    case 0:
        printf("\nProgramdan cikiliyor...\n");
        exit(0);
        break;
    case 1:
        ekle();
        break;
    case 2:
        ara();
        break;
    case 3:
        sil();
        break;
    case 4:
        hashTablosuListele();
        break;
    case 5:
        veriListele();
        break;
    case 6:
        ortalamaAdimSayisi();
        break;

    default:
        printf("\nHatali secim !");
        break;
    }
    printf("\n");
    menu();
}

void diziHazirla()
{
    int i;
    //hazirlama (diziyi -1 ile doldurma)
    for (i = 0; i < BOYUT; i++)
    {
        hash_tablo[i][0] = hash_tablo[i][1] = -1;
    }
}

void dosyaOku()
{
    FILE *dosya = fopen("veri.txt", "r");

    Musteri *musteri = (Musteri *)malloc(sizeof(Musteri));

    while (!feof(dosya))
    {
        fscanf(dosya, "%d %s %s", &musteri->musteri_no, musteri->ad, musteri->soyad);
        yeniKayit(musteri);
        //printf("%d %s %s\n",musteri->musteri_no,musteri->ad,musteri->soyad);
    }
}

int hashHesapla(int musteri_no)
{
    return musteri_no % 10;
}

int hashKontrol(int hash_no)
{
    if (hash_tablo[hash_no][0] == -1)
    {
        return 1;
    }
    return 0;
}

void veriListeEkle(Musteri *musteri, int index_no)
{
    veri_liste[index_no].musteri_no = musteri->musteri_no;
    strcpy(veri_liste[index_no].ad, musteri->ad);
    strcpy(veri_liste[index_no].soyad, musteri->soyad);
    return;
}

int nextDegeri(int hash_no)
{
    if (hash_tablo[hash_no][1] == -1)
    {
        return hash_no;
    }
    return nextDegeri(hash_tablo[hash_no][1]);
}

void yeniKayit(Musteri *musteri)
{
    int i;
    int hash_no = hashHesapla(musteri->musteri_no);

    if (hashKontrol(hash_no))
    {
        hash_tablo[hash_no][0] = musteri->musteri_no;
        veriListeEkle(musteri, hash_no);
        return;
    }
    int next = -1;
    for (i = 0; i < BOYUT; i++)
    {
        if (hashKontrol(i))
        {
            hash_tablo[nextDegeri(hash_no)][1] = i;
            hash_tablo[i][0] = musteri->musteri_no;
            veriListeEkle(musteri, i);
            break;
        }
    }
}

void ekle()
{
    Musteri *musteri = (Musteri *)malloc(sizeof(Musteri));

    printf("Musteri No : ");
    scanf("%d", &musteri->musteri_no);

    printf("Ad : ");
    scanf("%s", musteri->ad);

    printf("Soyad : ");
    scanf("%s", musteri->soyad);

    yeniKayit(musteri);
}

int musteriAra(int musteri_no, int *index_no, int *adim)
{
    if (hash_tablo[(*index_no)][0] == musteri_no)
    {
        return (*index_no);
    }

    if (hash_tablo[(*index_no)][1] == -1)
    {
        return -1;
    }

    if (hash_tablo[(*index_no)][1] != musteri_no)
    {
        (*adim)++;
        (*index_no) = hash_tablo[(*index_no)][1];
        return musteriAra(musteri_no, index_no, adim);
    }
}

void ara()
{
    int musteri_no;
    printf("Musteri No : ");
    scanf("%d", &musteri_no);
    int adim = 1;
    int index_no = hashHesapla(musteri_no);

    if (musteriAra(musteri_no, &index_no, &adim) == -1)
    {
        printf("\nAranilan Deger : %d\n", musteri_no);
        printf("Veri bulunamadi.\n");
        return;
    }

    printf("\nAranilan Deger : %d\n", musteri_no);
    printf("%d %s %s\n", musteri_no, veri_liste[index_no].ad, veri_liste[index_no].soyad);
    printf("Veri %d adimda bulundu.\n", adim);
    return;
}

void sil()
{
    int musteri_no;
    printf("Musteri No : ");
    scanf("%d", &musteri_no);

    int hash_no = hashHesapla(musteri_no);
    if (hashKontrol(hash_no))
    {
        printf("Boyle bir kayit yok.\n");
        return;
    }
    int i;
    for (i = 0; i < BOYUT; i++)
    {
        if (hash_tablo[i][0] == musteri_no)
            break;
    }
    if (i == 10 && hash_tablo[i][0] != musteri_no)
    {
        printf("Boyle bir kayit yok.\n");
        return;
    }

    printf("Silinen Deger : %d %s %s\n", musteri_no, veri_liste[i].ad, veri_liste[i].soyad);
    hash_tablo[i][0] = hash_tablo[i][1] = -1;
    veri_liste[i].musteri_no = 0;
    veri_liste[i].ad[0] = '\0';
    veri_liste[i].soyad[0] = '\0';

    return;
}

void hashTablosuListele()
{
    int i;
    for (i = 0; i < BOYUT; i++)
    {
        printf("%4d %2d\n", hash_tablo[i][0], hash_tablo[i][1]);
    }
    printf("\n");
    return;
}

void veriListele()
{
    int i;
    for (i = 0; i < BOYUT; i++)
    {
        if (veri_liste[i].musteri_no != 0)
            printf("%4d %s %s\n", veri_liste[i].musteri_no, veri_liste[i].ad, veri_liste[i].soyad);
    }
    printf("\n");
}

void ortalamaAdimSayisi()
{
    int i, adim = 1, toplamAdim = 0, toplamKayit = 0;

    for (i = 0; i < BOYUT; i++)
    {
        if (veri_liste[i].musteri_no == 0)
            continue;
        adim = 1;
        int musteri_no = veri_liste[i].musteri_no;
        int index_no = hashHesapla(musteri_no);
        musteriAra(musteri_no, &index_no, &adim);

        toplamKayit++;
        toplamAdim += adim;
    }
    printf("\nListedeki kayitlar icin ortalama %.2f adim.\n", ((float)toplamAdim / toplamKayit));
}