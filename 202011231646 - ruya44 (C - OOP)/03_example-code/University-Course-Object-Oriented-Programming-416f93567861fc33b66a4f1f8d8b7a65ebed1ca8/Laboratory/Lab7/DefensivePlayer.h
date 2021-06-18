/*****************************************
 * DefensivePlayer.h                     *
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

#ifndef DefensivePlayer_h
#define DefensivePlayer_h

#include "FootballPlayer.h"             //To derive DefensivePlayer class from FootballPlayer Class.

//DefensivePlayer class is derived from FootballPlayer class.
//DefensivePlayer class inherits FootballPlayer Class' functions and variables as public.

//  The important part is that FootballPlayer Class is also derived from Player Class so,
//DefensivePlayer Class is indirectly derived from Player Class.

/*
            Player Class
                ^
                |
                |
        FootballPlayer Class
                ^
                |
                |
        DefensivePlayer Class
 */

//This means, DefensivePlayer Class is also inherits functions and members of Player Class too.

class DefensivePlayer:public FootballPlayer
{

//Private variables CANNOT BE ACCESSED out of the class.
private:
    double paymentPerMatch;
    int playedMatchCount;
    
//Public variables can be accessed from derived classes too.
public:
    
    //Constructor Function of DefensivePlayer Class.
        //  This class is derived from FootballPlayer Class,
        //so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
    DefensivePlayer(const string& name, int age, double paymentPerYear, double paymentPerMatch);
    
    //Calculates the payment for DefensivePlayer for this year.
    double CalculatePaymentForThisYear() const;
    
    //Prints that player who called this function is defending.
    void Defense() const;
    
    //Returns playedMatchCount which is the PRIVATE member variable of DefensivePlayer Class.
    int getPlayedMatchCount() const;
    
    //Prints that player who called this function is tripped up.
    void TripUp(const Player* player) const;
  
    //Sets playedMatchCount which is the PRIVATE member variable of DefensivePlayer Class.
    void setPlayedMatchCount(int playedMatchCount);
    
    //Destructor Function of DefensivePlayer Class.
    ~DefensivePlayer();
};

#endif /* DefensivePlayer_hpp */
