/*****************************************
 * TwoDShape.h                           *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef TwoDShape_h
#define TwoDShape_h

#include "Shape.h"      //To derive TwoDShape Class from Shape Class.

//TwoDShape is ABSTRACT CLASS because of the pure virtual functions.
class TwoDShape:public Shape
{
    //Protected variables ARE ACCESSIBLE out of the class.
    //Center of mass stands for
    //                          the center for circle,
    //                          the intersection point of diagonals for rectangle.
protected:
    double m_centerofmass[2];
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of TwoDShape Class.
    TwoDShape(double* centerofmass, string color ="Black", bool visibility =false);
    
    //Virtual Destructor Function of TwoDShape Class.
    virtual ~TwoDShape();
    
    
    //Those are pure virtual functions, they will implement in derived classes.
    virtual double CalculateSurfaceArea() = 0;
    virtual string GetShapeDescription() = 0;
};

#endif /* TwoDShape_h */
