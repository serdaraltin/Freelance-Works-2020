#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;


struct ogrenci{
	int numara; 
    char ad[30];
    char soyad[30];
    int egitimKod;
};

struct node{
	struct ogrenci *ogrenci;

	struct node *sol;
	struct node *sag;
};

struct node *kok = NULL; 
int E1[4],E2[4],E3[4],E4[4],e1Boyut=0,e2Boyut=0,e3Boyut=0,e4Boyut=0;

void yazirOgrenci(struct ogrenci* ogrenci){
	printf("-----------------------------------\n");
	printf("Numara\t\t: %d\n",ogrenci->numara);
	printf("Ad\t\t: %s\n",ogrenci->ad);
	printf("Soyad\t\t: %s\n",ogrenci->soyad);
	printf("Egitim Kod\t: %d\n",ogrenci->egitimKod);
	printf("-----------------------------------\n");
}
void yazirOgrenciYatay(struct ogrenci* ogrenci){
	printf("%s",ogrenci->ad);
	printf("\t%s",ogrenci->soyad);
	printf("\t\t%d",ogrenci->numara);
	printf("\t\t%d",ogrenci->egitimKod);
	printf("\n--------------------------------------------------\n");
}

struct node *dugumYeni(struct ogrenci *ogrenci) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->ogrenci = ogrenci;
    temp->sol = NULL;
    temp->sag = NULL; 
    return temp; 
} 

void dugumListele(struct node *kok) 
{ 
    if (kok != NULL) 
    { 
        dugumListele(kok->sol); 
        yazirOgrenci(kok->ogrenci);
        dugumListele(kok->sag); 
    } 
} 

void dugumListeleEgitimKoduBazli(struct node *kok,int egitimKod) 
{ 
    if (kok != NULL) 
    { 
        dugumListeleEgitimKoduBazli(kok->sol,egitimKod); 
        if(kok->ogrenci->egitimKod == egitimKod)
        	yazirOgrenci(kok->ogrenci);
        dugumListeleEgitimKoduBazli(kok->sag,egitimKod); 
    } 
} 

struct node* dugumEkle(struct node* node, struct ogrenci *ogrenci) 
{ 

    if (node == NULL) 
    	return dugumYeni(ogrenci); 

    if (ogrenci->numara < node->ogrenci->numara) 
        node->sol  = dugumEkle(node->sol, ogrenci); 
    else if (ogrenci->numara > node->ogrenci->numara) 
        node->sag = dugumEkle(node->sag, ogrenci);    

    return node; 
} 

struct node* dugumAra(struct node* kok, int numara) 
{ 
    if (kok == NULL || kok->ogrenci->numara == numara) 
       return kok; 

    if (kok->ogrenci->numara < numara) 
       return dugumAra(kok->sag, numara); 
  
    return dugumAra(kok->sol, numara); 
} 

struct node * enKucukDeger(struct node* node) { 
    struct node* current = node; 
  
    while (current && current->sol != NULL) 
        current = current->sol; 
  
    return current; 
} 

struct node* dugumSil(struct node* kok, int numara) { 
    if (kok == NULL) 
    	return kok; 
    if (numara < kok->ogrenci->numara) 
        kok->sol = dugumSil(kok->sol, numara); 
    else if (numara > kok->ogrenci->numara) 
        kok->sag = dugumSil(kok->sag, numara); 
    else{ 
        if (kok->sol == NULL){ 
            struct node *temp = kok->sag; 
            free(kok); 
            return temp; 
        } 
        else if (kok->sag == NULL){ 
            struct node *temp = kok->sol; 
            free(kok); 
            return temp; 
        } 

        struct node* temp = enKucukDeger(kok->sag); 
  
        kok->ogrenci->numara = temp->ogrenci->numara; 
  
        kok->sag = dugumSil(kok->sag, temp->ogrenci->numara); 
    } 
    return kok; 
} 


void Menu();

void YeniOgrenciEkle(int numara,char ad[],char soyad[], int egitimKod);
void OgrenciEkle();
int EgitimKoduGir(int numara);
int EgitimKoduGirOto(int numara,int egitimKod);
void OgrenciDuzenle();
void OgrenciSil();

void KayitlariListele();
void SeminerKayitlari();
void SeminerListele(int egitim[],int boyut);

void SurpizCekilis();
void CekilisYap(int egitim[],int boyut);



