#include <stdio.h>
#include <stdlib.h>

int dizi_boyut(char*);
int dizi_yeni_boyut_bul(char *dizi);
int numarami(char str);
void yeni_dizi_olustur(char *dizi, char *yeniDizi);

int main(){
	char *dizi = (char*)malloc(sizeof(char)*100);;

	printf("Metin giriniz [orn : A3R2K3Y4V1D2] : ");
	scanf("%s",dizi);

	char *yeniDizi = (char*)malloc(sizeof(char)*dizi_yeni_boyut_bul(dizi));

	yeni_dizi_olustur(dizi,yeniDizi);

	printf("SONUC : %s\n",yeniDizi );
} 

int dizi_boyut(char *dizi){
	int i = 0;
	while(dizi[i] !='\0')
		i++;
	return i;
}

int dizi_yeni_boyut_bul(char *dizi){
	int i, yeniBoyut = 0;
	for(i=0; i<dizi_boyut(dizi); i++){
		if(numarami(dizi[i]) == 1)
			yeniBoyut += dizi[i] - '0';
	}
	return yeniBoyut;
}

int numarami(char str) {	
    if(str < '0' || str > '9')
        return -1;
    return 1;
}

void yeni_dizi_olustur(char *dizi, char *yeniDizi){
	int i,j, eklenenUzunluk = 0;
	int diziBoyut = dizi_boyut(dizi);

	for (i = 0; i < diziBoyut; i++){
		if(numarami(dizi[i]) == 1){
			int adet = dizi[i] - '0';
			for(j=0; j<adet; j++)
				yeniDizi[eklenenUzunluk++] = dizi[i-1];
		}
	}
}