//ilgili kütüphanelerin eklenmesi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

//liste için düğüm yapısının oluşturulması
struct Dugum { 
    int veri; 
    struct Dugum *sonraki; 
    struct Dugum *onceki; 
}; 

//parametre olarak gelen sayının düğümün başına eklenmesi
void EkleBasa(struct Dugum** baslangic, int deger) { 
    
    struct Dugum *enSon = (*baslangic)->onceki; 
  
    struct Dugum* yeniDugum = new Dugum; 
    yeniDugum->veri = deger;  
    yeniDugum->sonraki = *baslangic; 
    yeniDugum->onceki = enSon; 
  
    enSon->sonraki = (*baslangic)->onceki = yeniDugum; 

    *baslangic = yeniDugum; 
} 
  
//parametre olarak gelen sayının yine parametre olarak gelen sayının ardına eklenemesi
void EkleArdina(struct Dugum** baslangic, int deger1,int deger2) { 
    struct Dugum* yeniDugum = new Dugum; 
    yeniDugum->veri = deger1;
    
    struct Dugum *gecici = *baslangic; 
    while (gecici->veri != deger2) 
        gecici = gecici->sonraki; 
    struct Dugum *sonraki = gecici->sonraki; 
  
    gecici->sonraki = yeniDugum; 
    yeniDugum->onceki = gecici; 
    yeniDugum->sonraki = sonraki; 
    sonraki->onceki = yeniDugum; 
} 

//parametre olarak gelen sayının listenin sonuna eklenemesi
void EkleSona(struct Dugum** baslangic, int deger) { 
  
    if (*baslangic == NULL) { 
        struct Dugum* yeniDugum = new Dugum; 
        yeniDugum->veri = deger; 
        yeniDugum->sonraki = yeniDugum->onceki = yeniDugum; 
        *baslangic = yeniDugum; 
        return; 
    } 

    Dugum *enSon = (*baslangic)->onceki; 

    struct Dugum* yeniDugum = new Dugum; 
    yeniDugum->veri = deger; 
    yeniDugum->sonraki = *baslangic; 
    (*baslangic)->onceki = yeniDugum; 
    yeniDugum->onceki = enSon; 
    enSon->sonraki = yeniDugum; 
} 

//parametre olarak gelen sayıların ebobu hesaplanarak sonucun geriye döndürülmesi
int Ebob(int sayi1, int sayi2){
	while(sayi1 != sayi2){
		if(sayi1 > sayi2)
			sayi1 -= sayi2;
		else
			sayi2 -= sayi1;
	}
	return sayi1;
}

//Düğümdeki sayıların harf karşılıklarının sırasıyla yazdırılması işlemi
void Yazdir(struct Dugum* baslangic){
	struct Dugum *gecici = baslangic; 
  
    printf("Sifre: "); 
    while (gecici->sonraki != baslangic) 
    { 

        printf("%c", gecici->veri); 
        gecici = gecici->sonraki; 
    } 
    printf("%c\n", gecici->veri); 
}

