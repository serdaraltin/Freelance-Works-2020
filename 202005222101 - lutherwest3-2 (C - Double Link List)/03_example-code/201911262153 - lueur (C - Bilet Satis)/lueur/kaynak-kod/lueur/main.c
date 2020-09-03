#include <stdio.h>
#include <stdlib.h>

enum e_c{business,economy,standart};
enum e_p{veteran,diplomat};


struct t{
	char *passenger_name;
	enum e_c clas;
	enum e_p priority;
	struct t *next;
};
typedef struct t Ticket;

struct f{
	int readonly;
	int sold;
	char *name;
	int business;
	int standart;
	int economy;
	struct f *next;
	struct t *ticket;
};
typedef struct f Flight;

Flight *root = NULL;

Flight *find_flight(char *flight_name){
	Flight *iter = root;
	if(iter==NULL)
		return NULL;
	if(strcmp(iter->name,flight_name) == 0)
		return root;
	//perror("gecti");
	while(iter->next != NULL){
		if(strcmp(iter->name,flight_name) == 0)
			return iter;		
		iter = iter->next;
	}
	return NULL;
}

Flight *addseat(char *name, enum e_c clas, int amount){
	if(find_flight(name) != NULL)
	{
		Flight *flight = find_flight(name);
		if(flight->readonly == 1)
			return NULL;
		switch(clas){
		case business:
			flight->business = amount;
		break;
			
		case standart:
			flight->standart = amount;
		break;
		
		case economy:
			flight->economy = amount;
		break;
		}	
		printf("addseats %s %d %d %d\n",flight->name,flight->business,flight->standart,flight->economy);
		return flight;
	}
	Flight *create = (Flight*)malloc(sizeof(Flight));
	create->name = name;
	create->readonly = 0;
	create->business = 0;
	create->standart = 0;
	create->economy = 0;
	create->ticket = NULL;
	switch(clas){
		case business:
			create->business = amount;
		break;
			
		case standart:
			create->standart = amount;
		break;
		
		case economy:
			create->economy = amount;
		break;
	}
	printf("addseats %s %d %d %d\n",create->name,create->business,create->standart,create->economy);
	create->next = NULL;
	if(root == NULL)
	{
		root = create;	
		return create;
	}	
	Flight *iter = root;
	while(iter->next != NULL)
		iter = iter->next;
	iter->next = create;
	return create;
}

int passenger_count(Flight *flight,enum e_c clas){
	Ticket *iter = flight->ticket;
	if(iter == NULL)
		return 1;
	int i=1;
	while(iter->next != NULL)
	{
		i++;
		iter = iter->next;
	}
	return i;
	
}

Ticket *enqueue(char *flight_name,enum e_c clas,char *passenger_name,enum e_p priority){
	Flight *flight = find_flight(flight_name);
	if(flight->sold == 1)
	{
		printf("sold %s %d %d %d\n",flight->name,passenger_count(flight,business),passenger_count(flight,standart),passenger_count(flight,economy));
		return NULL;
	}
	if(flight->readonly == 1)
	{
		printf("closed %s %d %d\n",flight->name,passenger_count(flight,clas),1);
		return NULL;
	}
	Ticket *create = (Ticket*)malloc(sizeof(Ticket));
	create->passenger_name = passenger_name;
	create->clas = clas;
	create->priority = priority;
	create->next = NULL;
	
	char cl[15];
	if(clas == business)
		strcpy(cl,"business");
	else if(clas == standart)
		strcpy(cl,"standart");
	else if (clas == business)
		strcpy(cl,"economy");
	
	printf("enqueue %s %s %s %d\n",flight->name,passenger_name,cl,passenger_count(flight,clas));
	
	if(flight->ticket == NULL)
	{
		flight->ticket = create;
		//perror("gecti");
		return flight->ticket;	
	}
	
	Ticket *iter = flight->ticket;
	while(iter->next != NULL)
		iter = iter->next;
	iter->next = create;
	
	return iter->next;
}

void close(char *flight_name){
	Flight *flight = find_flight(flight_name);
	flight->readonly = 1;
	return;
}

int sell(char *flight_name){
	Flight *flight = find_flight(flight_name);
	close(flight_name);
	flight->sold = 1;
	printf("sold %s %d %d %d\n",flight->name,passenger_count(flight,business),passenger_count(flight,standart),passenger_count(flight,economy));
}

Ticket *find_ticket(char *passanger_name){
	if(root == NULL)
		return NULL;
	Flight *iter = root;
	
	if(iter->next == NULL)
	{
		Ticket *titer = iter->ticket;
		if(strcmp(titer->passenger_name,passanger_name) == 0)
			return titer;
		while(titer->next != NULL)
		{
			if(strcmp(titer->passenger_name,passanger_name) == 0)
				return titer;
			titer = titer->next;
		}
	}
	while(iter->next != NULL)
	{
		
		Ticket *titer = iter->ticket;
		if(strcmp(titer->passenger_name,passanger_name) == 0)
			return titer;
		while(titer->next != NULL)
		{
			if(strcmp(titer->passenger_name,passanger_name) == 0)
				return titer;
			titer = titer->next;
		}
		iter = iter->next;
	}
	return NULL;
}
Flight *find_tflight(char *passanger_name){
	if(root == NULL)
		return NULL;
	Flight *iter = root;
	
	
	if(iter->next == NULL){
		Ticket *titer = iter->ticket;
		if(strcmp(titer->passenger_name,passanger_name) == 0)
			return iter;
		
		while(titer->next != NULL)
		{
			if(strcmp(titer->passenger_name,passanger_name) == 0)
				return iter;
			titer = titer->next;
		}
	}
	while(iter->next != NULL)
	{
		Ticket *titer = iter->ticket;
		if(strcmp(titer->passenger_name,passanger_name) == 0)
			return iter;
		
		while(titer->next != NULL)
		{
			if(strcmp(titer->passenger_name,passanger_name) == 0)
				return iter;
			titer = titer->next;
		}
		iter = iter->next;
	}
	return NULL;
}

void info(char *passenger_name){
	char cl[15];
	Ticket *ticket = find_ticket(passenger_name);
	if(ticket->clas == business)
		strcpy(cl,"business");
	else if(ticket->clas == standart)
		strcpy(cl,"standart");
	else if(ticket->clas == economy)
		strcpy(cl,"economy");
	
	printf("%s %s %s\n",passenger_name,find_tflight(passenger_name)->name,cl);
}
 
int main(){
	
	
	addseat("tk1212",business,2);
	addseat("tk1212",standart,3);
	addseat("tk1212",economy,4);
	
	enqueue("tk1212",business,"psg_bus_1",veteran);
	
	info("psg_bus_1");
	
	
}