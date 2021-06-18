/*****************************************
 * CustomRectangle.cpp                   *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "CustomRectangle.h"            //To know function prototypes of CustomRectangle Class.

//Constructor Function of CustomRectangle Class.
//CustomRectangle Class is derived from TwoDShape Class, so TwoDShape Class' Constructor should be called.
CustomRectangle::CustomRectangle(double width, double height, double* centerofmass, string color, bool visibility):TwoDShape(centerofmass,color,visibility),width(width),height(height)
{
    
}

//Destructor Function of CustomRectangle Class.
CustomRectangle::~CustomRectangle()
{
    
}

//Returns the rectangle's area.
double CustomRectangle::CalculateSurfaceArea()
{
    return width*height;
}

//Returns the shape's description as string.
string CustomRectangle::GetShapeDescription()
{
    //m_visibility is a boolean variable, we can not add it to string directly.
    string s_visibility;
    if(m_visibility==true)
        s_visibility = "true";
    else
        s_visibility = "false";
    
    string description =
    "CustomRectangle:\t"+m_color
    +"\nVisibility:\t"+s_visibility
    +"\nCenter of Mass:\t<"+to_string(m_centerofmass[0])+","+to_string(m_centerofmass[1])
    +">\nWidth:\t"+to_string(width)
    +"\nHeight:\t"+to_string(height)
    +"\nArea:\t"+to_string((*this).CalculateSurfaceArea())+"\n";
    
    return description;
}
