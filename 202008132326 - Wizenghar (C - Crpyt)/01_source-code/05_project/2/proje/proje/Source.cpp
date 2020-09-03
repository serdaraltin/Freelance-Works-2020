/****************************************************************************
**						  SAKARYA ÜNÝVERSÝTESÝ
**				BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**					  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**						PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**			      ÖDEV NUMARASI......:
**				  ÖÐRENCÝ ADI........:
**				  ÖÐRENCÝ NUMARASI...:
**				  DERS GRUBU.........:
****************************************************************************/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void UrunEkle() {
	int UrunNo;
	string UrunAdi, UrunBirimi, UrunMarkasi;
	float UrunFiyati;
	char EvetHayir = 'e';
	ofstream yazDosyaUrun;
	yazDosyaUrun.open("urunler.txt", ios::app);

	do {
		cout << "Urun No    : ";
		cin >> UrunNo;
		cout << "Urun Ad    : ";
		cin >> UrunAdi;
		cout << "Urun Marka : ";
		cin >> UrunMarkasi;
		cout << "Urun Birim : ";
		cin >> UrunBirimi;
		cout << "Urun Fiyat : ";
		cin >> UrunFiyati;

		yazDosyaUrun << UrunNo << ' ' << UrunAdi << ' ' << UrunMarkasi << ' ' << UrunBirimi << ' ' << UrunFiyati << '\n';

		cout << "baska bir urun ekleyecek misiniz?(e/h) ";
		cin >> EvetHayir;
	} while (!(EvetHayir == 'h'));

	yazDosyaUrun.close();
	cout << "dosyaya yazim tamamlandi." << endl;
}
void UrunSil() {
	int UrunNo;
	string UrunAdi, UrunBirimi, UrunMarkasi;
	float UrunFiyati;
	int aranan = 0;

	cout << "Aranan No : "; cin >> aranan;
	ifstream okuDosyaUrun("urunler.txt");
	ofstream yazDosyaUrun;
	yazDosyaUrun.open("Urun_yeni.txt", ios::app);
	int kontrol = 0;
	while (!okuDosyaUrun.eof()) {
		okuDosyaUrun >> UrunNo >> UrunAdi >> UrunMarkasi >> UrunBirimi >> UrunFiyati;
		if (aranan == UrunNo) {
			if (kontrol == 0) {
				kontrol = 1;
				cout << "Silindi.";
				cout << endl;
			}
		}
		else
			yazDosyaUrun << UrunNo << ' ' << UrunAdi << ' ' << UrunMarkasi << ' ' << UrunBirimi << ' ' << UrunFiyati << '\n';
	}
	remove("urunler.txt");
	rename("Urun_yeni.txt", "urunler.txt");
	okuDosyaUrun.close();
	yazDosyaUrun.close();

	if (kontrol == 0) {
		cout << "Bulunamadi !" << endl;
	}
}
void UrunAra() {
	int UrunNo;
	string UrunAdi, UrunBirimi, UrunMarkasi;
	float UrunFiyati;
	int aranan = 0;

	cout << "Aranan No : "; cin >> aranan;
	ifstream okuDosyaUrun("urunler.txt");
	int kontrol = 0;
	while (!okuDosyaUrun.eof()) {
		okuDosyaUrun >> UrunNo >> UrunAdi >> UrunMarkasi >> UrunBirimi >> UrunFiyati;
		if (kontrol == 0 && aranan == UrunNo) {
			kontrol = 1;
			cout << endl;
			cout << "Urun No    : " <<
				UrunNo << endl;
			cout << "Urun Ad    : " <<
				UrunAdi << endl;
			cout << "Urun Marka : " <<
				UrunMarkasi << endl;
			cout << "Urun Birim : " <<
				UrunBirimi << endl;
			cout << "Urun Fiyat : " <<
				UrunFiyati << " TL" << endl;
			cout << endl;
			okuDosyaUrun.close();
			break;
		}
	}
	if (kontrol == 0) {
		cout << "Bulunamadi !" << endl;
	}
}
void Urun() {
	int Secilen;

	cout << "1) Urun ekle" <<
		endl;
	cout << "2) Urun sil" <<
		endl;
	cout << "3) Urun ara" <<
		endl;
	cout << "Secim : ";
	cin >> Secilen;

	if (Secilen == 1) {
		UrunEkle();
	}
	else if (Secilen == 2) {
		UrunSil();
	}
	else if (Secilen == 3) {
		UrunAra();
	}
	else {
		return;
	}
}

