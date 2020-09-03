
struct Node 
{ 
    int data; 
    struct Node *next; 
    struct Node *prev; 
}; 

void insertEnd(struct Node** start, int value) { 
  
    if (*start == NULL) { 
        struct Node* new_node = new Node; 
        new_node->data = value; 
        new_node->next = new_node->prev = new_node; 
        *start = new_node; 
        return; 
    } 

    Node *last = (*start)->prev; 

    struct Node* new_node = new Node; 
    new_node->data = value; 
    new_node->next = *start; 
    (*start)->prev = new_node; 
    new_node->prev = last; 
    last->next = new_node; 
} 
  

void insertBegin(struct Node** start, int value) { 
    
    struct Node *last = (*start)->prev; 
  
    struct Node* new_node = new Node; 
    new_node->data = value;  
    new_node->next = *start; 
    new_node->prev = last; 
  
    last->next = (*start)->prev = new_node; 

    *start = new_node; 
} 
  

void insertAfter(struct Node** start, int value1,int value2) { 
    struct Node* new_node = new Node; 
    new_node->data = value1;
    
    struct Node *temp = *start; 
    while (temp->data != value2) 
        temp = temp->next; 
    struct Node *next = temp->next; 
  
    temp->next = new_node; 
    new_node->prev = temp; 
    new_node->next = next; 
    next->prev = new_node; 
} 
  
  
void display(struct Node* start) 
{ 
    struct Node *temp = start; 
  
    printf("\n--------------------------\n"); 
    while (temp->next != start) 
    { 
        printf("|%d|<->", temp->data); 
        temp = temp->next; 
    } 
    printf("|%d|\n", temp->data); 
}  
