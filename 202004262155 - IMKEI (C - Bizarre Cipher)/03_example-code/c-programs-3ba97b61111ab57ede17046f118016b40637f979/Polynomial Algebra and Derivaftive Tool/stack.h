#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct {
        char sign;
        int num;
        int exp;
}ElementInfo;

struct stackNode { 
	ElementInfo num; 
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, ElementInfo ele);
ElementInfo pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printSplitted(StackNodePtr currentPtr, int numb);
void printPolynomial(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);
void simplify(StackNodePtr currentPtr);
StackNodePtr multiply(StackNodePtr fst, StackNodePtr snd);
StackNodePtr sumThem(StackNodePtr fst, StackNodePtr snd);
StackNodePtr derivative(StackNodePtr cur);
StackNodePtr simplifyMult(StackNodePtr cur);

#endif // STACK_H_INCLUDED
