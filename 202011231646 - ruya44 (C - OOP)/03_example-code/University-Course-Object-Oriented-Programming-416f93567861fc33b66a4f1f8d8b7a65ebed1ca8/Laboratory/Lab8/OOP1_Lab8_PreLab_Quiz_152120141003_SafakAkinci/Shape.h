/*****************************************
 * Shape.h                               *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef Shape_h
#define Shape_h

#include <iostream>         //To use standart input and output functions which are cin and cout. 
#include <string>           //To declare string type variables.
using namespace std;        //To use std namespace for string (std::string)


//Shape Class is an ABSTRACT CLASS because of the PURE VIRTUAL FUNCTIONS.
class Shape
{
    //Protected variables ARE ACCESSIBLE out of the class.
protected:
    string m_color;
    bool m_visibility;
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of Shape Class.
    Shape(string color ="Black", bool visibility =false);
    
    //Virtual Destructor Function of Shape Class.
    virtual ~Shape() =0;
    
    //Returns the shape's color as string.
    string getColor() const;
    
    //Returns the m_visibility as boolean.
    bool getVisibility() const;
    
    //Sets the m_color.
    void setColor(string color);
    
    //Sets the m_visibility.
    void setVisibility(bool visibility);
    
    
    //Those are pure virtual functions, they will implement in derived classes.
    virtual double CalculateSurfaceArea() = 0;
    virtual string GetShapeDescription() = 0;
    
};

#endif /* Shape_h */
