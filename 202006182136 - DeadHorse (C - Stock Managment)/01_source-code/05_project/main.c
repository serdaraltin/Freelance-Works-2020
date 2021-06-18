#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musteri{
	int no;
	char ad[30];
	char soyad[30];
	char telefon[13];
	char adres[300];
	float bakiye;
	struct musteri *sonraki;
};
typedef struct musteri Musteri;

struct urun{
	char kod[20];
	char isim[50];
	float fiyat;
	int stok;
	struct urun *sonraki;
};
typedef struct urun Urun;

struct siparis{
	int siparisNo;
	int musteriNo;
	char urunKod[20];
	int urunAdet;
	float tutar;
	char tarih[20];
	struct siparis *sonraki;
};
typedef struct siparis Siparis;

Musteri *Musteriler = NULL;
Urun *Urunler = NULL;
Siparis *Siparisler = NULL;

void AnaMenu();
void MusteriMenu();
void UrunMenu();
void SiparisMenu();
void DosyaMenu();

void MusteriEkle();
Musteri *YeniMusteri(int no,char ad[30],char soyad[30],char telefon[13],char adres[300],float bakiye);
void MusterileriListele();
void YazdirMusteri(Musteri *musteri);
void MusteriAra();
void MusteriAraMetinsel(char metin[]);
Musteri *MusteriAraNo(int no);
void MusteriGuncelle();
void MusteriBakiyeEkle();

void UrunEkle();
Urun *YeniUrun(char kod[20],char isim[50],float fiyat,int stok);
void UrunAra();
Urun *UrunAraKod();
void UrunAraIsim();
void UrunGuncelle();
void UrunListele();

void SiparisOlustur();
Siparis *YeniSiparis(int siparisNo,int musteriNo,char urunKod[20],int urunAdet,float tutar,char tarih[20]);
Siparis *SiparisAra(int siparisNo);
void SiparisGoruntule();
void SiparisListele();

void DatDosyasiYaz(char islem[],char veri[]);
void FaturaYaz();

int main(){
	AnaMenu();
}

void AnaMenu(){
	printf("\n");
	printf("1) Musteri Islemleri\n");
	printf("2) Urun Islemleri\n");
	printf("3) Siparis Islemleri\n");
	printf("4) Dosya Islemleri\n");
	printf("0) Cikis\n");
	printf("\nSeciminiz : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 0:
			printf("Programdan cikiliyor\n");
			exit(0);
			break;
		case 1:
			MusteriMenu();
			break;
		case 2:
			UrunMenu();
			break;
		case 3:
			SiparisMenu();
			break;
		case 4:
			DosyaMenu();
			break;
		default:
			printf("Hatali secim yaptiniz! Tekrar seciniz.\n");
			break;
	}
	AnaMenu();
}

void MusteriMenu(){
	printf("\n");
	printf("1) Musteri Ekle\n");
	printf("2) Musteri Guncelle\n");
	printf("3) Musteri Ara\n");
	printf("4) Musteri Bakiye Ekle\n");
	printf("5) Musterileri Listele\n");
	printf("6) Ana Menuye Don\n");
	printf("\nSeciminiz : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 6:
			AnaMenu(); //+
			break;
		case 1:
			MusteriEkle(); //+
			break;
		case 2:
			MusteriGuncelle(); //+
			break;
		case 3:
			MusteriAra(); //+
			break;
		case 4:
			MusteriBakiyeEkle(); //+
			break;
		case 5:
			MusterileriListele(); //+
			break;
		default:
			printf("Hatali secim yaptiniz! Tekrar seciniz.\n");
			break;
	}
	printf("\n");
	MusteriMenu();
}

void UrunMenu(){
	printf("\n");
	printf("1) Urun Ekle\n");
	printf("2) Urun Guncelle\n");
	printf("3) Urun Ara\n");
	printf("4) Urun Listele\n");
	printf("5) Ana Menuye Don\n");
		printf("\nSeciminiz : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 5:
			AnaMenu(); //+
			break;
		case 1:
			UrunEkle(); //+
			break;
		case 2:
			UrunGuncelle(); //+
			break;
		case 3:
			UrunAra(); //+
			break;
		case 4:
			UrunListele(); //+
			break;
		default:
			printf("Hatali secim yaptiniz! Tekrar seciniz.\n");
			break;
	}
	UrunMenu();
}

