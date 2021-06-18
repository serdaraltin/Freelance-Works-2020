#include <iostream> 
#include <stack> 
#include <fstream>

using namespace std; 

#define YIL 2020
  
class Kisi{
	public:
	string ad;
	int dogum;
	int kilo;
};

class Node  {  
    public: 
    Kisi *kisi;  
    stack <string> yigit; 
    Node *left;  
    Node *right;  
    int height;  
};  

int yasHesapla(Kisi *kisi){
	return (YIL-kisi->dogum);
}

int max(int a, int b);  

int height(Node *N)  {  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

int max(int a, int b)  {  
    return (a > b)? a : b;  
}  

Node* newNode(Kisi* kisi)  {  
    Node* node = new Node(); 
    node-> kisi =  kisi;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    node->yigit.push("O");
    return(node);  
}  

Node *rightRotate(Node *y)  {  
    Node *x = y->left;  
    Node *T2 = x->right;  

    x->right = y;  
    y->left = T2;  

    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;  


    return x;  
}  

Node *leftRotate(Node *x)  {  
	
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    y->left = x;  
    x->right = T2;  
  
    x->height = max(height(x->left), height(x->right)) + 1;  
    x->yigit.push("A");
    y->height = max(height(y->left), height(y->right)) + 1;  
 	y->yigit.push("Y");

    return y;  
}  
  
int getBalance(Node *N)  {  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
void ekleHarf(Node* node, string harf){
	node->yigit.push(harf);
	return;
}


Node* insert(Node* node, Kisi* kisi)  {  
	
    if (node == NULL)  {
    	Node * yeni = newNode(kisi);
        return(yeni);  
    }
  	
    if (yasHesapla(kisi) < yasHesapla(node->kisi))  {
    	
        node->left = insert(node->left, kisi);  

    }	
    else if (yasHesapla(kisi) > yasHesapla(node->kisi)){

        node->right = insert(node->right, kisi);  
      
    }
    else{
    
        return node;  
    }
 		
    node->height = 1 + max(height(node->left), height(node->right));  

    int balance = getBalance(node);  


    if (balance > 1 && yasHesapla(kisi) < yasHesapla(node->left->kisi))  {
        return rightRotate(node);  
    }
  
    if (balance < -1 && yasHesapla(kisi) > yasHesapla(node->right->kisi)){
        return leftRotate(node);  
    }
 
    if (balance > 1 && yasHesapla(kisi) > yasHesapla(node->left->kisi))  { 
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  

    if (balance < -1 && yasHesapla(kisi) < yasHesapla(node->right->kisi))  {  
    	node->right = rightRotate(node->right); 
        return leftRotate(node);  
    }  

    
    return node;  
}  

void postOrder(Node *root)  {  
    if(root != NULL)  {  
    	postOrder(root->left);  
        postOrder(root->right);  

        cout << root->kisi->ad << ", " << root->kisi->dogum << ", " << root->kisi->kilo;
        cout << "   Yigit: ";

        while (!root->yigit.empty()) 
	    { 
	        cout << root->yigit.top() << " "; 
	        root->yigit.pop(); 
	    } 
	    cout << endl;
    }  
}  

Kisi *yeniKisi(string _ad, int _dogum, int _kilo){
	Kisi *yeni = new Kisi();
	yeni->ad = _ad;
	yeni->dogum = _dogum;
	yeni->kilo = _kilo;
	return (yeni);
}
  
int main()  
{  

    Node *root = NULL;  

    ifstream myfile("Kisiler.txt");

    if(myfile.is_open())
    {
        string ad;
        string sdogum;
        string skilo;
        while(!myfile.eof())
        {
            getline(myfile,ad,'#');
         
            getline(myfile,sdogum,'#');

            getline(myfile,skilo,'\n');

            int dogum = stoi(sdogum);
            int kilo = stoi(skilo);

            root = insert(root, yeniKisi(ad,dogum,kilo));
        }
        myfile.close();

    }
    postOrder(root);  

    return 0;  
}  
