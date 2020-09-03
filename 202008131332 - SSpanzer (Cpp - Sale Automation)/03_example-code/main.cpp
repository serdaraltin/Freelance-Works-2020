/****************************************************************************
**						  SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**					  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**						PROGRAMLAMAYA GİRİŞİ DERSİ
**
**			      ÖDEV NUMARASI......: 
**				  ÖĞRENCİ ADI........: 
**				  ÖĞRENCİ NUMARASI...: 
**				  DERS GRUBU.........: 
****************************************************************************/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


int main(int argc, char *argv[]){
	int secim=0, i=1;
	//-
	int urunNo=0,projeNo=0,hakedisNo=0;
	//-
	string urunAd;
	string urunBirim;
	float urunFiyat;
	//-
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;
	//-
	string hakedisDonem;

	//urun ekle/urun sil/urun ara
	//proje ekle/proje silme/proje ara
	//hakedis ekle/hakedis urunler/hakedis urun sil/hakedis urun guncelle

	char cevap = 'e';

	while(1){
		do{
			cout << endl << "Ne yapmak istiyorsunuz ? " << endl;
			cout << "1) Urun menu" << endl;
			cout << "2) Proje menu" << endl;
			cout << "3) Hakedis menu" << endl;
			cout << "4) programdan cikis" << endl;
			cin >> secim;
		}while(secim !=1 && secim !=2 && secim !=3 && secim !=4);

		//urun menu
		if(secim == 1){
			do{
				cout << endl << "Ne yapmak istiyorsunuz ? " << endl;
				cout << "1) Urun ekle" << endl;
				cout << "2) Urun sil" << endl;
				cout << "3) Urun ara" << endl;
				cin >> secim;
			}while(secim !=1 && secim !=2 && secim !=3);

			if(secim == 1){//urun ekle
				ofstream DosyaYaz;
				DosyaYaz.open("Urun.txt",ios::app);

				do{
					cout << "Urun No    : "; cin >> urunNo;
					cout << "Urun Ad    : "; cin >> urunAd;
					cout << "Urun Birim : "; cin >> urunBirim;
					cout << "Urun Fiyat : "; cin >> urunFiyat;

					DosyaYaz << urunNo << ' ' << urunAd << ' ' << urunBirim << ' ' << urunFiyat << '\n';

					cout << "baska bir urun ekleyecek misiniz?(e/h) ";
					cin >> cevap;
				}while(!(cevap == 'h'));
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi." << endl;
			}
			if(secim == 2){//urun sil
				int arananUrunNo=0;
				urunNo = -1;
				cout << "Aranan Urun No : "; cin >> arananUrunNo;
				ifstream DosyaOku("Urun.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("Urun_yeni.txt",ios::app);
				int var = 0;
				while(!DosyaOku.eof()){
					DosyaOku >> urunNo >> urunAd >> urunBirim >> urunFiyat;
					if(arananUrunNo == urunNo){
						if(var == 0){
							var = 1;
							cout << endl << "Silinen urun bilgileri" << endl;
							cout << "Urun No    : " << urunNo << endl;
							cout << "Urun Ad    : " << urunAd << endl;
							cout << "Urun Birim : " << urunBirim << endl;
							cout << "Urun Fiyat : " << urunFiyat << endl;
							cout << endl;
						}
					}
					else
						DosyaYaz << urunNo << ' ' << urunAd << ' ' << urunBirim << ' ' << urunFiyat << '\n';
				}
				if(var == 0){
					cout << "Urun mevcut degil !" << endl;
				}
				remove("Urun.txt");
				rename("Urun_yeni.txt","Urun.txt");
				DosyaOku.close();
				DosyaYaz.close();
			}
			if(secim == 3){//urun ara
				int arananUrunNo=0;
				urunNo = -1;
				cout << "Aranan Urun No : "; cin >> arananUrunNo;
				ifstream DosyaOku("Urun.txt");
				int var = 0;
				while(!DosyaOku.eof()){
					DosyaOku >> urunNo >> urunAd >> urunBirim >> urunFiyat;
					if(var == 0 && arananUrunNo == urunNo){
						var = 1;
						cout << endl;
						cout << "Urun No    : " << urunNo << endl;
						cout << "Urun Ad    : " << urunAd << endl;
						cout << "Urun Birim : " << urunBirim << endl;
						cout << "Urun Fiyat : " << urunFiyat << endl;
						cout << endl;
						DosyaOku.close();
						break;
					}
				}
				if(var == 0){
					cout << "Urun mevcut degil !" << endl;
				}
			}
			secim = 0;
		}
		//proje menu
		if(secim == 2){
			do{
				cout << endl << "Ne yapmak istiyorsunuz ? " << endl;
				cout << "1) Proje ekle" << endl;
				cout << "2) Proje sil" << endl;
				cout << "3) Proje ara" << endl;
				cin >> secim;
			}while(secim !=1 && secim !=2 && secim !=3);

			if(secim == 1){//proje ekle
				ofstream DosyaYaz;
				DosyaYaz.open("Proje.txt",ios::app);

				do{
					cout << "Proje No         : "; cin >> projeNo;
					cout << "Proje Adi        : "; cin >> projeAdi;
					cout << "Yurutucu Firma   : "; cin >> projeYurutucuFirma;
					cout << "Proje Sorumlusu  : "; cin >> projeSorumlusu;
					cout << "Proje Kontroloru : "; cin >> projeKontroloru;

					DosyaYaz << projeNo << ' '  << projeAdi << ' ' << projeYurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << '\n';

					cout << "baska bir proje ekleyecek misiniz?(e/h) ";
					cin >> cevap;
				}while(!(cevap == 'h'));
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi." << endl;
			}
			if(secim == 2){//proje sil
				int arananProjeNo=0;
				projeNo = -1;
				cout << "Aranan Proje No : "; cin >> arananProjeNo;
				ifstream DosyaOku("Proje.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("Proje_yeni.txt",ios::app);
				int var = 0;
				while(!DosyaOku.eof()){
					DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;
					if(arananProjeNo == projeNo){
						if(var == 0){
							var = 1;
							cout << endl << "Silinen proje bilgileri" << endl;
							cout << "Proje No         : " << projeNo << endl;
							cout << "Proje Adi        : " << projeAdi << endl;
							cout << "Yurutucu Firma   : " << projeYurutucuFirma << endl;
							cout << "Proje Sorumlusu  : " << projeSorumlusu << endl;
							cout << "Proje Kontroloru : " << projeKontroloru << endl;
							cout << endl;
						}
					}
					else
						DosyaYaz << projeNo << ' ' << projeAdi << ' ' << projeYurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << '\n';
				}
				if(var == 0){
					cout << "Proje mevcut degil !" << endl;
				}
				remove("Proje.txt");
				rename("Proje_yeni.txt","Proje.txt");
				DosyaOku.close();
				DosyaYaz.close();
			}
			if(secim == 3){//proje ara
				int arananProjeNo=0;
				projeNo = -1;
				cout << "Aranan Proje No : "; cin >> arananProjeNo;
				ifstream DosyaOku("Proje.txt");
				int var = 0;
				while(!DosyaOku.eof()){
					DosyaOku >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;
					if(arananProjeNo == projeNo){
						if (var == 0) {
							var = 1;
							cout << endl;
							cout << "Proje No         : " << projeNo << endl;
							cout << "Proje Adi        : " << projeAdi << endl;
							cout << "Yurutucu Firma   : " << projeYurutucuFirma << endl;
							cout << "Proje Sorumlusu  : " << projeSorumlusu << endl;
							cout << "Proje Kontroloru : " << projeKontroloru << endl;
							cout << endl;
							DosyaOku.close();
							break;
						}
					}
				}
				if(var == 0){
					cout << "Proje mevcut degil !" << endl;
				}
			}
			secim = 0;
		}
		//hakedis menu
		if(secim == 3){
			do{
				cout << endl << "Ne yapmak istiyorsunuz ? " << endl;
				cout << "1) Hakedis ekle" << endl;
				cout << "2) Hakedis urunler" << endl;
				cout << "3) Hakedis urun sil" << endl;
				cout << "4) Hakedis urun guncelle" << endl;
				cin >> secim;
			}while(secim !=1 && secim !=2 && secim !=3 && secim !=4);

			if(secim == 1){//hakedis ekle
				ofstream DosyaYaz;
				DosyaYaz.open("Hakedis.txt",ios::app);

				do{
					cout << "Hakedis No    : "; cin >> hakedisNo;
					cout << "Proje No      : "; cin >> projeNo;
					cout << "Hakedis Donem : "; cin >> hakedisDonem;

					DosyaYaz << hakedisNo << ' '  << projeNo << ' ' << hakedisDonem << '\n';

					char baskaUrunEkle = 'e';
					ofstream DosyaYazSatilan;
					DosyaYazSatilan.open("Satilan_Urun.txt",ios::app);

					do{
						int urunAdet=0;
						cout << "Urun No   : "; cin >> urunNo;
						cout << "Urun Adet : "; cin >> urunAdet;

						DosyaYazSatilan << hakedisNo << ' '  << urunNo << ' ' << urunAdet << '\n';
						cout << "baska bir urun ekleyecek misiniz?(e/h) "; cin >> baskaUrunEkle;
					}while(!(baskaUrunEkle == 'h'));

					DosyaYazSatilan.close();
					cout << "baska bir hakedis ekleyecek misiniz?(e/h) ";
					cin >> cevap;
				}while(!(cevap == 'h'));
				DosyaYaz.close();
				
				cout << "dosyaya yazim tamamlandi." << endl;
			}
			if(secim == 2){//hakedis urunler
				int arananProjeNo=0,arananHakedisNo=0;
				projeNo = -1; 
				hakedisNo = -1;

				cout << "Aranan Hakedis No : "; cin >> arananHakedisNo;
				ifstream DosyaOku("Hakedis.txt");
				int var = 0;
				while(!DosyaOku.eof()){
					DosyaOku >> hakedisNo >> projeNo >> hakedisDonem;
					if(var == 0 && arananHakedisNo == projeNo){
						var = 1;
						cout << endl;
						cout << "Hakedis No : " << hakedisNo;
						cout << "  Proje No : " << projeNo;
						cout << "  Hakedis Donem : " << hakedisDonem;
						cout << endl;
						arananProjeNo = projeNo;
						arananHakedisNo = hakedisNo;
						DosyaOku.close();
						break;
					}
				}
				if(var == 0){
					cout << "Hakedis mevcut degil !" << endl;
					break;
				}
				cout << "-------------------------------------------------" << endl;
				ifstream DosyaOkuProje("Proje.txt");
				var = 0;
				while(!DosyaOkuProje.eof()){
					DosyaOkuProje >> projeNo >> projeAdi >> projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;
					if(var == 0 && arananProjeNo == projeNo){
						var = 1;
						cout << endl;
						cout << "Proje Adi        : " << projeAdi << endl;
						cout << "Yurutucu Firma   : " << projeYurutucuFirma << endl;
						cout << "Proje Sorumlusu  : " << projeSorumlusu << endl;
						cout << "Proje Kontroloru : " << projeKontroloru << endl;
						cout << endl;
						DosyaOkuProje.close();
						break;
					}
				}
				cout << "------------Urunler----------" << endl << endl;
				ifstream DosyaOkuSUrun("Satilan_Urun.txt");
				int oncekiUrunNo=0,urunAdet=0;
				while(!DosyaOkuSUrun.eof()){
					DosyaOkuSUrun >> hakedisNo >> urunNo >> urunAdet;
					if(arananHakedisNo == hakedisNo && oncekiUrunNo != urunNo){

						int arananUrunNo=urunNo;
						ifstream DosyaOkuUrun("Urun.txt");

						while(!DosyaOkuUrun.eof()){
							DosyaOkuUrun >> urunNo >> urunAd >> urunBirim >> urunFiyat;
							if(arananUrunNo == urunNo){
								cout << "Urun No    : " << urunNo << endl;
								cout << "Urun Ad    : " << urunAd << endl;
								cout << "Urun Fiyat : " << urunFiyat << endl;
								cout << "Urun Adet  : " << urunAdet << endl;
								cout << "Tutar      : " << (urunAdet*urunFiyat) << " TL" << endl;
								cout << "-----------------------------" << endl;
								DosyaOkuUrun.close();
								break;
							}
						}

						oncekiUrunNo = urunNo;
					}
				}
				DosyaOku.close();
				DosyaOkuProje.close();
				DosyaOkuSUrun.close();
			}
			if(secim == 3){//hakedis urun sil
				int arananUrunNo=0,arananHakedisNo=0,urunAdet=0;
				urunNo = -1;

				cout << "Aranan Hakedis No : "; cin >> arananHakedisNo;
				cout << "Aranan Urun No : "; cin >> arananUrunNo;

				ifstream DosyaOku("Satilan_Urun.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("Satilan_Urun_yeni.txt",ios::app);

				int var = 0,oncekiUrunNo=0;
				while(!DosyaOku.eof()){
					DosyaOku >> hakedisNo >> urunNo >> urunAdet;
					if(arananUrunNo == urunNo && arananHakedisNo == hakedisNo){
						var = 1;
					}
					if(urunNo != arananUrunNo && oncekiUrunNo != urunNo){
						DosyaYaz << hakedisNo << ' ' << urunNo << ' ' << urunAdet << '\n';
					}
					oncekiUrunNo = urunNo;
				}

				DosyaOku.close();
				DosyaYaz.close();
				remove("Satilan_Urun.txt");
				rename("Satilan_Urun_yeni.txt","Satilan_Urun.txt");

				if (var == 0) {
					cout << "Kayit mevcut degil !" << endl;
				}
				else {
					cout << "Silindi." << endl;
				}
			}
			if(secim == 4){//hakedis urun guncelle
				int arananUrunNo = 0, arananHakedisNo = 0, urunAdet = 0;
				urunNo = -1;

				cout << "Aranan Hakedis No : "; cin >> arananHakedisNo;
				cout << "Aranan Urun No : "; cin >> arananUrunNo;

				ifstream DosyaOku("Satilan_Urun.txt");
				ofstream DosyaYaz;
				DosyaYaz.open("Satilan_Urun_yeni.txt", ios::app);

				int var = 0, oncekiUrunNo = 0;
				while (!DosyaOku.eof()) {
					DosyaOku >> hakedisNo >> urunNo >> urunAdet;

					if (arananUrunNo == urunNo && arananHakedisNo == hakedisNo) {
						if (var == 0 ) {
							var = 1;
							cout << "Yeni Urun Adet : "; cin >> urunAdet;
						}
					}
					if (oncekiUrunNo != urunNo) {
						DosyaYaz << hakedisNo << ' ' << urunNo << ' ' << urunAdet << '\n';
					}
					
					oncekiUrunNo = urunNo;
				}

				DosyaOku.close();
				DosyaYaz.close();
				remove("Satilan_Urun.txt");
				rename("Satilan_Urun_yeni.txt", "Satilan_Urun.txt");

				if (var == 0) {
					cout << "Kayit mevcut degil !" << endl;
				}
				else {
					cout << "Guncellendi." << endl;
				}
			}
			secim = 0;
		}
		//cikis
		if(secim == 4){
			exit(0);
		}

	}

} 