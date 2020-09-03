#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Rastgele.h"

#define KISI_DOSYA "random_isimler.txt"

void KisiUret(char*);

void KisiUret(char* kisi){

	if(!fopen(KISI_DOSYA,"r")){
		printf("Dosya acilamadi!!!\n");
		return;
	}
	FILE *dosya;
	dosya = fopen(KISI_DOSYA,"r");
	char chr = getc(dosya);
	int i = 1,count = 1;
	while(chr != EOF){
		if(chr == '\n')
			count++;
		chr = getc(dosya);
	}
	fclose(dosya);

	int r = rast(1,count);
	char* isim = (char*)malloc(sizeof(char)*30);
	char* soyisim = (char*)malloc(sizeof(char)*20);
	dosya = fopen(KISI_DOSYA,"r");
	chr = getc(dosya);
	while(!feof(dosya)){
		fscanf(dosya,"%s %s",isim,soyisim);
		if(i == r)
			break;
		i++;
	}
	fclose(dosya);
	sprintf(kisi,"%s %s",isim,soyisim);
	return;
}
