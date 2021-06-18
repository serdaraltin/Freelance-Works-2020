#include <stdio.h>
#include <stdlib.h>

//node(dugum) yapý tanýmlamasý
struct node{
	int data;
	struct node * left;
	struct node * right;
};

typedef struct node Node;

Node * tree = NULL;
//arama asamasinda kacinci adimda aranan valueuein bulundugunu tutacak degisken
int step = 0;

//fonksiyon prototipleri
Node *del(Node *,int);
int min(Node *);
int max(Node *);
int search(Node *,int);
void list(Node *);
Node * insert (Node *, int );
void menu();

//main fonksiuonu
int main()
{
	printf("Ogrenci No : 0001 \nOgrenci Ad : Irem\n");
	menu();
}
//menu
void menu(){
	printf("\n\n===============================\n");
	printf("1. Rastgele dugum uret\n");
	printf("2. Dugum ekle\n");
	printf("3. Listele\n");
	printf("4. Ara\n");
	printf("5. Sil\n");
	printf("0. Cikis");
	printf("\n===============================\n");
	
	int secim;
	printf("\nSeciniz > ");
	scanf("%d",&secim);
	
	//menu ogeleri icerisinde yapilan secim icin kosul blogu
	switch(secim){
		case 1:	//rastgele dugum uretme
			printf("\nRastgele ekleme icin adet giriniz > ");
			int adet;
			scanf("%d",&adet);
			int i,rastgele;
			srand(time(NULL));
			for(i = 0; i < adet; i++)
			{
				int rastgele = rand()%200;
				tree = insert(tree,rastgele);
				printf("\n>> %d valueuei eklendi.",rastgele);
			}
			printf("\n\n");
			list(tree);
			menu();
			break;
		case 2: //node(dugum) ekleme
			printf("\nEkleme icin valueue giriniz > ");
			int valueue;
			scanf("%d",&valueue);
			if(search(tree,valueue) != 1){
				tree = insert(tree,valueue);
				printf("\n>> %d valueuei eklendi.\n\n",valueue);
				list(tree);
		    }
		    else{
		    	printf("\n>> valueue zaten var!!!");
			}
			menu();
			break;
		case 3: //bagli liste(linklist) icerisindeki node(dugum) listeleme
			printf("\n");
			list(tree);
			menu();
			break;
		case 4: // node(dugum) arama islemi
			printf("\nArama icin valueue giriniz > ");
			int aranacak;
			scanf("%d",&aranacak);
			if(search(tree,aranacak) == 1){
				printf("\n>> Aranan %d valueuei %d. asamada bulundu.",aranacak,step);
			}
			else
				printf("\n>> Aranan %d valueuei bulunamadi!",aranacak);
			menu();
			break;
		case 5: //node(dugum) silme islemi
			printf("\nSilmek icin valueue giriniz > ");
			int silinecek;
			scanf("%d",&silinecek);
			
			if(search(tree,silinecek) == 1){
				tree = del(tree,silinecek);
				printf("\n>> %d valueuei silindi.\n\n",silinecek);
				list(tree);
			}
			else
				printf("\n>> Silinecek %d valueuei bulunamadi!",silinecek);
			menu();
			break;
		case 0: //cikis islemi
			exit(1);
			break;
		default: //beklenen disinda valueue girilmesi durumu
			printf("\nGecersiz bir valueue girdiniz !!!\n");
			menu();
			break;
	}
}

//yeni node(dugum) eklemek icin olusturulan fonksiyon
Node * insert (Node *tree, int x){
	if(tree == NULL){
		Node *root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->data = x;
		return root;
	}
	if(tree->data < x){
		tree->right = insert(tree->right,x);
		return tree;
	}
	tree->left = insert(tree->left,x);
	return tree;
}

//olusturulmus olan node leri(dugum) listelemek icin olusturulan fonksyion
void list(Node *tree){
	if(tree == NULL)
		return;
	list(tree->left);
	printf("%d -> ",tree->data);
	list(tree->right);
}

//arama islemi fonksiyonu
int search(Node *tree,int aranan){
	++step;
	if(tree == NULL){
		return -1; step = 0;
	}
	if(tree->data == aranan)
			return 1; 
	if(search(tree->right,aranan) == 1)
		return 1; 
	if(search(tree->left,aranan) == 1)
			return 1;
	step = 0;
	return -1;
}

//bagli liste(linklist) icerisindeki minumum valueuei bulmak icin fonksiyon
int min(Node *tree){
	while(tree->left != NULL)
		tree = tree->left;
	
	return tree->data;
}

//bagli liste(linklist) icerisindeki maximum valueuei bulmak icin fonksiyon
int max(Node *tree){
	while(tree->right != NULL)
		tree = tree->right;
		
	return tree->data;
}

//bagli liste(linklist) icerisinden node(dugum) silme fonksiyonu
Node *del(Node *tree,int x){
	if(tree == NULL)
		return NULL;
	if(tree->data == x){
		if(tree->left == NULL && tree->right == NULL)
			return NULL;
		if(tree->right != NULL){
			tree->data = min(tree->right);
			tree->right = del(tree->right,min(tree->right));
			return tree;
		}
		tree->data = max(tree->left);
		tree->left = del(tree->left,max(tree->left));
		return tree;
	}
	if(tree->data < x){
		tree->right = del(tree->right,x);
		return tree;
	}
	tree->left = del(tree->left,x);
	return tree;
}
