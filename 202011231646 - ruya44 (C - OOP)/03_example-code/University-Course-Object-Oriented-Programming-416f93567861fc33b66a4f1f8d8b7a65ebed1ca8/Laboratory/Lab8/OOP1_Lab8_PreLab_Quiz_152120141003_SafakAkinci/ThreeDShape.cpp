/*****************************************
 * ThreeDShape.cpp                       *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "ThreeDShape.h"        //To know function prototypes of ThreeDShape Class.

//ThreeDShape is derived from Shape Class, so Shape Class' Constructor should be called.
ThreeDShape::ThreeDShape(double* centerofmass, string color, bool visibility):Shape(color, visibility)
{
    for(int i=0; i<3; i++)
        m_centerofmass[i] = centerofmass[i];
}


//Virtual Destructor Function of ThreeDShape Class.
ThreeDShape::~ThreeDShape()
{
    
}
