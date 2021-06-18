#ifndef KISI_H
#define KISI_H

#include "rastgeleuret.h"

void kisiekle(char* kisi){

	if(!fopen("src/random_isimler.txt","r")){
		printf("Dosya acilamadi!!!\n");
		return;
	}
	FILE *dosya;
	dosya = fopen("src/random_isimler.txt","r");
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
	dosya = fopen("src/random_isimler.txt","r");
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

#endif

