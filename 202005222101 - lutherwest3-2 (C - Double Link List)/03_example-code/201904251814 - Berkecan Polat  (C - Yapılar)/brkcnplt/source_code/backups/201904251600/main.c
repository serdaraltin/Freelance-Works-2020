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
sem_t mutex; //


struct node{
	int data;
	struct node *sol;
	struct node *orta;
	struct node *sag;
	struct node *ust;
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



void calistir(struct node * agac){
	if(agac->sol == uc->sol){
		
		//return;
	}
	
	printf("job%d done\n",agac->data);
	calistir(agac->sol);
}

void dolas2(struct node *agac){

	
	if(agac == uc)
	{
		
		iter = agac->sol;
		printf("job%d is waiting for job%d",iter->data,iter->ust->data);
    	printf("\n");
    	
   		 if(agac == uc){
		calistir(sifir);
		return;
		}
	}
	
		
	
		iter = agac->sol;
		printf("job%d is waiting for ",iter->data);
		while(iter->ust != NULL){	
		printf("job%d ",iter->ust->data);	
		iter = iter->ust;
		}
    	printf("\n");
	


 		iter = agac->sag;
		printf("job%d is waiting for ",iter->data);
		while(iter->ust != NULL){
			printf("job%d ",iter->ust->data);
			iter = iter->ust;
		}
   		 printf("\n");
	
	
    	iter = agac->orta;
		printf("job%d is waiting for ",iter->data);
		while(iter->ust != NULL){
			printf("job%d ",iter->ust->data);
			iter = iter->ust;
		}
    printf("\n");
	

	dolas2(agac->sol);

	
	
}

void dolas(struct node *agac){
	if(agac->sol == uc->sol){
		dolas2(agac->sol);
		return;
	}
	
	
	dolas2(agac);
	dolas(agac->sol);
	
}



int main(){
	
	sem_init(&mutex, 0, 1);
		
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
	
	sifir->sol = bir;
	sifir->orta = uc;
	sifir->sag = dort;
	sifir->ust = NULL;

	bir->sol = uc;
	bir->orta = bes;
	bir->sag = alti;
	bir->ust = sifir;
	
	uc->sol = yedi;
	uc->orta = NULL;
	uc->sag = NULL;
	uc->ust = sifir;

	dort->sol = NULL;
	dort->orta = NULL;
	dort->sag = NULL;
	dort->ust = sifir;

	bes->sol = alti;
	bes->orta = NULL;
	bes->sag = NULL;
	bes->ust = bir;

	alti->sol = NULL;
	alti->orta = NULL;
	alti->sag = NULL;
	alti->ust = bes;
	
	yedi->sol = NULL;
	yedi->orta = NULL;
	yedi->sag = NULL;
	yedi->ust = uc;

	iki->sol = dort;
	iki->orta = bes;
	iki->sag = alti;

	

	dolas(sifir);
	
	
	dolas(iki);
	
	
	
	
	
	
	//printf("arama : %d ",ara(sifir,4));

	sem_destroy(&mutex);
	//return 0 ;
}





