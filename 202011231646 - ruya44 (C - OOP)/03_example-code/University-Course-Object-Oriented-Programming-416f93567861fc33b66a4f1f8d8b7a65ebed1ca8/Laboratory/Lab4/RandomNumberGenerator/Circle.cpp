/*****************************************
 * Circle.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/

#include "Circle.h"             //To know function prototypes of Circle class.

//Constructor function of Circle class.
Circle::Circle()
{
    
}

//Destructor function of Circle class.
Circle::~Circle()
{
    
}

//Returns centerX (private member) as constant (doesn't change)
float Circle::getCenterX() const{
    return centerX;
}

//Returns centerY (private member) as constant (doesn't change)
float Circle::getCenterY() const{
    return centerY;
}

//Returns radius (private member) as constant (doesn't change)
double Circle::getRadius() const{
    return radius;
}

//Assigns given parameter (center_X) to object's private member centerX.
void Circle::setCenterX(float center_X){
    centerX = center_X;
}

//Assigns given parameter (center_Y) to object's private member centerY.
void Circle::setCenterY(float center_Y){
    centerY = center_Y;
}

//Assigns given parameter (rad) to object's private member radius.
void Circle::setRadius(double rad){
    radius = rad;
}
