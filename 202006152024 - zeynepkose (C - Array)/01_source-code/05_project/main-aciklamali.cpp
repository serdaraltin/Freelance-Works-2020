#include <stdio.h> //standart kutuphane
#include <stdlib.h> //bellek yonetimi icin standart kutuphane
#define BOYUT 10 //sayisal dizinin sabit boyutu icin on islemci komutu

int en_buyuk(int dizi[],int boyut){//dizideki en buyuk sayiyi bulan fonksiyon, parametre olarak dizi ve onun boyutu
	int i, max = dizi[0];//dongu icin "i" ve maximum elemanın degerini tutmak icin max degiskenleri, max ilk olarak dizinin 1. elemanini aliyor
	for(i=1; i<boyut; i++)//dongu dizinin 2. elemanindan baslayip sonuna dek gidiyor
		if(dizi[i] > max)//eger o anki dizi elemani max dan buyukse
			max = dizi[i];//max yerine o anki dizi elemani yaziliyor
	return max;//max degeri geri donduruluyor
}
int en_kucuk(int dizi[],int boyut){//dizideki en kucuk sayiyi bulan fonksiyon, parametre olarak dizi ve onun boyutu
	int i, min = dizi[0];//dongu icin "i" ve minimum elemanın degerini tutmak icin min degiskenleri, min ilk olarak dizinin 1. elemanini aliyor
	for(i=1; i<boyut; i++)//dongu dizinin 2. elemanindan baslayip sonuna dek gidiyor
		if(dizi[i] < min)//eger o anki dizi elemani min dan buyukse
			min = dizi[i];//min yerine o anki dizi elemani yaziliyor
	return min;//min degeri geri donduruluyor
}
int toplam(int dizi[],int boyut){//dizideki tum elemanlarin toplamını bulan fonksiyon,parametre olarak dizi ve onun boyutu
	int i, toplam = 0;//dongu icin "i" ve toplam icin degisken tanimi
	for(i=0; i<boyut; i++)//dongu dizinin 1. elemanindan baslayip sonuna dek gidiyor
			toplam += dizi[i];//o anki deger toplam degiskeninin uzerine ekleniyor
	return toplam;//toplam degeri geri donduruluyor
}
void tersten_yazdir(int dizi[],int boyut){//diziyi tersen yazdıran fonksiyon,parametre olarak dizi ve onun boyutu
	int i;//dongu icin "i" degiskeni
	for(i=boyut-1; i>-1; i--)//son elemandan baslanip 1. elemana dek giden dongu
		printf("%2d", dizi[i]);//dizideki o anki elemani yazdirma
	printf("\n");//bir satir assagi gecme
}
int ortalama(int dizi[],int boyut){//dizideki elemanların ortalamasını bulan fonksiyon,parametre olarak dizi ve onun boyutu
	return toplam(dizi,boyut)/boyut;//toplam fonksiyonundan tum elemanların toplamı alınıp, eleman sayısına bolunup geri donduruluyor
}
void cift_sayilar(int dizi[],int boyut){//dizideki cift sayilari bulup yazdiran fonksiyon,parametre olarak dizi ve onun boyutu
	int i;//dongu icin "i" degiskeni
	for(i=0; i<boyut; i++)//1. elemandan baslayip sona kadar giden dongu
		if(dizi[i] % 2 == 0)//o anki elemanın mod 2 si alınarak cift olma durumu kontrol ediliyor
			printf("%2d", dizi[i]);//cift olan sayi yazdiriliyor
	printf("\n");//bir satir asagi gecme
}
void tek_sayilar(int dizi[],int boyut){//dizideki tek sayilari bulup yazdiran fonksiyon,parametre olarak dizi ve onun boyutu
	int i;//dongu icin "i" degiskeni
	for(i=0; i<boyut; i++)//1. elemandan baslayip sona kadar giden dongu
		if(dizi[i] % 2 != 0)//o anki elemanın mod 2 si alınarak tek olma durumu kontrol ediliyor
			printf("%2d", dizi[i]);//tek olan sayi yazdiriliyor
	printf("\n");//bir satir asagi gecme
}
int uzunluk_bul(char dizi[]){//dizinin uzunlugunu bulan fonksiyon,parametre olarak dizi
	int i=0;//dongu icin "i" degiskeni
	while(dizi[i] != '\0')//dizinin sonuna dek devem eden dongu
		i++;//her bir adimda 1 artan i degiskeni
	return i;//sonuc olarak i dizinin uzunlugunu belirtir ve geri dondurulur
}
void tersten_yazdir_karakter_dizi(char dizi[]){//diziyi tersten yazdiran fonksiyon,parametre olarak dizi
	int i;//dongu icin "i" degiskeni
	for(i=uzunluk_bul(dizi)-1; i>-1; i--)//uzunluk_bul fonksiyonundan gelen degerden ilk degere kadar giden dongu
		printf("%c", dizi[i]);//o adimdaki dizi degeri yazdirma
	printf("\n");//bir satir asagi gecme
}
void harf_bul(char dizi[],char harf){//dizideki bir harfin konumunu bulan fonksiyon,parametre olarak dizi ve bir harf
	int i,j, uzunluk = uzunluk_bul(dizi);//dongu icin "i" degiskeni ve uzunluk icin uzunluk_bul fonksiyonundan dizinin boyutunu tutan degisken
	for(i=0; i<uzunluk; i++)//bir dongu ile dizinin basindan sonuna dek gidiliyor
		if(dizi[i] ==harf)//o anki adimdaki deger eger harf ile eslesiyor ise
			printf("\t[%d] indexte %c harfi bulunmakta.\n",i,harf); //o anki index deger ve harf yazdirma
}
void harf_degistir(char dizi[],char harf,char degisHarf){//dizideki bir harfin baska bir harf ile degistiren fonksiyon,parametre olarak dizi, harf ve harfin degistirilecegi harf
	int i,j, uzunluk = uzunluk_bul(dizi);//dongu icin "i" ve "j" degiskeni ve uzunluk icin uzunluk_bul fonksiyonundan dizinin boyutunu tutan degisken
	for(i=0; i<uzunluk; i++)//ilk elemandan baslayip sonuncu elemana kadar giden dongu
		if(dizi[i] == harf){//o anki eleman harf ile eslesiyor ise
			printf("\t[%d] indexteki %c harfi %c ile degistirildi.\n",i,harf,degisHarf);//o anki index deger ve harf yazdirma
			dizi[i] = degisHarf;//o anki index degerindeki harfi degistirme
    }
	printf("\tDizinin son hali : %s\n",dizi );//dizinin yeni halini yazdırma
}

