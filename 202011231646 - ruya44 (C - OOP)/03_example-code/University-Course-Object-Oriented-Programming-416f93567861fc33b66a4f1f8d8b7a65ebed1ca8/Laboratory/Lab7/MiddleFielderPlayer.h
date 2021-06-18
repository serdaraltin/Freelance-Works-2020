/*****************************************
 * MiddleFielderPlayer.h                 *
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

#ifndef MiddleFielderPlayer_h
#define MiddleFielderPlayer_h

#include "FootballPlayer.h"             //To derive MidFielderPlayer class from FootballPlayer Class.

//MidFielderPlayer class is derived from FootballPlayer class.
//MidFielderPlayer class inherits FootballPlayer Class' functions and variables as public.

//  The important part is that FootballPlayer Class is also derived from Player Class so,
//MidFielderPlayer Class is indirectly derived from Player Class.

/*
            Player Class
                ^
                |
                |
        FootballPlayer Class
                ^
                |
                |
        MidFielderPlayer Class
 */

//This means, MidFielderPlayer Class is also inherits functions and members of Player Class too.

class MidFielderPlayer:public FootballPlayer
{

//Private variables CANNOT BE ACCESSED out of the class.
private:
    int assistCount;
    double paymentPerAssist;

//Public variables can be accessed from derived classes too.
public:
    
    //Constructor Function of MidFielderPlayer Class.
        //  This class is derived from FootballPlayer Class,
        //so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
    MidFielderPlayer(const string& name, int age, double paymentPerYear, double paymentPerAssist);
    
    //Destructor Function of MidFielderPlayer Class.
    ~MidFielderPlayer();
    
    //Calculates the payment for MidFielderPlayer for this year.
    double CalculatePaymentForThisYear() const;
    
    //Returns assistCount is the PRIVATE member variable of MidFielderPlayer Class.
    int getAssistCount() const;
    
    //Prints that player who called this function is pressing.
    void Press() const;
    
    //Prints that player who called this function is trying a through ball.
    void TryThroughBall(const Player* player) const;
    
    //Sets assistCount which is the PRIVATE member variable of MidFielderPlayer Class.
    void setAssistCount(int assistCount);
};

#endif /* MiddleFielderPlayer_hpp */
