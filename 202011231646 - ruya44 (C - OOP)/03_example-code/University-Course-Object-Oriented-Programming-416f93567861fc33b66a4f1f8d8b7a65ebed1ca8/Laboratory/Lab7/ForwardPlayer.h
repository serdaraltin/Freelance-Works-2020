/*****************************************
 * ForwardPlayer.h                       *
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
#ifndef ForwardPlayer_h
#define ForwardPlayer_h

#include "FootballPlayer.h"         //To derive ForwardPlayer class from FootballPlayer Class.

//ForwardPlayer class is derived from FootballPlayer class.
//ForwardPlayer class inherits FootballPlayer Class' functions and variables as public.

//  The important part is that FootballPlayer Class is also derived from Player Class so,
//ForwardPlayer Class is indirectly derived from Player Class.

/*
        Player Class
            ^
            |
            |
    FootballPlayer Class
            ^
            |
            |
    ForwardPlayer Class
 */

//This means, ForwardPlayer Class is also inherits functions and members of Player Class too.

class ForwardPlayer:public FootballPlayer
{
//Private variables CANNOT BE ACCESSED out of the class.
private:
    int goalCount;
    double paymentPerGoal;

//Public variables can be accessed from derived classes too.
public:
    
    //Constructor Function of ForwardPlayer Class.
        //  This class is derived from FootballPlayer Class,
        //so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
    ForwardPlayer(const string& name, int age, double paymentPerYear, double paymentPerGoal);
    
    //Destructor Function of ForwardPlayer Class.
    ~ForwardPlayer();
    
    //Calculates the payment for ForwardPlayer for this year.
    double CalculatePaymentForThisYear() const;
    
    //Returns goalCount which is the PRIVATE member variable of ForwardPlayer Class.
    int getGoalCount() const;
    
    //Sets goalCount which is the PRIVATE member variable of ForwardPlayer Class.
    void setGoalCount(int goalCount);
    
    //Prints that player who called this function is throwing himself.
    void ThrowYourSelf() const;
    
    //Prints that player who called this function is trying a dribble past.
    void TryDribblePast(const Player* player) const;
    
};

#endif /* ForwardPlayer_h */