void kes(char dizi[],char harf){//diziyi belirli bir harften kesen fonksiyon,parametre olarak dizi ve harf
	int i,j, uzunluk = uzunluk_bul(dizi);//dongu icin "i" ve "j" degiskeni ve uzunluk icin uzunluk_bul fonksiyonundan dizinin boyutunu tutan degisken
	for(i=0; i<uzunluk; i++)//ilk elemandan baslayip sonuncu elemana kadar giden dongu
		if(dizi[i] == harf){//o anki eleman harf ile eslesiyor ise
			printf("\t[%d] indexteki %c harfinden kesildi.\n",i,harf);//o anki index deger ve harf yazdirma
			dizi[i] = '\0';//diziyi sonlandirmak icin kacis karakteri
		}
	printf("\tDizinin son hali : %s\n",dizi );//dizinin yeni halini yazdırma
}

void ekle(char dizi[],char harf){//diziyi belirli bir harften ekleyen fonksiyon,parametre olarak dizi ve harf
	int uzunluk = uzunluk_bul(dizi);//uzunluk_bul fonksiyonundan dizinin boyutunu tutan degisken
	dizi[uzunluk] = harf; //dizinin sonuna harf degerini ekleme
	dizi[uzunluk+1] = '\0'; //diziyi sonlandirmak icin kacis karakteri
	printf("\tDizinin son hali : %s\n",dizi ); //dizinin yeni halini yazdırma
}

void buyuk_harfleri_bul(char dizi[]){ //dizideki tum buyuk harfleri yazdiran fonksiyon,parametre olarak dizi
	int i,uzunluk = uzunluk_bul(dizi);//dongu icin "i" degiskeni ve uzunluk icin uzunluk_bul fonksiyonundan dizinin boyutunu tutan degisken
	for(i=0; i<uzunluk; i++)//ilk elemandan baslayip sonuncu elemana kadar giden dongu
		if(dizi[i] >= 65 && dizi[i] <= 90)//dizinin o anki elemani ASCII tablosundaki A-Z karakterlerinin sayısal karşılıkları arasında ise yani buyuk bir harf ise
			printf("\t[%d] indexteki %c harfi buyuk harftir.\n",i,dizi[i]);//o anki index deger ve harfi yazdirma
}

