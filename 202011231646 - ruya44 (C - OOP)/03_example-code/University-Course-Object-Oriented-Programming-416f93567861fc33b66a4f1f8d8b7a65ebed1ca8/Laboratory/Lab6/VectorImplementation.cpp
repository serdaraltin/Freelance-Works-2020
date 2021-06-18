/*****************************************
 * VectorImplementation.cpp              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 6: Operator Overloading    *
 *****************************************/

#include <iostream>                 //To use standart input and output functions like cin and cout.
#include <math.h>                   //To use pow() and sqrt() functions!
#include "VectorImplementation.h"   //To know function prototypes of Vector class.

//Use cin and cout functions under the std namespace.
//And also create an object from istream and ostream classes which are defined in std namespace.
using namespace std;

//Default parameter constructor.
//m_dimension is initialized by using member initializer :
Vector::Vector(int dimension):m_dimension(dimension)
{
    //Memory is allocated for object.
    m_data = new double [m_dimension];
}

//Overloaded constructor with a double array and dimension parameter.
Vector::Vector(double data[], int dimension):m_dimension(dimension)
{
    //Memory is allocated for object.
    m_data = new double [dimension];
    
    //data's elements are assigned to m_data's element of vector.
    for(int i=0; i<m_dimension; i++)
        m_data[i]= data[i];
}

//Copy constructor, it takes one constant parameter of its kind as reference.
Vector::Vector(const Vector& copyVector):m_dimension(copyVector.m_dimension)
{
    //m_data is a pointer the type of double, and each object should be its own array.
    m_data = new double[m_dimension];
    
    //copyVector's data is assigned to vector's data.
    for(int i=0; i<m_dimension; i++)
        m_data[i]= copyVector.m_data[i];
    
}

//Destructor function of Vector class.
//Free the data array to handle the memory leak.
Vector::~Vector()
{
    delete[] m_data;
}

//Returns the dimension of the vector.
int Vector::getDimension()
{
    return m_dimension;
}

//Takes inputs for vector. This function is class' friend, so function reach all members of this class.
istream& operator>>(istream& in, Vector& vec)
{
    for(int i=0; i<vec.m_dimension; i++)
        in>>vec[i];
    
    //Returns istream&
    return in;              //Enables cascading.
}

//Prints vector's data. This function is class' friend, so function reach all members of this class.
ostream& operator<<(ostream& os, Vector& vec)
{
    cout<<"[ ";
    for(int i=0; i<vec.m_dimension-1; i++)
        os<<"\t"<<vec.m_data[i]<<",";
    
    cout<<"\t"<<vec.m_data[vec.m_dimension-1]<<"]";
    
    //Returns ostream&
    return os;              //Enables cascading.
}

//Copies the given vector in the argument.
const Vector& Vector::operator= (const Vector& copyVector)
{
    //Avoids self assignment for vectors of different sizes, deallocate original left-side vector.
    if (&copyVector != this)
    {
        //then allocate new left-side vector.
        if(m_dimension != copyVector.m_dimension)
        {
            delete [] m_data;                               //release space
            m_dimension = copyVector.m_dimension;           //resize this object
            m_data = new double [m_dimension];              //create space for array copy
        }
        
        for(int i=0; i<m_dimension; i++)
            m_data[i] = copyVector.m_data[i];
        
    }//end if
    
    //Returns this object (vector) as constant (const Vector&).
    return *this;
}

//Return true, if the vectors are equal.
bool Vector::operator== (const Vector& secondOperand)
{
    if(m_dimension != secondOperand.m_dimension)
        return false;                               //Arrays' sizes are not equal!
    
    for(int i=0; i<m_dimension; i++)
        if(m_data[i]!= secondOperand.m_data[i])
            return false;                           //Arrays' contents are not equal!
    
    return true;                                    //Arrays are equal.
}

//Returns true if the vectors are not equal.
//REVERSE FUNCTION OF ==.
bool Vector::operator!= (const Vector& secondOperand)
{
    return !( (*this) == secondOperand);
    /*
     if(m_dimension != secondOperand.m_dimension)            //Arrray's sizes are not equal, they can not be equal.
     return true;
     
     for(int i=0; i<m_dimension; i++)
     if(m_data[i] == secondOperand.m_data[i])
     return false;
     
     return true;
     */
}

//Decides according to the magnitude of the vectors.
bool Vector::operator<(const Vector& secondOperand)
{
    double magnitudeFirstVector  = (*this)();
    
    //secondOperand is constant vector, operator() cannot be called for it.
    double magnitudeSecondVector = 0;
    for(int i=0; i<secondOperand.m_dimension; i++)
        magnitudeSecondVector += pow(secondOperand.m_data[i],2);
    
    magnitudeSecondVector = sqrt(magnitudeSecondVector);
    
    if(magnitudeFirstVector < magnitudeSecondVector)
        return true;
    
    return false;
}

