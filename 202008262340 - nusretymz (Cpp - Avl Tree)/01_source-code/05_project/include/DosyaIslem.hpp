/**
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Öğrencinin Adı Soyadı
*/


#include "Agac.hpp"

void DosyaOkuma(){
 	Dugum *ilk = NULL;  
    ifstream DosyaOku("Kisiler.txt");

    string adi;
    string sdogum;
    string skilo;

    while(!DosyaOku.eof())
    {
        getline(DosyaOku,adi,'#');
        getline(DosyaOku,sdogum,'#');
        getline(DosyaOku,skilo,'\n');
        int dogumTarihi = stoi(sdogum);
        int kilosu = stoi(skilo);	
        ilk = DugumEkle(ilk, OlusturKisi(adi,dogumTarihi,kilosu));
    }
    DosyaOku.close();

    Sirala(ilk);   
} 