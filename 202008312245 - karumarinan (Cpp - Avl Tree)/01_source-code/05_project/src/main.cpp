//ilgili kütüphaneler
#include <iostream> 
#include <stack> 
#include <fstream>
#include "dugum.hpp"
//isim uzayı
using namespace std;
//iki sayıdan büyük olanını bulan method
int buyukDeger(int a, int b)  {  
	if(a > b)
		return a;
	return b; 
}  
//yeni düğüm ekleyen method
Dugum* yeniDugum(Kisi* kisiBilgisi)  {  
    Dugum* node = new Dugum(); 
    node-> kisiBilgisi =  kisiBilgisi;  
    node->solu = NULL;  
    node->sagi = NULL;  
    node->yukseklikDegeri = 1; 
    node->stak.push("O");
    return(node);  
}  
//düğümün yükseklik değerini veren method
int yukseklikDegeri(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return N->yukseklikDegeri;  
} 
//düğümü sağa ilerleten method
Dugum *saga(Dugum *y){  
    //yer değişimlerinin yapılması
    Dugum *x = y->solu;  
    Dugum *T2 = x->sagi;  
    x->sagi = y;  
    y->stak.push("A");
    x->stak.push("Y");
    y->solu = T2; 
    y->yukseklikDegeri = buyukDeger(yukseklikDegeri(y->solu), yukseklikDegeri(y->sagi)) + 1;  
    x->yukseklikDegeri = buyukDeger(yukseklikDegeri(x->solu), yukseklikDegeri(x->sagi)) + 1;  
    return x;  
}  
//doğum tarihinden yaşı bulan method
int yasDegeri(Kisi *kisiBilgisi){
    return (2020-kisiBilgisi->kisiDogumu);
} 
//düğümü post order olarak sıralayan method
void siralama(Dugum *kokDugumu){  
    if(kokDugumu != NULL)  {  
    	siralama(kokDugumu->solu);  
        siralama(kokDugumu->sagi);  
        cout << kokDugumu->kisiBilgisi->kisiAdi << ", " << kokDugumu->kisiBilgisi->kisiDogumu << ", " << kokDugumu->kisiBilgisi->kisiKilosu;
        cout << " \tYigit: ";

        while (!kokDugumu->stak.empty()){ 
	        cout << kokDugumu->stak.top() << " "; 
	        kokDugumu->stak.pop(); 
	    } 
	    cout << endl;
    }  
}  
//düğümü sola ilerleten method
Dugum *sola(Dugum *x){  
    //yer değişimlerinin yapılması
    Dugum *y = x->sagi;  
    Dugum *T2 = y->solu;  
    y->solu = x;  
    x->sagi = T2;  
    x->yukseklikDegeri = buyukDeger(yukseklikDegeri(x->solu), yukseklikDegeri(x->sagi)) + 1;  
    y->yukseklikDegeri = buyukDeger(yukseklikDegeri(y->solu), yukseklikDegeri(y->sagi)) + 1;     
    return y;  
}
//düğümün denge durumunu veren method  
int dengeDurumu(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return yukseklikDegeri(N->solu) - yukseklikDegeri(N->sagi);  
}  
//yeni kişi oluşturan method
Kisi *eklemeKisi(string _ad, int _dogum, int _kilo){
	Kisi *yeniOlusturulan = new Kisi();
	yeniOlusturulan->kisiAdi = _ad;
	yeniOlusturulan->kisiDogumu = _dogum;
	yeniOlusturulan->kisiKilosu = _kilo;
	return (yeniOlusturulan);
}
//düğüme eleman ekleyen method
Dugum* ekleme(Dugum* node, Kisi* kisiBilgisi){  
    //düğüm boş ise
    if (node == NULL)  {
    	Dugum * yeniOlusturulan = yeniDugum(kisiBilgisi);
        return(yeniOlusturulan);  
    }
    //yas değeri mevcut düğümden küçük ise
    if (yasDegeri(kisiBilgisi) < yasDegeri(node->kisiBilgisi))
        node->solu = ekleme(node->solu, kisiBilgisi); 
    //yas değeri mevcut düğümden büyük ise 
    else if (yasDegeri(kisiBilgisi) > yasDegeri(node->kisiBilgisi))
        node->sagi = ekleme(node->sagi, kisiBilgisi);  
    //yas değeri mevcut düğümdekine eşit ise
    else if (yasDegeri(kisiBilgisi) == yasDegeri(node->kisiBilgisi))
       node->solu = ekleme(node->solu, kisiBilgisi);  
    //yukarıdakilerin hiçbiri değil ise
    else
        return node;
    //denge durumu -1 ise
    if(dengeDurumu(node) == -1)
      node->stak.push("D");
    //mevcut düğümün yükseklik değerini değiştirilmesi
    node->yukseklikDegeri = 1 + buyukDeger(yukseklikDegeri(node->solu), yukseklikDegeri(node->sagi));  
    int dengeDegeri = dengeDurumu(node);
    //  denge değeri 1 ve yas değeri düğümün solunun yaş değerinden küçük ise
    if (dengeDegeri > 1 && yasDegeri(kisiBilgisi) < yasDegeri(node->solu->kisiBilgisi)){
        node->stak.push("A");
        return saga(node);  
    }
    //  denge değeri -1 ve yas değeri düğümün sağının yaş değerinden büyük ise
    if (dengeDegeri < -1 && yasDegeri(kisiBilgisi) > yasDegeri(node->sagi->kisiBilgisi)){
        node->stak.push("A");
        return sola(node);  
    }
    //  denge değeri 1 ve yas değeri düğümün solunun yaş değerinden büyük ise
    if (dengeDegeri > 1 && yasDegeri(kisiBilgisi) > yasDegeri(node->solu->kisiBilgisi)){ 
        node->stak.push("Y");
        node->solu = sola(node->solu);  
        return saga(node);  
    }  
    //  denge değeri -1 ve yas değeri düğümün sağının yaş değerinden küçük ise
    if (dengeDegeri < -1 && yasDegeri(kisiBilgisi) < yasDegeri(node->sagi->kisiBilgisi)){  
        node->stak.push("A");
    	node->sagi = saga(node->sagi); 
        return sola(node);  
    } 
    //dğümün geriye döndürülmesi 
    return node;  
}  
//dosya okuma işlemlerini yapan method
void dosyaOkuma(){
    //başlangıç düğümü
 	Dugum *kokDugumu = NULL;  
     //dosya okuma için dosya belirlenmesi
    ifstream dosya("Kisiler.txt");
    //geçici değer barındıran değişkenler
    string kisiAdi;
    string _dogum;
    string _kilo;
    //dosyanın sonuna dek okuma
    while(!dosya.eof())
    {
        //ilgili değerlerin atanması
        getline(dosya,kisiAdi,'#'); 
        getline(dosya,_dogum,'#');
        getline(dosya,_kilo,'\n');
        //çevrimler
        int kisiDogumu = stoi(_dogum);
        int kisiKilosu = stoi(_kilo);	
        //kok düğümüne yeni kişinin eklenmesi
        kokDugumu = ekleme(kokDugumu, eklemeKisi(kisiAdi,kisiDogumu,kisiKilosu));
    }
    //dosyanın kapatılması
    dosya.close();
    //kok düğümünün sıralanması
    siralama(kokDugumu);   
} 
//ana method
int main(){
    //dosyaOkuma methodunun çağrılması
    dosyaOkuma();
}