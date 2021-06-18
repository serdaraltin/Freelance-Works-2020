#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int dizi_topla(int[],int[]);
int dizi_max(int[]);
int uzunluk_bul(char[]);
void ters_cevir(char[],char[]);
void sesli_harf_bul(char[]);
void dizi_birlestir(int[],int[],char[]);
void karakter_ara(char[],char);

int main(){
	setlocale(LC_ALL,"Turkish");

	srand(time(0));

	int i;

	int x[6] = {0,1,0,0,4,5};
	int y[6];
	char z[30];

	for(i=0; i<6; i++){
		y[i] = (rand() % 10)+10;
	}

	printf("z dizisi icin deger girini : ");
	scanf("%s",z);

	printf("x dizisinin en buyuk elemani : %d\n",dizi_max(x));
	printf("y dizisinin en buyuk elemani : %d\n",dizi_max(y));
	printf("x ile y dizisinin toplami : %d\n",dizi_topla(x,y));
	printf("z dizisinin uzunlugu : %d\n",uzunluk_bul(z));


	printf("z dizisi icerisinde aranacak karakter : ");
	char ch[2];
	scanf("%s",ch);
	karakter_ara(z,ch[0]);
	sesli_harf_bul(z);

	char revArr[uzunluk_bul(z)];
	ters_cevir(z,revArr);

	dizi_birlestir(x,y,z);
} 

int dizi_topla(int arry[] ,int arry2[]){
	int i, toplam = 0;
	for(i=0; i<6; i++){
		toplam += arry[i]+arry2[i];
	}
	return toplam;
}

int dizi_max(int arry[]){
	int i, maximum = arry[0];

	for(i=1; i<6; i++){
		if(arry[i] > maximum)
			maximum = arry[i];
	}
	return maximum;
}

int uzunluk_bul(char arry[]){
	int i=0;
	while(arry[i] != '\0')
		i++;
	return i;
}

void karakter_ara(char arry[],char ch){

	int len = uzunluk_bul(arry),i;
	int indexler[len], inCount = 0;

	for(i=0; i<len; i++)
		indexler[i] = -1;

	for(i=0; i<len; i++)
		if(arry[i] == ch)
			indexler[inCount++] = i;
	
	if(indexler[0] == -1){
		printf("Aranan karakter bulunamadi!!!\n"); 
		return;
	}
	for(i=0; i<len; i++)
		if(indexler[i] >= 0)
			printf("%c karakteri %d indexinde bulundu.\n",ch,indexler[i]);
}

void ters_cevir(char arry[],char arry2[]){
	int len = uzunluk_bul(arry);
	int i;
	for(i=0; i<len; i++){
		arry2[i] = arry[len-i-1];
	}
	arry2[len]='\0';

	printf("ters arry : %s\n",arry2);
}

void dizi_birlestir(int x[],int y[],char z[]){

	int i,len = 0;

	printf("x dizisi : ");
	for (i = 0; i < 6; ++i)
		printf("% 3d ",x[i]);
	printf("\ny dizisi : ");
	for (i = 0; i < 6; ++i)
		printf("% 3d ",y[i]);
	printf("\n");
	for(i=0; i<6; i++){
		char ch = x[i]+'0';
		z[len++] = ch;
	}
	for (i = 0; i < 6; ++i){
		char num[2];
		sprintf(num,"%d",y[i]);
		z[len++] = num[0];
		z[len++] = num[1];
	}
	z[len]= '\0';

	printf("x ve y birlesim: %s\n",z);
}

void sesli_harf_bul(char arry[]){
	char uCh[8] = {'a','e','ı','i','u','ü','o','ö'};

	int i,j, len = uzunluk_bul(arry);

	for(i=0; i<len; i++)
		for(j=0; j<8; j++)
			if(arry[i] == uCh[j])
				printf("%d indexte %c sesli harfi bulunmakta.\n",i,uCh[j]);
}
