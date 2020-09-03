#ifndef KISIURET_H
#define KISIURET_H

#include "kisi.h"

struct kisi {
    char tcno[15];
    char isimSoyisim[40];
    int yas;
    char telefon[15];
    char imei[20];
};
typedef struct kisi Kisi;

void kisiuret(Kisi* k) {
   /* k->tcno = (char*) malloc(sizeof (char)*20);
    k->telefon = (char*) malloc(sizeof (char)*20);
    k->imei = (char*) malloc(sizeof (char)*20);
    k->isimSoyisim = (char*) malloc(sizeof (char)*30);*/

    tcekle(k->tcno);

    telekle(k->telefon);

    imeiekle(k->imei);

    kisiekle(k->isimSoyisim);

    k->yas = yasekle();

    return;
}

#endif 

