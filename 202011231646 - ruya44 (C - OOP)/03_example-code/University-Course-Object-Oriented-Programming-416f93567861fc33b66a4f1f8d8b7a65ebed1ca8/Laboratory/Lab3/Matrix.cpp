/*****************************************
 * Matrix.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 3: Class vs Struct         *
 *****************************************/

#include "Matrix.h"                     //Adding Matrix.h header file that include function prototypes.
#include <math.h>                       //To use pow() and sqrt() functions.
#include <iostream>                     //To use standart input output functions.
#include <iomanip>                      //To use setw() function but didn't use.
using namespace std;                    //To don't write for each code std::   (e.x. std::cout)

//  Allocates two-dimensional dynamic array into the data member of the Matrix
//  and updates rowSize and columnSize variables.
void Matrix::Allocate(int rSize, int cSize)
{
    //setRowSize(rSize);
    rowSize = rSize;
    
    //setColumnSize(cSize);
    columnSize = cSize;
    
    
    //  data is a pointer to pointer(float**) which is created in Matrix class will point another pointer.
    
    //  rowSize times elements that all of them are float* (float pointer) are created in HEAP MEMORY,
    //  and assigned to data (float**).
    data = new float* [rowSize];
    
    //To get two-dimensional array, each ROW of the array must have columnSize times elements(float).
    for(int i=0; i<rowSize; i++)
        data[i] = new float [columnSize];
    
}//end Matrix::Allocate ()

//  Releases the allocated memory for the given Matrix and assigns rowSize and columnSize to -1 and data to nullptr.
void Matrix::Free()
{
    
    //  Deleted all columns of matrix for each row.
    for(int i=0; i<rowSize; i++){
        delete[]data[i];
    }
    
    //  Deleted all rows of matrix.
    delete[]data;
    
    //setRowSize(-1);
    rowSize = -1;
    
    //setColumnSize(-1);
    columnSize = -1;
    
    data = nullptr;
}//end Matrix::Free ()

//Gets row size of the object for another objects since rowSize is private.
//The returned value the type of integer will be constant so that it doesn't change.
int Matrix::getRowSize() const
{
    int rSize;
    
    rSize = rowSize;
    
    return rSize;
}//end Matrix::getRowSize ()

//Assigns given parameter to object's rowSize.
void Matrix::setRowSize(int rSize)
{
    rowSize = rSize;
}//end Matrix::setRowSize ()

//Gets column size of the object for another objects since columnSize is private.
//The returned value the type of integer will be constant so that it doesn't change.
int Matrix::getColumnSize() const
{
    int cSize;
    
    cSize = columnSize;
    
    return columnSize;
}//end Matrix::getColumnSize()

//Assigns given parameter to object's columnSize.
void Matrix::setColumnSize(int cSize)
{
    columnSize = cSize;
}//end Matrix::setColumnSize ()

//Gets data of the object for another objects since data is private.
//The returned value the type of float to float pointer will be constant so that it doesn't change.
float** Matrix::getData() const
{
    return data;
}//end Matrix::getData ()

//Assigns given parameter(two-dim array) to object's data.
void Matrix::setData(float** d)
{
    data = d;
}//end Matrix::setData ()

//Fills the data member of the Matrix by the given value.
void Matrix::FillByValue(float value)
{
    
    //  value is assigned to matrix's elements.
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<columnSize; j++){
            data[i][j] = value;
        }//end for
    }//end FOR
    
}//end Matrix::FillByValue ()

//Fills the data member of the Matrix by the corresponding elements of the given two-dimensional array.
void Matrix::FillByData(float** d)
{
    
    //data = d;
    
    //  data's elements are assigned to matrix.data .
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<columnSize; j++){
            data[i][j] = d[i][j];
        }//end for
    }//end FOR
    
}//Matrix::FillByData ()

void Matrix::FillByData()
{
    for(int row=0; row<rowSize; row++)
    {
        cout<<"Please, enter the "<<row<<" th elements!\n";
        for(int col=0; col<columnSize; col++)
        {
            cin>>data[row][col];
        }//end for
    }//end FOR
}

