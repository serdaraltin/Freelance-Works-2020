#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 50

struct item
{
	char explanation[50];
	int status;
};
typedef item item;

struct shopping_list
{
	char listName[SIZE];
	struct item items[20];
	int itemCount;
};

typedef shopping_list Shopping_Lists;

Shopping_Lists spList[SIZE];
int spListCount = 0;

void MainMenu();
void CreateNewList();
void ShowShoppingLists();
int  CheckListName(char listName[]);

void ShoppingListMenu(int listNo);
void PrintList(int listNo);
void AddItem(int listNo);
void EditItem(int listNo,int itemNo);
void DeleteItem(int listNo,int itemNo);
void Mark(int listNo,int itemNo);


int main(){
	MainMenu();
} 

void MainMenu(){
	printf("1. Create new List\n");
	printf("2. Show shopping Lists\n");
	printf("\nChoice : ");
	int cho;
	scanf("%d",&cho);
	printf("\n");
	switch(cho){
		case 1:
			CreateNewList();
			break;
		case 2:
			ShowShoppingLists();
			break;
		default:
			printf("Try again\n");
			break;
	}
	printf("\n");
	MainMenu();
}

void CreateNewList(){
	if(spListCount == SIZE){
		printf("Maximum list reached !!!\n");
		return;
	}
	printf("List Name : ");
	char listName[SIZE];
	scanf("%s",listName);
	if(CheckListName(listName) == 1){
		printf("%s already have. Try again!\n",listName );
		CreateNewList();
		return;
	}
	strcpy(spList[spListCount].listName,listName);
	spList[spListCount++].itemCount = 0;
	return;
}

int CheckListName(char listName[]){
	int i;
	for(i=0; i<SIZE; i++)
		if(strcmp(spList[i].listName,listName) == 0)
			return 1;
	return -1;
}

void ShowShoppingLists(){
	if(spListCount == 0){
		printf("No list!!!\n");
		return;
	}
	printf("No\tShopping List Name\n");
	printf("-------------------------------------\n");
	int i;
	for (i = 0; i < SIZE; i++)
		if(strcmp(spList[i].listName,"") != 0)
			printf("%d\t%s\n",i,spList[i].listName);

	printf("\nChoice : ");
	int cho;
	scanf("%d",&cho);
	if(cho >= 0 && cho <= 50){
		ShoppingListMenu(cho);
		return;
	}
	printf("Incorrect entry!!!\n");
	ShowShoppingLists();
	return;
}

void ShoppingListMenu(int listNo){
	printf("\n");
	printf("---> %s <---\n--> %d items\n\n",spList[listNo].listName,spList[listNo].itemCount);
	printf("1. Add Item\n");
	printf("2. Edit Item\n");
	printf("3. Delete Item\n");
	printf("4. Mark as Done Undone\n");
	printf("5. Items\n");
	printf("6. Main Menu\n");
	printf("\nChoice : ");
	int cho;
	scanf("%d",&cho);
	printf("\n");
	switch(cho){
		case 1:
			AddItem(listNo);
			break;
		case 2:
			PrintList(listNo);
			printf("\nChoice : ");
			int editNo;
			scanf("%d",&editNo);
			if(!(editNo >=0 && editNo <= 20)){
				printf("Incorrect entry\n"); 
				ShoppingListMenu(listNo);
				return;
			}
			
			printf("\n");
			EditItem(listNo,editNo);
			break;
		case 3:
			PrintList(listNo);
			printf("\nChoice : ");
			int delNo;
			scanf("%d",&delNo);
			if(!(delNo >=0 && delNo <= 20)){
				printf("Incorrect entry\n"); 
				ShoppingListMenu(listNo);
				return;
			}
			
			printf("\n");
			DeleteItem(listNo,delNo);
			break;
		case 4:
			PrintList(listNo);
			printf("\nChoice : ");
			int markNo;
			scanf("%d",&markNo);
			if(!(markNo >=0 && markNo <= 20)){
				printf("Incorrect entry\n"); 
				ShoppingListMenu(listNo);
				return;
			}
		
			printf("\n");
			Mark(listNo,markNo);
			break;
		case 5:
			PrintList(listNo);
			break;
		case 6:
			MainMenu();
			break;
		default:
			printf("Try again\n");
			break;
	}
	ShoppingListMenu(listNo);
}

void PrintList(int listNo){
	printf("No\tStatus\tEvent\n");
	printf("-------------------------------------------\n");
	int i;
	for (i = 0; i < 20; ++i){
		if(strcmp(spList[listNo].items[i].explanation,"") != 0){
			printf("%d\t",i);
			if(spList[listNo].items[i].status == 1)
				printf("OK\t");
			else
				printf("--\t");
			printf("%s\n",spList[listNo].items[i].explanation);
		}
	}
}
void AddItem(int listNo){
	if(spList[listNo].itemCount == 20){
		printf("Maximum list reached !!!\n");
		return;
	}
	int count = spList[listNo].itemCount;
	printf("Explanation : ");
	char explanation[50];
	scanf("%s",explanation);
	strcpy(spList[listNo].items[count].explanation,explanation);
	spList[listNo].items[count].status = 0;
	spList[listNo].itemCount++;
	return;
}
void EditItem(int listNo,int itemNo){
	if(strcmp(spList[listNo].items[itemNo].explanation,"") == 0){
		printf("Empty\n");
		return;
	}
	printf("Explanation : ");
	char explanation[50];
	scanf("%s",explanation);
	sprintf(spList[listNo].items[itemNo].explanation,"%s",explanation);
}
void DeleteItem(int listNo,int itemNo){
	sprintf(spList[listNo].items[itemNo].explanation,"%s","Deleted");
	spList[listNo].items[itemNo].status = 0;
}
void Mark(int listNo,int itemNo){
	printf("Mark [OK=1 / NO=0] : ");
	int status;
	scanf("%d",&status);
	spList[listNo].items[itemNo].status = status;
}