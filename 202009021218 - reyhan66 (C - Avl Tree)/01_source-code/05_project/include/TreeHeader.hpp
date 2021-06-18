#include <iostream> 
#include <stack> 
#include <fstream>

using namespace std;

class Pers{
	public:
	string nameVal;
	int birthDVal;
	int weightVal;
};

class Nod{  
    public: 
    Pers *per;  
    stack <string> nstack; 
    Nod *nodLeft;  
    Nod *nodRight;  
    int deepVal;  
};  
int bigVal(int a, int b)  {  
	if(a < b)
		return b;
	if(a == b)
		return b;
	return a; 
}  
int deepVal(Nod *N){  
    if (N == NULL)  
        return 0;  
    return N->deepVal;  
}  
Nod* creNod(Pers* per)  {  
    Nod* nod = new Nod(); 
    nod-> per =  per;  
    nod->nodLeft = NULL;  
    nod->nodRight = NULL;  
    nod->deepVal = 1; 
    nod->nstack.push("O");
    return(nod);  
}  
Nod *goRight(Nod *y){  
    Nod *x = y->nodLeft;  
    Nod *T2 = x->nodRight;  
    x->nodRight = y;  
    y->nodLeft = T2;  
    y->deepVal = bigVal(deepVal(y->nodLeft), deepVal(y->nodRight)) + 1;  
    x->deepVal = bigVal(deepVal(x->nodLeft), deepVal(x->nodRight)) + 1;  
    return x;  
}  
Nod *goLeft(Nod *x){  
    Nod *y = x->nodRight;  
    Nod *T2 = y->nodLeft;  
    y->nodLeft = x;  
    x->nodRight = T2;  
    x->deepVal = bigVal(deepVal(x->nodLeft), deepVal(x->nodRight)) + 1;  
    x->nstack.push("A");
    y->deepVal = bigVal(deepVal(y->nodLeft), deepVal(y->nodRight)) + 1;  
 	y->nstack.push("Y");
    return y;  
}  
int balanceVal(Nod *N){  
    if (N == NULL)  
        return 0;  
    return deepVal(N->nodLeft) - deepVal(N->nodRight);  
}  
int ageVal(Pers *per){
    return 2020-per->birthDVal;
}   
Nod* nodAdd(Nod* nod, Pers* per){  
    if (nod == NULL)  {
    	Nod * nVal = creNod(per); return(nVal);  
    }
    if (ageVal(per) < ageVal(nod->per)){
    	nod->nstack.push("D");
        if(nod->nodRight != NULL)
    	nod->nodRight->nstack.push("D");
        nod->nodLeft = nodAdd(nod->nodLeft, per);  
    }	
    else if (ageVal(per) > ageVal(nod->per))
        nod->nodRight = nodAdd(nod->nodRight, per);  
    else
        return nod;  
    nod->deepVal = 1 + bigVal(deepVal(nod->nodLeft), deepVal(nod->nodRight));  
    int balance = balanceVal(nod);  
    if (balance > 1 && ageVal(per) < ageVal(nod->nodLeft->per))
     return goRight(nod);  
    if (balance < -1 && ageVal(per) > ageVal(nod->nodRight->per)){
    	nod->nstack.push("D");return goLeft(nod);  
    }
    if (balance < -1 && ageVal(per) < ageVal(nod->nodRight->per)){  
    	nod->nodRight = goRight(nod->nodRight); return goLeft(nod);  
    }  
     if (balance > 1 && ageVal(per) > ageVal(nod->nodLeft->per)){ 
        nod->nodLeft = goLeft(nod->nodLeft);  return goRight(nod);  
    }  
    return nod;  
}  

Pers *crePers(string pnameVal, int pbirthDVal, int pweightVal){
	Pers *nVal = new Pers();
	nVal->nameVal = pnameVal; nVal->birthDVal = pbirthDVal; nVal->weightVal = pweightVal;
	return nVal;
} 

void postOrder(Nod *rootNod){  
    if(rootNod != NULL)  {  
    	postOrder(rootNod->nodLeft);  
        postOrder(rootNod->nodRight);  
        cout << rootNod->per->nameVal << ", " << rootNod->per->birthDVal << ", " << rootNod->per->weightVal;
        cout << "   Yigit: ";
        while (!rootNod->nstack.empty()) { 
	        cout << rootNod->nstack.top() << " "; 
	        rootNod->nstack.pop(); 
	    } 
	    cout << endl;
    }  
}  