void OgrenciEkle(){
	printf("-------Yeni Ogrenci Ekleme-------\n");

	printf("Numara\t: ");	
	int numara;
	cin >> numara;


	if(dugumAra(kok,numara) != NULL){
		printf("Bu numara baska ogrenciye ait.Tekrar deneyiniz!\n");
		OgrenciEkle();
		return;
	}

	printf("Ad\t: ");
	char ad[30];
	cin >> ad;

	printf("Soyad\t: ");
	char soyad[30];
	cin >> soyad;



	struct ogrenci* yeniOgrenci = (struct ogrenci*)malloc(sizeof(struct ogrenci));
    yeniOgrenci->numara = numara;
    strcpy(yeniOgrenci->ad,ad);
    strcpy(yeniOgrenci->soyad,soyad);
    yeniOgrenci->egitimKod = EgitimKoduGir(numara);

    if(kok == NULL)
    	kok = dugumEkle(kok,yeniOgrenci);
    else
    	dugumEkle(kok,yeniOgrenci);

    yazirOgrenci(yeniOgrenci);
    printf("Yeni ogrenci eklendi.\n");
}

void YeniOgrenciEkle(int numara,char ad[],char soyad[], int egitimKod){

	struct ogrenci* yeniOgrenci = (struct ogrenci*)malloc(sizeof(struct ogrenci));
    yeniOgrenci->numara = numara;
    strcpy(yeniOgrenci->ad,ad);
    strcpy(yeniOgrenci->soyad,soyad);
    yeniOgrenci->egitimKod = EgitimKoduGirOto(numara,egitimKod);

    if(kok == NULL)
    	kok = dugumEkle(kok,yeniOgrenci);
    else
    	dugumEkle(kok,yeniOgrenci);
}
int EgitimKoduGirOto(int numara,int egitimKod){
	switch(egitimKod){
		case 1:
			if(e1Boyut == 4){
				return EgitimKoduGir(numara);
			}
			E1[e1Boyut++] = numara;
			break;
		case 2:
			if(e2Boyut == 4){
				return EgitimKoduGir(numara);
			}
			E2[e2Boyut++] = numara;
			break;
		case 3:
			if(e3Boyut == 4){
				return EgitimKoduGir(numara);
			}
			E3[e3Boyut++] = numara;
			break;
		case 4:
			if(e4Boyut == 4){
				return EgitimKoduGir(numara);
			}
			E4[e4Boyut++] = numara;
			break;

	}
	return egitimKod;
}

int EgitimKoduGir(int numara){
	int kontrol = 0;
	printf("Egitim Kodu [1,2,3,4]: ");
	int egitimKod;
	cin >> egitimKod;
	switch(egitimKod){
		case 1:
			if(e1Boyut == 4){
				printf("Uzgunuz, egitimimizin kotasi dolmustur\n");
				return EgitimKoduGir(numara);
			}
			E1[e1Boyut++] = numara;
			break;
		case 2:
			if(e2Boyut == 4){
				printf("Uzgunuz, egitimimizin kotasi dolmustur\n");
				return EgitimKoduGir(numara);
			}
			E2[e2Boyut++] = numara;
			break;
		case 3:
			if(e3Boyut == 4){
				printf("Uzgunuz, egitimimizin kotasi dolmustur\n");
				return EgitimKoduGir(numara);
			}
			E3[e3Boyut++] = numara;
			break;
		case 4:
			if(e4Boyut == 4){
				printf("Uzgunuz, egitimimizin kotasi dolmustur\n");
				return EgitimKoduGir(numara);
			}
			E4[e4Boyut++] = numara;
			break;
		default:
			printf("Hatali bir secim yaptiniz! Tekrar deneyiniz.\n"); 
			return EgitimKoduGir(numara);
			break;
	}
	return egitimKod;
}

void OgrenciDuzenle(){
	printf("-------Ogrenci Duzenleme-------\n");

	printf("Numara\t: ");	
	int numara;
	cin >> numara;

	if(dugumAra(kok,numara) == NULL){
		printf("Ogrenci bulunamadi!\n");
		return;
	}

	struct ogrenci* aranan = dugumAra(kok,numara)->ogrenci;

	printf("Ad\t: ");
	char ad[30];
	cin >> ad;

	printf("Soyad\t: ");
	char soyad[30];
	cin >> soyad;

    strcpy(aranan->ad,ad);
    strcpy(aranan->soyad,soyad);
    aranan->egitimKod = EgitimKoduGir(numara);

    yazirOgrenci(aranan);
    printf("Ogrenci duzenlendi.\n");
}

void OgrenciSil(){
	if(kok == NULL){
		printf("Hic kayit yok!\n");
		return;
	}
	printf("-------Ogrenci Goruntuleme-------\n");
	printf("1) Tum ogrencileri sil\n");
	printf("2) Numarasina gore ogrenci sil\n");
	printf("3) Ana menuye don\n");
	printf("Secim : ");
	int sec;
	cin >> sec;

	if(sec == 1){
		free(kok);
		kok = NULL;
		printf("Tum ogrenciler silindi.\n");
	}
	else if(sec == 2){
		printf("Numara\t: ");	
		int numara;
		cin >> numara;

		if(dugumAra(kok,numara) == NULL){
			printf("Ogrenci bulunamadi!\n");
			return;
		}
		kok = dugumSil(kok,numara);
		printf("Ogrenci silindi.\n");
	}
	else if(sec == 3)
		return;
	else
		printf("Hatali bir secim yaptiniz!!!\n");
	OgrenciSil();	
}

