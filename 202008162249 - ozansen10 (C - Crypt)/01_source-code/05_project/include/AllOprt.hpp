#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

//dairesel liste için yapı
struct node { 
    int data; 
    struct node *next; 
    struct node *prev; 
}; 
typedef node * Node;


//en büyük ortak bölenin hesaplanması
int Gcd(int val1, int val2){
	while(val1 != val2){
		if(val1 > val2)
			val1 -= val2;
		else
			val2 -= val1;
	}
	return val1;
}
//parametre olarak gelen ilk sayi değerinin son sayi değerinin ardına eklenlenmesi
void InsertAfter(struct node** begin, int val1,int val2) { 
    struct node* newnode = new node; 
    newnode->data = val1;
    
    struct node *temp = *begin; 
    while (temp->data != val2) 
        temp = temp->next; 
    struct node *next = temp->next; 
  
    temp->next = newnode; 
    newnode->prev = temp; 
    newnode->next = next; 
    next->prev = newnode; 
} 
//parametre olarak gelen değerin listenin sonuna eklenmesi
void InsertEnd(struct node** begin, int value) { 
  
    if (*begin == NULL) { 
        struct node* newnode = new node; 
        newnode->data = value; 
        newnode->next = newnode->prev = newnode; 
        *begin = newnode; 
        return; 
    } 

    node *last = (*begin)->prev; 

    struct node* newnode = new node; 
    newnode->data = value; 
    newnode->next = *begin; 
    (*begin)->prev = newnode; 
    newnode->prev = last; 
    last->next = newnode; 
} 
//o anki listedeki sayıların harf karşılıklarının yazdırılması
void PrintCryptText(struct node* begin){
	struct node *temp = begin; 
  
    cout << "Sifre: "; 
    while (temp->next != begin) { 
        cout << (char)temp->data; 
        temp = temp->next; 
    } 
    cout << (char)temp->data << endl; 
}

//parametre olarak gelen değerin listenin başına eklenmesi
void InsertBegin(struct node** begin, int value) { 
    struct node *last = (*begin)->prev; 
    struct node* newnode = new node; 
    newnode->data = value;  
    newnode->next = *begin; 
    newnode->prev = last; 
  
    last->next = (*begin)->prev = newnode; 

    *begin = newnode; 
} 

//parametre olarak gelen file adındaki verilerin okunması ve ilgili işlemlerin yapılması
void InputFileRead(){
	//file pointeri oluşturulması
	FILE* file;
	//her bir satır için belirlenen maximum len
	int len = 5000;
	char bf[len];
	//dosyanın okuma modunda açılması
	file = fopen("Sayilar.txt", "r");

	while(fgets(bf, len, file)) {//o anki satırın okunması ve bf dizisine aktarılması, satır boş olmadığı sürece döngü devam eder
		int *numArray = (int*)malloc(sizeof(int)*512);
		
		//belirlenen " "(space) karakteri ile satırdaki sayıların ayrıştırılması için atama işlemi
		char delimiter[2] = " ";

		//strtok fonksiyonu ile o anki satırdaki sayılar döngüsel olarak ayrılıp bir diziye atanıyor
		char *token;
		token = strtok(bf,delimiter);

		int i = 0;
		//o anki satırın değerini tutan değişkende data var olduğu sürece dönen döngü
		while(token != NULL){
			numArray[i++] = atoi(token);
			token = strtok(NULL,delimiter);
		}

		int ebob = 0;
		//yeni bir düğüm oluşturulması
		struct node* begin = NULL;

	    int j;
	   	//0 dan başlanıp sayı adedi kadar dönen bir döngü
	    for(j=0; j<i; j++){

	    	//begin adım ise sayı listenin başına eklenmesi
	    	if(j==0){
	    		InsertEnd(&begin, numArray[0]); 
				continue;
	    	}
	    	//o anki sayı ile başlangıç değerindeki sayının ebobunun daha önceki en büyük ebob degerinden daha büyük olması
	    	if(ebob < Gcd(begin->data,numArray[j])){
	    		
	    		ebob = Gcd(begin->data,numArray[j]);

	    		//ilgili mod alma işlemlerinin yapılması
	    		int modResu;
	    		if(numArray[j] > begin->data)
	    			modResu = numArray[j] % begin->data;
	    		else
	    			modResu = begin->data % numArray[j];
	    		
	    		//mod sonucu kalansız ise
	    		if(modResu == 0){
	    			InsertAfter(&begin,numArray[j],begin->data);
	    			continue;
	    		}
	    		//mod sonucu 0 dan faklı ise
	    		else{
	    			int i=0;
	    			struct node *temp = begin;
	    			while(i++<modResu)
	    				temp = temp->prev;
	    			if(temp == begin){
	    				InsertBegin(&begin,numArray[j]);
	    				continue;
	    			}
	    		}
	    	}
	    	//o anki sayı ve başlangıç sayısının ebobu, en buyuk ebob değerinden küçük ise
	    	else{
	    		//temp bir düğüm oluşturulup başlangıcı gösterecek şekilde ayarlanması
	    		struct node *temp = begin;
	    		//temp düğümün o anki değeri ile dizinin o anki elemanının ebob değeri en büyük ebob değerinden küçük olduğu ve listenin tek elemanlı olmadığı sürece dönen döngü
	    		while(Gcd(temp->data,numArray[j]) < ebob && temp->next != begin){
	    			
	    			temp = temp->next;
	    		}

	    		//ilgili mod alma işlemleri
	    		int modResu;
	    		if(numArray[j] > temp->data)
	    			modResu = numArray[j] % temp->data;
	    		else
	    			modResu = temp->data % numArray[j];
	    		
	    		//döngü için "i" değişkeni ve kontrol için bayrak görevi gören "flag" değişkeni
	    		int i=0,flag=0;
	    		//i değeri mod alma sonucundan küçük olduğu sürece dönen döngü
	    		while(i++<modResu){
	    			//temp eşit ise başlanguca bayrak kaldırılır ve dizinin o anki değeri başa eklenir
	    			if(temp == begin){
	    				flag =1;
	    				InsertBegin(&begin,numArray[j]);
	    				break;
	    			}

	    			temp = temp->prev;
	    		}
	    		//bayrak kalmamış ise dizinin o anki elemanı temp göstericisinin ardına eklenir
	    		if(flag==0)
	    			InsertAfter(&temp,numArray[j],temp->data);
	    	}
	    }
	    //o anki satırdaki hesaplamalar yapıldıktan sonra sonuç yazdırılır
	    PrintCryptText(begin);
	    //bellek boşaltılır
	    free(begin);
	}
	//file kapatılır
	fclose(file);
}
