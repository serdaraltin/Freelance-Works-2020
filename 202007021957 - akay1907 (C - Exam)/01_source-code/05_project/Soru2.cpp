#include <iostream>
#include <time.h>

using namespace std;

//Seçerek sıralama sırasında yerleri değiştirilecek olunan değerler için fonksiyon tanımı
void YerDegistir(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
//verilen dizi ve o dizinin boyutuna göre "Seçerek Sıralama algoritması" ile diziyi sıralayan fonksiyon 
void selectionSort(int dizi[], int boyut)  
{  
    int i, j, kucuk;  
  	
  	//dizinin sonunda gelene dek dizideki "tek indisli elemanları "birbirleri ile karşılaştırma ve ilgili koşul sağlanırsa yer değiştirme
    for (i = 1; i < boyut-1; i+=2)  
    {  
        kucuk = i;  
        for (j = i+2; j < boyut; j++)  
        if (dizi[j] < dizi[kucuk])  
            kucuk = j;  
        YerDegistir(&dizi[kucuk], &dizi[i]);  
    }  
}  

//Sokarak sırlama algoritması ile diziyi siralayan fonksiyon
void insertionSort(int dizi[], int boyut)  
{  
    int i, buyuk, j;  

    //dizinin sonunda gelene dek dizideki "çift indisli elemanları "birbirleri ile karşılaştırma ve ilgili koşul sağlanırsa yer değiştirme
    for (i = 0; i < boyut; i+=2) 
    {  
        buyuk = dizi[i];  
        j = i - 2;  
        while (j >= 0 && dizi[j] < buyuk) 
        {  
            dizi[j + 2] = dizi[j];  
            j = j - 2;  
        }  
        dizi[j + 2] = buyuk;  
    }  
}  

//ana fonksiyon
int main(){
	//srand fonksiyonu o anki zaman değeri ile besleniyor (epoch) böylelikle benzersiz değerler üretiliyor
	srand(time(NULL));

	//ilgili değişkenlerin tanımlanması
	int i,j,dizi[100],enKucuk=1,enBuyuk=1000;

	//0 dan başlanıp 100 e kadar giden döngü
	for(i=0; i<100; i++){
		//dizinin o anki elemanına rand fonksiyonu ile 1-1000 arasında değer atanması (rastgele)
		dizi[i] = enKucuk + rand() % (enBuyuk - enKucuk);
	}
	//seçerek sıralama algoritması ile dizideki tek indisli elemanların sıralanması
	selectionSort(dizi,100);
	//sokarak sıralama algoritması ile dizideki çift indisli elemanların sıralanması
	insertionSort(dizi,100);

	//0 dan başlanıp 100 e kadar giden döngü
	for(i=0; i<100; i++){
		//o anki indis değeri çift ise
		if(i%2==0)
			cout << "  [" << i << "] -> "<< dizi[i] << "\n";
		//o anki indis değeri tek ise
		else
			cout << "[" << i << "] -> "<< dizi[i] << "\n";
	}

} 