void ProjeEkle() {
	int ProjeNo;
	string ProjeAdi, YurutucuFirma, Sorumlu, Kontrolor;

	char EvetHayir = 'e';
	ofstream yazDosyaProje;
	yazDosyaProje.open("projeler.txt", ios::app);

	do {
		cout << "Proje No         : ";
		cin >> ProjeNo;
		cout << "Proje Adi        : ";
		cin >> ProjeAdi;
		cout << "Yurutucu Firma   : ";
		cin >> YurutucuFirma;
		cout << "Proje Sorumlusu  : ";
		cin >> Sorumlu;
		cout << "Proje Kontroloru : ";
		cin >> Kontrolor;

		yazDosyaProje << ProjeNo << ' ' << ProjeAdi << ' ' << YurutucuFirma << ' ' << Sorumlu << ' ' << Kontrolor << '\n';

		cout << "baska bir urun ekleyecek misiniz?(e/h) ";
		cin >> EvetHayir;
	} while (!(EvetHayir == 'h'));

	yazDosyaProje.close();
	cout << "dosyaya yazim tamamlandi." << endl;
}
void ProjeSil() {
	int ProjeNo;
	int aranan = 0;
	string ProjeAdi, YurutucuFirma, Sorumlu, Kontrolor;

	cout << "Aranan No : "; cin >> aranan;
	ifstream okuDosyaProje("projeler.txt");
	ofstream yazDosyaProje;
	yazDosyaProje.open("projeler_yeni.txt", ios::app);
	int kontrol = 0;
	while (!okuDosyaProje.eof()) {
		okuDosyaProje >> ProjeNo >> ProjeAdi >> YurutucuFirma >> Sorumlu >> Kontrolor;

		if (aranan == ProjeNo) {
			if (kontrol == 0) {
				kontrol = 1;
				cout << "Silindi.";
				cout << endl;
			}
		}
		else
			yazDosyaProje << ProjeNo << ' ' << ProjeAdi << ' ' << YurutucuFirma << ' ' << Sorumlu << ' ' << Kontrolor << '\n';

	}
	remove("projeler.txt");
	rename("projeler_yeni.txt", "projeler.txt");
	okuDosyaProje.close();
	yazDosyaProje.close();

	if (kontrol == 0) {
		cout << "Bulunamadi !" << endl;
	}
}
void ProjeAra() {
	int ProjeNo;
	int aranan = 0;
	string ProjeAdi, YurutucuFirma, Sorumlu, Kontrolor;

	cout << "Aranan No : "; cin >> aranan;
	ifstream okuDosyaProje("projeler.txt");
	int kontrol = 0;
	while (!okuDosyaProje.eof()) {
		okuDosyaProje >> ProjeNo >> ProjeAdi >> YurutucuFirma >> Sorumlu >> Kontrolor;

		if (kontrol == 0 && aranan == ProjeNo) {
			kontrol = 1;
			cout << "Proje No         : " <<
				ProjeNo << endl;
			cout << "Proje Adi        : " <<
				ProjeAdi << endl;
			cout << "Yurutucu Firma   : " <<
				YurutucuFirma << endl;
			cout << "Proje Sorumlusu  : " <<
				Sorumlu << endl;
			cout << "Proje Kontroloru : " <<
				Kontrolor << endl;
			okuDosyaProje.close();
			break;
		}
	}
	if (kontrol == 0) {
		cout << "Bulunamadi !" << endl;
	}
}

void Proje() {
	int Secilen;
	cout << "1) Proje ekle" <<
		endl;
	cout << "2) Proje sil" <<
		endl;
	cout << "3) Proje ara" <<
		endl;
	cout << "Secim : ";
	cin >> Secilen;

	if (Secilen == 1) {
		ProjeEkle();
	}
	else if (Secilen == 2) {
		ProjeSil();
	}
	else if (Secilen == 3) {
		ProjeAra();
	}
	else {
		return;
	}
}

