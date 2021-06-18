#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char type[3];
	int nrOfOpr;
	int num;
}BizarreNumber_t;

typedef struct stackNode{
	BizarreNumber_t data;
	struct stackNode *nextPtr;
}StackNodePtr;

StackNodePtr *createStack(int capacity); 

void push(StackNodePtr *topPtr, BizarreNumber_t info);
BizarreNumber_t pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void printStackDetailed(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);

int isAbundantNumber(int num);
int isPrime(int num);
int isPerfectSquare(int num);

StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);

int main(){
	
} 


StackNodePtr *createStack(int capacity){
	StackNodePtr *stack = (StackNodePtr*)malloc(sizeof(StackNodePtr));
	stack->num = capacity;
}