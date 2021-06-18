#include <stdio.h>
#include <string.h>

//ogrenci bilgileri icin ogrenci adinda yapinin tanimlanmasi
typedef struct ogrenci{
	int no;
	int dogum;
	int sinif;
	char * isim;
	char * soyisim;
	char * cinsiyet;
	char * bolum;
	struct ogrenci *sonraki;
}liste,liste_mezun; //iki adet liste uretilmesi(normal ve mezun)

liste *yeni, *ilk = NULL, *gecici, *silGecici; //normal liste uzerinde islemler yapabilmek icin pointer(gosterici) tanimlanmasi
liste_mezun *m_yeni, *m_ilk = NULL, *m_gecici; //mezun liste uzerinde islemler yapabilmek icin pointer(gosterici) tanimlanmasi


//fonksiyon prototipleri
void menu();
void dosya_oku();
int dosya_isle(char[]);
int dateStrInt(char[]);
char dataIntStr(int);
void splitDate(int,int*,int*,int*);
void ekle(int,int,int,char*,char*,char*,char*);
void listele();
int ara_sinif(int);
int sil(int);
void arttir();
void listele_bolum(char[]);
void listele_sinif(int);


//baslangic fonksiyonu
int main()
{	
	menu();
}

//secimler icin menu tasarimi
void menu()
{
	printf("\n==========================\n");
	printf("1. Dosyadan Veri Al\n");
	printf("2. Sinif Arttir\n");
	printf("3. Listele > Normal\n");
	printf("4. Listele > Bolum\n");
	printf("5. Listele > Mezun\n");
	printf("6. Listele > Sinif\n");
	printf("0. Cikis");
	printf("\n==========================\n");
	printf("\nSecenek > ");
	
	int sec_no;
	scanf("%d",&sec_no);
	
	switch(sec_no)
	{
		case 0:
			exit(1);
		break;
		
		case 1:
			//Dosyadan veri al
			dosya_oku();
		break;
		
		case 2:
			//Sinif arttir
			arttir();
		break;
		
		case 3:
			//Normal olarak listele
			listele();
		break;
		
		case 4:
			//Bolume gore listele
			printf("\nBolum adini giriniz > ");
			char bolum[10];
			scanf("%s",bolum);
			listele_bolum(bolum);
		break;
		
		case 5:
			//Mezunlari listele
			listele_mezun();
		break;
		
		case 6:
			//Sinifa gore listele
			printf("\nSinif giriniz > ");
			int sinif = 1;
			scanf("%d",&sinif);
			listele_sinif(sinif);
		break;
		
		default:
			printf("\n\nGecerli bir deger girmediniz !!!\a");
			menu();
		break;
	}
}

void ekle(int no,int dogum,int sinif,char *isim,char *soyisim,char *cinsiyet,char *bolum)
{
	if(ilk == NULL)
	{
		ilk = (liste*)malloc(sizeof(liste));
		ilk->no = no;
		ilk->dogum = dogum;
		ilk->sinif = sinif;
		ilk->isim = isim;
		ilk->soyisim = soyisim;
		ilk->cinsiyet = cinsiyet;
		ilk->bolum = bolum;
		ilk->sonraki = NULL;
	
	}
	else
	{
		if((ilk->dogum) > (dogum))
		{
			yeni = (liste*)malloc(sizeof(liste));
			yeni->no = no;
			yeni->dogum = dogum;
			yeni->sinif = sinif;
			yeni->isim = isim;
			yeni->soyisim = soyisim;
			yeni->cinsiyet = cinsiyet;
			yeni->bolum = bolum;
			ilk->sonraki = yeni;
		}
		else
		{
			gecici = ilk;
			yeni = (liste*)malloc(sizeof(liste));
			yeni->no = no;
			yeni->dogum = dogum;
			yeni->sinif = sinif;
			yeni->isim = isim;
			yeni->soyisim = soyisim;
			yeni->cinsiyet = cinsiyet;
			yeni->bolum = bolum;
			while(gecici != NULL)
			{
				//gecici elemaninin sonraki degeri null ve son elemandan buyukse
				if(gecici->sonraki == NULL && (gecici->dogum) <= (dogum))
				{
					yeni->sonraki = NULL;
					gecici->sonraki = yeni;
					break;
				}
				//Araya ekleme
				if((gecici->sonraki->dogum) > (dogum))
				{
					yeni->sonraki = gecici->sonraki;
					gecici->sonraki = yeni;
					break;
				}
				gecici = gecici->sonraki;
			}
		}
	}
}