void SiparisMenu(){
	printf("\n");
	printf("1) Siparis Olustur\n");
	printf("2) Siparis Goruntule\n");
	printf("3) Siparisleri Listele\n");
	printf("4) Ana Menuye Don\n");
	printf("\nSeciminiz : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 4:
			AnaMenu();
			break;
		case 1:
			SiparisOlustur();
			break;
		case 2:
			SiparisGoruntule();
			break;
		case 3:
			SiparisListele();
			break;
		default:
			printf("Hatali secim yaptiniz! Tekrar seciniz.\n");
			break;
	}
	SiparisMenu();
}

void DosyaMenu(){
	printf("\n");
	printf("1) Fatura Yazdir\n");
	printf("2) Ana Menuye Don\n");
	printf("\nSeciminiz : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 2:
			AnaMenu(); //+
			break;
		case 1:
			FaturaYaz(); //+
			break;
		default:
			printf("Hatali secim yaptiniz! Tekrar seciniz.\n");
			break;
	}
	DosyaMenu();
}

void MusteriEkle(){
	int no;
	char ad[30];
	char soyad[30];
	char telefon[13];
	char adres[300];
	float bakiye;

	printf("No : ");
	scanf("%d",&no);
	printf("Ad : ");
	scanf("%s",ad);
	printf("Soyad : ");
	scanf("%s",soyad);
	printf("Telefon : ");
	scanf("%s",telefon);
	printf("Adres [sehir] : ");
	scanf("%s",adres);
	printf("Bakiye : ");
	scanf("%f",&bakiye);

	if(Musteriler == NULL){
		Musteriler = YeniMusteri(no,ad,soyad,telefon,adres,bakiye);
		printf("\nMusteri Eklendi.\n");
		return;
	}
	Musteri *iter = Musteriler;

	while(iter->sonraki != NULL)
		iter = iter->sonraki;

	iter->sonraki = YeniMusteri(no,ad,soyad,telefon,adres,bakiye);

	printf("\nMusteri Eklendi.\n");

	return;
}

Musteri *YeniMusteri(int no,char ad[30],char soyad[30],char telefon[13],char adres[300],float bakiye){

	Musteri *yeniMusteri = (Musteri*)malloc(sizeof(Musteri));
	yeniMusteri->no = no;
	strcpy(yeniMusteri->ad,ad);
	strcpy(yeniMusteri->soyad,soyad);
	strcpy(yeniMusteri->telefon,telefon);
	strcpy(yeniMusteri->adres,adres);
	yeniMusteri->bakiye = bakiye;
	yeniMusteri->sonraki = NULL;

	char veri[500];
	sprintf(veri,"No\t\t: %d\nAd\t\t: %s\nSoyad\t: %s\nTelefon\t: %s\nAdres\t: %s\nBakiye\t: %.2f",
		no,ad,soyad,telefon,adres,bakiye);
	DatDosyasiYaz("Musteri Ekleme",veri);

	return yeniMusteri;
}

void MusterileriListele(){
	printf("-------- MUSTERI LISTESI --------- \n");
	Musteri *iter = Musteriler;

	while(iter != NULL){
		YazdirMusteri(iter);
		iter = iter->sonraki;
    }
    char veri[500];
	sprintf(veri,"Tum Musteriler");
	DatDosyasiYaz("Musteri Listeleme",veri);

}

void YazdirMusteri(Musteri *musteri){
	if(musteri == NULL){
		return;
	}
	printf("\n-----------------------------------\n");
	printf("No\t: %d\n",musteri->no);
	printf("Ad\t: %s\n",musteri->ad);
	printf("Soyad\t: %s\n",musteri->soyad);
	printf("Telefon\t: %s\n",musteri->telefon);
	printf("Adres\t: %s\n",musteri->adres);
	printf("Bakiye\t: %.2f TL\n",musteri->bakiye);
	printf("-----------------------------------\n");

    char veri[500];
	sprintf(veri,"Musteri No : %d",musteri->no);
	DatDosyasiYaz("Musteri Yazdirma",veri);

}

void MusteriAra(){
	printf("Arama [Ad Gore : 1 / No'ya Gore : 2] : ");
	int secim;
	scanf("%d",&secim);
	if(secim == 1){
		printf("Ad : ");
		char ad[30];
		scanf("%s",ad);
		MusteriAraMetinsel(ad);
	}
	else if(secim == 2){
		printf("No : ");
		int no;
		scanf("%d",&no);
		YazdirMusteri(MusteriAraNo(no));
	}
	else{
		printf("Hatali bir secinm yaptiniz! Tekrar giriniz.\n"); 
		MusteriAra();
	}
}

