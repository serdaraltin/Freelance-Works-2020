/*****************************************
 * MatrixTestApp.cpp                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 3: Class vs Struct         *
 *****************************************/

#include "Matrix.h"                     //Adding Matrix.h header file that include function prototypes.
#include <iostream>                     //To use standart input output functions.
#include <string>                       //To create string variable.
#include <iomanip>                      //To use setw() function but didn't use.
#include <math.h>
using namespace std;                    //To don't write for each code std::   (e.x. std::cout)

//  Prints +----+ according to the length.
void PrintFrameLine(int length);

//  Prints the message to console.
void PrintMessageInFrame(const string& message);

//  Creates two-dimensional array and fills it with random numbers.
float** GetRandomData(int row, int column);

void TEST_FILL_BY_VALUE();
void TEST_FILL_BY_DATA();
void TEST_ADDITION();
void TEST_SUBSTRUCTION();
void TEST_MULTIPLICATION_MATRIX();
void TEST_MULTIPLICATION_CONSTANT();
void TEST_DIVISION();
void TEST_TRANSPOSE();
void TEST_ROW_MODULE();
void TEST_COLUMN_MODULE();

Matrix A,X;
class point {
public:
    int x,y;
    int ROW;
    point (int r):ROW(r){};
    
    void AssignToMatrix()
    {
        for(int col=0, row=ROW; col<3; col++)
        {
            if(col==0)                              //a
                A.data[row][col] = 2*x;
            else if(col==1)                         //b
                A.data[row][col] = 2*y;
            else                                    //Z     (a^2 + b^2 - r^2)
                A.data[row][col] = 1;
        }
        
        X.data[ROW][0] = -(x*x + y*y);
    }
};

int main() {
    A.Allocate(3, 3);
    X.Allocate(3, 1);
    point p0(0),p1(1),p2(2);
    char comma;
    
    cout<<"Please, enter first point!\n";
    cin>>p0.x>>comma>>p0.y;
    p0.AssignToMatrix();
    cout<<"Please, enter second point!\n";
    cin>>p1.x>>comma>>p1.y;
    p1.AssignToMatrix();
    cout<<"Please, enter third point!\n";
    cin>>p2.x>>comma>>p2.y;
    p2.AssignToMatrix();
    
    PrintMessageInFrame("Matrix A");
    A.Display();
    
    PrintMessageInFrame("Matrix X");
    X.Display();
    
    PrintMessageInFrame("Inverse Matrix");
    A.Inverse().Display();
    
    PrintMessageInFrame("Result Matrix");
    A.Inverse().Multiplication(X).Display();
    
    float a, b, z;
    float r;
    a = A.Inverse().Multiplication(X).data[0][0];
    b = A.Inverse().Multiplication(X).data[1][0];
    z = A.Inverse().Multiplication(X).data[2][0];
    if(a== -0)
        a = 0;
    
    if(b== -0)
        b = 0;
    
    if(z== -0)
        z = 0;
    
    r = sqrt(a*a + b*b + -1*z);
    cout<<"Origin's x:\t"<<a<<endl;
    cout<<"Origin's y:\t"<<b<<endl;
    cout<<"Circle's radius:\t"<<r<<endl;
        
    return 0;
}//end main ()

// Takes one integer parameter called length(message.length) and prints +----+ according to it.
void PrintFrameLine(int length){
    cout << "+";
    length -= 2;
    for (int i = 0; i < length; i++)
    {
        cout << "-";
    }
    
    cout << "+" << endl;
}//end PrintFrameLine ()

// Takes one const string reference called message and prints it to console.
void PrintMessageInFrame(const string& message)
{
    //  Added (unsigned int) in front of the message.length() function to get integer (lost precision).
    PrintFrameLine((unsigned)message.length() + 4);
    cout << "| " << message << " |" << endl;
    PrintFrameLine(message.length() + 4);
    //If we don't add (unsigned int) in front of the message.length() function Xcode warns the developer with
    //  " Implicit conversion loses integer precision: 'unsigned long' to 'int' ".
    
}//end PrintMessageInFrame ()

// Takes two integer parameters and creates two-dimensional array and returns it.
float** GetRandomData(int row, int column){
    
    //  row times elements that all of them are float(float*) are created in HEAP MEMORY,
    //  and assigned to matrixData.
    float** matrixData = new float*[row];
    
    //To get two-dimensional array, each ROW of the array must have columnSize times elements(float).
    for (int i = 0; i < row; i++){
        matrixData[i] = new float[column];
    }
    
    //  Random numbers are assigned to matrixData.
    for (int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            matrixData[i][j] = -10 + rand() % (22);
        }//end for
    }//end FOR
    
    //matrixData is returned to where it is called.
    return matrixData;
    
}//end GetRandomData ()

void TEST_FILL_BY_VALUE()
{
    
    //  Print "FILL BY VALUE TEST" to console.
    PrintMessageInFrame("FILL BY VALUE TEST");
    
    //  m1 object is created from Matrix class.     (It has members and member functions.)
    Matrix m1;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByValue function which is the member function of m1 is called to fill the matrix with given value.
    m1.FillByValue(1.34);
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Free function which is the member function of m1 is called to free the memory that was allocated for m1.
    m1.Free();
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(4, 3);
    
    //  FillByValue function which is the member function of m1 is called to fill the matrix with given value.
    m1.FillByValue(-2.65);
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Free function which is the member function of m1 is called to free the memory that was allocated for m1.
    m1.Free();
    
}//end TEST_FILL_BY_VALUE ()

