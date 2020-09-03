#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
/* eger linux uzerinde calistiracaksaniz lutfen <semaphore.h> kutuphanesinin var oldugundan emin olun
kutuphane yok ise edinin ve ardï¿½ndan [#include <semaphore.h>] > [#include "[dosya_yolu]"] seklinde degistirin.
kutuphaneyi edinebileceginiz baglantilar;
https://github.com/torvalds/linux/blob/master/include/linux/semaphore.h
https://github.com/torvalds/linux/tree/master/include/linux
*/
sem_t mutex; //
int a = 0,b = 0, c = 0;
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
/*node calistirma */
printf("job%d done\n",agac->data);
if(agac->data == yedi->data){
calistir(iki);
}
if(agac->orta == bes && b == 0){
printf("job%d done\n",bes->data);
b = 1;
}
if(agac->sag == alti && c == 0){
printf("job%d done\n",alti->data);
c = 1;
}
calistir(agac->sol);
}
void dolas2(struct node *agac){
/* alt nodeleri dolasma */
if(agac->data == uc->data && a == 1)
{
iter = agac->sol;
printf("job%d is waiting for job%d",iter->data,iter->ust->data);
printf("\n");
if(agac == uc){
iter = bir->orta;
printf("job%d is waiting for ",iter->data);
if(iki->sol == iter || iki->orta == iter || iki->sag == iter){
printf("job%d ",iki->data);
}
while(iter->ust != NULL)
{
if(iter->ust->data != sifir->data)
printf("job%d ",iter->ust->data);
iter = iter->ust;
}
printf("\n");
calistir(sifir);
calistir(iki);
return;
}
}
iter = agac->sol;
printf("job%d is waiting for ",iter->data);
while(iter->ust != NULL)
{
printf("job%d ",iter->ust->data);
iter = iter->ust;
}
printf("\n");
iter = agac->sag;
printf("job%d is waiting for ",iter->data);
if(iki->sol == iter || iki->orta == iter || iki->sag == iter){
printf("job%d ",iki->data);
}
while(iter->ust != NULL){
if(iter->ust->data != sifir->data)
printf("job%d ",iter->ust->data);
iter = iter->ust;
}
printf("\n");
iter = agac->orta;
if(iter->data == uc->data && a ==0){
printf("job%d is waiting for ",iter->data);
if(iki->sol == iter || iki->orta == iter || iki->sag == iter){
printf("job%d ",iki->data);
}
if(iter->data == uc->data)
{
a = 1;
printf("job%d ",bir->data);
}
while(iter->ust != NULL){
printf("job%d ",iter->ust->data);
iter = iter->ust;
}
printf("\n");
}
dolas2(agac->sol);
}
void dolas(struct node *agac){
/* ust nodeleri doalsma*/
if(agac->sol == uc->sol){
dolas2(agac->sol);
return;
}
dolas2(agac);
dolas(agac->sol);
}
int main(){
sem_init(&mutex, 0, 1);
/* bellekte yer acma */
sifir = (struct node*) malloc(sizeof(struct node));
bir = (struct node*) malloc(sizeof(struct node));
uc = (struct node*) malloc(sizeof(struct node));
dort = (struct node*) malloc(sizeof(struct node));
bes = (struct node*) malloc(sizeof(struct node));
alti = (struct node*) malloc(sizeof(struct node));
yedi = (struct node*) malloc(sizeof(struct node));
iki = (struct node*) malloc(sizeof(struct node));
/* nodelerin icini doldurma */ 
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




