/*****************************************
 * Circle.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Circle.h"         //To know function prototypes of Circle Class.


//Constructor Function of Circle Class.
//Circle Class is derived from TwoDShape Class, so TwoDShape Class' Constructor should be called.
Circle::Circle(double radius, double* centerofmass, string color, bool visibility):TwoDShape(centerofmass,color,visibility)
{
    (*this).radius = radius;
}


//Destructor Function of Circle Class.
Circle::~Circle()
{
    
}

//Returns the circle's area.
double Circle::CalculateSurfaceArea()
{
    return 3.14*radius*radius;
}

//Returns the shape's description as string.
string Circle::GetShapeDescription()
{
    //m_visibility is a boolean variable, we can not add it to string directly.
    string s_visibility;
    if(m_visibility==true)
        s_visibility = "true";
    else
        s_visibility = "false";
    
    string description =
    "Circle:\t"+m_color
    +"\nVisibility:\t"+s_visibility
    +"\nCenter of Mass:\t<"+to_string(m_centerofmass[0])+","+to_string(m_centerofmass[1])
    +">\nRadius:\t"+to_string(radius)
    +"\nArea:\t"+to_string((*this).CalculateSurfaceArea())+"\n";
    
    return description;
}
