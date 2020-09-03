#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

int main(void)
{
	StackNodePtr mainStackPtr = NULL;
	StackNodePtr helperStackPtr = NULL;
	BizarreNumber_t data;
	int input;
	int num;
	
	printf("Enter an integer number to push:\n");
	num = scanf("%d",&input);
	
	while(num != EOF)
	{
		if(isPrime(input)) // PR
		{
			data.num = input * input;
			strcpy(data.type,"PR");
			data.nrOfOpr = 0;
			push(&mainStackPtr,data);
			
			data.num = -1;
                       	strcpy(data.type,"");
                        data.nrOfOpr = 0;
                        push(&helperStackPtr,data);
		}
		else if(isPerfectSquare(input)) // SQ
		{
			int prf = 0;
			// Perfect Square Implementation comes here
			while(isPerfectSquare(input))
			{
				input = sqrt(input);
				prf++;
			}
			data.num = input;
                        strcpy(data.type,"SQ");
                        data.nrOfOpr = prf;
                        push(&mainStackPtr,data);

			data.num = -1;
                        strcpy(data.type,"");
                        data.nrOfOpr = 0;
                        push(&helperStackPtr,data);
		}
		else
		{
			int numb = isAbundantNumber(input);
			if(numb > 0) // AB
			{
				int max_divisor = (input / 2) + 1, sum = 0;
        			for(int i = 1; i < max_divisor; i++)
        			{
                			if(input % i == 0)
                			{
                        			sum += i;
         	       			}
        			}
				int hInt = sum - input;
				int mInt = input - hInt;
				
				data.num = hInt;
                                strcpy(data.type,"AB");
                                data.nrOfOpr = 0;
                                push(&helperStackPtr,data);

                                data.num = mInt;
                                strcpy(data.type,"AB");
                                data.nrOfOpr = 0;
                                push(&mainStackPtr,data);
			}
			else if(numb < 0) // DF
			{
				data.num = input;
                                strcpy(data.type,"DF");
                                data.nrOfOpr = 0;
                                push(&helperStackPtr,data);
				
				data.num = -1;
                        	strcpy(data.type,"");
                        	data.nrOfOpr = 0;
                        	push(&mainStackPtr,data);
			}
			else //PF
			{
				data.num = input;
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
        	num = scanf("%d",&input);
	}
	// system("CLC"); // For Windows
	system("clear"); //For Unix-based
	puts("The main stack is:");
	printStack(mainStackPtr);
	puts("The helper stack is:");
	printStack(helperStackPtr);
	StackNodePtr recoverPtr = recoverCipher(mainStackPtr,helperStackPtr);
	puts("Recovered stack is:");
	printStackDetailed(recoverPtr);
	
	return 0;
}
