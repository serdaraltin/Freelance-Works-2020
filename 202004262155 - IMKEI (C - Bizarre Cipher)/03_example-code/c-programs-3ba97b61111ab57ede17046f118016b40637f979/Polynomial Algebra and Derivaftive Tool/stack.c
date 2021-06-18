#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

// stack related
void push(StackNodePtr *topPtr, ElementInfo ele)
{
	StackNodePtr newPtr = malloc(sizeof(StackNode));
    	
	if(newPtr != NULL)
	{
        	newPtr->num = ele;
        	newPtr->nextPtr = *topPtr;
        	*topPtr = newPtr;
    	}
    	else 
	{
        	printf("No memory available.\n");
    	}	
}
ElementInfo pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr = *topPtr;
	ElementInfo popValue = (*topPtr)->num;
    	*topPtr = (*topPtr)->nextPtr;
    	free(tempPtr);
    	return popValue;
}
int isEmpty(StackNodePtr topPtr)
{
	return topPtr == NULL;
}
void printSplitted(StackNodePtr currentPtr, int numb)
{
	printf("Splitted polynomial %d:\n",numb);
	int count = 1;
	while(currentPtr != NULL)
	{
		printf("Monomial %d is: %c %dx%d\n",count,currentPtr->num.sign,currentPtr->num.num,currentPtr->num.exp);
		currentPtr = currentPtr->nextPtr;
		count++;
	}
	printf("\n");
}
void printPolynomial(StackNodePtr currentPtr)
{
	printf("%dx^%d ",currentPtr->num.num,currentPtr->num.exp);
	currentPtr = currentPtr->nextPtr;
	while(currentPtr != NULL)
	{
		if(currentPtr->num.sign == '-')
			printf("+ %c%dx^%d ", currentPtr->num.sign,currentPtr->num.num,currentPtr->num.exp);
		else
			printf("+ %dx^%d ",currentPtr->num.num,currentPtr->num.exp);
		currentPtr = currentPtr->nextPtr;
	}
	printf("\n");
}
void simplify(StackNodePtr currentPtr)
{
	int count = 0;
	while(currentPtr != NULL)
	{
		if(count == 0)
		{
			if(currentPtr->num.exp == 0)
                	{
                        	if(currentPtr->num.sign == '+')
                                	printf("%d ",currentPtr->num.num);
                        	else
                                	printf("- %d ",currentPtr->num.num);
                	}
                	else if(currentPtr->num.exp == 1)
                	{
                        	if(currentPtr->num.sign == '+')
                                	printf("%dx ",currentPtr->num.num);
                        	else
                                	printf("- %dx ",currentPtr->num.num);
                	}
                else
                {
                        if(currentPtr->num.sign == '+')
                                printf("%dx^%d ",currentPtr->num.num,currentPtr->num.exp);
                        else
                                printf("- %dx^%d ",currentPtr->num.num,currentPtr->num.exp);
                }
			count++;
			currentPtr = currentPtr->nextPtr;
		}
		if(currentPtr->num.exp == 0)
		{
			if(currentPtr->num.sign == '+')
				printf("+ %d ",currentPtr->num.num);
			else
				printf("- %d ",currentPtr->num.num);
		}
		else if(currentPtr->num.exp == 1)
		{
			if(currentPtr->num.sign == '+')
                                printf("+ %dx ",currentPtr->num.num);
                        else
                                printf("- %dx ",currentPtr->num.num);
		}
		else
		{
			if(currentPtr->num.sign == '+')
                                printf("+ %dx^%d ",currentPtr->num.num,currentPtr->num.exp);
                        else
                                printf("- %dx^%d ",currentPtr->num.num,currentPtr->num.exp);
		}
		currentPtr = currentPtr->nextPtr;
	}
	printf("\n");
}
StackNodePtr reverseStack(StackNodePtr currentPtr)
{
	StackNodePtr temp = NULL;
	while(currentPtr != NULL)
	{
		push(&temp,currentPtr->num);
		currentPtr = currentPtr->nextPtr;
	}
	return temp;
}
StackNodePtr multiply(StackNodePtr fst, StackNodePtr snd)
{
	ElementInfo ele;
	StackNodePtr temp = NULL; 
	while(fst != NULL)
	{
		StackNodePtr tmp = snd;
		while(tmp != NULL)
		{
			if(fst->num.sign == tmp->num.sign)
			{
				ele.sign = '+';
				ele.num = (fst->num.num) * (tmp->num.num);
				ele.exp = (fst->num.exp) + (tmp->num.exp);
				push(&temp,ele);
			}
			else
			{
				ele.sign = '-';
                                ele.num = (fst->num.num) * (tmp->num.num);
                                ele.exp = (fst->num.exp) + (tmp->num.exp);
                                push(&temp,ele);
			}
			tmp = tmp->nextPtr;
		}
		fst = fst->nextPtr;
	}
	return temp;
}
StackNodePtr derivative(StackNodePtr cur)
{
	StackNodePtr der = NULL;
	ElementInfo ele;
	while(cur != NULL)
	{
		if(cur->num.exp == 0)
		{
			
		}
		else if(cur->num.exp == 1)
		{
			ele.sign = cur->num.sign;
			ele.num = cur->num.num;
			ele.exp = 0;
			push(&der,ele);
		}
		else
		{
			ele.sign = cur->num.sign;
                        ele.num = (cur->num.num) * (cur->num.exp);
                        ele.exp = (cur->num.exp) - 1;
			push(&der,ele);
		}
		cur = cur->nextPtr;
	}
	return der;
}
StackNodePtr sumThem(StackNodePtr fst, StackNodePtr snd)
{
	StackNodePtr rec = NULL;
	ElementInfo inf;
	while(fst != NULL && snd != NULL)
	{
		if(fst->num.exp == snd->num.exp)
		{
			if(fst->num.sign == snd->num.sign)
			{
				inf.sign = fst->num.sign;
				inf.num = fst->num.num + snd->num.num;
				inf.exp = fst->num.exp;
				push(&rec,inf);
			}
			else
			{
				if(fst->num.sign == '-')
				{
                                	inf.num = - fst->num.num + snd->num.num;
                                	if(inf.num > 0)	
						inf.sign = snd->num.sign;
					else
						inf.sign = fst->num.sign;
					inf.exp = fst->num.exp;
                                	push(&rec,inf);
				}
				else
                                {
                                        inf.num = fst->num.num - snd->num.num;
                                        if(inf.num > 0)     
                                                inf.sign = fst->num.sign;
                                        else
                                                inf.sign = snd->num.sign;
					inf.exp = fst->num.exp;
                                        push(&rec,inf);
                                }
			}
			fst = fst->nextPtr;
			snd = snd->nextPtr;
		}
		else if(fst->num.exp > snd->num.exp)
		{
			inf.sign = snd->num.sign;
                        inf.num = snd->num.num;
               	        inf.exp = snd->num.exp;
                        push(&rec,inf);
			snd = snd->nextPtr;
		}
		else
		{
			inf.sign = fst->num.sign;
                        inf.num = fst->num.num;
                        inf.exp = fst->num.exp;
                        push(&rec,inf);
			fst = fst->nextPtr;
		}
	}
	return rec;
}
StackNodePtr simplifyMult(StackNodePtr cur)
{
	StackNodePtr rev = reverseStack(cur);
	int arr[99]={0};
	ElementInfo ele;
	while(rev != NULL)
	{
		if(arr[rev->num.exp] == 0)
			if(rev->num.sign == '-')
                                arr[rev->num.exp] = 0 - rev->num.num;
                        else
                                arr[rev->num.exp] = rev->num.num;
		else
		{
			if(rev->num.sign == '-')
				arr[rev->num.exp] = arr[rev->num.exp] - rev->num.num;
			else
				arr[rev->num.exp] = arr[rev->num.exp] + rev->num.num;
		}
		rev = rev->nextPtr;
	}
	StackNodePtr ret = NULL;
	for(int i = 0; i < 99; i++)
	{
		if(arr[i] == 0)	continue;
		else
		{
			if(arr[i] < 0)
			{
				ele.num = -arr[i];
				ele.sign = '-';
				ele.exp = i;
				push(&ret,ele);
			}
			else
			{
				ele.num = arr[i];    
                                ele.sign = '+';
                                ele.exp = i;
				push(&ret,ele);
			}
		}
	}
	return ret;
}
