#ifndef IMEIURET_H
#define IMEIURET_H

#include  <string.h>
#include "rastgeleuret.h"

void imeiekle(char *imei) {
    int tempIMEI[15], i;

    tempIMEI[0] = rast(1, 9);
    for (int i = 1; i < 14; i++) {
        tempIMEI[i] = rast(0, 11);
    }
    int tekhanetoplam = 0;
    int cifthanetoplam = 0;
    for (int i = 0; i < 7; i++) {
        tekhanetoplam = tekhanetoplam + tempIMEI[i * 2];
        if (tempIMEI[1 + i * 2] * 2 >= 10) {
            int onlar = tempIMEI[1 + i * 2] * 2 / 10;
            int birler = tempIMEI[1 + i * 2] * 2 % 10;
            cifthanetoplam = cifthanetoplam + onlar + birler;
        } else
            cifthanetoplam = cifthanetoplam + tempIMEI[1 + i * 2] * 2;
    }
    tempIMEI[14] = (10 - (tekhanetoplam + cifthanetoplam) % 10) % 10;

    int index = 0;
    for (i = 0; i < 15; i++) {
        index += snprintf(&imei[index], 128 - index, "%d", tempIMEI[i]);
    }

    return;
}

int imeidogrula(char* imei) {
    int imeiLen = strlen(imei);

    int imeiNO[imeiLen], i;

    for (i = 0; i < 15; i++) {
        imeiNO[i] = imei[i] - 48;
    }

    if (imeiLen != 15) {
        return -1;
    }
    int tekhanetoplam = 0;
    int cifthanetoplam = 0;
    for (int i = 0; i < 7; i++) {
        tekhanetoplam = tekhanetoplam + imeiNO[i * 2];
        if (imeiNO[1 + i * 2] * 2 >= 10) {
            int onlar = imeiNO[1 + i * 2] * 2 / 10;
            int birler = imeiNO[1 + i * 2] * 2 % 10;
            cifthanetoplam = cifthanetoplam + onlar + birler;
        } else
            cifthanetoplam = cifthanetoplam + imeiNO[1 + i * 2] * 2;
    }
    int i15 = (10 - (tekhanetoplam + cifthanetoplam) % 10) % 10;
    if (imeiNO[14] == i15)
        return 1;
    return -1;

}

#endif 

