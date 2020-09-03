#ifndef RASTGELEURET_H
#define RASTGELEURET_H
int rast(int m,int mx){int addr = 0xACE1u;
int b,poin=0; int *value;value = (int*)malloc(sizeof(int)); 
      int res = ((int)value);poin = poin ^ res; b  = ((addr >> 0) ^ (addr >> 2) ^ (addr >> 3) ^ (addr >> 5) ) & 1;
      addr = ((b<<15) | (addr>>1) | poin)%mx;
      while(addr<m){ addr = addr + mx - m; }
      return addr;}
#endif 