void KayitlariListele(){
	if(kok == NULL){
		printf("Hic kayit yok!\n");
		return;
	}
	printf("-------Liste Goruntuleme-------\n");
	printf("1) Tum listeyi goruntule\n");
	printf("2) Egitim kodu bazli liste goruntule\n");
	printf("3) Ana menuye don\n");
	printf("Secim : ");
	int sec;
	cin >> sec;

	if(sec == 1){
		dugumListele(kok);
	}
	else if(sec == 2){
		printf("Egitim Kod : ");
		int egitimKod;
		cin >> egitimKod;
		if(egitimKod >0 && egitimKod < 5)
			dugumListeleEgitimKoduBazli(kok,egitimKod);
		else{
			printf("Hatali giris yaptiniz!!!\n");
			KayitlariListele();
		}
	}
	else if(sec == 3)
		return;
	else
		printf("Hatali bir secim yaptiniz!!!\n");
	KayitlariListele();
}

void SeminerKayitlari(){
	if(kok == NULL){
		printf("Hic kayit yok!\n");
		return;
	}
	printf("-------Seminer Kayitlari Goruntuleme-------\n");
	printf("1) Tum seminerleri goruntule\n");
	printf("2) Seminer koduna gore goruntule\n");
	printf("3) Ana menuye don\n");
	printf("Secim : ");
	int sec;
	cin >> sec;

	if(sec == 1){
		int toplamSeminerKayit = e1Boyut+e2Boyut+e3Boyut+e4Boyut;
		printf("\nTum seminerlerdeki toplam kayit sayisi : %d\n",toplamSeminerKayit);
		printf("\nAd\tSoyad\tOgrenci No\tEgitim Kodu\n");
		printf("\n--------------------------------------------------\n");
		SeminerListele(E1,e1Boyut);
		SeminerListele(E2,e2Boyut);
		SeminerListele(E3,e3Boyut);
		SeminerListele(E4,e4Boyut);
	}
	else if(sec == 2){
		printf("Egitim Kod : ");
		int egitimKod;
		cin >> egitimKod;
		printf("\nAd\tSoyad\tOgrenci No\tEgitim Kodu\n");
		printf("\n--------------------------------------------------\n");
		switch(egitimKod){
			case 1:
				SeminerListele(E1,e1Boyut);
				break;
			case 2:
				SeminerListele(E1,e2Boyut);
				break;
			case 3:
				SeminerListele(E1,e3Boyut);
				break;
			case 4:
				SeminerListele(E1,e4Boyut);
				break;
			default:
				printf("Hatali bir secim yaptiniz!!!\n");
				SeminerKayitlari();
				break;
		}
	}
	else if(sec == 3)
		return;
	else
		printf("Hatali bir secim yaptiniz!!!\n");
	SeminerKayitlari();
}

void SeminerListele(int egitim[],int boyut){
	int i;
	for (i = 0; i < boyut; i++){
		if(dugumAra(kok,egitim[i])){
			yazirOgrenciYatay(dugumAra(kok,egitim[i])->ogrenci);
		}
	}
}

void SurpizCekilis(){
	printf("-------Surpiz Hediye Cekilisi-------\n");
	printf("Egitim Kod : ");
	int egitimKod;
	cin >> egitimKod;
	switch(egitimKod){
		case 1:
			CekilisYap(E1,e1Boyut);
			break;
		case 2:
			CekilisYap(E2,e2Boyut);
			break;
		case 3:
			CekilisYap(E3,e3Boyut);
			break;
		case 4:
			CekilisYap(E4,e4Boyut);
			break;
		default:
			printf("Hatali bir secim yaptiniz!!!\n");
			SeminerKayitlari();
			break;
	}
}

void CekilisYap(int egitim[],int boyut){
	int i,enKucuk = egitim[0],enBuyuk =egitim[0];
	for (i = 0; i < boyut; i++){
		if(egitim[i] < enKucuk)
			enKucuk = egitim[i];
		if(egitim[i] > enBuyuk)
			enBuyuk = egitim[i];
	}
	printf("Kazanan Ogrenci/ler >> \n");
	if(enKucuk == enBuyuk)
		yazirOgrenci(dugumAra(kok,enBuyuk)->ogrenci);
	else{
		yazirOgrenci(dugumAra(kok,enKucuk)->ogrenci);
		yazirOgrenci(dugumAra(kok,enBuyuk)->ogrenci);
	}
}
