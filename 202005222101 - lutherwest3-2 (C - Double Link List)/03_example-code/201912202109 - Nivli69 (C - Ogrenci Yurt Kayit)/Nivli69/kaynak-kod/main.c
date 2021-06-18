#include <stdio.h>
#include <stdlib.h>


struct o{
	int No;
	char *Ad;
	char *Soyad;
	char *Baslangic;
	char *Bitis;
	struct o *Sonraki;
};

typedef struct o Ogrenci;

struct od{
	int No;
	int ogr1,ogr2,ogr3,ogr4;
	struct od *Sonraki;
};

typedef struct od Oda;

//struct tanimlamalari
Ogrenci *AktifOgrenciler, *PasifOgrenciler; 
Oda *Odalar;

//fonksiyon prototipleri
void Menu();
void Odada_Kalan_Ogrenciler();
void Ogrencinin_Kaldigi_Oda();
void Gecmiste_Yurtta_Kalan_Ogrenciler();
void Halen_Yurtta_Kalan_Ogrenciler();
void Ogrenci_Hangi_Tarihler_Arasinda_Yurtta_Kaldi();

Oda *Ogrenci_Oda_Bul(Oda *root,int ogr_no);
void OgrenciEkle();
void AktifOgrenciEkle(int No, char *Ad, char *Soyad, char *Baslangic);
void OgrenciIlisigiKes();
void PasifOgrenciEkle(int No,char *Bitis);
void PasifOgrenciEkle2(int No, char *Ad, char *Soyad, char *Baslangic, char *Bitis);
void AktifOgrenciSil(int No);
void Oda_Ekle(int No);
void Oda_Guncelle(int no, int Ogr1, int Ogr2, int Ogr3, int Ogr4);
Oda *Oda_Bul(Oda *root,int no);
Ogrenci *Ogrenci_Bul(Ogrenci *root,int no);


void Dosya_Oku();
void Dosya_Yaz();

//main
int main(){
	AktifOgrenciler = NULL;
	PasifOgrenciler = NULL;
	Odalar = NULL;
	
	/*int i;
	for(i = 1; i <=100; i++){
		Oda_Ekle(i);
		//printf("%d\n",Oda_Bul(Odalar,i)->No);
	}*/
	Dosya_Oku();
	
	
	Menu();
}

//menu
void Menu(){
	Dosya_Yaz();
	printf("\n=================================================\n");
	printf("1) Odada Kalan Ogrenciler\n");
	printf("2) Ogrencinin Kaldigi Oda\n");
	printf("3) Halen Yurtta Kalan Ogrenciler\n");
	printf("4) Gecmiste Yurtta Kalan Ogrenciler\n");
	printf("5) Ogrenci Hangi Tarihler Arasinda Yurtta Kaldi\n");
	printf("6) Ogrenci Ekle\n");
	printf("7) Ogrenci Ilisigi Kes\n");
	printf("8) Cikis\n");
	printf("=================================================\n");
	
	printf("\n\nSeciniz : ");
	int sec;
	scanf("%d",&sec);
	
	switch(sec){
		case 1:
			Odada_Kalan_Ogrenciler();
			Menu();
			break;
		case 2:
			Ogrencinin_Kaldigi_Oda();
			Menu();
			break;
		case 3:
			Halen_Yurtta_Kalan_Ogrenciler();
			Menu();
			break;
		case 4:
			Gecmiste_Yurtta_Kalan_Ogrenciler();
			Menu();
			break;
		case 5:
			Ogrenci_Hangi_Tarihler_Arasinda_Yurtta_Kaldi();
			Menu();
			break;
		case 6:
			OgrenciEkle();
			Menu();
			break;
		case 7:
			OgrenciIlisigiKes();
			Menu();
			break;
		case 8:
			printf("\nProgramdan cikiliyor...\n");
			exit(1);
			break;
		default:
			printf("Gecersiz islem !!! \n\n");
			Menu();
			break;	
	}
	
}

