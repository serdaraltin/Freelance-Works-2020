/*****************************************
 * ThreeDShape.h                         *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/


#ifndef ThreeDShape_h
#define ThreeDShape_h

#include "Shape.h"      //To derive ThreeDShape Class from Shape Class.

//ThreeDShape is ABSTRACT CLASS because of the pure virtual functions.
class ThreeDShape:public Shape
{
    //Protected variables ARE ACCESSIBLE out of the class.
protected:
    double m_centerofmass[3];
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of TwoDShape Class.
    ThreeDShape(double* centerofmass, string color = "Black", bool visibility =false);
    
    //Virtual Destructor Function of ThreeDShape Class.
    virtual ~ThreeDShape();
    
    //Those are pure virtual functions, they will implement in derived classes.
    virtual double CalculateSurfaceArea() = 0;
    virtual string GetShapeDescription() = 0;
    
};

#endif /* ThreeDShape_h */
