#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void Menu();

void UrunMenu();
void UrunListele();
void UrunEkle();
void UrunSil();
void UrunAra();
void UrunRaporla();
int UrunKontrol(int arananNo);
void UrunYazdir(int arananNo,int adet);

void ProjeMenu();
void ProjeEkle();
void ProjeSil();
void ProjeAra();
void ProjeRaporla();
int ProjeKontrol(int arananNo);
void ProjeYazdir(int arananNo);

void HakedisMenu();
void HakedisEkle();
void HakedisSil();
void HakedisKullanilanUrunler();
void HakedisUrunSil();
void HakedisUrunGuncelle();
void HakedisUrunListele();
void HakedisUrunAra();
int HakedisKontrol(int arananNo);
void HakedisUrunEkle(int HakedisNo);
void HakedisYazdir(int arananNo);


int main(int argc, char *argv[]){

	Menu();
} 

void Menu(){
	cout << "1) Urun Islemleri" << endl;
	cout << "2) Proje Islemleri" << endl;
	cout << "3) Hakedis Islemleri" << endl;
	cout << "0) Cikis" << endl << endl;
	cout << "Seciminiz : ";

	int secim;
	cin >> secim;
	cout << endl;
	switch(secim){

		case 0:
			cout << "Programdan cikiliyor..." << endl;
			exit(0);
			break;

		case 1:
			UrunMenu();
			break;

		case 2:
			ProjeMenu();
			break;

		case 3:
			HakedisMenu();
			break;

		default:
			cout << endl << "Hatali secim !" << endl;
			break;
	}
	cout << endl;
	Menu();
}

void UrunMenu(){
	cout << "1) Urun Ekle" << endl;
	cout << "2) Urun Sil" << endl;
	cout << "3) Urun Ara" << endl;
	cout << "4) Urun Raporla" << endl;
	cout << "5) Urun Listesi" << endl;
	cout << "0) Ust Menu" << endl << endl;
	cout << "Seciminiz : ";

	int secim;
	cin >> secim;
	cout << endl;
	switch(secim){

		case 0:
			return;
			break;

		case 1:
			UrunEkle();
			break;

		case 2:
			UrunSil();
			break;

		case 3:
			UrunAra();
			break;

		case 4:
			UrunRaporla();
			break;

		case 5:
			UrunListele();
			break;

		default:
			cout << endl << "Hatali secim !" << endl;
			break;
	}
	cout << endl;
	UrunMenu();
}

void UrunListele(){
	int urunNo,oncekiUrunNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;

	ifstream DosyaOku("urunler.txt");

	cout << "------------Urunler-------------" << endl << endl;
	while(!DosyaOku.eof()){
		DosyaOku >> urunNo >> urunAdi >> 
		birim >> birimFiyati >> marka;
		if(oncekiUrunNo == urunNo)
			break;
		oncekiUrunNo = urunNo;
		cout <<"Urun No      : " << urunNo << endl; 
		cout <<"Urun Adi     : " << urunAdi << endl; 
		cout <<"Urun Birimi  : " << birim << endl; 
		cout <<"Urun Fiyati  : " << birimFiyati << endl; 
		cout <<"Urun Markasi : " << marka << endl; 
		cout << "--------------------------------" << endl;
	}
	DosyaOku.close();
}

void UrunEkle(){
	int urunNo=0;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;

	ofstream DosyaYaz;
	DosyaYaz.open("urunler.txt",ios::app);

	char cevap = 'e';
	do{
		while(1){
			cout <<"Urun No   : "; cin >> urunNo;
			if(UrunKontrol(urunNo) == 1)
				cout << "Bu no'ya sahip bir urun var !" << endl;
			else
				break;
		}
		cout <<"Urun Adi     : "; cin >> urunAdi;
		cout <<"Urun Birimi  : "; cin >> birim;
		cout <<"Urun Fiyati  : "; cin >> birimFiyati;
		cout <<"Urun Markasi : "; cin >> marka;

		DosyaYaz << urunNo << ' ' <<urunAdi << ' ' << birim << ' ' << birimFiyati << ' ' << marka << '\n';

		cout << "Baska bir urun ekleyecek misiniz? [e/h] :"; cin >> cevap;
	}while(cevap == 'e' || cevap == 'E');

	DosyaYaz.close();

	cout <<"Urun/ler eklendi." << endl;
}

