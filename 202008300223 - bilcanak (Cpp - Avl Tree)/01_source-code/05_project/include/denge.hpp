#include "dugum.hpp"
#include "yukseklik.hpp"

using namespace std;
//ağacon denge durumunun hesaplanması
int dengeDurumu(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return yukseklik(N->dugumSol) - yukseklik(N->dugumSag);  
}  