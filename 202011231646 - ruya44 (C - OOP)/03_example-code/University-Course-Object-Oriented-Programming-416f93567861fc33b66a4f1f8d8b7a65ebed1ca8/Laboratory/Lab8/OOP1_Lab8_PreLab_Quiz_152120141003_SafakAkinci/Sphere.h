/*****************************************
 * Sphere.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef Sphere_h
#define Sphere_h

#include "ThreeDShape.h"            //To derive Sphere Class from ThreeDShape Class.

//Sphere Class is derived from ThreeDShape Class as public.
class Sphere:public ThreeDShape
{
    //Private variable IS NOT ACCESSIBLE out of the class.
private:
    double radius;
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of Sphere Class.
    Sphere(double radius, double* centerofmass, string color ="Black", bool visibility = false);
    
    //Destructor Function of Sphere Class.
    ~Sphere();
    
    //Returns the sphere's area.
    double CalculateSurfaceArea();
    
    //Returns the shape's description as string.
    string GetShapeDescription();
    
};

#endif /* Sphere_h */
