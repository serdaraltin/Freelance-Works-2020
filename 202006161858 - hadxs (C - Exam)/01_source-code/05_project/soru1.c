#include <stdio.h>
#include <stdlib.h>

void sayi_gir();
void yonetici();
void menu_goster();
void isci();
void partime();

int main(){
	menu_goster();
} 
void partime(){
	int ucret,ms;
	ucret = 0;
	printf("Mesai saati : ");
	scanf("%d",&ms);
	printf("Maas : %d TL\n",ms*65);
}

void isci(){
	int mKontrol,mesai=0;
	printf("Mesai yapildi mi ?[E=1/H=0] : ");
	scanf("%d",&mKontrol);
	if(mKontrol == 1){
		printf("Mesai kac saat : ");
		scanf("%d",&mesai);
	}
	printf("Maas : %d TL\n",1000+(mesai*25));
}

void sayi_gir(){
	int sec;
	scanf("%d",&sec);

	switch(sec){
		case 3:
			partime();
			break;
		case 2:
			isci();
			break;
		case 1:
			yonetici();
			break;
		default:
			printf("Tekrar deneyiniz\n");
			sayi_gir();
			break;
	}
}

void yonetici(){
	int ucret,mKontrol,mesai=0;
	ucret = 2000;
	printf("Mesai yapildi mi ?[E=1/H=0] : ");
	scanf("%d",&mKontrol);
	if(mKontrol == 1){
		printf("Mesai kac saat : ");
		scanf("%d",&mesai);
	}
	printf("Maas : %d TL\n",2000+(mesai*40));
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


