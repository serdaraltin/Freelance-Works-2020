#include <stdio.h>
#include <stdlib.h>

void yonetici();
void isci();
void partime();
void menu_goster();
void sayi_gir();

int main(){
	menu_goster();
} 

void menu_goster(){
	printf("1. Yonetici\n");
	printf("2. Isci\n");
	printf("3. Part-Time\n");
	printf("\nSecim : ");
	sayi_gir();
	menu_goster();
}

void sayi_gir(){
	int sec;
	scanf("%d",&sec);

	if(sec == 1)
		yonetici();
    else if(sec == 2)
		isci();
	else if(sec == 3)
		partime();
	else{
		printf("Tekrar deneyiniz!!!\n");
		sayi_gir();
	}
}


void yonetici(){
	printf("Fazla mesai ne kadar [Yoksa 0 giriniz]: ");
	int fm;
	scanf("%d",&fm);
	int maas = 2000 + (fm*40);
	printf("Yonetici %d Lira maas almaktadir\n", maas);
}

void isci(){
	printf("Fazla mesai ne kadar [Yoksa 0 giriniz]: ");
	int fm;
	scanf("%d",&fm);
	int maas = 1000 + (fm*25);
	printf("Isci %d Lira maas almaktadir\n", maas);
}

void partime(){
	printf("Mesai saati : ");
	int ms;
	scanf("%d",&ms);
	int maas = (ms*65);
	printf("Part-Time %d Lira maas almaktadir\n",maas);
}
