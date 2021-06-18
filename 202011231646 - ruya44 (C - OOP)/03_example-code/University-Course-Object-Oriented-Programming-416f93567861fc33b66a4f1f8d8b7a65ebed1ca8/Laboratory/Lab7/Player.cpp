/*****************************************
 * Player.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/

#include "Player.h"             //To know function prototypes of Player Class.

/*  using namespace std;  was included in "Player.h" header, that's why we didn't include it again here.  */


//Constructor Function of Player Class.
//Directly derived classes from Player class must initialize name and age(PROTECTED) variables!
Player::Player(const string& name, int age):name(name),age(age)
{
}

//Destructor Function of Player Class.
Player::~Player()
{
}

//Returns age which is the PROTECTED member variable of Player Class.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
int Player::getAge() const
{
    return age;
}

//Returns name which is the PROTECTED member variable of Player Class.
//Function should be const because it is an accessor function (It shouldn't change the class' variables.)
const string& Player::getName() const
{
    return name;
}

//Calls private functions of Player Class.
void Player::Move(Player::Direction direction)
{
    switch (direction) {
        case Direction::EAST:
            MoveEast();
            break;
        case Direction::NORTH:
            MoveNorth();
            break;
        case Direction::NORTH_EAST:
            MoveNorthEast();
            break;
        case Direction::NORTH_WEST:
            MoveNorthWest();
            break;
        case Direction::SOUTH:
            MoveSouth();
            break;
        case Direction::SOUTH_EAST:
            MoveSouthEast();
            break;
        case Direction::SOUTH_WEST:
            MoveSouthWest();
            break;
        case Direction::WEST:
            MoveWest();
            break;
    }//end switch
}//end Player::Move()

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveEast()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to EAST\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveNorth()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to NORTH\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveNorthEast()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to NORTH-EAST\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveNorthWest()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to NORTH-WEST\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveSouth()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to SOUTH\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveSouthEast()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to SOUTH-EAST\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveSouthWest()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to SOUTH-WEST\n";
}

//Prints that player is moving to given direction in MOVE FUNCTION (public).
void Player::MoveWest()
{
    //name is protected member of Player Class, it can be accessed from FootballPlayer Class and its functions because of the PROTECTED defined.
    cout<<name<<" is moving to WEST\n";
}
