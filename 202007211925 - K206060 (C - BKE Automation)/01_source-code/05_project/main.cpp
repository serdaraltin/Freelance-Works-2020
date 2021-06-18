#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void Menu();
void DiyetMenu();
void DiyetOlustur();
void DiyetiListeleDiyetisyenOnerisi();
void DiyetiListeleAdetMiktariAzalan();
void DiyetiListeleGunSirasi();

struct ogun
{
	int grMiktari;
	int siviMiktari;
	int adetMiktari;
	struct ogun *sonraki;
};


struct diyet
{	
	int no;
	int gun;
	struct ogun *ogun;
	struct diyet *sol,*sag;
};


struct musteri
{
	int diyetNo[10];
	int yas;
	int boy;
	int kilo;
	int kategori;
	float BKE;
	struct diyet *diyetListesi;
};


struct musteri *musteri = (struct musteri*)malloc(sizeof(struct musteri));

struct diyet* YeniDugum(int no, struct ogun *ogun ,int gun){
	
    struct diyet *yeniDiyet= (struct diyet*)malloc(sizeof(struct diyet));
    yeniDiyet->no = no;
    yeniDiyet->ogun = ogun;
    yeniDiyet->gun = gun;

    yeniDiyet->sol = yeniDiyet->sag = NULL;
    return yeniDiyet;
}

struct diyet* DiyetEkle(struct diyet *baslangic, int no, struct ogun *ogun, int gun){
	//perror("girdi");
    if(baslangic == NULL){
    	
    	return YeniDugum(no,ogun,gun);
	}  
    else if(no > baslangic->no){
    	 baslangic->sag = DiyetEkle(baslangic->sag, no, ogun, gun);
	}
    else if(no < baslangic->no){
    	baslangic->sol = DiyetEkle(baslangic->sol, no, ogun, gun);
	}
        

    return baslangic;
}

struct diyet* Ara(struct diyet *baslangic,int no){
    if(baslangic == NULL || baslangic->no == no) 
        return baslangic;
    else if(no > baslangic->no) 
        return Ara(baslangic->sag, no);
    else 
        return Ara(baslangic->sol, no);
}

float BKEHesapla(int kilo, int boy){
	float boyM = (float)boy/100.0;
	return kilo / (boyM*boyM);
}

void KategoriBelirle(struct musteri *musteri){
	int i;
	float BKE = BKEHesapla(musteri->kilo,musteri->boy);
	musteri->BKE = BKE;

	if(BKE < 18.49){
		int ogun[10] = {5,9,8,7,6,4,3,8,6,4};
		for(i=0; i<10; i++)
			musteri->diyetNo[i] = ogun[i];
		musteri->kategori = 1;
		return;
	}
	else if(BKE > 18.49 && BKE < 24.99){
		int ogun[10] = {1,5,9,7,0,3,6,8,4,2};
		for(i=0; i<10; i++)
			musteri->diyetNo[i] = ogun[i];
		musteri->kategori = 2;
		return;
	}
	else if(BKE > 24.99 && BKE < 29.99){
		int ogun[10] = {1,0,3,2,3,1,4,6,0,2};
		for(i=0; i<10; i++)
			musteri->diyetNo[i] = ogun[i];
		musteri->kategori = 3;
		return;
	}
	else if(BKE > 30.00){
		int ogun[10] = {1,0,0,2,0,1,3,0,0,1};
		for(i=0; i<10; i++)
			musteri->diyetNo[i] = ogun[i];
		musteri->kategori = 4;
		return;
	}
}

void MusteriYazdir(struct musteri *musteri){
	printf("\nMusterinin\n");
	printf("yasi: %d\tboyu: %dcm\tkilosu: %dkg\n",musteri->yas,musteri->boy,musteri->kilo);
	printf("BKE = %.2f ", musteri->BKE);

	if(musteri->kategori == 1)
		printf("(Ideal Kilonun Alti) - ");
	else if(musteri->kategori == 2)
		printf("(Ideal Kilo) - ");
	else if(musteri->kategori == 3)
		printf("(Ideal Kilonun Uzeri) - ");
	else if(musteri->kategori == 4)
		printf("(Ideal Kilonun Cok Uzeri) - ");

	printf("Diyet numarasi ");

	int i;
	for(i=0; i<10; i++)
		printf("%d ",musteri->diyetNo[i]);
	printf("\n");
}

int BoyRakamlarToplam(int boy){
	int sayi = boy, rakam, toplam = 0;

	while(sayi > 0){
		rakam = sayi % 10;
		toplam += rakam;
		sayi /= 10;
	}
	return toplam;
}

void DiyetListesiOlustur(struct musteri *musteri){
	int i;
	musteri->diyetListesi = NULL;
	for(i=0; i<10; i++){
	
		struct ogun *sabah = (struct ogun*)malloc(sizeof(struct ogun));
		
		sabah->grMiktari = (musteri->boy) - (musteri->yas) + (musteri->diyetNo[i]);
		sabah->siviMiktari = (musteri->kilo) + (musteri->yas) - (musteri->diyetNo[i]);
		sabah->adetMiktari = musteri->diyetNo[i];
		

		struct ogun *oglen = (struct ogun*)malloc(sizeof(struct ogun));
		oglen->grMiktari = (musteri->kilo) + (musteri->yas) + (musteri->diyetNo[i]);
		oglen->siviMiktari = (BoyRakamlarToplam(musteri->boy)) + (musteri->diyetNo[i]);
		oglen->adetMiktari = musteri->diyetNo[i];

		struct ogun *aksam = (struct ogun*)malloc(sizeof(struct ogun));
		aksam->grMiktari = (musteri->boy) - (musteri->yas) + (musteri->diyetNo[i]);
		aksam->siviMiktari = (musteri->kilo) + (musteri->yas) - (musteri->diyetNo[i]);
		aksam->adetMiktari = musteri->diyetNo[i];

		sabah->sonraki = oglen;
		oglen->sonraki = aksam;
		aksam->sonraki = NULL;

		musteri->diyetListesi = DiyetEkle(musteri->diyetListesi, musteri->diyetNo[i],sabah,i+1);
		
	}
}

