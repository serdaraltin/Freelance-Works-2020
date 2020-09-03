#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MUSTERI_DOSYA "musteri.txt"
#define ARAC_DOSYA "arac.txt"

struct node2{
	char plaka[20];
	char marka[20];
	char model[30];

	float gunlukUcret;	

	struct node2 *Onceki;
	struct node2 *Sonraki;
};
typedef struct node2 Arac;

struct node{
	char tcno[12];
	char ad[20];
	char soyad[20];
	char mailAdres[30];
	char telefon[12];

	char baslangicTarih[12];
	
	struct node2 *arac;

	int gunSayisi;

	struct node *Onceki;
	struct node *Sonraki;
};
typedef struct node Musteri;



Musteri *Musteriler; 
Arac *Araclar;

void Menu();

void DosyaOkuMusteri();
void DosyaOkuArac();

void DosyaYazMusteri();
void DosyaYazArac();

void YeniMusteriEkle();
void YeniAracEkle();

void MusteriEkle(char *tcno,char* ad,char* soyad,char* mailAdres,char * telefon,
	char* baslangicTarih, char *plaka, int gunSayisi);
void AracEkle(char *plaka,char* marka,char* model,float gunlukUcret);

void YazdirMusteri(Musteri*);
void YazdirArac(Arac*);

Musteri* AraMusteri(char tcno[12]);
Arac* AraArac(char plaka[20]);
Arac* GetirArac(char plaka[20]);

void GuncelleMusteri(char tcno[12]);
void GuncelleArac(char plaka[20]);

void ListeleMusteri();
void ListeleArac();

Musteri* SilMusteri(char tcno[12]);
Arac* SilArac(char plaka[20]);

int main(){
	Musteriler = NULL;
	Araclar = NULL;
	DosyaOkuArac();
	printf("\nHosgeldiniz...\n");
	Menu();
}

void Menu(){
	DosyaYazArac();
	DosyaYazMusteri();
	printf("\n=================================================\n");

	printf("1) Musterileri Listele\n");
	printf("2) Yeni Musteri Ekle\n");
	printf("3) Musteri Guncelle\n");
	printf("4) Musteri Sil\n");
	printf("5) Musteri Ara\n");

	printf("6) Araclari Listele\n");
	printf("7) Yeni Arac Ekle\n");
	printf("8) Arac Guncelle\n");
	printf("9) Arac Sil\n");
	printf("10) Arac Ara\n");

	printf("0) Cikis\n");
	printf("=================================================\n");
	printf("\n\nSeciniz : ");
	int sec;
	scanf("%d",&sec);
	printf("\n");
	switch(sec){
		case 0:
			printf("Programdan cikiliyor...\n");
			exit(0);
			break;
		case 1:
			printf("------> LISTELE MUSTERI\n");
			ListeleMusteri();
			Menu();
			break;
		case 2:
			printf("------> EKLE MUSTERI\n");
			YeniMusteriEkle();
			Menu();
			break;	
		case 3:
			printf("------> GUNCELLE MUSTERI\n");
			printf("Musteri TcNo : ");
			char gtcno[12];
			scanf("%s",gtcno);
			GuncelleMusteri(gtcno);
			Menu();
			break;	
		case 4:
			printf("------> SIL MUSTERI\n");
			printf("Musteri TcNo : ");
			char stcno[12];
			scanf("%s",stcno);
			Musteriler = SilMusteri(stcno);
			Menu();
			break;
		case 5:
			printf("------> ARA MUSTERI\n");
			printf("Musteri TcNo : ");		
			char atcno[12];
			scanf("%s",atcno);
			AraMusteri(atcno);
			Menu();
			break;
		case 6:
			printf("------> LISTELE ARAC\n");
			ListeleArac();
			Menu();
			break;
		case 7:
			printf("------> EKLE ARAC\n");
			YeniAracEkle();
			Menu();
			break;	
		case 8:
			printf("------> GUNCELLE ARAC\n");
			printf("Plaka : ");
			char gplaka[20];
			scanf("%s",gplaka);
			GuncelleArac(gplaka);
			Menu();
			break;	
		case 9:
			printf("------> SIL ARAC\n");
			printf("Plaka : ");
			char splaka[20];
			scanf("%s",splaka);
			Araclar = SilArac(splaka);
			Menu();
			break;
		case 10:
			printf("------> ARA ARAC \n");
			printf("Plaka : ");		
			char aplaka[20];
			scanf("%s",aplaka);
			AraArac(aplaka);
			Menu();
			break;
	}
}

