//Eklenen kutuphaneler
#include <iostream>
#include <string.h>

using namespace std;

//alisveris listesi boyutu icin onislemci komutu
#define BOYUT 50

//gorev bilgileri icin struct
struct gorev
{
	char aciklama[50];
	int durum;
	char adet[20];
};
typedef gorev gorev;

//alisveris bilgieri icin struct
struct salisveris
{
	char alisverisAdi[BOYUT];
	struct gorev items[20];
	int itemCount;
};
typedef salisveris alStruct;

//alisveris listelerinin tutuldugu dizi tanimlamasi
alStruct alisverisListeleri[BOYUT];
int listeSayisi = 0;


//fonksiyon prototipleri
void AnaMenu();
void GorevSil(int alisverisListesiNumarasi,int itemNo);
int  ListeVarlikKontrol(char alisverisAdi[]);
void AlisverisListesiOlustur();
void TumListeler();
void GorevDuzenle(int alisverisListesiNumarasi,int itemNo);
void GorevDurumunuDegistir(int alisverisListesiNumarasi,int itemNo);
void ListeyiYazdir(int alisverisListesiNumarasi);
void AlisverisMenu(int alisverisListesiNumarasi);
void GorevEkle(int alisverisListesiNumarasi);


//ana fonksiyon
int main(){
	AnaMenu();
} 

void AlisverisListesiOlustur(){
	//liste boyutu kontrolu
	if(listeSayisi == BOYUT){
		cout << "Listede bos yer yok!"<< endl;
		return;
	}
	//ilgili bilgilerin kullanicidan alinmasi
	cout << "Alisveris Listesi Adi : ";
	char alisverisAdi[BOYUT];
	cin >> alisverisAdi;
	//listenin daha onceden var olup olmadıgı kontrolu
	if(ListeVarlikKontrol(alisverisAdi) == 1){
		cout <<  alisverisAdi << " bu isimde zaten bir liste var" << endl ;
		cout << alisverisAdi << " bu isimde zaten bir liste var"<< endl;
		AlisverisListesiOlustur();
		return;
	}
	//ilgili verilerin alanlara atanmasi
	strcpy(alisverisListeleri[listeSayisi].alisverisAdi,alisverisAdi);
	//yeni bir liste olusturulduktan sonra eleman sayisinin sifir yapilmasi
	alisverisListeleri[listeSayisi++].itemCount = 0;
	return;
}

//ana menu
void AnaMenu(){
	cout << "1. Alisveris Listesi Olustur" << endl;
	cout << "2. Tum Alisveris Listelerini Goruntule" << endl;
	cout << endl << "Seciminiz : ";
	int sec;
	cin >>sec;
	cout << endl;
	//switch-case yapısı ile secim kontrolu
	switch(sec){
		case 1:
			AlisverisListesiOlustur();
			break;
		case 2:
			TumListeler();
			break;
		default:
			cout <<"Hatali secim yaptiniz"<< endl;
			break;
	}
	cout << endl;
	AnaMenu();
}


int ListeVarlikKontrol(char alisverisAdi[]){
	//0. indexten baslanip son index degerine kadar gidilerek parametre olarak gelen liste adi kontrolü yapılıyor
	int i;
	for(i=0; i<BOYUT; i++)
		if(strcmp(alisverisListeleri[i].alisverisAdi,alisverisAdi) == 0)
			return 1;
	return -1;
}

void GorevEkle(int alisverisListesiNumarasi){
	//listenin eleman boyutu kontrolü
	if(alisverisListeleri[alisverisListesiNumarasi].itemCount == 20){
		cout <<"Listede bos yer yok!"<< endl;
		return;
	}
	//secilen listedeki eleman sayisinin alimasi ve bir degiskene atanmasi
	int count = alisverisListeleri[alisverisListesiNumarasi].itemCount;
	cout <<"Aciklama : ";
	char aciklama[50];
	cin >> aciklama;
	cout << "Adet : ";
	char adet[20];
	cin >> adet;
	//ilgili verilerin ilgili alanlara atanmasi
	strcpy(alisverisListeleri[alisverisListesiNumarasi].items[count].aciklama,aciklama);
	strcpy(alisverisListeleri[alisverisListesiNumarasi].items[count].adet,adet);
	alisverisListeleri[alisverisListesiNumarasi].items[count].durum = 0;
	//listeye eleman eklendikten sonra eleman sayisinin arttirilmasi
	alisverisListeleri[alisverisListesiNumarasi].itemCount++;
	return;
}

