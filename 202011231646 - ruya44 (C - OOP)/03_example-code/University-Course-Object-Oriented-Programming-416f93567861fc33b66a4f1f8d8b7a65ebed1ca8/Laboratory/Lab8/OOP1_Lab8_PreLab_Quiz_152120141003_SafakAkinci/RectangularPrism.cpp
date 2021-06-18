/*****************************************
 * RectangularPrism.cpp                  *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "RectangularPrism.h"       //To know function prototypes of RectangularPrism Class.

//Constructor Function of RectangularPrism Class.
//RectangularPrism Class is derived from ThreeDShape Class, so ThreeDShape Class' Constructor should be called.
RectangularPrism::RectangularPrism(double width, double height, double depth, double* centerofmass, string color, bool visibility):ThreeDShape(centerofmass,color,visibility),width(width),height(height),depth(depth)
{
    
}

//Destructor Function of RectangularPrism Class.
RectangularPrism::~RectangularPrism()
{
    
}

//Returns the rectangle prism's area.
double RectangularPrism::CalculateSurfaceArea()
{
    return width*height*depth;
}

//Returns the shape's description as string.
string RectangularPrism::GetShapeDescription()
{
    //m_visibility is a boolean variable, we can not add it to string directly.
    string s_visibility;
    if(m_visibility==true)
        s_visibility = "true";
    else
        s_visibility = "false";
    
    string description =
    "RectangularPrism:\t"+m_color
    +"\nVisibility:\t"+s_visibility
    +"\nCenter of Mass:\t<"+to_string(m_centerofmass[0])+","+to_string(m_centerofmass[1])+","+to_string(m_centerofmass[2])
    +">\nWidth:\t"+to_string(width)
    +"\nHeight:\t"+to_string(height)
    +"\nDepth:\t"+to_string(depth)
    +"\nArea:\t"+to_string((*this).CalculateSurfaceArea())+"\n";

    return description;
}
