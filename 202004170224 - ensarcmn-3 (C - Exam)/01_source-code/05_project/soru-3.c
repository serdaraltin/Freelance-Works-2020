#include <stdio.h>

//tamsayı türünde bir gösterici(pointer) parametre alan fonksiyon
void kareyiYaz(int *sayi) {
	//işlemlerin daha rahat anlaşılabilmesi için göstericinin bellek adresindeki
	//tamsayı değeri gecici bir tamsayı değişkene kopyalanıyor
	int gecici = *sayi;
	//gecici değişkeninin karesi hesaplanıp kendine eşitleniyor
	gecici *= gecici;
	//sayi göstericisinin bellek adresindeki değer gecici(yani kare) ile değiştiriliyor
	*sayi = gecici;
	return;
}

int main() {
	int a = 11, b = 20;
	printf("a = %d\tb = %d\n", a, b);
	kareyiYaz(&a);
	kareyiYaz(&b);
	printf("a = %d\tb = %d\n", a, b);
	return 0;
}
