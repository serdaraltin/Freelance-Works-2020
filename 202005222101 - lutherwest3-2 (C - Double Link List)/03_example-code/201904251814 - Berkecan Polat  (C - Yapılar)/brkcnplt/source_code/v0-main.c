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
    int job;
    struct node *next;
};

 struct node *head = NULL;
 struct node *pointer = NULL;




void DugumEkle(int job){
     struct node *dugum = (struct node*) malloc(sizeof(struct node));
    dugum->job = job;
    dugum->next = head;
    head = dugum;
}

void DugumListele(){
		
    sem_wait(&mutex);
   
    printf("job%d tamamlandi.\n",pointer->job);
    
    sleep(2);
    sem_post(&mutex);
    
}


int main(){


	int i;
    for(i=10; i>=0; i--){
        DugumEkle(i);
    }

	
	sem_init(&mutex, 0, 1);
	pthread_t t1;
	
	printf("------------------\n");
	pointer = head;
	while(pointer != NULL){
		
    	printf("job%d bekliyor job%d\n",pointer->next->job,pointer->job);
		pthread_create(&t1,NULL,DugumListele, NULL);
	
		pthread_join(t1,NULL);
		
		pointer = pointer->next;
	}
	
	printf("------------------\n\n");
	sem_destroy(&mutex);
	
	return 0;
}


