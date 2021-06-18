#include "KolaMakine.h"
#include <iostream>

int main(){
    
    KolaMakinesi makine;
    
    makine.ilkYukleme(2,50);
    std::cout<<std::endl;
    
    makine.goster();
    std::cout<<std::endl;
    
    makine.kolaVerme();
    std::cout<<std::endl;
    
    makine.goster();
}
