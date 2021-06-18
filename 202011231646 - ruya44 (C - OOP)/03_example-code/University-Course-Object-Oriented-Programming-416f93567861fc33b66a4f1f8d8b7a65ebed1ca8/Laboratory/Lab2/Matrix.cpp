/*****************************************
 * Matrix.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 2: Introduction to C++ - II*
 * Lab Exercise: Matrix Library Creation *
 *****************************************/

//  Created Matrix.cpp and included the Matrix.h .

//  A C++ Matrix library that performs the basic matrix operations
//  by using the given struct type (Matrix) is written and tested.

//  Implemented required functions that located in the Matrix.h file.

#include "Matrix.h"                 //Adding Matrix.h header file that include function prototypes.
#include <iostream>                 //Adding iostream header to use standart input output functions.
#include <iomanip>                  //Adding iomanip header to use setw() function but didn't use.
#include <math.h>                   //Adding math.h header to use pow and sqrt functions.

using namespace std;                //To don't write for each code std::   (e.x. std::cout)

//  Matrix_Allocate function takes a reference called matrix the type of the struct Matrix
//  which is defined in Matrix.h and two variables called rowSize and columnSize to allocate
//  memory to dynamic matrix.s
//  All parameters were taken from MatrixTestApp.cpp .
/*  Function took reference to don't waste memory (like copying given parameter for function). */
/*  Using reference allows us to change(assign etc) given parameter. */
/*  We can access the given parameter under the name of "matrix" in Matrix_Allocate function */

/***  This function will allocate two-dimensional dynamic array into the data member of the Matrix
    and update rowSize and columnSize variables which are the member of matrix. ***/

void Matrix_Allocate(Matrix& matrix, int rowSize, int columnSize)
{
    
    //rowSize(2) and columnSize(3) are assigned to matrix's members called rowSize and columnSize.
    matrix.rowSize = rowSize;
    matrix.columnSize = columnSize;
    
    //A dynamic two-dimensional array is basically "an array of pointers to pointers".
    
    //  matrix.data is a pointer which is created in STACK will point another pointer.
    
    //  rowSize times elements that all of them are float* (float pointer) are created in HEAP MEMORY,
    //  and assigned to matrix's member called data (float**).
    
    matrix.data = new float* [matrix.rowSize];
    
    //To get two-dimensional array, each ROW of the array must have columnSize times elements(float).
    for(int i=0; i<matrix.rowSize; i++)
        matrix.data[i] = new float [matrix.columnSize];
    
}//end Matrix_Allocate ()

//  Matrix_Free function takes a reference called matrix the type of the struct Matrix which is defined in Matrix.h
//  Matrix_Free function will delete the elements of the given parameter, in this case it is called matrix.
/***  This function will free the allocated memory for the given Matrix to prevent memory leak
    and assign rowSize and columnSize which are the member of matrix to -1 and data to nullptr. ***/
void Matrix_Free(Matrix& matrix)
{
    
    //  Deleted all columns of matrix for each row.
    for(int i=0; i<matrix.rowSize; i++){
        delete[]matrix.data[i];
    }
    
    //  Deleted all rows of matrix.
    delete[]matrix.data;
    
    //  -1 is assigned to matrix.rowSize and matrix.columnSize to know matrix.data isn't initialized (empty).
    matrix.rowSize = -1;
    matrix.columnSize = -1;
    //  matrix.data is a pointer, after the removing its items, it should point to NULL.
    matrix.data = nullptr;
    
}//end Matrix_Free ()

//  Matrix_FillByValue takes a reference called matrix the type of the stuct Matrix which is defined in Matrix.h
//  and a float variable called value which is equal to 1.34 was given by MatrixTestApp.cpp .
/***  This function will fill the data member of the Matrix by the given value. ***/
void Matrix_FillByValue(Matrix& matrix, float value)
{
    //  value(1.34) is assigned to all elements of the matrix.
    for(int i=0; i<matrix.rowSize; i++){
        for(int j=0; j<matrix.columnSize; j++){
            matrix.data[i][j]=value;
        }//end for
    }//end FOR
    
}//end Matrix_FillByValue ()

