/*****************************************
 * DefensivePlayer.cpp                   *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

#include "DefensivePlayer.h"            //To know function prototypes of DefensivePlayer Class.
//DefensivePlayer.h also includes FootballPlayer.h header, that's why we don't also include FootballPlayer.h header here (also Player.h).

//Constructor Function of DefensivePlayer Class.
//This class is derived from FootballPlayer Class, so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
DefensivePlayer::DefensivePlayer(const string& name, int age, double paymentPerYear, double paymentPerMatch):FootballPlayer(name,age,paymentPerYear)
{
    (*this).paymentPerMatch = paymentPerMatch;
}

//Destructor Function of DefensivePlayer Class.
DefensivePlayer::~DefensivePlayer()
{
    
}

//Calculates the payment for DefensivePlayer for this year.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
double DefensivePlayer::CalculatePaymentForThisYear() const
{
    return paymentPerYear + paymentPerMatch * playedMatchCount;
}

//Prints that player who called this function is defending.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void DefensivePlayer::Defense() const
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is defending...\n";
}

//Returns playedMatchCount which is the PRIVATE member variable of DefensivePlayer Class.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
int DefensivePlayer::getPlayedMatchCount() const
{
    return playedMatchCount;
}

//Prints that player who called this function is tripped up.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void DefensivePlayer::TripUp(const Player* player) const
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" tripped up "<<player->getName()<<endl;
}

//Sets playedMatchCount which is the PRIVATE member variable of DefensivePlayer Class.
void DefensivePlayer::setPlayedMatchCount(int playedMatchCount)
{
    (*this).playedMatchCount = playedMatchCount;
}
