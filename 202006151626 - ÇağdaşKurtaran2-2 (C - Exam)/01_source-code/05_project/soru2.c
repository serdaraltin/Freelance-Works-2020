#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int dizi_topla(int[],int[]);
int dizi_max(int[]);
void sesli_harf_bul(char[]);
int uzunluk_bul(char[]);
void dizi_birlestir(int[],int[],char[]);
void karakter_ara(char[],char);
void ters_cevir(char[],char[]);


int main(){
	setlocale(LC_ALL,"Turkish");

	srand(time(0));

	int i;

	int x[] = {0,1,0,0,6,7};
	int y[6];
	char z[25];

	for(i=0; i<6; i++){
		y[i] = (rand() % 10)+10;
	}

	printf("z(char) dizisi icin deger giriniz (max:20) : ");
	scanf("%s",z);

	printf("x ile y dizisinin toplami : %d\n",dizi_topla(x,y));

	printf("x dizisinin en buyuk elemani : %d\n",dizi_max(x));
	printf("y dizisinin en buyuk elemani : %d\n",dizi_max(y));

	sesli_harf_bul(z);

	printf("z dizisinin uzunlugu : %d\n",uzunluk_bul(z));

	

	printf("z dizisi icerisinde aranacak karakter : ");
	char karakter[2];
	scanf("%s",karakter);
	karakter_ara(z,karakter[0]);

	char tersDizi[uzunluk_bul(z)];
	ters_cevir(z,tersDizi);

	dizi_birlestir(x,y,z);
} 

int dizi_topla(int dizi1[] ,int dizi2[]){
	int i, toplam = 0;
	for(i=0; i<6; i++){
		toplam += dizi1[i]+dizi2[i];
	}
	return toplam;
}

int dizi_max(int dizi[]){
	int i, max = dizi[0];

	for(i=1; i<6; i++){
		if(dizi[i] > max)
			max = dizi[i];
	}
	return max;
}

int uzunluk_bul(char dizi[]){
	int i=0;
	while(dizi[i] != '\0'){
		i++;
	}
	return i;
}

void karakter_ara(char dizi[],char karakter){

	int uzunluk = uzunluk_bul(dizi),i;
	int indexler[uzunluk], indexSon = 0;

	for(i=0; i<uzunluk; i++)
		indexler[i] = -1;

	for(i=0; i<uzunluk; i++){
		if(dizi[i] == karakter)
			indexler[indexSon++] = i;
	}

	if(indexler[0] == -1){
		printf("Aranan karakter bulunamadi!!!\n"); 
		return;
	}

	for(i=0; i<uzunluk; i++){
		if(indexler[i] >= 0)
			printf("%c karakteri %d indexinde bulundu.\n",karakter,indexler[i]);
	}
}

void ters_cevir(char dizi1[],char dizi2[]){
	int uzunluk = uzunluk_bul(dizi1);
	int i;
	for(i=0; i<uzunluk; i++){
		dizi2[i] = dizi1[uzunluk-i-1];
	}
	dizi2[uzunluk]='\0';

	printf("ters dizi : %s\n",dizi2);
}

void dizi_birlestir(int x[],int y[],char z[]){

	int i,uzunluk = 0;

	printf("x dizisi : ");
	for (i = 0; i < 6; ++i)
		printf("% 3d ",x[i]);
	printf("\ny dizisi : ");
	for (i = 0; i < 6; ++i)
		printf("% 3d ",y[i]);
	printf("\n");
	for(i=0; i<6; i++){
		char karakter = x[i]+'0';
		z[uzunluk++] = karakter;
	}
	for (i = 0; i < 6; ++i){
		char sayi[2];
		sprintf(sayi,"%d",y[i]);
		z[uzunluk++] = sayi[0];
		z[uzunluk++] = sayi[1];
	}
	z[uzunluk]= '\0';

	printf("x ve y dizilerinin birlestirilmis hali (z dizisinde) : %s\n",z);
}

void sesli_harf_bul(char dizi[]){
	char sesliHarler[8] = {'a','e','ı','i','u','ü','o','ö'};

	int i,j, uzunluk = uzunluk_bul(dizi);

	for(i=0; i<uzunluk; i++){
		for(j=0; j<8; j++){
			if(dizi[i] == sesliHarler[j]){
				printf("%d indexte %c sesli harfi bulunmakta.\n",i,sesliHarler[j]);
			}
		}
	}
}
