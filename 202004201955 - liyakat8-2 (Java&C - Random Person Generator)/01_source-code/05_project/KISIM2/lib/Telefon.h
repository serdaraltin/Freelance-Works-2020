#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void TelefonUret(char*);

void TelefonUret(char* telefon){
	int telefonDizi[11],i;
	telefonDizi[0] = 0;
	telefonDizi[1] = 5;
	telefonDizi[2] = rast(3,5);
	while(telefonDizi[2] < 3 || telefonDizi[1] > 5){
		telefonDizi[2] = rast(3,5);
	}

	for(i=3; i<11; i++){
		telefonDizi[i] = rast(1,9);
	}

	for(i=0; i<11; i++){
		telefon[i] = telefonDizi[i] + 48;
	}
	return;
}
