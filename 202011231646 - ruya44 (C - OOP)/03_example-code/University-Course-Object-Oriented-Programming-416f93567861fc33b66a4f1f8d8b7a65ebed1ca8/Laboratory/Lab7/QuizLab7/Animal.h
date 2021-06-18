/*****************************************
 * Animal.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

/*
 This is a preprocessor technique of preventing a header file from being included multiple times,
 which can be problematic for various reasons.
 
 During compilation of the project, each .cpp file (usually) is compiled.
 
 The compiler will take .cpp file, open any files #included by it, concatenate them all into one massive text file,
 and then perform syntax analysis and finally it will convert it to some intermediate code,
 optimize/perform other tasks, and finally generate the assembly output for the target architecture.
 
 *****************************************************************************************
 *    Because of this, if a file is #included multiple times under one .cpp file,        *
 *    the compiler will append its file contents twice,                                  *
 *    so if there are definitions within that file,                                      *
 *    we will get a compiler error telling us that we redefined a variable.              *
 *****************************************************************************************
 
 When the file is processed by the preprocessor step in the compilation process,
 the first time its contents are reached the first two lines will check if FILE_H has been defined for the preprocessor.
 If not, it will define FILE_H and continue processing the code between it and the #endif directive.
 
 The next time that file's contents are seen by the preprocessor, the check against FILE_H will be false,
 so it will immediately scan down to the #endif and continue after it.
 THIS PREVENTS REDEFINITION ERRORS.
 */

#ifndef Animal_h
#define Animal_h

//Animal.h includes base class, including iostream header in this file
//allows that not include the iostream header for each file.
#include <iostream>

//To declare string type variables.
#include <string>

//Define string type under the namespace of std.
using namespace std;


//Animal class is the base class.
class Animal
{
    
//Protected variables can be accessed from derived classes.
protected:
    string m_name;
    int m_age;
    
//Public variables can be accessed from derived classes too.
public:
    
    //Constructor Function of Animal Class.
    Animal(const string& name, int age);
    
    //Returns m_name which is the PROTECTED member variable of Animal Class.
    string getName() const;
    
    //Returns m_age which is the PROTECTED member variable of Animal Class.
    int getAge() const;
    
    //Sets m_name which is the PROTECTED member variable of Animal Class.
    void setName(string name);
    
    //Sets m_age which is the PROTECTED member variable of Animal Class.
    void setAge(int age);
};

#endif
