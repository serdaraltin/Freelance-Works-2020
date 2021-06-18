/*****************************************
 * Matrix.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 2: Introduction to C++ - II*
 *****************************************/

//  Created Matrix.h (header file) and it includes given function prototypes.

#pragma once
/*  
 In the C and C++ programming languages, " #pragma once " is a non-standard
    but widely supported preprocessor directive designed to cause the current source file 
    to be included only once in a single compilation.
 " #pragma once " has several advantages, including:
    less code, avoidance of name clashes, and sometimes improvement in compilation speed.

*** In this case, because of the #pragma once preprocessor directive (it works for Visual Studio),
*** Matrix.h file will compile just for once.
*/

//  Matrix (the type of struct) is created in STACK, and it has three members
//  Two of them are "int" and the other one is "pointer to point another pointer". (**)
struct Matrix{
    int rowSize = -1;
    int columnSize = -1;
    float** data = 0;
};

//  Allocating memory to matrix for required sizes.
void Matrix_Allocate(Matrix& matrix, int rowSize, int columnSize);

//  Deleting the elements of the given matrix.
void Matrix_Free(Matrix& matrix);

//  Filling the given matrix with the given value.
void Matrix_FillByValue(Matrix& matrix, float value);

//  Assigning data's elements to matrix.
void Matrix_FillByData(Matrix& matrix, float** data);

//  Displaying all elements of the given matrix.
void Matrix_Display(const Matrix& matrix);

//  Adding two matrices and saving the result to result matrix.
void Matrix_Addition(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);

//  Subtracting two matrices and saving the result to result matrix.
void Matrix_Substruction(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);

//  Multiplication the given matrices and saving the result to result matrix.
void Matrix_Multiplication(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);

//  Multiplication the given matrix with scalarValue and saving the result to result matrix.
void Matrix_Multiplication(const Matrix& matrix_left, float scalarValue, Matrix& result);

//  Dividing the given matrix to scalarValue and saving the result to result matrix.
void Matrix_Division(const Matrix& matrix_left, float scalarValue, Matrix& result);

//  Transposing the given matrix and saving it to result matrix.
void Matrix_Transpose(const Matrix& matrix, Matrix&result);

//  Calculating the row module of the given matrix and saving it to result matrix.
void Matrix_Row_Module(const Matrix& matrix, Matrix&result);

//  Calculating the column module of the given matrix and saving it to result matrix.
void Matrix_Column_Module(const Matrix& matrix, Matrix&result);
