#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct ogr
{
	char tcno[12];
	char ad[20];
	char soyad[20];
	char dogum[30];
	char cinsiyet[6];
	char mail[30];
	char telefon[30];
	int bolumNo;
};
typedef struct ogr Ogrenci;

Ogrenci ogrenciler[60];

char dersler[3][200];
char bolumler[3][200];


struct not
{
	char ogrenciTcno[12];
	int dersNo;

	int vize;
	int final;
	int butunleme;

	float ortalama;
};
typedef struct not Not;

Not Notlar[180];


void Menu();
void DersKayit();
int ListeleDers();
int DersKontrol(int dersNo);

void BolumKayit();
int ListeleBolum();
int BolumKontrol(int bolumNo);

void OgrenciYazdir(int ogrenciNo);
void OgrenciKayit();
void OgrenciKayitBulma(char tcno[12]);
int OgrenciKayitGetir(char tcno[12]);
void OgrenciKayitDuzenleme(char tcno[12]);
void OgrenciKayitSilme(char _tcno[12]);

void GecmeNotuBelirleme();
void SinavYuzdesiBelirleme();
void OgrenciNotGirisi(char tcno[12]);

int NotKontrol(char tcno[12], int dersNo);
void ListelemeNot();
void ListelemeBolumDers();
void BolumDersOrtalama();

void BolumEnYuksekNot();
void BolumEnDusukNot();

float OgrenciGenelOrtalama(char tcno[12]);


//Hizmete dahil degildir
void GecmeKriteriBelirleme();


int gecmeNotuOrtalama = 40;

int gecmeNotuVize = 50;
int gecmeNotuFinal = 50;
int gecmeNotuButunleme = 50;

int yuzdeVize = 40;
int yuzdeFinal = 60;


int main(){
	//test verileri (silinebilir/önemsiz)
	/*strcpy(bolumler[0],"bolum1");
	strcpy(dersler[0],"ders1");
	strcpy(dersler[1],"ders2");
	strcpy(dersler[2],"ders3");

	strcpy(ogrenciler[0].tcno,"1");
	strcpy(ogrenciler[0].ad,"ad");
	strcpy(ogrenciler[0].soyad,"soyad");
	strcpy(ogrenciler[0].dogum,"dogum");
	strcpy(ogrenciler[0].cinsiyet,"cins");
	strcpy(ogrenciler[0].mail,"mail");
	strcpy(ogrenciler[0].telefon,"telefon");
	ogrenciler[0].bolumNo = 0;

	strcpy(ogrenciler[1].tcno,"2");
	strcpy(ogrenciler[1].ad,"ad");
	strcpy(ogrenciler[1].soyad,"soyad");
	strcpy(ogrenciler[1].dogum,"dogum");
	strcpy(ogrenciler[1].cinsiyet,"cins");
	strcpy(ogrenciler[1].mail,"mail");
	strcpy(ogrenciler[1].telefon,"telefon");
	ogrenciler[1].bolumNo = 0;*/

	Menu();
}

