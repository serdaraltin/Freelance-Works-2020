#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//ikili dugum yapisi
struct node{
    int data; 
    struct node *right; 
    struct node *left; 
};

//gelen parametre ile yeni bir dugum olusturma ve dugumu geri dondurme
struct node* new_node(int x)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

//parametre olarak gelen dugume, parametre olarak gelen degeri ekleme ve dugumu geri dondurme
struct node* insert(struct node* node, int data) 
{ 
    if (node == NULL) return new_node(data); 
  
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    

    return node; 
} 

//parametre olarak gelen dugumdeki minimum degeri barindiran dugumu bulma ve dugumu geri dondurme
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL)
        return find_minimum(root->left); 
    return root;
}

//parametre olarak gelen dugumden, parametre olarak gelen degeri silme ve dugumu geri dondurme
struct node* deleteNode(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = deleteNode(root->right, x);
    else if(x<root->data)
        root->left = deleteNode(root->left, x);
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

//parametre olarak gelen dugumu PostOrder olarak listeleme
void postOrder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     postOrder(node->left); 
     postOrder(node->right); 
     printf("%d ", node->data); 
} 

//parametre olarak gelen dugumu InOrder olarak listeleme
void inOrder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     inOrder(node->left); 
     printf("%d ", node->data);   
     inOrder(node->right); 
} 

//parametre olarak gelen dugumu PreOrder olarak listeleme
void preOrder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);   
     preOrder(node->left);   
     preOrder(node->right); 
}     

//parametre olarak gelen dugumdeki eleman sayisini bulma ve geri dondurme
int count(node *node)
{
    int c =  1;
    if (node ==NULL)
        return 0;
    else
    {
        c += count(node->left);
        c += count(node->right);
        return c;
    }
}

//fonksiyon prototipleri
void Menu();
void IkiliAgac();

//main fonksiyonu
int main(){
	Menu();
}

//ana menu
void Menu(){
	printf("Yapmak istediginiz uygulamayi seciniz:\n");
	printf("1- Yigin Uygulamasi\n");
	printf("2- Kuyruk Uygulamasi\n");
	printf("3- Tek Yonlu Bagli Liste Uygulamasi\n");
	printf("4- Ikili Agac Uygulamasi\n");
	printf("5- Cirpilma Uygulamasi\n");
	printf("6- Programdan Cikis\n");

	int choice;
	scanf("%d",&choice);

	switch(choice){
		case 6:
		  exit(0);
		 	break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			//Ikili Agac Uygulamasi
			IkiliAgac();
			break;
		case 5:
			break;
		default:
			printf("Hatali bir secim yaptiniz\n");
			break;	
	
	}
	printf("\n");
	Menu();
}

//ikili agac menusu
void IkiliAgac(){
	struct node* root = NULL;

	while(1){
		printf("Ikili Agac icin islem seciniz:\n");
		printf("1- Agaca Eleman Ekle\n");
		printf("2- Agactan Eleman sil\n");
		printf("3- Agaci Temizle\n");
		printf("4- Agactaki Eleman Sayisini goster\n");
		printf("5- Agaci InOrder dolasarak Elemanlari Goster\n");
		printf("6- Agaci PreOrder dolasarak Elemanlari Goster\n");
		printf("7- Agaci PostOrder dolasarak Elemanlari Goster\n");
		printf("8- Ana menuye geri don\n");

		int choice;
		scanf("%d",&choice);
		printf("\n\n");	
		switch(choice){
			case 8:
			  Menu();
			 	break;
			case 1:
				printf("Ekelenecek Eleman [1,2,3...] : ");
				int eklenecek;
				scanf("%d",&eklenecek);
				if(root == NULL)
					root = insert(root,eklenecek);
				else
					insert(root,eklenecek);
				break;
			case 2:
				if(root == NULL){
					printf("Bos\n");
					break;
				}
				printf("Silinecek Eleman [1,2,3...] : ");
				int silinecek;
				scanf("%d",&silinecek);
				root = deleteNode(root,silinecek);
				break;
			case 3:
				free(root);
				root = NULL;
				break;
			case 4:
				printf("Eleman Sayisi : %d\n",count(root));
				break;
			case 5:
				if(root == NULL){
					printf("Bos\n");
					break;
				}
				printf("InOrder >\n");
				inOrder(root);
				break;
			case 6:
				if(root == NULL){
					printf("Bos\n");
					break;
				}
				printf("PreOrder >\n");
				preOrder(root);
				break;
			case 7:
				if(root == NULL){
					printf("Bos\n");
					break;
				}
				printf("PostOrder >\n");
				postOrder(root);
				break;
			default:
				printf("Hatali bir secim yaptiniz\n");
				break;	
		}
		printf("\n\n");
	}

}
