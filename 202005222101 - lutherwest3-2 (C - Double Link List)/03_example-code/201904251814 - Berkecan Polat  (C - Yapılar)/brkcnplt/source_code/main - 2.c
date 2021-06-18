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





void dolas(struct node *agac){
	if(agac->sol == uc->sol){
		printf("%d > %d\n",agac->data,agac->sol->data);
		return;
	}
		
	printf("%d > %d\n",agac->data,agac->sol->data);
	printf("%d > %d\n",agac->data,agac->orta->data);
	printf("%d > %d\n",agac->data,agac->sag->data);

	dolas2(agac);
	dolas(agac->sol);
			


}

void dolas2(struct node *agac){
	if(agac == yedi)
		return;
		
	
		
	printf("job%d is waiting for ",agac->sol->data);
	iter = agac->sol;

	
	if(iter->ust == sifir)
		printf("job%d ",iter->ust->data);
		
	while(iter->ust != sifir){
		if(iter->ust->sol != NULL && iter->ust->sol != iter) 
			printf("job%d ",iter->ust->sol->data);
		if(iter->ust->orta == NULL || iter->ust->sag == NULL){
			if(iter->ust != NULL)
				printf("job%d ",iter->ust->data);
		}
		
		iter = iter->ust;
		
	}

    printf("\n");
    
	dolas2(agac->sol);
	

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
	sifir->ust = NULL;
	 /* bir nodesi icin alt nodeler*/
	bir->sol = uc;
	bir->orta = bes;
	bir->sag = alti;
	bir->ust = sifir;
	 /* uc nodesi icin alt nodeler*/
	uc->sol = yedi;
	uc->orta = NULL;
	uc->sag = NULL;
	uc->ust = sifir;
	 /* dort nodesi */
	dort->sol = NULL;
	dort->orta = NULL;
	dort->sag = NULL;
	dort->ust = sifir;
	 /* bes nodesi*/
	bes->sol = NULL;
	bes->orta = NULL;
	bes->sag = NULL;
	bes->ust = bir;
	 /* alti nodesi*/
	alti->sol = NULL;
	alti->orta = NULL;
	alti->sag = NULL;
	alti->ust = bir;
	 /* yedi nodesi*/
	yedi->sol = NULL;
	yedi->orta = NULL;
	yedi->sag = NULL;
	yedi->ust = uc;
	/* iki nodesi icin alt nodeler*/
	iki->sol = dort;
	iki->orta = bes;
	iki->sag = alti;
	

	dolas(sifir);
	
	
	
	

	
	
	//return 0 ;
}





