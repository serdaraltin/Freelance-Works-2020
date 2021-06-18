#include <iostream>
#include <cstring>
#include "sem.h"
using namespace std;

int main(){
	YeniOgrenciEkle(30,"Deniz","Ozoglu",1);
	YeniOgrenciEkle(20,"Emirhan","Taner",2);
	YeniOgrenciEkle(25,"Betul","Dikmen",4);
	YeniOgrenciEkle(42,"Ecem","Cetin",1);
	YeniOgrenciEkle(32,"Mert","Acunman",4);
	YeniOgrenciEkle(47,"Gunce","Er",3);
	YeniOgrenciEkle(10,"Fatih","Balci",3);
	YeniOgrenciEkle(23,"Ahsen","Konak",2);
	YeniOgrenciEkle(17,"Ece","Surucu",1);
	YeniOgrenciEkle(40,"Yaren","Sari",1);

	Menu();
}

void Menu(){
	printf("1) Ogrenci Ekle\n");
	printf("2) Ogrenci Duzenle\n");
	printf("3) Ogrenci Sil\n");
	printf("4) Kayitlari Listele\n");
	printf("5) Seminer Kayitlari\n");
	printf("6) Surpiz Hediye Cekilisi\n");
	printf("0) Sistemden cik\n");

	printf("Secim : ");
	int choice;
	scanf("%d",&choice);

	switch(choice){
		case 0:
		  	printf("Sistemden cikiliyor...\n");
		  	exit(0);
		 	break;
		case 1:
			OgrenciEkle();//+
			break;
		case 2:
			OgrenciDuzenle();//+
			break;
		case 3:
			OgrenciSil();//+
			break;
		case 4:
			KayitlariListele();//+
			break;
		case 5:
			SeminerKayitlari();//+
			break;
		case 6:
			SurpizCekilis();//+
			break;
		default:
			printf("Hatali bir secim yaptiniz\n");
			break;	
	
	}
	printf("\n");
	Menu();
} 
