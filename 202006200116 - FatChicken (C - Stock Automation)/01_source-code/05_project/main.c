#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer{
	int no;
	char name[30];
	char lastname[30];
	char phone[13];
	char address[300];
	float balance;
	struct customer *next;
};
typedef struct customer Customer;

struct product{
	char code[20];
	char name[50];
	float price;
	int stock;
	struct product *next;
};
typedef struct product Product;

struct order{
	int order_no;
	int customer_no;
	char product_code[20];
	int product_piece;
	float amount;
	char date[20];
	struct order *next;
};
typedef struct order Order;

Customer *Customers = NULL;
Product *Products = NULL;
Order *Orders = NULL;

void MainMenu();
void CustomerMenu();
void ProductMenu();
void OrderMenu();
void FileMenu();

void CustomerAdd();
Customer *NewCustomer(int no,char name[30],char lastname[30],char phone[13],char address[300],float balance);
void CustomersList();
void PrintCustomer(Customer *customer);
void CustomerSearch();
void CustomerSearchString(char metin[]);
Customer *CustomerSearchCode(int no);
void CustomerUpdate();
void CustomerBakiyeAdd();

void ProductAdd();
Product *NewProduct(char code[20],char name[50],float price,int stock);
void ProductSearch();
Product *ProductSearchCode();
void ProductSearchName();
void ProductUpdate();
void ProductsList();

void OrderCreate();
Order *NewOrder(int order_no,int customer_no,char product_code[20],int product_piece,float amount,char date[20]);
Order *OrderSearch(int order_no);
void OrderView();
void OrdersList();

void DatFileWrite(char islem[],char veri[]);
void InvoiceWrite();

void FileWriteCustomer();
void FileWriteProduct();
void FileWriteOrder();

void FileReadCustomer();
void FileReadProduct();
void FileReadOrder();

int main(){
	FileReadCustomer();
    FileReadProduct();
    FileReadOrder();
	MainMenu();
}

void MainMenu(){
	printf("\n");
	printf("1) Musteri Menu\n");
	printf("2) Urun Menu\n");
	printf("3) Siparis Menu\n");
	printf("4) Dosya Menu\n");
	printf("0) Cikis\n");
	printf("\nSec : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 0:
			printf("Cikiliyor...\n");
			exit(0);
			break;
		case 1:
			CustomerMenu();
			break;
		case 2:
			ProductMenu();
			break;
		case 3:
			OrderMenu();
			break;
		case 4:
			FileMenu();
			break;
		default:
			printf("Hatali secim.\n");
			break;
	}
	MainMenu();
}

void CustomerMenu(){
	printf("\n");
	printf("1) Musteri Ekle\n");
	printf("2) Musteri Guncelle\n");
	printf("3) Musteri Bul\n");
	printf("4) Musteri Bakiye Ekle\n");
	printf("5) Musterileri Listele\n");
	printf("0) Ana Menuye Geri Don");
	printf("\nSec : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 0:
			MainMenu(); //+
			break;
		case 1:
			CustomerAdd(); //+
			break;
		case 2:
			CustomerUpdate(); //+
			break;
		case 3:
			CustomerSearch(); //+
			break;
		case 4:
			CustomerBakiyeAdd(); //+
			break;
		case 5:
			CustomersList(); //+
			break;
		default:
			printf("Hatali secim.\n");
			break;
	}
	printf("\n");
	CustomerMenu();
}

void ProductMenu(){
	printf("\n");
	printf("1) Urun Ekle\n");
	printf("2) Urun Guncelle\n");
	printf("3) Urun Bul\n");
	printf("4) Urunleri Listele\n");
	printf("0) Ana Menuye Geri Don");
		printf("\nSec : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 0:
			MainMenu(); //+
			break;
		case 1:
			ProductAdd(); //+
			break;
		case 2:
			ProductUpdate(); //+
			break;
		case 3:
			ProductSearch(); //+
			break;
		case 4:
			ProductsList(); //+
			break;
		default:
			printf("Hatali secim.\n");
			break;
	}
	ProductMenu();
}

void OrderMenu(){
	printf("\n");
	printf("1) Siparis Ekle\n");
	printf("2) Siparis Goruntule\n");
	printf("3) Siparisleri Listele\n");
	printf("0) Ana Menuye Geri Don");
	printf("\nSec : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 0:
			MainMenu();
			break;
		case 1:
			OrderCreate();
			break;
		case 2:
			OrderView();
			break;
		case 3:
			OrdersList();
			break;
		default:
			printf("Hatali secim.\n");
			break;
	}
	OrderMenu();
}

