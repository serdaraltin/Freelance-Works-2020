#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define UZUNLUK 6

int dizi_topla(int[],int[]);
void ters_cevir(char[],char[]);
void sesli_harf_bul(char[]);
void karakter_ara(char[],char);
int dizi_max(int[]);
int uzunluk_bul(char[]);
void dizi_birlestir(int[],int[],char[]);

int main(){

	srand(time(0));
	setlocale(LC_ALL,"Turkish");
	int a,y[UZUNLUK];
	char z[30];
	int x[] = {0,1,0,0,6,7};//ogrenci no
	
	for(a=0; a<UZUNLUK; a++){
		y[a] = rand() % 10;
		y[a] = y[a]+10;
	}

	printf("z icin deger : ");
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


int dizi_topla(int diz1[] ,int diz2[]){
	int a, toplam = 0;
	for(a=0; a<UZUNLUK; a++){
		toplam += diz1[a]+diz2[a];
	}
	return toplam;
}

void sesli_harf_bul(char dizi[]){

	int a,b, boyut = uzunluk_bul(dizi);

	char sesliler[8];
	sesliler[0] = 'a';
	sesliler[1] = '3';
	sesliler[2] = 'ı';
	sesliler[3] = 'i';
	sesliler[4] = 'u';
	sesliler[5] = 'ü';
	sesliler[6] = 'o';
	sesliler[7] = 'ö';

	for(a=0; a<boyut; a++)
		for(b=0; b<8; b++)
			if(dizi[a] == sesliler[b])
				printf("\t%d indexte sesli harfi bulunmakta.\n",a);
}

int uzunluk_bul(char dizi[]){
	int a=0;
	while(dizi[a] != '\0')
		a++;
	return a;
}
int dizi_max(int dizi[]){
	int a, maxi = dizi[0];

	for(a=1; a<UZUNLUK; a++){
		if(dizi[a] > maxi)
			maxi = dizi[a];
	}
	return maxi;
}
void karakter_ara(char dizi[],char ch){

	int boyut = uzunluk_bul(dizi),a;
	int indexler[boyut], inSon = 0;
	for(a=0; a<boyut; a++)
		indexler[a] = -1;

	for(a=0; a<boyut; a++)
		if(dizi[a] == ch)
			indexler[inSon++] = a;
	if(indexler[0] == -1){
		printf("\tbulunamadi!!!\n"); 
		return;
	}

	for(a=0; a<boyut; a++)
		if(indexler[a] >= 0)
			printf("\t%d. indexte bulundu.\n",indexler[a]);
}
void dizi_birlestir(int x[],int y[],char z[]){

	int a,boyut = 0;

	printf("x : ");
	for (a = 0; a < UZUNLUK; a++)
		printf("% 2d ",x[a]);
	printf("\ny : ");
	for (a = 0; a < UZUNLUK; a++)
		printf("% 2d ",y[a]);
	printf("\n");
	for(a=0; a<UZUNLUK; a++){
		char ch = x[a]+'0';
		z[boyut++] = ch;
	}
	for (a = 0; a < UZUNLUK; a++){
		char ySayi[2];
		sprintf(ySayi,"%d",y[a]);
		z[boyut++] = ySayi[0];
		z[boyut++] = ySayi[1];
	}
	z[boyut]= '\0';

	printf("x ve y dizilerinin birlesimi : %s\n",z);
}

void ters_cevir(char diz1[],char diz2[]){
	int boyut = uzunluk_bul(diz1);
	int a;
	for(a=0; a<boyut; a++){
		diz2[a] = diz1[boyut-a-1];
	}
	diz2[boyut]='\0';

	printf("ters dizi : %s\n",diz2);
}
