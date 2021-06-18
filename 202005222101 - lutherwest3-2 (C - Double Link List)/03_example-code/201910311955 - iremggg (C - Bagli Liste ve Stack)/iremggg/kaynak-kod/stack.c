#include <stdio.h>
#include <stdlib.h>

struct stack{
	int* value;
	struct stack *next;
};

typedef struct stack    Stack;


void push(int value, Stack *head);
int pop(Stack *head);

int main(){	
	Stack *top,*finish;
	
	int value;
	top = (Stack*)malloc(sizeof(Stack));
	finish = (Stack*)malloc(sizeof(Stack));
	top->next = finish;
	do{
		printf("Deger giriniz (cikis icin -1) > ");
		scanf("%d",&value);
		
		if(value != -1){
			push(value,top);
		}
	}while(value != -1);
	
	printf("Yigin\'nin ustten alta durumu > \n");
	
	do{
		printf("%d->",pop(top))	;
	}while(top->next != finish);
	
}

void push(int value, Stack *top){
	Stack *added;
	added = (Stack*)malloc(sizeof(Stack));
	
/*	if(top == NULL){
		Stack *root = (Stack*)malloc(sizeof(Stack));
		root->next = NULL;
		root->value = value;
		top = root;
		return;
	}
	if(top->value < value){
		added->value = value;
		added->next = top->next;
		top->next = added;
		return;
	}
	if(top->value > value){
		added->value = value;
		added->next = top;
		top->next = top->next->next;
		return;	
	}
	*/
	
	added->value = value;
	added->next = top->next;
	top->next = added;	
}

int pop(Stack *top){
	Stack *temp;
	int value = top->next->value;
	temp = top->next;
	top->next = top->next->next;
	free(temp);
	return value;
}


/*link list uzerinde ekleme,silme,arama,listeleme 
  islemleri main.c icerinde mevcuttur,
  ayýrabildigim zaman icerisinden elimden geleni yaptim.
*/

