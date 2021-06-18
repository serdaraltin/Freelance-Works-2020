/*****************************************
 * Matrix.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 3: Class vs Struct         *
 *****************************************/


class Matrix
{
    
//Public members are accessible from anywhere where the object is visible.
public:
    float** data;
    
    //Those are member functions. They can call for each member that is created from Matrix class.
    
    //Allocates memory for required sizes to object.
    void Allocate(int rSize, int cSize);
    
    //The memory which was allocated for object will be free.
    void Free();
    
    //Gets row size of the object for another objects since rowSize is private.
    //The returned value the type of integer will be constant so that it doesn't change.
    int getRowSize() const;
    
    //Assigns given parameter to object's rowSize.
    void setRowSize(int rSize);
    
    //Gets column size of the object for another objects since columnSize is private.
    //The returned value the type of integer will be constant so that it doesn't change.
    int getColumnSize() const;
    
    //Assigns given parameter to object's columnSize.
    void setColumnSize(int cSize);
    
    //Gets data of the object for another objects since data is private.
    //The returned value the type of float to float pointer will be constant so that it doesn't change.
    float** getData() const;
    
    //Assigns given parameter(two-dim array) to object.
    void setData(float** d);
    
    //Fills the object with given value.
    void FillByValue(float value);
    
    //Fills the object with randomly.
    void FillByData(float** d);
    
    //Fills the object with entered numbers.
    void FillByData();
    
    //Display the object's items.
    void Display();
    
    float Determinant();
    Matrix Cofactor();
    Matrix Inverse();
    
    
    //Adds given object that is created from Marix class to object.
    Matrix Addition(const Matrix& matrix_right);
    
    //Subtracts given object that is created from Marix class from object.
    Matrix Substruction(const Matrix& matrix_right);
    
    //Multiplies given object that is created from Marix class with object.
    Matrix Multiplication(const Matrix& matrix_right);
    
    //Multiplies given scalarValue with object.
    Matrix Multiplication(float scalarValue);
    
    //Divides object to scalarValue.
    Matrix Division(float scalarValue);
    
    //Transposes the object.
    Matrix Transpose();
    
    //Calculates the row module of the object.
    Matrix Row_Module();
    
    //Calculates the column module of the object.
    Matrix Column_Module();
    
//Private members of a class are accessible only from within other members of the same class.
private:
    int rowSize;
    int columnSize;
};