//parametre olarak gelen dosya adındaki verilerin okunması ve ilgili işlemlerin yapılması
void DosyaOku(char dosyaAdi[20]){
	//dosya pointeri oluşturulması
	FILE* dosya;
	//her bir satır için belirlenen maximum uzunluk
	int uzunluk = 5000;
	char bf[uzunluk];
	//dosyanın okuma modunda açılması
	dosya = fopen(dosyaAdi, "r");

	while(fgets(bf, uzunluk, dosya)) {//o anki satırın okunması ve bf dizisine aktarılması, satır boş olmadığı sürece döngü devam eder
		int *dizi = (int*)malloc(sizeof(int)*512);
		
		//belirlenen " "(space) karakteri ile satırdaki sayıların ayrıştırılması için atama işlemi
		char ayirici[2] = " ";

		//strtok fonksiyonu ile o anki satırdaki sayılar döngüsel olarak ayrılıp bir diziye atanıyor
		char *parca;
		parca = strtok(bf,ayirici);

		int i = 0;
		//o anki satırın değerini tutan değişkende veri var olduğu sürece dönen döngü
		while(parca != NULL){
			dizi[i++] = atoi(parca);
			parca = strtok(NULL,ayirici);
		}

		int enBuyukEb = 0;
		//yeni bir düğüm oluşturulması
		struct Dugum* baslangic = NULL;

	    int j;
	   	//0 dan başlanıp sayı adedi kadar dönen bir döngü
	    for(j=0; j<i; j++){

	    	//ilk adım ise sayı listenin başına eklenmesi
	    	if(j==0){
	    		EkleSona(&baslangic, dizi[0]); 
				continue;
	    	}
	    	//o anki sayı ile başlangıç değerindeki sayının ebobunun daha önceki en büyük ebob degerinden daha büyük olması
	    	if(enBuyukEb < Ebob(baslangic->veri,dizi[j])){
	    		
	    		enBuyukEb = Ebob(baslangic->veri,dizi[j]);

	    		//ilgili mod alma işlemlerinin yapılması
	    		int modSonuc;
	    		if(dizi[j] > baslangic->veri)
	    			modSonuc = dizi[j] % baslangic->veri;
	    		else
	    			modSonuc = baslangic->veri % dizi[j];
	    		
	    		//mod sonucu kalansız ise
	    		if(modSonuc == 0){
	    			EkleArdina(&baslangic,dizi[j],baslangic->veri);
	    			continue;
	    		}
	    		//mod sonucu 0 dan faklı ise
	    		else{
	    			int i=0;
	    			struct Dugum *gecici = baslangic;
	    			while(i++<modSonuc)
	    				gecici = gecici->onceki;
	    			if(gecici == baslangic){
	    				EkleBasa(&baslangic,dizi[j]);
	    				continue;
	    			}
	    		}
	    	}
	    	//o anki sayı ve başlangıç sayısının ebobu, en buyuk ebob değerinden küçük ise
	    	else{
	    		//gecici bir düğüm oluşturulup başlangıcı gösterecek şekilde ayarlanması
	    		struct Dugum *gecici = baslangic;
	    		//gecici düğümün o anki değeri ile dizinin o anki elemanının ebob değeri en büyük ebob değerinden küçük olduğu ve listenin tek elemanlı olmadığı sürece dönen döngü
	    		while(Ebob(gecici->veri,dizi[j]) < enBuyukEb && gecici->sonraki != baslangic){
	    			
	    			gecici = gecici->sonraki;
	    		}

	    		//ilgili mod alma işlemleri
	    		int modSonuc;
	    		if(dizi[j] > gecici->veri)
	    			modSonuc = dizi[j] % gecici->veri;
	    		else
	    			modSonuc = gecici->veri % dizi[j];
	    		
	    		//döngü için "i" değişkeni ve kontrol için bayrak görevi gören "flag" değişkeni
	    		int i=0,flag=0;
	    		//i değeri mod alma sonucundan küçük olduğu sürece dönen döngü
	    		while(i++<modSonuc){
	    			//gecici eşit ise başlanguca bayrak kaldırılır ve dizinin o anki değeri başa eklenir
	    			if(gecici == baslangic){
	    				flag =1;
	    				EkleBasa(&baslangic,dizi[j]);
	    				break;
	    			}

	    			gecici = gecici->onceki;
	    		}
	    		//bayrak kalmamış ise dizinin o anki elemanı gecici göstericisinin ardına eklenir
	    		if(flag==0)
	    			EkleArdina(&gecici,dizi[j],gecici->veri);
	    	}
	    }
	    //o anki satırdaki hesaplamalar yapıldıktan sonra sonuç yazdırılır
	    Yazdir(baslangic);
	    //bellek boşaltılır
	    free(baslangic);
	}
	//dosya kapatılır
	fclose(dosya);
}

