
#include <iostream> 
#include <stack> 
#include <fstream>

using namespace std;





class Person{
	public:
	string name;
	int birthDate;
	int weight;
};

class Node{  
    public: 
    Person *person;  
    stack <string> fStack; 
    Node *NLeft;  
    Node *NRight;  
    int height;  
};  

int height(Node *N){  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

int Getmaxi(int a, int b)  { 
    if(a != b) {
        if(a < b)
            return b;
    }
    else if (a == b)
    {
        return a;
    }
    else{
        return a; 
    }
	return 0;
}  

int GetBalance(Node *N){  
    if (N == NULL)  
        return 0;  
    return height(N->NLeft) - height(N->NRight);  
}  

Node* CreateNode(Person* person)  {  
    Node* nod = new Node(); 
    nod-> person =  person;  
    nod->NLeft = NULL;  
    nod->NRight = NULL;  
    nod->height = 1; 
    nod->fStack.push("O");
    return(nod);  
}  

Node *RRight(Node *y){  
	
    Node *x = y->NLeft;  
    Node *T2 = x->NRight;  
    x->NRight = y;  
    y->NLeft = T2;  
    y->height = Getmaxi(height(y->NLeft), height(y->NRight)) + 1;  
    x->height = Getmaxi(height(x->NLeft), height(x->NRight)) + 1;  
    return x;  
}  

Node *RLeft(Node *x){  
    Node *y = x->NRight;  
    Node *T2 = y->NLeft;  
    y->NLeft = x;  
    x->NRight = T2;  
    x->height = Getmaxi(height(x->NLeft), height(x->NRight)) + 1;  
    x->fStack.push("A");
    y->height = Getmaxi(height(y->NLeft), height(y->NRight)) + 1;  
 	y->fStack.push("Y");
    return y;  
}  
  
int CalcAge(Person *person){
    int year = 2020;
    int age = year-person->birthDate;
    return age;
}   

Node* NodeIns(Node* nod, Person* person){  
	
    if (nod == NULL)  {
    	Node * newF = CreateNode(person);
        return(newF);  
    }
    if (CalcAge(person) < CalcAge(nod->person)){
    	nod->fStack.push("D");
    	nod->NRight->fStack.push("D");
        nod->NLeft = NodeIns(nod->NLeft, person);  

    }	
    else if (CalcAge(person) > CalcAge(nod->person))
        nod->NRight = NodeIns(nod->NRight, person);  
    else
        return nod;  
    
 		
    nod->height = 1 + Getmaxi(height(nod->NLeft), height(nod->NRight));  
    int balance = GetBalance(nod);  
    if (balance > 1 && CalcAge(person) < CalcAge(nod->NLeft->person))
        return RRight(nod);  
    if (balance < -1 && CalcAge(person) > CalcAge(nod->NRight->person)){
    	nod->fStack.push("D");
        return RLeft(nod);  
    }
    if (balance < -1 && CalcAge(person) < CalcAge(nod->NRight->person)){  
    	nod->NRight = RRight(nod->NRight); 
        return RLeft(nod);  
    }  
     if (balance > 1 && CalcAge(person) > CalcAge(nod->NLeft->person)){ 
        nod->NLeft = RLeft(nod->NLeft);  
        return RRight(nod);  
    }  

    return nod;  
}  

void SortPostOrder(Node *firstNode){  
    if(firstNode != NULL)  {  
    	SortPostOrder(firstNode->NLeft);  
        SortPostOrder(firstNode->NRight);  

        cout << firstNode->person->name << ", " << firstNode->person->birthDate << ", " << firstNode->person->weight;
        cout << "   Yigit: ";

        while (!firstNode->fStack.empty()) 
	    { 
	        cout << firstNode->fStack.top() << " "; 
	        firstNode->fStack.pop(); 
	    } 
	    cout << endl;
    }  
}  

Person *CreatePerson(string pname, int pbirthDate, int pweight){
	Person *newF = new Person();
	newF->name = pname;
	newF->birthDate = pbirthDate;
	newF->weight = pweight;
	return (newF);
} 

void FileProcess(){
 	Node *ilk = NULL;  
    ifstream FReader("Kisiler.txt");

    string name;
    string stringBirthDate;
    string stringWeight;

    while(!FReader.eof())
    {
        getline(FReader,name,'#');
        getline(FReader,stringBirthDate,'#');
        getline(FReader,stringWeight,'\n');
        int birthDate = stoi(stringBirthDate);
        int weight = stoi(stringWeight);	
        ilk = NodeIns(ilk, CreatePerson(name,birthDate,weight));
    }
    FReader.close();

    SortPostOrder(ilk);   
} 