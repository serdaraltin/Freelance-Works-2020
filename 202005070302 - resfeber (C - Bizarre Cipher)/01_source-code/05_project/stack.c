#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"
BizarreNumber_t pop(StackNodePtr *topPtr){
StackNodePtr tempTopPtr = *topPtr;
BizarreNumber_t popValue = (*topPtr)->data;
*topPtr = (*topPtr)->nextPtr;
free(tempTopPtr);
return popValue;}
void printStack(StackNodePtr currentPtr){
if(currentPtr == NULL){printf("null.\n");}
else{printf("TOP --> ");
while(currentPtr != NULL){
if(currentPtr->data.num == -1)
printf("NULL --> ");
else
printf("%d --> ", currentPtr->data.num);
currentPtr = currentPtr->nextPtr;}
puts("BOTTOM\n");}}
void push(StackNodePtr *topPtr, BizarreNumber_t info){
StackNodePtr stacknew = malloc(sizeof(StackNode));
if(stacknew != NULL){
stacknew->data = info;
stacknew->nextPtr = *topPtr;
*topPtr = stacknew;}
else
printf("null.\n");}
StackNodePtr reverseStack(StackNodePtr currentPtr){StackNodePtr stackrev = NULL;
while(currentPtr != NULL){push(&stackrev, pop(&currentPtr));}
return stackrev;}
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack){StackNodePtr stackreco = NULL;
BizarreNumber_t d;
while(mainStack != NULL){
if(strcmp(mainStack->data.type,"PR") == 0){strcpy(d.type,"PR");
d.nrOfOpr = 0;
d.num = sqrt(mainStack->data.num);
push(&stackreco,d);}
else if(strcmp(mainStack->data.type,"PF") == 0){
strcpy(d.type,"PF");
d.nrOfOpr = 0;
d.num = mainStack->data.num;
push(&stackreco,d);}
else if(strcmp(mainStack->data.type,"SQ") == 0){
int oInt = mainStack->data.num;
for(int i = mainStack->data.nrOfOpr; i > 0; i--){
oInt *= oInt;}
strcpy(d.type,"SQ");
d.nrOfOpr = mainStack->data.nrOfOpr;
d.num = oInt;
push(&stackreco,d);}
else if(strcmp(mainStack->data.type,"AB") == 0){
strcpy(d.type,"AB");
d.nrOfOpr = 0;
d.num = mainStack->data.num + helperStack->data.num;
push(&stackreco,d);}
else{
strcpy(d.type,"DF");
d.nrOfOpr = 0;
d.num = helperStack->data.num;
push(&stackreco,d);}
mainStack = mainStack->nextPtr;
helperStack = helperStack->nextPtr;}
StackNodePtr stackrev= reverseStack(stackreco);
return stackrev;}
void printStackDetailed(StackNodePtr currentPtr){
printf("  **TOP**\n");
while(currentPtr != NULL){
printf("%3d, %d, %s\n",currentPtr->data.num,currentPtr->data.nrOfOpr,currentPtr->data.type);
currentPtr = currentPtr->nextPtr;}
printf("**BOTTOM**\n\n");}

int isEmpty(StackNodePtr topPtr){
return topPtr == NULL;}
int isAbundantNumber(int num){
int div = (num / 2) + 1, s = 0;
for(int i = 1; i < div; i++){
if(num % i == 0)
s += i;}
if(num > s)
return -1;
else if(num < s)
return 1;
else
return 0;
return 0;
}
int isPerfectSquare(int num){
for(int i = 1; i <= ((int)sqrt(num)); i++){
if (num == i * i)
return 1;}
return 0;}
int isPrime(int num){
for(int i = 2; i < num; i++){
if(num % i == 0 && i != num)
return 0;}
return 1;}

