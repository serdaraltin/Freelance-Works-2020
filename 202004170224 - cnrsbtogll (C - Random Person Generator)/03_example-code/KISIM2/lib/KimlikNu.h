#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Rastgele.h"

void TcNoUret(char*);
int TcNoKontrol(char*);

void TcNoUret(char* tcno){
	int tcDizi[11], yedek = 0,i;

	for (i=0; i < 11; i++)
	{
		if(i == 0){
			tcDizi[0] = rast(1,9);
		}
		else if(i < 10){
			tcDizi[i] = rast(1,9);
		}
	}
	tcDizi[9] = (((tcDizi[0] + tcDizi[2] + tcDizi[4] + tcDizi[6] + tcDizi[8]) * 7) - (tcDizi[1] + tcDizi[3] + tcDizi[5] + tcDizi[7])) % 10;
	for(i=0; i<=9; i++){
		yedek += tcDizi[i];
	}	
	tcDizi[10] = yedek % 10;
	for(i=0; i<11; i++){
		tcno[i] = tcDizi[i] + 48;
	}
	return;
}

int TcNoKontrol(char* tcno){
	int tcnoLen = strlen(tcno);
	    if (tcnoLen!= 11) {
            return -1;
        }
        int TcDizi[11],i;
        for (i = 0; i <tcnoLen; i++) {
            TcDizi[i] = (int)(tcno[i] - 48);
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