void Dosya_Oku(){	
	if(!fopen("odalar.txt","r")){
		printf("\nOdalar dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya_oda;
	dosya_oda = fopen("odalar.txt","r");
	
		while(!feof(dosya_oda)){
			//perror("girdi");
			int no,ogr1,ogr2,ogr3,ogr4;
			fscanf(dosya_oda,"%d %d %d %d %d",&no,&ogr1,&ogr2,&ogr3,&ogr4);
			Oda_Ekle(no);
			Oda_Guncelle(no,ogr1,ogr2,ogr3,ogr4);
		}
		fclose(dosya_oda);
	}
	if(!fopen("aktifogrenciler.txt","r")){
		printf("\nAktif Ogrenciler dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya_aogrenciler;
	dosya_aogrenciler = fopen("aktifogrenciler.txt","r");
	
		while(!feof(dosya_aogrenciler)){
			//perror("girdi");
			int no;
			char *ad = (char*)malloc(sizeof(char)*100);
			char *soyad = (char*)malloc(sizeof(char)*100);
			char *baslangic = (char*)malloc(sizeof(char)*100);
			fscanf(dosya_aogrenciler,"%d %s %s %s",&no,ad,soyad,baslangic);
			AktifOgrenciEkle(no,ad,soyad,baslangic);
		}
		fclose(dosya_aogrenciler);
	}
	if(!fopen("pasifogrenciler.txt","r")){
		printf("\nAktif Ogrenciler dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya_pogrenciler;
	dosya_pogrenciler = fopen("pasifogrenciler.txt","r");
	
		while(!feof(dosya_pogrenciler)){
			//perror("girdi");
			int no;
			char *ad = (char*)malloc(sizeof(char)*100);
			char *soyad = (char*)malloc(sizeof(char)*100);
			char *baslangic = (char*)malloc(sizeof(char)*100);
			char *bitis = (char*)malloc(sizeof(char)*100);
			fscanf(dosya_pogrenciler,"%d %s %s %s %s",&no,ad,soyad,baslangic,bitis);
			PasifOgrenciEkle2(no,ad,soyad,baslangic,bitis);
		}
		fclose(dosya_pogrenciler);
	}
}

void Dosya_Yaz(){
	if(!fopen("odalar.txt","w")){
		printf("\nOdalar dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya_oda;
		dosya_oda = fopen("odalar.txt","w");
	
		Oda *iter = Odalar;
		while(iter != NULL){
			fprintf(dosya_oda,"%d %d %d %d %d\n",iter->No,iter->ogr1,iter->ogr2,iter->ogr3,iter->ogr4);		
			iter = iter->Sonraki;
		}
		fclose(dosya_oda);
	
	}
	if(!fopen("aktifogrenciler.txt","w")){
		printf("\nAktif Ogrenciler dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya_aogrenciler;
		dosya_aogrenciler = fopen("aktifogrenciler.txt","w");
	
		Ogrenci *iter = AktifOgrenciler;
		while(iter != NULL){
			fprintf(dosya_aogrenciler,"%d %s %s %s\n",iter->No,iter->Ad,iter->Soyad,iter->Baslangic);		
			iter = iter->Sonraki;
		}
		fclose(dosya_aogrenciler);
	
	}
	if(!fopen("pasifogrenciler.txt","w")){
		printf("\nPasif Ogrenciler dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya_pogrenciler;
		dosya_pogrenciler = fopen("pasifogrenciler.txt","w");
	
		Ogrenci *iter = PasifOgrenciler;
		while(iter != NULL){
			fprintf(dosya_pogrenciler,"%d %s %s %s %s\n",iter->No,iter->Ad,iter->Soyad,iter->Baslangic,iter->Bitis);		
			iter = iter->Sonraki;
		}
		fclose(dosya_pogrenciler);
	
	}
}


//odada kalan ogrencileri ve bos odalari listeleme
void Odada_Kalan_Ogrenciler(){
	printf("============ Odada Kalan Ogrenciler ============\n");
	Oda *liste = Odalar;
	
	while(liste != NULL){
		
		if(liste->ogr1 > 0 || liste->ogr2 > 0 || liste->ogr3 > 0 || liste->ogr4 > 0) {
			printf("\n======================\n");
			printf("Oda No\t\t: %d\nOgrenci 1 No\t: %d\nOgrenci 2 No\t: %d\nOgrenci 3 No\t: %d\nOgrenci 4 No\t: %d",liste->No,liste->ogr1,liste->ogr2,liste->ogr3,liste->ogr4);
		}
			/*	else
			printf("Oda No\t\t: %d\nODA BOS !!!",liste->No);*/
		liste = liste->Sonraki;
	}
	printf("\n\n");
	return;
}

void Ogrencinin_Kaldigi_Oda(){
	printf("============ Ogrencinin Kaldigi Oda ============\n");
	printf("Ogrenci No : ");
	int no;
	scanf("%d",&no);
	Oda *bulunan = Ogrenci_Oda_Bul(Odalar,no);
	if(bulunan != NULL){
		printf("\n%d nolu ogrenci %d ninci odada kaliyor.\n",bulunan->No);
		return;
	}
	printf("\nVeri bulunamadi !!!\n");
}

void Halen_Yurtta_Kalan_Ogrenciler(){
	printf("============ Yurtta Kalan Ogrenciler ============\n");
	Ogrenci *liste = AktifOgrenciler;
	
	while(liste != NULL){
	printf("\n============================\n");	
		printf("Ogrenci No\t: %d\nAd\t\t: %s\nSoyad\t\t: %s\nBaslangic\t: %s\n",liste->No,liste->Ad,liste->Soyad,liste->Baslangic);
		
		liste = liste->Sonraki;
	}
	return;
}

void Gecmiste_Yurtta_Kalan_Ogrenciler(){	
	printf("============ Gecmiste Yurtta Kalan Ogrenciler ============\n");
	Ogrenci *liste = PasifOgrenciler;
	while(liste != NULL){
		printf("\n============================\n");
		printf("Ogrenci No\t: %d\nAd\t\t: %s\nSoyad\t\t: %s\nBaslangic\t: %s\nBitis\t\t: %s\n",liste->No,liste->Ad,liste->Soyad,liste->Baslangic,liste->Bitis);

		liste = liste->Sonraki;
	}
	return;
}

void Ogrenci_Hangi_Tarihler_Arasinda_Yurtta_Kaldi(){
	printf("============ Ogrencinin Kaldigi Oda ============\n");
	printf("Ogrenci No : ");
	int no;
	scanf("%d",&no);
	Ogrenci *bulunan = Ogrenci_Bul(PasifOgrenciler,no);
	printf("\nAd\t: %s\nSoyad\t: %s\n\nOgrenci yurtta %s ile %s arasinda kalmistir.\n\n",bulunan->Ad,bulunan->Soyad,bulunan->Baslangic,bulunan->Bitis);
	return;
}

//yeni ogrenci ekleme ve ogrenci oda numarasi belirleme bilgilerinin alinmasi
void OgrenciEkle(){
	printf("============ Ogrenci Ekle ============\n");
	printf("No : ");
	int no;
	scanf("%d",&no);
	
	printf("Ad : ");
	char ad[30];
	scanf("%s",ad);
	
	printf("Soyad : ");
	char soyad[30];
	scanf("%s",soyad);
	
	char Baslangic[30];
	printf("Baslangic [12.12.2019] : ");
	scanf("%s",Baslangic);
	
	printf("Oda No : ");
	int Oda_No;
	scanf("%d",&Oda_No);
	
	
	AktifOgrenciEkle(no,ad,soyad,Baslangic);
	
	Oda *bulunan_oda = Oda_Bul(Odalar,Oda_No);
	
	if(!bulunan_oda->ogr1 > 0)
		Oda_Guncelle(Oda_No,no,0,0,0);
	else if(!bulunan_oda->ogr2 > 0)
		Oda_Guncelle(Oda_No,0,no,0,0);
	else if(!bulunan_oda->ogr3 > 0)
		Oda_Guncelle(Oda_No,0,0,no,0);
	else if(!bulunan_oda->ogr4 > 0)
		Oda_Guncelle(Oda_No,0,0,0,no);
		
	return;
}

//ogrenci ekleme ve oda numarasi belirleme
void AktifOgrenciEkle(int No, char *Ad, char *Soyad, char *Baslangic){
	
	if(AktifOgrenciler == NULL){
		AktifOgrenciler = (Ogrenci*)malloc(sizeof(Ogrenci));
		AktifOgrenciler->No = No;
		AktifOgrenciler->Ad = Ad;
		AktifOgrenciler->Soyad = Soyad;
		AktifOgrenciler->Baslangic = Baslangic;
		AktifOgrenciler->Bitis = NULL;
		AktifOgrenciler->Sonraki = NULL;
		return;
	}
	
	Ogrenci *iter = AktifOgrenciler;
	
	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;
	
	Ogrenci *yeni = (Ogrenci*)malloc(sizeof(Ogrenci));
	yeni->No = No;
	yeni->Ad = Ad;
	yeni->Soyad = Soyad;
	yeni->Baslangic = Baslangic;
	yeni->Bitis = NULL;
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;
	return;

}

//ogrenci kaydi silme (ilisigi kesme)
void OgrenciIlisigiKes(){
	printf("============ Ogrenci Ilisigi Kesme ============\n");
	printf("No : ");
	int no;
	scanf("%d",&no);
	
	char Bitis[30];
	printf("Bitis [12.12.2019] : ");
	scanf("%s",Bitis);
	
	PasifOgrenciEkle(no,Bitis);
}

//silinen ogrenci(ilisik kesilen) pasif olarak baska bir listeye aktariliyor
void PasifOgrenciEkle(int No, char *Bitis){
	
	Ogrenci *eklenecek = Ogrenci_Bul(AktifOgrenciler,No);
	
	
	if(PasifOgrenciler == NULL){
		PasifOgrenciler = (Ogrenci*)malloc(sizeof(Ogrenci));
		PasifOgrenciler->No = No;
		PasifOgrenciler->Ad = eklenecek->Ad;
		PasifOgrenciler->Soyad = eklenecek->Soyad;
		PasifOgrenciler->Baslangic = eklenecek->Baslangic;
		PasifOgrenciler->Bitis = Bitis;
		PasifOgrenciler->Sonraki = NULL;
		AktifOgrenciSil(No);
		return;
	}
	
	Ogrenci *iter = PasifOgrenciler;
	
	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;
	
	Ogrenci *yeni = (Ogrenci*)malloc(sizeof(Ogrenci));
	yeni->No = No;
	yeni->Ad = eklenecek->Ad;
	yeni->Soyad = eklenecek->Soyad;
	yeni->Baslangic = eklenecek->Baslangic;
	yeni->Bitis = Bitis;
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;
	AktifOgrenciSil(No);
	return;

}

void PasifOgrenciEkle2(int No, char *Ad, char *Soyad, char *Baslangic, char *Bitis){

	if(PasifOgrenciler == NULL){
		PasifOgrenciler = (Ogrenci*)malloc(sizeof(Ogrenci));
		PasifOgrenciler->No = No;
		PasifOgrenciler->Ad = Ad;
		PasifOgrenciler->Soyad = Soyad;
		PasifOgrenciler->Baslangic = Baslangic;
		PasifOgrenciler->Bitis = Bitis;
		PasifOgrenciler->Sonraki = NULL;
		return;
	}
	
	Ogrenci *iter = PasifOgrenciler;
	
	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;
	
	Ogrenci *yeni = (Ogrenci*)malloc(sizeof(Ogrenci));
	yeni->No = No;
	yeni->Ad = Ad;
	yeni->Soyad = Soyad;
	yeni->Baslangic = Baslangic;
	yeni->Bitis = Bitis;
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;
	return;

}

//ogrenci ilisigi kesme isleminde listeden kaydin kaldirimasi
void AktifOgrenciSil(int No){
	Ogrenci *iter = AktifOgrenciler;
	
	while(iter->Sonraki->No != No)
		iter = iter->Sonraki;
	Ogrenci *gecici = iter->Sonraki;
	iter->Sonraki = iter->Sonraki->Sonraki;
	free(gecici);

}

//Oda ekleme ve oda numarasi belirleme
void Oda_Ekle(int No){
	
	if(Odalar == NULL){
		Odalar = (Oda*)malloc(sizeof(Oda));
		Odalar->No = No;
		Odalar->ogr1 = 0;
		Odalar->ogr2 = 0;
		Odalar->ogr3 = 0;
		Odalar->ogr4 = 0;
		Odalar->Sonraki = NULL;
		return;
	}
	
	Oda *iter = Odalar;
	
	while(iter->Sonraki != NULL)
		iter = iter->Sonraki;
	
	Oda *yeni = (Oda*)malloc(sizeof(Oda));
	yeni->No = No;
	yeni->ogr1 = 0;
	yeni->ogr2 = 0;
	yeni->ogr3 = 0;
	yeni->ogr4 = 0;
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;
	return;

}

//bir ogrencinin odasi belirlenmesi
void Oda_Guncelle(int no, int Ogr1, int Ogr2, int Ogr3, int Ogr4){
	Oda *bulunan = Oda_Bul(Odalar,no);
	if(Ogr1 > 0)
		bulunan->ogr1 = Ogr1;
	if(Ogr2 > 0)
		bulunan->ogr2 = Ogr2;
	if(Ogr3 > 0)
		bulunan->ogr3 = Ogr3;
	if(Ogr4 > 0)
		bulunan->ogr4 = Ogr4;
	return;
}

//aktif veya pasif ogrenciler icerisinde ogrenci numarasina gore ogrenci bulma
Ogrenci *Ogrenci_Bul(Ogrenci *root,int no){
	if(root == NULL)
		return NULL;
	Ogrenci *iter = root;
	while(iter != NULL){
		
		if(iter->No == no)
			return iter;
		iter =	iter->Sonraki;
	}
	return NULL;
}

//odalar icerisinde oda numarasina gore arama
Oda *Oda_Bul(Oda *root,int no){
	if(root == NULL)
		return NULL;
	Oda *iter = root;
	while(iter != NULL){
		
		if(iter->No == no)
			return iter;
		iter =	iter->Sonraki;
	}
	return NULL;
}

Oda *Ogrenci_Oda_Bul(Oda *root,int ogr_no){
	if(root == NULL)
		return NULL;
	Oda *iter = root;
	while(iter != NULL){
		
		if(iter->ogr1 == ogr_no || iter->ogr2 == ogr_no || iter->ogr3 == ogr_no || iter->ogr4 == ogr_no)
			return iter;
		iter =	iter->Sonraki;
	}
	return NULL;
}