void MusteriAraMetinsel(char metin[]){
	Musteri *iter = Musteriler;
	int bulundu = 0;
	while(iter != NULL){
		if(strcmp(iter->ad,metin) >= 0){
			YazdirMusteri(iter);
			bulundu = 1;
		}
		iter = iter->sonraki;
	}
	if(bulundu == 0)
		printf("\nBulunamadi!\n");
}

Musteri *MusteriAraNo(int no){
	Musteri *iter = Musteriler;

	while(iter != NULL){
		if(iter->no == no)
			return iter;
		iter = iter->sonraki;
	}
	return NULL;
}

void MusteriGuncelle(){
	printf("Musteri No : ");
	int no;
	scanf("%d",&no);
	if(MusteriAraNo(no) == NULL)
		return;
	printf("Telefon : ");
	char telefon[13];
	scanf("%s",telefon);
	printf("Adres : ");
	char adres[300];
	scanf("%s",adres);

	Musteri *iter = Musteriler;
	while(iter != NULL){
		if(iter->no == no)
			break;
		iter = iter->sonraki;
	}
	sprintf(iter->telefon,"%s",telefon);
	sprintf(iter->adres,"%s",adres);
	printf("\nMusteri Guncellendi.\n");
	MusteriAraNo(no);
}

void MusteriBakiyeEkle(){
	printf("Musteri No : ");
	int no;
	scanf("%d",&no);
	if(MusteriAraNo(no) == NULL)
		return;
	printf("Eklenecek Miktar : ");
	float ekBakiye;
	scanf("%f",&ekBakiye);

	MusteriAraNo(no)->bakiye += ekBakiye;
	printf("Yeni Bakiye >> %.2f\n TL",MusteriAraNo(no)->bakiye);
}

void UrunEkle(){
	char kod[20];
	char isim[50];
	float fiyat;
	int stok;

	printf("Kod : ");
	scanf("%s",kod);
	printf("Isım : ");
	scanf("%s",isim);
	printf("Fiyat : ");
	scanf("%f",&fiyat);
	printf("Stok Adet : ");
	scanf("%d",&stok);

	if(Urunler == NULL){
		Urunler = YeniUrun(kod,isim,fiyat,stok);
		printf("\nUrun eklendi\n");
		return;
	}

	Urun *iter = Urunler;

	while(iter->sonraki != NULL)
		iter = iter->sonraki;

	iter->sonraki = YeniUrun(kod,isim,fiyat,stok);
	printf("\nUrun Eklendi.\n");
	return;
}

Urun *YeniUrun(char kod[20],char isim[50],float fiyat,int stok){
	Urun *yeniUrun = (Urun*)malloc(sizeof(Urun));
	yeniUrun->fiyat = fiyat;
	yeniUrun->stok = stok;
	strcpy(yeniUrun->kod,kod);
	strcpy(yeniUrun->isim,isim);
	yeniUrun->sonraki = NULL;

	char veri[500];
	sprintf(veri,"Kod\t\t: %s\nIsim\t: %s\nFiyat\t: %.2f\nStok\t: %d",
		kod,isim,fiyat,stok);
	DatDosyasiYaz("Urun Ekleme",veri);

	return yeniUrun;
}

void YazdirUrun(Urun *urun){
	if(urun == NULL){
		return;
	}
	printf("\n-----------------------------------\n");
	printf("Kod\t: %s\n",urun->kod);
	printf("Isim\t: %s\n",urun->isim);
	printf("Fiyat\t: %.2f\n",urun->fiyat);
	printf("Stok\t: %d\n",urun->stok);
	printf("-----------------------------------\n");
	char veri[500];
	sprintf(veri,"Urun Kod : %s",urun->kod);
	DatDosyasiYaz("Urun Yazdirma",veri);
}

void UrunAra(){
	printf("Arama [Isim Gore : 1 / Koda Gore : 2] : ");
	int secim;
	scanf("%d",&secim);
	if(secim == 1){
		printf("Isim : ");
		char isim[30];
		scanf("%s",isim);
		UrunAraIsim(isim);
	}
	else if(secim == 2){
		printf("Kod : ");
		char kod[30];
		scanf("%s",kod);
		YazdirUrun(UrunAraKod(kod));
	}
	else{
		printf("Hatali bir secinm yaptiniz! Tekrar giriniz.\n"); 
		UrunAra();
	}
}