//  Matrix_FillByData takes one reference called matrix, and one 2-D array called data
//  which is generated from GetRandomData() function that located in MatrixTestApp.cpp .
/***  This function will fill the data member of the Matrix by
    the corresponding elements of the given two-dimensional array.  ***/
void Matrix_FillByData(Matrix & matrix, float ** data)
{
    
    //  data's elements are assigned to matrix.data .
    for(int i=0; i<matrix.rowSize; i++){
        for(int j=0; j<matrix.columnSize; j++){
            matrix.data[i][j]=data[i][j];
        }//end for
    }//end FOR
    
}//end Matrix_FillByData

//  Matrix_FillByValue takes "a constant(to don't change anything of its) reference" called matrix
//"const" word is used to prevent changing the data of the given matrix, just get(read) its data.
//  the type of the stuct Matrix which is defined in Matrix.h.
/***  This function will display the matrix's elements to console. ***/

void Matrix_Display(const Matrix& matrix)
{
    
    cout<<"\nMATRIX:\t"<<matrix.rowSize<<" x "<<matrix.columnSize<<endl<<endl;
    
    //  All elements of the array will print to console.
    for(int i=0; i<matrix.rowSize; i++){
        for(int j=0; j<matrix.columnSize; j++){
            cout<<"\t"<<matrix.data[i][j]<<"\t\t";
        }//end for
        cout<<endl;
    }//end FOR
    
}//end Matrix_Display ()

//  Matrix_Addition takes three references that two of them are constant are the type of struct called Matrix.
//"const" word is used to prevent changing the data of the given matrix, just get(read) its data.
/***  This function will call Matrix_Allocate function to create result array for the required sizes
and perform matrix addition for the given first two matrices by saving the result into the Matrix named result.*/
void Matrix_Addition(const Matrix & matrix_left, const Matrix & matrix_right, Matrix &result)
{
    
    //  Matrix_Allocate function allocate memory for result.
    Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
    
    //  The addition of the two matrices will calculate and assign to result (Matrix).
    for(int i=0; i<result.rowSize; i++){
        for(int j=0; j<result.columnSize; j++){
            result.data[i][j] = matrix_left.data[i][j] + matrix_right.data[i][j];
        }//end for
    }//end FOR
    
}//end Matrix_Addition ()

