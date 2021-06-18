/*****************************************
 * TwoDShape.cpp                         *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "TwoDShape.h"      //To know function prototypes of TwoDShape Class.


//Constructor Function of TwoDShape Class.
//TwoDShape is derived from Shape Class, so Shape Class' Constructor should be called.
TwoDShape::TwoDShape(double* centerofmass, string color, bool visibility):Shape(color, visibility)
{
    for(int i=0; i<2; i++)
        m_centerofmass[i] = centerofmass[i];
}

//Virtual Destructor Function of TwoDShape Class.
TwoDShape::~TwoDShape()
{
    
}
