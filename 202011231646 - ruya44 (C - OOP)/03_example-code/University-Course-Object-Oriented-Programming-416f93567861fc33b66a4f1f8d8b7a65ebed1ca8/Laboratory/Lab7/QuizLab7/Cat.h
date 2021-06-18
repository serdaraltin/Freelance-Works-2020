/*****************************************
 * Cat.h                                 *
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

#ifndef Cat_h
#define Cat_h

#include "Mammal.h"         //To derive Cat class from Mammal Class.


//Cat class is derived from Mammal Class.
//Cat class inherits Mammal Class' functions and variables as public.
//In this case Mammal Class is base class.

//  The important part is that Mammal Class is also derived from Animal Class so,
//Cat Class is indirectly derived from Animal Class.

/*
        Animal Class
            ^
            |
            |
        Mammal Class
            ^
            |
            |
        Cat Class
 */

//This stands for Cat Class is also inherits functions and members of Animal Class too.
class Cat: public Mammal
{
    //Private variables CAN NOT BE ACCESSED from derived classes.
private:
    int m_miaowSoundLevel;
    
    //Public variables can be accessed from derived classes too.
public:
    
    //Constructor Function of Cat Class.
    Cat(const string& name, int age, int miaowSoundLevel);
    
    //Prints that cat which called this function is miaowing and its sound level.
    void Miaow() const;
};


#endif /* Cat_h */
