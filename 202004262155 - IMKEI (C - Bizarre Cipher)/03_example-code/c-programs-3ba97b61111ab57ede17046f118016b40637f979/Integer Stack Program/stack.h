#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct { 
	char type[3]; 
	int nrOfOpr; 
	int num;
}BizarreNumber_t;

struct stackNode { 
	BizarreNumber_t data; 
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

// stack related
void push(StackNodePtr *topPtr, BizarreNumber_t info);
BizarreNumber_t pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void printStackDetailed(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);

// maths related
int isAbundantNumber(int num); //returns abundance (if 0 perfect, if > 0 abundant, if < 0 deficient)
int isPrime(int num);
int isPerfectSquare(int num);

//recovery related
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);

#endif // STACK_H_INCLUDED
