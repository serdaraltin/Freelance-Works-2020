
void ListPrint(struct Node* start){
	struct Node *temp = start; 
  
    printf("Sifre: "); 
    while (temp->next != start) 
    { 

        printf("%c", temp->data); 
        temp = temp->next; 
    } 
    printf("%c\n", temp->data); 
} 
