/*****************************************
 * FootballPlayer.cpp                    *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

#include "FootballPlayer.h"     //To know function prototypes of FootballPlayer Class.
//FootballPlayer.h also includes Player.h header, that's why we don't also include Player.h header here.

//Constructor Function of FootballPlayer Class.
//This class is derived from Player Class, so this constructor function has to call its base class' constructor function(Player Class' Construction).
FootballPlayer::FootballPlayer(const string& name, int age, double paymentPerYear):Player(name,age)
{
    (*this).paymentPerYear = paymentPerYear;
}

//Returns paymentPerYear which is the PROTECTED member variable of FootballPlayer Class.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
double FootballPlayer::getPaymentPerYear() const
{
    return paymentPerYear;
}

//Sets paymentPerYear which is the PROTECTED member variable of FootballPlayer Class.
void FootballPlayer::setPaymentPerYear(double paymentPerYear)
{
    (*this).paymentPerYear = paymentPerYear;
}


//Prints that player who called this function is passing to given player.
void FootballPlayer::Pas(const Player *player)
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is passing to "<<player->getName()<<endl;
}

//Prints that player who called this function is shotting.
void FootballPlayer::Shot()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is shootting !\n";
}

//Destructor Function of FootballPlayer Class.
FootballPlayer::~FootballPlayer()
{
    
}
