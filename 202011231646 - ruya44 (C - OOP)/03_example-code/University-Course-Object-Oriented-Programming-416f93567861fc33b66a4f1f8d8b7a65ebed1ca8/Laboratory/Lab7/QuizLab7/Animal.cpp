/*****************************************
 * Animal.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

//To know function prototypes of Animal Class.
#include "Animal.h"


//Constructor Function of Animal Class.
//m_name and m_age are initialized in memory initializer scope.
Animal::Animal(const string& name, int age):m_name(name),m_age(age)
{
    
}

//Returns m_name which is the PROTECTED member variable of Animal Class.
//Function should be const, because it is an accessor function, it won't change any member of Class.
string Animal::getName() const
{
    return m_name;
}

//Returns m_age which is the PROTECTED member variable of Animal Class.
//Function should be const, because it is an accessor function, it won't change any member of Class.
int Animal::getAge() const
{
    return m_age;
}

//Sets m_name which is the PROTECTED member variable of Animal Class.
void Animal::setName(string name)
{
    m_name = name;
}

//Sets m_age which is the PROTECTED member variable of Animal Class.
void Animal::setAge(int age)
{
    m_age = age;
}