//mezun olanlarin mezun listesine eklenmesi
void ekle_mezun(int no,int dogum,int sinif,char *isim,char *soyisim,char *cinsiyet,char *bolum)
{
	sinif--;
	if(m_ilk == NULL)
	{
		m_ilk = (liste*)malloc(sizeof(liste));
		m_ilk->no = no;
		m_ilk->dogum = dogum;
		m_ilk->sinif = sinif;
		m_ilk->isim = isim;
		m_ilk->soyisim = soyisim;
		m_ilk->cinsiyet = cinsiyet;
		m_ilk->bolum = bolum;
		m_ilk->sonraki = NULL;
	
	}
	else
	{
		if((m_ilk->dogum) > (dogum))
		{
			m_yeni = (liste*)malloc(sizeof(liste));
			m_yeni->no = no;
			m_yeni->dogum = dogum;
			m_yeni->sinif = sinif;
			m_yeni->isim = isim;
			m_yeni->soyisim = soyisim;
			m_yeni->cinsiyet = cinsiyet;
			m_yeni->bolum = bolum;
			m_ilk->sonraki = m_yeni;
		}
		else
		{
			m_gecici = ilk;
			m_yeni = (liste*)malloc(sizeof(liste));
			m_yeni->no = no;
			m_yeni->dogum = dogum;
			m_yeni->sinif = sinif;
			m_yeni->isim = isim;
			m_yeni->soyisim = soyisim;
			m_yeni->cinsiyet = cinsiyet;
			m_yeni->bolum = bolum;
			while(m_gecici != NULL)
			{
				//gecici elemaninin sonraki degeri null ve son elemandan buyukse
				if(m_gecici->sonraki == NULL && (m_gecici->dogum) <= (dogum))
				{
					m_yeni->sonraki = NULL;
					m_gecici->sonraki = m_yeni;
					break;
				}
				//Araya ekleme
				if((m_gecici->sonraki->dogum) > (dogum))
				{
					m_yeni->sonraki = m_gecici->sonraki;
					m_gecici->sonraki = m_yeni;
					break;
				}
				m_gecici = m_gecici->sonraki;
			}
		}
	}
}

//normal listeleme yapilmasi
void listele()
{
	if(ilk == NULL)
		printf("\nVeri yok !!!\n");
	else
	{
		gecici = ilk;
		printf("\nno        \tisim\tsoyad\tdogum\t\tcins.\tbolum\tsinif\n");
		while(gecici != NULL)
		{
			printf("---------------------------------------------------------------------\n");
			int dp,mp,yp;
			splitDate(gecici->dogum,&dp,&mp,&yp);
			printf(
			"%d\t%s\t%s\t%d/%d/%d\t%s\t%s\t%d\n",gecici->no,gecici->isim,gecici->soyisim,dp,mp,yp,gecici->cinsiyet,gecici->bolum,gecici->sinif);
			
			gecici = gecici->sonraki;
		}
	}
	printf("---------------------------------------------------------------------\n");
	menu();
}

//verilen bolum adina gore listeleme yapilmasi
void listele_bolum(char bolum[])
{
	if(ilk == NULL)
		printf("\nVeri yok !!!\n");
	else
	{
		printf("\nBOLUM : %s\n",bolum);
		gecici = ilk;
		printf("\nno        \tisim\tsoyad\tdogum\t\tcins.\tbolum\tsinif\n");
		while(gecici != NULL)
		{
			if(strcmp(gecici->bolum,bolum) == 0)
			{
				printf("---------------------------------------------------------------------\n");
				int dp,mp,yp;
				splitDate(gecici->dogum,&dp,&mp,&yp);
				printf(
				"%d\t%s\t%s\t%d/%d/%d\t%s\t%s\t%d\n",gecici->no,gecici->isim,gecici->soyisim,dp,mp,yp,gecici->cinsiyet,gecici->bolum,gecici->sinif);
			}
			gecici = gecici->sonraki;
		}
	}
	printf("---------------------------------------------------------------------\n");
	menu();
}

//sinif degerine gore listeleme yapilmasi
void listele_sinif(int sinif)
{
	if(ilk == NULL)
		printf("\nVeri yok !!!\n");
	else
	{
		printf("\nSINIF : %d\n",sinif);
		gecici = ilk;
		printf("\nno        \tisim\tsoyad\tdogum\t\tcins.\tbolum\tsinif\n");
		while(gecici != NULL)
		{
			if(gecici->sinif == sinif)
			{
				printf("---------------------------------------------------------------------\n");
				int dp,mp,yp;
				splitDate(gecici->dogum,&dp,&mp,&yp);
				printf(
				"%d\t%s\t%s\t%d/%d/%d\t%s\t%s\t%d\n",gecici->no,gecici->isim,gecici->soyisim,dp,mp,yp,gecici->cinsiyet,gecici->bolum,gecici->sinif);
			}
			gecici = gecici->sonraki;
		}
	}
	printf("---------------------------------------------------------------------\n");
	menu();
}

//mezun olanlarin listelenmesi
void listele_mezun()
{
	if(m_ilk == NULL)
		printf("\nVeri yok !!!\n");
	else
	{
		m_gecici = m_ilk;
		printf("\nMEZUNLAR >>\n");
		printf("\nno        \tisim\tsoyad\tdogum\t\tcins.\tbolum\tsinif\n");
		while(m_gecici != NULL)
		{
			printf("---------------------------------------------------------------------\n");
			int dp,mp,yp;
			splitDate(m_gecici->dogum,&dp,&mp,&yp);
			printf(
			"%d\t%s\t%s\t%d/%d/%d\t%s\t%s\t%d\n",m_gecici->no,m_gecici->isim,m_gecici->soyisim,dp,mp,yp,m_gecici->cinsiyet,m_gecici->bolum,m_gecici->sinif);
			
			m_gecici = m_gecici->sonraki;
		}
	}
	printf("---------------------------------------------------------------------\n");
	menu();
}

