#include <stdio.h>
#include <stdlib.h>

enum e_c{
	business,
	economy,
	standard
};

enum e_p{
	veteran,
	diplomat
};

typedef struct n{
	char *flight;
	enum e_c clas_s;
	char *passenger_name;
	enum e_p piority;
	struct n *next;
}Customer;

void addseat(char *flight, enum e_c clas_s, int count);

void enqueue(char *flight, enum e_c clas_s, char *passenger_name, 
enum e_p piority);

void sell(char *flight);

void close(char *flight);

void report(char *flight);

void info(char *passenger_name);

Customer *flight = NULL;

int main(){




}


void addseat(char *flight, enum e_c clas_s, int count){
	
	


}
