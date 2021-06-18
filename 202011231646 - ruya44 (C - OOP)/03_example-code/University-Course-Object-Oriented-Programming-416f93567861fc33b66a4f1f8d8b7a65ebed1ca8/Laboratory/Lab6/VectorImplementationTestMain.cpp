/*****************************************
 * VectorImplementationTestMain.cpp      *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 6: Operator Overloading    *
 *****************************************/

#include <iostream>                 //To use standart input and output functions like cin and cout.
#include "VectorImplementation.h"   //To know function prototypes of Vector class.
using namespace std;                //Use cin and cout functions under the std namespace.


void TEST_Input (Vector& vector)
{
    cout<< "+------------+" << endl
    << "| INPUT TEST |" << endl
    << "+------------+" << endl;
    
    //Takes inputs and they will be assigned to vector's m_data.
    cin>>vector;
}

void TEST_Output (Vector& vector)
{
    cout<< "+-------------+" << endl
    << "| OUTPUT TEST |" << endl
    << "+-------------+" << endl;
    
    //Prints vector's m_data to the console.
    cout<<vector<<endl;
}

void TEST_CopyConstructor(Vector& vector)
{
    cout<< "+-----------------------+" << endl
    << "| COPY CONSTRUCTOR TEST |" << endl
    << "+-----------------------+" << endl;
    
    //copy_vector is created as vector's copy. (Same dimension, Same data.)
    Vector copy_vector(vector);
    
    cout << "Original Vector : " <<vector<< endl<< "Copy Vector : "<<copy_vector << endl;
}

void TEST_Assignment(Vector& vector)
{
    cout<< "+-----------------+" << endl
    << "| ASSIGNMENT TEST |" << endl
    << "+-----------------+" << endl;
    
    //copy_vector is created, default constructor is called for it. (m_dimension = 3)
    Vector copy_vector;
    
    //vector's members are assigned to copy_vector.
    copy_vector = vector;
    
    cout << "Original Vector : " << vector << endl << "Assignment Copy Vector : " << copy_vector << endl;
}

void TEST_Equal(Vector& vector1, Vector& vector2)
{
    cout<< "+------------+" << endl
    << "| EQUAL TEST |" << endl
    << "+------------+" << endl;
    
    //Checks vectors are equal.
    if (vector1 == vector2)
        cout << vector1 << " is equal to " << vector2 << endl;
    else
        cout << vector1 << " is not equal to " << vector2 << endl;
}

void TEST_Not_Equal(Vector& vector1, Vector& vector2)
{
    cout<< "+----------------+" << endl
    << "| NOT EQUAL TEST |" << endl
    << "+----------------+" << endl;
    
    //Checks vector are not equal.
    if(vector1 != vector2)
        cout << vector1 << " is not equal to " << vector2 << endl;
    else
        cout << vector1 << " is equal to " << vector2 << endl;
    
}

void TEST_LESS_THAN(Vector& vector1, Vector& vector2)
{
    
    cout<< "+----------------+" << endl
    << "| LESS THAN TEST |" << endl
    << "+----------------+" << endl;
    
    //Checks the left-hand side vectors is less than the other or not.
    if (vector1 < vector2)
        cout << vector1 << " is less than " << vector2 << endl;
    else
        cout << vector1 << " is not less than " << vector2 << endl;
    
}

void TEST_LESS_THAN_OR_EQUAL(Vector& vector1, Vector& vector2)
{
    cout<< "+-------------------------+" << endl
    << "| LESS THAN OR EQUAL TEST |" << endl
    << "+-------------------------+" << endl;
    
    //Checks the left-hand side vectors is less than or equal to the other or not.
    if (vector1 <= vector2)
        cout << vector1 << " is less than or equal to " << vector2 << endl;
    else
        cout << vector1 << " is not less than or equal to" << vector2 << endl;
    
}

void TEST_GREATER_THAN(Vector& vector1, Vector& vector2)
{
    cout<< "+--------------------+" << endl
    << "| GREATER THAN  TEST |" << endl
    << "+--------------------+" << endl;
    
    //Checks the left-hand side vectors is greater than the other or not.
    if (vector1 > vector2)
        cout << vector1 << " is greater than " << vector2 << endl;
    else
        cout << vector1 << " is not greater than " << vector2 << endl;
}