void AlisverisMenu(int alisverisListesiNumarasi){
	cout << endl;
	//secilen listenin adinin yazdirilmasi
	cout << ">>>> "<< alisverisListeleri[alisverisListesiNumarasi].alisverisAdi << " <<<<" << endl << endl;

	cout << "1. Gorev Ekle"<<endl;
	cout << "2. Gorev Duzenle"<<endl;
	cout << "3. Gorev Sil"<<endl;
	cout << "4. Gorev Durumunu Degistir"<<endl;
	cout << "5. Gorevleri Listele"<<endl;
	cout << "6. Ana Menuye Don"<<endl;
	cout << endl << "Seciminiz : ";
	int sec;
	cin >> sec;
	cout << endl;
	//switch-case yapisi ile secim kontrolu
	switch(sec){
		case 1:
		//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
			GorevEkle(alisverisListesiNumarasi);
			break;
		case 2:
		//listedeki tum verilerin yazdirilmasi
			ListeyiYazdir(alisverisListesiNumarasi);
			cout << endl <<"Seciminiz : ";
			int editNo;
			cin >> editNo;
			if(!(editNo >=0 && editNo <= 20)){
				cout <<"Gecersiz bir deger girdiniz!" << endl; 
				//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
				AlisverisMenu(alisverisListesiNumarasi);
				return;
			}
			cout << endl;
			//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
			GorevDuzenle(alisverisListesiNumarasi,editNo);
			break;
		case 3:
			ListeyiYazdir(alisverisListesiNumarasi);
			cout << endl <<"Seciminiz : ";
			int delNo;
			cin >> delNo;
			if(!(delNo >=0 && delNo <= 20)){
				cout <<"Gecersiz bir deger girdiniz!" << endl; 
				//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
				AlisverisMenu(alisverisListesiNumarasi);
				return;
			}
			cout << endl;
			//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
			GorevSil(alisverisListesiNumarasi,delNo);
			break;
		case 4:
			//listedeki tum verilerin yazdirilmasi
			ListeyiYazdir(alisverisListesiNumarasi);
			cout << endl <<"Seciminiz : ";
			int markNo;
			cin >> markNo;
			if(!(markNo >=0 && markNo <= 20)){
				cout <<"Gecersiz bir deger girdiniz!" << endl; 
				AlisverisMenu(alisverisListesiNumarasi);
				return;
			}
			cout << endl;
			//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
			GorevDurumunuDegistir(alisverisListesiNumarasi,markNo);
			break;
		case 5:
		//listedeki tum verilerin yazdirilmasi
			ListeyiYazdir(alisverisListesiNumarasi);
			break;
		case 6:
			AnaMenu();
			break;
		default:
			cout << "Tekrar deneyiniz" << endl;
			break;
	}
	//ilgili fonksiyonun cagrilmasi ve parametrelerin verilmesi
	AlisverisMenu(alisverisListesiNumarasi);
}
void GorevSil(int alisverisListesiNumarasi,int itemNo){
	//ilgili numaradaki gorevin silindi olarak isaretlenmesi
	sprintf(alisverisListeleri[alisverisListesiNumarasi].items[itemNo].aciklama,"%s","Silindi");
	alisverisListeleri[alisverisListesiNumarasi].items[itemNo].durum = 0;
}
void TumListeler(){
	//listenin bos olma durumunun kontrolü
	if(listeSayisi == 0){
		cout <<"Liste tamamen bos"<< endl;
		return;
	}
	cout << "No\tShopping List Name" << endl;
	cout << "-------------------------------------" << endl;
	//listenin var olma durumu kontrolu
	int i;
	for (i = 0; i < BOYUT; i++)
		if(strcmp(alisverisListeleri[i].alisverisAdi,"") != 0)
			cout <<i<<"\t"<<alisverisListeleri[i].alisverisAdi << endl;

	//liste secimi
	cout << endl << "Seciminiz : ";
	int sec;
	cin >> sec;
	if(sec >= 0 && sec <= 50){
		AlisverisMenu(sec);
		return;
	}
	cout << "Gecersiz bir deger girdiniz!!!!" << endl;
	TumListeler();
	return;
}
void GorevDuzenle(int alisverisListesiNumarasi,int itemNo){
	//ilgili gorevin varlik kontroly
	if(strcmp(alisverisListeleri[alisverisListesiNumarasi].items[itemNo].aciklama,"") == 0){
		cout <<"Alan bos"<< endl;
		return;
	}
	cout <<"Aciklama : ";
	char aciklama[50];
	cin >>aciklama;
	cout << "Adet : ";
	char adet[20];
	cin >> adet;
	//ilgili goreve yeni veri atanmasi
	sprintf(alisverisListeleri[alisverisListesiNumarasi].items[itemNo].aciklama,"%s",aciklama);
	sprintf(alisverisListeleri[alisverisListesiNumarasi].items[itemNo].adet,"%s",adet);
}

void ListeyiYazdir(int alisverisListesiNumarasi){
	//listedeki gorevlerin belirtilen bicimde ard arda yazdirilmasi
	cout << "Numara\tDurum\t\tAciklama\tAdet"<< endl;
	cout <<"-------------------------------------------"<< endl;
	int i;
	for (i = 0; i < 20; ++i){
		if(strcmp(alisverisListeleri[alisverisListesiNumarasi].items[i].aciklama,"") != 0){
			cout <<i<<"\t";
			//o anki gorevin tamamlanmasi durumunda bastirilacak metin
			if(alisverisListeleri[alisverisListesiNumarasi].items[i].durum == 1)
				cout <<"Tamam\t\t";
			else
				//o anki gorevin tamamlanmamasi durumunda bastirilacak metin
				cout <<"Bekliyor\t";
			cout <<alisverisListeleri[alisverisListesiNumarasi].items[i].aciklama<< "\t\t";
			cout <<alisverisListeleri[alisverisListesiNumarasi].items[i].adet<<endl;
		}
	}
}
void GorevDurumunuDegistir(int alisverisListesiNumarasi,int itemNo){
	//secilen gorevin tamam/bekliyor seklinde isaretlenmesi
	cout <<"Gorev Durumunu [Tamam=1 / Bekliyor=0] : ";
	int durum;
	cin >> durum;
	alisverisListeleri[alisverisListesiNumarasi].items[itemNo].durum = durum;
}