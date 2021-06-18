#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct dugum{
	struct dugum** Iyilestirme_liste;
	struct dugum* Sonraki;
	char* isim;
	int x;
	int y;
	int Maks_PP;
	int Mevcut_PP;
	int carpilan;
	int iyilestirme_miktari;
	int saglik;};
typedef struct dugum Kisi;
int initial_range;
int jump_range;
int num_jumps;
float initial_power;
float power_reduction;
int** saglik;
int en_iyi_saglik;
int toplam_iyilestirme;
int** gecerli_saglik;
Kisi** gecici_yol;
Kisi** en_iyi_yol;
Kisi* gecerli;
Kisi* gecici;
Kisi* ilk;
Kisi* kontol2;
Kisi* kontol;
void Hesapla(Kisi*,int,int,int,Kisi*,int);
int main(int argc, char* argv[]){
	FILE *dosya = stdin;
	initial_range = atoi(argv[1]);
	jump_range = atoi(argv[2]);
	num_jumps = atoi(argv[3]);
	initial_power = atoi(argv[4]);
	power_reduction = atof(argv[5]);
	int sayac = 0;
	//printf("%d %d %d %d %f\n",initial_power,jump_range,num_jumps,initial_range,power_reduction );
	int x;
	int y;
	int Maks_PP;
	int Mevcut_PP;
	char* isim = (char*)malloc(sizeof(char)*50);
	ilk = (Kisi*)malloc(sizeof(Kisi));
	ilk = NULL;
	gecerli = (Kisi*)malloc(sizeof(Kisi));
	while(fscanf(dosya,"%d %d %d %d %s", &x,&y, &Mevcut_PP,&Maks_PP,isim) != EOF){
		gecici = (Kisi*)malloc(sizeof(Kisi));
		gecici->x = x;
		gecici->y = y;
		gecici->Mevcut_PP = Mevcut_PP;
		gecici->Maks_PP = Maks_PP;
		gecici->isim = (char*)malloc(sizeof(char)*50);
		strcpy(gecici->isim,isim);
		//perror("gecti");
		if(sayac <= 0){
			ilk = gecici;
			ilk->Sonraki = NULL;
			gecerli = ilk;	
		}
		else{
			gecerli->Sonraki = gecici;
			gecerli = gecici;
			gecerli->Sonraki = NULL;
		}
		//free(gecici);
		sayac++;
	}
	fclose(dosya);
	gecerli = ilk;
	int sayac2 = 0;
	Kisi* ic = (Kisi*)malloc(sizeof(Kisi));
	Kisi* dis = (Kisi*)malloc(sizeof(Kisi));
	dis = ilk;
//perror("gecti");
	while(dis){
		int sayac3 = 0;
		ic = ilk;
		while(ic){
			if(ic != dis){
				float konum = sqrt(((dis->x - ic->x)*(dis->x - ic->x)) + ((dis->y - ic->y)*(dis->y
                        - ic->y)));
				if(konum <= jump_range)
					sayac3++;
			}
			ic = ic->Sonraki;
		}
		dis->iyilestirme_miktari = sayac3;
		dis = dis->Sonraki;
	}
	gecerli = ilk;
	dis = ilk;
//perror("gecti");
	while(dis){
		dis->Iyilestirme_liste = (Kisi**)malloc(dis->iyilestirme_miktari*sizeof(Kisi*));
		int sira_sayac = 0;
		ic = ilk;
		while(ic){
			if(ic != dis){
				float konum =  sqrt(((dis->x - ic->x)*(dis->x - ic->x)) + ((dis->y -
                        ic->y)*(dis->y - ic->y)));
				if(konum <= jump_range)
					dis->Iyilestirme_liste[sira_sayac++] = ic;
			}
			ic = ic->Sonraki;
		}
		dis = dis->Sonraki;
	}
	gecici_yol = (Kisi**)malloc(num_jumps*sizeof(Kisi*));
	gecerli_saglik = (int**)malloc(num_jumps*sizeof(int*));
	en_iyi_yol = (Kisi**)malloc(sizeof(Kisi*)*num_jumps);
	saglik = (int**)malloc(num_jumps*sizeof(int*));
	kontol = (Kisi*)malloc(sizeof(Kisi));
	kontol2 = (Kisi*)malloc(sizeof(Kisi));
	en_iyi_saglik = 0;
	int sayac4;
	gecerli = ilk;
//perror("gecti");	
	for(sayac4 =0; sayac4 < sayac; sayac4++){
		float konum = sqrt(((ilk->x - gecerli->x)*(ilk->x - gecerli->x)) +
                ((ilk->y - gecerli->y)*(ilk->y - gecerli->y)));
		if(konum <= initial_range){
			Hesapla(gecerli, 1, num_jumps,0, NULL, 0);
			gecerli = gecerli->Sonraki;}
	}
//perror("gecti");
	printf("Toplan_Iyilesme: %d\n",toplam_iyilestirme);
	return 0;
}
void Hesapla(Kisi* secilen, int v, int fnum_jumps, int toplam_saglik, Kisi* iyilestiren, int liste_sayac){
	int saglik_gereksinimi;
	int i;
	float finitial_power = initial_power;
	if(v > fnum_jumps || secilen->carpilan == 1){
		secilen->carpilan = 0;
		return;}
//perror("gecti");
	int adet;
	gecici_yol[liste_sayac] = secilen;
	if(fnum_jumps -1 == liste_sayac){
		
		for(i=0; i < fnum_jumps; i++){
			saglik_gereksinimi =gecici_yol[i]->Maks_PP - gecici_yol[i]->Mevcut_PP;
			if(saglik_gereksinimi < initial_power){
				gecici_yol[i]->saglik = saglik_gereksinimi;}
			else{
				gecici_yol[i]->saglik = rint(initial_power);}
			initial_power *= (1 - power_reduction);
			toplam_saglik += gecici_yol[i]->saglik;
			toplam_iyilestirme = toplam_saglik;
			printf("%s %d\n",gecici_yol[i]->isim, gecici_yol[i]->saglik);
		}
	    int j;
		int x;
//perror("gecti");
		for(i=0; i< fnum_jumps-1; i++){
			for(j = i+1; j < fnum_jumps; j++){
				kontol = gecici_yol[i];
				kontol2 = gecici_yol[j];
				if(kontol2 == kontol){
					toplam_saglik = 0;
				}
			}	
		}
		initial_power = finitial_power;
//perror("gecti");
		if(en_iyi_saglik < toplam_saglik){
			en_iyi_saglik = toplam_saglik;
			for(x=0; x < fnum_jumps; x++){
				en_iyi_yol[x] = gecici_yol[x];
				saglik[x] = gecerli_saglik[x];
			}
		}
	}
	for(i = 0; i < secilen->iyilestirme_miktari; i++){
		secilen->carpilan = 1;
		Hesapla(secilen->Iyilestirme_liste[i], v+1, fnum_jumps, toplam_saglik, secilen->Sonraki,liste_sayac+1);
	}
//perror("gecti");
}