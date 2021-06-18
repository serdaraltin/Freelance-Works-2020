#ifndef TCNOURET_H
#define TCNOURET_H
int tcDogrula(char* tcno) {
    if (strlen(tcno) > 11)
        return -1;
    int arrayTc[11], i;
    for (i = 0; i < 11; i++)
        arrayTc[i] = (int) (tcno[i] - 48);
    int han10, han11, b = 0;han10 = ((arrayTc[0] + arrayTc[2] + arrayTc[4] + arrayTc[6] + arrayTc[8]) * 7 - (arrayTc[1] + arrayTc[3] + arrayTc[5] + arrayTc[7])) % 10;
    for (i = 0; i <= 9; i++)
        b += arrayTc[i];
    han11 = b % 10;
    if (arrayTc[9] == han10 && arrayTc[10] == han11)
        return 1;
    else
        return -1;
}
void tcUret(char* tcno) {int arrayTc[11], i;arrayTc[0] = rast(1, 9);
    for (i = 1; i < 6; i++) 
        arrayTc[i] = rast(0, 10);
    for (i = 6; i < 10; i++) 
        arrayTc[i] = rast(0, 11);
    arrayTc[9] = (((arrayTc[0] + arrayTc[2] + arrayTc[4] + arrayTc[6] + arrayTc[8]) *7) - (arrayTc[1] + arrayTc[3] + arrayTc[5] + arrayTc[7])) % 10;arrayTc[10] = (arrayTc[0] + arrayTc[1] + arrayTc[2] + arrayTc[3] + arrayTc[4] + arrayTc[5] + arrayTc[6] + arrayTc[7] + arrayTc[8] + arrayTc[9]) % 10;
    int index = 0;
    for (i = 0; i < 11; i++)
        index += snprintf(&tcno[index], 128 - index, "%d", arrayTc[i]);}
#endif

