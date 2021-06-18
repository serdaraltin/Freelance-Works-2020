#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	char name[20];
	char surname[20];
	struct node *next;
}Node;


void fileRead();
void menu();
void sort(Node **root);


Node *root = NULL;

Node *newNode(int data, char *name, char *surname)
{
	Node *newNode = (Node *)malloc(sizeof( Node));

	newNode->data = data;
	strcpy(newNode->name, name);
	strcpy(newNode->surname, surname);

	newNode->next = NULL;

	return newNode;
}

int lastDigit(int num)
{
	return num % 10;
}

int count(Node *num)
{
	Node *current = root;
	int count = 1;
	while (current != NULL)
	{
		if (lastDigit(current->data) == lastDigit(num->data))
			count++;
		current = current->next;
	}
	return count;
}

void printList()
{
	Node *temp = root;
	while (temp != NULL)
	{
		printf("%d-%s-%s\n", temp->data, temp->name, temp->surname);
		temp = temp->next;
	}
	printf("\n");
}

void delete(int num)
{
	Node *temp = root, *prev;

	if (temp != NULL && temp->data == num)
	{
		root = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != num)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return;

	prev->next = temp->next;

	free(temp);
	sort(&root);
}



void search(int num){
	Node *temp = root;
	int step = 1;
	while(temp != NULL){
		if(temp->data == num){
			printf("Aranan deger %d adimda bulundu.\n",step);
			printf("Sonuc: %d-%s-%s\n", temp->data, temp->name, temp->surname);
			return;
		}
		step++;
		temp = temp->next;
	}
	printf("Aranan deger bulunamadi (%d)\n",num);
}

Node* swap(Node *a, Node *b) { 
  Node *tmp = b->next;
  b->next = a;
  a->next = tmp;
  return b;
} 

void sort(Node **root) {
  int fMap[10] = { 0 };

	Node *currentNode = *root;
	int nodeCount = 0;
	while (currentNode != NULL) {
		fMap[currentNode->data % 10]++;
		currentNode = currentNode->next;
		nodeCount++;
	}

	int swapControl = 1;
	Node **h;

	for (int i = 0; i <= nodeCount && swapControl; i++) {
		h = root;
		swapControl = 0;
		for (int j = 0; j < nodeCount - i - 1; j++) {
			Node *p1 = *h;
			Node *p2 = p1->next;

			if (fMap[p1->data % 10] < fMap[p2->data % 10]) {
				*h = swap(p1, p2);
				swapControl = 1;
			}

			h = &(*h)->next;
		}
	}
}

void insert(Node *newNode){
	if (root == NULL)
	{
		root = newNode;
		return;
	}

	Node *temp = root;

	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	sort(&root);
	return;
}

int main(){
	fileRead();
	menu();
	return 0;
}

void fileRead()
{
	FILE *file;
	file = fopen("veri.txt","r");

	while(!feof(file)){
		int no;
		char *ad = (char*)malloc(sizeof(char)*20);
		char *soyad = (char*)malloc(sizeof(char)*20);

		fscanf(file,"%d %s %s\n",&no,ad,soyad);

		insert(newNode(no,ad,soyad));
	}
	fclose(file);
}

void fileWrite(){
	FILE *file;
	file = fopen("veri.txt","w");

	Node *iter = root;
	while(iter != NULL){
		fprintf(file, "%d %s %s\n",iter->data,iter->name,iter->surname);
		iter = iter->next;
	}
	fclose(file);
}

void menu()
{

	printf("1) Ekleme Islemi\n");
	printf("2) Arama Islemi\n");
	printf("3) Listeleme Islemi\n");
	printf("4) Silme Islemi\n");
	printf("5) Cikis Islemi\n");
	int secim;

	printf("\nSeciminiz: ");
	scanf("%d", &secim);
	printf("\n");
	switch (secim)
	{
		case 1:
			printf("Eklenecek deger > \n");
			printf("No: ");
			int no;
			scanf("%d",&no);
			printf("Ad: ");
			char ad[20];
			scanf("%s",ad);
			printf("Soyad: ");
			char soyad[20];
			scanf("%s",soyad);
			insert(newNode(no,ad, soyad));
			break;
		case 2:
			printf("Aranacak deger: ");
			int searchNum;
			scanf("%d",&searchNum);
			search(searchNum);
			break;
		case 3:
			printList();
			break;
		case 4:
			printf("Silinecek deger: ");
			int delNum;
			scanf("%d",&delNum);
			delete(delNum);
			break;
		case 5:
			printf("Programdan cikiliyor...\n");
			fileWrite();
			exit(0);
			break;
		default:
			printf("Hatali secim !\n");
			break;
	}
	printf("\n");
	menu();
}