void kucuk_harfleri_bul(char dizi[]){//dizideki tum buyuk harfleri yazdiran fonksiyon,parametre olarak dizi
	int i,uzunluk = uzunluk_bul(dizi);//dongu icin "i" degiskeni ve uzunluk icin uzunluk_bul fonksiyonundan dizinin boyutunu tutan degisken
	for(i=0; i<uzunluk; i++)//ilk elemandan baslayip sonuncu elemana kadar giden dongu
		if(dizi[i] >= 97 && dizi[i] <= 122)//dizinin o anki elemani ASCII tablosundaki a-z karakterlerinin sayısal karşılıkları arasında ise yani buyuk bir harf ise
			printf("\t[%d] indexteki %c harfi kucuk harftir.\n",i,dizi[i]);//o anki index deger ve harfi yazdirma
}

int main(){//ana fonksiyon

	int sayisal_dizi[BOYUT] = {5,1,3,7,9,8,6,2,4,10};//test icin icerisinde 1-10 arasındaki sayıları barındıran bir dizi tanımlama
	char karakter_dizi[7] = "Merhaba";//test icin icerisinde "Merhaba" degerini barindiran bir dizi tanimlama

	printf("1. Sayisal Dizideki en kucuk elemean : %d\n",en_kucuk(sayisal_dizi,BOYUT)); //en kucuk eleman degerini yazdirmak icin yazdirma fonksiyonu icerisinde ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("2. Sayisal Dizideki en buyuk elemean : %d\n",en_buyuk(sayisal_dizi,BOYUT));//en buyuk eleman degerini yazdirmak icin yazdirma fonksiyonu icerisinde ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("3. Sayisal Dizideki elamanlarin toplami : %d\n",toplam(sayisal_dizi,BOYUT));//toplam degerinin yazdirmak icin yazdirma fonksiyonu, ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("4. Sayisal Dizi tersten : "); tersten_yazdir(sayisal_dizi,BOYUT);//tersten yazdirmak icin yazdirma fonksiyonu, ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("5. Sayisal Dizideki elemanlarin ortalamasi : %d\n",ortalama(sayisal_dizi,BOYUT)); //ortalama degerini yazdirmak icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("6. Sayisal Dizideki tek elemanlar : "); tek_sayilar(sayisal_dizi,BOYUT);//tek sayilari yazdirmak icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("7. Sayisal Dizideki cift elemanlar : "); cift_sayilar(sayisal_dizi,BOYUT);//cift sayilari yazdirmak icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("8. Karakter Dizi uzunluk : %d\n",uzunluk_bul(karakter_dizi));//dizinin uzunlugunu yazdirmak icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("9. Karakter Dizi tersten : "); tersten_yazdir_karakter_dizi(karakter_dizi);//tersten yazdirmak icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("10. Karakter Dizi a harfi : \n"); harf_bul(karakter_dizi, 'a');//diziden bir harfi bulmak icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("11. Karakter Dizi a harfi o harfi degistirme : \n"); harf_degistir(karakter_dizi, 'a','o'); //dizideki bir harfi degistirmek icin yazdirma fonksiyonu icerisinde ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("12. Karakter Dizi h harfinden kesme : \n"); kes(karakter_dizi, 'h');//diziyi bir harften sonra kesmek icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("13. Karakter Dizi o harfi ekleme : \n"); ekle(karakter_dizi, 'o');//diziye 1 harf eklemek icin icin yazdirma fonksiyonu  ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("14. Karakter Dizi buyuk harfler : \n"); buyuk_harfleri_bul(karakter_dizi);//dizideki buyuk harfleri yazdirmak icin yazdirma fonksiyonu ilgili fonksiyonun ilgili degerler ile cagrimi
	printf("15. Karakter Dizi kucuk harfler : \n"); buyuk_harfleri_bul(karakter_dizi);//dizideki kucuk harfleri yazdirmak icin yazdirma fonksiyonu ilgili fonksiyonun ilgili degerler ile cagrimi
} 

