#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define BOYUT 6

int dizi_topla(int[],int[]);
void ters_cevir(char[],char[]);
void sesli_harf_bul(char[]);
int dizi_max(int[]);
void karakter_ara(char[],char);
int uzunluk_bul(char[]);
void dizi_birlestir(int[],int[],char[]);


int main(){

	srand(time(0));
		setlocale(LC_ALL,"Turkish");
	int a,y[BOYUT];
	char z[30];
	int x[] = {0,1,0,0,1,9};
	
	for(a=0; a<BOYUT; a++){
		y[a] = rand() % 10;
		y[a] = y[a]+10;
	}

	printf("z icin deger (orn : ahmet) : ");
	scanf("%s",z);

	printf("x icindeki en buyuk  : %d\n",dizi_max(x));
	printf("y icindeki en buyuk  : %d\n",dizi_max(y));
	printf("x ile y toplami : %d\n",dizi_topla(x,y));

	sesli_harf_bul(z);

	printf("z uzunluk : %d\n",uzunluk_bul(z));

	printf("z icerisinde aranacak  : ");
	char ch[2];
	scanf("%s",ch);
	karakter_ara(z,ch[0]);

	char zTers[uzunluk_bul(z)];
	ters_cevir(z,zTers);

	dizi_birlestir(x,y,z);
} 


int dizi_topla(int arr1[] ,int arr2[]){
	int a, tp = 0;
	for(a=0; a<BOYUT; a++){
		tp += arr1[a]+arr2[a];
	}
	return tp;
}

void sesli_harf_bul(char dizi[]){

	int a,b, uz = uzunluk_bul(dizi);

	char harfler[8];
	harfler[0] = 'a';
	harfler[1] = '3';
	harfler[2] = 'ı';
	harfler[3] = 'i';
	harfler[4] = 'u';
	harfler[5] = 'ü';
	harfler[6] = 'o';
	harfler[7] = 'ö';

	for(a=0; a<uz; a++)
		for(b=0; b<8; b++)
			if(dizi[a] == harfler[b])
				printf("\t%d indexte sesli harfi bulunmakta.\n",a);
}


int uzunluk_bul(char dizi[]){
	int a=0;
	while(dizi[a] != '\0'){
		a++;
	}
	return a;
}
int dizi_max(int dizi[]){
	int a, enBuyuk = dizi[0];

	for(a=1; a<BOYUT; a++){
		if(dizi[a] > enBuyuk)
			enBuyuk = dizi[a];
	}
	return enBuyuk;
}
void karakter_ara(char dizi[],char ch){

	int uz = uzunluk_bul(dizi),a;
	int indexler[uz], inF = 0;
	for(a=0; a<uz; a++)
		indexler[a] = -1;

	for(a=0; a<uz; a++)
		if(dizi[a] == ch)
			indexler[inF++] = a;
	if(indexler[0] == -1){
		printf("\tbulunamadi!!!\n"); 
		return;
	}

	for(a=0; a<uz; a++)
		if(indexler[a] >= 0)
			printf("\t%d. indexte bulundu.\n",indexler[a]);
}
void dizi_birlestir(int x[],int y[],char z[]){

	int a,uz = 0;

	printf("x : ");
	for (a = 0; a < BOYUT; a++)
		printf("% 2d ",x[a]);
	printf("\ny : ");
	for (a = 0; a < BOYUT; a++)
		printf("% 2d ",y[a]);
	printf("\n");
	for(a=0; a<BOYUT; a++){
		char ch = x[a]+'0';
		z[uz++] = ch;
	}
	for (a = 0; a < BOYUT; a++){
		char ySayi[2];
		sprintf(ySayi,"%d",y[a]);
		z[uz++] = ySayi[0];
		z[uz++] = ySayi[1];
	}
	z[uz]= '\0';

	printf("x ve y birlesim : %s\n",z);
}

void ters_cevir(char arr1[],char arr2[]){
	int uz = uzunluk_bul(arr1);
	int a;
	for(a=0; a<uz; a++){
		arr2[a] = arr1[uz-a-1];
	}
	arr2[uz]='\0';

	printf("ters dizi : %s\n",arr2);
}
