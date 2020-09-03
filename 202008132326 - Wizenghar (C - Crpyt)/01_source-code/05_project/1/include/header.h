#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
void print(struct nd*);
struct nd { 
int val; 
struct nd *rg; 
struct nd *lf;}; 
void aftadd(struct nd** st, int val1,int val2) { 
struct nd* ndnew = new nd; 
ndnew->val = val1;
struct nd *temp = *st; 
while (temp->val != val2) 
temp = temp->rg; 
struct nd *rg = temp->rg; 
temp->rg = ndnew; 
ndnew->lf = temp; 
ndnew->rg = rg; 
rg->lf = ndnew; } 
int gcd(int n1, int nm2){
while(n1 != nm2){
if(n1 > nm2)
n1 -= nm2;
else
nm2 -= n1;}
return n1;}
void endadd(struct nd** st, int val) { 
if (*st == NULL){ 
struct nd* ndnew = new nd; 
ndnew->val = val; 
ndnew->rg = ndnew->lf = ndnew; 
*st = ndnew; 
return;} 
nd *lst = (*st)->lf; 
struct nd* ndnew = new nd; 
ndnew->val = val; 
ndnew->rg = *st; 
(*st)->lf = ndnew; 
ndnew->lf = lst; 
lst->rg = ndnew;} 
void bgadd(struct nd** st, int val){ 
struct nd *lst = (*st)->lf; 
struct nd* ndnew = new nd; 
ndnew->val = val;  
ndnew->rg = *st; 
ndnew->lf = lst; 
lst->rg = (*st)->lf = ndnew; 
*st = ndnew;} 
void rfile(char fname[20]){
FILE* fpo;
int bfrl = 5000;
char bfr[bfrl];
fpo = fopen(fname, "r");
while(fgets(bfr, bfrl, fpo)) {
int *arry = (int*)malloc(sizeof(int)*512);
char del[2] = " ";
char *token;
token = strtok(bfr,del);
int i = 0;
while(token != NULL){
arry[i++] = atoi(token);
token = strtok(NULL,del);}
int mxgcd = 0;	
struct nd* st = NULL;
int j;
for(j=0; j<i; j++){
if(j==0){
endadd(&st, arry[0]); 
continue;}
if(mxgcd < gcd(st->val,arry[j])){
mxgcd = gcd(st->val,arry[j]);
int modres;
if(arry[j] > st->val)
modres = arry[j] % st->val;
else
modres = st->val % arry[j];
if(modres == 0){
aftadd(&st,arry[j],st->val);
continue;}
else{
int i=0;
struct nd *temp = st;
while(i++<modres)
temp = temp->lf;
if(temp == st){
bgadd(&st,arry[j]);
continue;}}}
else{
struct nd *temp = st;
while(gcd(temp->val,arry[j]) < mxgcd && temp->rg != st){
temp = temp->rg;}
int modres;
if(arry[j] > temp->val)
modres = arry[j] % temp->val;
else
modres = temp->val % arry[j];
int i=0,chk=0;
while(i++<modres){
if(temp == st){
chk =1;
bgadd(&st,arry[j]);
break;}
temp = temp->lf;}
if(chk==0)
aftadd(&temp,arry[j],temp->val);}}
print(st);
free(st);}
fclose(fpo);}
void print(struct nd* st){
struct nd *temp = st; 
printf("Sifre: "); 
while (temp->rg != st){ 
printf("%c", temp->val); 
temp = temp->rg;} 
printf("%c\n", temp->val);}