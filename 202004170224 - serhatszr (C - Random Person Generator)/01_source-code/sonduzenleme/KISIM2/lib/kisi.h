#ifndef KISI_H
#define KISI_H

#include "rastgeleuret.h"

void kisiekle(char* kisi) {

  
    FILE *dosya;
  
    int r = rast(1, 3000);
    char* isim = (char*) malloc(sizeof (char)*30);
    char* soyisim = (char*) malloc(sizeof (char)*20);
    dosya = fopen("src/random_isimler.txt", "r");
     int i=0;
    while (!feof(dosya)) {
        fscanf(dosya, "%s %s", isim, soyisim);
        if (i == r)
            break;
        i++;
    }
    fclose(dosya);
    sprintf(kisi, "%s %s", isim, soyisim);
    return;
}

#endif

