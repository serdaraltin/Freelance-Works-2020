#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct kisi{
    char* tcno[11];
    char* isimSoyisim[30];
    int yas;
    char* telefon[11];
    char* imei[15];
};
typedef struct kisi Kisi;

void RastgeleKisi(Kisi*);

void RastgeleKisi(Kisi* k){

	char* tcno = (char*)malloc(sizeof(char)*11);
	TcNoUret(tcno);

	char* telefon =(char*)malloc(sizeof(char)*12);
	TelefonUret(telefon);

	int yas = YasUret();

	char* imei =(char*)malloc(sizeof(char)*15);
	ImeiUret(imei);

	char* isimSoyisim = (char*)malloc(sizeof(char)*30);
	KisiUret(isimSoyisim);
        
        tcno[11] = '\0';
        telefon[11]  = '\0';
        imei[15] = '\0';
        
        strcpy(k->tcno,tcno);
        strcpy(k->isimSoyisim,isimSoyisim);
        strcpy(k->telefon,telefon);
        k->yas = yas;
        strcpy(k->imei,imei);
        
	//sprintf(kisi,"%s %s %d %s (%s)",tcno,isimSoyisim,yas,telefon,imei);

	free(tcno);
	free(telefon);
	free(imei);
	free(isimSoyisim);
	return;
}
