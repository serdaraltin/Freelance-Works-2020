/*****************************************
 * CustomRectangle.h                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef CustomRectangle_h
#define CustomRectangle_h

#include "TwoDShape.h"          //To derive CustomRectangle Class from TwoDShape Class.

//CustomRectangle Class is derived from TwoDShape Class as public.
class CustomRectangle:public TwoDShape
{
    //Private variables ARE NOT ACCESSIBLE out of the class.
private:
    double width;
    double height;
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of CustomRectangle Class.
    CustomRectangle(double width, double height, double* centerofmass, string ="Black", bool visibility =false);
    
    //Destructor Function of CustomRectangle Class.
    ~CustomRectangle();
    
    //Returns the rectangle's area.
    double CalculateSurfaceArea();
    
    //Returns the shape's description as string.
    string GetShapeDescription();
};

#endif /* CustomRectangle_h */
