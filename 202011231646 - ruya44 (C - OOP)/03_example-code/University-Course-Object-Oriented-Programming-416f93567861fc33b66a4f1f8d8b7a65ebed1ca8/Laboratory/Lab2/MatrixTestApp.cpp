/*****************************************
 * MatrixTestApp.cpp                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 2: Introduction to C++ - II*
 *****************************************/

//  Created a test file which includes the entry point of the program (main)
//  and its name is MatrixTestApp.cpp and copied the given test code to it.

#include "Matrix.h"                 //Adding Matrix.h header file that include function prototypes.
#include <iostream>                 //Adding iostream header to use standart input output functions.
#include <string>                   //Adding string header to find string's length via length () function.
#include <iomanip>                  //Adding iomanip header to use setw() function but didn't use.

using namespace std;                //To don't write for each code std::   (e.x. std::cout)

//  PrintFrameLine function prints +----+ according to the length.
void PrintFrameLine(int length);
//  PrintMessageInFrame function prints the message to console.
void PrintMessageInFrame(const string& message);
//  GetRandomData will create two-dimensional array and fill it with random numbers.
float** GetRandomData(int row, int column);

void TEST_FILL_BY_VALUE();
void TEST_FILL_BY_DATA();
void TEST_ADDITION();
void TEST_SUBSTRUCTION();
void TEST_MULTIPLICATION_MATRIX();
void TEST_MULTIPLICATION_CONSTANT();
void TEST_DIVISION();
void TEST_QUIZ();

int main() {
    TEST_FILL_BY_VALUE();
    TEST_FILL_BY_DATA();
    TEST_ADDITION();
    TEST_SUBSTRUCTION();
    TEST_MULTIPLICATION_MATRIX();
    TEST_MULTIPLICATION_CONSTANT();
    TEST_DIVISION();
    TEST_QUIZ();
    
    return 0;
}//end main()

//  PrintFrameLine function takes one integer parameter called length(message.length) and prints +----+
void PrintFrameLine (int length){
    
    cout << "+";
    length -= 2;
    
    for (int i = 0; i < length; i++)
    {
        cout << "-";
    }
    
    cout << "+" << endl;
}//end PrintFrameLine ()

//  PrintMessageInFrame function takes one const string reference called message and prints it to console.
void PrintMessageInFrame (const string& message ){
    
    //  Added (unsigned int) in front of the message.length() function to get integer (lost precision).
    PrintFrameLine( (unsigned int)message.length() + 4 );
    cout << "| " << message << " |" << endl;
    PrintFrameLine( message.length() + 4 );
    //If we don't add (unsigned int) in front of the message.length() function Xcode warns the developer with
    //  " Implicit conversion loses integer precision: 'unsigned long' to 'int' ".
    
}//end PrintMessageInFrame ()

//  GetRandomData function takes two integer parameters and will create two-dimensional array and return it.
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
    
//  m1 is created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);

//  All of the m1's elements will assign to 1.34 .
    Matrix_FillByValue(m1, 1.34);

//  All of the m1's elements will print to console.
    Matrix_Display(m1);

//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);

//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 4, 3);
    
//  All of the m1's elements will assign to -2.65 .
    Matrix_FillByValue(m1, -2.65);
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    
}//end TEST_FILL_BY_VALUE ()

void TEST_FILL_BY_DATA(){
    
//  Print "FILL BY DATA SET" to console.
    PrintMessageInFrame("FILL BY DATA TEST");
    
//  m1 is created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 4, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(4, 3));

//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    
}//end TEST_FILL_BY_DATA ()

void TEST_ADDITION(){
    
//  Print "ADDITION TEST" to console.
    PrintMessageInFrame("ADDITION TEST");
    
//  m1, m2 and m3 are created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1, m2, m3;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    cout << "First Matrix:" << endl;
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Allocate function will allocate memory for m2.
    Matrix_Allocate(m2, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m2, GetRandomData(2, 3));
    
    cout << "Second Matrix:" << endl;
    
//  All of the m2's elements will print to console.
    Matrix_Display(m2);
    
//  Matrix_Addition function will add m1 to m2 and save the result to m3.
    Matrix_Addition(m1, m2, m3);
    cout << "Result Matrix:" << endl;
    
//  All of the m3's elements will print to console.
    Matrix_Display(m3);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    Matrix_Free(m2);
    Matrix_Free(m3);

}//end TEST_ADDITION

