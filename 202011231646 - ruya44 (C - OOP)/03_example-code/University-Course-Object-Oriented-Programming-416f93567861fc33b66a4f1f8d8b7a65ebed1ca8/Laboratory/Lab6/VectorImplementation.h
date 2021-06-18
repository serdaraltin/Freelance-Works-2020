/*****************************************
 * VectorImplementation.h                *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 6: Operator Overloading    *
 *****************************************/

#include <iostream>             //To use standart input and output functions (cin and cout).

//Vector class that represents a mathematical vector.
class Vector
{
public:
    //Default parameter constructor.
    Vector(int dimension = 3);
    
    //Overloaded constructor with a double array and dimension parameter.
    Vector(double data[], int dimension);
    
    //Copy constructor, it takes one constant parameter of its kind as reference.
    Vector(const Vector& copyVector);
    
    //Destructor. Free the data array to handle the memory leak.
    ~Vector();
    
    //Returns the dimension of the vector.
    int getDimension();
    
    //Copies the given vector in the argument.
    //Returns this object (vector) as constant (const Vector&).
    const Vector& operator= (const Vector& copyVector);
    
    //Take inputs for vector. This function is class' friend, so function reach all members of this class.
    friend std::istream& operator>>(std::istream&, Vector&);
    
    //Print vector's data. This function is class' friend, so function reach all members of this class.
    friend std::ostream& operator<<(std::ostream&, Vector&);
    
    //Return true, if the vectors are equal.
    bool operator== (const Vector& secondOperand);
    
    //Returns true, if the vectors are not equal.               REVERSE FUNCTION OF ==.
    bool operator!= (const Vector& secondOperand);
    
    //Decides according to the magnitude of the vectors.
    bool operator< (const Vector& secondOperand);
    
    //Decides according to the magnitude of the vectors.        REVERSE FUNCTION OF <
    bool operator>= (const Vector& secondOperand);
    
    //Decides according to the magnitude of the vectors.
    bool operator> (const Vector& secondOperand);
    
    //Decides according to the magnitude of the vectors.        REVERSE FUNCTION OF >
    bool operator<= (const Vector& secondOperand);
    
    //Returns the vector element according to the given index and it works for non-const objects.
    double& operator[] (int index);

    //Returns the vector element according to the given index and it works for const objects.
    const double& operator[](int index) const;
    
    //Adds two vectors and returns a Vector object.
    Vector operator+ (const Vector& secondOperand);
    
    //Adds secondOperand's data to object, and returns this object. (Vector&)
    Vector& operator+= (const Vector& secondOperand);
    
    //Subtracts two vectors and returns a Vector object.
    Vector operator- (const Vector& secondOperand);
    
    //Subtracts secondOperand's data from object, and returns this object. (Vector&)
    Vector& operator-= (const Vector& secondOperand);
    
    //Dot Product. Multiplies each element of object with secondOperand's element and adds them.
    double operator* (const Vector& secondOperand);
    
    //Multiples object's data with multiplier, and returns a Vector object.
    Vector operator* (const double multiplier);
    
    //Multiplies secondOperand's data with object's data, and returns this object. (Vector&)
    Vector& operator*= (const double multiplier);
    
    //Divides object's data to secondOperand's data, and returns a Vector object.
    Vector operator/ (const Vector& secondOperand);
    
    //Divides object's data to secondOperand's data, and returns this object. (Vector&)
    Vector& operator/= (const Vector& secondOperand);
    
    //Divides object's data to divider, and returns a Vector object.
    Vector operator/ (const double divider);
    
    //Divides object's data to divider, and returns this object. (Vector&)
    Vector& operator/= (const double divider);
    
    //Calculates object's magnitude.
    double operator() ();
    
    //Multiply object with -1.
    Vector& operator! ();

private:
    double* m_data;             //A double array to keep the raw data.
    int m_dimension;            //Size of the vector.
};
