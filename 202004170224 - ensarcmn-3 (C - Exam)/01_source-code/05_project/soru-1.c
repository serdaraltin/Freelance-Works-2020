 #include <stdio.h>

//bir tamsayı parametre alan fonksiyon tanımı
int basamakSayi(int s){
	//bir sayi en az tek basamakli olacağından başlangıç değeri 1 ayarlanıyor
	int basamak=1; 
	// bir döngü oluşturularak sayinin 10 dan büyük veya eşit ya da -10 dan küçük
	// veya -10 eşit olma durumunda döngü devam ettiriliyor
	while(s >= 10 || s <= -10){ 
		//her adımda sayı 10 a bölünüyor
		s /=10;
		//10 bölümde bir basamak eksildiğinden basamak değeri 1 arttırılıyor
		basamak++;
	}
	//basamak değeri geri döndürülüyor
	return basamak;
}


int main(){
	int s;
	printf("Sayi gir: ");
	scanf("%d",&s);
	printf("%d , %d basamaklidir\n", s, basamakSayi(s));
}