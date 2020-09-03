#include <stdio.h>
#include <stdlib.h>

int size = 4;

void display(int *array,int n);

int main(){
	int i;

	//1.
	int *array = (int*)malloc(sizeof(int)*size);
	for(i=0; i<size; i++)
		*(array+i) = -1;
	display(array,size);
	//2.a
	size+=1;
	int *array2 = (int*)malloc(sizeof(int)*size);
	display(array2,size);
	//2.b
	for(i=0; i<size-1; i++)
		*(array2+i)  = array[i];
	display(array2,size);
	//2.c
	array2[i] = 1;
	display(array2,size);
	//2.d
	free(array);
	display(array2,size);
	//3
	int tmp_size = size;
	int *temp = (int*)malloc(sizeof(int)*size);
	for(i=0; i<size; i++)
		*(temp+i)  =*(array2+i);
	free(array2);

	size*=2;
	array2 = (int*)malloc(sizeof(int)*size);		

	for(i=0; i<size; i++)
		*(array2+i)=*(temp+i) ;
	for(i=tmp_size; i<size; i++)
		*(array2+i) = *(array2+(i-tmp_size));
	free(temp);
	display(array2,size);
	//4
	size = tmp_size;
	temp = (int*)malloc(sizeof(int)*size);
	for(i=0; i<size; i++)
		*(temp+i) =*(array2+i);
	free(array2);
	array2 = (int*)malloc(sizeof(int)*size);
	for(i=0; i<size; i++)
		*(array2+i) =*(temp+i);
	free(temp);
	display(array2,size);
	//5
	temp = (int*)malloc(sizeof(int)*size-1);
	for(i=1; i<size; i++)
		*(temp+(i-1)) =*(array2+i);
	size--;
	array2 = (int*)malloc(sizeof(int)*size);
	for(i=0; i<size; i++)
		*(array2+i)= *(temp+i);
	display(array2,size);

}
void display(int *array,int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d\n",*(array+i));
	printf("----------------\n");
}
