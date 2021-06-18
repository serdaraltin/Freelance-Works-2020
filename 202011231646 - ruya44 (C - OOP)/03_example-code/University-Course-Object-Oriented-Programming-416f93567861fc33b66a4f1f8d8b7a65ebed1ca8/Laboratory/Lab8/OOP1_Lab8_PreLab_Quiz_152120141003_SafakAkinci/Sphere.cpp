/*****************************************
 * Sphere.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Sphere.h"         //To know function prototypes of Sphere Class.

//Constructor Function of Sphere Class.
//Sphere Class is derived from ThreeDShape Class, so ThreeDShape Class' Constructor should be called.
Sphere::Sphere(double radius, double* centerofmass, string color, bool visibility):ThreeDShape(centerofmass,color,visibility),radius(radius)
{
    
}

//Destructor Function of Sphere Class.
Sphere::~Sphere()
{
    
}

//Returns the sphere's area.
double Sphere::CalculateSurfaceArea()
{
    return 4*3.14*radius*radius;
}

//Returns the shape's description as string.
string Sphere::GetShapeDescription()
{
    //m_visibility is a boolean variable, we can not add it to string directly.
    string s_visibility;
    if(m_visibility==true)
        s_visibility = "true";
    else
        s_visibility = "false";
    
    string description =
    "Sphere:\t"+m_color
    +"\nVisibility:\t"+s_visibility
    +"\nCenter of Mass:\t<"+to_string(m_centerofmass[0])+","+to_string(m_centerofmass[1])+","+to_string(m_centerofmass[2])
    +">\nRadius:\t"+to_string(radius)
    +"\nArea:\t"+to_string((*this).CalculateSurfaceArea())+"\n";
    
    
    return description;
}
