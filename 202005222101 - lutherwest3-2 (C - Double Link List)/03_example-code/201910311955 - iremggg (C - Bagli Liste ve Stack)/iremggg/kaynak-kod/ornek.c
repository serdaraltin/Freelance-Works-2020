#include <stdio.h>
#include <stdlib.h>


struct eleman{
	int* deger;
	struct eleman *sonraki;
};

typedef struct eleman Eleman;


void push(int val, Eleman *head);
int pop(Eleman *head);

int main(){
	
	Eleman *baslangic,*bitis;
	
	int deger;
	
	
	baslangic = (Eleman*)malloc(sizeof(Eleman));
	bitis = (Eleman*)malloc(sizeof(Eleman));
	
	baslangic->sonraki = bitis;
	
	do{
		printf("Deger giriniz (cikis icin -1) > ");
		scanf("%d",&deger);
		
		if(deger != -1){
			push(deger,baslangic);
		}
		
		
	}while(deger != -1);
	
	printf("Yigin\'nin ustten alta durumu > \n");
	
	do{
		printf("%d->",pop(baslangic))	;
	}while(baslangic->sonraki != bitis);
		
}

void push(int val, Eleman *baslangic){
	Eleman *eklenecek;
	eklenecek = (Eleman*)malloc(sizeof(Eleman));
	eklenecek->deger = val;
	eklenecek->sonraki = baslangic->sonraki;
	baslangic->sonraki = eklenecek;
}

int pop(Eleman *baslangic){
	Eleman *gecici;
	int val = baslangic->sonraki->deger;
	gecici = baslangic->sonraki;
	baslangic->sonraki = baslangic->sonraki->sonraki;
	free(gecici);
	return val;
}
