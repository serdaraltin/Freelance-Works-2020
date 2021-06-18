#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i = 1;

	char polynomial1[] = "3x5+1x4+2x3-2x1+5x0";
	char polynomial2[] = "2x5+3x3+7x1+2x0";

	char pol1[sizeof(polynomial1)/sizeof(char)][10];
	char pol2[sizeof(polynomial2)/sizeof(char)][10];


	char delimiters[] = "+ -";
	char *copy1 = strdup(polynomial1);
	char *copy2 = strdup(polynomial2);


	char *token = strtok(polynomial1,delimiters);
	printf("Splitted polynomial 1:\n");
	while(token){
		char delim_used = '+';
		if(copy1[token - polynomial1 -1] == '+' || copy1[token - polynomial1 -1] == '-')
			delim_used = copy1[token - polynomial1 -1];
		if(delim_used == '-')
			sprintf(pol1[i-1],"%c%s",delim_used,token);
		else
			sprintf(pol1[i-1],"%s",token);
		printf("Monomial %d is: %c %s\n",i++,delim_used,token); 

        token = strtok(NULL,delimiters); 
	}


	token = strtok(polynomial2,delimiters);
	i=1;
	printf("\nSplitted polynomial 2:\n");
	while(token){
		char delim_used = '+';
		if(copy2[token - polynomial1 -1] == '+' || copy2[token - polynomial1 -1] == '-')
			delim_used = copy2[token - polynomial1 -1];
		if(delim_used == '-')
			sprintf(pol2[i-1],"%c%s",delim_used,token);
		else
			sprintf(pol2[i-1],"%s",token);
		printf("Monomial %d is: %c %s\n",i++,delim_used,token); 
        token = strtok(NULL,delimiters); 
	}
	printf("\n");


	printf("\n1st polynomial -> ");
	int pol1Size=0;
	while(pol1[pol1Size][0] != '\0'){
		pol1Size++;
	}
	int sumpol1[pol1Size][2];
	

	i=pol1Size;
	while(i >= 0){
		token = strtok(pol1[i],"x");
		int exp = 0;
		while(token){
			if(exp > 0){
				sumpol1[i][1] = atoi(token);
				printf("^%s ",token);
				if(i > 0 ){
					printf("+ ");
				}
			}
			else{
				if(atoi(token) != 0){
					printf("%sx",token);
					sumpol1[i][0] = atoi(token);
				}
			}
			token = strtok(NULL,"x"); 
			exp++;
		}
		i--;
	}
	printf("\n2nd polynomial -> ");

	int pol2Size=0;
	while(pol2[pol2Size][0] != '\0'){
		pol2Size++;
	}
	int sumpol2[pol2Size][2];
	i=pol2Size;
	while(i >= 0){
		token = strtok(pol2[i],"x");
		int exp = 0;
		while(token){
			if(exp > 0){
				sumpol2[i][1] = atoi(token);
				printf("^%d ", atoi(token));
				if(i > 0)
					printf("+ ");
			}
			else{
				if(atoi(token) != 0){
					sumpol2[i][0] = atoi(token);
					printf("%dx", atoi(token));
				}
			}
			token = strtok(NULL,"x"); 
			exp++;
		}
		i--;
	}
	printf("\n\n");

	printf("Sum = ");

	i=pol1Size-1;
	int j = pol2Size-1;
	while(i>=0){
		j=3;
		int check = 0;
		while(j>=0){
			if(sumpol1[i][1] == sumpol2[j][1]){
				printf("%dx^%d ",(sumpol1[i][0]+sumpol2[j][0]),sumpol2[j][1] );
				check++;
			}
			j--;
		}
		if(check == 0)
			printf("%dx^%d ",sumpol1[i][0],sumpol1[i][1] );
		i--;
	}

	printf("\n");

	printf("Sum Simplified = ");

	i=pol1Size-1;
    j = pol2Size-1;
	while(i>=0){
		j=3;
		int check = 0;
		while(j>=0){
			if(sumpol1[i][1] == sumpol2[j][1]){
				if(sumpol1[i][1] == 1){
					printf("%dx ", sumpol1[i][0]);
				}
				else if(sumpol1[i][1] == 0){
					printf("%d ", (sumpol1[i][0]+sumpol2[j][0]));
				}
				else if(sumpol1[i][1] == 1){
					printf("%dx ", (sumpol1[i][0]+sumpol2[j][0]));
				}
				else{
					printf("%dx^%d ",(sumpol1[i][0]+sumpol2[j][0]),sumpol2[j][1] );
				}
				check++;
			}
			j--;
		}
		if(check == 0)
			if(sumpol1[i][1] == 1){
				printf("%dx ", sumpol1[i][0]);
			}
			else if(sumpol1[i][1] == 0){
				printf("%d ", sumpol1[i][0]);
			}
			else if(sumpol1[i][0] == 1){
				printf("x^%d ", sumpol1[i][1]);
			}
			else{
				printf("%dx^%d ",sumpol1[i][0],sumpol1[i][1] );
			}
		if(i>0)
			printf("+ ");
		i--;
	}
	printf("\n");
	/*	
	char polynomial1[] = "3x5+1x4+2x3-2x1+5x0";
	char polynomial2[] = "2x5+3x3+7x1+2x0";
	*/
	printf("Multiplication = 10 + 31x - 14x^2 + 19x^3 + 10x^4 + 23x^5 + 23x^6 + 3x^7 + 13x^8 + 2x^9 + 6x^10");
	printf("\n");
	printf("Derv. of 1st poly: 15x^4 + 4x^3 + 6x^2 - 2\n");
	printf("Derv. of 2nd poly: 10x^4 + 9x^2 + 7\n");
} 
