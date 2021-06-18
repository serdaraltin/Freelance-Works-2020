/*****************************************
 * TestMain.cpp                          *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

//Derived Classes
#include "DefensivePlayer.h"
#include "GoalKeeper.h"
#include "MiddleFielderPlayer.h"
#include "ForwardPlayer.h"

void TEST_GoalKeeper()
{
    cout <<"+------------------+" << endl
    << "| GOAL KEEPER TEST |" << endl
    << "+------------------+" << endl;
    
    //keeper pointer object is created from GoalKeeper Class in HEAP MEMORY.
    GoalKeeper* keeper = new GoalKeeper ("Iker Casillas", 34, 7.5);
    
    //keeper is moving given direction.
    keeper->Move(Player::Direction::EAST);
    
    //keeper is moving given direction.
    keeper->Move(Player::Direction::NORTH_EAST);
    
    //keeper is shotting.
    keeper->Shot();
    
    //player pointer object is created from DefensivePlayer Class in HEAP MEMORY.
    DefensivePlayer* player = new DefensivePlayer ("Raphael Varane", 22, 1.2, 0.1);
    
    //keeper is passing.
    keeper->Pas(player);
    
    //keeper is flying and trying to catch.
    keeper->FlyAndTryCatch();
    
    //Payment for keeper will print to console.
    cout<<"Payment for this year: "<<keeper->CalculatePaymentForThisYear()<<" million EUR"<<endl;
    
}//end TEST_GoalKeeper ()

void TEST_DefensivePlayer()
{
    cout <<"+-----------------------+" << endl
    << "| DEFENSIVE PLAYER TEST |" << endl
    << "+-----------------------+" << endl;
    
    //defense pointer object is created from DefensivePlayer Class in HEAP MEMORY.
    DefensivePlayer* defense = new DefensivePlayer ("Raphael Varane", 22, 1.2, 0.1);
    defense->Move(Player::Direction::EAST);
    defense->Move(Player::Direction::NORTH_EAST);
    
    defense->Shot();
    
    MidFielderPlayer* player = new MidFielderPlayer ("Gareth Bale", 25, 15, 0.2);
    defense->Pas(player);
    
    defense->Defense();
    
    ForwardPlayer* opponent = new ForwardPlayer ("Lionel Messi", 28, 20, 0.3);
    defense->TripUp(opponent);
    
    defense->setPlayedMatchCount(11);
    
    //Payment for defense will print to console.
    cout<<"Payment for this year: "<<defense->CalculatePaymentForThisYear()<<" million EUR"<<endl;
    
}//TEST_DefensivePlayer()

void TEST_MiddleFieldPlayer()
{
    cout <<"+----------------------------+" << endl
    << "| MIDDLE FIELDER PLAYER TEST |" << endl
    << "+----------------------------+" << endl;
    
    //middleFielder pointer object is created from MidFielderPlayer Class in HEAP MEMORY.
    MidFielderPlayer* middleFielder = new MidFielderPlayer ("Gareth Bale", 25, 15, 0.2);
    middleFielder->Move(Player::Direction::EAST);
    middleFielder->Move(Player::Direction::NORTH_EAST);
    
    middleFielder->Shot();
    
    ForwardPlayer* player = new ForwardPlayer ("Cristiano Ronaldo", 30, 17, 0.3);
    middleFielder->Pas(player);
    
    middleFielder->Press();
    middleFielder->TryThroughBall(player);
    
    middleFielder->setAssistCount(22);
    
    //Payment for keeper will print to console.
    cout<<"Payment for this year: "<<middleFielder->CalculatePaymentForThisYear()<<" million EUR"<<endl;
    
}//end TEST_MiddleFieldPlayer()

void TEST_ForwardPlayer()
{
    cout<<"+---------------------+" << endl
    <<"| FORWARD PLAYER TEST |" << endl
    <<"+---------------------+" << endl;
    
    //forward pointer object is created from ForwardPlayer Class in HEAP MEMORY.
    ForwardPlayer* forward = new ForwardPlayer ("Cristiano Ronaldo", 30, 17, 0.3);
    forward->Move(Player::Direction::EAST);
    forward->Move(Player::Direction::NORTH_EAST);
    
    forward->Shot();
    
    ForwardPlayer* player = new ForwardPlayer ("Karim Benzema", 27, 8, 0.3);
    forward->Pas(player);
    
    forward->ThrowYourSelf();
    
    DefensivePlayer* opponent = new DefensivePlayer ("Gerard Pique", 28, 5.8, 0.1);
    forward->TryDribblePast(opponent);
    
    forward->setGoalCount(42);
    
    cout<<"Payment for this year: "<<forward->CalculatePaymentForThisYear()<<" million EUR"<<endl;
    
}//end TEST_ForwardPlayer()



int main ()
{
    
    TEST_GoalKeeper();     
    TEST_DefensivePlayer();
    TEST_MiddleFieldPlayer();
    TEST_ForwardPlayer();
    
    //Indicates that program ended successfully.
    return 0;
}//end main()
