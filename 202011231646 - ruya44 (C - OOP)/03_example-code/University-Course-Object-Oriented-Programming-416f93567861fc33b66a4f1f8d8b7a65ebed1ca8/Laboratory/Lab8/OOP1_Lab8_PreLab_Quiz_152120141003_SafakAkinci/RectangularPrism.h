/*****************************************
 * RectangularPrism.h                    *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef RectangularPrism_h
#define RectangularPrism_h

#include "ThreeDShape.h"        //To derive RectangularPrism Class from ThreeDShape Class.

//RectangularPrism Class is derived from ThreeDShape Class as public.
class RectangularPrism:public ThreeDShape
{
    //Private variables ARE NOT ACCESSIBLE out of the class.
private:
    double width;
    double height;
    double depth;
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of RectangularPrism Class.
    RectangularPrism(double width, double height, double depth, double* centerofmass, string color ="Black", bool visibility =false);
    
    //Destructor Function of RectangularPrism Class.
    ~RectangularPrism();
    
    
    //Returns the rectangle prism's area.
    double CalculateSurfaceArea();
    
    //Returns the shape's description as string.
    string GetShapeDescription();
};

#endif /* RectangularPrism_h */
