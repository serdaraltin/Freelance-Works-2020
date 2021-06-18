/*****************************************
 * MiddleFielderPlayer.cpp               *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

#include "MiddleFielderPlayer.h"            //To know function prototypes of MiddleFielderPlayer Class.
//MiddleFielderPlayer.h also includes FootballPlayer.h header, that's why we don't also include FootballPlayer.h header here (also Player.h).


//Constructor Function of MidFielderPlayer Class.
    //  This class is derived from FootballPlayer Class,
    //so this constructor function has to call its base class' constructor function(FootballPlayer Class' Construction).
MidFielderPlayer::MidFielderPlayer(const string& name, int age, double paymentPerYear, double paymentPerAssist):FootballPlayer(name,age,paymentPerYear)
{
    (*this).paymentPerAssist = paymentPerAssist;
}

//Destructor Function of MidFielderPlayer Class.
MidFielderPlayer::~MidFielderPlayer()
{
    
}

//Calculates the payment for MidFielderPlayer for this year.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
double MidFielderPlayer::CalculatePaymentForThisYear() const
{
    return paymentPerYear + paymentPerAssist * assistCount;
}

//Returns assistCount is the PRIVATE member variable of MidFielderPlayer Class.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
int MidFielderPlayer::getAssistCount() const
{
    return assistCount;
}

//Prints that player who called this function is pressing.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void MidFielderPlayer::Press() const
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is pressing...\n";
}

//Prints that player who called this function is trying a through ball.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
void MidFielderPlayer::TryThroughBall(const Player* player) const
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is trying a through ball to "<<player->getName()<<endl;
}

//Sets assistCount which is the PRIVATE member variable of MidFielderPlayer Class.
void MidFielderPlayer::setAssistCount(int assistCount)
{
    (*this).assistCount = assistCount;
}