void FileMenu(){
	printf("\n");
	printf("1) Fatura Bastir\n");
	printf("2) Ana Menuye Geri Don");
	printf("\nSec : ");
	int secim;
	scanf("%d",&secim);

	switch(secim){
		case 2:
			MainMenu(); //+
			break;
		case 1:
			InvoiceWrite(); //+
			break;
		default:
			printf("Hatali secim.\n");
			break;
	}
	FileMenu();
}

void CustomerAdd(){
	int no;
	char name[30];
	char lastname[30];
	char phone[13];
	char address[300];
	float balance;

	printf("No : ");
	scanf("%d",&no);
	printf("Isim : ");
	scanf("%s",name);
	printf("Soyisim : ");
	scanf("%s",lastname);
	printf("Tel No : ");
	scanf("%s",phone);
	printf("Sehir : ");
	scanf("%s",address);
	printf("Bakiye : ");
	scanf("%f",&balance);

	if(Customers == NULL){
		Customers = NewCustomer(no,name,lastname,phone,address,balance);
		printf("\nCustomer Eklendi.\n");
		return;
	}
	Customer *iter = Customers;

	while(iter->next != NULL)
		iter = iter->next;

	iter->next = NewCustomer(no,name,lastname,phone,address,balance);
	FileWriteCustomer();
	printf("\nCustomer Eklendi.\n");
	return;
}

void CustomersList(){
	printf("-------- Customer LISTESI --------- \n");
	Customer *iter = Customers;

	while(iter != NULL){
		PrintCustomer(iter);
		iter = iter->next;
    }
    char veri[500];
	sprintf(veri,"Tum Customers");
	DatFileWrite("Customers Listelendi",veri);

}
void CustomerSearch(){
	printf("Bul [Isim : 1 / No : 2] : ");
	int secim;
	scanf("%d",&secim);
	if(secim == 1){
		printf("Isim : ");
		char name[30];
		scanf("%s",name);
		CustomerSearchString(name);
	}
	else if(secim == 2){
		printf("No : ");
		int no;
		scanf("%d",&no);
		PrintCustomer(CustomerSearchCode(no));
	}
	else{
		printf("Hatali secim..\n"); 
		CustomerSearch();
	}
}
void PrintCustomer(Customer *customer){
	if(customer == NULL){
		return;
	}
	printf("\n-----------------------------------\n");
	printf("No\t: %d\n",customer->no);
	printf("Isim\t: %s\n",customer->name);
	printf("Soyisim\t: %s\n",customer->lastname);
	printf("Tel No\t: %s\n",customer->phone);
	printf("Sehir\t: %s\n",customer->address);
	printf("Bakiye\t: %.2f TL\n",customer->balance);
	printf("-----------------------------------\n");

    char veri[500];
	sprintf(veri,"Customer No : %d",customer->no);
	DatFileWrite("Customer Yazdir",veri);

}

Customer *CustomerSearchCode(int no){
	Customer *iter = Customers;

	while(iter != NULL){
		if(iter->no == no)
			return iter;
		iter = iter->next;
	}
	return NULL;
}

Customer *NewCustomer(int no,char name[30],char lastname[30],char phone[13],char address[300],float balance){

	Customer *newCustomer = (Customer*)malloc(sizeof(Customer));
	newCustomer->no = no;
	strcpy(newCustomer->name,name);
	strcpy(newCustomer->lastname,lastname);
	strcpy(newCustomer->phone,phone);
	strcpy(newCustomer->address,address);
	newCustomer->balance = balance;
	newCustomer->next = NULL;
	
	char veri[500];
	sprintf(veri,"No\t\t: %d\nIsim\t\t: %s\nSoyisim\t: %s\nTel No\t: %s\nSehir\t: %s\nBakiye\t: %.2f",
		no,name,lastname,phone,address,balance);
	DatFileWrite("Customer Eklendi",veri);

	return newCustomer;
}

