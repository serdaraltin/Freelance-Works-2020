#ifndef TCNOURET_H
#define TCNOURET_H

void tcekle(char* tcno) {
    int tcDizi[11], i;

    tcDizi[0] = rast(1,9);
    
    for(i=1; i<6; i++){
        tcDizi[i] = rast(0,10);
    }
    for(i=6; i<10; i++){
        tcDizi[i] = rast(0,11);
    }
    
    tcDizi[9] = (((tcDizi[0]+tcDizi[2]+tcDizi[4]+tcDizi[6]+tcDizi[8]) *7) - (tcDizi[1]+tcDizi[3]+tcDizi[5]+tcDizi[7])) % 10;
    tcDizi[10] = (tcDizi[0]+tcDizi[1]+tcDizi[2]+tcDizi[3]+tcDizi[4]+tcDizi[5]+tcDizi[6]+tcDizi[7]+tcDizi[8]+tcDizi[9]) % 10;
    int index = 0;
    for (i = 0; i < 11; i++) {
        index += snprintf(&tcno[index], 128-index, "%d", tcDizi[i]);  
    }
    return;
}

int tcdogrula(char* tcno) {
    int tcnoLen = strlen(tcno);
    if (tcnoLen > 11) {
        return -1;
    }
    int TcDizi[11], i;
    for (i = 0; i < tcnoLen; i++) {
        TcDizi[i] = (int) (tcno[i] - 48);
    }
    int Hane10, Hane11, yedek2 = 0;
    Hane10 = ((TcDizi[0] + TcDizi[2] + TcDizi[4] + TcDizi[6] + TcDizi[8]) * 7 - (TcDizi[1] + TcDizi[3] + TcDizi[5] + TcDizi[7])) % 10;
    for (i = 0; i <= 9; i++) {
        yedek2 += TcDizi[i];
    }
    Hane11 = yedek2 % 10;
    if (TcDizi[9] == Hane10 && TcDizi[10] == Hane11) {
        return 1;
    } else {
        return -1;
    }
}
#endif