//Displays the Matrix.
void Matrix::Display()
{
    
    cout<<"\nMATRIX:\t"<<rowSize<<" x "<<columnSize<<endl<<endl;
    
    //  All elements of the data will print to console.
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<columnSize; j++){
            cout<<"\t"<<data[i][j]<<"\t\t";
        }//end for
        cout<<endl;
    }//end FOR
    
}//end Matrix::Display ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs matrix addition.
Matrix Matrix::Addition(const Matrix& matrix_right)
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(rowSize, columnSize);
    
    //Two matrix is added and the result is assigned to result object.
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<columnSize; j++){
            result.data[i][j] = data[i][j] + matrix_right.data[i][j];
        }//end for
    }//end FOR
    
    
    return result;
    
}//end Matrix::Addition ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs matrix subtraction.
Matrix Matrix::Substruction(const Matrix& matrix_right)
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(rowSize, columnSize);
    
    //Given object's data is subtracted from object's data and result is assigned result's data.
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<columnSize; j++){
            result.data[i][j] = data[i][j] - matrix_right.data[i][j];
        }//end for
    }//end FOR
    
    return result;
    
}//end Matrix::Substruction ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs matrix multiplication.
Matrix Matrix::Multiplication(const Matrix& matrix_right)
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(rowSize, matrix_right.columnSize);
    
    //Multiplies given object with object and result is assigned the result matrix.
    for(int row=0;row<rowSize;row++){
        for(int col=0;col<matrix_right.columnSize;col++){
            
            result.data[row][col]=0;
            
            for(int k=0;k<columnSize;k++){
                result.data[row][col] += data[row][k] * matrix_right.data[k][col];
            }//end for
            
        }//end FOR
    }//END FOR
    
    return result;
    
}//end Matrix::Multiplication ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs multiplication with scalarValue.
Matrix Matrix::Multiplication(float scalarValue)
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(rowSize, columnSize);
    
    //Multiplies given scalarValue with object and result is assigned the result matrix.
    for(int i=0; i<result.rowSize; i++){
        for(int j=0; j<result.columnSize; j++){
            result.data[i][j] = data[i][j] * scalarValue;
        }//end for
    }//end FOR
    
    return result;
}//end Matrix::Multiplication ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs division with scalarValue.
Matrix Matrix::Division(float scalarValue)
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(rowSize, columnSize);
    
    //Divides object to given scalarValue and result is assigned the result matrix.
    for(int i=0; i<result.rowSize; i++){
        for(int j=0; j<result.columnSize; j++){
            result.data[i][j] = data[i][j] / scalarValue;
        }//end for
    }//end FOR
    
    return result;
}//end Matrix::Division ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs transpose operation.
Matrix Matrix::Transpose()
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(columnSize, rowSize);
    
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<columnSize; j++)
            result.data[j][i] = data[i][j];
    }//end FOR
    
    return result;
}//end Matrix::Transpose ()

//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs matrix row module.
Matrix Matrix::Row_Module()
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(rowSize, 1);
    
    for(int row=0, total=0; row<rowSize; row++){
        for(int col=0; col<columnSize; col++){
            total += pow(data[row][col],2);
        }//  Each element at the row is squared and totalled.
        
        result.data[row][0] = sqrt(total);
        //The square root of the total is assigned to result.data[row][0]
        
    }//end FOR
    
    return result;
    
}//end Matrix::Row_Module ()


//Creates a new matrix and calls Allocate function for the result Matrix for required sizes and performs matrix column module.
Matrix Matrix::Column_Module()
{
    //result object is created by Matrix class.
    Matrix result;
    
    //Allocates memory for required sizes to it.
    result.Allocate(columnSize, 1);
    
    for(int col=0, total=0; col<columnSize; col++){
        for(int row=0; row<rowSize; row++){
            total += pow(data[row][col],2);
        }//  Each element at the column is squared and totalled.
        
        result.data[col][0] = sqrt(total);
        //The square root of the total is assigned to result.data[0][col]
        
    }//end FOR
    
    return result;
    
}//end Matrix::Column_Module ()

float Matrix::Determinant()
{
    
    if (rowSize == 2 && columnSize ==2)
        return data[0][0] * data[1][1] - data [0][1] * data[1][0];
    
    else if(rowSize == 3 && columnSize ==3)
    {
        return (data[0][0]*data[1][1]*data[2][2] + data[1][0]*data[2][1]*data[0][2] + data[2][0]*data[0][1]*data[1][2])
        -
        (data[0][2]*data[1][1]*data[2][0] + data[1][2]*data[2][1]*data[0][0] + data[2][2]*data[1][0]*data[0][1]);
        
    }
    
    cout<<"It isn't square matrix!\n";
    
    return -1;
}

Matrix Matrix::Cofactor()
{
    Matrix cofactor;
    cofactor.Allocate(rowSize, columnSize);
    
    if(rowSize == 3 && columnSize == 3)
    {
        for(int row=0; row<rowSize; row++)
            for(int col=0; col<columnSize; col++)
            {
                
                cofactor.data[row][col] =
                data[(row+1) % 3][(col+1) % 3] * data[(row+2) % 3][(col+2) % 3]
                -
                data[(row+1) % 3][(col+2) %3] * data[(row+2) % 3][(col+1) % 3];
                
                if(cofactor.data[row][col] == -0)
                    cofactor.data[row][col]= 0;
            }
    }
    else
    {
        cofactor.data[0][0]=data[1][1];
        cofactor.data[0][1]= -1 * data[1][0];
        cofactor.data[1][0]= -1 * data[0][1];
        cofactor.data[1][1]=data[0][0];
        
        
        /*
         //Precedence of % is higher than +.
         for(int row=0; row<rowSize; row++)
         for(int col=0; col<columnSize; col++)
         {
         
         cofactor.data[row][col] = this->data[(row+1 % 2)][(col+1 % 2)];
         
         if ( pow( -1, row+col+2) == -1 )
         cofactor.data[row][col] *= -1;
         }
         */
    }
    
    return cofactor;
}

Matrix Matrix::Inverse()
{
    return this->Cofactor().Transpose().Division( this->Determinant() );
}
