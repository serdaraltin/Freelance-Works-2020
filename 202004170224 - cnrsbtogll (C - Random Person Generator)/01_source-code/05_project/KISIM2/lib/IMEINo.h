#ifndef IMEIURET_H
#define IMEIURET_H
#include  <string.h>
#include "Rastgele.h"
int IMDogrula(char* imno) {int ss, sum = 0, i;
    if (strlen(imno) != 15)
        return -1;int ls = imno[14] - 48;
    for (i = 0; i < 14; i++) {
        ss = imno[i] - 48;
        if (i % 2 != 0) {ss = 2 * ss;
            if (ss > 9) {
                ss = (ss / 10) + (ss - 10);
            } sum += ss; } else sum += ss;}int hesap = sum % 10 == 0 ? sum : ((sum / 10 + 1) * 10);
    if (hesap - sum == ls)
        return 1;
    else
        return -1;
}
void IMUret(char *imno) {int arrayimei[15], i , sum = 0 ,c = 0;arrayimei[0] = rast(1, 9);
    for (int i = 1; i < 14; i++)
        arrayimei[i] = rast(0, 11);
    for (int i = 0; i < 7; i++) {sum = sum + arrayimei[i * 2];
        if (arrayimei[1 + i * 2] * 2 >= 10) {
            int o = arrayimei[1 + i * 2] * 2 / 10;
            int b = arrayimei[1 + i * 2] * 2 % 10;
            c = c + o + b;} else
            c = c + arrayimei[1 + i * 2] * 2;
    } arrayimei[14] = (10 - (sum + c) % 10) % 10;int inx = 0;
    for (i = 0; i < 15; i++)
        inx += snprintf(&imno[inx], 128 - inx, "%d", arrayimei[i]);}
#endif 