/*****************************************
 * CustomRectangle.h                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 6: Operator Overloading    *
 *****************************************/

#include <iostream>                 //To use standart input and output functions like cin and cout.

//Use cin and cout functions under the std namespace.
//And also create an object from istream and ostream classes which are defined in std namespace.
using namespace std;

class CustomRectangle
{
    int m_width;                //mine_width
    int m_height;               //mine_height
    
public:
    //Constructor Function initializes private member values called m_width and m_height.
    CustomRectangle (int width =0, int height =0);
    
    //Destructor Function.
    ~CustomRectangle ();
    
    //Returns object's width (m_width)
    int getWidth ();
    //Returns object's height (m_height)
    int getHeight ();
    
    //Adds other's size with object's size and returns a CustomRectangle object.
    CustomRectangle operator+(const CustomRectangle& other);
    
    //Adds other's size to object's size, and returns this object. (CustomRectangle&)
    CustomRectangle& operator+=(const CustomRectangle& other);
    
    //Subtracts other's size from object's size and returns a CustomRectangle object.
    CustomRectangle operator-(const CustomRectangle& other);
    
    //Subtracts other's size from object's size, and returns this object. (CustomRectangle&)
    CustomRectangle& operator-=(const CustomRectangle& other);
    
    //Multiplies other's size with constantNumber and returns a CustomRectangle object.
    CustomRectangle operator*(int constantNumber);
    
    //Multiplies other's size with object's size and returns a CustomRectangle object.
    CustomRectangle operator*(const CustomRectangle& other);
    
    //Multiplies other's size with object's size, and returns this object. (CustomRectangle&)
    CustomRectangle& operator*=(const CustomRectangle& other);
    
    //Increment operator will increase the width and height by one. PREFIX FORM.
    CustomRectangle& operator++ ();
    
    //Decrement operator will decrease the width and height by one.
    CustomRectangle& operator-- ();
    
    //Prints rectangle's size. This function is class' friend, so function reach all members of this class.
    friend ostream& operator<<(ostream& out, const CustomRectangle& rectangle);
    
    //Takes inputs for rectangle. This function is class' friend, so function reach all members of this class.
    friend istream& operator>>(istream& in, CustomRectangle& rectangle);
};
