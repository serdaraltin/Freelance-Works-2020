//kutuphaneler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int plakakodu[82];
int *plakasayi[82];
char *plakaharf[82][100][3];

struct plaka
{
	int *plakasayi;
	char *plakaharf[4];
};

struct plaka PLAKALAR[82][100];


void plakasayisigoster()
{
	int i;
	printf("\n");
	for(i = 1; i < 82;i++)
	{	
		int j,plakasayi = 0;
		for(j = 0; PLAKALAR[i][j].plakasayi > 1; j++){
			plakasayi ++;
		}
		printf("%d -> %d \n",i,plakasayi);
	
	}
	
}

void sehirplakasayisigoster(int plaka)
{
	printf("\n");
	int j ;
	for(j = 0; PLAKALAR[plaka][j].plakasayi > 1; j++){
		printf("%d. Plaka: %s %d\n",j,PLAKALAR[plaka][j].plakaharf,PLAKALAR[plaka][j].plakasayi);
	}
}

void plakaekle(int plaka)
{
	printf("\nPlaka Sayi Giriniz: ");
	
	int pkod;
	
	char h1,h2,h3;
	
	scanf("%d",&pkod);
			
		if(pkod > 0 && pkod <= 9999)
		{
			int j,plakasirasi = 0;
			for(j = 0; PLAKALAR[plaka][j].plakasayi > 1; j++){
				plakasirasi ++;
			}
			
			printf("\nPlaka Harf Giriniz : ");
			
			scanf("%s",PLAKALAR[plaka][plakasirasi].plakaharf);

			PLAKALAR[plaka][plakasirasi].plakasayi = pkod;
			
			printf("\nplakasirasi : %d\n",plakasirasi);
			
			printf("Plaka Eklendi -> %d  %d  %s \n ",plaka,PLAKALAR[plaka][plakasirasi].plakasayi,PLAKALAR[plaka][plakasirasi].plakaharf);
		}
		else
		{ 
			printf("\nPlaka Kodu En fazla 4 haneli olabilir.\n");
		}
		
}


void dosyadanplakaekle(char dosya[])
{
	FILE *plakadosya;
    plakadosya = fopen(dosya,"r");

	printf("\n");
    if(plakadosya != NULL)
	{
		int *plakasayi;
		char *plakaharf[4];
		
		while(!feof(plakadosya))
		{
			int j,plakasirasi = 0, plaka;
			for(j = 0; PLAKALAR[plaka][j].plakasayi > 1; j++){
				plakasirasi ++;
			}
			
			fscanf(plakadosya, "%d",&plaka);
			
			fscanf(plakadosya, "%s %d",PLAKALAR[plaka][plakasirasi].plakaharf,&PLAKALAR[plaka][plakasirasi].plakasayi);
			
			printf("\nEklenen -> %d %s %d",plaka,PLAKALAR[plaka][plakasirasi].plakaharf,PLAKALAR[plaka][plakasirasi].plakasayi);
		}
		fclose(plakadosya);
	}
	else
	{
        printf("Dosya bulunamadi !\n\n");
    }
	printf("\n\n");
}

void plakalarilistele(){
	printf("\n");
	int i,j;
	for(i = 1; i < 82;i++)
	{	
		int j,plakasayi = 0;
		for(j = 0; PLAKALAR[i][j].plakasayi > 1; j++){
			printf("%d. Plaka: %s %d\n",j+1,PLAKALAR[i][j].plakaharf,PLAKALAR[i][j].plakasayi);
		}

	}
	printf("\n");
}

void plakalariyazdir(char dosya[]){
	printf("\n");
	
	FILE * plakadosya;
	
	plakadosya = fopen(dosya,"w");
	if(plakadosya != NULL)
	{
		int i,j;
		for(i = 1; i < 82;i++)
		{	
			int j,plakasayi = 0;
			for(j = 0; PLAKALAR[i][j].plakasayi > 1; j++){
				printf("%d. Plaka: %s %d\n",j+1,PLAKALAR[i][j].plakaharf,PLAKALAR[i][j].plakasayi);
			}

		}
		fclose(plakadosya);
		printf("\nPlakalar yazdirildi...");
	}
	else
	{
        printf("Dosya bulunamadi !\n\n");
    }
}
void sehirplakalariyazdir(char dosya[], int plaka){
	printf("\n");
	
	FILE * plakadosya;
	
	plakadosya = fopen(dosya,"w");
	if(plakadosya != NULL)
	{
		int i,j;
		for(j = 0; PLAKALAR[plaka][j].plakasayi > 1; j++){
			printf("%d. Plaka: %s %d\n",j+1,PLAKALAR[plaka][j].plakaharf,PLAKALAR[plaka][j].plakasayi);
			
		}
		fclose(plakadosya);
		printf("\nSehir Plakalar yazdirildi...");
	}
	else
	{
        printf("Dosya bulunamadi !\n\n");
    }
}
int main(int argc, char *argv[]) {

	int i;
	for(i=0;i<82;i++)
	{
		plakasayi[i]=(int *)realloc(plakasayi[i],81*sizeof(int));		
	}
	
	int secim;
	while(secim!=0)
	{
		printf("\n1-Girilen Plakalari Goster.\n2-Bir sehire Kayitli Plakalari Goster\n3-Yeni Plaka Ekle.\n4-Dosyadan Plaka Ekle\n5-Tum Plakalari Listele\n6-Plakalari Dosyaya Yazdir\n7-Sehir Plakalari Dosyaya Yazdir\n0-Cikis.\n\nSecim : ");
		scanf("%d",&secim);
	

	if(secim==1)
	{
		plakasayisigoster();
	}
	
	else if(secim==2)
	{
		printf("\nSehrin Plaka Kodunu Giriniz: ");
		int plakasecim;
		scanf("%d",&plakasecim);
		if(plakasecim>0&&plakasecim<=81){
		sehirplakasayisigoster(plakasecim);}
		else{
			printf("\nGecersiz plaka girdiniz.\n");
		}
	}
	
	else if(secim==3)
	{
		printf("\nHangi Sehire Plaka Eklemek Istiyorsunuz? : ");
		int plaka;
		scanf("%d",&plaka);
		if(plaka>0&&plaka<=81){
		plakakodu[plaka]++;
		plakaekle(plaka);}
		else
		{
			printf("Gecersiz plaka girdiniz.");
		}
		
	}	
	else if(secim == 4)
	{
		printf("\nDosya Yolu : ");
		char *dosya[250];
		scanf("%s",dosya);
		dosyadanplakaekle(dosya);
	}
	else if(secim == 5)
	{
		plakalarilistele();
	}
	else if(secim = 6)
	{
		printf("Dosya Yolu : ");
		char *dosya[250];
		scanf("%s",dosya);
		plakalariyazdir(dosya);
	}
	else if(secim = 7)
	{
		printf("Sehir Plaka Kodu : ");
		int plaka;
		scanf("%d",&plaka);
		printf("Dosya Yolu : ");
		char *dosya[250];
		scanf("%s",dosya);
		sehirplakalariyazdir(dosya,plaka);
	}
	}
	return 0;
}

