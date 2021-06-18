#ifndef TELURET_H
#define TELURET_H

void telekle(char* telefon) {
    int telefonDizi[11], i;
    telefonDizi[0] = 0;
    telefonDizi[1] = 5;
    telefonDizi[2] = rast(3, 5);

    for (i = 3; i < 11; i++) {
        telefonDizi[i] = rast(1, 9);
    }

    int index = 0;
    for (i = 0; i < 11; i++) {
        index += snprintf(&telefon[index], 128 - index, "%d", telefonDizi[i]);
    }

    return;
}
#endif

