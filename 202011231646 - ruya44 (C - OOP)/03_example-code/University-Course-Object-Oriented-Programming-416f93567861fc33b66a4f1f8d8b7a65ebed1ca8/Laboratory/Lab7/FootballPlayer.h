/*****************************************
 * FootballPlayer.h                      *
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
#ifndef FootballPlayer_h
#define FootballPlayer_h

#include "Player.h"       //To derive FootballPlayer Class from Player Class which defined in Player.h header.

//FootballPlayer class is derived from Player Class.
//FootballPlayer class inherits Player Class' functions and variables as public.
//In this case Player Class is base class.
class FootballPlayer:public Player
{
//Protected variables can be accessed from derived classes.
protected:
    double paymentPerYear;
    
//Public variables can be accessed from derived classes too.
public:
    //Constructor Function of FootballPlayer Class.
        //  This class is derived from Player Class,
        //so this constructor function has to call its base class' constructor function(Player Class' Construction).
    FootballPlayer(const string& name, int age, double paymentPerYear);
    
    //Returns paymentPerYear which is the PROTECTED member variable of FootballPlayer Class.
    double getPaymentPerYear() const;
    
    //Sets paymentPerYear which is the PROTECTED member variable of FootballPlayer Class.
    void setPaymentPerYear(double paymentPerYear);
    
    //Prints that player who called this function is passing to given player.
    void Pas (const Player* player);
    
    //Prints that player who called this function is shotting.
    void Shot();
    
    //Destructor Function of FootballPlayer Class.
    ~FootballPlayer();
};

#endif /* FootballPlayer_h */
