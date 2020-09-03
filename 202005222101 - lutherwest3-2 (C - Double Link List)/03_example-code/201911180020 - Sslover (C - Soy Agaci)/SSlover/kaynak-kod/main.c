#include <stdio.h>
#include <stdlib.h>

struct p{
	char *name;
	int year_of_birth;
	char *sex;
	struct p *father;
	struct p *mother;
	struct p *wife;
	struct p *child1;
	struct p *child2;
};

typedef struct p Person;

Person *person_constructor(char *name, int year_of_birth, char *sex);
void display_person(Person *p);
void display_family(Person *family[], int n);
void marry_them(Person *p1, Person *p2);
Person *birth(char *name, int year_of_birth, char *sex, Person *mother);
Person *sibling(Person *p, int print);
void display_uncles(Person *p);
void display_aunts(Person *p);


int main(){
	Person* p1 = person_constructor("Abbas", 1970, "male");
	Person* p2 = person_constructor("Sidika", 1970, "famale");
	marry_them(p1,p2);
	
	Person* p3 = person_constructor("Pinar", 1990, "famale");
	Person* p4 = birth("Siamak", 1990, "male",p2);
	marry_them(p3,p4);
	
	Person* p5 = birth("Guzide", 1990, "famale",p2);
	Person* p6 = person_constructor("Fatih", 1990, "male");
	marry_them(p5,p6);
	
	Person* p7 = birth("Berkecan", 2010, "male",p3);
	Person* p8 = birth("Ekinsu", 2010, "famale",p3);
	Person* p9 = birth("Canim", 2010, "famale",p5);
	
	
	display_person(p1);
	sibling(p7,1);
	display_uncles(p7);
	display_aunts(p9);
    
	Person* family[] = {p1, p2, p3, p4, p5, p6, p7, p8, p9};
	display_family(family, 9); 
	return;
}

Person * person_constructor(char *name, int year_of_birth, char *sex)
{
	Person *create = (Person*)malloc(sizeof(Person));
	create->name = name;
	create->year_of_birth = year_of_birth;
	create->sex = sex;
	create->mother = NULL;
	create->father = NULL;
	create->child1 = NULL;
	create->child2 = NULL;
	create->wife = NULL;
	
	return create;
}

void display_person(Person *p)
{
	printf("================\n");
	printf("Name\t: %s\nSex\t: %s\nYear\t: %d\n",
	p->name,p->sex,p->year_of_birth);
	if(p->father != NULL)
		printf("Father\t: %s",p->father->name);
	else
		printf("Father\t: NA");
	printf("\n");
	if(p->mother != NULL)
		printf("Mother\t: %s",p->mother->name);
	else
		printf("Mother\t: NA");
	printf("\n");
	if(p->child1 != NULL)
		printf("Sig.O\t: %s",p->wife->name);
	else
		printf("Sig.O\t: NA");
	printf("\n");
	if(p->child1 != NULL)
		printf("Child 1\t: %s",p->child1->name);
	else
		printf("Child 1\t: NA");
	printf("\n");
	if(p->child2 != NULL)
		printf("Child 2\t: %s",p->child2->name);
	else
		printf("Child 2\t: NA");
	printf("\n");
	return;
}

void display_family(Person *family[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{	
		display_person(family[i]);
	}
}

void marry_them(Person *p1, Person *p2)
{
	p1->wife = p2;
	p2->wife = p1;
	return;
}

Person *birth(char *name, int year_of_birth, char *sex, Person *mother)
{
	Person *child = (Person*)malloc(sizeof(Person));
	child->name = name;
	child->year_of_birth = year_of_birth;
	child->sex = sex;
	child->mother = mother;
	child->father = mother->wife;
	child->child1 = NULL;
	child->child2 = NULL;
	child->wife = NULL;
	
	if(mother->child1 == NULL)
	{
		mother->child1 = child;
		mother->wife->child1 = child;
		return child;
	}
	mother->child2 = child;
	mother->wife->child2 = child;
	return child;
}

Person *sibling(Person *p, int print)
{
	
	if(p->mother->child1 == p && p->mother->child2 != NULL)
	{
		printf("\nThe sibling of %s is %s.\n",p->name,p->mother->child2->name);
		return p->mother->child2;
	}
	else if(p->mother->child1 != NULL)
	{
		printf("\nThe sibling of %s is %s.\n",p->name,p->mother->child1->name);
		return p->mother->child1;
	}
}

void display_uncles(Person *p)
{
	Person *child = NULL;
	
	if(p->father->mother->child1 != NULL && p->father->mother->child1 != p->father)
		child = p->father->mother->child1;
	if(p->father->mother->child2 != NULL && p->father->mother->child2 != p->father)
		child = p->father->mother->child2;
		
	if(child != NULL && strcmp(child->sex,"male") == 0)
		printf("\n%s\n",child->name); 
	else if(child != NULL)
	{
		if(child->wife != NULL)
			printf("\n%s\n",child->wife->name);
	}

	return;
}

void display_aunts(Person *p)
{
	Person *child = NULL;
	
	if(p->mother->mother->child1 != NULL && p->mother->mother->child1 != p->mother)
		child = p->mother->mother->child1;
	if(p->mother->mother->child2 != NULL && p->mother->mother->child2 != p->mother)
		child = p->mother->mother->child2;
		
	if(child != NULL && strcmp(child->sex,"famale") == 0)
		printf("\n%s\n",child->name); 
	else if(child != NULL)
	{
		if(child->wife != NULL)
			printf("\n%s\n",child->wife->name);
	}
	
	return;
}






