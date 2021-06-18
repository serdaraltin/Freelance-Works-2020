#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
int main(void){
StackNodePtr mainStackPtr = NULL;
StackNodePtr helperStackPtr = NULL;
BizarreNumber_t data;
int inputvalue;
int num;
printf("Enter an integer number to push:\n");
num = scanf("%d",&inputvalue);
while(num != EOF){
if(isPrime(inputvalue)){
data.num = inputvalue * inputvalue;
strcpy(data.type,"PR");
data.nrOfOpr = 0;
push(&mainStackPtr,data);
data.num = -1;
strcpy(data.type,"");
data.nrOfOpr = 0;
push(&helperStackPtr,data);}
else if(isPerfectSquare(inputvalue)){
int perfectS = 0;
while(isPerfectSquare(inputvalue)){
inputvalue = sqrt(inputvalue);
perfectS++;}
data.num = inputvalue;
strcpy(data.type,"SQ");
data.nrOfOpr = perfectS;
push(&mainStackPtr,data);
data.num = -1;
strcpy(data.type,"");
data.nrOfOpr = 0;
push(&helperStackPtr,data);}
else{
int ab = isAbundantNumber(inputvalue);
if(ab > 0){
int m = (inputvalue / 2) + 1, s = 0;
for(int i = 1; i < m; i++){
if(inputvalue % i == 0){
s += i;}}
int si = s - inputvalue;
int is = inputvalue - si;
data.num = si;
strcpy(data.type,"AB");
data.nrOfOpr = 0;
push(&helperStackPtr,data);
data.num = is;
strcpy(data.type,"AB");
data.nrOfOpr = 0;
push(&mainStackPtr,data);}
else if(ab < 0){
data.num = inputvalue;
strcpy(data.type,"DF");
data.nrOfOpr = 0;
push(&helperStackPtr,data);
data.num = -1;
strcpy(data.type,"");
data.nrOfOpr = 0;
push(&mainStackPtr,data);}
else{
data.num = inputvalue;
strcpy(data.type,"PF");
data.nrOfOpr = 0;
push(&mainStackPtr,data);
data.num = -1;
strcpy(data.type,"");
data.nrOfOpr = 0;
push(&helperStackPtr,data);}}
printf("Enter an integer number to push:\n");
num = scanf("%d",&inputvalue);}
puts("The main stack is:");
printStack(mainStackPtr);
puts("The helper stack is:");
printStack(helperStackPtr);
StackNodePtr recStack = recoverCipher(mainStackPtr,helperStackPtr);
puts("Recovered stack is:");
printStackDetailed(recStack);
return 0;}
