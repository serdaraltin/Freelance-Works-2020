#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
struct calisan
{
	int CalisanNo;
	char Adi[30];
	char Soyadi[30];
	float Maasi;
};

typedef struct calisan Calisan;

Calisan Calisanlar[7];


void Menu();
int Son();
void Ekle(int CalisanNo,char* Adi,char* Soyadi,float Maasi);
int Bul(int CalisanNo);
void Yazdir(int index);
void EnYuksekMaas();
void EnDusukMaas();
float OrtalamaMaas();
void OrtalamaAltindaMaasAlanlar();
void TumPersonelListesi();
void UcretArtisAzalis(int index,float degisim);

int main(){
	printf("******    PERSONEL PROGRAMI *********\n");
	Menu();
}

void Menu(){
	printf("1: Bilgi girisi\n"); 
	printf("2: Bilgi goruntuleme\n");
	printf("3: En yuksek maas\n");
	printf("4: En dusuk maas\n");
	printf("5: Ortalama maas\n");
	printf("6: Ortalama maasin altinda maas alan personel\n");
	printf("7: Ucret artis/azalis\n");
	printf("8: Tum personel listesi\n");

	printf("\n\nNe Yapmak istiyorsunuz: ");
	int sec;
	scanf("%d",&sec);
	printf("\n\n");
	switch(sec){
		case 1:
			if(Son() == 7){
				printf("Daha fazla calisan eklenemez!!!\n");
				break;
			}

			printf("Calisan No: ");
			int CalisanNo;
			scanf("%d",&CalisanNo);
			while(Bul(CalisanNo) != -1){
				printf("Ayni No'ya sahip bir calisan var tekrar deneyini!\n");
				printf("Calisan No:");
				scanf("%d",&CalisanNo);
			}

			printf("Adi: ");
			char Adi[30];
			scanf("%s",Adi);

			printf("Soyadi: ");
			char Soyadi[30];
			scanf("%s",Soyadi);

			printf("Maasi: ");
			float Maasi;
			scanf("%f",&Maasi);

			Ekle(CalisanNo,Adi,Soyadi,Maasi);
			break;
		case 2:
			printf("Calisan No: ");
			int BulCalisanNo;
			scanf("%d",&BulCalisanNo);
			if(Bul(BulCalisanNo) == -1){
				printf("Belirtilen Calisan bulunamadi\n");
				break;
			}
			Yazdir(Bul(BulCalisanNo));
			break;
		case 3:
			EnYuksekMaas();
			break;
		case 4:
			EnDusukMaas();
			break;
		case 5:
			OrtalamaMaas();
			break;
		case 6:
			OrtalamaAltindaMaasAlanlar();
			break;
		case 7:
			printf("Calisan No: ");
			int UcCalisanNo;
			scanf("%d",&UcCalisanNo);
			if(Bul(UcCalisanNo) == -1){
				printf("Belirtilen Calisan bulunamadi\n");
				break;
			}
			printf("Maas Artis/Azalis[azaltma icin orn> -100] : ");
			float degisim;
			scanf("%f",&degisim);

			UcretArtisAzalis(Bul(UcCalisanNo),degisim);
			break;
		case 8:
			TumPersonelListesi();
			break;
		default:
			printf("Hatali secim,tekrar deneyiniz !!!\n");
			break;
	}
	printf("\n\n");
	Menu();
}

void Ekle(int CalisanNo,char* Adi,char* Soyadi,float Maasi){
	int index = Son();
	Calisanlar[index].CalisanNo = CalisanNo;
	strcpy(Calisanlar[index].Adi,Adi);
	strcpy(Calisanlar[index].Soyadi,Soyadi);
	Calisanlar[index].Maasi = Maasi;

	printf("\nCalisan Eklendi.\n");
	return;
}
	
int Son(){
	int i = 0;
	while(strcmp(Calisanlar[i].Adi,"")!=0){
		i++;
	}
	return i;
}

int Bul(int CalisanNo){
	int i;
	for (i = 0; i < 7; i++)
	{
		if(Calisanlar[i].CalisanNo == CalisanNo)
			return i;
	}
	return -1;
}
void Yazdir(int index){
	printf("\n---------------------------------\n");
	printf("Calisan No: %d\n",Calisanlar[index].CalisanNo);
	printf("Adi\t: %s\n",Calisanlar[index].Adi);
	printf("Soyadi\t: %s\n",Calisanlar[index].Soyadi);
	printf("Maasi\t: %.2f TL\n",Calisanlar[index].Maasi);
	printf("---------------------------------\n");
	return;
}

void EnYuksekMaas(){
	int EnCalisan = -1;
	int i;
	for(i=0; i< Son(); i++){
		if(EnCalisan == -1 && Calisanlar[i].Maasi > 0){
			EnCalisan = i;
		}
		if(Calisanlar[EnCalisan].Maasi < Calisanlar[i].Maasi){
			EnCalisan = i;
		}
	}
	if(EnCalisan == -1){
		printf("Herhangi bir calisan yok!!!\n");
	}
	Yazdir(EnCalisan);
	return;
}

void EnDusukMaas(){
	int EnCalisan = -1;
	int i;
	for(i=0; i< Son(); i++){
		if(EnCalisan == -1 && Calisanlar[i].Maasi > 0){
			EnCalisan = i;
		}
		if(Calisanlar[EnCalisan].Maasi > Calisanlar[i].Maasi){
			EnCalisan = i;
		}
	}
	if(EnCalisan == -1){
		printf("Herhangi bir calisan yok!!!\n");
	}
	Yazdir(EnCalisan);
	return;
}

float OrtalamaMaas(){
	float toplam = 0;
	int i;
	for(i=0; i< Son(); i++){
		toplam += Calisanlar[i].Maasi;
	}
	float ortalama = toplam / Son();
	printf("\nOrtalama Maas : %.2f\n",ortalama );
	return ortalama;
}

void OrtalamaAltindaMaasAlanlar(){
	printf("Ortalama Altinda Maas Alan Personeller ->\n");
	float ortalama = OrtalamaMaas();

	int i;
	for(i=0; i< Son(); i++){
		if(Calisanlar[i].Maasi < ortalama){
			Yazdir(i);
		}
	}
	return;
}

void TumPersonelListesi(){
	printf("Personel Listesi ->\n");
	int i;
	for(i=0; i< Son(); i++){
			Yazdir(i);
	}
	return;
}

void UcretArtisAzalis(int index, float degisim){
	Calisanlar[index].Maasi += degisim;
	printf("Maas degisikligi yapildi\n");
	return;
}