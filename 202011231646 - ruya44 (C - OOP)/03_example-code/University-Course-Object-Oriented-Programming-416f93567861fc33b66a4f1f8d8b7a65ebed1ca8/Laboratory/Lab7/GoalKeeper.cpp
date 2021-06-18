/*****************************************
 * DefensivePlayer.cpp                   *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

#include "GoalKeeper.h"         //To know function prototypes of GoalKeeper Class.
//GoalKeeper.h also includes FootballPlayer.h header, that's why we don't also include FootballPlayer.h header here (also Player.h).

//Constructor function of GoalKeeper class.
//This class is derived from FootballPlayer Class, so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
GoalKeeper::GoalKeeper(const string name, int age, double paymentPerYear):FootballPlayer(name,age,paymentPerYear)
{
    
}

//Destructor function of GoalKeeper class.
GoalKeeper::~GoalKeeper()
{
    
}

//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
double GoalKeeper::CalculatePaymentForThisYear() const
{
    return paymentPerYear;
}

//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void GoalKeeper::FlyAndTryCatch() const
{
    
    //name is protected member of Player Class, it can be accessed from GoalKeeper Class and its functions because of the PROTECTED defined.
    cout<<name<<" is flying and trying to catch...\n";
}
