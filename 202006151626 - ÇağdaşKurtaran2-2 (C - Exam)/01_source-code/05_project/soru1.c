#include <stdio.h>
#include <stdlib.h>



void menu_goster();
void sayi_gir();
void yonetici();
void isci();
void partime();

int main(){
	menu_goster();
} 

void menu_goster(){
	printf("1. Yonetici\n");
	printf("2. Isci\n");
	printf("3. Part-Time\n");
	printf("\nSecim : ");
	sayi_gir();
	printf("\n");
	menu_goster();
}

void sayi_gir(){
	int secim;
	scanf("%d",&secim);

	switch(secim){

		case 1:
			//Yonetici
			yonetici();
			break;
		case 2:
			//Isci
			isci();
			break;
		case 3:
			//PartTime
			partime();
			break;
		default:
			printf("Hatali bir secim yapildi! Tekrar seciniz\n");
			sayi_gir();
			break;
	}
}

void yonetici(){
	int maas,fazlaMesaiKontrol,fazlaMesai;
	maas = 2000;
	printf("Fazla mesai yapildi mi ?[E=1/H=0] : ");
	scanf("%d",&fazlaMesaiKontrol);
	if(fazlaMesaiKontrol == 1){
		printf("Fazla mesai ne kadar : ");
		scanf("%d",&fazlaMesai);
		maas += (fazlaMesai*40);
	}
	printf("Yonetici maasi %d Lira olarak hesaplanmistir\n",maas);
}

void isci(){
	int maas,fazlaMesaiKontrol,fazlaMesai;
	maas = 1000;
	printf("Fazla mesai yapildi mi ?[E=1/H=0] : ");
	scanf("%d",&fazlaMesaiKontrol);
	if(fazlaMesaiKontrol == 1){
		printf("Fazla mesai ne kadar : ");
		scanf("%d",&fazlaMesai);
		maas += (fazlaMesai*25);
	}
	printf("Isci maasi %d Lira olarak hesaplanmistir\n",maas);
}

void partime(){
	int maas,mesai;
	maas = 0;

	printf("Mesai ne kadar : ");
	scanf("%d",&mesai);
	maas += (mesai*65);

	printf("Part-Time maasi %d Lira olarak hesaplanmistir\n",maas);
}
