#include <iostream> 
#include <stack> 
#include "indiv.hpp"

using namespace std;
class Node{  
    public: 
    Indiv *indiv;  
    stack <string> heap; 
    Node *dex;  
    Node *right;  
    int altitude;  
};  