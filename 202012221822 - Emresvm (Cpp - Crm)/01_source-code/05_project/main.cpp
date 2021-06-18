#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <locale.h>

#define DOSYA "hesap.txt"

using namespace std;

class Musteri
{
private:
public:
    string tcNo;
    string ad;
    string soyad;
    float borc;
    float alacak;
    float bakiye;
    Musteri(string _tcNo, string _ad, string _soyad, float _borc, float _alacak, float _bakiye);
    ~Musteri();
};

Musteri::Musteri(string _tcNo, string _ad, string _soyad, float _borc, float _alacak, float _bakiye)
{
    this->tcNo = _tcNo;
    this->ad = _ad;
    this->soyad = _soyad;
    this->borc = _borc;
    this->alacak = _alacak;
    this->bakiye = _bakiye;
}

Musteri::~Musteri() {}

vector<Musteri> musteriler;

void Listele();
void Ekle();
void Sil();
void Guncelle();
void Ara(string aranan);
void toplamBakiye();
void dosyaOku();
void dosyaYaz();
void Menu();

void Yazdir(Musteri musteri);

int main()
{

	setlocale(LC_ALL,"Turkish");
    dosyaOku();
    Menu();
}

void dosyaOku()
{
    fstream dosya(DOSYA);
    string satir, tcNo, ad, soyad;
    float borc, alacak, bakiye;

    musteriler.clear();
    while (dosya >> tcNo >> ad >> soyad >> borc >> alacak >> bakiye)
    {
            Musteri musteri = Musteri(tcNo, ad, soyad, borc, alacak, bakiye);
            musteriler.push_back(musteri);
        
    }
}

void dosyaYaz()
{
    ofstream dosya(DOSYA);

    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {

        dosya << (*itr).tcNo << " " << (*itr).ad << " " << (*itr).soyad << " " << (*itr).borc << " " << (*itr).alacak << " " << (*itr).bakiye << endl;
    }
}

void Menu()
{
    cout << "1) Listele" << endl;
    cout << "2) Ekle" << endl;
    cout << "3) Sil" << endl;
    cout << "4) G�ncelle" << endl;
    cout << "5) Ara" << endl;
    cout << "6) Toplam Bakiye" << endl;
    cout << endl
         << "0) Program� Sonland�r" << endl;
    cout << endl
         << "Se�iminiz : ";
    int secim;
    cin >> secim;
    string aranacak;
    switch (secim)
    {

    case 0:
        cout << endl
             << "Programdan kapat�l�yor..." << endl;
        exit(0);
        break;
    case 1:
        Listele();
        break;
    case 2:
        Ekle();
        break;
    case 3:
        Sil();
        break;
    case 4:
        Guncelle();
        break;
    case 5:
        cout << endl
             << "M��TER� ARAMA >> " << endl;
        cout << "Ara (TC,Ad,Soyad) : ";

        cin >> aranacak;
        Ara(aranacak);
        break;
    case 6:
        toplamBakiye();
        break;

    default:
        cout << endl
             << "Hatal� Se�im !" << endl;
        break;
    }
    cout << endl;
    Menu();
}

void Yazdir(Musteri musteri)
{
    cout << musteri.tcNo << " " << musteri.ad << " " << musteri.soyad << " " << musteri.borc << " " << musteri.alacak << " " << musteri.bakiye << endl;
}

void Listele()
{
    fstream dosya(DOSYA);
    string satir, tcNo, ad, soyad;
    float borc, alacak, bakiye;

    musteriler.clear();
   while (dosya >> tcNo >> ad >> soyad >> borc >> alacak >> bakiye)
    {
            Musteri musteri = Musteri(tcNo, ad, soyad, borc, alacak, bakiye);
            musteriler.push_back(musteri);
        
    }
    cout << endl
         << "M��TER� L�STELE" << endl;
    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {
        Yazdir(*itr);
    }
}

void Ekle()
{
    string tcNo, ad, soyad;
    float borc, alacak, bakiye;

    cout << endl
         << "M��TER� EKLE" << endl;
    cout << "Tc No : ";
    cin >> tcNo;

    cout << "Ad : ";
    cin >> ad;

    cout << "Soyad : ";
    cin >> soyad;

    cout << "Bor� : ";
    cin >> borc;

    cout << "Alacak : ";
    cin >> alacak;

    bakiye = borc - alacak;

    musteriler.push_back(Musteri(tcNo, ad, soyad, borc, alacak, bakiye));
    dosyaYaz();
    cout << endl
         << "M��teri Eklendi." << endl;
}

void Sil()
{
    cout << endl
         << "M��TER� S�L >> " << endl;
    int i = 1;
    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {
        cout << i << ") " << (*itr).tcNo << " " << (*itr).ad << " " << (*itr).soyad << " " << (*itr).borc << " " << (*itr).alacak << " " << (*itr).bakiye << endl;
        i++;
    }
    cout << endl
         << "Silinecek M��teri No : ";
    int silinecek;
    cin >> silinecek;
    i = 1;
    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {
        if (i == silinecek)
        {
            musteriler.erase(itr);
            break;
        }
        i++;
    }
    dosyaYaz();
    cout << endl
         << "M��teri silindi." << endl;
}

void Guncelle()
{
    cout << endl
         << "M��TER� G�NCELLE >> " << endl;
    int i = 1;
    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {
        cout << i << ") " << (*itr).tcNo << " " << (*itr).ad << " " << (*itr).soyad << " " << (*itr).borc << " " << (*itr).alacak << " " << (*itr).bakiye << endl;
        i++;
    }
    cout << endl
         << "G�ncellenecek M��teri No : ";
    int guncellenecek;
    cin >> guncellenecek;

    string tcNo, ad, soyad;
    float borc, alacak, bakiye;

    cout << "Tc No : ";
    cin >> tcNo;

    cout << "Ad : ";
    cin >> ad;

    cout << "Soyad : ";
    cin >> soyad;

    cout << "Bor� : ";
    cin >> borc;

    cout << "Alacak : ";
    cin >> alacak;

    bakiye = borc - alacak;
    musteriler.at(guncellenecek - 1) = Musteri(tcNo, ad, soyad, borc, alacak, bakiye);

    dosyaYaz();
    cout << endl
         << "M��teri güncellendi." << endl;
}

void Ara(string aranan)
{

    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {
        if ((*itr).ad == aranan || (*itr).soyad == aranan || (*itr).tcNo == aranan)
        {
            Yazdir(*itr);
            return;
        }
    }
    cout << endl
         << "Aranan de�er bulunamad� !." << endl;
}

void toplamBakiye()
{
    cout << endl
         << "M��TER�LER�N TOPLAM BAK�YES� >> " << endl;
    float bakiyeToplam = 0;
    for (vector<Musteri>::iterator itr = musteriler.begin(); itr != musteriler.end(); itr++)
    {
        bakiyeToplam += (*itr).bakiye;
    }
    cout << endl
         << "Bakiye : " << bakiyeToplam << " TL' dir." << endl;
}