void HakedisEkle() {
	int UrunNo, HakedisNo, ProjeNo;
	string UrunAdi, UrunBirimi, UrunMarkasi, hakedisDonem;
	float UrunFiyati;
	char EvetHayir = 'e';

	ofstream DosyaYaz;
	DosyaYaz.open("hakedisler.txt", ios::app);

	do {
		cout << "Hakedis No    : ";
		cin >> HakedisNo;
		cout << "Proje No      : ";
		cin >> ProjeNo;
		cout << "Hakedis Donem : ";
		cin >> hakedisDonem;

		DosyaYaz << HakedisNo << ' ' << ProjeNo << ' ' << hakedisDonem << '\n';

		char baskaUrunEkle = 'e';
		ofstream DosyaYazSatilan;
		DosyaYazSatilan.open("satilan_urunler.txt", ios::app);

		do {
			int UrunAdet = 0;
			cout << "Urun No   : ";
			cin >> UrunNo;
			cout << "Urun Adet : ";
			cin >> UrunAdet;

			DosyaYazSatilan << HakedisNo << ' ' << UrunNo << ' ' << UrunAdet << '\n';
			cout << "baska bir urun ekleyecek misiniz?(e/h) "; cin >> baskaUrunEkle;
		} while (!(baskaUrunEkle == 'h'));

		DosyaYazSatilan.close();
		cout << "baska bir hakedis ekleyecek misiniz?(e/h) ";
		cin >> EvetHayir;
	} while (!(EvetHayir == 'h'));
	DosyaYaz.close();

	cout << "dosyaya yazim tamamlandi." << endl;
}
void HakedisUrunler() {
	int UrunNo, HakedisNo, ProjeNo;
	string ProjeAdi, YurutucuFirma, Sorumlu, Kontrolor;
	string UrunAdi, UrunBirimi, UrunMarkasi, hakedisDonem;
	float UrunFiyati;
	int arananProjeNo = 0, aranan = 0;
	ProjeNo = -1;
	HakedisNo = -1;
	char EvetHayir = 'e';

	cout << "Aranan No : "; cin >> aranan;
	ifstream okuDosyaHakedis("hakedisler.txt");
	int var = 0;
	while (!okuDosyaHakedis.eof()) {
		okuDosyaHakedis >> HakedisNo >> ProjeNo >> hakedisDonem;
		if (var == 0 && aranan == ProjeNo) {
			var = 1;
			cout << endl;
			cout << "Hakedis No : " <<
				HakedisNo << endl;
			cout << "Proje No : " <<
				ProjeNo << endl;
			cout << "Hakedis Donem : " <<
				hakedisDonem << endl << endl;
			cout << endl;
			arananProjeNo = ProjeNo;
			aranan = HakedisNo;
			okuDosyaHakedis.close();
			break;
		}
	}
	if (var == 0) {
		cout << "Bulunamadi !" << endl;
		return;
	}
	ifstream okuDosyaProje("projeler.txt");
	var = 0;
	while (!okuDosyaProje.eof()) {
		okuDosyaProje >> ProjeNo >> ProjeAdi >> YurutucuFirma >> Sorumlu >> Kontrolor;
		if (var == 0 && arananProjeNo == ProjeNo) {
			var = 1;
			cout << endl;
			cout << "Proje Adi        : " <<
				ProjeAdi << endl;
			cout << "Yurutucu Firma   : " <<
				YurutucuFirma << endl;
			cout << "Proje Sorumlusu  : " <<
				Sorumlu << endl;
			cout << "Proje Kontroloru : " <<
				Kontrolor << endl;
			cout << endl;
			okuDosyaProje.close();
			break;
		}
	}
	ifstream okuDosyaSatilanUrun("satilan_urunler.txt");
	int oncekiUrunNo = 0, UrunAdet = 0;
	while (!okuDosyaSatilanUrun.eof()) {
		okuDosyaSatilanUrun >> HakedisNo >> UrunNo >> UrunAdet;
		if (aranan == HakedisNo && oncekiUrunNo != UrunNo) {

			int arananUNo = UrunNo;
			ifstream okuDosyaUrun("urunler.txt");

			while (!okuDosyaUrun.eof()) {
				okuDosyaUrun >> UrunNo >> UrunAdi >> UrunMarkasi >> UrunBirimi >> UrunFiyati;
				if (arananUNo == UrunNo) {
					cout << "Urun No    : " <<
						UrunNo << endl;
					cout << "Urun Ad    : " <<
						UrunAdi << endl;
					cout << "Urun Marka : " <<
						UrunMarkasi << endl;
					cout << "Urun Fiyat : " <<
						UrunFiyati << endl;
					cout << "Urun Adet  : " <<
						UrunAdet << endl;
					cout << "Tutar      : " <<
						(UrunAdet*UrunFiyati) << " TL" << endl << endl;
					okuDosyaUrun.close();
					break;
				}
			}

			oncekiUrunNo = UrunNo;
		}
	}
	okuDosyaHakedis.close();
	okuDosyaProje.close();
	okuDosyaSatilanUrun.close();
}
void HakedisUrunSil() {
	int UrunNo, HakedisNo, ProjeNo;
	int arananUNo = 0, aranan = 0, UrunAdet = 0;
	UrunNo = -1;

	cout << "Aranan No : "; cin >> aranan;
	cout << "Aranan Urun No : "; cin >> arananUNo;

	ifstream okuDosyaHakedis("satilan_urunler.txt");
	ofstream DosyaYaz;
	DosyaYaz.open("satilan_urunler_yeni.txt", ios::app);

	int var = 0, oncekiUrunNo = 0;
	while (!okuDosyaHakedis.eof()) {
		okuDosyaHakedis >> HakedisNo >> UrunNo >> UrunAdet;
		if (arananUNo == UrunNo && aranan == HakedisNo) {
			var = 1;
		}
		if (UrunNo != arananUNo && oncekiUrunNo != UrunNo) {
			DosyaYaz << HakedisNo << ' ' << UrunNo << ' ' << UrunAdet << '\n';
		}
		oncekiUrunNo = UrunNo;
	}

	okuDosyaHakedis.close();
	DosyaYaz.close();
	remove("satilan_urunler.txt");
	rename("satilan_urunler_yeni.txt", "satilan_urunler.txt");

	if (var == 0)
		cout << "Bulunamadi !" << endl;
	else
		cout << "dosya yazma tamamlandi." << endl;

}
void HakedisUrunGuncelle() {
	int UrunNo, HakedisNo, ProjeNo;
	int arananUNo = 0, aranan = 0, UrunAdet = 0;
	UrunNo = -1;

	cout << "Aranan No : "; cin >> aranan;
	cout << "Aranan Urun No : "; cin >> arananUNo;

	ifstream okuDosyaSatilanUrunler("satilan_urunler.txt");
	ofstream yazDosyaSatilanUrunler;
	yazDosyaSatilanUrunler.open("satilan_urunler_yeni.txt", ios::app);

	int var = 0, oncekiUrunNo = 0;
	while (!okuDosyaSatilanUrunler.eof()) {
		okuDosyaSatilanUrunler >> HakedisNo >> UrunNo >> UrunAdet;

		if (arananUNo == UrunNo && aranan == HakedisNo) {
			if (var == 0) {
				var = 1;
				cout << "Yeni Urun Adet : ";
				cin >> UrunAdet;
			}
		}
		if (oncekiUrunNo != UrunNo) {
			yazDosyaSatilanUrunler << HakedisNo << ' ' << UrunNo << ' ' << UrunAdet << '\n';
		}

		oncekiUrunNo = UrunNo;
	}

	okuDosyaSatilanUrunler.close();
	yazDosyaSatilanUrunler.close();
	remove("satilan_urunler.txt");
	rename("satilan_urunler_yeni.txt", "satilan_urunler.txt");

	if (var == 0)
		cout << "Bulunamadi !" << endl;
	else
		cout << "dosya yazma tamamlandi." << endl;
}