void DosyaYazMusteri(){
	if(!fopen(MUSTERI_DOSYA,"w")){
		printf("\nMusteri dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya;
		dosya = fopen(MUSTERI_DOSYA,"w");
	
		Musteri *iter = Musteriler;
		while(iter->tcno != NULL){
			//tcno ad soyad mailadres telefon baslangicTarih arac gunsayisi
			fprintf(dosya,"%s %s %s %s %s %s %s %d\n",
			iter->tcno,iter->ad,iter->soyad,iter->mailAdres,iter->telefon,iter->baslangicTarih,iter->arac->plaka,iter->gunSayisi);		
			iter = iter->Sonraki;
		}
		fclose(dosya);
	}

}

void DosyaYazArac(){
	if(!fopen(ARAC_DOSYA,"w")){
		printf("\nArac dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya;
		dosya = fopen(ARAC_DOSYA,"w");
	
		Arac *iter = Araclar;
		while(iter->plaka != NULL){
			//plaka marka model gunlukUcret
			fprintf(dosya,"%s %s %s %f\n",
			iter->plaka,iter->marka,iter->model,iter->gunlukUcret);		
			iter = iter->Sonraki;
		}
		fclose(dosya);
	}
}

void DosyaOkuMusteri(){	
	if(!fopen(MUSTERI_DOSYA,"r")){
		printf("\nMusteri dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya;
	dosya = fopen(MUSTERI_DOSYA,"r");
	
		while(!feof(dosya)){
		char *tcno= (char*)malloc(sizeof(char)*100);
		char *ad= (char*)malloc(sizeof(char)*100);
		char *soyad= (char*)malloc(sizeof(char)*100);
		char *mailAdres= (char*)malloc(sizeof(char)*100);
		char *telefon= (char*)malloc(sizeof(char)*100);
		char *baslangicTarih= (char*)malloc(sizeof(char)*100);
		char *plaka = (char*)malloc(sizeof(char)*100);
		int gunSayisi;
		//tcno ad soyad mailadres telefon baslangicTarih plaka gunsayisi
		fscanf(dosya,"%s %s %s %s %s %s %s %d\n",
		tcno,ad,soyad,mailAdres,telefon,baslangicTarih,plaka,&gunSayisi);
	   	if(strcmp(tcno,"")!=0 && GetirArac(plaka) != NULL)
	   		MusteriEkle(tcno,ad,soyad,mailAdres,telefon,baslangicTarih,plaka,gunSayisi);
		}
		fclose(dosya);
	}
}

void DosyaOkuArac(){	
	if(!fopen(ARAC_DOSYA,"r")){
		printf("\nArac dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya;
	dosya = fopen(ARAC_DOSYA,"r");
	
		while(!feof(dosya)){
		char *plaka = (char*)malloc(sizeof(char)*100);
		char *marka = (char*)malloc(sizeof(char)*100);
		char *model = (char*)malloc(sizeof(char)*100);
		float gunlukUcret;
		//plaka marka model gunlukUcret
		fscanf(dosya,"%s %s %s %f\n",
		plaka,marka,model,&gunlukUcret);
	   	if(strcmp(plaka,"")!=0)
	   		AracEkle(plaka,marka,model,gunlukUcret);
		}
		fclose(dosya);
	}
	DosyaOkuMusteri();
}

void YazdirMusteri(Musteri* musteri){
	float ucret = musteri->arac->gunlukUcret * musteri->gunSayisi;
	printf("TcNo\t: %s\nAd\t: %s\nSoyad\t: %s\nMail\t: %s\nTelefon\t: %s\nBaslangic Tarih\t: %s\n\n-----Arac Bilgileri----------\n\nPlaka\t: %s\nMarka\t: %s\nModel\t: %s\nUcret\t: %.2f TL\n",
	musteri->tcno,musteri->ad,musteri->soyad,musteri->mailAdres,musteri->telefon,musteri->baslangicTarih,musteri->arac->plaka,musteri->arac->marka,musteri->arac->model,ucret);	
	printf("\n---------------------------------------\n\n");
}

void YazdirArac(Arac* arac){
	printf("Plaka\t: %s\nMarka\t: %s\nModel\t: %s\nGunluk Ucret\t: %.2f TL\n",
	arac->plaka,arac->marka,arac->model,arac->gunlukUcret);	
	printf("\n---------------------------------------\n\n");
}

Musteri* AraMusteri(char tcno[12]){
	Musteri *liste = Musteriler;
	if(liste == NULL){
		printf("\nHic musteri kaydi yok !!!\n");
		return NULL;
	}
	printf("\n=============MUSTERI ARAMASI=============\n");

	while(liste != NULL){
		if(strcmp(liste->tcno,tcno)==0){
			YazdirMusteri(liste);
			return liste;
		}
		liste = liste->Sonraki;
	}
	printf("\nAranan musteri kayitlarda yok!!!\n");	
}

Arac* AraArac(char plaka[20]){
	Arac *liste = Araclar;
	if(liste == NULL){
		printf("\nHic arac kaydi yok !!!\n");
		return NULL;
	}
	printf("\n=============ARAC ARAMASI=============\n");

	while(liste != NULL){
		if(strcmp(liste->plaka,plaka)==0){
			YazdirArac(liste);
			return liste;
		}
		liste = liste->Sonraki;
	}
	printf("\nAranan arac kayitlarda yok!!!\n");	
}

Arac* GetirArac(char plaka[20]){
	Arac *liste = Araclar;
	if(liste == NULL){
		return NULL;
	}
	while(liste != NULL){
		if(strcmp(liste->plaka,plaka)==0){
			return liste;
		}
		liste = liste->Sonraki;
	}
}
void YeniMusteriEkle(){
	if(Araclar == NULL){
		printf("Hic arac kaydi olmadigi icin musteri ekelenemez !!!!\n");
		return;
	}
	printf("============ Musteri Ekle ============\n");
	printf("TcNo\t: ");
	char tcno[12];
	scanf("%s",tcno);

	printf("Ad\t: ");
	char ad[20];
	scanf("%s",ad);

	printf("Soyad\t: ");
	char soyad[20];
	scanf("%s",soyad);

	printf("Telefon\t: ");
	char telefon[12];
	scanf("%s",telefon);

	printf("Mail\t: ");
	char mailAdres[30];
	scanf("%s",mailAdres);

	printf("Baslangic Tarih\t: ");
	char baslangicTarih[12];
	scanf("%s",baslangicTarih);

	printf("Plaka \t: ");
	char plaka[20];
	scanf("%s",plaka);

	printf("Gun Sayisi \t: ");
	int gunSayisi;
	scanf("%d",&gunSayisi);
	
	MusteriEkle(tcno,ad,soyad,mailAdres,telefon,baslangicTarih,plaka,gunSayisi);
}

void YeniAracEkle(){
	printf("============ Arac Ekle ============\n");
	printf("Plaka \t: ");
	char plaka[20];
	scanf("%s",plaka);

	printf("Marka \t: ");
	char marka[20];
	scanf("%s",marka);

	printf("Model \t: ");
	char model[20];
	scanf("%s",model);

	printf("Gunluk Ucret \t: ");
	float gunlukUcret;
	scanf("%f",&gunlukUcret);
	
	AracEkle(plaka,marka,model,gunlukUcret);
}

void MusteriEkle(char* tcno,char* ad,char* soyad,char* mailAdres,char * telefon,char *baslangicTarih,char *plaka, int gunSayisi){
	
	Arac* arac = GetirArac(plaka);

	if(arac == NULL){
		printf("\nPlakaya kayitli arac kaydi yok tekrar deneyin !!!\n");
		while (arac == NULL){
			printf("Plaka \t: ");
			char plaka[20];
			scanf("%s",plaka);
			arac = GetirArac(plaka);
		}
	}
	if(Musteriler == NULL){

		Musteriler = (Musteri*)malloc(sizeof(Musteri));

		strcpy(Musteriler->tcno,tcno);
		strcpy(Musteriler->ad,ad);
		strcpy(Musteriler->soyad,soyad);
		strcpy(Musteriler->mailAdres,mailAdres);
		strcpy(Musteriler->telefon,telefon);
		strcpy(Musteriler->baslangicTarih,baslangicTarih);
		Musteriler->arac = arac;
		Musteriler->gunSayisi = gunSayisi;

		Musteriler->Onceki = NULL;
		Musteriler->Sonraki = NULL;		

		return;
	}
	Musteri *iter = Musteriler;

	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;

	Musteri *yeni = (Musteri*)malloc(sizeof(Musteri));

	strcpy(yeni->tcno,tcno);
	strcpy(yeni->ad,ad);
	strcpy(yeni->soyad,soyad);
	strcpy(yeni->mailAdres,mailAdres);
	strcpy(yeni->telefon,telefon);
	strcpy(yeni->baslangicTarih,baslangicTarih);
	yeni->arac = arac;
	yeni->gunSayisi = gunSayisi;

	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;


	return;		
}

void AracEkle(char* plaka,char* marka,char* model,float gunlukUcret){

	if(Araclar == NULL){

		Araclar = (Arac*)malloc(sizeof(Arac));

		strcpy(Araclar->plaka,plaka);
		strcpy(Araclar->marka,marka);
		strcpy(Araclar->model,model);
		Araclar->gunlukUcret = gunlukUcret;

		Araclar->Onceki = NULL;
		Araclar->Sonraki = NULL;		
		return;
	}
	Arac *iter = Araclar;

	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;

	Arac *yeni = (Arac*)malloc(sizeof(Arac));

	strcpy(yeni->plaka,plaka);
	strcpy(yeni->marka,marka);
	strcpy(yeni->model,model);
	yeni->gunlukUcret = gunlukUcret;

	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;
	return;		
}

void ListeleMusteri(){
	Musteri *liste = Musteriler;
	if(liste == NULL){
		printf("\nHic musteri kaydi yok !!!\n");
		return;
	}
	printf("\n=============MUSTERI LISTESI=============\n\n");
	while(liste != NULL){
		YazdirMusteri(liste);
		liste = liste->Sonraki;
	}
	printf("\n");
}

void ListeleArac(){
	Arac *liste = Araclar;
	if(liste == NULL){
		printf("\nHic arac kaydi yok !!!\n");
		return;
	}
	printf("\n=============ARAC LISTESI=============\n\n");
	while(liste != NULL){
		YazdirArac(liste);
		liste = liste->Sonraki;
	}
	printf("\n");
}

void GuncelleMusteri(char tcno[12]){
	Musteri *liste = Musteriler;
	if(liste == NULL){
		printf("\nHic musteri kaydi yok !!!\n");
		return;
	}
	printf("\n=============MUSTERI GUNCELLEME=============\n");

	while(liste != NULL){
		if(strcmp(liste->tcno,tcno)==0){
			YazdirMusteri(liste);
			printf("YENI BILGILER >>\n\n");

			printf("TcNo\t: ");
			char tcno[12];
			scanf("%s",tcno);

			printf("Ad\t: ");
			char ad[20];
			scanf("%s",ad);

			printf("Soyad\t: ");
			char soyad[20];
			scanf("%s",soyad);

			printf("Telefon\t: ");
			char telefon[12];
			scanf("%s",telefon);

			printf("Mail\t: ");
			char mailAdres[30];
			scanf("%s",mailAdres);

			printf("Baslangic Tarih\t: ");
			char baslangicTarih[12];
			scanf("%s",baslangicTarih);

			printf("Plaka \t: ");
			char plaka[20];
			scanf("%s",plaka);

			printf("Gun Sayisi \t: ");
			int gunSayisi;
			scanf("%d",&gunSayisi);

			Arac* arac = GetirArac(plaka);

			strcpy(liste->tcno,tcno);
			strcpy(liste->ad,ad);
			strcpy(liste->soyad,soyad);
			strcpy(liste->mailAdres,mailAdres);
			strcpy(liste->telefon,telefon);
			strcpy(liste->baslangicTarih,baslangicTarih);
			liste->arac = arac;
			liste->gunSayisi = gunSayisi;
		
			return;
		}
		liste = liste->Sonraki;
	}
	printf("\nAranan musteri kayitlarda yok!!!\n");	
}

void GuncelleArac(char plaka[20]){
	Arac *liste = Araclar;
	if(liste == NULL){
		printf("\nHic arac kaydi yok !!!\n");
		return;
	}
	printf("\n=============ARAC GUNCELLEME=============\n");

	while(liste != NULL){
		if(strcmp(liste->plaka,plaka)==0){
			YazdirArac(liste);
			printf("YENI BILGILER >>\n\n");

			printf("Plaka \t: ");
			char plaka[20];
			scanf("%s",plaka);

			printf("Marka \t: ");
			char marka[20];
			scanf("%s",marka);

			printf("Model \t: ");
			char model[20];
			scanf("%s",model);

			printf("Gunluk Ucret \t: ");
			float gunlukUcret;
			scanf("%f",&gunlukUcret);

			strcpy(liste->plaka,plaka);
			strcpy(liste->marka,marka);
			strcpy(liste->model,model);
			liste->gunlukUcret = gunlukUcret;	
			return ;
		}
		liste = liste->Sonraki;
	}
	printf("\nAranan arac kayitlarda yok!!!\n");	
	
}

Musteri* SilMusteri(char tcno[12]){
	Musteri *iter = Musteriler;
	Musteri *temp;

	if(strcmp(Musteriler->tcno,tcno) == 0){
		YazdirMusteri(Musteriler);
		printf("Musteri silindi.\n");
		temp = Musteriler;
		Musteriler = Musteriler->Sonraki;
		free(temp);
		return Musteriler;
	}

	while(iter->Sonraki != NULL && strcmp(iter->Sonraki->tcno,tcno) != 0)
		iter = iter->Sonraki;
	
	if(iter->Sonraki == NULL)
	{
		printf("\nAranan musteri kayitlarda yok!!!\n");	
		return Musteriler;
	}

	temp = iter->Sonraki;
	iter->Sonraki = iter->Sonraki->Sonraki;
	YazdirMusteri(temp);
	printf("Musteri silindi.\n");
	free(temp);

	if(iter->Sonraki != NULL)
		iter->Sonraki->Onceki = iter;

	return Musteriler;
}

Arac* SilArac(char plaka[20]){
	Arac *iter = Araclar;
	Arac *temp;

	if(strcmp(Araclar->plaka,plaka) == 0){
		YazdirArac(Araclar);
		printf("Arac silindi.\n");
		temp = Araclar;
		Araclar = Araclar->Sonraki;
		free(temp);
		return Araclar;
	}

	while(iter->Sonraki != NULL && strcmp(iter->Sonraki->plaka,plaka) != 0)
		iter = iter->Sonraki;
	
	if(iter->Sonraki == NULL)
	{
		printf("\nAranan arac kayitlarda yok!!!\n");	
		return Araclar;
	}

	temp = iter->Sonraki;
	iter->Sonraki = iter->Sonraki->Sonraki;
	YazdirArac(temp);
	printf("Arac silindi.\n");
	free(temp);

	if(iter->Sonraki != NULL)
		iter->Sonraki->Onceki = iter;

	return Araclar;
}
 
