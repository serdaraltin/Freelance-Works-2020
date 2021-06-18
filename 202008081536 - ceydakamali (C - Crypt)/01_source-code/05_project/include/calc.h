#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
void TreePrint(struct node*);
struct node { 
int value; 
struct node *right; 
struct node *left;}; 
void AddAfter(struct node** strt, int deger1,int deger2) { 
struct node* newnod = new node; 
newnod->value = deger1;
struct node *tmp = *strt; 
while (tmp->value != deger2) 
tmp = tmp->right; 
struct node *right = tmp->right; 
tmp->right = newnod; 
newnod->left = tmp; 
newnod->right = right; 
right->left = newnod; } 
int CalcGcd(int nm1, int nm2){
while(nm1 != nm2){
if(nm1 > nm2)
nm1 -= nm2;
else
nm2 -= nm1;}
return nm1;}
void AddEnd(struct node** strt, int deger) { 
if (*strt == NULL){ 
struct node* newnod = new node; 
newnod->value = deger; 
newnod->right = newnod->left = newnod; 
*strt = newnod; 
return;} 
node *lst = (*strt)->left; 
struct node* newnod = new node; 
newnod->value = deger; 
newnod->right = *strt; 
(*strt)->left = newnod; 
newnod->left = lst; 
lst->right = newnod;} 
void AddBegin(struct node** strt, int deger){ 
struct node *lst = (*strt)->left; 
struct node* newnod = new node; 
newnod->value = deger;  
newnod->right = *strt; 
newnod->left = lst; 
lst->right = (*strt)->left = newnod; 
*strt = newnod;} 
void RdFile(char dosyaAdi[20]){
	FILE* pFile;
	int bfLen = 5000;
	char buf[bfLen];
	pFile = fopen(dosyaAdi, "r");
	while(fgets(buf, bfLen, pFile)) {
		int *arr = (int*)malloc(sizeof(int)*512);
		char del[2] = " ";
		char *tok;
		tok = strtok(buf,del);
		int i = 0;
		while(tok != NULL){
		arr[i++] = atoi(tok);
		tok = strtok(NULL,del);
	}

	int mxEb = 0;	
	struct node* strt = NULL;
	int j;
	for(j=0; j<i; j++){
	if(j==0){
		AddEnd(&strt, arr[0]); 
		continue;
	}
	if(mxEb < CalcGcd(strt->value,arr[j])){
		mxEb = CalcGcd(strt->value,arr[j]);
		int mdResult;
	if(arr[j] > strt->value)
		mdResult = arr[j] % strt->value;
	else
	mdResult = strt->value % arr[j];
	if(mdResult == 0){
		AddAfter(&strt,arr[j],strt->value);
		continue;
	
	else{
		int i=0;
		struct node *tmp = strt;
		while(i++<mdResult)
		tmp = tmp->left;
		if(tmp == strt){
			AddBegin(&strt,arr[j]);
			continue;
		}
	}
	}
	else{
		struct node *tmp = strt;
		while(CalcGcd(tmp->value,arr[j]) < mxEb && tmp->right != strt){
		tmp = tmp->right;
	}

	int mdResult;
	if(arr[j] > tmp->value)
		mdResult = arr[j] % tmp->value;
	else
		mdResult = tmp->value % arr[j];

	int i=0,check=0;
	while(i++<mdResult){
		if(tmp == strt){
			check =1;
			AddBegin(&strt,arr[j]);
			break;
		}
		tmp = tmp->left;
	}

	if(check==0)
		AddAfter(&tmp,arr[j],tmp->value);
	}
	}
	TreePrint(strt);
	free(strt);
	}
	fclose(pFile);
}
void TreePrint(struct node* strt){
struct node *tmp = strt; 
printf("Sifre: "); 
while (tmp->right != strt){ 
printf("%c", tmp->value); 
tmp = tmp->right;} 
printf("%c\n", tmp->value);}