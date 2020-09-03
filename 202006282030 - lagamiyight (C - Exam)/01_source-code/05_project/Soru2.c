#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int AsalKontrol(int sayi){
	int sinir = sayi /2, i=2;
	while(i <= sinir){
		if(sayi % i == 0)
			return -1;
		i++;
	}
	return 0;
}


int main(){
	srand(time(NULL));

	int matris1[3][3],matris2[3][3],sonuc[3];
	printf("Rastgele uretilecek sayilar icin minimum deger : ");
	int min;
	scanf("%d",&min);
	printf("Rastgele uretilecek sayilar icin maximum deger : ");
	int max;
	scanf("%d",&max);

	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			matris1[i][j] = min + rand() %(max+1 - min);
		}
	}
	printf("Matrix A >> \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%4d",matris1[i][j]);
		}
		printf("\n");
	}

	printf("Ikinci matris icin baslangic degeri : ");
	scanf("%d",&min);

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			while(AsalKontrol(min) == -1)
				min++;
			matris2[i][j] = min++;
		}
	}

	printf("Matrix B >> \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%4d",matris2[i][j]);
		}
		printf("\n");
	}
	
	sonuc[0] = matris1[0][1]+matris1[0][1];
	sonuc[1] = matris1[1][1]+matris1[1][1];
	sonuc[2] = matris1[2][2]+matris1[2][2];
	printf("Sonuc >> \n");
	for(i=0; i<3; i++){
		printf("%4d",sonuc[i]);
	}
	printf("\n");
} 
