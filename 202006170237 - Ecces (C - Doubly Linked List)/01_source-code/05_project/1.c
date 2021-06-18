#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data; 
    struct node *left; 
    struct node *right; 
};
struct node* node_new(int data){
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    return p;
}
struct node* insert_node(struct node *root, int data){
    if(root==NULL)
        return node_new(data);
    else if(data < root->data)
        root->left = insert_node(root->left, data);
    else 
        root->right = insert_node(root->right,data);
    return root;
}
struct node* minimum(struct node *root){
    if(root == NULL)
        return NULL;
    else if(root->right != NULL)
        return minimum(root->right); 
    return root;
}
struct node* search_node(struct node *root, int data){
    if(root==NULL || root->data==data) 
        return root;
    else if(data < root->data) 
        return search_node(root->left, data);
    else 
        return search_node(root->right,data);
}
void printarr(int array[],int siz){
    printf("Numbers : ");
    int i;
    for(i=0; i<siz; i++){
        printf("%2d ",array[i]);
    }
    printf("\n");
}
struct node *addauto_node(struct node *root){
	int i, array[10];
	for(i=0; i<10; i++){
		array[i] = rand()%100+1;
	}
	printarr(array,10);
  	root = node_new(array[0]);

	for(i=1; i<10; i++){
		insert_node(root,array[i]);
	}
	return root;
}
void sort_node(struct node *root){
    if(root!=NULL){
        sort_node(root->left); 
        printf("%2d ", root->data);
        sort_node(root->right);
    }
}
struct node* delete_node(struct node *root, int data){
    if(root==NULL)
        return NULL;
    if (data < root->data)
        root->left = delete_node(root->left, data);
    else if(data > root->data)
        root->right = delete_node(root->right, data);
    else{
        if(root->right==NULL && root->left==NULL){
            free(root);
            return NULL;
        }
        else if(root->right==NULL || root->left==NULL){
            struct node *temp;
            if(root->right==NULL)
                temp = root->left;
            else
                temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = minimum(root->left);
            root->data = temp->data;
            root->left = delete_node(root->left, temp->data);
        }
    }
    return root;
}
int main(){
	srand(time(0));
	struct node *root = NULL;
	
	root = addauto_node(root);
	printf("\n");

	printf("Sort\t: ");
	sort_node(root);
	
	printf("\n\n");

    return 0;
}