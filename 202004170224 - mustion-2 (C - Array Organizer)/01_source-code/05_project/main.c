#include <stdio.h>

//fonksiyon prototipleri
void organizer(int a[], int size, int x);
void printArray(int a[], int size, int index);

int main(){
	//a adında int(tamsayı) türünde bir dizi tanımlanıyor ve değerleri atanıyor, atanan değer kadar uzunluğa sahip olmakta
	int a[] = {4,6,2,9,1,7,3,10};
	//printArray fonskyionu çağrılarak sırasıyla dizi, dizinin uzunluğu, ve başlangıç index değerleri parametre olarak veriliyor
	printArray(a,8,0);
	//organizer fonksiyonu çağrılıyor ve sırasıyla dizi, dizinin uzunluğu ve karşılaştırma yapılacak değer parametre olarak veriliyor
	organizer(a,8,5);
	//printArray fonskyionu çağrılarak sırasıyla dizi, dizinin uzunluğu, ve başlangıç index değerleri parametre olarak veriliyor
	printArray(a,8,0);
} 

//organizer fonksiyonu bir int(tamsayı) dizi, bir int, bir int parametre alıyor
void organizer(int a[], int size, int x){
	//o anki x değeri kontrol ediliyor ve x değeri <= 0 ise fonksiyon sonlandırılıyor
	if(x <= 0 || x >= size)
		return;
	//*(a+x) => a[x] ifadeleri birbirine eşittir burada diziler pointerlar gibi kullanılabildiği için bu tanımlama yapılmıştır
	if(*(a+x) > x){
		//yer değişimi yapılacağından üzerine yazılıcak olunan değer geçici olarak başka bir değişkende tutuluyor
		int tmp = *(a+x+1); 
		//a[x+1] inci elamanın bellek adresine a[x] elemanı yazılıyor yani seçilen eleman bir sonraki haneye kaydırılıyor
		*(a+x+1)= *(a+x);
		//kaydırılan elemanın önceki bellek adresine geçici değişkende tutulan eleman değeri aktarılıyor
		*(a+x) = tmp;
		//rekursif(özyineli) olarak fonksiyon o anki x değerinin 1 eksiği ile tekrar çağrılıyor
		organizer(a,size,x-1);
	}
	//*(a+x) => a[x] ifadeleri birbirine eşittir burada diziler pointerlar gibi kullanılabildiği için bu tanımlama yapılmıştır
	if(*(a+x) < x){
		int tmp = *(a+x-1);
		//a[x-1] inci elamanın bellek adresine a[x] elemanı yazılıyor yani seçilen eleman bir önceki haneye kaydırılıyor
		*(a+x-1) = *(a+x);
		//kaydırılan elemanın sonraki bellek adresine geçici değişkende tutulan eleman değeri aktarılıyor
		*(a+x) = tmp;
		//rekursif(özyineli) olarak fonksiyon o anki x değerinin 1 eksiği ile tekrar çağrılıyor
		organizer(a,size,x-1);
	}
	//*(a+x+1) => a[x+1] ifadeleri birbirine eşittir burada diziler pointerlar gibi kullanılabildiği için bu tanımlama yapılmıştır
	if(*(a+x+1) < *(a+x) ){
		int tmp = *(a+x-1);
		//a[x-1] inci elamanın bellek adresine a[x] elemanı yazılıyor yani seçilen eleman bir önceki haneye kaydırılıyor
		*(a+x-1) = *(a+x) ;
		//kaydırılan elemanın sonraki bellek adresine geçici değişkende tutulan eleman değeri aktarılıyor
		*(a+x)  = tmp;
		//rekursif(özyineli) olarak fonksiyon o anki x değerinin 1 eksiği ile tekrar çağrılıyor
		organizer(a,size,x-1);
	}
	return;//fonksiyon geri döndürülüyor
}
//organizer fonksiyonu bir int(tamsayı) dizi, bir int, bir int parametre alıyor
void printArray(int a[], int size, int index){
	//gelen index değeri dizinin boyutundan büyük veya eşitse tüm elemanlar bastırılmış demektir bu nedenle bir satır boşluk bastırılıp
	//fonskyion sonlandırılmak için geriye döndürülüyor
	if(index >= size){
		printf("\n");
		return;//fonksiyon geri döndürülüyor
	}
	//*(a+index) => a[index] ifadeleri birbirine eşittir burada diziler pointerlar gibi kullanılabildiği için bu tanımlama yapılmıştır
	//o anki index değerindeki eleman yazdırılıyor
	printf("%d ",*(a+index));
	//fonksiyon rekursif(özyineli) olarak bir sonraki elemanı bastırlamak için index değerini 1 arttırarak kendini çağırıyor
	printArray(a,size,index+1);
	return;//fonksiyon geri döndürülüyor
}