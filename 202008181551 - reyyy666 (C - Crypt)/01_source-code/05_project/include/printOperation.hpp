
void printDLs(struct nod* first){
	struct nod *temp = first; 
  
    printf("Sifre: "); 
    while (temp->left != first) 
    { 

        printf("%c", temp->num); 
        temp = temp->left; 
    } 
    printf("%c\n", temp->num); 
} 
