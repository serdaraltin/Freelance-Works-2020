#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Rastgele.h"

void ImeiUret(char*);
int ImeiKontrol(char*);

void ImeiUret(char *imei){
	int imeiDizi[15],Tsayi = 0, Csayi = 0, yedek = 0,i;

	for(i=0; i<15; i++){
		imeiDizi[i] = rast(1,9);
	}

	for(i=0; i<=12; i+=2){
		Tsayi += imeiDizi[i];
	}

	for(i=1; i<=13; i+=2){
		yedek = imeiDizi[i] * 2;
		if(yedek > 9){
			yedek = yedek - 9;
		}
		Csayi += yedek;
	}
	yedek = Csayi + Tsayi;

	double Yyedek = ((ceil(yedek/10))* 10) + 10;

	if((int)Yyedek - yedek > 9){
		imeiDizi[14] = ((int)Yyedek - yedek) % 10;
	}
	else{
		imeiDizi[14] = (int)Yyedek - yedek;
	}

	for(i=0; i<15; i++){
		imei[i] = imeiDizi[i] + 48;
	}
	return ;
}

int ImeiKontrol(char* imei){
	int imeiLen = strlen(imei);
	int KTsayi = 0, KCsayi = 0;
	int imeiDizi[imeiLen],i;

	if(imeiLen != 15){
		return -1;
	}

	int last = imei[14] - 48;

    int curr;
    int sum = 0;
    for (i = 0; i < 14; i++) {
        curr = imei[i] - 48;
        if (i % 2 != 0){
        
            curr = 2 * curr;
            if(curr > 9) {
                curr = (curr / 10) + (curr - 10);
            }
            sum += curr;
        }
        else {
            sum += curr;
        }

    }
	int round = sum % 10 == 0 ? sum : ((sum / 10 + 1) * 10);

    return (round - sum == last) ? 1 : -1;

}
