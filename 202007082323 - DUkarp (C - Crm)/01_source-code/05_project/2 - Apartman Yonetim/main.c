#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char tcno[12];
	char ad[20];
	char soyad[20];
	char mailAdres[30];
	char telefon[12];
	char dogumTarih[12];
	int medeniHal;
	int  kat;
	int daire;
	char baslangicTarih[12];

	struct node *Onceki;
	struct node *Sonraki;
};
typedef struct node Uye;

Uye *Uyeler; 

void Menu();
void YeniUyeEkle();
void UyeEkle(char *tcno,char* ad,char* soyad,char* mailAdres,char * telefon,char* dogumTarih,int medeniHal,int kat,int daire,char *baslangicTarih);
void Listele();
void Ara(char tcno[12]);
void Guncelle(char tcno[12]);
Uye* Sil(char tcno[12]);
void Yazdir(Uye*);
void DosyaYaz();
void DosyaOku();

int main(){
	Uyeler = NULL;
	DosyaOku();
	Menu();
}

void Menu(){
	DosyaYaz();
	printf("\n=================================================\n");
	printf("1) Uyeleri Listele\n");
	printf("2) Yeni Uye Ekle\n");
	printf("3) Uye Guncelle\n");
	printf("4) Uye Sil\n");
	printf("5) Uye Ara\n");
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
			printf("------> LISTELE\n");
			Listele();
			Menu();
			break;
		case 2:
			printf("------> EKLE\n");
			YeniUyeEkle();
			Menu();
			break;	
		case 3:
			printf("------> GUNCELLE\n");
			printf("Uye TcNo : ");
			char gtcno[12];
			scanf("%s",gtcno);
			Guncelle(gtcno);
			Menu();
			break;	
		case 4:
			printf("------> SIL\n");
			printf("Uye TcNo : ");
			char stcno[12];
			scanf("%s",stcno);
			Uyeler = Sil(stcno);
			Menu();
			break;
		case 5:
			printf("------> ARA\n");
			printf("Uye TcNo : ");
			char atcno[12];
			scanf("%s",atcno);
			Ara(atcno);
			Menu();
			break;
			
	}
	
}

