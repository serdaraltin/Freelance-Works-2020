/*****************************************
 * Shape.cpp                             *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Shape.h"          //To know function prototypes of Shape Class.

//Constructor Function of Shape Class.
Shape::Shape(string color, bool visibility):m_color(color),m_visibility(visibility)
{
    
}

//Virtual Destructor Function of Shape Class.
Shape::~Shape()
{
    
}

//Returns the shape's color as string.
string Shape::getColor() const
{
    return m_color;
}

//Returns the m_visibility as boolean.
bool Shape::getVisibility() const
{
    return m_visibility;
}

//Sets the m_color.
void Shape::setColor(string color)
{
    m_color = color;
}

//Sets the m_visibility.
void Shape::setVisibility(bool visibility)
{
    m_visibility = visibility;
}
