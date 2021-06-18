#include "TreeHeader.hpp"

void fileReader(){
 	Nod *rootNod = NULL;  
    ifstream fileRead("Kisiler.txt");

    string nameVal;
    string pbirth;
    string pweight;

    while(!fileRead.eof())
    {
        getline(fileRead,nameVal,'#');
        getline(fileRead,pbirth,'#');
        getline(fileRead,pweight,'\n');
        int birthDVal = stoi(pbirth);
        int weightVal = stoi(pweight);	
        rootNod = nodAdd(rootNod, crePers(nameVal,birthDVal,weightVal));
    }
    fileRead.close();

    postOrder(rootNod);   
} 