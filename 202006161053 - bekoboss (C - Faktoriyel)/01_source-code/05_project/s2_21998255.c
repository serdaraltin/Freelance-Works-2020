#include <stdio.h>
#include <stdlib.h>


void dizi_modla(int dizi[],int boyut){
	int i;
	for (i = 0; i < boyut; ++i){
		if(dizi[i] > 5)
			dizi[i] %= 5;
	}
}

void dizi_yazdir(int dizi[],int boyut){
	int i;
	for (i = 0; i < boyut; ++i)
		printf("%3d", dizi[i]);
	printf("\n");
}

void faktoriyel_for(int dizi[]){
	int i,j,faktoriyel;
	for (i = 0; i < 4; ++i){
		faktoriyel = 1;
		printf("%d inci Sayi= %d!= ",i,dizi[i]);
		for (j = dizi[i]; j > 0; j--){
			faktoriyel *= j;

			if(j==dizi[i])
				printf("%d",j);
			else
				printf("*%d",j);
		}
		printf(" ve --> %d\n",faktoriyel);
	}
}
void faktoriyel_while(int dizi[]){
	int i,j,faktoriyel;
	i= 4;
	while(i<7){
		faktoriyel = 1;
		printf("%d inci Sayi= %d!= ",i,dizi[i]);
		j = dizi[i];
		while(j>0){
			faktoriyel *= j;

			if(j==dizi[i])
				printf("%d",j);
			else
				printf("*%d",j);
			j--;
		}
		printf(" ve --> %d\n",faktoriyel);
		i++;
	}
}

int main(){
	//21998255
	int i,j,faktoriyel;
	int ogrNo[7] = {2,1,9,9,8,2,5};

	printf("Verilen dizi\t : ");
	dizi_yazdir(ogrNo,7);

	dizi_modla(ogrNo,7);
	printf("Duzeltilmis dizi : ");
	dizi_yazdir(ogrNo,7);


	while(1){
		printf("Faktoriyel hesabi Dongu turunu giriniz : 1 ya da 2 ? : ");
		int donguTuru;
		scanf("%d",&donguTuru);

		switch(donguTuru){
			case 1:
				faktoriyel_for(ogrNo);
				break;
			case 2:
				faktoriyel_while(ogrNo);
				break;
			default:
			printf("Hatali bir secim yaptiniz!\n");
				break;
		}
	}
} 


