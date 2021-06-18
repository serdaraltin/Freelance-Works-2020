/*****************************************
 * Dog.h                                 *
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
#ifndef Dog_h
#define Dog_h

#include "Mammal.h"             //To derive Dog class from Mammal Class.


//Dog class is derived from Mammal Class.
//Dog class inherits Mammal Class' functions and variables as public.
//In this case Mammal Class is base class.

//  The important part is that Mammal Class is also derived from Animal Class so,
//Dog Class is indirectly derived from Animal Class.

/*
            Animal Class
                ^
                |
                |
            Mammal Class
                ^
                |
                |
            Dog Class
 */

//This stands for Dog Class is also inherits functions and members of Animal Class too.

class Dog:public Mammal
{
//Protected variables can be accessed from derived classes.
protected:
    int m_barkSoundLevel;
    
//Public variables can be accessed from derived classes too.
public:
    
    //Constructor Function of Dog Class.
    Dog(const string& name, int age, int barkSoundLevel);
    
    //Prints that dog which called this function is barking and its sound level.
    void Bark() const;
};

#endif /* Dog_h */
