/*****************************************
 * CustomRectangleTestMain.cpp           *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 6: Operator Overloading    *
 *****************************************/

#include <iostream>                 //To use standart input and output functions like cin and cout.
#include "CustomRectangle.h"        //To know function prototypes of CustomRectangle.
using namespace std;                //Use cin and cout functions under the std namespace.

void TEST_Input (CustomRectangle& rect1)
{
    cout<< "+------------+" << endl
    << "| INPUT TEST |" << endl
    << "+------------+" << endl;
    
    //Takes inputs and they will be assigned to rect1's m_width and m_height.
    cin>>rect1;
}

void TEST_Output (CustomRectangle& rect1)
{
    cout<< "+-------------+" << endl
    << "| OUTPUT TEST |" << endl
    << "+-------------+" << endl;
    
    //Prints rect1's m_width and m_height.
    cout<<rect1<<endl;
}

void TEST_Addition(CustomRectangle& rect1, CustomRectangle& rect2)
{
    cout<< "+---------------+" << endl
    << "| ADDITION TEST |" << endl
    << "+---------------+" << endl;
    
    //Addition operator adds given rectangles, and returns final rectangle.
    //Returned rectangle is assigned to result the type of CustomRectangle.
    CustomRectangle result = rect1 + rect2;
    cout << rect1 << " + " << rect2 << " = " << result << endl;
}

void TEST_AdditionOver(CustomRectangle& rect1, CustomRectangle& rect2)
{
    cout<< "+--------------------+" << endl
    << "| ADDITION OVER TEST |" << endl
    << "+--------------------+" << endl;
    
    //Addition Over operator adds given rectangle to rectangle.
    cout << "Rectangle 1 Before Addition Over:\t" << rect1 << endl;
    rect1 += rect2;
    cout << "Rectangle 1 After Addition Over:\t" << rect1 << endl;
}

void TEST_Substraction(CustomRectangle& rect1, CustomRectangle& rect2)
{
    cout<< "+--------------------+" << endl
    << "|  SUBTRACTION TEST  |" << endl
    << "+--------------------+" << endl;
    
    //Subtraction operator subtracts given rectangle from rectangle.
    //Operator returns a rectangle the type of CustomRectangle, and it is assigned to result vector.
    CustomRectangle result = rect1 - rect2;
    cout << rect1 << " - " << rect2 << " = " << result << endl;
}

void TEST_SubstractionOver(CustomRectangle& rect1, CustomRectangle& rect2)
{
    cout<< "+-----------------------+" << endl
    << "| SUBTRACTION OVER TEST |" << endl
    << "+-----------------------+" << endl;
    
    //Subtraction Over operator subtracts given rectangle from rectangle.
    cout << "Rectangle 1 Before Subtraction over: " << rect1 << endl;
    rect1 -= rect2;
    cout << "Rectangle 1 After Subtraction over: " << rect1 << endl;
}

void TEST_Constant_Multiplication(CustomRectangle& rect1, double constant_value)
{
    cout<< "+-------------------------+" << endl
    << "| CONSTANT MULTIPLICATION |" << endl
    << "+-------------------------+" << endl;
    
    cout << "Rectangle Before Constant Multiplication:\t " << rect1 << endl;
    
    //Operator returns a rectangle the type of CustomRectangle, and it is assigned to result Rectangle.
    CustomRectangle result = rect1 * constant_value;
    cout << rect1 << " * " << constant_value << " = " << result << endl;
}

void TEST_Rectangle_Multiplication(CustomRectangle& rect1, CustomRectangle& rect2)
{
    cout<< "+---------------------------+" << endl
    << "| RECTANGLE MULTIPLICATION  |" << endl
    << "+---------------------------+" << endl;
    
    cout << "Rectangle Before Multiplication\t" << rect1 << endl;
    
    //Operator returns a rectangle the type of CustomRectangle, and it is assigned to result Rectangle.
    CustomRectangle result = rect1 * rect2;
    cout << rect1 << " * " << rect2 << " = " << result << endl;
}

void TEST_MultiplicationOver(CustomRectangle& rect1, CustomRectangle& rect2)
{
    cout<< "+-------------------------------+" << endl
    << "| RECTANGLE MULTIPLICATION OVER |" << endl
    << "+-------------------------------+" << endl;
    
    cout << "Rectangle Before Rectangle Multiplication Over: " << rect1 << endl;
    
    cout << rect1 << " *= " << rect2 << " = ";
    //Operator returns the object which called this operator. (CustomRectangle&)
    rect1 *= rect2;
    cout << rect1 << endl;
}


void TEST_Increment(CustomRectangle& rect1)
{
    cout<<"+-----------+"<<endl
    <<"| Increment |"<<endl
    <<"+-----------+"<<endl;
    
    cout<<"Rectangle before increment\t"<<rect1<<endl;
    
    //Rectangle's m_width and m_height will increase by one. (PREFIX FORM)
    ++rect1;
    cout<<"Rectangle after increment!\t"<<rect1<<endl;
}


void TEST_Decrement(CustomRectangle& rect1)
{
    cout<<"+-----------+"<<endl
    <<"| Decrement |"<<endl
    <<"+-----------+"<<endl;
    
    cout<<"Rectangle before decrement\t"<<rect1<<endl;
    //Rectangle's m_width and m_height will decrease by one. (PREFIX FORM)
    --rect1;
    cout<<"Rectangle after decrement!\t"<<rect1<<endl;
}


int main ()
{
    CustomRectangle rect1, rect2(3,4);
    
    TEST_Input(rect1);
    TEST_Output(rect1);
    TEST_Addition(rect1, rect2);
    TEST_AdditionOver(rect1, rect2);
    TEST_Substraction(rect1, rect2);
    TEST_SubstractionOver(rect1, rect2);
    TEST_Constant_Multiplication(rect1, 3.2);
    TEST_Rectangle_Multiplication(rect1, rect2);
    TEST_MultiplicationOver(rect1, rect2);
    TEST_Increment(rect1);
    TEST_Decrement(rect1);
    
    return 0;
}