//Decides according to the magnitude of the vectors.
//REVERSE FUNCTION OF <
bool Vector::operator>=(const Vector& secondOperand)
{
    return !( (*this)<secondOperand );
}

//Decides according to the magnitude of the vectors.
bool Vector::operator>(const Vector& secondOperand)
{
    double magnitudeFirstVector=0;
    for(int i=0; i<m_dimension; i++)
        magnitudeFirstVector += pow(m_data[i],2);
    
    magnitudeFirstVector = sqrt(magnitudeFirstVector);
    
    double magnitudeSecondVector=0;
    for(int i=0; i<secondOperand.m_dimension; i++)
        magnitudeSecondVector += pow(secondOperand.m_data[i],2);
    
    magnitudeSecondVector = sqrt(magnitudeSecondVector);
    
    if(magnitudeFirstVector > magnitudeSecondVector)
        return true;
    
    return false;
}

//Decides according to the magnitude of the vectors.
//REVERSE FUNCTION OF >
bool Vector::operator<=(const Vector& secondOperand)
{
    return !( (*this)>secondOperand );
}

//Returns the vector element according to the given index and it works for non-const objects.
double& Vector::operator[] (int index)
{
    if(index>=0 ||index < m_dimension)
        return m_data[index];
    
    cout<<"You tried to reach an element that is out of the vector!\n";
    return m_data[0];
}

//Returns the vector element according to the given index and it works for const objects.
const double& Vector::operator[](int index) const
{
    if(index>=0 || index < m_dimension)
        return m_data[index];
    
    cout<<"You tried to reach an element that is out of the vector!\n";
    return m_data[0];
}

//Adds two vectors and returns a Vector object.
Vector Vector::operator+ (const Vector& secondOperand)
{
    Vector result;
    
    for(int i=0; i<m_dimension; i++)
        result.m_data[i]= m_data[i]+ secondOperand.m_data[i];
    
    return result;
}

//Adds secondOperand's data to object, and returns this object. (Vector&)
Vector& Vector::operator+= (const Vector& secondOperand)
{
    for(int i=0; i<m_dimension; i++)
        m_data[i] += secondOperand.m_data[i];
    
    return (*this);
}

//Subtracts two vectors and returns a Vector object.
Vector Vector::operator- (const Vector& secondOperand)
{
    Vector result;
    
    for(int i=0; i<m_dimension; i++)
        result.m_data[i] = m_data[i]- secondOperand.m_data[i];
    
    return result;
}

//Subtracts secondOperand's data from object, and returns this object. (Vector&)
Vector& Vector::operator-= (const Vector& secondOperand)
{
    for(int i=0; i<m_dimension; i++)
        m_data[i] -= secondOperand.m_data[i];
    
    return (*this);
}

//Dot Product.Multiplies each element of object with secondOperand's element and adds them.
double Vector::operator* (const Vector& secondOperand)
{
    double result=0;
    
    for(int i=0; i<m_dimension; i++)
        result += m_data[i] * secondOperand.m_data[i];
    
    return result;
}

//Multiples object's data with multiplier, and returns a Vector object.
Vector Vector::operator* (const double multiplier)
{
    Vector result;
    
    for(int i=0; i<m_dimension; i++)
        result.m_data[i]= m_data[i]* multiplier;
    
    return result;
}

//Multiplies secondOperand's data with object's data, and returns this object. (Vector&)
Vector& Vector::operator*= (const double multiplier)
{
    for(int i=0; i<m_dimension; i++)
        m_data[i]*= multiplier;
    
    return (*this);
}

//Divides object's data to secondOperand's data, and returns a Vector object.
Vector Vector::operator/ (const Vector& secondOperand)
{
    Vector result;
    
    for(int i=0; i<m_dimension; i++)
        result.m_data[i]= m_data[i]/ secondOperand.m_data[i];
    
    return result;
}

//Divides object's data to secondOperand's data, and returns this object. (Vector&)
Vector& Vector::operator/= (const Vector& secondOperand)
{
    for(int i=0; i<m_dimension; i++)
        m_data[i] /= secondOperand.m_data[i];
    
    return (*this);
}

//Divides object's data to divider, and returns a Vector object.
Vector Vector::operator/ (const double divider)
{
    Vector result;
    
    for(int i=0; i<m_dimension; i++)
        result.m_data[i]= m_data[i]/ divider;
    
    return result;
}

//Divides object's data to divider, and returns this object. (Vector&)
Vector& Vector::operator/= (const double divider)
{
    for(int i=0; i<m_dimension; i++)
        m_data[i] /= divider;
    
    return (*this);
}

//Calculates object's magnitude.
double Vector::operator() ()
{
    double result = 0;
    
    for(int i=0; i<m_dimension; i++)
        result += pow(m_data[i],2);
    
    return sqrt(result);
}

//Multiply object with -1.
Vector& Vector::operator! ()
{
    return  (*this)*=-1;
}
