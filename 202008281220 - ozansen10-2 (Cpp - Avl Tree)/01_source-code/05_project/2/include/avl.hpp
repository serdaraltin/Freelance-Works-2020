#include <iostream> 
#include "nod.hpp"
#include "max.hpp"

using namespace std;

int cAge(Indiv *indiv){
    return 2020-indiv->Inativ;
} 

int altitude(Node *node){  
    if (node == NULL)  
        return 0;  
    return node->altitude;  
}  
  
Indiv *newIndi(string iname, int inativ, int iponder){
	Indiv *oNew = new Indiv();
	oNew->Iname = iname;
	oNew->Inativ = inativ;
	oNew->Iponder = iponder;
	return (oNew);
} 

Node* newNode(Indiv* indiv)  {  
    Node* node = new Node(); 
    node-> indiv =  indiv;  
    node->dex = NULL;  
    node->right = NULL;  
    node->altitude = 1; 
    node->heap.push("O");
    return(node);  
}  

Node *RotR(Node *b){  
    Node *a = b->dex;  
    Node *T2 = a->right;  
    a->right = b;  
    b->dex = T2;  
    b->altitude = getBig(altitude(b->dex), altitude(b->right)) + 1;  
    a->altitude = getBig(altitude(a->dex), altitude(a->right)) + 1;  
    return a;  
}  

void listPostOrder(Node *org){  
    if(org != NULL)  {  
    	listPostOrder(org->dex);  
        listPostOrder(org->right);  
        cout << org->indiv->Iname << ", " << org->indiv->Inativ << ", " << org->indiv->Iponder;
        cout << "   Yigit: ";
        while (!org->heap.empty()) { 
	        cout << org->heap.top() << " "; 
	        org->heap.pop(); 
	    } 
	    cout << endl;
    }  
} 

int cStability(Node *node){  
    if (node == NULL)  
        return 0;  
    return altitude(node->dex) - altitude(node->right);  
}  

Node *RotL(Node *a){  
    Node *b = a->right;  
    Node *T2 = b->dex;  
    b->dex = a;  
    a->right = T2;  
    a->altitude = getBig(altitude(a->dex), altitude(a->right)) + 1;  
    a->heap.push("A");
    b->altitude = getBig(altitude(b->dex), altitude(b->right)) + 1;  
 	b->heap.push("Y");
    return b;  
}  

Node* insert(Node* node, Indiv* indiv){  
    if (node == NULL)  {
    	Node * oNew = newNode(indiv);
        return(oNew);  
    }
    if (cAge(indiv) < cAge(node->indiv)){
    	node->heap.push("D");
    	node->right->heap.push("D");
        node->dex = insert(node->dex, indiv);  
    }	
    else if (cAge(indiv) > cAge(node->indiv))
        node->right = insert(node->right, indiv);  
    else
        return node;  
    node->altitude = 1 + getBig(altitude(node->dex), altitude(node->right));  
    int stability = cStability(node);  
    if (stability < -1 && cAge(indiv) < cAge(node->right->indiv)){  
    	node->right = RotR(node->right); 
        return RotL(node);  
    } 
    if (stability > 1 && cAge(indiv) < cAge(node->dex->indiv))
        return RotR(node); 
    if (stability > 1 && cAge(indiv) > cAge(node->dex->indiv)){ 
        node->dex = RotL(node->dex);  
        return RotR(node);  
    }  
    if (stability < -1 && cAge(indiv) > cAge(node->right->indiv)){
    	node->heap.push("D");
        return RotL(node);  
    }
    return node;  
}  



