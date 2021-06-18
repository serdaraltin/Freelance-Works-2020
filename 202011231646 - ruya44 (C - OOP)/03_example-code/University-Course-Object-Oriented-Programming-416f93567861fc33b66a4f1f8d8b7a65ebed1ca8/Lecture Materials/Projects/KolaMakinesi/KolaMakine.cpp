#include <iostream>
#include "KolaMakine.h"

using namespace std;

void KolaMakinesi::ilkYukleme(float fiyati,int kolasayisi)
{
	fiyat = fiyati;
	sayi = kolasayisi;
}

void KolaMakinesi::kolaVerme()
{
	float ode;

	cout<<"Kolanin Fiyati"<<fiyat<<" lira"<<endl;
	cout<<"Odemeniz: ";
	cin>>ode;

	if(ode>=fiyat){
		if(sayi>0){
			sayi--;
			cout<<"Kolaniz veriliyor..."<<endl;
			cout<<"Para ustu: "<<(ode-fiyat)<<endl;
		}
		else{
			cout<<"Kola yok, paranizi geri aliniz..."<<endl;
		}
	}
	else{
		cout<<"Eksik para, paranizi geri alin."<<endl;
	}
}

void KolaMakinesi::goster()
{
	cout<<"Kolanin Fiyati"<<fiyat<<" lira"<<endl;
	cout<<"Kalan Kola Sayisi: "<<sayi<<endl;
}
