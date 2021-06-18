/**
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Öğrencinin Adı Soyadı
*/


#include <iostream> 
#include <stack> 
#include <fstream>
#include "Buyuk.hpp"

using namespace std;

class Kisi{
	public:
	string adi;
	int dogumTarihi;
	int kilosu;
};

class Dugum{  
    public: 
    Kisi *kisi;  
    stack <string> yig; 
    Dugum *sol;  
    Dugum *sag;  
    int derinlik;  
};  

int derinlik(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return N->derinlik;  
}  

Dugum* OlusturDugum(Kisi* kisi)  {  
    Dugum* dugum = new Dugum(); 
    dugum-> kisi =  kisi;  
    dugum->sol = NULL;  
    dugum->sag = NULL;  
    dugum->derinlik = 1; 
    dugum->yig.push("O");
    return(dugum);  
}  

Dugum *GitSag(Dugum *y){  
	
    Dugum *x = y->sol;  
    Dugum *T2 = x->sag;  
    x->sag = y;  
    y->sol = T2;  
    y->derinlik = max(derinlik(y->sol), derinlik(y->sag)) + 1;  
    x->derinlik = max(derinlik(x->sol), derinlik(x->sag)) + 1;  
    return x;  
}  

Dugum *GitSol(Dugum *x){  
    Dugum *y = x->sag;  
    Dugum *T2 = y->sol;  
    y->sol = x;  
    x->sag = T2;  
    x->derinlik = max(derinlik(x->sol), derinlik(x->sag)) + 1;  
    x->yig.push("A");
    y->derinlik = max(derinlik(y->sol), derinlik(y->sag)) + 1;  
 	y->yig.push("Y");
    return y;  
}  
  
int Denge(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return derinlik(N->sol) - derinlik(N->sag);  
}  
int YasDegeri(Kisi *kisi){
    return (2020-kisi->dogumTarihi);
}   

Dugum* DugumEkle(Dugum* dugum, Kisi* kisi){  
	
    if (dugum == NULL)  {
    	Dugum * yeni = OlusturDugum(kisi);
        return(yeni);  
    }
    if (YasDegeri(kisi) < YasDegeri(dugum->kisi)){
    	dugum->yig.push("D");
    	dugum->sag->yig.push("D");
        dugum->sol = DugumEkle(dugum->sol, kisi);  

    }	
    else if (YasDegeri(kisi) > YasDegeri(dugum->kisi))
        dugum->sag = DugumEkle(dugum->sag, kisi);  
    else
        return dugum;  
    
 		
    dugum->derinlik = 1 + max(derinlik(dugum->sol), derinlik(dugum->sag));  
    int balance = Denge(dugum);  
    if (balance > 1 && YasDegeri(kisi) < YasDegeri(dugum->sol->kisi))
        return GitSag(dugum);  
    if (balance < -1 && YasDegeri(kisi) > YasDegeri(dugum->sag->kisi)){
    	dugum->yig.push("D");
        return GitSol(dugum);  
    }
    if (balance < -1 && YasDegeri(kisi) < YasDegeri(dugum->sag->kisi)){  
    	dugum->sag = GitSag(dugum->sag); 
        return GitSol(dugum);  
    }  
     if (balance > 1 && YasDegeri(kisi) > YasDegeri(dugum->sol->kisi)){ 
        dugum->sol = GitSol(dugum->sol);  
        return GitSag(dugum);  
    }  

    return dugum;  
}  

void Sirala(Dugum *baslangic){  
    if(baslangic != NULL)  {  
    	Sirala(baslangic->sol);  
        Sirala(baslangic->sag);  

        cout << baslangic->kisi->adi << ", " << baslangic->kisi->dogumTarihi << ", " << baslangic->kisi->kilosu;
        cout << "   Yigit: ";

        while (!baslangic->yig.empty()) 
	    { 
	        cout << baslangic->yig.top() << " "; 
	        baslangic->yig.pop(); 
	    } 
	    cout << endl;
    }  
}  

Kisi *OlusturKisi(string _ad, int _dogum, int _kilo){
	Kisi *yeni = new Kisi();
	yeni->adi = _ad;
	yeni->dogumTarihi = _dogum;
	yeni->kilosu = _kilo;
	return (yeni);
} 

