/*****************************************
 * Snake.cpp                             *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

#include "Snake.h"          //To know function prototypes of Snake Class.


//Constructor Function of Snake Class.
//Snake Class is derived from Reptile Class, so Snake Class' Constructor Function HAS TO CALL REPTILE CLASS' CONSTRUCTOR.
Snake::Snake(const string& name, int age, int sizzleSoundLevel):Reptile(name,age)
{
    //m_sizzleSoundLevel is the private member of Snake Class.
    m_sizzleSoundLevel = sizzleSoundLevel;
}

//Prints that snake which called this function is sizzling and its sound level.
//Function should be const, because it is an accessor function, it won't change any member of Class.
void Snake::Sizzle() const
{
    //m_name is the protected member of Animal Class, we can reach it from Snake class because of the PROTECTED DEFINED.
    cout<<m_name<<" is sizzling and its sound level is:\t"<<m_sizzleSoundLevel<<endl;
}
