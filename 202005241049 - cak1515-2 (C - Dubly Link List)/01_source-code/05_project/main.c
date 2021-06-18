#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DLINKED_LIST_NODE_s *DLINKED_LIST_NODE;

typedef struct DLINKED_LIST_NODE_s{
	DLINKED_LIST_NODE next;
	DLINKED_LIST_NODE prev;
	void *data;
} DLINKED_LIST_NODE_t[1];


typedef struct DLINKED_LIST_s *DLINKED_LIST;

typedef struct DLINKED_LIST_s{
	DLINKED_LIST_NODE head;
} DLINKED_LIST_t[1];

DLINKED_LIST dlinked_list_init();
void dlinked_list_free(DLINKED_LIST list);
void dlinked_list_prepend(DLINKED_LIST list, void *data);
void dlinked_list_append(DLINKED_LIST list, void *data);
void dlinked_list_insert(DLINKED_LIST list, void *data, int idx);
void dlinked_list_set(DLINKED_LIST list, void *data, int idx);
void *dlinked_list_get(DLINKED_LIST list, int idx);
void *dlinked_list_remove(DLINKED_LIST list, int idx);
void dlinked_list_removeall(DLINKED_LIST list);
int countList(DLINKED_LIST_NODE start);
void Menu();

DLINKED_LIST list = NULL;

int main(){
	Menu();
} 
void Menu(){
	printf("1) Init\n");
	printf("2) Free\n");
	printf("3) Prepend\n");
	printf("4) Append\n");
	printf("5) Insert\n");
	printf("6) Set\n");
	printf("7) Get\n");
	printf("8) Remove\n");
	printf("9) RemoveAll\n");
	printf("0) Exit\n");
	
	printf("Choice : ");
	int ch;
	scanf("%d",&ch);

	void *data;
	int idx;
	switch(ch){
		case 0:
			exit(0);
			break;
		case 1:
			list = dlinked_list_init();
			break;
		case 2:
			dlinked_list_free(list);
			break;
		case 3:
			printf("Data : ");
			scanf("%d",(int*)data);
			dlinked_list_prepend(list,data);
			break;
		case 4:
			printf("Data : ");
			scanf("%d",(int*)data);
			dlinked_list_append(list,data);
			break;
		case 5:
			printf("Data : ");
			scanf("%d",(int*)data);
			printf("idx : ");
			scanf("%d",&idx);
			dlinked_list_insert(list,data,idx);
			break;
		case 6:
			printf("Data : ");
			scanf("%d",(int*)data);
			printf("idx : ");
			scanf("%d",&idx);
			dlinked_list_set(list,data,idx);
			break;
		case 7:
			printf("idx : ");
			scanf("%d",&idx);
			dlinked_list_get(list,idx);
			break;
		case 8:
			printf("idx : ");
			scanf("%d",&idx);
			dlinked_list_remove(list,idx);
			break;
		case 9:
			dlinked_list_removeall(list);
			break;

	}
	Menu();
}

DLINKED_LIST dlinked_list_init(){
	DLINKED_LIST list = (DLINKED_LIST)malloc(sizeof(struct DLINKED_LIST_s));
	return list;
}

void dlinked_list_free(DLINKED_LIST list){
	free(list);
	return;
}

void dlinked_list_prepend(DLINKED_LIST list, void *data){
	list->head->data = data;
	list->head->next = NULL;
	list->head->prev = NULL;
	return;
}

void dlinked_list_append(DLINKED_LIST list, void *data){
	DLINKED_LIST_NODE new_node = (DLINKED_LIST_NODE)malloc(sizeof(struct DLINKED_LIST_NODE_s));
	
	DLINKED_LIST_NODE last = list->head;

	new_node->data = data;

	new_node->next = NULL;

	if(list->head == NULL){
		new_node->prev = NULL;
		list->head = new_node;
		return;
	}

	while(last->next != NULL){
		last = last->next;
	}

	last->next = new_node;
	new_node->prev = last;
	
	return;
}

void dlinked_list_insert(DLINKED_LIST list, void *data, int idx){
	DLINKED_LIST_NODE temp, newNode;
	int i, count;

	newNode = (DLINKED_LIST_NODE)malloc(sizeof(struct DLINKED_LIST_NODE_s));

	temp = list->head;

	count = countList(list->head);

	if(temp == NULL || count < idx)
		return;
	else{
		newNode->data = data;

		for(i=1; i<idx-1; i++){
			temp = temp->next;
		}

		newNode->next = temp->next;

		(temp->next)->prev = newNode;

		temp->next = newNode;

		newNode->prev = temp;
		return;
	}
	return;
}

void dlinked_list_set(DLINKED_LIST list, void *data, int idx){
	DLINKED_LIST_NODE temp;
	int i, count;

	temp = list->head;

	count = countList(list->head);

	if(temp == NULL || count < idx)
		return;
	else{
		for(i=1; i<idx; i++){
			temp = temp->next;
		}
		temp->data = data;
	}
	return;
}

void *dlinked_list_get(DLINKED_LIST list, int idx){
	DLINKED_LIST_NODE temp;
	int i, count;
	temp = list->head;
	count = countList(list->head);
	if(temp == NULL || count < idx)
		return NULL;
	else{
		for(i=1; i<idx; i++){
			temp = temp->next;
		}
		return temp;
	}
	return NULL;
}

void *dlinked_list_remove(DLINKED_LIST list, int idx){
	DLINKED_LIST_NODE temp;
	int i, count;
	temp = list->head;
	count = countList(list->head);

	if(temp == NULL || count < idx)
		return NULL;
	else{
		for(i=1; i<idx; i++){
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
		return list;
	}
	return NULL;
}

void dlinked_list_removeall(DLINKED_LIST list){
	DLINKED_LIST_NODE temp;
	int i, count;
	temp = list->head;
	count = countList(list->head);

	while(temp != NULL){
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
	return;
}

int countList(DLINKED_LIST_NODE start) { 
    DLINKED_LIST_NODE temp = start; 

    int count = 0; 
 
    while (temp->next != start) { 
        temp = temp->next; 
        count++; 
    } 

    count++; 
  
    return count; 
} 