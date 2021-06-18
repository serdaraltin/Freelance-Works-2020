#include <stdio.h>
#include <stdlib.h>
#define BOYUT 10

int en_buyuk(int dizi[],int boyut){
	int i, max = dizi[0];
	for(i=1; i<boyut; i++)
		if(dizi[i] > max)
			max = dizi[i];
	return max;
}
int en_kucuk(int dizi[],int boyut){
	int i, min = dizi[0];
	for(i=1; i<boyut; i++)
		if(dizi[i] < min)
			min = dizi[i];
	return min;
}
int toplam(int dizi[],int boyut){
	int i, toplam = 0;
	for(i=0; i<boyut; i++)
			toplam += dizi[i];
	return toplam;
}
void tersten_yazdir(int dizi[],int boyut){
	int i;
	for(i=boyut-1; i>-1; i--)
		printf("%2d", dizi[i]);
	printf("\n");
}
int ortalama(int dizi[],int boyut){
	return toplam(dizi,boyut)/boyut;
}
void cift_sayilar(int dizi[],int boyut){
	int i;
	for(i=0; i<boyut; i++)
		if(dizi[i] % 2 == 0)
			printf("%2d", dizi[i]);
	printf("\n");
}
void tek_sayilar(int dizi[],int boyut){
	int i;
	for(i=0; i<boyut; i++)
		if(dizi[i] % 2 != 0)
			printf("%2d", dizi[i]);
	printf("\n");
}
int uzunluk_bul(char dizi[]){
	int i=0;
	while(dizi[i] != '\0')
		i++;
	return i;
}
void tersten_yazdir_karakter_dizi(char dizi[]){
	int i;
	for(i=uzunluk_bul(dizi)-1; i>-1; i--)
		printf("%c", dizi[i]);
	printf("\n");
}
void harf_bul(char dizi[],char harf){
	int i,j, uzunluk = uzunluk_bul(dizi);
	for(i=0; i<uzunluk; i++)
		if(dizi[i] ==harf)
			printf("\t[%d] indexte %c harfi bulunmakta.\n",i,harf);
}
void harf_degistir(char dizi[],char harf,char degisHarf){
	int i,j, uzunluk = uzunluk_bul(dizi);
	for(i=0; i<uzunluk; i++)
		if(dizi[i] == harf){
			printf("\t[%d] indexteki %c harfi %c ile degistirildi.\n",i,harf,degisHarf);
			dizi[i] = degisHarf;
		}
	printf("\tDizinin son hali : %s\n",dizi );
}

void kes(char dizi[],char harf){
	int i,j, uzunluk = uzunluk_bul(dizi);
	for(i=0; i<uzunluk; i++)
		if(dizi[i] == harf){
			printf("\t[%d] indexteki %c harfinden kesildi.\n",i,harf);
			dizi[i] = '\0';
		}
	printf("\tDizinin son hali : %s\n",dizi );
}

void ekle(char dizi[],char harf){
	int uzunluk = uzunluk_bul(dizi);
	dizi[uzunluk] = harf; dizi[uzunluk+1] = '\0';
	printf("\tDizinin son hali : %s\n",dizi );
}

void buyuk_harfleri_bul(char dizi[]){
	int i,uzunluk = uzunluk_bul(dizi);
	for(i=0; i<uzunluk; i++)
		if(dizi[i] >= 65 && dizi[i] <= 90)
			printf("\t[%d] indexteki %c harfi buyuk harftir.\n",i,dizi[i]);
}

void kucuk_harfleri_bul(char dizi[]){
	int i,uzunluk = uzunluk_bul(dizi);
	for(i=0; i<uzunluk; i++)
		if(dizi[i] >= 97 && dizi[i] <= 122)
			printf("\t[%d] indexteki %c harfi kucuk harftir.\n",i,dizi[i]);
}

int main(){

	int sayisal_dizi[BOYUT] = {5,1,3,7,9,8,6,2,4,10};
	char karakter_dizi[7] = "Merhaba";

	printf("1. Sayisal Dizideki en kucuk elemean : %d\n",en_kucuk(sayisal_dizi,BOYUT));
	printf("2. Sayisal Dizideki en buyuk elemean : %d\n",en_buyuk(sayisal_dizi,BOYUT));
	printf("3. Sayisal Dizideki elamanlarin toplami : %d\n",toplam(sayisal_dizi,BOYUT));
	printf("4. Sayisal Dizi tersten : "); tersten_yazdir(sayisal_dizi,BOYUT);
	printf("5. Sayisal Dizideki elemanlarin ortalamasi : %d\n",ortalama(sayisal_dizi,BOYUT));
	printf("6. Sayisal Dizideki tek elemanlar : "); tek_sayilar(sayisal_dizi,BOYUT);
	printf("7. Sayisal Dizideki cift elemanlar : "); cift_sayilar(sayisal_dizi,BOYUT);
	printf("8. Karakter Dizi uzunluk : %d\n",uzunluk_bul(karakter_dizi));
	printf("9. Karakter Dizi tersten : "); tersten_yazdir_karakter_dizi(karakter_dizi);
	printf("10. Karakter Dizi a harfi : \n"); harf_bul(karakter_dizi, 'a');
	printf("11. Karakter Dizi a harfi o harfi degistirme : \n"); harf_degistir(karakter_dizi, 'a','o'); 
	printf("12. Karakter Dizi h harfinden kesme : \n"); kes(karakter_dizi, 'h');
	printf("13. Karakter Dizi o harfi ekleme : \n"); ekle(karakter_dizi, 'o');
	printf("14. Karakter Dizi buyuk harfler : \n"); buyuk_harfleri_bul(karakter_dizi);
	printf("15. Karakter Dizi kucuk harfler : \n"); buyuk_harfleri_bul(karakter_dizi);
} 