void TEST_FILL_BY_DATA()
{
    //  Print "FILL BY DATA TEST" to console.
    PrintMessageInFrame("FILL BY DATA TEST");
    
    //  m1 object is created from Matrix class.     (It has members and member functions.)
    Matrix m1;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Free function which is the member function of m1 is called to free the memory that was allocated for m1.
    m1.Free();
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(4, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(4, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Free function which is the member function of m1 is called to free the memory that was allocated for m1.
    m1.Free();
    
}//end TEST_FILL_BY_DATA ()

void TEST_ADDITION()
{
    //  Print "ADDITION TEST" to console.
    PrintMessageInFrame("ADDITION TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2, m3;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    cout << "First Matrix:" << endl;
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Allocate function which is the member function of m2 is called to allocate memory for required sizes.
    m2.Allocate(2, 3);
    
    //  FillByData function which is the member function of m2 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m2.FillByData(GetRandomData(2, 3));
    
    cout << "Second Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  m1 and m2 is added and assigned to m3.
    m3 = m1.Addition(m2);
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m3 is called to display its items.
    m3.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    m3.Free();
}//end TEST_ADDITION ()

void TEST_SUBSTRUCTION()
{
    //  Print "SUBSTRUCTION TEST" to console.
    PrintMessageInFrame("SUBSTRUCTION TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2, m3;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    cout << "First Matrix:" << endl;
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Allocate function which is the member function of m2 is called to allocate memory for required sizes.
    m2.Allocate(2, 3);
    
    //  FillByData function which is the member function of m2 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m2.FillByData(GetRandomData(2, 3));
    
    cout << "Second Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  m2 is subtracted from m1 and the result is assigned to m3.
    m3 = m1.Substruction(m2);
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m3 is called to display its items.
    m3.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    m3.Free();
    
}//end TEST_SUBSTRUCTION ()

void TEST_MULTIPLICATION_MATRIX()
{
    //  Print "MATRIX MULTIPLICATION TEST" to console.
    PrintMessageInFrame("MATRIX MULTIPLICATION TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2, m3;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    cout << "First Matrix:" << endl;
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  Allocate function which is the member function of m2 is called to allocate memory for required sizes.
    m2.Allocate(3, 2);
    
    
    //  FillByData function which is the member function of m2 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m2.FillByData(GetRandomData(3, 2));
    
    cout << "Second Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  m1 and m2 is multiplied and the result is assigned to m3.
    m3 = m1.Multiplication(m2);
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m3 is called to display its items.
    m3.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    m3.Free();
    
}//end TEST_MULTIPLICATION_MATRIX ()

void TEST_MULTIPLICATION_CONSTANT()
{
    //  Print "SCALAR MULTIPLICATION TEST" to console.
    PrintMessageInFrame("SCALAR MULTIPLICATION TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    float scalar = 3;
    //  m1 is divided to given scalar value and the result is assigned to m2.
    m2 = m1.Multiplication(scalar);
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    
}//end TEST_MULTIPLICATION_CONSTANT ()

void TEST_DIVISION()
{
    //  Print "SCALAR DIVISION TEST" to console.
    PrintMessageInFrame("SCALAR DIVISION TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    float scalar = 3;
    //  m1 is divided to given scalar value and the result is assigned to m2.
    m2 = m1.Division(scalar);
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    
}//end TEST_DIVISION ()

void TEST_TRANSPOSE()
{
    //  Print "TRANSPOSE TEST" to console.
    PrintMessageInFrame("TRANSPOSE TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  m1's transpose is assigned to m2.
    m2 = m1.Transpose();
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    
}//end TEST_TRANSPOSE ()

void TEST_ROW_MODULE()
{
    //  Print "ROW MODULE TEST" to console.
    PrintMessageInFrame("ROW MODULE TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData(GetRandomData(2, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  m1's row module is calculated and the result is assigned to m2.
    m2 = m1.Row_Module();
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    
}//end TEST_ROW_MODULE ()

void TEST_COLUMN_MODULE()
{
    //  Print "COLUMN MODULE TEST" to console.
    PrintMessageInFrame("COLUMN MODULE TEST");
    
    //  Objects are created from matrix class.
    Matrix m1, m2;
    
    //  Allocate function which is the member function of m1 is called to allocate memory for required sizes.
    m1.Allocate(2, 3);
    
    //  FillByData function which is the member function of m1 is called to fill the matrix with random data
    //  that is generated GetRandomData function.
    m1.FillByData( GetRandomData(2, 3));
    
    //  Display function which is the member function of m1 is called to display its items.
    m1.Display();
    
    //  m1's column module is calculated and the result is assigned to m2.
    m2 = m1.Column_Module();
    
    cout << "Result Matrix:" << endl;
    
    //  Display function which is the member function of m2 is called to display its items.
    m2.Display();
    
    //  Free function which is the member function of each object is called to free the memory that was allocated for each of them.
    m1.Free();
    m2.Free();
    
}//end TEST_COLUMN_MODULE ()