//kullanicidan veri dosyasi icin giris alinmasi
void dosya_oku()
{
	printf("\nDosya adini giriniz > ");
	char dosya[50];
	scanf("%s",dosya);
	dosya_isle(dosya);
}

//verilen dosya adi uzerinden listeye ekleme yapilmasi
int dosya_isle(char dosya[])
{
	if(!fopen(dosya,"r"))
	{
		printf("\n\nDosya okunamiyor!!!\a");
		menu();
	}
	else
	{
		FILE *oku;
		oku = fopen(dosya,"r");
	//	printf("\nno        \tisim\tsoyad\tdogum\t\tcins.\tbolum\tsinif\n");
		
		while(!feof(oku)){
			liste okunan;
			okunan.isim = (char*)malloc(sizeof(char)*100);
			okunan.soyisim = (char*)malloc(sizeof(char)*100);
			char *dogum = (char*)malloc(sizeof(char)*100);
			okunan.cinsiyet = (char*)malloc(sizeof(char)*5);
			okunan.bolum = (char*)malloc(sizeof(char)*5);
		
			fscanf(oku,"%d %s %s %s %s %s %d",&okunan.no,okunan.isim,okunan.soyisim,dogum,okunan.cinsiyet,okunan.bolum,&okunan.sinif);
			okunan.dogum = dateStrInt(dogum);
			
			ekle(okunan.no,okunan.dogum,okunan.sinif,okunan.isim,okunan.soyisim,okunan.cinsiyet,okunan.bolum);

			int dp,mp,yp;
			splitDate(okunan.dogum,&dp,&mp,&yp);
			//printf("---------------------------------------------------------------------\n");
		//	printf("%d\t%s\t%s\t%d/%d/%d\t%s\t%s\t%d\n",okunan.no,okunan.isim,okunan.soyisim,dp,mp,yp,okunan.cinsiyet,okunan.bolum,okunan.sinif);
			
		}
		fclose(oku);
	}
//	printf("---------------------------------------------------------------------\n");
	menu();		
}

//metinsel olarak verilen tarih verisinin sayisal veriye donusturulmesi
int dateStrInt(char str[])
{
	int day, mounth, year;
	sscanf(str,"%d/%d/%d",&day,&mounth,&year);
	return (year*10000+mounth*100+day);
}

//sayisal olarak verilen tarihin gun,ay,yil seklinde bolunmesi
void splitDate(int ymd, int *dp, int *mp, int *yp)
{
	*dp = ymd % 100;
	*mp = (ymd / 100) % 100;
	*yp = ymd / 10000;
}

//sinif bazinda arama yapma
int ara_sinif(int sinif)
{
	int sayac = 0;
	gecici = ilk;
	
	while(gecici != NULL)
	{
		sayac ++;
		if(gecici->sinif == sinif)
		{
			printf("Bulundu");
			return sayac;
			
		}
		gecici = gecici->sonraki;
	}
	return -1;
}

//butun listedeki kayitlarin sinif degerinin 1 arttirilmasi
void arttir()
{
	if(ilk == NULL)
		printf("\nVeri yok !!!\n");
	else
	{
		gecici = ilk;
		while(gecici != NULL)
		{
			gecici->sinif += 1;
			gecici = gecici->sonraki;
		}
		printf("\n>>> Arttirma islemi uygulandi.\n");
		sil_mezun(4);
	}
}

//mezun olanlarin normal listeden silinip mezun listesine eklenmesi
int sil_mezun(int sinif)
{
	if(ilk == NULL)
		return 1;
	else if(ilk->sinif > sinif)
	{
		silGecici = ilk;
		ilk = ilk->sonraki;
		printf(">>> Mezun oldu [ %d -> %s %s].\n",silGecici->no,silGecici->isim,silGecici->soyisim);
		ekle_mezun(silGecici->no,silGecici->dogum,silGecici->sinif,silGecici->isim,silGecici->soyisim,silGecici->cinsiyet,silGecici->bolum);
		free(silGecici);
		return 1;
	}
	else
	{
		gecici = ilk;
		while(gecici->sonraki != NULL)
		{
			if(gecici->sonraki->sinif > sinif)
			{
				silGecici = gecici->sonraki;
				gecici->sonraki = silGecici->sonraki;
				printf(">>> Mezun oldu [ %d -> %s %s].\n",silGecici->no,silGecici->isim,silGecici->soyisim);
				ekle_mezun(silGecici->no,silGecici->dogum,silGecici->sinif,silGecici->isim,silGecici->soyisim,silGecici->cinsiyet,silGecici->bolum);
				free(silGecici);
				return 1;
			}
			gecici = gecici->sonraki;
		}
	}
	return 0;
}

/*
  silme bolumunde tek tek silmektedir.
  ayrac olmasi icin ; yerine bosluk(space) kullanilmistir
  ek olarak sinif filtrelemesi eklenmistir
*/

