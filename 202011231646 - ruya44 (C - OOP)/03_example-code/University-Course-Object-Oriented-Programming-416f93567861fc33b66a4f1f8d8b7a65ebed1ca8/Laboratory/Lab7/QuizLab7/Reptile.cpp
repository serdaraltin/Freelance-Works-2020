/*****************************************
 * Reptile.cpp                           *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

#include "Reptile.h"        //To know function prototypes of Reptile Class.


//Constructor Function of Reptile Class.
//Reptile Class is derived from Animal Class, so Reptile Class' Constructor Function HAS TO CALL ANIMAL CLASS' CONSTRUCTOR.
Reptile::Reptile(const string& name, int age):Animal(name,age)
{
    
}

//Prints that reptile which called this function is ovulating.
//Function should be const, because it is an accessor function, it won't change any member of Class.
void Reptile::Ovulate() const
{
    //m_name is the protected member of Animal Class, we can reach it from Reptile class because of the PROTECTED DEFINED.
    cout<<m_name<<" is ovulating!\n";
}
