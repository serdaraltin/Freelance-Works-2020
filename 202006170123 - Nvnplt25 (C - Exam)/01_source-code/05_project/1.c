#include <stdio.h>
#include <stdlib.h>

void yonetici();
void sayi_gir();
void isci();
void menu_goster();
void partime();


int main(){
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
		printf("Tekrar deneyin!\n");
		sayi_gir();
	}
}

void yonetici(){
	printf("Mesai ne kadar [Yoksa 0]: ");
	int fazlaMes;
	scanf("%d",&fazlaMes);
	int ms = 2000 + (fazlaMes*40);
	printf("%d Lira ms almaktadir\n", ms);
}

void isci(){
	printf("Mesai ne kadar [Yoksa 0]: ");
	int fazlaMes;
	scanf("%d",&fazlaMes);
	int ms = 1000 + (fazlaMes*25);
	printf("%d Lira ms almaktadir\n", ms);
}

void partime(){
	printf("Mesai saati : ");
	int ms;
	scanf("%d",&ms);
	int mas = (ms*65);
	printf("%d Lira ms almaktadir\n",mas);
}

void menu_goster(){
	printf("1. Yonetici\n");
	printf("2. Isci\n");
	printf("3. Part-Time\n");
	printf("\nSecim : ");
	sayi_gir();
	menu_goster();
}




