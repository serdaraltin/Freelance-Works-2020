/*****************************************
 * GoalKeeper.h                          *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
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

#ifndef GoalKeeper_h
#define GoalKeeper_h

#include "FootballPlayer.h"         //To derive GoalKeeper class from FootballPlayer Class.

//GoalKeeper class is derived from FootballPlayer class.
//GoalKeeper class inherits FootballPlayer Class' functions and variables as public.

//  The important part is that FootballPlayer Class is also derived from Player Class so,
//GoalKeeper Class is indirectly derived from Player Class.

/*
            Player Class
                ^
                |
                |
        FootballPlayer Class
                ^
                |
                |
         GoalKeeper Class
 */

//This means, GoalKeeper Class is also inherits functions and members of Player Class too.
class GoalKeeper:public FootballPlayer
{

//Public variables can be accessed from derived classes too.
public:
    //Construction Function of GoalKeeper Class.
    //This class is derived from FootballPlayer Class and it was derived from Player Class.
    //  name, age and paymentPerYear variables that function take should be initialized by FootballPlayer Constructor,
    //  and it will also call the constructor function of Player Class to initialize name and age members.
    //**  paymentPerYear is PROTECTED member variable of FootballPlayer Class.
    GoalKeeper(const string name, int age, double paymentPerYear);
    
    //Destructor Function of GoalKeeper Class.
    ~GoalKeeper();
    
    //Calculates the payment for GoalKeeper for this year.
    double CalculatePaymentForThisYear() const;
    
    //Prints that player who called this function is flying and trying to catch.
    void FlyAndTryCatch() const;
};
#endif /* GoalKeeper_h */
