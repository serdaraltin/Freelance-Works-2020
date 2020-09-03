#include <fstream>
#include "avl.hpp"

void fileRead(){
 	Node *org = NULL;  

    ifstream readFile("Kisiler.txt");

    if(readFile.is_open()){
        string Iname;
        string sInativ;
        string sIponder;
        while(!readFile.eof()){
            getline(readFile,Iname,'#');
            getline(readFile,sInativ,'#');
            getline(readFile,sIponder,'\n');
            int Inativ = stoi(sInativ);
            int Iponder = stoi(sIponder);	
            org = insert(org, newIndi(Iname,Inativ,Iponder));
        }
        readFile.close();

    }
    listPostOrder(org);   
} 