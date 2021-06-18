/*****************************************
 * Mammal.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

#include "Mammal.h"             //To know function prototypes of Mammal Class.

//Constructor Function of Mammal Class.
//Mammal Class is derived from Animal Class, so Mammal Class' Constructor Function HAS TO CALL ANIMAL CLASS' CONSTRUCTOR.
Mammal::Mammal(const string& name, int age):Animal(name,age)
{}

//Prints that mammal which called this function is breeding.
//Function should be const, because it is an accessor function, it won't change any member of Class.
void Mammal::Breed() const
{
    //m_name is the protected member of Animal Class, we can reach it from Mammal class because of the PROTECTED DEFINED.
    cout<<m_name<<" is breeding!\n";
}
