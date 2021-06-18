#include <iostream> 
#include <stack> 
#include <fstream>
#include "ageCalculate.hpp"
#include "depth.hpp"
#include "maximum.hpp"
#include "printfTree.hpp"

using namespace std;

int getPoise(CNode *N){  
    if (N == NULL)  
        return 0;  
    return depth(N->pLeft) - depth(N->pRight);  
}  

CNode* recNod(CPerson* pPerson)  {  
    CNode* pNod = new CNode(); 
    pNod-> pPerson =  pPerson;  
    pNod->pLeft = NULL;  
    pNod->pRight = NULL;  
    pNod->depth = 1; 
    pNod->cSt.push("O");
    return(pNod);  
}  

CNode *turnRight(CNode *y){  
    CNode *x = y->pLeft;  
    CNode *T2 = x->pRight;  
    x->pRight = y;  
    y->pLeft = T2;  
    y->depth = getMaximum(depth(y->pLeft), depth(y->pRight)) + 1;  
    x->depth = getMaximum(depth(x->pLeft), depth(x->pRight)) + 1;  
    return x;  
}  

CNode *turnLeft(CNode *x){  
    CNode *y = x->pRight;  
    CNode *T2 = y->pLeft;  
    y->pLeft = x;  
    x->pRight = T2;  
    x->depth = getMaximum(depth(x->pLeft), depth(x->pRight)) + 1;  
    x->cSt.push("A");
    y->depth = getMaximum(depth(y->pLeft), depth(y->pRight)) + 1;  
 	y->cSt.push("Y");
    return y;  
}  
  
CNode* addNod(CNode* pNod, CPerson* pPerson){  
    if (pNod == NULL)  {
    	CNode * nove = recNod(pPerson);
        return(nove);  
    }
    if (ageCalculate(pPerson) < ageCalculate(pNod->pPerson)){
    	pNod->cSt.push("D");
    	pNod->pRight->cSt.push("D");
        pNod->pLeft = addNod(pNod->pLeft, pPerson);  
    }	
    else if (ageCalculate(pPerson) > ageCalculate(pNod->pPerson)){
        pNod->pRight = addNod(pNod->pRight, pPerson);  
    }
    else{
        return pNod;  
    }
    pNod->depth = 1 + getMaximum(depth(pNod->pLeft), depth(pNod->pRight));  
    int poise = getPoise(pNod);  
    if (poise > 1 && ageCalculate(pPerson) < ageCalculate(pNod->pLeft->pPerson)){
        return turnRight(pNod);  
    }
    if (poise < -1 && ageCalculate(pPerson) > ageCalculate(pNod->pRight->pPerson)){
    	pNod->cSt.push("D");
        return turnLeft(pNod);  
    }
    if (poise > 1 && ageCalculate(pPerson) > ageCalculate(pNod->pLeft->pPerson)){ 
        pNod->pLeft = turnLeft(pNod->pLeft);  
        return turnRight(pNod);  
    }  
    if (poise < -1 && ageCalculate(pPerson) < ageCalculate(pNod->pRight->pPerson)){  
    	pNod->pRight = turnRight(pNod->pRight); 
        return turnLeft(pNod);  
    }  
    return pNod;  
}  

CPerson *recPerson(string _ad, int _dogum, int _kilo){
	CPerson *nove = new CPerson();
	nove->pName = _ad;
	nove->pDeliv = _dogum;
	nove->pHeft = _kilo;
	return (nove);
} 