void DiyetYazdir(struct diyet *diyet){

	struct ogun *ogun = diyet->ogun;
	struct ogun *sabah = ogun;
	struct ogun *oglen = sabah->sonraki;
	struct ogun *aksam = oglen->sonraki;

	printf("Gun : %d\tDiyet Numarasi : %d\n\n",diyet->gun, diyet->no);
	printf("Sabah > ");
	printf("%d gr peynir, %d cc sivi, %d adet zeytin\n", sabah->grMiktari,sabah->siviMiktari,sabah->adetMiktari);
	printf("Oglen > ");
	printf("%d gr salata, %d kasik corba, %d adet meyve\n", oglen->grMiktari,oglen->siviMiktari,oglen->adetMiktari);
	printf("Aksam > ");
	printf("%d gr et, %d cc sivi, %d dilim ekmek\n", aksam->grMiktari,aksam->siviMiktari,aksam->adetMiktari);

	printf("------------------------------------------------------\n");
	return;
}

void AzalanListele(struct diyet *baslangic){
    if(baslangic!=NULL)
    {
    	AzalanListele(baslangic->sag);
        DiyetYazdir(baslangic);
        AzalanListele(baslangic->sol); 
    }
}

void ArtanListele(struct diyet *baslangic){
    if(baslangic!=NULL)
    {
    	ArtanListele(baslangic->sol); 
        DiyetYazdir(baslangic);
        ArtanListele(baslangic->sag);
    }
}

void GunListele(struct musteri *musteri){
	int i;
	for(i=0; i<10; i++){
		struct ogun *ogun = Ara(musteri->diyetListesi,musteri->diyetNo[i])->ogun;
		struct ogun *sabah = ogun;
		struct ogun *oglen = sabah->sonraki;
		struct ogun *aksam = oglen->sonraki;

		printf("Gun : %d\tDiyet Numarasi : %d\n\n",i+1, musteri->diyetNo[i]);
		printf("Sabah > ");
		printf("%d gr peynir, %d cc sivi, %d adet zeytin\n", sabah->grMiktari,sabah->siviMiktari,sabah->adetMiktari);
		printf("Oglen > ");
		printf("%d gr salata, %d kasik corba, %d adet meyve\n", oglen->grMiktari,oglen->siviMiktari,oglen->adetMiktari);
		printf("Aksam > ");
		printf("%d gr et, %d cc sivi, %d dilim ekmek\n", aksam->grMiktari,aksam->siviMiktari,aksam->adetMiktari);

		printf("------------------------------------------------------\n");
	}
}

int main(){
	printf("... Hosgeldiniz ...\n");
	Menu();
} 

void Menu(){
	printf("\n");
	printf("1) Diyet Menu\n");
	printf("0) Cikis\n");
	printf("\nSecim : ");
	int secim;
	cin >> secim;
	printf("\n");
	switch(secim){
		case 0:
			printf("Programdan Cikiliyor...\n");
			exit(0);
			break;
		case 1:
			DiyetMenu();
			break;
		default:
			printf("Hatali secim, tekrar deneyiniz!\n");
			break;
	}
	Menu();
}

void DiyetMenu(){
	printf("\n");
	printf("1) Diyet Olustur\n");
	printf("2) Diyeti Listele (Diyetisyenin onerdigi)\n");
	printf("3) Diyeti Listele (Adet miktari azalacak sekilde)\n");
	printf("4) Diyeti Listele (Gun sirasi)\n");
	printf("0) Ust Menu\n");
	printf("\nSecim : ");
	int secim;
	cin >> secim;
	printf("\n");
	switch(secim){
		case 0:
			return;
			break;
		case 1:
			DiyetOlustur();
			break;
		case 2:
			DiyetiListeleDiyetisyenOnerisi();
			break;
		case 3:
			DiyetiListeleAdetMiktariAzalan();
			break;
		case 4:
			DiyetiListeleGunSirasi();
			break;
		default:
			printf("Hatali secim, tekrar deneyiniz!\n");
			break;
	}

	DiyetMenu();
}

void DiyetOlustur(){
	printf("Yas : ");
	cin >> musteri->yas;

	printf("Boy (cm): ");
	cin >> musteri->boy;

	printf("Kilo (kg) : ");
	cin >> musteri->kilo;

	KategoriBelirle(musteri);
	DiyetListesiOlustur(musteri);
	MusteriYazdir(musteri);
}

void DiyetiListeleGunSirasi(){
	if(musteri->diyetListesi != NULL){
		GunListele(musteri);
		return;
	}
	printf("Herhangi bir diyet listesi bulunmamaktadir !\n");
	return;
}

void DiyetiListeleDiyetisyenOnerisi(){
	if(musteri->diyetListesi != NULL){
		ArtanListele(musteri->diyetListesi);
		return;
	}
	printf("Herhangi bir diyet listesi bulunmamaktadir !\n");
	return;
}

void DiyetiListeleAdetMiktariAzalan(){
	if(musteri->diyetListesi != NULL){
		AzalanListele(musteri->diyetListesi);
		return;
	}
	printf("Herhangi bir diyet listesi bulunmamaktadir !\n");
	return;
}
