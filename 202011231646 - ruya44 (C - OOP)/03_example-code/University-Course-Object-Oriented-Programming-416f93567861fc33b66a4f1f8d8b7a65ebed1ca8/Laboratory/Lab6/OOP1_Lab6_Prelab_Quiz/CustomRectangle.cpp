/*****************************************
 * CustomRectangle.cpp                   *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 6: Operator Overloading    *
 *****************************************/

#include "CustomRectangle.h"            //To know function prototypes of CustomRectangle class.
#include <iostream>                     //To use standart input and output functions (cin, cout).

//Constructor Function.
CustomRectangle::CustomRectangle (int width, int height):m_width(width),m_height(height)
{}

//Destructor Function.
CustomRectangle::~CustomRectangle()
{};

//Returns object's m_width.
int CustomRectangle::getWidth()
{
    return m_width;
}

//Returns object's m_height.
int CustomRectangle::getHeight()
{
    return m_height;
}

//Adds other's size with object's size and returns a CustomRectangle object called rect.
CustomRectangle CustomRectangle::operator+(const CustomRectangle& other)
{
    CustomRectangle rect;
    rect.m_width = m_width + other.m_width;
    rect.m_height = m_height + other.m_height;
    
    return rect;
}

//Adds other's size to object's size, and returns this object. (CustomRectangle&)
CustomRectangle& CustomRectangle::operator+=(const CustomRectangle& other)
{
    m_width += other.m_width;
    m_height += other.m_height;
    
    return (*this);
}

//Subtracts other's size from object's size and returns a CustomRectangle object called rect.
CustomRectangle CustomRectangle::operator-(const CustomRectangle &other)
{
    CustomRectangle rect;
    rect.m_width = m_width - other.m_width;
    rect.m_height = m_height - other.m_height;
    
    return rect;
}

//Subtracts other's size from object's size, and returns this object. (CustomRectangle&)
CustomRectangle& CustomRectangle::operator-=(const CustomRectangle &other)
{
    m_width -= other.m_width;
    m_height -= other.m_height;
    
    return (*this);
}

//Multiplies other's size with object's size and returns a CustomRectangle object.
CustomRectangle CustomRectangle::operator*(const CustomRectangle &other)
{
    CustomRectangle rect;
    rect.m_width = m_width * other.m_width;
    rect.m_height = m_height * other.m_height;
    
    return rect;
}

//Multiplies other's size with constantNumber and returns a CustomRectangle object.
CustomRectangle CustomRectangle::operator*(int constantNumber)
{
    CustomRectangle rect;
    rect.m_width = m_width * constantNumber;
    rect.m_height = m_height * constantNumber;
    
    return rect;
}

//Multiplies other's size with object's size, and returns this object. (CustomRectangle&)
CustomRectangle& CustomRectangle::operator*=(const CustomRectangle &other)
{
    m_width *= other.m_width;
    m_height *= other.m_height;
    
    return (*this);
}

//Increment operator will increase the width and height by one. Prefix Form.
CustomRectangle& CustomRectangle::operator++()
{
    ++m_width;
    ++m_height;
    
    return (*this);
}

//Decrement operator will decrease the width and height by one.
CustomRectangle& CustomRectangle::operator--()
{
    --m_width;
    --m_height;
    
    return (*this);
}

//Prints rectangle's size. This function is class' friend, so function reach all members of this class.
ostream& operator<<(ostream& out, const CustomRectangle& rectangle)
{
    out<<"["<<rectangle.m_width<<"\t"<<rectangle.m_height<<"]";
    
    //Returns ostream&
    return out;                 //Enables cascading.
}

//Takes inputs for rectangle. This function is class' friend, so function reach all members of this class.
istream& operator>>(istream& in, CustomRectangle& rectangle)
{
    in>>rectangle.m_width;
    in>>rectangle.m_height;
    
    //Returns istream&
    return in;                  //Enables cascading.
}
