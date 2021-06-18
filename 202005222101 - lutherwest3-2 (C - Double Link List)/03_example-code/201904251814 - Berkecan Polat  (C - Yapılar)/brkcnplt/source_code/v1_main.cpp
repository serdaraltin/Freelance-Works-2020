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
sem_t mutex;


struct node{
	int data;
	struct node *sol;

	struct node *sag;
};

struct node * ekle(struct node * agac, int x){
	if(agac =  NULL){
		struct node * root = (struct node*) malloc(sizeof(struct node));
		root->sol = NULL;
		root->sag = NULL;
		root->data = x;
		return root;
	}
	
	if(agac->data < x){
		agac->sag = ekle(agac->sag,x);
		return agac;
	}
	agac->sol = ekle(agac->sol,x);
	printf("%d > ",agac);
	return agac;
}

void dolas(struct node *agac){
	if(agac == NULL){
		return;
	}
	
	dolas(agac->sag);
	printf("%d ",agac->data);
	dolas(agac->sol);
	
}




int main(){

	
	struct node *agac =  (struct node*) malloc(sizeof(struct node));
	
	agac = ekle(agac,0);
	agac = ekle(agac,1);
	agac = ekle(agac,2);
	agac = ekle(agac,3);
	agac = ekle(agac,4);
	agac = ekle(agac,5);
	agac = ekle(agac,6);
	agac = ekle(agac,7);

	
	dolas(agac);
	
	
	
	
	
	//return 0 ;
}





