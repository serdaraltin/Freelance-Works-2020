/**
* @file node.hpp
* @description Class'ın özeti
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 2020.08.28
* @author Emre Uysal
*/

#include "people.hpp"

using namespace std;

class Node{  
    public: 
    Node();
    People *peop;  
    int hei;
    stack <string> sst; 
    Node *l,*r;
};  