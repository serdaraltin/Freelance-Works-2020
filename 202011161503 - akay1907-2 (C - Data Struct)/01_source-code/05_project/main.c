#include <stdio.h>
#include <stdlib.h>

#define AD "ad"
#define SOYAD "soyad"

#include <stdio.h>
 
struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* head2 = NULL;

struct node* pop(struct node *,int *);
struct node* push(struct node* ,int );
void display(struct node*);
int isEmpty(struct node*);

int islemler[100] = {0}, islemNo=0;

struct node *undo(struct node *head){
    int sayi;
    head2 = pop(head2,&sayi);
    printf("%d silinme islemi geri alindi\n",sayi);
    return push(head,sayi);
}

struct node* push(struct node* head,int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

struct node* pop(struct node *head,int *element)
{
    struct node* tmp = head;
    *element = head->data;
    head = head->next;
    free(tmp);
    return head;
}

int isEmpty(struct node* head)
{
    return head == NULL ? 1 : 0;
}

void display(struct node* head)
{
    struct node *current;
    current = head;
    if(current!= NULL)
    {
        printf("Ekrana yazdirildi= ");
        do
        {
            printf("%d ",current->data);
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
        return;
    }
    printf("Yiginda veri yok !\n");
}

void Menu();

int main(){
    printf("Hosgeldiniz %s %s\n\n",AD,SOYAD);
    Menu();
}

void Menu(){

    printf("1) EKLE\n");
    printf("2) SIL\n");
    printf("3) YAZDIR\n");
    printf("4) GERI AL\n");
    printf("0) CIKIS\n\n");
    printf("Secim : ");
    int secim;
    scanf("%d",&secim);
    int sayi;
    switch (secim)
    {
        case 0:
            printf("Programdan cikiliyor...\n");
            exit(0);
            break;
        
        case 1:
            printf("Eklenecek deger : ");
            scanf("%d",&sayi);
            head = push(head,sayi);
            printf("%d degeri eklendi\n",sayi);
            islemler[islemNo++] = 1;
            break;

        case 2:
            if(isEmpty(head))
                printf("Yigin bos !\n");
            else{
                head = pop(head,&sayi);
                printf("%d silindi.\n",sayi);
            }
            head2 = push(head2,sayi);
            islemler[islemNo++] = 2;
            break;

        case 3:
            display(head);
            break;
        
        case 4:
            if(islemler[islemNo-1] == 2){
                head = undo(head);
                islemNo--;
            }
            else if(islemler[islemNo-1] == 1)
            {
                head = pop(head,&sayi);
                printf("%d ekleme islemi geri alindi.\n",sayi);
                islemNo--;
            }
            else{
                printf("geri alinacak bir islem yok !\n");
            }
            break;
        default:
            printf("Hatali secim !\n");
            break;
    }
    printf("\n");
    Menu();
}