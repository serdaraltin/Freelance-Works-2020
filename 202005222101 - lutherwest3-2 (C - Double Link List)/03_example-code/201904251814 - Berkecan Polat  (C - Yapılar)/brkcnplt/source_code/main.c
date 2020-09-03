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
	struct node *sag;
	struct node *orta;
	struct node *sol;
	struct node *ust;
};


struct node *yarat(int x){
	printf("kok yaratildi > %d\n",x);
	
	struct node *agac = (struct node*)malloc(sizeof(struct node));
	
	agac->data = x;
	agac->sag = NULL;
	agac->orta = NULL;
	agac->sol = NULL;

	return agac;	
	
};

void ekle(struct node **root, int x){
	
	if(!(*root)){
		(*root) = yarat(x);
	}
	
	/*
	if(x < (*root)->data){
		ekle(&(*root)->sol,x);
		printf("sola eklendi\n",(*root)->data);
	}
	
	else if(x > (*root)->data){
		ekle(&(*root)->sag,x);
		printf("saga eklendi\n",(*root)->data);
	}
	
	else if(x == (*root)->data){
		ekle(&(*root)->orta,x);
		printf("ortaya eklendi\n",(*root)->data);
	}*/
	
	
	
	
}



int main(){
	

	struct node *temp = NULL;
	
	ekle(&temp,0);
	ekle(&temp,1);
	ekle(&temp,2);
	ekle(&temp,3);

}





