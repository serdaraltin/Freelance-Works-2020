#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
int main(void){
	StackNodePtr mainStackPtr = NULL;
	StackNodePtr helperStackPtr = NULL;
	BizarreNumber_t data;
	int in;
	int num;
	printf("Enter an integer number to push:\n");
	num = scanf("%d",&in);
	while(num != EOF){
		if(isPrime(in)){
			data.num = in * in;
			strcpy(data.type,"PR");
			data.nrOfOpr = 0;
			push(&mainStackPtr,data);
			data.num = -1;
                       	strcpy(data.type,"");
                        data.nrOfOpr = 0;
                        push(&helperStackPtr,data);
		}
		else if(isPerfectSquare(in)){
			int prf = 0;
			while(isPerfectSquare(in)){
				in = sqrt(in);
				prf++;
			}
			data.num = in;
                        strcpy(data.type,"SQ");
                        data.nrOfOpr = prf;
                        push(&mainStackPtr,data);

			data.num = -1;
                        strcpy(data.type,"");
                        data.nrOfOpr = 0;
                        push(&helperStackPtr,data);
		}
		else{
			int numb = isAbundantNumber(in);
			if(numb > 0){
				int max_divisor = (in / 2) + 1, sum = 0;
        			for(int i = 1; i < max_divisor; i++){
                			if(in % i == 0){
                        			sum += i;
         	       			}
        			}
				int hInt = sum - in;
				int mInt = in - hInt;
				
				data.num = hInt;
                                strcpy(data.type,"AB");
                                data.nrOfOpr = 0;
                                push(&helperStackPtr,data);

                                data.num = mInt;
                                strcpy(data.type,"AB");
                                data.nrOfOpr = 0;
                                push(&mainStackPtr,data);
			}
			else if(numb < 0){
				data.num = in;
                                strcpy(data.type,"DF");
                                data.nrOfOpr = 0;
                                push(&helperStackPtr,data);
				
				data.num = -1;
                        	strcpy(data.type,"");
                        	data.nrOfOpr = 0;
                        	push(&mainStackPtr,data);
			}
			else {
				data.num = in;
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
        	num = scanf("%d",&in);
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
