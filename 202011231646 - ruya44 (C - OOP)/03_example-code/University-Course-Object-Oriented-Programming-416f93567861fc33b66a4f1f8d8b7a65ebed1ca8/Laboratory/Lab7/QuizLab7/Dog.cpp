/*****************************************
 * Dog.cpp                               *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

#include "Dog.h"            //To know function prototypes of Dog Class.

//Constructor Function of Dog Class.
//Dog Class is derived from Mammal Class, so Dog Class' Constructor Function HAS TO CALL MAMMAL CLASS' CONSTRUCTOR.
Dog::Dog(const string& name, int age, int barkSoundLevel):Mammal(name,age)
{
    //m_barkSoundLevel is the protected member of Dog Class.
    m_barkSoundLevel = barkSoundLevel;
}

//Prints that dog which called this function is barking and its sound level.
//Function should be const, because it is an accessor function, it won't change any member of Class.
void Dog::Bark() const
{
    //m_name is the protected member of Animal Class, we can reach it from Dog class because of the PROTECTED DEFINED.
    cout<<m_name<<" is barking and its sound level is:\t"<<m_barkSoundLevel<<endl;
}


