#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void)
{
	char *polynomial1 = "3x5+1x4+2x3-2x1+5x0";
	char *polynomial2 = "2x5+3x3+7x1+2x0";
	int intg = 0;
	int len = strlen(polynomial1);
	ElementInfo ele;

	StackNodePtr poly1 = NULL;
	StackNodePtr poly2 = NULL;
	
	for(int i = 0; i < len; i++)
	{
		if(i == 0)
		{
			ele.sign = '+';
			ele.num = polynomial1[i] - '0';
			i = i + 2;
			ele.exp = polynomial1[i] - '0';
			push(&poly1, ele);
		}
        	else
        	{
        		ele.sign = polynomial1[i++];
            		ele.num = polynomial1[i] - '0';
            		i = i + 2;
            		ele.exp = polynomial1[i] - '0';
            		push(&poly1, ele);
        	}
	}
	int len2 = strlen(polynomial2);
	
    for(int i = 0; i < len2; i++)
    {
	if(polynomial2[i] == '\0')      break;
        if(i == 0)
        {
            ele.sign = '+';
            ele.num = polynomial2[i] - '0';
            i = i + 2;
            ele.exp = polynomial2[i] - '0';
            push(&poly2, ele);
        }
        else
        {
            ele.sign = polynomial2[i++];
            ele.num = polynomial2[i] - '0';
            i = i + 2;
            ele.exp = polynomial2[i] - '0';
            push(&poly2, ele);
        }
    }
   	system("clear");  //For UNIX
	// system("CLS");  //For Windows

	StackNodePtr p1 = reverseStack(poly1);
	printSplitted(p1,1);
	StackNodePtr p2 = reverseStack(poly2);
	printSplitted(p2,2);
	
	printf("1st polynomial -> ");
	printPolynomial(poly1); // TRUE FORMAT
	printf("2nd polynomial -> ");
	printPolynomial(poly2); // TRUE FORMAT

	printf("\nSum = ");
	StackNodePtr sumPoly = sumThem(poly1,poly2);
	StackNodePtr sumPolyRev = reverseStack(sumPoly);
	printPolynomial(sumPolyRev); // TRUE FORMAT
	
	printf("Sum Simplified = ");
	simplify(sumPolyRev);	
	
	StackNodePtr mulPoly = multiply(poly1,poly2);
	StackNodePtr mulP = simplifyMult(mulPoly);
	printf("Multiplication = ");
	StackNodePtr mu = reverseStack(mulP);
	simplify(mu);
	
	printf("\nDerv. of 1st poly: ");
	StackNodePtr drvPoly1 = derivative(poly1); // TRUE FORMAT
	simplify(drvPoly1);
	printf("Derv. of 2nd poly: ");
	StackNodePtr drvPoly2 = derivative(poly2); // TRUE FORMAT
	simplify(drvPoly2);
	printf("\n");
	return 0;
}
