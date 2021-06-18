#ifndef RASTGELEURET_H
#define RASTGELEURET_H
int rast(int bas,int son){
      int bellek = 0xACE1u;
      int b,alt=0;
      int *sayi;
      sayi = (int*)malloc(sizeof(int)); 
      int res = ((int)sayi);

      alt = alt ^ res;
      b  = ((bellek >> 0) ^ (bellek >> 2) ^ (bellek >> 3) ^ (bellek >> 5) ) & 1;
      bellek = ((b<<15) | (bellek>>1) | alt)%son;
      while(bellek<bas){
          bellek = bellek + son - bas;
      }

      return bellek;
}
#endif 

