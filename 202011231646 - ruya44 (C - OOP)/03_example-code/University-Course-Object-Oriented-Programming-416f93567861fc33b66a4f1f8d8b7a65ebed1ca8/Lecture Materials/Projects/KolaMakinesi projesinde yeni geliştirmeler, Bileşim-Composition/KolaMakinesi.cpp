#include "KolaMakinesi.h"
#include <iostream>
using namespace std;

KolaMakinesi::KolaMakinesi(KAYITTURU kayit):hata(kayit)
{
	fiyat = 0;
	sayi = 0;
	cout << "KolaMakinesi Constructor" << endl;
}


KolaMakinesi::KolaMakinesi(float p, int s, KAYITTURU kayit)
	:hata(kayit)
{
	ilkYukleme(p, s);
}


KolaMakinesi::~KolaMakinesi()
{
	std::cout << "KolaMakinesi Destructor" << std::endl;
}

void KolaMakinesi::ilkYukleme(float fiyati,int kolaSayisi)
{
	fiyat = fiyati;
	sayi = kolaSayisi;
}

void KolaMakinesi::kolaVerme()
{
	float ode;

	cout << "Kolanin Fiyati :" << fiyat << " lira" << endl;
	cout << "Odemeniz : ";
	cin >> ode;

	hata.kaydet("odeme yapildi...");

	if (ode >= fiyat) {
		if (sayi > 0) {
			sayi--;
			cout << "Kolaniz veriliyor..." << endl;
			cout << "Para ustu: " << (ode - fiyat) << endl;
		}
		else {
			cout << "Kola yok, paraniz geri alin." << endl;
		}
	}
	else {
		cout << "Eksik para, paranizi geri alin..." << endl;
	}
}

void KolaMakinesi::goster() const
{
	cout << "Kolanin Fiyati: " << fiyat << " lira" << endl;
	cout << "Kalan Kola Sayisi: " << sayi << " adet" << endl;
}
