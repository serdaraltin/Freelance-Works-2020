#include "agac.hpp"
//dosyadan okuma ve okuma aşamasında veriyi parçalara ayırma ardından ağaca ekleme ve listeleme
void dosyaOku(string dosyaYol){
    ifstream dosyaYolu(dosyaYol);
    Dugum *kok = NULL;
    while(!dosyaYolu.eof())
    {
        //parçalama ardından verilerin geçici olarak atanması için değişkenler
        string isim,adogum,aagirlik;
        //ilk parça
        getline(dosyaYolu,isim,'#');
        //ikinci parça
        getline(dosyaYolu,adogum,'#');
        int yas = stoi(adogum);
        //son parça
        getline(dosyaYolu,aagirlik,'\n');
        int agirlik = stoi(aagirlik);	
        //kok düğümüne okunan verinin eklenmesi
        kok = ekleDugum(kok, yeniInsan(isim,yas,agirlik));
    }
    dosyaYolu.close(); 
    //post order yöntemi ile ağacın yazdırılması
    yazdirAgac(kok);   
    free(kok);
} 