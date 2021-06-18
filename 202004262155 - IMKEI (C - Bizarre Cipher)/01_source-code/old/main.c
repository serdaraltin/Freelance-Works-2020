#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type[3];
    int nrOfOpr;
    int num;
} BizarreNumber_t;

struct stackNode {
    BizarreNumber_t data;
    struct stackNode *nextPtr;
};


void push(struct stackNode *topPtr, BizarreNumber_t info);


int main(){
	struct stackNode* stackHead=malloc(sizeof(struct stackNode));

    BizarreNumber_t a={"sa",1,1};
    BizarreNumber_t b={"as",2,2};

    stackHead->data=a;
    stackHead->nextPtr=NULL;

    printf("%s\n", stackHead->data.type);
   push(&stackHead,b);

    printf("%s\n", stackHead->nextPtr->data.type);//HERE!!!
    return 0;
} 

 void push(struct stackNode **topPtr, BizarreNumber_t info){
        struct stackNode *newTop = malloc(sizeof(struct stackNode));
        newTop->data = info;
        newTop->nextPtr = *topPtr; /*new node next make it to head node */
        *topPtr=newTop; /*update the head node */
 }