void TEST_GREATER_THAN_OR_EQUAL(Vector& vector1, Vector& vector2)
{
    cout<< "+----------------------------+" << endl
    << "| GREATER THAN OR EQUAL TEST |" << endl
    << "+----------------------------+" << endl;
    
    //Checks the left-hand side vectors is greater than or equal than the other or not.
    if (vector1 >= vector2)
        cout << vector1 << " is greater than or equal to " << vector2 << endl;
    else
        cout << vector1 << " is not greater than or equal to " << vector2 << endl;
}

void TEST_Subscription(Vector& vector, int i, double newValue)
{
    cout<< "+-------------------+" << endl
    << "| SUBSCRIPTION TEST |" << endl
    << "+-------------------+" << endl;
    
    cout << "Vector itself : " << vector << endl;
    cout << "Get vector[" << i << "] = " << vector[i] << endl;
    
    //newValue is assigned to vector's i th element.
    vector[i] = newValue;
    cout << "Set vector[" << i << "] to "<<newValue<<", then vector[" << i << "] =" << vector[i] << endl;
}

void TEST_Addition(Vector& vector1, Vector& vector2)
{
    cout<< "+---------------+" << endl
    << "| ADDITION TEST |" << endl
    << "+---------------+" << endl;
    
    //Addition operator adds given vectors, and returns final vector. Returned vector is assigned to result the type of vector.
    Vector result = vector1 + vector2;
    cout << vector1 << " + " << vector2 << " = " << result << endl;
}

void TEST_AdditionOver(Vector vector1, Vector vector2)
{
    cout<< "+--------------------+" << endl
    << "| ADDITION OVER TEST |" << endl
    << "+--------------------+" << endl;
    //Addition Over operator adds vector2 to vector1, and returns vector1.
    cout << "Vector 1 Before Addition over: " << vector1 << endl; vector1 += vector2;
    cout << "Vector 1 After Addition over: " << vector1 << endl;
}

void TEST_Substraction(Vector& vector1, Vector& vector2)
{
    cout<< "+--------------------+" << endl
    << "|  SUBTRACTION TEST  |" << endl
    << "+--------------------+" << endl;
    
    //Subtraction operator subtracts given vectors, and returns final vector. Returned vector is assigned to result the type of vector.
    Vector result = vector1 - vector2;
    cout << vector1 << " - " << vector2 << " = " << result << endl;
}

void TEST_SubstractionOver(Vector vector1, Vector vector2)
{
    cout<< "+-----------------------+" << endl
    << "| SUBTRACTION OVER TEST |" << endl
    << "+-----------------------+" << endl;
    //Subtraction Over operator subtracts vector2 from vector1, and returns vector1.
    cout << "Vector 1 Before Subtraction over: " << vector1 << endl; vector1 -= vector2;
    cout << "Vector 1 After Subtraction over: " << vector1 << endl;
}

void TEST_DotProduct(Vector& vector1, Vector& vector2)
{
    cout<< "+------------------+" << endl
    << "| DOT PRODUCT TEST |" << endl
    << "+------------------+" << endl;
    
    //Each element of vector1 and vector2 will multiply each other and add, the final result is called DOT PRODUCT.
    cout << vector1 << " - " << vector2 << " = " << vector1*vector2 <<endl;
}

void TEST_Constant_Multiplication(Vector& vector1, double constant_value)
{
    cout<< "+------------------------------+" << endl
    << "| CONSTANT MULTIPLICATION TEST |" << endl
    << "+------------------------------+" << endl;
    
    //vector1's elements will multiply with constant_value and this operator returns a vector, it is assigned to result (Vector).
    Vector result = vector1*constant_value;
    cout << vector1 << " * " << constant_value << " = " << result << endl;
}

void TEST_Constant_MultiplicationOver(Vector vector, double constant_value)
{
    cout<< "+-----------------------------+" << endl
    << "| CONSTANT MULTIPLICATIN OVER |" << endl
    << "+-----------------------------+" << endl;
    
    cout << "Vector Before Constant Multiplication over: " << vector << endl;
    //Multiplication Over operator multiply vector with constant_value and operator returns this vector.
    vector *= constant_value;
    cout << "Vector After Constant Multiplication over: " << vector << endl;
}

