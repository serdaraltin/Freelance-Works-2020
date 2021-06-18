/*****************************************
 * Cat.cpp                               *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

#include "Cat.h"        //To know function prototypes of Cat Class.

//Constructor Function of Cat Class.
//Cat Class is derived from Mammal Class, so Cat Class' Constructor Function HAS TO CALL MAMMAL CLASS' CONSTRUCTOR.
Cat::Cat(const string& name, int age, int miaowSoundLevel):Mammal(name,age)
{
    //m_miaowSoundLevel is the private member of Cat Class.
    m_miaowSoundLevel = miaowSoundLevel;
}


//Prints that cat which called this function is miaowing and its sound level.
//Function should be const, because it is an accessor function, it won't change any member of Class.
void Cat::Miaow() const
{
    //m_name is the protected member of Animal Class, we can reach it from Cat class because of the PROTECTED DEFINED.
    cout<<m_name<<" is miaowing and its sound level is:\t"<<m_miaowSoundLevel<<endl;
}
