#include <iostream> 
#include <stack> 

using namespace std;

class CNode{  
    public: 
    int depth;  
    stack <string> cSt; 
    CPerson *pPerson;  
    CNode *pLeft;  
    CNode *pRight;  
};  