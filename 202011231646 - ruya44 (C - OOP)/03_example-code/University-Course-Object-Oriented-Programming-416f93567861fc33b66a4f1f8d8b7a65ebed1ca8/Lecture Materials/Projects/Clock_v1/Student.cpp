#include "Student.h"
#include <iostream>
using namespace std;

void Student::setStudent(string _name, int _id)
{
	name=_name;
	id=_id;
}

void Student::print()
{

	cout<<"Name : "<<name<<endl;
	cout<<"ID   : "<<id<<endl;

}
