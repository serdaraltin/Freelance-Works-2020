#include "stdafx.h"
#include <stdlib.h>

int matrisA[2][2] = { { -1,3 },{ 9,-3 } };
int matrisB[2][2] = { { 0,5 },{ -2,4 } };

void menu();

void MatrislerinToplami() {
	int matrisToplam[2][2];

	int i, j;

	for (i = 0; i<2; i++) {
		for (j = 0; j<2; j++) {
			matrisToplam[i][j] = matrisA[i][j] + matrisB[i][j];
		}
	}
	printf("Matris Toplami:\n");
	for (i = 0; i<2; i++) {
		for (j = 0; j<2; j++) {
			printf("%3d ", matrisToplam[i][j]);
		}
		printf("\n");
	}
}

void MatrislerinCarpimi() {
	int matrisCarpim[2][2];

	int i, j, k;

	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{
			matrisCarpim[i][j] = 0;
			for (k = 0; k<2; k++)
			{
				matrisCarpim[i][j] += matrisA[i][k] * matrisB[k][j];
			}
		}
	}
	printf("Matris Carpimi:\n");
	for (i = 0; i<2; i++) {
		for (j = 0; j<2; j++) {
			printf("%3d ", matrisCarpim[i][j]);
		}
		printf("\n");
	}


}

void AltMenu() {
	printf("A matrisi 1. satir (orn > 5 3):");
	scanf("%d %d", &matrisA[0][0], &matrisA[0][1]);
	printf("A matrisi 2. satir (orn > 5 3):");
	scanf("%d %d", &matrisA[1][0], &matrisA[1][1]);

	printf("B matrisi 1. satir (orn > 5 3):");
	scanf("%d %d", &matrisB[0][0], &matrisB[0][1]);
	printf("B matrisi 2. satir (orn > 5 3):");
	scanf("%d %d", &matrisB[1][0], &matrisB[1][1]);
	return;
}

int main()
{
	menu();
    return 0;
}

void menu() {
	printf("1-Matrislerin Toplami\n");
	printf("2-Matrislerin Carpimi\n");
	printf("3-Matrisleri ben girmek istiyorum\n");
	printf("4-Cikis\n\n");
	printf("Seciminiz:");
	int secim;
	scanf("%d", &secim);
	switch (secim)
	{
	case 1:
		MatrislerinToplami();
		break;
	case 2:
		MatrislerinCarpimi();
		break;
	case 3:
		AltMenu();
		break;
	case 4:
		printf("Programdan cikiliyor...\n");
		exit(0);
		break;
	default:
		printf("Hatali secim, tekrar deneyiniz\n");
		break;
	}
	printf("\n");
	menu();

}