#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int *stk;
	int top;
	int max_size;
};
typedef struct Stack stack;


stack *newStack(int size);
void deleteStack(stack* s);

int pop (stack *s);
int push(stack * s, int value);
void display( stack *s);
void stringReverse(char *str, stack *s);


int peek(stack* s);
int isEmpty(stack* s);
int isFull(stack* s);

void stringReverse(char *str, stack *s){
	int n = strlen(str);

	int i;
	for(i=0; i<n; i++)
		push(s, str[i]);
	for(i=0; i<n; i++)
		str[i] = pop(s);
	return;
}

stack *newStack(int size){
	stack *newS = (stack*)malloc(sizeof(stack));
	newS->stk = (int*)malloc(sizeof(int)*size);
	newS->top = -1;
	newS->max_size = size;
	return newS;
}

void deleteStack(stack* s){
	free(s);
	return;
}

int isEmpty(stack* s){
	return s->top == -1;
}

int isFull(stack* s){
	return s->top == s->max_size -1;
}

int push(stack * s, int value){
	if(isFull(s))
		return value;
	s->stk[++s->top] = value;
	printf("%d pushed to stack\n",s->stk[s->top]);
	return value;
}

int pop (stack *s){
	if(isEmpty(s))
		return 0;
	return s->stk[s->top--];
}

int peek(stack* s){
	if(isEmpty(s))
		return 0;
	return s->stk[s->top];
}

void display(stack *s){
	int i;
	for(i=0; i<=s->top; i++)
		printf("array[%d] -> %d\n",i,s->stk[i]);
	return;
}