void Menu(){
	printf("------------------------------------\n");
	printf("1)  Ogrenci kayit\n");
	printf("2)  Ogrenci kayit bulma\n");
	printf("3)  Ogrenci kayit duzenleme\n"); 
	printf("4)  Ogrenci kayit silme\n");
	printf("5)  Ders kayit\n");
	printf("6)  Bolum kayit\n");
	printf("7)  Sinav yuzdesi belirleme\n");
	printf("8)  Gecme notu belirleme\n");
	printf("9)  Gecme kriteri belirleme -\n");
	printf("10) Ogrenci not girisi\n");
	printf("11) Listeleme bolum/ders bazinda\n");
	printf("12) Listeleme not\n");
	printf("13) Bolum ders ortalamasi\n");
	printf("14) Bolum en yuksek not\n");
	printf("15) Bolum en dusuk not\n"); 
	printf("0)  Cikis\n");
	printf("------------------------------------\n");
	printf("Secim : ");
	int secim;
	scanf("%d",&secim);
	switch(secim){
		case 0:
			printf("Programdan cikiliyor...\n");
			exit(0);
			break;
		case 1:
			OgrenciKayit();
			break;
		case 2:
			printf("TcNo : ");
			char tcno[12];
			scanf("%s",tcno);
			OgrenciKayitBulma(tcno);
			break;
		case 3:
			printf("TcNo : ");
			char dtcno[12];
			scanf("%s",dtcno);
			OgrenciKayitDuzenleme(dtcno);
			break;
		case 4:
			printf("TcNo : ");
			char stcno[12];
			scanf("%s",stcno);
			OgrenciKayitSilme(stcno);
			break;
		case 5:
			DersKayit();
			break;
		case 6:
			BolumKayit();
			break;
		case 7:
			SinavYuzdesiBelirleme();
			break;
		case 8:
			GecmeNotuBelirleme();
			break;
		case 9:
			GecmeKriteriBelirleme();
			break;
		case 10:
			printf("TcNo : ");
			char ntcno[12];
			scanf("%s",ntcno);
			OgrenciNotGirisi(ntcno);
			break;
		case 11:
			ListelemeBolumDers();
			break;
		case 12:
			ListelemeNot();
			break;
		case 13:
			BolumDersOrtalama();
			break;
		case 14:
			BolumEnYuksekNot();
			break;
		case 15:
			BolumEnDusukNot();
			break;
		default:
			printf("Hatali secim yaptiniz, tekrar seciniz!\n");
			break;
	}
	Menu();
}

void BolumKayit(){
	if(strcmp(bolumler[2],"") != 0)
	{
		printf("Daha fazla bolum eklenemez!!!\n");
		return;
	}
	printf("Bolum Adi : ");
	char ad[60];
	scanf("%s",ad);

	int i = 0;
	while(i<3){
		if(strcmp(bolumler[i],"") == 0){
			strcpy(bolumler[i],ad);
			break;
		}
		i++;
	}
}

int ListeleBolum(){
	if(strcmp(bolumler[0],"") == 0)
		return -1;
	printf("--------------BOLUMLER--------------\n");
	int i;
	for(i=0; i<3; i++){
		if(strcmp(bolumler[i],"") != 0)
			printf("No : %d\tBolum Adi : %s\n",i,bolumler[i]);
	}
	return 1;
}

int BolumKontrol(int bolumNo){
	if(bolumNo < 0 || bolumNo > 2)
		return -1;
	if(strcmp(bolumler[bolumNo],"") == 0)
		return -1;
	return 1;
}

void DersKayit(){
	if(strcmp(dersler[2],"") != 0)
	{
		printf("Daha fazla ders eklenemez!!!\n");
		return;
	}

	printf("Ders Adi : ");
	char ad[60];
	scanf("%s",ad);


	int i = 0;
	while(i<3){
		if(strcmp(dersler[i],"") == 0){
			strcpy(dersler[i],ad);
			break;
		}
		i++;
	}
}

int ListeleDers(){
	if(strcmp(dersler[0],"") == 0)
		return -1;
	printf("--------------DESLER---------------\n");
	int i;
	for(i=0; i<3; i++){
		if(strcmp(dersler[i],"") != 0)
			printf("No : %d\tDers Adi : %s\n",i,dersler[i]);
	}
	return 1;
}

int DersKontrol(int dersNo){
	if(dersNo < 0 || dersNo > 2)
		return -1;
	if(strcmp(dersler[dersNo],"") == 0)
		return -11;
	return 1;
}