void UrunSil(){
	int urunNo,arananNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;
	cout << "Urun No : "; cin >> arananNo;

	ifstream DosyaOku("urunler.txt");
	ofstream DosyaYaz;
	DosyaYaz.open("gecici_urunler.txt", ios::app);

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> urunNo >> urunAdi >> 
		birim >> birimFiyati >> marka;

		if(arananNo == urunNo && kontrol == 0){
			kontrol = 1;
			cout << endl <<"----Silinen Urun Bilgileri----" << endl;
			cout <<"Urun No      : " << urunNo << endl; 
			cout <<"Urun Adi     : " << urunAdi << endl; 
			cout <<"Urun Birimi  : " << birim << endl; 
			cout <<"Urun Fiyati  : " << birimFiyati << endl; 
			cout <<"Urun Markasi : " << marka << endl; 
		}
		if(arananNo != urunNo)
			DosyaYaz << urunNo << ' ' <<urunAdi << ' ' << birim << ' ' << birimFiyati << ' ' << marka << '\n';
	}
	DosyaOku.close();
	DosyaYaz.close();
	remove("urunler.txt");
	rename("gecici_urunler.txt","urunler.txt");
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}

void UrunAra(){
	int urunNo,arananNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;
	cout << "Urun No : "; cin >> arananNo;
	ifstream DosyaOku("urunler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> urunNo >> urunAdi >> 
		birim >> birimFiyati >> marka;

		if(arananNo == urunNo){
			kontrol = 1;
			cout << endl <<"----Urun Bilgileri----" << endl;
			cout <<"Urun No      : " << urunNo << endl; 
			cout <<"Urun Adi     : " << urunAdi << endl; 
			cout <<"Urun Birimi  : " << birim << endl; 
			cout <<"Urun Fiyati  : " << birimFiyati << endl; 
			cout <<"Urun Markasi : " << marka << endl; 
			DosyaOku.close();
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}

void UrunYazdir(int arananNo,int adet){
	int urunNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;

	ifstream DosyaOku("urunler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> urunNo >> urunAdi >> 
		birim >> birimFiyati >> marka;

		if(arananNo == urunNo){
			kontrol = 1;
			cout <<"Urun No      : " << urunNo << endl; 
			cout <<"Urun Adi     : " << urunAdi << endl; 
			cout <<"Urun Marka   : " << marka << endl; 
			cout <<"Birim Fiyati : " << birimFiyati << " TL"<< endl;
			cout <<"Urun Adet    : " << adet << endl;
			cout <<"Tutar        : " << (birimFiyati*(float)adet) << " TL" << endl; 
			cout << "--------------------------------" << endl;
			DosyaOku.close();
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}

void UrunRaporla(){
	int urunNo,arananNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;
	cout << "Urun No : "; cin >> arananNo;
	ifstream DosyaOku("urunler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> urunNo >> urunAdi >> 
		birim >> birimFiyati >> marka;

		if(arananNo == urunNo){
			kontrol = 1;
			cout << endl <<"----Urun Bilgileri----" << endl;
			cout <<"Urun No      : " << urunNo << endl; 
			cout <<"Urun Adi     : " << urunAdi << endl; 
			cout <<"Urun Birimi  : " << birim << endl; 
			cout <<"Urun Fiyati  : " << birimFiyati << endl; 
			cout <<"Urun Markasi : " << marka << endl; 
			DosyaOku.close();
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}

int UrunKontrol(int arananNo){
	int urunNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;

	ifstream DosyaOku("urunler.txt");

	while(!DosyaOku.eof()){
		DosyaOku >> urunNo >> urunAdi >> 
		birim >> birimFiyati >> marka;

		if(arananNo == urunNo){
			DosyaOku.close();
			return 1;
		}
	}
	DosyaOku.close();
	return 0;
}


void ProjeMenu(){
	cout << "1) Proje Ekle" << endl;
	cout << "2) Proje Sil" << endl;
	cout << "3) Proje Ara" << endl;
	cout << "4) Proje Raporla" << endl;
	cout << "0) Ust Menu" << endl << endl;
	cout << "Seciminiz : ";

	int secim;
	cin >> secim;
	cout << endl;
	switch(secim){

		case 0:
			return;
			break;

		case 1:
			ProjeEkle();
			break;

		case 2:
			ProjeSil();
			break;

		case 3:
			ProjeAra();
			break;

		case 4:
			ProjeRaporla();
			break;

		default:
			cout << endl << "Hatali secim !" << endl;
			break;
	}
	cout << endl;
	ProjeMenu();
}

void ProjeEkle(){
	int projeNo;
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;

	ofstream DosyaYaz;
	DosyaYaz.open("projeler.txt",ios::app);

	char cevap = 'e';
	do{
		while(1){
			cout <<"Proje No   : "; cin >> projeNo;
			if(ProjeKontrol(projeNo) == 1)
				cout << "Bu no'ya sahip bir proje var !" << endl;
			else
				break;
		}
		cout <<"Proje Adi     : "; cin >> projeAdi;
		cout <<"Yurutucu Firma: "; cin >> projeYurutucuFirma;
		cout <<"Sorumlu       : "; cin >> projeSorumlusu;
		cout <<"Kontrolor     : "; cin >> projeKontroloru;

		DosyaYaz << projeNo << ' ' << projeAdi << ' ' << projeYurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << '\n';

		cout << "Baska bir proje ekleyecek misiniz? [e/h] :"; cin >> cevap;
	}while(cevap == 'e' || cevap == 'E');

	DosyaYaz.close();

	cout <<"Proje/ler eklendi." << endl;
}

void ProjeSil(){
	int projeNo,arananNo;
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;
	cout << "Proje No : "; cin >> arananNo;

	ifstream DosyaOku("projeler.txt");
	ofstream DosyaYaz;
	DosyaYaz.open("gecici_projeler.txt", ios::app);

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> projeNo >> projeAdi >> 
		projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

		if(arananNo == projeNo && kontrol == 0){
			kontrol = 1;
			cout << endl <<"----Silinen Proje Bilgileri----" << endl;
			cout <<"Proje No      : " << projeNo << endl; 
			cout <<"Proje Adi     : " << projeAdi << endl; 
			cout <<"Yurutucu Firma: " << projeYurutucuFirma << endl; 
			cout <<"Sorumlu       : " << projeSorumlusu << endl; 
			cout <<"Kontrolor     : " << projeKontroloru << endl; 
		}
		if(arananNo != projeNo)
			DosyaYaz << projeNo << ' ' << projeAdi << ' ' << projeYurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << '\n';
	}
	DosyaOku.close();
	DosyaYaz.close();
	remove("projeler.txt");
	rename("gecici_projeler.txt","projeler.txt");
	if(kontrol == 0){
		cout<<"Proje bulunamadi !" << endl;
	}
}

void ProjeAra(){
	int projeNo,arananNo;
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;

	cout << "Proje No : "; cin >> arananNo;
	ifstream DosyaOku("projeler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> projeNo >> projeAdi >> 
		projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

		if(projeNo == arananNo ){
			kontrol = 1;
			cout << endl <<"----Proje Bilgileri----" << endl;
			cout <<"Proje No      : " << projeNo << endl; 
			cout <<"Proje Adi     : " << projeAdi << endl; 
			cout <<"Yurutucu Firma: " << projeYurutucuFirma << endl; 
			cout <<"Sorumlu       : " << projeSorumlusu << endl; 
			cout <<"Kontrolor     : " << projeKontroloru << endl; 
			DosyaOku.close();
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Proje bulunamadi !" << endl;
	}
}

void ProjeYazdir(int arananNo){
	int projeNo;
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;

	ifstream DosyaOku("projeler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> projeNo >> projeAdi >> 
		projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

		if(projeNo == arananNo ){
			kontrol = 1;
			cout << endl <<"----Proje Bilgileri----" << endl;
			cout <<"Proje No      : " << projeNo << endl; 
			cout <<"Proje Adi     : " << projeAdi << endl; 
			cout <<"Yurutucu Firma: " << projeYurutucuFirma << endl; 
			cout <<"Sorumlu       : " << projeSorumlusu << endl; 
			cout <<"Kontrolor     : " << projeKontroloru << endl; 
			DosyaOku.close();
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Proje bulunamadi !" << endl;
	}
}

int ProjeKontrol(int arananNo){
	int projeNo;
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;
	ifstream DosyaOku("projeler.txt");

	while(!DosyaOku.eof()){
		DosyaOku >> projeNo >> projeAdi >> 
		projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;
		if(projeNo == arananNo ){
			DosyaOku.close();
			return 1;
		}
	}
	DosyaOku.close();
	return 0;
}

void ProjeRaporla(){
	int projeNo,arananNo;
	string projeAdi;
	string projeYurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;

	cout << "Proje No : "; cin >> arananNo;
	ifstream DosyaOku("projeler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> projeNo >> projeAdi >> 
		projeYurutucuFirma >> projeSorumlusu >> projeKontroloru;

		if(projeNo == arananNo ){
			kontrol = 1;
			cout << endl <<"----Proje Bilgileri----" << endl;
			cout <<"Proje No      : " << projeNo << endl; 
			cout <<"Proje Adi     : " << projeAdi << endl; 
			cout <<"Yurutucu Firma: " << projeYurutucuFirma << endl; 
			cout <<"Sorumlu       : " << projeSorumlusu << endl; 
			cout <<"Kontrolor     : " << projeKontroloru << endl; 
			DosyaOku.close();
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Proje bulunamadi !" << endl;
	}
}

void HakedisMenu(){
	cout << "1) Hakedis Ekle" << endl;
	cout << "2) Hakedis Kullanilan Urunler" << endl;
	cout << "3) Hakedis Urun Sil" << endl;
	cout << "4) Hakedis Urun Guncelle" << endl;
	cout << "5) Hakedis Urun Ara" << endl;
	cout << "0) Ust Menu" << endl << endl;
	cout << "Seciminiz : ";

	int secim;
	cin >> secim;
	cout << endl;
	switch(secim){

		case 0:
			return;
			break;

		case 1:
			HakedisEkle();
			break;

		case 2:
			HakedisKullanilanUrunler();
			break;

		case 3:
			HakedisUrunSil();
			break;

		case 4:
			HakedisUrunGuncelle();
			break;

		case 5:
			HakedisUrunAra();
			break;

		default:
			cout << endl << "Hatali secim !" << endl;
			break;
	}
	cout << endl;
	HakedisMenu();
}

void HakedisEkle(){
	int hakedisNo=0;
	int projeNo=0;
	string hakedisDonemi;

	ofstream DosyaYaz;

	char cevap = 'e';
	do{
		while(1){
			cout <<"Hakedis No : "; cin >> hakedisNo;
			if(HakedisKontrol(hakedisNo) == 1)
				cout << "Bu Hakedis No zaten mevcut" << endl;
			else
				break;
		}

		while(1){
			cout <<"Proje No   : "; cin >> projeNo;
			if(ProjeKontrol(projeNo) == 0)
				cout << "Proje bulunamadi !" << endl;
			else
				break;
		}

		cout <<"Hakedis Donemi : "; cin >> hakedisDonemi;

		DosyaYaz.open("hakedisler.txt",ios::app);
		DosyaYaz << hakedisNo << ' ' << projeNo << ' ' << hakedisDonemi << '\n';

		HakedisUrunEkle(hakedisNo);

		cout << "Baska bir hakedis ekleyecek misiniz? [e/h] :"; cin >> cevap;
	}while(cevap == 'e' || cevap == 'E');

	DosyaYaz.close();

	cout <<"Hakedis/ler eklendi." << endl;
}

void HakedisUrunEkle(int hakedisNo){
	int urunNo,arananNo;
	string urunAdi;
	string birim;
	float birimFiyati;
	string marka;
	int urunAdet;

	char cevap = 'e';
	do{
		while(1){
			cout << "Urun No : "; cin >> arananNo;
			ifstream DosyaOku("urunler.txt");

			int kontrol = 0;
			while(!DosyaOku.eof()){
				DosyaOku >> urunNo >> urunAdi >> 
				birim >> birimFiyati >> marka;

				if(arananNo == urunNo){
					kontrol = 1;
					cout << endl <<"----Urun Bilgileri----" << endl;
					cout <<"Urun No      : " << urunNo << endl; 
					cout <<"Urun Adi     : " << urunAdi << endl; 
					cout <<"Urun Birimi  : " << birim << endl; 
					cout <<"Urun Fiyati  : " << birimFiyati << endl; 
					cout <<"Urun Markasi : " << marka << endl; 
					DosyaOku.close();
					break;
				}
			}
			if(kontrol == 0){
				cout<<"Urun bulunamadi !" << endl;
			}
			else{
				cout << "Urun Adet : "; cin >> urunAdet;
				ofstream DosyaYaz;
				DosyaYaz.open("hakedis_urunler.txt",ios::app);
				DosyaYaz << ' ' << hakedisNo << ' ' << urunNo << ' ' << urunAdet << '\n';
				DosyaYaz.close();
				break;
			}
		}
		cout << "Baska bir urun ekleyecek misiniz? [e/h] :"; cin >> cevap;
	}while(cevap == 'e' || cevap == 'E');
}

void HakedisKullanilanUrunler(){
	int hakedisNo=0;

	while(1){
		cout <<"Hakedis No : "; cin >> hakedisNo;
		if(HakedisKontrol(hakedisNo) == 0)
			cout << "Hakedis bulunamadi !" << endl;
		else
			break;
	}
	HakedisYazdir(hakedisNo);

	int urunNo,oncekiUrunNo;
	int urunAdet;

	ifstream DosyaOku("hakedis_urunler.txt");

	cout << endl << "------------Urunler-------------" << endl;
	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> urunNo >> urunAdet;
		if(oncekiUrunNo == urunNo)
			break;
		oncekiUrunNo = urunNo;
		UrunYazdir(urunNo,urunAdet);
	}
	DosyaOku.close();
}

void HakedisSil(){
	int hakedisNo=0,arananNo;
	int projeNo=0;
	string hakedisDonemi;
	cout << "Hakedis No : "; cin >> arananNo;

	ifstream DosyaOku("hakedisler.txt");
	ofstream DosyaYaz;
	DosyaYaz.open("gecici_hakedisler.txt", ios::app);

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> projeNo >> hakedisDonemi;

		if(arananNo == hakedisNo && kontrol == 0){
			kontrol = 1;
			cout << endl <<"----Silinen Hakedis Bilgileri----" << endl;
			cout <<"Hakedis No     : " << hakedisNo << endl; 
			cout <<"Proje No       : " << projeNo << endl; 
			cout <<"Hakedis Donemi : " << hakedisDonemi << endl; 
		}
		if(arananNo != hakedisNo)
			DosyaYaz << hakedisNo << ' ' << projeNo << ' ' << hakedisDonemi << '\n';
	}
	DosyaOku.close();
	DosyaYaz.close();
	remove("hakedisler.txt");
	rename("gecici_hakedisler.txt","hakedisler.txt");
	if(kontrol == 0){
		cout<<"Hakedis bulunamadi !" << endl;
	}
}

void HakedisUrunSil(){
	int hakedisNo=0;
	int urunNo,arananNo;
	int urunAdet;

	while(1){
		cout <<"Hakedis No : "; cin >> hakedisNo;
		if(HakedisKontrol(hakedisNo) == 0)
			cout << "Hakedis bulunamadi !" << endl;
		else
			break;
	}
	cout << "Urun No : "; cin >> arananNo;
	ifstream DosyaOku("hakedis_urunler.txt");

	ofstream DosyaYaz;
	DosyaYaz.open("gecici_hakedis_urunler.txt", ios::app);

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> urunNo >> urunAdet;

		if(arananNo == urunNo && kontrol == 0){
			kontrol = 1;
			cout << endl <<"----Silinen Urun Bilgileri----" << endl;
			UrunYazdir(urunNo,urunAdet);
		}
		if(arananNo != urunNo)
			DosyaYaz << hakedisNo << ' ' << urunNo << ' ' << urunAdet << '\n';
	}
	DosyaOku.close();
	DosyaYaz.close();
	remove("hakedis_urunler.txt");
	rename("gecici_hakedis_urunler.txt","hakedis_urunler.txt");
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}

void HakedisUrunGuncelle(){
	int hakedisNo=0;
	int urunNo,arananNo;
	int urunAdet,yeniAdet;

	while(1){
		cout <<"Hakedis No : "; cin >> hakedisNo;
		if(HakedisKontrol(hakedisNo) == 0)
			cout << "Hakedis bulunamadi !" << endl;
		else
			break;
	}
	cout << "Urun No : "; cin >> arananNo;
	ifstream DosyaOku("hakedis_urunler.txt");

	ofstream DosyaYaz;
	DosyaYaz.open("gecici_hakedis_urunler.txt", ios::app);

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> urunNo >> urunAdet;

		if(arananNo == urunNo && kontrol == 0){
			kontrol = 1;
			cout << endl <<"----Guncellenecek Urun Bilgileri----" << endl;
			UrunYazdir(urunNo,urunAdet);
			cout << "Urun Adet : "; cin >> yeniAdet;
			DosyaYaz << hakedisNo << ' ' << urunNo << ' ' << yeniAdet << '\n';
		}
		if(arananNo != urunNo)
			DosyaYaz << hakedisNo << ' ' << urunNo << ' ' << urunAdet << '\n';
	}
	DosyaOku.close();
	DosyaYaz.close();
	remove("hakedis_urunler.txt");
	rename("gecici_hakedis_urunler.txt","hakedis_urunler.txt");
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}


void HakedisYazdir(int arananNo){
	int hakedisNo=0;
	int projeNo=0;
	string hakedisDonemi;

	ifstream DosyaOku("hakedisler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> projeNo >> hakedisDonemi;

		if(hakedisNo == arananNo ){
			kontrol = 1;
			cout << endl <<"----Hakedis Bilgileri----" << endl;
			cout <<"Hakedis No     : " << hakedisNo << endl; 
			cout <<"Proje No       : " << projeNo << endl; 
			cout <<"Hakedis Donemi : " << hakedisDonemi << endl; 
			DosyaOku.close();
			ProjeYazdir(projeNo);
			break;
		}
	}
	if(kontrol == 0){
		cout<<"Hakedis bulunamadi !" << endl;
	}
}

void HakedisUrunAra(){
	int hakedisNo=0;
	int urunNo,arananNo;
	int urunAdet;

	while(1){
		cout <<"Hakedis No : "; cin >> hakedisNo;
		if(HakedisKontrol(hakedisNo) == 0)
			cout << "Hakedis bulunamadi !" << endl;
		else
			break;
	}
	cout << "Urun No : "; cin >> arananNo;
	ifstream DosyaOku("hakedis_urunler.txt");

	int kontrol = 0;
	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> urunNo >> urunAdet;

		if(arananNo == urunNo && kontrol == 0){
			kontrol = 1;
			cout << endl <<"----Urun Bilgileri----" << endl;
			UrunYazdir(urunNo,urunAdet);
		}
	}
	DosyaOku.close();
	if(kontrol == 0){
		cout<<"Urun bulunamadi !" << endl;
	}
}

int HakedisKontrol(int arananNo){
	int hakedisNo;
	int projeNo;
	string hakedisDonemi;

	ifstream DosyaOku("hakedisler.txt");

	while(!DosyaOku.eof()){
		DosyaOku >> hakedisNo >> projeNo >> 
		hakedisDonemi;
		if(projeNo == arananNo ){
			DosyaOku.close();
			return 1;
		}
	}
	DosyaOku.close();
	return 0;
}


