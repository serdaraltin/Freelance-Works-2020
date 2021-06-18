#include <stdio.h>
#include <stdlib.h>

struct tambolen
{
	int sayi;
	int* bolenler;
};

typedef struct tambolen TB;

int main(){

	FILE *dosya;
	dosya = fopen("veri.txt","r");

	FILE *cikti;
	cikti = fopen("cikti.txt","w");
	
	while(!feof(dosya)){
		int sayi,bol,bolum;
		fscanf(dosya,"%d",&sayi);

		fprintf(cikti, "%d -> ",sayi );
		int i;
		for(bol = 1; bol<=sayi;bol++){
    		bolum=sayi % bol;
    		if(bolum==0){
    			fprintf(cikti, "%d ",bol );
    		}
    	}

    	fprintf(cikti, "\n");
	}

} 
