#include <iostream>
using namespace std;

class KolaMakinesi{
public:
    void ilkYukleme(float fiyati, int kolaSayisi);
    void kolaVerme();
    void goster();
private:
    float fiyat;
    int sayi;
};

void KolaMakinesi::ilkYukleme(float price, int amountCola){
    if(price<0)
        fiyat = 1;
    else
        fiyat = price;
    
    if(amountCola<0)
        sayi=0;
    else
        sayi = amountCola;
}

void KolaMakinesi::kolaVerme(){
    float ode;
    
    cout<<"Kolanın fiyatı:\t"<<fiyat<<"lira"<<endl;
    cout<<"Odemeniz:\t";
    cin>>ode;
    
    if(ode>=fiyat){
        if(sayi>0){
            sayi--;
            cout<<"Kolanız veriliyor!\n";
            cout<<"Para üstü:\t"<<ode-fiyat<<" lira!\n";
        }
        else
            cout<<"Kola yok, paranızı geri alınız!\n";
    }
    else {
        cout<<"Eksik para, paranızı geri alınız!\n";
    }
}

void KolaMakinesi::goster(){
    cout<<"Kola fiyatı: "<<fiyat<<" lira\n";
    cout<<"Kalan kola sayısı: "<<sayi<<endl;
}

int main (){
    
    KolaMakinesi makine;
    makine.ilkYukleme(1.5, 30);
    makine.goster();
    makine.kolaVerme();
    makine.goster();
    
    return 0;
    
}

/*
 
 class point {
 int x=3;
 int y=4;
 public:
 int z=10;
 void print (){
 cout<<x<<" "<<y<<endl;
 }
 };
 
 point p1;
 p1.print();
 //  p1.x = 5;           // point sınıfının x değişkeni "private" olarak tanımlanmış.
 cout<<p1.z<<endl;       // point sınıfının z değişkeni "public" olarak tanımlanmış, diğer fonksiyonlardan ona erişebilirsin.

 */