Urun *UrunAraKod(char kod[]){
	Urun *iter = Urunler;

	while(iter != NULL){
		if(strcmp(iter->kod,kod) == 0)
			return iter;
		iter = iter->sonraki;
	}
	return NULL;
}

void UrunAraIsim(char isim[]){
	Urun *iter = Urunler;
	int bulundu = 0;
	while(iter != NULL){
		if(strcmp(iter->isim,isim) >= 0){
			YazdirUrun(iter);
			bulundu = 1;
		}
		iter = iter->sonraki;
	}
	if(bulundu == 0)
		printf("\nBulunamadi!\n");
}

void UrunGuncelle(){
	printf("Urun Kod : ");
	char kod[20];
	scanf("%s",kod);
	if(UrunAraKod(kod) == NULL)
		return;

	float fiyat;
	int stok;

	printf("Fiyat : ");
	scanf("%f",&fiyat);
	printf("Stok Adet : ");
	scanf("%d",&stok);

	Urun *iter = Urunler;
	while(iter != NULL){
		if(strcmp(iter->kod,kod) == 0)
			break;
		iter = iter->sonraki;
	}
	iter->fiyat = fiyat;
	iter->stok  = stok;
	printf("\nUrun Guncellendi.\n");
	UrunAraKod(kod);
}

void UrunListele(){
	printf("-------- URUN LISTESI --------- \n");
	Urun *iter = Urunler;

	while(iter != NULL){
		YazdirUrun(iter);
		iter = iter->sonraki;
    }
    char veri[500];
	sprintf(veri,"Tum Urunler");
	DatDosyasiYaz("Urun Listeleme",veri);
}

void YazdirSiparis(Siparis *siparis){
	if(siparis == NULL){
		return;
	}
	printf("\n-----------------------------------\n");
	printf("Siparis No : %d\n",siparis->siparisNo);
	printf("Musteri No : %d\n",siparis->musteriNo);
	printf("Urun Kod   : %s\n",siparis->urunKod);
	printf("Adet\t: %d\n",siparis->urunAdet);
	printf("Tutar\t: %.2f\n",siparis->tutar);
	printf("Tarih\t: %s\n",siparis->tarih);
	printf("-----------------------------------\n");
	char veri[500];
	sprintf(veri,"Siparis No : %d",siparis->siparisNo);
	DatDosyasiYaz("Siparis Yazdirma",veri);
}

void SiparisOlustur(){
	int siparisNo;
	int musteriNo;
	char urunKod[20];
	int urunAdet;
	float tutar;
	char tarih[20];

	printf("Siparis No: ");
	scanf("%d",&siparisNo);

	if(SiparisAra(siparisNo) != NULL){
		printf("Ayni no'ya sahip bir siparis zaten var!!!\n");
		SiparisOlustur();
		return;
	}

	printf("Musteri No: ");
	scanf("%d",&musteriNo);
	if(MusteriAraNo(musteriNo) == NULL){
		printf("Musteri Bulunamadi!");
		SiparisOlustur();
		return;
	}

	printf("Urun Kod: ");
	scanf("%s",urunKod);
	if(UrunAraKod(urunKod) == NULL){
		printf("Urun Bulunamadi!");
		SiparisOlustur();
		return;
	}

	printf("Urun Adet : ");
	scanf("%d",&urunAdet);
	if(UrunAraKod(urunKod)->stok < urunAdet){
		printf("Stokta yeterli urun yok!\n");
		SiparisOlustur();
		return;
	}
	tutar = UrunAraKod(urunKod)->fiyat * urunAdet;

	if(MusteriAraNo(musteriNo)->bakiye < tutar){
		printf("Bakiye Yetersiz!\n");
		return;
	}

	printf("Tarih [orn : 2020.06.18]: ");
	scanf("%s",tarih);



	if(Siparisler == NULL){
		Siparisler = YeniSiparis(siparisNo,musteriNo,urunKod,urunAdet,tutar,tarih);
		printf("\nSiparis eklendi\n");
		return;
	}

	Siparis *iter = Siparisler;

	while(iter->sonraki != NULL)
		iter = iter->sonraki;

	iter->sonraki = YeniSiparis(siparisNo,musteriNo,urunKod,urunAdet,tutar,tarih);
	printf("\nSiparis Eklendi.\n");
	return;
}
Siparis *YeniSiparis(int siparisNo,int musteriNo,char urunKod[20],int urunAdet,float tutar,char tarih[20]){
	Siparis *yeniSiparis = (Siparis*)malloc(sizeof(Siparis));
	yeniSiparis->siparisNo = siparisNo;
	yeniSiparis->musteriNo = musteriNo;
	yeniSiparis->urunAdet = urunAdet;
	yeniSiparis->tutar = tutar;
	strcpy(yeniSiparis->urunKod,urunKod);
	strcpy(yeniSiparis->tarih,tarih);
	yeniSiparis->sonraki = NULL;

	UrunAraKod(urunKod)->stok -= urunAdet;
	MusteriAraNo(musteriNo)->bakiye -= tutar;

	char veri[500];
	sprintf(veri,"No\t\t\t: %d\nMusteri No\t: %d\nUrun Kod\t: %s\nUrun Adet\t: %d\nTutar\t\t: %.2f\nTarih\t\t: %s",
		siparisNo,musteriNo,urunKod,urunAdet,tutar,tarih);
	DatDosyasiYaz("Siparis Ekleme",veri);

	return yeniSiparis;
}

