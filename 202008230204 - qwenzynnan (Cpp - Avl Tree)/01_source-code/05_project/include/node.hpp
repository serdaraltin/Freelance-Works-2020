#include <iostream> 
#include <stack> 
#include <fstream>
#include "max.hpp"

//mevcut yıl değerinin tutulduğu önişlemci değeri
#define YIL 2020

using namespace std;

//kişi sınıfı
class Kisi{
	public:
	string ad;
	int dogum;
	int kilo;
};

//Node sınıfı, avl ağacının her bir öğesi bu sınıftan üretilir
class Node{  
    public: 
    Kisi *kisi;  
    stack <string> yigit; 
    Node *left;  
    Node *right;  
    int height;  
};  

//mevcut yıl değerine bağlı olarak parametre olarak gelen kişi nesnesindeki doğum değerinden yasın hesaplanması ve geriye döndürülmesi
int yasHesapla(Kisi *kisi){
    return (YIL-kisi->dogum);
} 

//parametre olarak gelen düğümün yüksekliğinin geriye döndürülmesi
int height(Node *N){  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

//parametre olarak gelen değer yoluyla, yeni bir düğüm oluşturulup ilgili değerlerin ilgili alanlara atanması
Node* newNode(Kisi* kisi)  {  
    Node* node = new Node(); 
    node-> kisi =  kisi;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    //yeni oluşturulan düğümün yığınına "O" harfinin eklenmesi
    node->yigit.push("O");
    return(node);  
}  

//parametre olarak gelen düğümün sağına ilerlenmesi
Node *rightRotate(Node *y){  
	
    Node *x = y->left;  
    Node *T2 = x->right;  

    x->right = y;  
    y->left = T2;  

    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;  


    return x;  
}  

//parametre olarak gelen düğümün sağına ilerlenmesi
Node *leftRotate(Node *x){  
	
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
  
//parametre olarak gelen düğümün dengesinin hesaplanıp geriye döndürülmesi
int getBalance(Node *N){  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  

//parametre olarak gelen düğüme, parametre olarak gelen kişi bilgisinin eklenmesi
Node* insert(Node* node, Kisi* kisi){  
	
	//düğüm boş ise yeni düğüm oluşturulup geriye döndürülmesi
    if (node == NULL)  {
    	Node * yeni = newNode(kisi);
        return(yeni);  
    }
  	
  	//düğümdeki yaş değerinin, parametre olarak gelen yaş değerinden büyük olması
    if (yasHesapla(kisi) < yasHesapla(node->kisi)){
    	//mevcut düğümde değişiklik olmadığından "D" harfi eklenmesi
    	node->yigit.push("D");
    	//mevcut düğümüm sağında değişiklik olmadığından "D" harfi eklenmesi
    	node->right->yigit.push("D");
    	//mevcut düğümün soluna ekleme
        node->left = insert(node->left, kisi);  

    }	
    //düğümdeki yaş değerinin, parametre olarak gelen yaş değerinden küçük olması
    else if (yasHesapla(kisi) > yasHesapla(node->kisi)){
    	//mevcut düğümün sağına ekleme
        node->right = insert(node->right, kisi);  
      
    }
    else{
        return node;  
    }
 		
 	//mevcut düğümün yüksekliğinin güncellenmesi
    node->height = 1 + max(height(node->left), height(node->right));  

    //mevcut düğümün denge değerinin atanması
    int balance = getBalance(node);  


    //dengenin 1 den büyük olması ve yeni eklenecek olan yaş değerinin mevcut düğümün solunun yaş değerinden küçük olması
    if (balance > 1 && yasHesapla(kisi) < yasHesapla(node->left->kisi)){
    	//düğümün sağa kaydırılması
        return rightRotate(node);  
    }
  	
  	//dengenin -1 den küçük olması ve yeni eklenecek olan yaş değerinin mevcut düğümün sağından yaş değerinden büyük olması
    if (balance < -1 && yasHesapla(kisi) > yasHesapla(node->right->kisi)){
    	//mevcut düğümde değişiklik olmadığından "D" harfi eklenmesi
    	node->yigit.push("D");
    	//düğümün sola kaydırılması
        return leftRotate(node);  
    }
 	//dengenin 1 den büyük olması ve yeni eklenecek olan yaş değerinin mevcut düğümün solunun yaş değerinden büyük olması
    if (balance > 1 && yasHesapla(kisi) > yasHesapla(node->left->kisi)){ 
    	//düğümün solunun, soluna kaydırılması
        node->left = leftRotate(node->left);  
        //düğümün sağa kaydırılması
        return rightRotate(node);  
    }  
    //dengenin -1 den küçük olması ve yeni eklenecek olan yaş değerinin mevcut düğümün solunun yaş değerinden küçük olması
    if (balance < -1 && yasHesapla(kisi) < yasHesapla(node->right->kisi)){  
    	//düğümün sağının, sağına kaydırılması
    	node->right = rightRotate(node->right); 
    	//düğümün sola kaydırılması
        return leftRotate(node);  
    }  
    //mevcut düğümün geri döndürülmesi
    return node;  
}  

//parametre olarak gelen düğümdeki verilerin postOrder olarak listelenmesi
void postOrder(Node *root){  
    if(root != NULL)  {  
    	postOrder(root->left);  
        postOrder(root->right);  

        //o anki düğümdeki kisi bilgilerinin yazdırılması
        cout << root->kisi->ad << ", " << root->kisi->dogum << ", " << root->kisi->kilo;
        cout << "   Yigit: ";

        //yiğin boşalana dek devam eden döngü
        while (!root->yigit.empty()) 
	    { 
	    	//yığındaki elemanların yazdırılması
	        cout << root->yigit.top() << " "; 
	        root->yigit.pop(); 
	    } 
	    cout << endl;
    }  
}  

//parametre olarak değerlerden yeni bir kişi nesnesinin oluşturulması ve geri döndürülmesi
Kisi *yeniKisi(string _ad, int _dogum, int _kilo){
	//Kişi sınıfından kisi nesnesi üretilmesi
	Kisi *yeni = new Kisi();
	yeni->ad = _ad;
	yeni->dogum = _dogum;
	yeni->kilo = _kilo;
	//yeni üretilen kisi nesnesinin geriye döndürülmesi
	return (yeni);
} 

