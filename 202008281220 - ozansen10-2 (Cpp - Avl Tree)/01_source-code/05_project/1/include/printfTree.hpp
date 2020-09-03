
void printTree(CNode *pStem){  
    if(pStem != NULL)  {  
    	printTree(pStem->pLeft);  
        printTree(pStem->pRight);  

        cout << pStem->pPerson->pName << ", " << pStem->pPerson->pDeliv << ", " << pStem->pPerson->pHeft;
        cout << "   Yigit: ";

        while (!pStem->cSt.empty()) 
	    { 
	        cout << pStem->cSt.top() << " "; 
	        pStem->cSt.pop(); 
	    } 
	    cout << endl;
    }  
}  
