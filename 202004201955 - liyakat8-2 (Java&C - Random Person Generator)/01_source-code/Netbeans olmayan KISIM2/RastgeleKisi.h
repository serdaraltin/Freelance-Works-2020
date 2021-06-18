#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void RastgeleKisi(char*);


void RastgeleKisi(char* kisi){

	char* tcno = (char*)malloc(sizeof(char)*11);
	TcNoUret(tcno);

	char* telefon =(char*)malloc(sizeof(char)*12);
	TelefonUret(telefon);

	int yas = YasUret();

	char* imei =(char*)malloc(sizeof(char)*15);
	ImeiUret(imei);

	char* isimSoysim = (char*)malloc(sizeof(char)*30);
	KisiUret(isimSoysim);


	sprintf(kisi,"%s %s %d %s (%s)",tcno,isimSoysim,yas,telefon,imei);

	free(tcno);
	free(telefon);
	free(imei);
	free(isimSoysim);
	return;
}
