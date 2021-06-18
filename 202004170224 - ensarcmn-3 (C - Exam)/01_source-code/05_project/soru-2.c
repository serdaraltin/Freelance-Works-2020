#include <stdio.h>

//bir tamsayı dizisi ve bu dizinin boyut bilgisini parametre olarak alan fonksiyon
int maxEleman(int dizi[],int boyut){
	//döngü içerisinde kullanılmak üzere "i" değişkeni, en büyük(maximum)
	//sayı değerini tutmak için "max" değişkeni tanımlanıyor
	int i,max; 
	//0 dan başayıp boyut yani dizinin sonuna kadar giden bir döngü oluşturuluyor
	for(i=0; i<boyut; i++){
		//eğer döngünün ilk adımındaysa max değeri seçilen elemana eşitleniyor
		//böylece sonraki elemanlar ile karşılaştırma yapılabiliyor
		if(i == 0)
			max = dizi[i];
		//o anki index numarasındaki dizi elemanı mevcut max değişkeninin değerinden
		//büyük ise max değişkeninin değeri o anki index numarasındaki dizi elamanına eşitleniyor
		if(dizi[i] > max)
			max = dizi[i];
	}
	//döngü bitip son elemana gelindikten sonra nihayi max değeri geri döndürülüyor
	return max;
}

int main(){
	int A[7] = {50, -20, 30, 70, -40, -10, 60};
	int B[9] = {5, 10, -5, 35, -10, 20, -15, 15, 25};
	printf("A dizisinde max eleman = %d\n", maxEleman(A,7));
	printf("B dizisinde max eleman = %d\n", maxEleman(B,9));
	return 0;
}