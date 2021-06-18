#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//parametre olan gelen sayının polidrom bir sayı olup olmadığını kontrol eden ve
//geriye polidrom ise "1" değilse 0 degeri döndüren fonksiyon
int PolidromKontrol(int sayi){
	int ters = 0, geriKalan, orjinal = sayi;

	while(sayi != 0){
		geriKalan = sayi % 10;
		ters = ters * 10 + geriKalan;
		sayi /= 10;
	}

	if(ters == orjinal)
		return 1;
	return 0;
}

//belirtilen 2^nxn-1 formülünü parametre olarak gelen sayıya uygulayıp sonucu
//geriye döndüren fonksiyon
int FormulUygula(int sayi){
	int i,usluKisim = 1;

	for(i=0; i<sayi; i++)
		usluKisim *= 2;
	return (usluKisim*sayi)-1;
}

int main(){
	//döngüler ve matrisler için değişken tanımları
	int i,j,matris1[3][3],matris2[3][3];

	printf("Bir sayi giriniz : ");
	int sayi;
	scanf("%d",&sayi);
	printf("\nMatris 1 >> \n");

	//iç içe bir döngü ile önce satırlar sonra sütünlar gezilerek girilen sayıdan
	//sonraki sayılar artacak şekilde o anki sayı polidrom olana dek devam eden ve
	//polidrom sayıyı matrisin ilgili konumuna ekleme
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			while(PolidromKontrol(++sayi) == 0){	
			}
			matris1[i][j] = sayi;
		}
	}

	//iç içe bir döngü ile önce satırlar sonra sütünlar gezilerek matrisi(1) yazdırma
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%6d", matris1[i][j] );
		}
		printf("\n");
	}

	printf("Bir sayi giriniz : ");
	scanf("%d",&sayi);
	printf("\nMatris 2 >> \n");

	//iç içe bir döngü ile önce satırlar sonra sütünlar gezilerek girilen sayıdan
	//sonraki sayılar artacak şekilde o anki sayıya formül uygulanarak matrisin
	//ilgili konumuna eklenmesi
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			matris2[i][j] = FormulUygula(++sayi);
		}
	}

	//iç içe bir döngü ile önce satırlar sonra sütünlar gezilerek matrisi(2) yazdırma
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%6d", matris2[i][j] );
		}
		printf("\n");
	}

	//matrislerin köşegenlerindeki ilgili işlemlerin yapılıp yeni bir matrise atanması
	int matris3[2][3];
	matris3[0][0] = matris1[0][0] + matris2[0][0];
	matris3[0][1] = matris1[1][1] + matris2[1][1];
	matris3[0][2] = matris1[2][2] + matris2[2][2];

	matris3[1][0] = matris1[0][2] + matris2[0][2];
	matris3[1][1] = matris1[1][1] + matris2[1][1];
	matris3[1][2] = matris1[2][0] + matris2[2][0];


	printf("\nTBMYO >> \n");
	//iç içe bir döngü ile önce satırlar sonra sütünlar gezilerek matrisi(TBMYO) yazdırma
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%6d", matris3[i][j] );
		}
		printf("\n");
	}

} 
