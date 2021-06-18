#include <stdio.h>
#include <stdlib.h>

//tamsayı türünde bir gösterici(pointer) ve tamsayı parametre alan fonksiyon
void sirala(int *dizi, int boyut){
	//döngüler için "i" ve "j" değişken tanımları
	int i,j;
	//dizinin tüm elmanlarını gezmek için 0 dan başlayıp "boyut" değerine
	//kadar giden döngü
	//bu döngüden gelen değer ile seçilen eleman karşılaştırmada kullanılacaktır
	for(i=0; i<boyut; i++){
		//birinci döngünün içerisindeki ikinci döngü
		//bu döngü dizinin üzerinden ikinci sefer geçilmesine olanak sağlıyor
		//böylece dizideki her bir elemanı dizideki diğer her bir elemanla karşılaştırabiliyoruz
		for(j=0; j<boyut; j++){
			//birinci diziden ve ikinci iç diziden gelen "i" ve "j" değerlerindeki
			//dizi elemanları karşılaştırılıyor
			if(dizi[i] < dizi[j]){
				//eğer dizinin seçilen o anki elemanı iç döngüde seçilen dizinin diğer
				//elemanından küçük ise yer değişikliği yapmak adına işlemler yapılıyor
				//yer değişikliği sırasında üzerine yazılacak olan dizi elemanının kaybolmaması
				//için geçiçi bir tamsayı değişken tanımlanarak değeri değişkene kopyalanıyor
				int gecici = dizi[j];
				//ikinci döngüdeki "j" değerindeki eleman yerine birinci döngüdeki "i" değerindeki eleman
				//yazılıyor
				dizi[j] = dizi[i];
				//bir önceki adımda yazma sonucu "j" değerindeki eleman kayboluyor, geçici değişkeni bu
				//kaybolmadan önce "j" değerindeki elemanın değerini kopyaladığı için "i" değerindeki eleman
				//yerine bir önceki "j" değerindeki elemanın değeri yani geçiçi olarak tutulan değer yazılıyor
				dizi[i] = gecici;
				//tüm bu işlemlerden sonra iki eleman yer değiştiriyor
				//bu dizinin her bir elemanında dizinin tüm elemanlarıyle karşılaştırma işlemi yapıldığından
				//tüm dizideki elemanlar düzenlenmiş oluyor
			}
		}
	}
	//geriye herhangi bir değer döndürülmüyor çünkü gösterici türünde bir parametre aldığından doğrudan
	//bellek adresi üzerinde işlem yapıldı
	return;
}

int main(){
	//eleman sayisini tutmak için "adet" adında değişken tanımı
	int adet;
	printf("Eleman sayisi gir: ");
	//kullanıcıdan alınan değer "adet" değişkeninin bellek adresine yazılıyor
	scanf("%d",&adet);
	
	//dinamik bir tamsayı dizi yani tamsayı türünde bir gösterici tanımlanıyor
	//bellekte tamsayı gösterici türünde bir "int" veri türünün kapladığı alan çarpı
	//o an kullanıcıdan alınan eleman değeri kadar yer ayrılıyor
	int *tamsayiDizi = (int*)malloc(sizeof(int)*adet);
	//döngüler için "i" değişkeni
	int i;
	//bir döngü oluşturularak 0. index değerinden o an kullanıcıdan alınan
	//"adet(eleman sayisi)" değerine kadar gidiliyor
	for(i=0; i<adet; i++){
		//sayiyi tutmak için "sayi" adında değişken tanımı
		int sayi;
		printf("Eleman gir: ");
		//kullanıcının girdiği değer tamsayı türündeki göstericinin o anki index değerin bellek
		//adresine yazılıyor, göstericiler bir dizi gibi işlev görebildiğinden
		//[] "köşeli parantez"ler ile elemanlarına erişilebiliyor
		//int* türünde bir gösterici tanımlandığında bellekte ayrılan alan ard ardadır
		scanf("%d",&tamsayiDizi[i]);	
	}
	//sirala fonksiyonu çağrılarak int* (tamsayı gösterici) türündeki dizi ve dizinin
	//uzunluğunu belirten eleman sayısı değerini barındıran tamsayı "adet" değişkeni parametre
	//olarak veriliyor 
	sirala(tamsayiDizi,adet);

	printf("Sirali dizi:\n");
	//bir döngü oluşturularak 0. index değerinden o an kullanıcıdan alınan
	//"adet(eleman sayisi)" değerine kadar gidiliyor
	for(i=0; i<adet; i++){
		//o anki index değerindeki dizi elemanı ekrana yazdırılıyor
		printf("%d ", tamsayiDizi[i]);
	}
	printf("\n");

}