
struct nod 
{ 
    int num; 
    struct nod *left; 
    struct nod *right; 
}; 

void end(struct nod** first, int num) { 
  
    if (*first == NULL) { 
        struct nod* newnod = new nod; 
        newnod->num = num; 
        newnod->left = newnod->right = newnod; 
        *first = newnod; 
        return; 
    } 

    nod *lsnod = (*first)->right; 

    struct nod* newnod = new nod; 
    newnod->num = num; 
    newnod->left = *first; 
    (*first)->right = newnod; 
    newnod->right = lsnod; 
    lsnod->left = newnod; 
} 
  

void beg(struct nod** first, int num) { 
    
    struct nod *lsnod = (*first)->right; 
  
    struct nod* newnod = new nod; 
    newnod->num = num;  
    newnod->left = *first; 
    newnod->right = lsnod; 
  
    lsnod->left = (*first)->right = newnod; 

    *first = newnod; 
} 
  

void aft(struct nod** first, int n1,int n2) { 
    struct nod* newnod = new nod; 
    newnod->num = n1;
    
    struct nod *temp = *first; 
    while (temp->num != n2) 
        temp = temp->left; 
    struct nod *left = temp->left; 
  
    temp->left = newnod; 
    newnod->right = temp; 
    newnod->left = left; 
    left->right = newnod; 
} 
  
  
void printPass(struct nod* first) 
{ 
    struct nod *temp = first; 
  
    printf("\n--------------------------\n"); 
    while (temp->left != first) 
    { 
        printf("|%d|<->", temp->num); 
        temp = temp->left; 
    } 
    printf("|%d|\n", temp->num); 
}  
