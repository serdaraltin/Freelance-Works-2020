#include "mylib.h"

#define TEST2 0

int main(){

	if(TEST2){

		int size=10;

		stack* newS = newStack(size);

		int i;
		for (int i = 0; i < size; ++i)
			push(newS,i*10);

		display(newS);

		for (int i = 0; i < size/2; ++i)
			printf("pop -> %d\n",pop(newS));

		display(newS);

		char str[] = "test123";
		printf("before string value -> %s\n", str);

		stack* newS2 = newStack(strlen(str));
		stringReverse(str,newS2);
		
		printf("after string value -> %s\n",str);
		
	}

	return 0;
}