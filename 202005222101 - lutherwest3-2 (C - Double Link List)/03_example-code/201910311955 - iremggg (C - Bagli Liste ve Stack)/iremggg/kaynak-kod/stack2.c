#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	int capacity;
	int* task;
	int* values;
};

typedef struct stack Stack;


int pop(Stack *);
void push(int, Stack *);
void printStack(Stack *);
Stack * createStack(int);
int isFull(Stack*);
int isEmpty(Stack*);

int main(){
	
	Stack *s1 = createStack(16);

	
	int i;
	for(i=20; i<=50; i+=10){
		push(i,s1);
	}
	printStack(s1);
	
	pop(s1);
	printStack(s1);

}


int pop(Stack *s){
	if(isEmpty(s)){
		printf("\nStack is empty.");
		return -1;
	}
	if(s->top <= s->capacity/4 && s->capacity > 2){
		
		int *values2 = (int*)malloc(sizeof(int)*s->capacity/2);
		
		int i;
		for(i=0; i < s->capacity; i++)
			values2[i] = s->values[i];
			
		//free(s->values);
		
		s->values = values2;
		s->capacity /= 2;
	}

	return s->values[--s->top];
}

void push(int a, Stack *s){
	if(isEmpty(s)){
		s->values = (int*)malloc(sizeof(int)*2);
	}
	if(isFull(s)){
		int *values2 = (int*)malloc(sizeof(int)*s->capacity*2);
		
		int i;
		for(i=0; i < s->capacity; i++)
			values2[i] = s->values[i];
			
		int *temp = s->values;
		s->values = values2;
		free(temp);
		s->capacity *= 2;
	}
	s->values[s->top++] = a;
}

void printStack(Stack *s) {
	printf("\nCapasity : %d\n",s->capacity);
	int i;
	for(i=0; i < s->top; i++){
		printf("%d -> ",s->values[i]);
	}
	printf("\n");
}

Stack * createStack(int capacity){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->values = NULL;
	s->capacity = capacity;
	s->top = 0;
	return s;
}

int isEmpty(Stack *s){
	if(s->top <= 0 || s->values == NULL)
		return 1;
	else
		return 0;
}

int isFull(Stack *s){
	if(s->top >= s->capacity-1)
		return 1;
	else 
		return 0;
}

//yetistirmeye calistigimdan gozumdan kacan ayrintilar olabilir


