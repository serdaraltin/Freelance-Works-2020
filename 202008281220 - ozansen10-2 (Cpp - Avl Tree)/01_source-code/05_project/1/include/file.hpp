#include "tree.hpp"

void Read(string fName){
    ifstream myfile(fName);
    CNode *pStem = NULL;
    while(!myfile.eof())
    {
        string pName,_deliv,_heft;
        getline(myfile,pName,'#');
        getline(myfile,_deliv,'#');
        int pDeliv = stoi(_deliv);
        getline(myfile,_heft,'\n');
        int pHeft = stoi(_heft);	
        pStem = addNod(pStem, recPerson(pName,pDeliv,pHeft));
    }
    myfile.close();
    
    printTree(pStem);   
    free(pStem);
} 