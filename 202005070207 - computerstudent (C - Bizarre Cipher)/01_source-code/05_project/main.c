#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
int main(void){
	StackNodePtr mainStackPtr = NULL;
	StackNodePtr helperStackPtr = NULL;
	BizarreNumber_t data;
	int vi;
	int num;
	printf("Enter an integer number to push:\n");
	num = scanf("%d",&vi);
	while(num != EOF){
		if(isPrime(vi)){
			data.num = vi * vi;
			strcpy(data.type,"PR");
			data.nrOfOpr = 0;
			push(&mainStackPtr,data);
			data.num = -1;
                       	strcpy(data.type,"");
                        data.nrOfOpr = 0;
                        push(&helperStackPtr,data);
		}
		else if(isPerfectSquare(vi)){
			int p = 0;
			while(isPerfectSquare(vi)){
				vi = sqrt(vi);
				p++;
			}
			data.num = vi;
                        strcpy(data.type,"SQ");
                        data.nrOfOpr = p;
                        push(&mainStackPtr,data);

			data.num = -1;
                        strcpy(data.type,"");
                        data.nrOfOpr = 0;
                        push(&helperStackPtr,data);
		}
		else{
			int numb = isAbundantNumber(vi);
			if(numb > 0){
				int max_divisor = (vi / 2) + 1, su = 0;
        			for(int i = 1; i < max_divisor; i++){
                			if(vi % i == 0){
                        			su += i;
         	       			}
        			}
				int h = su - vi;
				int mi = vi - h;
				
				data.num = h;
                                strcpy(data.type,"AB");
                                data.nrOfOpr = 0;
                                push(&helperStackPtr,data);

                                data.num = mi;
                                strcpy(data.type,"AB");
                                data.nrOfOpr = 0;
                                push(&mainStackPtr,data);
			}
			else if(numb < 0){
				data.num = vi;
                                strcpy(data.type,"DF");
                                data.nrOfOpr = 0;
                                push(&helperStackPtr,data);
				
				data.num = -1;
                        	strcpy(data.type,"");
                        	data.nrOfOpr = 0;
                        	push(&mainStackPtr,data);
			}
			else {
				data.num = vi;
                        	strcpy(data.type,"PF");
                        	data.nrOfOpr = 0;
                        	push(&mainStackPtr,data);
				
				data.num = -1;
                        	strcpy(data.type,"");
                        	data.nrOfOpr = 0;
                        	push(&helperStackPtr,data);
			}
		}
		printf("Enter an integer number to push:\n");
        	num = scanf("%d",&vi);
	}
	puts("The main stack is:");
	printStack(mainStackPtr);
	puts("The helper stack is:");
	printStack(helperStackPtr);
	StackNodePtr recoverPtr = recoverCipher(mainStackPtr,helperStackPtr);
	puts("Recovered stack is:");
	printStackDetailed(recoverPtr);
	return 0;
}
