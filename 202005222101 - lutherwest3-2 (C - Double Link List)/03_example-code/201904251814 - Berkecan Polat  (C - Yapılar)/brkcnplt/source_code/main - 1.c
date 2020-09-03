#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>


/* eger linux uzerinde calistiracaksaniz lutfen <semaphore.h> kutuphanesinin var oldugundan emin olun
kutuphane yok ise edinin ve ard�ndan [#include <semaphore.h>] > [#include "[dosya_yolu]"] seklinde degistirin.
kutuphaneyi edinebileceginiz baglantilar;
https://github.com/torvalds/linux/blob/master/include/linux/semaphore.h
https://github.com/torvalds/linux/tree/master/include/linux
*/


struct node{
	int data;
	struct node *sol;
	struct node *orta;
	struct node *sag;
};

struct node *iter = NULL;
struct node *sifir = NULL;
struct node *bir =  NULL;
struct node *uc =  NULL;
struct node *dort = NULL;
struct node *bes =  NULL;
struct node *alti =  NULL;
struct node *yedi =  NULL;
struct node *iki =  NULL;



void dolas(struct node *agac){
	if(agac->sol == uc->sol){
		printf("%d > %d\n",agac->data,agac->sol->data);
		return;
	}
		
	printf("%d > %d\n",agac->data,agac->sol->data);
	printf("%d > %d\n",agac->data,agac->orta->data);
	printf("%d > %d\n",agac->data,agac->sag->data);
		

	dolas(agac->sol);
	
}





int main(){
	sifir = (struct node*) malloc(sizeof(struct node));
	bir = (struct node*) malloc(sizeof(struct node));
	uc = (struct node*) malloc(sizeof(struct node));
	dort = (struct node*) malloc(sizeof(struct node));
	bes = (struct node*) malloc(sizeof(struct node));
	alti = (struct node*) malloc(sizeof(struct node));
	yedi = (struct node*) malloc(sizeof(struct node));
	
	iki = (struct node*) malloc(sizeof(struct node));


	sifir->data = 0;
	bir->data = 1;
	iki->data = 2;
	uc->data = 3;
	dort->data = 4;
	bes->data = 5;
	alti->data = 6;
	yedi->data = 7;
	
    /* sifir nodesi icin alt nodeler*/
	sifir->sol = bir;
	sifir->orta = uc;
	sifir->sag = dort;
	 /* bir nodesi icin alt nodeler*/
	bir->sol = uc;
	bir->orta = bes;
	bir->sag = alti;
	 /* uc nodesi icin alt nodeler*/
	uc->sol = yedi;
	uc->orta = NULL;
	uc->sag = NULL;
	 /* dort nodesi icin alt nodeler*/
	dort->sol = NULL;
	dort->orta = NULL;
	dort->sag = NULL;
	/* iki nodesi icin alt nodeler*/
	iki->sol = dort;
	iki->orta = bes;
	iki->sag = alti;
	



	dolas(sifir);
	
	

	
	
	//return 0 ;
}





