#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

// stack related
void push(StackNodePtr *topPtr, BizarreNumber_t info)
{
	StackNodePtr newPtr = malloc(sizeof(StackNode));
    	
	if(newPtr != NULL)
	{
        	newPtr->data = info;
        	newPtr->nextPtr = *topPtr;
        	*topPtr = newPtr;
    	}
    	else 
	{
        	printf("No memory available.\n");
    	}	
}
BizarreNumber_t pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr = *topPtr;
	BizarreNumber_t popValue = (*topPtr)->data;
    	*topPtr = (*topPtr)->nextPtr;
    	free(tempPtr);
    	return popValue;
}
int isEmpty(StackNodePtr topPtr)
{
	return topPtr == NULL;
}
void printStack(StackNodePtr currentPtr)
{
	if(currentPtr == NULL)
	{
        	printf("Empty.\n");
    	}
    	else
	{
		printf("TOP --> ");
        	while(currentPtr != NULL)
		{
			if(currentPtr->data.num == -1)
				printf("NULL --> ");
            		else	
				printf("%d --> ", currentPtr->data.num);
            		currentPtr = currentPtr->nextPtr;
        	}
       	 	puts("BOTTOM\n");
    	}
}
void printStackDetailed(StackNodePtr currentPtr)
{
	printf("  **TOP**\n");
	while(currentPtr != NULL)
	{
		printf("%3d, %d, %s\n",currentPtr->data.num,currentPtr->data.nrOfOpr,currentPtr->data.type);
		currentPtr = currentPtr->nextPtr;
	}
	printf("**BOTTOM**\n\n");
}
StackNodePtr reverseStack(StackNodePtr currentPtr)
{
	StackNodePtr rev = NULL;
	while(currentPtr != NULL)
	{
		push(&rev, pop(&currentPtr));
	}
	return rev;
}

// maths related
int isAbundantNumber(int num)
{
	int max_divisor = (num / 2) + 1, sum = 0;
	for(int i = 1; i < max_divisor; i++)
	{
		if(num % i == 0)
		{
			sum += i;
		}
	}
	if(num > sum)
	{
		return -1;
	}
	else if(num < sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
int isPrime(int num)
{
	for(int i = 2; i < num; i++)
	{
		if(num % i == 0 && i != num)
		{
			return 0;
		}
	}
	return 1;
}
int isPerfectSquare(int num)
{
	for(int i = 1; i <= ((int)sqrt(num)); i++)
	{
		if (num == i * i)
        	{
            		return 1;
		}
	}
	return 0;
}

//recovery related
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack)
{
	StackNodePtr rec = NULL;
	BizarreNumber_t d;
	while(mainStack != NULL)
	{
		if(strcmp(mainStack->data.type,"PR") == 0)
		{
			strcpy(d.type,"PR");
			d.nrOfOpr = 0;
			d.num = sqrt(mainStack->data.num);
			push(&rec,d);
		}
		else if(strcmp(mainStack->data.type,"PF") == 0)
                {
                        strcpy(d.type,"PF");
                        d.nrOfOpr = 0;
                        d.num = mainStack->data.num;
                        push(&rec,d);
                }
		else if(strcmp(mainStack->data.type,"SQ") == 0)
                {
			int oInt = mainStack->data.num;
			
			for(int i = mainStack->data.nrOfOpr; i > 0; i--)
                        {
				oInt *= oInt;
			}

			strcpy(d.type,"SQ");
            d.nrOfOpr = mainStack->data.nrOfOpr;
			d.num = oInt;
                        push(&rec,d);
                }
		else if(strcmp(mainStack->data.type,"AB") == 0)
                {
                        strcpy(d.type,"AB");
                        d.nrOfOpr = 0;
                        d.num = mainStack->data.num + helperStack->data.num;
                        push(&rec,d);
                }
		else
                {
                        strcpy(d.type,"DF");
                        d.nrOfOpr = 0;
                        d.num = helperStack->data.num;
                        push(&rec,d);
                }
		mainStack = mainStack->nextPtr;
		helperStack = helperStack->nextPtr;
	}
	StackNodePtr revrec = reverseStack(rec);
	return revrec;
}