//  Matrix_Substruction takes three references that two of them are constant are the type of struct called Matrix.
//"const" word is used to prevent changing the data of the given matrix, just get(read) its data.
/***  This function will call Matrix_Allocate function to create result array for the required sizes
and perform matrix subtruction for the given first two matrices by saving the result into the Matrix named result.*/
void Matrix_Substruction(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{
    
    //  Matrix_Allocate function allocate memory for result.
    Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
    
    //  The "subtraction" of the two matrices will calculate and assign to result (Matrix).
    for(int i=0; i<result.rowSize; i++){
        for(int j=0; j<result.columnSize; j++){
            result.data[i][j] = matrix_left.data[i][j] - matrix_right.data[i][j];
        }//end for
    }//end FOR
    
}//end Matrix_Substruction ()

//  Matrix_Multiplication takes three references that two of them are constant are the type of struct called Matrix.
//"const" word is used for don't change the data of the given matrix, just get(read) its data.
/***  This function will call Matrix_Allocate function to create result array for the required sizes
and perform matrix multiplication for the given first two matrices by saving the result into the Matrix named result*/
void Matrix_Multiplication(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result)
{

    //  Matrix_Allocate function allocate memory for result.
    Matrix_Allocate(result, matrix_left.rowSize, matrix_right.columnSize);
    
    //  The multiplication of the two matrices will calculate and assign to result (Matrix).
    for(int i=0;i<matrix_left.rowSize;i++){
        for(int j=0;j<matrix_right.columnSize;j++){
            
            result.data[i][j]=0;
            
            for(int k=0;k<matrix_left.columnSize;k++){
                result.data[i][j] += matrix_left.data[i][k] * matrix_right.data[k][j];
            }//end for
            
        }//end FOR
    }//END FOR
    
}//end Matrix_Multiplication ()

//  Matrix_Multiplication takes two references that their types are struct called Matrix
//and one float variable called scalarValue.
//  There are two function with same name (Matrix_Multiplication), the difference between them
//are variables that they take.
//  Program will decide which function should call according to their variables
//when the Matrix_Multiplication function call.
/***  This function will call Matrix_Allocate function to create result array for the required sizes
 and perform multiplication with matrix and the scalarValue(float) by saving the result into the Matrix named result*/
void Matrix_Multiplication(const Matrix & matrix_left, float scalarValue, Matrix & result)
{
    
    //  Matrix_Allocate function allocates memory for result.
    Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
    
    //  matrix_left.data will multiple with the scalarValue (float) and assign to result.data .
    for(int i=0; i<result.rowSize; i++){
        for(int j=0; j<result.columnSize; j++){
            result.data[i][j] = matrix_left.data[i][j] * scalarValue;
        }//end for
    }//end FOR
    
}//end Matrix_Multiplication ()

//  Matrix_Division takes two references that their types are struct called Matrix
//and one float variable called scalarValue.
/***  This function will call Matrix_Allocate function to create result array for the required sizes
 and perform divison with matrix and the scalarValue(float) by saving the result into the Matrix named result*/
void Matrix_Division(const Matrix & matrix_left, float scalarValue, Matrix & result)
{
    
    //  Matrix_Allocate function allocates memory for result.
    Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
    
    //  matrix_left.data will divide to the scalarValue (float) and assign to result.data .
    for(int i=0; i<result.rowSize; i++){
        for(int j=0; j<result.columnSize; j++){
            result.data[i][j] = matrix_left.data[i][j] / scalarValue;
        }//end for
    }//end FOR
    
}//end Matrix_Division ()

//  Matrix_Transpose takes two references(one is const) that their types are struct called Matrix.
/***  This function will call Matrix_Allocate function to create result array for the required sizes
 and perform transposition with given matrix by saving the result into the Matrix named result*/
void Matrix_Transpose(const Matrix& matrix, Matrix&result){
    
    //  Matrix_Allocate function allocates memory for result.
    Matrix_Allocate(result, matrix.columnSize, matrix.rowSize);
    
    for(int i=0; i<matrix.rowSize; i++){
        for(int j=0; j<matrix.columnSize; j++)
            result.data[j][i] = matrix.data[i][j];
    }//end FOR
    
}//end Matrix_Transpoze ()

//  Matrix_Row_Module takes two references(one is const) that their types are struct called Matrix.
/***  This function will call Matrix_Allocate function to create result array for matrix.rowSize x 1 sizes
 and perform row module with given matrix by saving the result into the Matrix named result*/
void Matrix_Row_Module(const Matrix& matrix, Matrix&result){
    
    //  Matrix_Allocate function allocates memory for result (matrix.rowSize x 1)
    Matrix_Allocate(result, matrix.rowSize, 1);
    
    for(int row=0, total=0; row<matrix.rowSize; row++){
        for(int col=0; col<matrix.columnSize; col++){
            total += pow(matrix.data[row][col],2);
        }//  Each element at the row is squared and totalled.
        
        result.data[row][0] = sqrt(total);
        //The square root of the total is assigned to result.data[row][0]
        
    }//end FOR
    
}//end Matrix_Row_Module ()

//  Matrix_Column_Module takes two references(one is const) that their types are struct called Matrix.
/***  This function will call Matrix_Allocate function to create result array for 1 x matrix.columnSize sizes
 and perform column module with given matrix by saving the result into the Matrix named result*/
void Matrix_Column_Module(const Matrix& matrix, Matrix&result){
    
    //  Matrix_Allocate function allocates memory for result (1 x matrix.columnSize)
    Matrix_Allocate(result, 1, matrix.columnSize);
    
    for(int col=0, total=0; col<matrix.columnSize; col++){
        for(int row=0; row<matrix.rowSize; row++){
            total += pow(matrix.data[row][col],2);
        }//  Each element at the column is squared and totalled.
        
        result.data[0][col] = sqrt(total);
        //The square root of the total is assigned to result.data[0][col]
        
    }//end FOR
    
}//end Matrix_Column_Module ()


//->    matrixes -> matrices
//->    substruction -> subtraction
