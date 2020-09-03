#include <iostream>
using namespace std;

//OzelIslem sinifinin tanimlanmasi
class OzelIslem
{
	//sinif disindan sadece get ve set ile erisilebilinen degerler
	private:
		int sayi1;
		int sayi2;
		int sayi3;
	
	//fonksiyonlarin public, disarindan erisilebilir yapilmasi
	public:
		//kapsulleme
		int getSayi1(){
			return sayi1;
		}
		//kapsulleme
		void setSayi1(int value){
			sayi1 = value;	
		}
		//kapsulleme
		int getSayi2(){
			return sayi2;
		}
		//kapsulleme
		void setSayi2(int value){
			sayi2 = value;	
		}
		//kapsulleme
		int getSayi3(){
			return sayi3;
		}
		//kapsulleme
		void setSayi3(int value){
			sayi3 = value;	
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Ekok(int sayi1,int sayi2){
			// Ýki sayýnýn EKOK'u bulunurken EKOK en fazla yine ikisinin çarpýmý olabilir.
			for(int i=1; i<=sayi1*sayi2; i++) {
				if( (i%sayi1==0) && (i%sayi2==0) ){
					return i;
					break;
				}
			}
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Ekok(int sayi1,int sayi2,int sayi3){
			//Halihazirda varolan iki sayinin ekokunu bulan fonksiyon icice kullanilarak
			//once ilk iki sayi ardindan ilk iki sayinin sonucu ile ucuncu sayinin ekoku
			//hesaplanarak sonuc elde ediliyor
			return Ekok(Ekok(sayi1,sayi2),sayi3);
		}
		
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Ebob(int sayi1,int sayi2){
			// Ýki sayýnýn EBOB'u bulunurken EBOB en fazla büyük sayý olabilir.
			int buyukSayi;
			if(sayi1>sayi2) {
				buyukSayi = sayi1;
			} else {
				buyukSayi = sayi2;
			}
			
			for(buyukSayi; buyukSayi>0; buyukSayi--) {
				if( (sayi1%buyukSayi==0) && (sayi2%buyukSayi==0) ) {
					return buyukSayi;
					break;
				}
			}
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Ebob(int sayi1,int sayi2,int sayi3){
			//Halihazirda varolan iki sayinin ebobunu bulan fonksiyon icice kullanilarak
			//once ilk iki sayi ardindan ilk iki sayinin sonucu ile ucuncu sayinin ebobu
			//hesaplanarak sonuc elde ediliyor
			return Ebob(Ebob(sayi1,sayi2),sayi3);
		}
		
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Faktoriyel(int sayi1){
			//Faktoriyel isleminde capim isleminde sonucun 0 olmamasi icin sonuc degiskeni
			//baslangic olarak 1  yani caprimda etkisiz elemana esitlenir, sonrasinda dongu
			//ile belirlenen sayiya kadar olan tum sayilar carpilir
			int i,sonuc = 1;
			for(i=2; i<=sayi1; i++){
				sonuc *= i;
			}
			return sonuc;
		}
		
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int UsAlma(int sayi1,int sayi2){
			//us alma isleminde carpimda etkisiz elaman olan 1 sonuc degiskenin ilk degeri olarak atanir
			//bir dongu ile us adedine kadar girilir ve her adimda ussu alinacak sayi carpilir
			int i, sonuc = 1;
			for(i=0; i<sayi2; i++){
				sonuc *= sayi1;
			}
			return sonuc;
		}
			
};

//DortIslem sinifinin tanimlanmasi
class DortIslem
{
	//sinif disindan sadece get ve set ile erisilebilinen degerler
	private:
		int sayi1;
		int sayi2;
		int sayi3;
	//fonksiyonlarin public, disarindan erisilebilir yapilmasi
	public:
		//kapsulleme
		int getSayi1(){
			return sayi1;
		}
		//kapsulleme
		void setSayi1(int value){
			sayi1 = value;	
		}
		//kapsulleme
		int getSayi2(){
			return sayi2;
		}
		//kapsulleme
		void setSayi2(int value){
			sayi2 = value;	
		}
		//kapsulleme
		int getSayi3(){
			return sayi3;
		}
		//kapsulleme
		void setSayi3(int value){
			sayi3 = value;	
		}
		
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Topla(int sayi1,int sayi2){
			//geriye parametre olarak gelen sayilarin toplami donduruluyor
			return sayi1+sayi2;
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Topla(int sayi1,int sayi2,int sayi3){
			//geriye parametre olarak gelen sayilarin toplami donduruluyor
			return sayi1+sayi2+sayi3;
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Cikar(int sayi1,int sayi2){
			//geriye parametre olarak gelen sayilarin farki donduruluyor
			return sayi1-sayi2;
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Cikar(int sayi1,int sayi2,int sayi3){
			//geriye parametre olarak gelen sayilarin farki donduruluyor
			return sayi1-sayi2-sayi3;
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Carp(int sayi1,int sayi2){
			//geriye parametre olarak gelen sayilarin carpimi donduruluyor
			return sayi1*sayi2;
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Carp(int sayi1,int sayi2,int sayi3){
			//geriye parametre olarak gelen sayilarin carpimi donduruluyor
			return sayi1*sayi2*sayi3;
		}
		//ilgili fonksiyonun tanimlanmasi ve alacagi parametrelerin belirlenmesi
		int Bol(int sayi1,int sayi2){
			//geriye parametre olarak gelen sayilarin bolumu donduruluyor
			return sayi1/sayi2;
		}
};

//Islemler sinifinin tanimlanmasi ve DortIslem,OzelIslem siniflarindan kalitim yapilmasi
class Islemler: public DortIslem, public OzelIslem{};

//Menu fonksiyonu prototipi
void Menu();

//main fonksiyonu
int main(void){
	Menu();
}

//Menu olusturulmasi icin fonksiyon tanimi
void Menu(){
	//Islemler sinindan islem adinda bir nesne tanimlanmasi
	Islemler islem;
	//seceneklerin ekrana bastirilmasi
	cout << "1-EKOK (En Kucuk Ortak Kat)" << endl;
	cout << "2-EBOB (En Kucuk Ortak Kat)" << endl;
	cout << "3-Faktoriyel Hesabi" << endl;
	cout << "4-Us Alma" << endl;
	cout << "5-Toplama" << endl;
	cout << "6-Cikarma" << endl;
	cout << "7-Carpma" << endl;
	cout << "8-Bolme" << endl << endl;
	cout << "Secim : ";
	//secimin bir tamsayi degiskene atanmasi
	int sec;
	cin >> sec;

	cout << endl;
	//parametre olarak kullanilacak sayilarin tanimlanmasi
	int sayi1,sayi2,sayi3;
	//adet bilgisini tutacak degiskenin tanimlanmasi
	int adet;
	
	//secim yapisinin olusuturlmasi
	switch(sec){
		//her durumun islemlerinin belirlenmesi
		case 1:
			cout << endl << "Sayi adedi [2,3] (2 veya 3 degilse 2 kabul edilir): ";
			cin >> adet;
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			//girilecek sayi adedinin 3 olma durumu
			if(adet == 3){
				cout << "Sayi3 : ";
				cin >> sayi3;
				//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
				cout << endl << "Ekok : " << islem.Ekok(sayi1,sayi2,sayi3) << endl;
				break;
			}
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Ekok : " << islem.Ekok(sayi1,sayi2) << endl;
			break;
		case 2:
			cout << endl << "Sayi adedi [2,3] (2 veya 3 degilse 2 kabul edilir): ";
			cin >> adet;
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			if(adet == 3){
				cout << "Sayi3 : ";
				cin >> sayi3;
				//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
				cout << endl << "Ebob : " << islem.Ebob(sayi1,sayi2,sayi3) << endl;
				break;
			}
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Ebob : " << islem.Ebob(sayi1,sayi2) << endl;
			break;
		case 3:
			cout << "Sayi : ";
			cin >> sayi1;
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Faktoriyel : " << islem.Faktoriyel(sayi1) << endl;
			break;
		case 4:
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Us Alma : " << islem.UsAlma(sayi1,sayi2) << endl;
			break;
		case 5:
			cout << endl << "Sayi adedi [2,3] (2 veya 3 degilse 2 kabul edilir): ";
			cin >> adet;
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			if(adet == 3){
				cout << "Sayi3 : ";
				cin >> sayi3;
				//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
				cout << endl << "Toplama : " << islem.Topla(sayi1,sayi2,sayi3) << endl;
				break;
			}
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Toplama : " << islem.Topla(sayi1,sayi2) << endl;
			break;
			break;
		case 6:
			cout << endl << "Sayi adedi [2,3] (2 veya 3 degilse 2 kabul edilir): ";
			cin >> adet;
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			if(adet == 3){
				cout << "Sayi3 : ";
				cin >> sayi3;
				//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
				cout << endl << "Cikarma : " << islem.Cikar(sayi1,sayi2,sayi3) << endl;
				break;
			}
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Cikarma : " << islem.Cikar(sayi1,sayi2) << endl;
			break;
		case 7:
		   	cout << endl << "Sayi adedi [2,3] (2 veya 3 degilse 2 kabul edilir): ";
			cin >> adet;
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			if(adet == 3){
				cout << "Sayi3 : ";
				cin >> sayi3;
				//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
				cout << endl << "Carpma : " << islem.Carp(sayi1,sayi2,sayi3) << endl;
				break;
			}
			cout << endl << "Carpma : " << islem.Carp(sayi1,sayi2) << endl;
			break;
		case 8:
			cout << "Sayi1 : ";
			cin >> sayi1;
			cout << "Sayi2 : ";
			cin >> sayi2;
			//ekrana bastirma sirasinde islem nesnesinden ilgili fonksiyonun cagrilmasi ve sonucunun yazdirilmasi
			cout << endl << "Bolme : " << islem.Bol(sayi1,sayi2) << endl;
			break;
		default:
			cout << endl << "Yanlis secim yaptiniz." << endl << endl;
	}
	
	
	cout << endl;
	//Devam etme durumu icin char turunde bir degisken olusturulmasi ve kullanicidan ilgili degerin alinmasi
	cout << "Devam etmek istiyor musunuz? [E/H] : ";
	char devam;
	
	cin >> devam;
	
	if(devam == 'H'){
		cout << "Cikiliyor..." << endl;
		exit(0);
	}
	
	if(devam != 'E'){
		cout << "Farkli bir deger girildi Evet olarak kabul edilip devam ediliyor..." << endl;
	}
	cout << endl;
	Menu();
}










