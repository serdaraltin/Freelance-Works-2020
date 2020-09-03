#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

//parametre olarak gelen dizinin içerisinde parametre olarak gelen rakamı
//arayıp var ise geriye "1", yok ise "0" değeri döndüren fonksiyon
int icindemi(int dizi1[],int rakam){
	int i;
	for(i=0; i<4; i++){
		if(dizi1[i] == rakam)
			return 1;
	}
	return 0;
}

//parametre olarak gelen iki dizinin ilgili indek değerindeki rakamları kontrol
//ederek aynı ise geriye "1" değilse "0" değeri döndüren fonksiyon
int yeriAynimi(int dizi1[],int dizi2[],int konum){
	if(dizi1[konum] == dizi2[konum])
		return 1;
	return 0;
}

//parametre olarak gelen iki dizinin birbiri ile aynı olma durumunu kontrol edip
//aynı ise geriye "1" değil ise "0" değerini döndüren fonksiyon
int tammi(int dizi1[],int dizi2[]){
	int i;
	for(i=0; i<4; i++){
		if(dizi1[i] != dizi2[i])
			return 0;
	}
	return 1;
}

//ana fonksiyon
int main(){
	//srand fonksiyonu o anki zaman ile besleniyor böylelikle o anki epoch değeri ile
	//rastgele sayılar üretilebiliyor
	srand(time(NULL));

	//ilgili değişkenlerin ve dizinin tanımlanması
	int dizi1[4],i,j,rastgeleRakam;

	//dizinin ilk elemanına 1-9 arasında rastgele değer atanması
	dizi1[0] = 1 + rand() % 9;
	for(i=1; i<4; i++){
		//rastgele bir rakam üretilmesi 0-9 arasında
		rastgeleRakam = 0+ rand() % 9;
		for(j=0; j<4; j++){
			//dizinin o anki elemani rastgele üretilen rakama eşit olduğu sürece tekrar
			//rastgele bir rakam üretme böylelikle tüm rakamları farklı yapma
			while(rastgeleRakam == dizi1[j]){
				rastgeleRakam = 0+ rand() % 9;
			}
		}
		//üretilen rastgele rakamın dizinin ilgili index değerine atanmasi
		dizi1[i] = rastgeleRakam;
	}

	//test verisi
	/*
	dizi1[0] = 1;
	dizi1[1] = 2;
	dizi1[2] = 3;
	dizi1[3] = 4;*/
	
	int uretilen = 0;
	//dizideki rastgele rakamların bir değişkene atanmasi
	for(i=0; i<4; i++){
		uretilen = 10*uretilen+dizi1[i];
	}
	
	//ilgili değişkenlerin tanımı, doğru ve yanlış sayılarını tutan
	int dogruSayisi,yanlisSayisi;
	int a=1;
	//10 kere dönen döngü ile 10 tahmin hakkı tanınması
	while(a <= 10){
		printf("Belirlenen sayi : %d\n",uretilen);

		
		int tahminEdilen=0,thDizisi[4];
		
		printf("Tahmin edilen sayi : ");
		scanf("%d",&tahminEdilen);


		//tahmin edilen sayının bir diziye doldurulması her bir rakamının bir indexe atanması
		for (i = 0; i < 4; i++) {
		  thDizisi[i] = tahminEdilen%10;
		  tahminEdilen = tahminEdilen / 10;
		}

		//tahmin edilen rakamın atandığı dizi ters olduğundan tekrar tersi alınaran düzeltilmesi
		int dizi2[4];
		for (i = 0; i < 4; i++) {
			dizi2[i] = thDizisi[3-i];
		}

		dogruSayisi = 0, yanlisSayisi = 0;

		//bir döngü ile tek tek tüm rakamların kontrol edilmesi
		for (i = 0; i < 4; i++) {
			//o anki rakamın üretilen sayı içerisinde olup olmadığı kontrolü (varsa)
			if(icindemi(dizi1,dizi2[i]) == 1){
				//o anki rakamın üretilen sayının doğru yerinde olup olmadığı kontrolü (doğru ise)
				if(yeriAynimi(dizi1,dizi2,i) == 1){
					dogruSayisi++;
				}
				//yukarıdaki koşul sağlanmaz ise yani rakam içinde var fakat farklı bir yerde ise
				else{
					yanlisSayisi++;
				}
			}
		}
		a++;
		printf("Verilecek bilgi : ");

		//doğru sayısına göre bilginin şekillendirilmesi
		if(dogruSayisi > 0){
			if(dogruSayisi == 1){
				printf("+ ");
			}
			else{
				printf("+%d ",dogruSayisi );
			}
		}
		//yanlış sayısına göre bilginin şekillendirilmesi
		if(yanlisSayisi > 0){
			if(yanlisSayisi == 1){
				printf("-");
			}
			else{
				printf("-%d",yanlisSayisi );
			}
		}
	
		printf("\n");

		//doğru tahmin sonucu bilgi verilmesi ve döngünün sonlandırılması
		if(tammi(dizi1,dizi2) == 1){
			printf("Tebrikler kazandiniz.\n");
			break;
		}

		//10 adet tahmin sonrası bilgi verilemsi ve döngünün sonlandırılması
		if(a == 11){
			printf("Kaybettiniz :(\n");
			break;
		}

	}
}