void TEST_Division(Vector& vector1, Vector& vector2)
{
    cout<< "+---------------+" << endl
    << "| DIVISION TEST |" << endl
    << "+---------------+" << endl;
    
    //vector1's data will divide to vector2's data and Division operator returns a vector, returned vector will assign to result (Vector).
    Vector result = vector1/vector2;
    cout << vector1 << " / " << vector2 << " = " << result << endl;
}

void TEST_DivisionOver(Vector vector1, Vector vector2)
{
    cout<< "+--------------------+" << endl
    << "| DIVISION OVER TEST |" << endl
    << "+--------------------+" << endl;
    
    cout << "Vector 1 Before Division over: " << vector1 << endl;
    //Division Over operator divides vector1 to vector2 and operator returns this vector.
    vector1 /= vector2;
    cout << "Vector 1 After Division over: " << vector1 << endl;
}

void TEST_Constant_Division(Vector& vector1, double constant_value)
{
    cout<< "+------------------------+" << endl
    << "| CONSTANT DIVISION TEST |" << endl
    << "+------------------------+" << endl;
    
    //Division operator divides vector to constant_value and operator returns a vector, returned vector will assign to result (Vector).
    Vector result = vector1 / constant_value;
    cout << vector1 << " / " << constant_value << " = " << result << endl;
    
}

void TEST_Constant_DivisionOver(Vector vector, double constant_value)
{
    cout<< "+-----------------------------+" << endl
    << "| CONSTANT DIVISION OVER TEST |" << endl
    << "+-----------------------------+" << endl;
    
    cout << "Vector Before Constant Division over: " << vector << endl;
    
    //Division Over operator divides vector1 to constant_value and operator returns this vector.
    vector /= constant_value;
    cout << "Vector After Constant Division over: " << vector << endl;
    
}

void TEST_Magnitude(Vector& vector1)
{
    cout<< "+----------------+" << endl
    << "| MAGNITUDE TEST |" << endl
    << "+----------------+" << endl;
    //operator() will calculate the vector1's magnitude, and operator returns the result.
    double result = vector1();
    cout << "MAG( " << vector1 << " ) = " << result << endl;
}

void TEST_InverseDirection(Vector vector)
{
    cout<< "+-------------------+" << endl
    << "| INVERSE DIRECTION |" << endl
    << "+-------------------+" << endl;
    
    //operator! will multiply the vector with -1.
    cout << "Original Vector: " << vector << endl;
    cout << "Inversed Vector: " << !vector << endl;
}

int main ()
{
    double firstTestData[] {1.2, 2.4, 3.6};
    double secondTestData[] {1.8, 2.6, 3.4};
    
    Vector v1(3);
    Vector v2(firstTestData, 3);
    Vector v3(firstTestData, 3);
    Vector v4(secondTestData, 3);
    
    TEST_Input(v1);
    TEST_Output(v1);
    TEST_CopyConstructor(v1);
    TEST_Assignment(v1);
    TEST_Equal(v2, v3);
    TEST_Not_Equal(v3, v4);
    TEST_LESS_THAN(v1, v2);
    TEST_LESS_THAN_OR_EQUAL(v2, v3);
    TEST_GREATER_THAN(v1, v2);
    TEST_GREATER_THAN_OR_EQUAL(v2, v3);
    TEST_Subscription(v1, 1, 5.3);
    TEST_Addition(v1, v2);
    TEST_AdditionOver(v1, v2);
    TEST_Substraction(v1, v2);
    TEST_SubstractionOver(v1, v2);
    TEST_DotProduct(v1, v2);
    TEST_Constant_Multiplication(v1, 2);
    TEST_Constant_MultiplicationOver(v1, 2);
    TEST_Division(v1, v2);
    TEST_DivisionOver(v1, v2);
    TEST_Constant_Division(v1, 2);
    TEST_Constant_DivisionOver(v1, 2);
    TEST_Magnitude(v1);
    TEST_InverseDirection(v1);
    
    return 0;
}