void OgrenciKayit(){
	if(ListeleBolum() == -1){
		printf("Herhangi bir bolum kaydi bulunamadi !!!\n");
		return;
	}

 	printf("Bolum No : ");
 	int bolumNo;
	scanf("%d",&bolumNo);

	if(BolumKontrol(bolumNo)){
		while(BolumKontrol(bolumNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Bolum No : ");
			scanf("%d",&bolumNo);
		}
	}
 	
	printf("TcNo : ");
	char tcno[12];
	scanf("%s",tcno);

	printf("Ad : ");
	char ad[20];
	scanf("%s",ad);

	printf("Soyad : ");
	char soyad[20];
	scanf("%s",soyad);

	printf("Dogum Tarihi : ");
	char dogum[30];
	scanf("%s",dogum);

	printf("Cinsiyet : ");
	char cinsiyet[6];
	scanf("%s",cinsiyet);

	printf("Mail : ");
	char mail[30];
	scanf("%s",mail);

	printf("Telefon : ");
	char telefon[30];
	scanf("%s",telefon);

	int i;
	for(i=0; i<60; i++){
		if(strcmp(ogrenciler[i].tcno,"") == 0){
			strcpy(ogrenciler[i].tcno,tcno);
			strcpy(ogrenciler[i].ad,ad);
			strcpy(ogrenciler[i].soyad,soyad);
			strcpy(ogrenciler[i].dogum,dogum);
			strcpy(ogrenciler[i].cinsiyet,cinsiyet);
			strcpy(ogrenciler[i].mail,mail);
			strcpy(ogrenciler[i].telefon,telefon);
			ogrenciler[i].bolumNo = bolumNo;
			printf("Ogrenci eklendi.\n");
			//OgrenciYazdir(i);
			return;
		}
	}
	printf("Maksimum ogrenci kaydina ulasildiginden ogrenci eklenemedi!!!\n");
	return;
}

void OgrenciYazdir(int ogrenciNo){
	if(strcmp(ogrenciler[ogrenciNo].tcno,"") == 0){
		printf("\n%d Ogrenci No ya ait bilgiler bulunmamaktadir!!!\n",ogrenciNo);
		return;
	}

	printf("--------------OGRENCI--------------\n");
	printf("Bolum\t: %s\n",bolumler[ogrenciler[ogrenciNo].bolumNo]);
	printf("TcNo\t: %s\n",ogrenciler[ogrenciNo].tcno);
	printf("Ad\t: %s\n",ogrenciler[ogrenciNo].ad);
	printf("Soyad\t: %s\n",ogrenciler[ogrenciNo].soyad);
	printf("Dogum\t: %s\n",ogrenciler[ogrenciNo].dogum);
	printf("Cinsiyet: %s\n",ogrenciler[ogrenciNo].cinsiyet);
	printf("Mail\t: %s\n",ogrenciler[ogrenciNo].mail);
	printf("Telefon : %s\n",ogrenciler[ogrenciNo].telefon);
	printf("\n");
	return;
}

void OgrenciKayitBulma(char tcno[12]){
	int i;
	for(i=0; i<60; i++){
		if(strcmp(ogrenciler[i].tcno,tcno) == 0){
			OgrenciYazdir(i);
			return;
		}
	}
	printf("\nAranan ogrenci kaydi yok!!!\n");
	return;
}

int OgrenciKayitGetir(char tcno[12]){
	int i;
	for(i=0; i<60; i++){
		if(strcmp(ogrenciler[i].tcno,tcno) == 0){
			return i;
		}
	}
	return -1;
}

void OgrenciKayitDuzenleme(char _tcno[12]){
	int ogrenciNo = OgrenciKayitGetir(_tcno);
	if(ogrenciNo == -1){
		printf("Belirtilen ogrenci kaydi yok!!!\n");
		return;
	}
	ListeleBolum();
 	printf("Bolum No : ");
 	int bolumNo;
	scanf("%d",&bolumNo);

	if(BolumKontrol(bolumNo)){
		while(BolumKontrol(bolumNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Bolum No : ");
			scanf("%d",&bolumNo);
		}
	}
 	
	printf("TcNo : ");
	char tcno[12];
	scanf("%s",tcno);

	printf("Ad : ");
	char ad[20];
	scanf("%s",ad);

	printf("Soyad : ");
	char soyad[20];
	scanf("%s",soyad);

	printf("Dogum Tarihi : ");
	char dogum[30];
	scanf("%s",dogum);

	printf("Cinsiyet : ");
	char cinsiyet[6];
	scanf("%s",cinsiyet);

	printf("Mail : ");
	char mail[30];
	scanf("%s",mail);

	printf("Telefon : ");
	char telefon[30];
	scanf("%s",telefon);
	
	strcpy(ogrenciler[ogrenciNo].tcno,tcno);
	strcpy(ogrenciler[ogrenciNo].ad,ad);
	strcpy(ogrenciler[ogrenciNo].soyad,soyad);
	strcpy(ogrenciler[ogrenciNo].dogum,dogum);
	strcpy(ogrenciler[ogrenciNo].cinsiyet,cinsiyet);
	strcpy(ogrenciler[ogrenciNo].mail,mail);
	strcpy(ogrenciler[ogrenciNo].telefon,telefon);
	ogrenciler[ogrenciNo].bolumNo = bolumNo;
	printf("\nOgrenci kaydi duzenlendi.\n");
	OgrenciYazdir(ogrenciNo);
	return;
}

void OgrenciKayitSilme(char tcno[12]){
	int ogrenciNo = OgrenciKayitGetir(tcno);
	if(ogrenciNo == -1){
		printf("Belirtilen ogrenci kaydi yok!!!\n");
		return;
	}
	
	ogrenciler[ogrenciNo].tcno[0] = '\0';
	ogrenciler[ogrenciNo].ad[0] = '\0';
	ogrenciler[ogrenciNo].soyad[0] = '\0';
	ogrenciler[ogrenciNo].dogum[0] = '\0';
	ogrenciler[ogrenciNo].cinsiyet[0] = '\0';
	ogrenciler[ogrenciNo].mail[0] = '\0';
	ogrenciler[ogrenciNo].telefon[0] = '\0';
	ogrenciler[ogrenciNo].bolumNo = -1;
	printf("\nOgrenci kaydi silindi.\n");
	
}

void GecmeNotuBelirleme(){
	printf("Vize : ");
	scanf("%d",&gecmeNotuVize);

	printf("Final : ");
	scanf("%d",&gecmeNotuFinal);

	printf("Butunleme : ");
	scanf("%d",&gecmeNotuButunleme);

	printf("Ortalama : ");
	scanf("%d",&gecmeNotuOrtalama);
	return;
}

void SinavYuzdesiBelirleme(){
	printf("Vize : ");
	scanf("%d",&yuzdeVize);

	printf("Final : ");
	scanf("%d",&yuzdeFinal);
}

void GecmeKriteriBelirleme(){
	printf("Hizmete dahil degildir\n");
	return;
}

void OgrenciNotGirisi(char tcno[12]){
	int ogrenciNo = OgrenciKayitGetir(tcno);
	OgrenciYazdir(ogrenciNo);

	if(ListeleDers() == -1){
		printf("Ders kayi olmadigindan not belirlenemez!!!\n");
		return;
	}
	if(ogrenciNo == -1){
		printf("Ogrenci kaydi yok!!!\n");
		return;
	}


	printf("Ders No : ");
 	int dersNo;
	scanf("%d",&dersNo);

	if(DersKontrol(dersNo)){
		while(DersKontrol(dersNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Ders No : ");
			scanf("%d",&dersNo);
		}
	}

	if(NotKontrol(tcno,dersNo) == 1){
		printf("Bu derse zaten not girisi yapildi!\n");
		return;
	}
	float notVize = 0;
	float notFinal = 0;
	float notButunleme = -1;

	printf("Vize Notu : ");
	scanf("%f",&notVize);

	printf("Final Notu : ");
	scanf("%f",&notFinal);

	if(notVize < gecmeNotuVize)
		printf("Ogrenci vize sinavindan kaldi\n");
	
	if(notFinal < gecmeNotuFinal)
		printf("Ogrenci final sinavindan kaldi\n"); 

	if(notVize < gecmeNotuVize || notFinal < gecmeNotuFinal){
		printf("Ogrenci butunleme sinavina girdi mi [E = 1/ H = 0] : ");
		int butGirme;
		scanf("%d",&butGirme);
		if(butGirme == 1){
			printf("Butunleme Notu : ");
			scanf("%f",&notButunleme);
		}
		else{
			notButunleme = -1;
		}
	}

	int i;
	for(i=0; i<180; i++){
		if(strcmp(Notlar[i].ogrenciTcno,"") == 0){
			strcpy(Notlar[i].ogrenciTcno,tcno);

			Notlar[i].dersNo = dersNo;
			Notlar[i].vize = notVize;
			Notlar[i].final = notFinal;
			Notlar[i].butunleme = notButunleme;

			if(notButunleme > -1){
				Notlar[i].ortalama = notButunleme;
			}
			else{
				float ort = ((notVize/100)*yuzdeVize) + ((notFinal/100)*yuzdeFinal);
				Notlar[i].ortalama = ort;
			}
			printf("Ortalama : %.2f\n",Notlar[i].ortalama );
			printf("Not giris kaydi eklendi.\n");
			return;
		}
	}
	printf("Maksimum kayit sayisina ulasildigindan kayit yapilmadi!!!\n");
	return;
}

void ListelemeNot(){
	int i = 0;
	while(strcmp(Notlar[i].ogrenciTcno,"") != 0){
		int dersNo = Notlar[i].dersNo;
		int ogrenciNo = OgrenciKayitGetir(Notlar[i].ogrenciTcno);
		printf("Ders : %s\tTcNo : %s\tAd : %s\tSoyad : %s\tVize : %d\tFinal : %d\t",
			dersler[dersNo],Notlar[i].ogrenciTcno,ogrenciler[ogrenciNo].ad,ogrenciler[ogrenciNo].soyad,Notlar[i].vize,Notlar[i].final);
		if(Notlar[i].butunleme > -1)
			printf("Butunleme : %d\t",Notlar[i].butunleme);
		printf("Ortalama : %.2f\n",Notlar[i].ortalama );
		i++;
	}
}

void ListelemeBolumDers(){
	if(ListeleBolum() == -1){
		printf("Herhangi bir bolum kaydi bulunamadi !!!\n");
		return;
	}

 	printf("Bolum No : ");
 	int bolumNo;
	scanf("%d",&bolumNo);

	if(BolumKontrol(bolumNo)){
		while(BolumKontrol(bolumNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Bolum No : ");
			scanf("%d",&bolumNo);
		}
	}

	if(ListeleDers() == -1){
		printf("Hic ders yok!!!\n");
		return;
	}

	printf("Ders No : ");
 	int dersNo;
	scanf("%d",&dersNo);

	if(DersKontrol(dersNo)){
		while(DersKontrol(dersNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Ders No : ");
			scanf("%d",&dersNo);
		}
	}

	int i = 0;
	while(strcmp(Notlar[i].ogrenciTcno,"") != 0){
		int ogrenciNo = OgrenciKayitGetir(Notlar[i].ogrenciTcno);
		if(dersNo ==  Notlar[i].dersNo && bolumNo == ogrenciler[ogrenciNo].bolumNo){
			printf("Bolum : %s\tDers : %s\tTcNo : %s\tAd : %s\tSoyad : %s\t",
				bolumler[ogrenciler[ogrenciNo].bolumNo],dersler[dersNo],Notlar[i].ogrenciTcno,ogrenciler[ogrenciNo].ad,ogrenciler[ogrenciNo].soyad);
			if(Notlar[i].ortalama >= gecmeNotuOrtalama)
				printf("Durum : gecti\n");
			else
				printf("Durum : kaldi\n");
		}
		i++;
	}
}

void BolumDersOrtalama(){

	if(ListeleBolum() == -1){
		printf("Herhangi bir bolum kaydi bulunamadi !!!\n");
		return;
	}

 	printf("Bolum No : ");
 	int bolumNo;
	scanf("%d",&bolumNo);

	if(BolumKontrol(bolumNo)){
		while(BolumKontrol(bolumNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Bolum No : ");
			scanf("%d",&bolumNo);
		}
	}

	if(ListeleDers() == -1){
		printf("Hic ders yok!!!\n");
		return;
	}

	printf("Ders No : ");
 	int dersNo;
	scanf("%d",&dersNo);

	if(DersKontrol(dersNo)){
		while(DersKontrol(dersNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Ders No : ");
			scanf("%d",&dersNo);
		}
	}

	float ortalama = 0;
	int adet = 0;

	int i = 0;

	while(i<180){
		if(strcmp(Notlar[i].ogrenciTcno,"") != 0){
			int ogrenciNo = OgrenciKayitGetir(Notlar[i].ogrenciTcno);
			if(ogrenciler[ogrenciNo].bolumNo == bolumNo && Notlar[i].dersNo == dersNo){
				ortalama += Notlar[i].ortalama;
				adet++;
			}
		}
		i++;
	}
	ortalama /= adet;
	printf("Bolum : %s",bolumler[bolumNo]); 
	printf("Ders : %s\n",dersler[dersNo]);
	printf("Ortalama : %.2f\n\n",ortalama);
	return;
}

void BolumEnYuksekNot(){

	if(ListeleBolum() == -1){
		printf("Herhangi bir bolum kaydi bulunamadi !!!\n");
		return;
	}

 	printf("Bolum No : ");
 	int bolumNo;
	scanf("%d",&bolumNo);

	if(BolumKontrol(bolumNo)){
		while(BolumKontrol(bolumNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Bolum No : ");
			scanf("%d",&bolumNo);
		}
	}

	int ogrenciNo = 0;

	int i = 0;
	while(i<180){
		if(strcmp(Notlar[i].ogrenciTcno,"") != 0){
			int ogrNo = OgrenciKayitGetir(Notlar[i].ogrenciTcno);
			if(ogrenciler[ogrNo].bolumNo == bolumNo){
				if(OgrenciGenelOrtalama(Notlar[i].ogrenciTcno) > OgrenciGenelOrtalama(ogrenciler[ogrenciNo].tcno) ){
					ogrenciNo = ogrNo;
				}
			}
		}
		i++;
	}
	printf("\nBolumdeki en yuksek not\n");
	printf("Bolum\t: %s\n",bolumler[ogrenciler[ogrenciNo].bolumNo]);
	printf("TcNo\t: %s\n",ogrenciler[ogrenciNo].tcno); 
	printf("Ad\t: %s\n",ogrenciler[ogrenciNo].ad);
	printf("Soyad\t: %s\n",ogrenciler[ogrenciNo].soyad);
	printf("Not\t: %.2f\n\n",OgrenciGenelOrtalama(ogrenciler[ogrenciNo].tcno));
}

void BolumEnDusukNot(){
	if(ListeleBolum() == -1){
		printf("Herhangi bir bolum kaydi bulunamadi !!!\n");
		return;
	}

 	printf("Bolum No : ");
 	int bolumNo;
	scanf("%d",&bolumNo);

	if(BolumKontrol(bolumNo)){
		while(BolumKontrol(bolumNo) == -1){
			printf("Hatali secim yaptiniz, tekrar seciniz\n");
			printf("Bolum No : ");
			scanf("%d",&bolumNo);
		}
	}

	int ogrenciNo = 0;

	int i = 0;
	while(i<180){
		if(strcmp(Notlar[i].ogrenciTcno,"") != 0){
			int ogrNo = OgrenciKayitGetir(Notlar[i].ogrenciTcno);
			if(ogrenciler[ogrNo].bolumNo == bolumNo){
				if(OgrenciGenelOrtalama(Notlar[i].ogrenciTcno) < OgrenciGenelOrtalama(ogrenciler[ogrenciNo].tcno) ){
					ogrenciNo = ogrNo;
				}
			}
		}
		i++;
	}
	printf("\nBolumdeki en dusuk not\n");
	printf("Bolum\t: %s\n",bolumler[ogrenciler[ogrenciNo].bolumNo]);
	printf("TcNo\t: %s\n",ogrenciler[ogrenciNo].tcno); 
	printf("Ad\t: %s\n",ogrenciler[ogrenciNo].ad);
	printf("Soyad\t: %s\n",ogrenciler[ogrenciNo].soyad);
	printf("Not\t: %.2f\n\n",OgrenciGenelOrtalama(ogrenciler[ogrenciNo].tcno));
}

float OgrenciGenelOrtalama(char tcno[12]){
	float ortalama = 0;
	int adet = 0;

	int i = 0;
	while(i<180){
		if(strcmp(Notlar[i].ogrenciTcno,tcno) == 0){
			ortalama += Notlar[i].ortalama;
			adet++;
		}
		i++;
	}
	return ortalama/adet;
}

int NotKontrol(char tcno[12], int dersNo){
	int i=0;
	while (i<180){
		if(strcmp(Notlar[i].ogrenciTcno,tcno) == 0  && Notlar[i].dersNo == dersNo){
			return 1;
		}
		i++;
	}
	return -1;
}