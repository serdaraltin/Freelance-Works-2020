#include "ImeiNu.h"
#include "KimlikNu.h"
#include "Kisi.h"
#include "Telefon.h"
#include "Yas.h"
#include "RastgeleKisi.h"

#define KISLER_DOSYA "Kisiler.txt"

void Menu();
void RastgeleKisiUret(int);
void KontrolEt();



int main(){
	srand(time(NULL));

	Menu();
}

void Menu(){
	printf("1 - Rastgele Kisi Uret\n2 - Uretilmis Dosya Kontrol Et\n3 - Cikis\n");

	printf("Secim : ");
	int secim;
	scanf("%d",&secim);


	switch(secim){
		case 1:
			printf("Uretilecek Kisi Sayisi : ");
			int adet;
			scanf("%d",&adet);
			RastgeleKisiUret(adet);
			Menu();
			break;
		case 2:
			KontrolEt();
			Menu();
			break;
		case 3:
			printf("Cikis yapildi...\n");
			break;
		default:
			printf("Lutfen Gecerli Degerler Giriniz\n");
			Menu();
			break;
	}
	return;
}	

void RastgeleKisiUret(int adet){

	if(!fopen(KISLER_DOSYA,"a")){
		if(!fopen(KISLER_DOSYA,"w"));
		{
			printf("Kisiler dosyasi olusturulamiyor!!!\n");
			return;
		}
	}

	int i;
	FILE *dosya;
	dosya = fopen(KISLER_DOSYA,"a");
	for(i=0; i<adet; i++){
		char* kisi = (char*)malloc(sizeof(char)*100);
		RastgeleKisi(kisi);
		fprintf(dosya,"%s\n",kisi);
		
		free(kisi);
	}
	fclose(dosya);
	printf("Kayit Eklendi...\n");
	return;
}

void KontrolEt(){
	if(!fopen(KISLER_DOSYA,"r")){
		printf("Dosya acilamadi!!!\n");
		return;
	}

	int GecerliImei=0,GecersizImei=0,GecerliTcNo=0,GecersizTcNo=0;
	FILE *dosya;
	dosya = fopen(KISLER_DOSYA,"r");

	while(!feof(dosya)){
		char* tcno = (char*)malloc(sizeof(char)*11);
		char* telefon =(char*)malloc(sizeof(char)*12);
		int yas = YasUret();
		char* imei =(char*)malloc(sizeof(char)*15);
		char* isim = (char*)malloc(sizeof(char)*15);
		char* soyisim = (char*)malloc(sizeof(char)*15);

		fscanf(dosya,"%s %s %s %d %s (%s)",tcno,isim,soyisim,&yas,telefon,imei);
		imei[strlen(imei)-1] = '\0';
		
		if((int)(tcno[0]-48) > 0){
			if(TcNoKontrol(tcno) == 1)
				GecerliTcNo++;
			else
				GecersizTcNo++;
		}

		if((int)(imei[0]-48) > 0){
			if(ImeiKontrol(imei) == 1)
				GecerliImei++;
			else
				GecersizImei++;		
		}
		
		free(tcno);
		free(telefon);
		free(imei);
		free(isim);
		free(soyisim);
	}

	printf("\nT.C Kimlik Kontrol\n%d Gecerli\n%d Gecersiz\n",GecerliTcNo,GecersizTcNo);
	printf("\nIMEI Kontrol\n%d Gecerli\n%d Gecersiz\n",GecerliImei,GecersizImei);

	return;
}