void CustomerSearchString(char metin[]){
	Customer *iter = Customers;
	int bulundu = 0;
	while(iter != NULL){
		if(strcmp(iter->name,metin) >= 0){
			PrintCustomer(iter);
			bulundu = 1;
		}
		iter = iter->next;
	}
	if(bulundu == 0)
		printf("\nBulunamadi\n");
}
void ProductAdd(){
	char code[20];
	char name[50];
	float price;
	int stock;

	printf("Kod : ");
	scanf("%s",code);
	printf("Isim : ");
	scanf("%s",name);
	printf("Fiyat : ");
	scanf("%f",&price);
	printf("Stok : ");
	scanf("%d",&stock);

	if(Products == NULL){
		Products = NewProduct(code,name,price,stock);
		printf("\nProduct Eklendi\n");
		return;
	}

	Product *iter = Products;

	while(iter->next != NULL)
		iter = iter->next;

	iter->next = NewProduct(code,name,price,stock);

	FileWriteProduct();
	printf("\nProduct Eklendi.\n");
	return;
}
void CustomerUpdate(){
	printf("Customer No : ");
	int no;
	scanf("%d",&no);
	if(CustomerSearchCode(no) == NULL)
		return;
	printf("Tel No : ");
	char phone[13];
	scanf("%s",phone);
	printf("Sehir: ");
	char address[300];
	scanf("%s",address);

	Customer *iter = Customers;
	while(iter != NULL){
		if(iter->no == no)
			break;
		iter = iter->next;
	}
	sprintf(iter->phone,"%s",phone);
	sprintf(iter->address,"%s",address);
	FileWriteCustomer();
	printf("\nCustomer Guncellendi..\n");
	CustomerSearchCode(no);
}

void CustomerBakiyeAdd(){
	printf("Customer No : ");
	int no;
	scanf("%d",&no);
	if(CustomerSearchCode(no) == NULL)
		return;
	printf("Bakiye : ");
	float ekBakiye;
	scanf("%f",&ekBakiye);

	CustomerSearchCode(no)->balance += ekBakiye;
	printf("New Bakiye >> %.2f TL\n",CustomerSearchCode(no)->balance);
}

void PrintProduct(Product *product){
	if(product == NULL){
		return;
	}
	printf("\n-----------------------------------\n");
	printf("Kod\t: %s\n",product->code);
	printf("Isim\t: %s\n",product->name);
	printf("Fiyat\t: %.2f\n",product->price);
	printf("Stok\t: %d\n",product->stock);
	printf("-----------------------------------\n");
	char veri[500];
	sprintf(veri,"Product Kod : %s",product->code);
	DatFileWrite("Product Yazdirildi",veri);
}
Product *NewProduct(char code[20],char name[50],float price,int stock){
	Product *yeniProduct = (Product*)malloc(sizeof(Product));
	yeniProduct->price = price;
	yeniProduct->stock = stock;
	strcpy(yeniProduct->code,code);
	strcpy(yeniProduct->name,name);
	yeniProduct->next = NULL;

	char veri[500];
	sprintf(veri,"Kod\t\t: %s\nIsim\t: %s\nFiyat\t: %.2f\nStok\t: %d",
		code,name,price,stock);
	DatFileWrite("Product eklendi",veri);

	return yeniProduct;
}
void ProductSearch(){
	printf("Bul [Isim : 1 / Kod : 2] : ");
	int secim;
	scanf("%d",&secim);
	if(secim == 1){
		printf("Isim : ");
		char name[30];
		scanf("%s",name);
		ProductSearchName(name);
	}
	else if(secim == 2){
		printf("Kod : ");
		char code[30];
		scanf("%s",code);
		PrintProduct(ProductSearchCode(code));
	}
	else{
		printf("Hatali secim..\n"); 
		ProductSearch();
	}
}

Product *ProductSearchCode(char code[]){
	Product *iter = Products;

	while(iter != NULL){
		if(strcmp(iter->code,code) == 0)
			return iter;
		iter = iter->next;
	}
	return NULL;
}

void ProductUpdate(){
	printf("Product Kod : ");
	char code[20];
	scanf("%s",code);
	if(ProductSearchCode(code) == NULL)
		return;

	float price;
	int stock;

	printf("Fiyat : ");
	scanf("%f",&price);
	printf("Stok Adet : ");
	scanf("%d",&stock);

	Product *iter = Products;
	while(iter != NULL){
		if(strcmp(iter->code,code) == 0)
			break;
		iter = iter->next;
	}
	iter->price = price;
	iter->stock  = stock;
	FileWriteProduct();
	printf("\nProduct Guncellendi..\n");
	ProductSearchCode(code);
}

void ProductSearchName(char name[]){
	Product *iter = Products;
	int bulundu = 0;
	while(iter != NULL){
		if(strcmp(iter->name,name) >= 0){
			PrintProduct(iter);
			bulundu = 1;
		}
		iter = iter->next;
	}
	if(bulundu == 0)
		printf("\nBulunamadi\n");
}

