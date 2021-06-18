#ifndef TELURET_H
#define TELURET_H
void TUret(char* argtel) {int arrtel[11], i;
    arrtel[0] = 0; arrtel[1] = 5;arrtel[2] = rast(3, 5);
    for (i = 3; i < 11; i++) 
        arrtel[i] = rast(1, 9);
    int index = 0;
    for (i = 0; i < 11; i++) index += snprintf(&argtel[index], 128 - index, "%d", arrtel[i]);}
#endif