void DosyaYaz(){
	if(!fopen("veri.txt","w")){
		printf("\nVeri dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya;
		dosya = fopen("veri.txt","w");
	
		Uye *iter = Uyeler;
		while(iter->tcno != NULL){
			fprintf(dosya,"%s %s %s %s %s %s %d %d %d %s\n",
			iter->tcno,iter->ad,iter->soyad,iter->mailAdres,iter->telefon,iter->dogumTarih,iter->medeniHal,iter->kat,iter->daire,iter->baslangicTarih);		
			iter = iter->Sonraki;
		}
		fclose(dosya);	
	}
}

void DosyaOku(){	
	if(!fopen("veri.txt","r")){
		printf("\nVeri dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya;
	dosya = fopen("veri.txt","r");
	
		while(!feof(dosya)){
		
		char *tcno= (char*)malloc(sizeof(char)*100);
		char *ad= (char*)malloc(sizeof(char)*100);
		char *soyad= (char*)malloc(sizeof(char)*100);
		char *mailAdres= (char*)malloc(sizeof(char)*100);
		char *telefon= (char*)malloc(sizeof(char)*100);
		char *dogumTarih= (char*)malloc(sizeof(char)*100);
		char *baslangicTarih= (char*)malloc(sizeof(char)*100);
		int medeniHal;
		int  kat;
		int daire;
		
		fscanf(dosya,"%s %s %s %s %s %s %d %d %d %s",
		tcno,ad,soyad,mailAdres,telefon,dogumTarih,&medeniHal,&kat,&daire,baslangicTarih);
	   	if(strcmp(tcno,"")!=0)
	   		UyeEkle(tcno,ad,soyad,mailAdres,telefon,dogumTarih,medeniHal,kat,daire,baslangicTarih);
		}
		fclose(dosya);
	}
}
void Yazdir(Uye* uye){
		printf("TcNo\t: %s\nAd\t: %s\nSoyad\t: %s\nMail\t: %s\nTelefon\t: %s\nDogum Tarih\t: %s\nMedeni Hal\t: %d\nKat\t\t: %d\nDaire\t\t: %d\nBaslangic Tarih\t: %s\n",
		uye->tcno,uye->ad,uye->soyad,uye->mailAdres,uye->telefon,uye->dogumTarih,uye->medeniHal,uye->kat,uye->daire,uye->baslangicTarih);	
		printf("=====================================\n");
}

Uye* Sil(char tcno[12]){
	Uye *iter = Uyeler;
	Uye *temp;

	if(strcmp(Uyeler->tcno,tcno) == 0){
		Yazdir(Uyeler);
		printf("Uye silindi.\n");
		temp = Uyeler;
		Uyeler = Uyeler->Sonraki; 
		free(temp);
		return Uyeler;
	}

	while(iter->Sonraki != NULL && strcmp(iter->Sonraki->tcno,tcno) != 0)
		iter = iter->Sonraki;
	
	if(iter->Sonraki == NULL)
	{
		printf("\nAranan uye kayitlarda yok!!!\n");	
		return Uyeler;
	}

	temp = iter->Sonraki;
	iter->Sonraki = iter->Sonraki->Sonraki;
	Yazdir(temp);
	printf("Uye silindi.\n");
	free(temp);

	if(iter->Sonraki != NULL)
		iter->Sonraki->Onceki = iter;

	return Uyeler;
}

void Guncelle(char tcno[12]){
	Uye *liste = Uyeler;
	if(liste == NULL){
		printf("\nHic uye kaydi yok !!!\n");
		return;
	}
	printf("\n=============UYE GUNCELLEME=============\n");

	while(liste != NULL){
		if(strcmp(liste->tcno,tcno)==0){
			Yazdir(liste);
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

			printf("Dogum Tarih\t: ");
			char dogumTarih[12];
			scanf("%s",dogumTarih);

			printf("Medeni Hal\t: ");
			int medeniHal;
			scanf("%d",&medeniHal);

			printf("Kat [0,1,2...]\t: ");
			int kat;
			scanf("%d",&kat);

			printf("Daire [5,11...]\t: ");
			int daire;
			scanf("%d",&daire);

			printf("Baslangic Tarih\t: ");
			char baslangicTarih[12];
			scanf("%s",baslangicTarih);

			strcpy(liste->tcno,tcno);
			strcpy(liste->ad,ad);
			strcpy(liste->soyad,soyad);
			strcpy(liste->mailAdres,mailAdres);
			strcpy(liste->telefon,telefon);
			strcpy(liste->dogumTarih,dogumTarih);
			strcpy(liste->baslangicTarih,baslangicTarih);
			liste->medeniHal = medeniHal;
			liste->kat = kat;
			liste->daire = daire;

			return;
		}
		liste = liste->Sonraki;
	}
	printf("\nAranan uye kayitlarda yok!!!\n");	
}

void Ara(char tcno[12]){
	Uye *liste = Uyeler;
	if(liste == NULL){
		printf("\nHic uye kaydi yok !!!\n");
		return;
	}
	printf("\n=============UYE ARAMASI=============\n");

	while(liste != NULL){
		if(strcmp(liste->tcno,tcno)==0){
			Yazdir(liste);
			return;
		}
		liste = liste->Sonraki;
	}
	printf("\nAranan uye kayitlarda yok!!!\n");	
}

void YeniUyeEkle(){
	printf("============ Uye Ekle ============\nTarih > gg-aa-yyyy\nMedeni Hal > Evli(1),Bekar(0)\n\n");
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

	printf("Dogum Tarih\t: ");
	char dogumTarih[12];
	scanf("%s",dogumTarih);

	printf("Medeni Hal\t: ");
	int medeniHal;
	scanf("%d",&medeniHal);

	printf("Kat [0,1,2...]\t: ");
	int kat;
	scanf("%d",&kat);

	printf("Daire [5,11...]\t: ");
	int daire;
	scanf("%d",&daire);

	printf("Baslangic Tarih\t: ");
	char baslangicTarih[12];
	scanf("%s",baslangicTarih);
	UyeEkle(tcno,ad,soyad,mailAdres,telefon,dogumTarih,medeniHal,kat,daire,baslangicTarih);
}

void UyeEkle(char* tcno,char* ad,char* soyad,char* mailAdres,char * telefon,char* dogumTarih,int medeniHal,int kat,int daire,char *baslangicTarih){
	
	if(Uyeler == NULL){

		Uyeler = (Uye*)malloc(sizeof(Uye));
		strcpy(Uyeler->tcno,tcno);
		strcpy(Uyeler->ad,ad);
		strcpy(Uyeler->soyad,soyad);
		strcpy(Uyeler->mailAdres,mailAdres);
		strcpy(Uyeler->telefon,telefon);
		strcpy(Uyeler->dogumTarih,dogumTarih);
		strcpy(Uyeler->baslangicTarih,baslangicTarih);
		Uyeler->medeniHal = medeniHal;
		Uyeler->kat = kat;
		Uyeler->daire = daire;
		Uyeler->Onceki = NULL;
		Uyeler->Sonraki = NULL;		
		return;
	}
	Uye *iter = Uyeler;

	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;

	Uye *yeni = (Uye*)malloc(sizeof(Uye));
	strcpy(yeni->tcno,tcno);
	strcpy(yeni->ad,ad);
	strcpy(yeni->soyad,soyad);
	strcpy(yeni->mailAdres,mailAdres);
	strcpy(yeni->telefon,telefon);
	strcpy(yeni->dogumTarih,dogumTarih);
	strcpy(yeni->baslangicTarih,baslangicTarih);
	yeni->medeniHal = medeniHal;
	yeni->kat = kat;
	yeni->daire = daire;
	yeni->Onceki = iter;
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;
	return;		
}

void Listele(){
	Uye *liste = Uyeler;
	if(liste == NULL){
		printf("\nHic uye kaydi yok !!!\n");
		return;
	}
	printf("\n=============UYE LISTESI=============\n");
	while(liste != NULL){
		Yazdir(liste);
		liste = liste->Sonraki;
	}
	printf("\n");
} 
