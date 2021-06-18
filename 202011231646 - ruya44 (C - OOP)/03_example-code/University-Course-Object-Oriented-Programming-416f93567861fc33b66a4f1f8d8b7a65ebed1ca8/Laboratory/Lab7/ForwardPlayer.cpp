/*****************************************
 * ForwardPlayer.cpp                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

#include "ForwardPlayer.h"              //To know function prototypes of ForwardPlayer Class.
//ForwardPlayer.h also includes FootballPlayer.h header, that's why we don't also include FootballPlayer.h header here (also Player.h).


//Constructor Function of ForwardPlayer Class.
//  This class is derived from FootballPlayer Class,so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
ForwardPlayer::ForwardPlayer(const string& name, int age, double paymentPerYear, double paymentPerGoal):FootballPlayer(name,age,paymentPerYear)
{
    (*this).paymentPerGoal = paymentPerGoal;
}

//Destructor Function of ForwardPlayer Class.
ForwardPlayer::~ForwardPlayer()
{
    
}

//Calculates the payment for ForwardPlayer for this year.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
double ForwardPlayer::CalculatePaymentForThisYear() const
{
    return paymentPerYear + paymentPerGoal * goalCount;
}

//Returns goalCount which is the PRIVATE member variable of ForwardPlayer Class.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
int ForwardPlayer::getGoalCount() const
{
    return goalCount;
}

//Sets goalCount which is the PRIVATE member variable of ForwardPlayer Class.
void ForwardPlayer::setGoalCount(int goalCount)
{
    (*this).goalCount = goalCount;
}

//Prints that player who called this function is throwing himself.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void ForwardPlayer::ThrowYourSelf() const
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is throwing himself...\n";
}

//Prints that player who called this function is trying a dribble past.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void ForwardPlayer::TryDribblePast(const Player* player) const
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is trying a dribble past on "<<player->getName()<<endl;
}
