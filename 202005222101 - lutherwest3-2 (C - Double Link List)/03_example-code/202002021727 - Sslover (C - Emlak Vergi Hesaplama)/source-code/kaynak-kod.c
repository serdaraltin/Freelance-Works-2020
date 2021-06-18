#include <stdio.h>


float vergi_hesapla(float);


int main() {

	basla:
	printf("Ev degeri bilgisi giriniz : ");
	float fiyat;
	scanf("%f",&fiyat);
	if(fiyat < 0){
		printf("Gecerli bir deger giriniz!\n");
		goto basla;
	}
	float vergi_miktari = vergi_hesapla(fiyat);
	printf("Vergi miktari : %.2f TL\n",vergi_miktari);

	return 0;
}

float vergi_hesapla(float fiyat){
	if(fiyat < 5000){
		printf("Vergiden muaftir.\n");
		return 0;
	}
	else if (fiyat > 4999 && fiyat < 50000){
		return (fiyat / 1000) * 5;
	}
	else if (fiyat > 49999 && fiyat <= 100000){
		fiyat -= 5000;
		float vergi_1 = (50000 / 1000) * 5;
		fiyat -= 50000;
		float vergi_2 = (fiyat / 100) * 1;

		return vergi_1 + vergi_2;
	}
	else if (fiyat > 100000){

		fiyat -= 5000;
		float vergi_1 = (45000 / 1000) * 5;
		fiyat -= 45000;
		float vergi_2 = (50000 / 100) * 1;
		fiyat -= 50000;
		float vergi_3 = 0;
		if(fiyat >= 20000){
			vergi_3 = (fiyat / 100) * 2;
		}
		return vergi_1 + vergi_2 + vergi_3;
	}
}

