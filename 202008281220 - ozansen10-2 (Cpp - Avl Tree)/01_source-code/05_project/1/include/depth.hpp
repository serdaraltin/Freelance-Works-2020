#include "node.hpp"

int depth(CNode *N){  
    if (N == NULL)  
        return 0;  
    return N->depth;  
}  