void TEST_SUBSTRUCTION(){
    
//  Print "SUBSTRUCTION TEST" to console.
    PrintMessageInFrame("SUBSTRUCTION TEST");
    
//  m1, m2 and m3 are created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1, m2, m3;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    cout << "First Matrix:" << endl;
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Allocate function will allocate memory for m2.
    Matrix_Allocate(m2, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m2, GetRandomData(2, 3));
    
    cout << "Second Matrix:" << endl;

//  All of the m2's elements will print to console.
    Matrix_Display(m2);
    
//  Matrix_Substruction function will subtract m2 from m1 and save the result to m3.
    Matrix_Substruction(m1, m2, m3);
    
    cout << "Result Matrix:" << endl;
    
//  All of the m3's elements will print to console.
    Matrix_Display(m3);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    Matrix_Free(m2);
    Matrix_Free(m3);
}//end TEST_SUBSTRUCTION

void TEST_MULTIPLICATION_MATRIX (){
    
//  Print "MATRIX MULTIPLICATION TEST" to console.
    PrintMessageInFrame("MATRIX MULTIPLICATION TEST");
    
//  m1, m2 and m3 are created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1, m2, m3;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    
    cout << "First Matrix:" << endl;
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Allocate function will allocate memory for m2.
    Matrix_Allocate(m2, 3, 2);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m2, GetRandomData(3, 2));
    
    cout << "Second Matrix:" << endl;
    
//  All of the m2's elements will print to console.
    Matrix_Display(m2);
    
//  Matrix_Multiplication function will multiply m1 with m2 and save the result to m3.
    Matrix_Multiplication(m1, m2, m3);
    
    cout << "Result Matrix:" << endl;
    
//  All of the m3's elements will print to console.
    Matrix_Display(m3);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    Matrix_Free(m2);
    Matrix_Free(m3);
}//end TEST_MULTIPLICATION_MATRIX

void TEST_MULTIPLICATION_CONSTANT(){
    
//  Print "SCALAR MULTIPLICATION TEST" to console.
    PrintMessageInFrame("SCALAR MULTIPLICATION TEST");
    
//  m1 and m2 are created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1, m2;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);

//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Multiplication function will multiply m1 with scalar and save the result to m2.
    float scalar = 3;
    Matrix_Multiplication(m1, scalar, m2);
    
    cout << "Result Matrix:" << endl;
    
//  All of the m2's elements will print to console.
    Matrix_Display(m2);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    Matrix_Free(m2);
}//end TEST_MULTIPLICATION_CONSTANT

void TEST_DIVISION (){
    
//  Print "SCALAR DIVISION TEST" to console.
    PrintMessageInFrame("SCALAR DIVISION TEST");
    
//  m1 and m2 are created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1, m2;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Division function will divide m1 to scalar and save the result to m2.
    float scalar = 3;
    Matrix_Division(m1, scalar, m2);
    
    cout << "Result Matrix:" << endl;
    
//  All of the m2's elements will print to console.
    Matrix_Display(m2);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    Matrix_Free(m2);
}//end TEST_DIVISION

void TEST_QUIZ(){
    
//  Print "TRANSPOSE TEST" to console.
    PrintMessageInFrame("TRANSPOSE TEST");
    
//  m1 and result are created the type of the struct Matrix which is defined in Matrix.h.
    Matrix m1, result;
    
//  Matrix_Allocate function will allocate memory for m1.
    Matrix_Allocate(m1, 2, 3);
    
//  Matrix_FillByData function will fill the given matrix with random numbers.
    Matrix_FillByData(m1, GetRandomData(2, 3));
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Transpose function transpozes the given matrix and saves it to result.
    Matrix_Transpose(m1, result);
    
//  All of the m1's elements will print to console.
    Matrix_Display(result);
    
//  Print "ROW MODULE TEST" to console.
    PrintMessageInFrame("ROW MODULE TEST");
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Row_Module function calculate the row module and saves it to result.
    Matrix_Row_Module(m1, result);
    
//  All of the m1's elements will print to console.
    Matrix_Display(result);
    
//  Print "COLUMN MODULE TEST" to console.
    PrintMessageInFrame("COLUMN MODULE TEST");
    
//  All of the m1's elements will print to console.
    Matrix_Display(m1);
    
//  Matrix_Column_Module function calculate the column module and saves it to result.
    Matrix_Column_Module(m1, result);
    
//  All of the m1's elements will print to console.
    Matrix_Display(result);
    
//  Matrix_Free function will delete the elements of the given parameter.
    Matrix_Free(m1);
    Matrix_Free(result);
}
