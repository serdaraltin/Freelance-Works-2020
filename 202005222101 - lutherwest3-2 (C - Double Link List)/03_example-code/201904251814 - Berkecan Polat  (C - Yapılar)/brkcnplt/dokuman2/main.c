#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#define NO_OF_THREADS 10




struct Singleton {
   char *Data;	
};

static struct A *instance = NULL; //static(sabit) struct(yapi) turunde bir pointer(isaretci) olusturma
struct Singleton *singletonObjectPointer;


int addresses[NO_OF_THREADS];
sem_t mutex; //

void *runner(void *params); /* the thread */
struct Singleton *getInstance();



int main()
{
	int i;
		sem_init(&mutex, 0, 1);
	pthread_t threadIds[NO_OF_THREADS];
	

	for (i=0; i < NO_OF_THREADS; i++){
		sem_wait(&mutex);
		pthread_create(&threadIds[i], NULL, &runner, (void *)(i));
		sleep(1);
		sem_post(&mutex);
	} //thread olusturma
	sem_destroy(&mutex);
	/* Wait until all threads are done */
	for (i=0; i < NO_OF_THREADS; i++){
		pthread_join(threadIds[i], NULL);
	} //thread calistirma
	
	/* Control addresses. All of them should be same */
	int prevAddr=addresses[0];
	for (i=1; i < NO_OF_THREADS; i++){
		if(addresses[i]!=prevAddr){//nesne kontrol
			printf("Nesne bir kereden fazla yaratildi !\n");
			return -1;
		}
		prevAddr=addresses[i];
	}
	printf("\n----------------\n");
	for (i=0; i < NO_OF_THREADS; i++){
		printf("Singleton Adresi : %x\n",addresses[i]);//adreslenme
	}
	printf("\n----------------\n");
	printf("Basarili\n");
	return 1;
}

/**
 * The thread will begin control in this function
 */
void *runner(void *params) 
{
	int i = (int)params;
	printf("Thread %d\n",i);
	struct Singleton *s = getInstance();
	addresses[i]=s;
	pthread_exit(0);
}

//Fill this method
struct Singleton *getInstance(){
	 

    //olusturulan instance eger hicbir deger icerimiyorsa, bos(null) ise kosulu
    if(instance == NULL)
    {

		singletonObjectPointer = (struct Singleton *)malloc(sizeof(struct Singleton));
		printf("-> Obje adresi: %x\n",singletonObjectPointer);
		singletonObjectPointer->Data="This is object data"; 
		
	}

	return instance;//fonksiyon cagrildiginda geriye instance sabitini gonderiyor
}
