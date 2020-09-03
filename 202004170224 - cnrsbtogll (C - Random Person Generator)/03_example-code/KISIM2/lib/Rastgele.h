#ifndef RASTGELE_H
#define RASTGELE_H
int rast(int startNumber,int endNumber){
      int lfsr = 0xACE1u;
      int bit,t=0;
      int *p;
      p = (int*)malloc(sizeof(int)); 
      int res = ((int)p%10);

      t = t ^ res;
      bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
      lfsr = ((bit<<15) | (lfsr>>1) | t)%endNumber;
      while(lfsr<startNumber){
          lfsr = lfsr + endNumber - startNumber;
      }

      return lfsr;
}

#endif

