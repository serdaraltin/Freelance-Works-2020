#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Hesapla(int sayi1,int sayi2,int islem){
	if(islem == 1)
		return sayi1+sayi2;
	else if(islem == 2)
		return sayi1*sayi2;
	else if(islem == 3)
		return sayi1/sayi2;
	else if(islem == 4)
		return sayi1-sayi2;
	else{
		printf("HATALI GIRIS YAPILMISTIR!!!\n");
		return 0;
	}
}

int main(){
	FILE *dosya;
	if(fopen("C:\\matematik.txt","r"))
		dosya = fopen("C:\\matematik.txt","r");
	else{
		printf("Dosya Okunamadi!!!\nProgram kapatiliyor...\n");
		return 0;
	}

	int sayi1,sayi2,islem;
	while(!feof(dosya)){
		fscanf(dosya,"%d,%d,%d\n",&sayi1,&islem,&sayi2);
		printf("Sayi1 : %d, Sayi2 : %d, Islem : %d\nSonuc : %d\n",sayi1,sayi2,islem,Hesapla(sayi1,sayi2,islem));
	}
	fclose(dosya);
} 