Siparis *SiparisAra(int siparisNo){
	Siparis *iter = Siparisler;

	while(iter != NULL){
		if(iter->siparisNo = siparisNo)
			return iter;
		iter = iter->sonraki;
	}
	return NULL;
}

void SiparisGoruntule(){
	printf("Siparis No :");
	int siparisNo;
	scanf("%d",&siparisNo);
	YazdirSiparis(SiparisAra(siparisNo));
}

void SiparisListele(){
	printf("Musteri No :");
	int musteriNo;
	scanf("%d",&musteriNo);
	if(MusteriAraNo(musteriNo) == NULL){
		printf("Musteri Bulunamadi!\n");
		return;
	}
	YazdirMusteri(MusteriAraNo(musteriNo));

	printf("-------- %s %s / SIPARIS LISTESI ---- \n",MusteriAraNo(musteriNo)->ad,MusteriAraNo(musteriNo)->soyad);
	Siparis *iter = Siparisler;

	while(iter != NULL){
		if(iter->musteriNo == musteriNo)
			YazdirSiparis(iter);
		iter = iter->sonraki;
    }
    char veri[500];
	sprintf(veri,"Musteri No\t: %d\nMusteri Ad\t: %s\nMusteri Soyad : %s",
	musteriNo,MusteriAraNo(musteriNo)->ad,MusteriAraNo(musteriNo)->soyad);
	DatDosyasiYaz("Siparis Listeleme",veri);

}

void DatDosyasiYaz(char islem[],char veri[]){
	FILE *dosya;
	dosya = fopen("veriler.dat","a");
	fprintf(dosya,"\nIslem >> %s\n-----------------------------------\n",islem);
	fprintf(dosya,"%s\n-----------------------------------\n",veri);
	fclose(dosya);
}

void FaturaYaz(){
	printf("Siparis No :");
	int siparisNo;
	scanf("%d",&siparisNo);
	if(SiparisAra(siparisNo) == NULL){
		printf("Siparis Bulunamadi!\n");
		return;
	}
	YazdirSiparis(SiparisAra(siparisNo));
	Siparis *siparis = SiparisAra(siparisNo);
	Musteri *musteri = MusteriAraNo(siparis->musteriNo);
	Urun *urun = UrunAraKod(siparis->urunKod);

	char dosyaAd[70];
	sprintf(dosyaAd,"%s_%s.txt",musteri->ad,musteri->soyad);

	FILE *dosya;
	dosya = fopen(dosyaAd,"w+");
	fprintf(dosya, "Siparis No : %d \nMusteri No : %d \nAd\t\t: %s \nSoyad\t: %s \nTelefon\t: %s \nAdres\t: %s \nUrun Kod: %s \nUrun Ad\t: %s \nAdet\t: %d \nTutar\t: %.2f TL \nTarih\t: %s",
	 siparis->siparisNo,musteri->no,musteri->ad,musteri->soyad,musteri->telefon,musteri->adres,urun->kod,urun->isim,siparis->urunAdet,siparis->tutar,siparis->tarih);
	fclose(dosya);

	printf("Fatura Olusturuldu.\n");
}