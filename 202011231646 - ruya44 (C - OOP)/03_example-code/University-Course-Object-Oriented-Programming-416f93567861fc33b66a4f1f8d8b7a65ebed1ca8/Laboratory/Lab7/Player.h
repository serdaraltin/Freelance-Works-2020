/*****************************************
 * Player.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence             *
 *****************************************/


//Player.h includes base class, including iostream header in this file
//allows that not include the iostream header for each header file.
#include <iostream>

//To declare string type variables.
#include <string>

//Define string type under the namespace of std.
using namespace std;


class Player {
//Protected variables can be accessed from derived classes.
protected:
    int age;
    string name;
    
//Public variables can be accessed from derived classes too.
public:
    enum Direction
    {
        EAST,
        NORTH,
        NORTH_EAST,
        NORTH_WEST,
        SOUTH,
        SOUTH_EAST,
        SOUTH_WEST,
        WEST
    };
    
    //Returns age which is the PROTECTED member variable of Player Class.
    int getAge() const;
    
    //Returns name which is the PROTECTED member variable of Player Class.
    const string& getName() const;
    
    //Calls private functions of Player Class.
    void Move(Direction direction);
    
    //Constructor Function of Player Class.
    //Directly derived classes from Player class must initialize name and age(PROTECTED) variables!
    Player(const string& name, int age);
    
    //Destructor Function of Player Class.
    ~Player();
    
//Private Functions CANNOT BE ACCESSED out of the class.
private:
    //Move functions print that player is moving to given direction in MOVE FUNCTION(public).
    void MoveEast();
    void MoveNorth();
    void MoveNorthEast();
    void MoveNorthWest();
    void MoveSouth();
    void MoveSouthEast();
    void MoveSouthWest();
    void MoveWest();
};
