#include <stdio.h>
#include <stdlib.h>


 
int randa(int startNumber,int endNumber)
{
	unsigned int lfsr = 0xACE1u;
	unsigned int bit,t=0;
    if(startNumber == endNumber) return startNumber;
    int p;
    t = t ^ p;
    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    lfsr = ((bit<<15) | (lfsr>>1) | t)%endNumber;
    while(lfsr<startNumber){
        lfsr = lfsr + endNumber - startNumber;
    }
    return lfsr;
}


int main()
{
	int i;
	for(i=0; i<50; i++)
    	printf("%d\n",randa(0,100) );
    return 0;
}

