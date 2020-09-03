#include <stdio.h>
#include <stdlib.h>

struct a{
	char *ownerName; //hesap sahibi
	char *password; //parola
	int amount; //miktar
	int accountCreationYear; //hesap olusturma yili
	struct a *next;
};

typedef struct a Account;

struct b{
	char *bankName; //banka adi
	int maxNumberOfAccounts; //maximum hesap sayisi
	int curNumberOfAccounts; //mevcut hesap sayisi
	struct a *allAccounts; //tum hesaplara erismek icin Account struct
};

typedef struct b Bank;


Bank *bank_counstructor(char *bankName, int maxNumberOfAccounts);
void bankInfo(Bank *b);
void customerInfo(Bank *b);
int createAccount(Bank *b, char* holderName, char *password, int accountCreationYear);
int depositMoney(Bank *b, int accountNumber, int amount);
int withdrawMoney(Bank *b, int accountNumber, char *password, int amount);
int transferMoney(Bank *senderBank, int senderAccount, char *senderPassword, Bank *receiverbank, int receiverAccount, int amount);
void checkBalance(Bank *b, int accountNumber, char *password);
Account *find_account(Bank *b, int accountNumber);


int main()
{
	Bank *b1 = bank_counstructor("BankA", 3);
	Bank *b2 = bank_counstructor("BankB", 4);
	
	int hesap11 = createAccount(b1, "Ahmet", "pass" , 1980);
	int hesap12 = createAccount(b1, "Veli", "word" , 2000);
	int hesap21 = createAccount(b2, "Mehmet", "sifre" , 1990);
	
	depositMoney(b1, hesap11, 50);
	depositMoney(b1, hesap12, 80);	
	
	transferMoney(b1, hesap11, "hatali", b2, hesap21, 20);
	transferMoney(b1, hesap11, "pass", b2, hesap21, 20);
	
	
	withdrawMoney(b1, hesap12, "hatali", 40);
	withdrawMoney(b1, hesap12 , "word", 120);
	withdrawMoney(b1, hesap12 , "word", 40);

	checkBalance(b1, hesap11, "hatali");
	checkBalance(b1, hesap11, "pass");
	checkBalance(b2, hesap21, "sifre");
    checkBalance(b1, hesap12, "word");
	
    customerInfo(b1);
	bankInfo(b2);
	
	return;
}

Bank *bank_counstructor(char *bankName, int maxNumberOfAccount)
{
	Bank *create = (Bank*)malloc(sizeof(Bank));
	create->bankName = bankName;
	create->maxNumberOfAccounts = maxNumberOfAccount;
	create->curNumberOfAccounts = 0;
	create->allAccounts = NULL;
	return create;
}

void bankInfo(Bank *b)
{
	int total_Capital = 0;
	
	Account *iter = b->allAccounts;
	total_Capital = iter->amount;
	while(iter->next != NULL)
	{
		total_Capital += iter->amount;
		iter = iter->next;
	}
	
	printf("Name of the Bank: %s\nTotal Capital: %d",b->bankName,total_Capital);
	return;
}

void customerInfo(Bank *b)
{
	printf("\nCustomer List :\n");
	Account *iter = b->allAccounts;
	
	while(iter != NULL)
	{
		printf("%s since %d.\n",iter->ownerName,iter->accountCreationYear);
		iter = iter->next;
	}
}

int createAccount(Bank *b, char* holderName, char *password, int accountCreationYear)
{
	Account *create = (Account*)malloc(sizeof(Account));
	create->ownerName = holderName;
	create->password = password;
	create->accountCreationYear = accountCreationYear;
	create->amount = 0;
	create->next = NULL;
	
	if(b->curNumberOfAccounts == b->maxNumberOfAccounts)
		return -1;
		
	
	if(b->allAccounts == NULL)
	{
		b->allAccounts = create;
		return 0;
	}
	Account *iter = b->allAccounts;
	int i=1;
	while(iter->next != NULL)
	{
		i++;
		iter = iter->next;
	}	
	
	iter->next = create;	
	return i;
}

int depositMoney(Bank *b, int accountNumber, int amount)
{
	Account *account = find_account(b,accountNumber);
	account->amount+= amount;
	//printf("\nHesap -> %s \nMiktar -> %d",account->ownerName,amount);
	return amount;
}

int withdrawMoney(Bank *b, int accountNumber, char *password, int amount)
{
	Account *account = find_account(b,accountNumber);
	
	if(strcmp(account->password,password) != 0)
	{
		printf("\nWrong password!");
		return -1;
	}
	if(account->amount < amount)
	{
		printf("\nInsufficient funds!");
		return -1;
	}
	account->amount-= amount;
    //printf("\nAccount balance: %d",account->amount);	
	return account->amount;
}

int transferMoney(Bank *senderBank, int senderAccount, char *senderPassword, Bank *receiverbank, int receiverAccount, int amount)
{
	Account *receiver_account = find_account(receiverbank,receiverAccount);
	
	if(withdrawMoney(senderBank,senderAccount,senderPassword,amount) == -1)
		return 0;
	receiver_account->amount+= amount;
	//printf("\nbakiye - %d",receiver_account->amount);
	return amount;
}

void checkBalance(Bank *b, int accountNumber, char *password)
{
	Account *account = find_account(b,accountNumber);
	
	if(strcmp(account->password,password) == 0)
	{
		printf("\nAccount balance: %d",account->amount);
		return;
	}
	printf("\nWrong password!");
	return;
}

Account *find_account(Bank *b, int accountNumber)
{
	if(accountNumber == 0)
		return b->allAccounts;
	Account *iter = b->allAccounts;
	int i=1;
	while(i <= accountNumber){
		i++;
		iter = iter->next;
	}
	return iter;
}