Order *NewOrder(int order_no,int customer_no,char product_code[20],int product_piece,float amount,char date[20]){
	Order *yeniOrder = (Order*)malloc(sizeof(Order));
	yeniOrder->order_no = order_no;
	yeniOrder->customer_no = customer_no;
	yeniOrder->product_piece = product_piece;
	yeniOrder->amount = amount;
	strcpy(yeniOrder->product_code,product_code);
	strcpy(yeniOrder->date,date);
	yeniOrder->next = NULL;

	if(ProductSearchCode(product_code) == NULL || CustomerSearchCode(customer_no) == NULL){
		return NULL;
	}
	ProductSearchCode(product_code)->stock -= product_piece;
	CustomerSearchCode(customer_no)->balance -= amount;

	printf("girdi\n");

	char veri[500];
	sprintf(veri,"No\t\t\t: %d\nCustomer No\t: %d\nProduct Kod\t: %s\nProduct Adet\t: %d\nTutar\t\t: %.2f\nTarih\t\t: %s",
		order_no,customer_no,product_code,product_piece,amount,date);
	DatFileWrite("Order Ekleme",veri);

	return yeniOrder;
}

void ProductsList(){
	printf("-------- Product LISTESI --------- \n");
	Product *iter = Products;

	while(iter != NULL){
		PrintProduct(iter);
		iter = iter->next;
    }
    char veri[500];
	sprintf(veri,"Tum Productler");
	DatFileWrite("Productler Listelendi",veri);
}

void PrintOrder(Order *order){
	if(order == NULL){
		return;
	}
	printf("\n-----------------------------------\n");
	printf("Order No : %d\n",order->order_no);
	printf("Customer No : %d\n",order->customer_no);
	printf("Product Kod   : %s\n",order->product_code);
	printf("Adet\t: %d\n",order->product_piece);
	printf("Tutar\t: %.2f\n",order->amount);
	printf("Tarih\t: %s\n",order->date);
	printf("-----------------------------------\n");
	char veri[500];
	sprintf(veri,"Order No : %d",order->order_no);
	DatFileWrite("Order Yazdirildi",veri);
}

void DatFileWrite(char islem[],char veri[]){

	FILE *dosya;
	dosya = fopen("data.dat","a");
	fprintf(dosya,"\nIslem >> %s\n-----------------------------------\n",islem);
	fprintf(dosya,"%s\n-----------------------------------\n",veri);
	fclose(dosya);
}

void InvoiceWrite(){
	printf("Order No :");
	int order_no;
	scanf("%d",&order_no);
	if(OrderSearch(order_no) == NULL){
		printf("Order Bulunamadi!\n");
		return;
	}
	PrintOrder(OrderSearch(order_no));
	Order *order = OrderSearch(order_no);
	Customer *customer = CustomerSearchCode(order->customer_no);
	Product *product = ProductSearchCode(order->product_code);

	char dosyaAd[70];
	sprintf(dosyaAd,"%s_%s.txt",customer->name,customer->lastname);

	FILE *dosya;
	dosya = fopen(dosyaAd,"w+");
	fprintf(dosya, "Order No : %d \nCustomer No : %d \nIsim\t\t: %s \nSoyisim\t: %s \nTel No\t: %s \nSehir\t: %s \nProduct Kod: %s \nProduct Isim\t: %s \nAdet\t: %d \nTutar\t: %.2f TL \nTarih\t: %s",
	 order->order_no,customer->no,customer->name,customer->lastname,customer->phone,customer->address,product->code,product->name,order->product_piece,order->amount,order->date);
	fclose(dosya);

	printf("Fatura yazdirildi.\n");
}
void OrderCreate(){
	int order_no;
	int customer_no;
	char product_code[20];
	int product_piece;
	float amount;
	char date[20];

	printf("Order No: ");
	scanf("%d",&order_no);

	if(OrderSearch(order_no) != NULL){
		printf("Zaten var !!!\n");
		OrderCreate();
		return;
	}

	printf("Customer No: ");
	scanf("%d",&customer_no);
	if(CustomerSearchCode(customer_no) == NULL){
		printf("Customer Bulunamadi!");
		OrderCreate();
		return;
	}

	printf("Product Kod: ");
	scanf("%s",product_code);
	if(ProductSearchCode(product_code) == NULL){
		printf("Product bulunamadi!");
		OrderCreate();
		return;
	}

	printf("Product Piece : ");
	scanf("%d",&product_piece);
	if(ProductSearchCode(product_code)->stock < product_piece){
		printf("Yeterli stok yok!\n");
		OrderCreate();
		return;
	}
	amount = ProductSearchCode(product_code)->price * product_piece;

	if(CustomerSearchCode(customer_no)->balance < amount){
		printf("Bakiye yetersiz!\n");
		return;
	}

	printf("Tarih : ");
	scanf("%s",date);



	if(Orders == NULL){
		Orders = NewOrder(order_no,customer_no,product_code,product_piece,amount,date);
		printf("\nOrder eklendi\n");
		return;
	}

	Order *iter = Orders;

	while(iter->next != NULL)
		iter = iter->next;

	iter->next = NewOrder(order_no,customer_no,product_code,product_piece,amount,date);
	printf("\nOrder eklendi.\n");
	return;
}

