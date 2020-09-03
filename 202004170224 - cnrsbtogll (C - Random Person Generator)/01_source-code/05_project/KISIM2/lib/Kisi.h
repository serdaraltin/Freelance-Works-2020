#ifndef KISI_H
#define KISI_H
#include "Kisi.h"
void RastKisi(char* kisi){ int i = 0, r = rast(1, 3000);
    FILE *f = fopen("../src/random_isimler.txt", "r");
    char n[30]; char s[30];
    while (!feof(f)) {
        fscanf(f, "%s %s", s, n);
        if (i == r)
            break;
        i++;}
    fclose(f);sprintf(kisi, "%s %s", s, n);}
#endif

