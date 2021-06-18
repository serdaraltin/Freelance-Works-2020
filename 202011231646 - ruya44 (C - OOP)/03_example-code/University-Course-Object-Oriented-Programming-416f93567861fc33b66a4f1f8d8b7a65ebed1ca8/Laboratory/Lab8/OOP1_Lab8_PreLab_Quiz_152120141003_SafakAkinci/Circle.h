/*****************************************
 * Circle.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef Circle_h
#define Circle_h

#include "TwoDShape.h"          //To derive Circle Class from TwoDShape Class.

//Circle class is derived from TwoDShape Class.
class Circle:public TwoDShape
{
    //Private variables ARE NOT ACCESSIBLE out of the class.
private:
    double radius;
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of Circle Class.
    Circle(double radius, double* centerofmass, string color ="Black", bool visibility =false);
    
    //Destructor Function of Circle Class.
    ~Circle();
    
    //Returns the circle's area.
    double CalculateSurfaceArea();
    
    //Returns the shape's description as string.
    string GetShapeDescription();
};

#endif /* Circle_h */
