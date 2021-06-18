/*****************************************
 * Crocodile.cpp                         *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

#include "Crocodile.h"          //To know function prototypes of Crocodile Class.

//Constructor Function of Crocodile Class.
//Crocodile Class is derived from Reptile Class, so Crocodile Class' Constructor Function HAS TO CALL REPTILE CLASS' CONSTRUCTOR.
Crocodile::Crocodile(const string& name, int age, int roarSoundLevel):Reptile(name,age)
{
    //m_roarSoundLevel is the protected member of Crocodile Class.
    m_roarSoundLevel = roarSoundLevel;
}


//Prints that crocodile which called this function is roaring and its sound level.
//Function should be const, because it is an accessor function, it won't change any member of Class.
void Crocodile::Roar() const
{
    //m_name is the protected member of Animal Class, we can reach it from Crocodile class because of the PROTECTED DEFINED.
    cout<<m_name<<" is roaring and its sound level is:\t"<<m_roarSoundLevel<<endl;
}
