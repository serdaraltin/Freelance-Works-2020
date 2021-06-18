/**
* @file node.cpp
* @description Kullandığımız fonksiyonlar ve main kısmı
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 2020.08.28
* @author Emre Uysal
*/
#include <iostream> 
#include <fstream>
#include <stack> 

#include "node.hpp"

using namespace std;

int mx(int p1, int p2)  {  
	if(p1 > p2)
		return p1;
	return p2; 
}  
int cage(People *peop){
    return 2020-peop->btd;
} 
int hei(Node *N){  
    if (N == NULL)  
        return 0;  
    return N->hei;  
}  
Node* nnod(People* peop)  {  
    Node* node = new Node(); 
    node-> peop =  peop;  
    node->l = NULL;  
    node->r = NULL;  
    node->hei = 1; 
    node->sst.push("O");
    return(node);  
}  
Node *rR(Node *y){  
    Node *x = y->l;  
    Node *T2 = x->r;  
    x->r = y;  
    y->l = T2;  
    y->hei = mx(hei(y->l), hei(y->r)) + 1;  
    x->hei = mx(hei(x->l), hei(x->r)) + 1;  
    return x;  
}  
Node *leftRotate(Node *x){  
    Node *y = x->r;  
    Node *T2 = y->l;  
    y->l = x;  
    x->r = T2;  
    x->hei = mx(hei(x->l), hei(x->r)) + 1;  
    x->sst.push("A");
    y->hei = mx(hei(y->l), hei(y->r)) + 1;  
 	y->sst.push("Y");
    return y;  
}  
int gblnc(Node *N){  
    if (N == NULL)  
        return 0;  
    return hei(N->l) - hei(N->r);  
}  
Node* insnod(Node* node, People* peop){  
    if (node == NULL)  {
    	Node * yeni = nnod(peop);
        return(yeni);  
    }
    if (cage(peop) < cage(node->peop)){
    	node->sst.push("D");
    	if(node->r != NULL)
    	node->r->sst.push("D");
        node->l = insnod(node->l, peop);  
    }	
    else if (cage(peop) > cage(node->peop))
        node->r = insnod(node->r, peop);  
    else
        return node;  
    node->hei = 1 + mx(hei(node->l), hei(node->r));  
    int balance = gblnc(node);  
    if (balance < -1 && cage(peop) > cage(node->r->peop)){
    	node->sst.push("D");
        return leftRotate(node);  
    }
    if (balance > 1 && cage(peop) < cage(node->l->peop))
        return rR(node);  
    if (balance < -1 && cage(peop) < cage(node->r->peop)){  
    	node->r = rR(node->r); 
        return leftRotate(node);  
    }  
    if (balance > 1 && cage(peop) > cage(node->l->peop)){ 
        node->l = leftRotate(node->l);  
        return rR(node);  
    }  
    return node;  
}  
void listprint(Node *rt){  
    if(rt != NULL)  {  
    	listprint(rt->l);  
        listprint(rt->r);  
        cout << rt->peop->nm << ", " << rt->peop->btd << ", " << rt->peop->wei;
        cout << "   Yigit: ";
        while (!rt->sst.empty()) 
	    { 
	        cout << rt->sst.top() << " "; 
	        rt->sst.pop(); 
	    } 
	    cout << endl;
    }  
}  
People *nprsn(string pnm, int pbt, int pwei){
	People *yeni = new People();
	yeni->nm = pnm;
	yeni->btd = pbt;
	yeni->wei = pwei;
	return (yeni);
} 
void fR(){
 	Node *rt = NULL;  
    ifstream of("Kisiler.txt");
    string nm;
    string sbt;
    string sw;
    while(!of.eof()){
        getline(of,nm,'#');
        getline(of,sbt,'#');
        getline(of,sw,'\n');
        int btd = stoi(sbt);
        int wei = stoi(sw);	
        rt = insnod(rt, nprsn(nm,btd,wei));
    }
    of.close();
    listprint(rt);   
    free(rt);
}  

int main(){
    fR();
}