Order *OrderSearch(int order_no){
	Order *iter = Orders;

	while(iter != NULL){
		if(iter->order_no = order_no)
			return iter;
		iter = iter->next;
	}
	return NULL;
}

void OrderView(){
	printf("Order No :");
	int order_no;
	scanf("%d",&order_no);
	PrintOrder(OrderSearch(order_no));
}

void OrdersList(){
	printf("Customer No :");
	int customer_no;
	scanf("%d",&customer_no);
	if(CustomerSearchCode(customer_no) == NULL){
		printf("Customer bulunamadi!\n");
		return;
	}
	PrintCustomer(CustomerSearchCode(customer_no));

	printf("-------- %s %s / Order LISTESI ---- \n",CustomerSearchCode(customer_no)->name,CustomerSearchCode(customer_no)->lastname);
	Order *iter = Orders;

	while(iter != NULL){
		if(iter->customer_no == customer_no)
			PrintOrder(iter);
		iter = iter->next;
    }
    char veri[500];
	sprintf(veri,"Customer No\t: %d\nCustomer Isim\t: %s\nCustomer Soyisim : %s",
	customer_no,CustomerSearchCode(customer_no)->name,CustomerSearchCode(customer_no)->lastname);
	DatFileWrite("Order Listelendi",veri);

}

void FileWriteCustomer(){
	FILE *file = fopen("customers.txt","w");
	Customer *iter = Customers->next;

	while(iter != NULL){
		fprintf(file, "%d %s %s %s %s %f\n",iter->no,iter->name,iter->lastname,iter->phone,iter->address,iter->balance);
		iter = iter->next;
    }
    fclose(file);
}
void FileWriteProduct(){
	FILE *file = fopen("products.txt","w");
	Product *iter = Products->next;

	while(iter != NULL){
		fprintf(file, "%s %s %f %d\n",iter->code,iter->name,iter->price,iter->stock);
		iter = iter->next;
    }
    fclose(file);
}
void FileWriteOrder(){
	FILE *file = fopen("orders.txt","w");
	Order *iter = Orders->next;

	while(iter != NULL){
		fprintf(file, "%d %d %s %d %f %s\n",
			iter->order_no,iter->customer_no,iter->product_code,iter->product_piece,iter->amount,iter->date);
		iter = iter->next;
    }
    fclose(file);
}

void FileReadCustomer(){
	FILE *file = fopen("customers.txt","r");
	Customers = NULL;
	while(!feof(file)){
		int no;
		char name[30];
		char lastname[30];
		char phone[13];
		char address[300];
		float balance;
		fscanf(file, "%d %s %s %s %s %f\n",&no,name,lastname,phone,address,&balance);

		if(Customers == NULL){
			Customers = NewCustomer(no,name,lastname,phone,address,balance);
			continue;
		}
		else{
			Customer *iter = Customers;
			while(iter->next !=NULL)
				iter = iter->next;
			iter->next = NewCustomer(no,name,lastname,phone,address,balance);
		}
	}
	fclose(file);
}
void FileReadProduct(){
	FILE *file = fopen("products.txt","r");
	Products = NULL;
	while(!feof(file)){
		char code[20];
		char name[50];
		float price;
		int stock;
		fscanf(file, "%s %s %f %d\n",code,name,&price,&stock);

		if(Orders == NULL){
			Products = NewProduct(code,name,price,stock);
			continue;
		}
		else{
			Product *iter = Products;
			while(iter->next !=NULL)
				iter = iter->next;
			iter->next = NewProduct(code,name,price,stock);
		}
	}
	fclose(file);
}
void FileReadOrder(){
	FILE *file = fopen("orders.txt","r");
	Orders = NULL;
	while(!feof(file)){

		int order_no;
		int customer_no;
		char product_code[20];
		int product_piece;
		float amount;
		char date[20];

		fscanf(file, "%d %d %s %d %f %s\n",&order_no,&customer_no,product_code,&product_piece,&amount,date);

		if(Orders == NULL){
			Orders = NewOrder(order_no,customer_no,product_code,product_piece,amount,date);
			continue;
		}

		Order *iter = Orders;

		while(iter->next != NULL)
			iter = iter->next;

		iter->next = NewOrder(order_no,customer_no,product_code,product_piece,amount,date);
	
	}
	fclose(file);
}