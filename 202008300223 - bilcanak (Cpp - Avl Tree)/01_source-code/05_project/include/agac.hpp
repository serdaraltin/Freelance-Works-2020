#include <iostream> 
#include <stack> 
#include <fstream>
#include "insan.hpp"
#include "denge.hpp"
#include "yazdir.hpp"

using namespace std;
//parametre olarak gelen değerin içinnde bulunduğu yeni bir düğümü oluşturup geriye döndüren 
Dugum* yeniDugum(Insan* insan)  {  
    Dugum* dugum = new Dugum(); 
    dugum-> insan =  insan;  
    dugum->dugumSol = NULL;  
    dugum->dugumSag = NULL;  
    dugum->yukseklik = 1; 
    dugum->cSt.push("O");
    return(dugum);  
}  
//parametre olarak gelen insan yapısındaki yas verisinden 2020 yılına göre yaşının hesaplanıp geri döndürülmesi
int yas(Insan *insan){
    int deliv = insan->yas;
    int res = 2020 - deliv;
    return res;
} 
//parametre olarak gelen iki değerden büyüğünün bulup geriye döndüren 
int buyukOlan(int i, int j)  {  
	if(i != j){
		if(i > j){
			return i;
		}
		else{
			return j;
		}
		return i;
	}
	return 0; 
}  
//parametre olarak gelen düğümden belirtilen konuma ilerleyen
Dugum *ilerleSag(Dugum *y){  
    Dugum *x = y->dugumSol;  
    Dugum *T2 = x->dugumSag;  
    x->dugumSag = y;  
    y->dugumSol = T2;  
    y->yukseklik = buyukOlan(yukseklik(y->dugumSol), yukseklik(y->dugumSag)) + 1;  
    x->yukseklik = buyukOlan(yukseklik(x->dugumSol), yukseklik(x->dugumSag)) + 1;  
    return x;  
}  
//parametre olarak gelen düğümden belirtilen konuma ilerleyen
Dugum *ilerleSol(Dugum *x){  
    Dugum *y = x->dugumSag;  
    Dugum *T2 = y->dugumSol;  
    y->dugumSol = x;  
    x->dugumSag = T2;  
    x->yukseklik = buyukOlan(yukseklik(x->dugumSol), yukseklik(x->dugumSag)) + 1;  
    x->cSt.push("A");
    y->yukseklik = buyukOlan(yukseklik(y->dugumSol), yukseklik(y->dugumSag)) + 1;  
 	y->cSt.push("Y");
    return y;  
}  
//parametre olarak gelen düğüme, parametre olarak gelen insan yapısının eklenmesi
Dugum* ekleDugum(Dugum* dugum, Insan* insan){  
    //yeni bir düğümün oluşturulması sıfırdan
    if (dugum == NULL)  {
    	Dugum * yeni = yeniDugum(insan);
        return(yeni);  
    }
    //yas değerinin mevcut düğüm ile kıyası
    if (yas(insan) < yas(dugum->insan)){
    	dugum->cSt.push("D");
    	dugum->dugumSag->cSt.push("D");
        dugum->dugumSol = ekleDugum(dugum->dugumSol, insan);  
    }	
    //yas değerinin mevcut düğüm ile kıyası
    else if (yas(insan) > yas(dugum->insan)){
        dugum->dugumSag = ekleDugum(dugum->dugumSag, insan);  
    }
    else{
        return dugum;  
    }
    //mevcut düğümün yüksekliğinin değiştirilmesi
    dugum->yukseklik = 1 + buyukOlan(yukseklik(dugum->dugumSol), yukseklik(dugum->dugumSag));  
    //mevcut düğümün denge durumunun alınması
    int poise = dengeDurumu(dugum);  
    //yas değerinin mevcut düğüm ile kıyası ve denge değerinin 1 den büyük olması
    if (poise > 1 && yas(insan) < yas(dugum->dugumSol->insan)){
        return ilerleSag(dugum);  
    }
    //yas değerinin mevcut düğüm ile kıyası ve denge değerinin -1 den küçük olması
    if (poise < -1 && yas(insan) > yas(dugum->dugumSag->insan)){
    	dugum->cSt.push("D");
        return ilerleSol(dugum);  
    }
    //yas değerinin mevcut düğüm ile kıyası ve denge değerinin 1 den büyük olması
    if (poise > 1 && yas(insan) > yas(dugum->dugumSol->insan)){ 
        dugum->dugumSol = ilerleSol(dugum->dugumSol);  
        return ilerleSag(dugum);  
    }  
    //yas değerinin mevcut düğüm ile kıyası ve denge değerinin -1 den küçük olması
    if (poise < -1 && yas(insan) < yas(dugum->dugumSag->insan)){  
    	dugum->dugumSag = ilerleSag(dugum->dugumSag); 
        return ilerleSol(dugum);  
    }  
    return dugum;  
}  
//parametre olarak gelen değerlerden yeni bir insan oluşturulması
Insan *yeniInsan(string _ad, int _dogum, int _kilo){
	Insan *yeni = new Insan();
	yeni->isim = _ad;
	yeni->yas = _dogum;
	yeni->agirlik = _kilo;
	return (yeni);
} 