void Hakedis() {
	int Secilen;
	cout << "1) Hakedis ekle" << endl;
	cout << "2) Hakedis urunler" << endl;
	cout << "3) Hakedis urun sil" << endl;
	cout << "4) Hakedis urun guncelle" << endl;
	cout << "Secim : ";
	cin >> Secilen;

	if (Secilen == 1) {
		HakedisEkle();
	}
	else if (Secilen == 2) {
		HakedisUrunler();
	}
	else if (Secilen == 3) {
		HakedisUrunSil();
	}
	else if (Secilen == 4) {
		HakedisUrunGuncelle();
	}
	else {
		return;
	}
}

int main(int argc, char *argv[]) {
	int Secilen;

	while (1) {

		cout << endl << "Ne yapmak istiyorsunuz ? " << endl;
		cout << "1) Urun islem" << endl;
		cout << "2) Proje islem" << endl;
		cout << "3) Hakedis islem" << endl;
		cout << "4) Programdan cikis" << endl;
		cout << "Secim : ";
		cin >> Secilen;

		if (Secilen == 1) {
			Urun();
		}
		if (Secilen == 2) {
			Proje();
		}
		if (Secilen == 3) {
			Hakedis();
		}
		if (Secilen == 4 || (Secilen <1 || Secilen > 5)) {
			exit(0);
		}
	}

	return 0;
}

