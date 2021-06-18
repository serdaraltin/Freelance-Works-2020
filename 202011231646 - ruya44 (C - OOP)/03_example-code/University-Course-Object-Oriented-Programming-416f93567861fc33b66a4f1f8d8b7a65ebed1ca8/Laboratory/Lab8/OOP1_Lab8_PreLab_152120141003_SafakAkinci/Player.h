/*****************************************
 * Player.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef Player_h
#define Player_h

#include <iostream>         //To use standart input and output functions.
using namespace std;        //To declare string type variables under the std namespace.



//Classes that contain at least one pure virtual function are known as abstract base classes.


//It can be used to create pointers to it, and take advantage of all its polymorphic abilities.
//And can actually be dereferenced when pointing to objects of derived (non-abstract) classes.

//Player Class is an ABSTRACT CLASS because of the PURE VIRTUAL FUNCTIONS.
//Abstract base classes cannot be used to instantiate objects.
//This is a class that can only be used as base class, and thus is allowed to have virtual member functions without definition (known as pure virtual functions). The syntax is to replace their definition by =0 (an equal sign and a zero).
class Player
{
    //Protected variables can be accessed out of the class.
protected:
    int maxVolumeLevel;
    int volumeLevel;
    string mediaName;
    
    //Public variables can be accessed out of the class.
public:
    
    //Constructor Function of Player Class.
    Player (int maxVolumeLevel = 100);
    
    //Prints that player is opened.
    void Open();
    
    //Adds given amount to volumeLevel and prints it.
    virtual void VolumeUp(int amount);
    
    //Subtracts given amount from volumeLevel and prints it.
    virtual void VolumeDown(int amount);
    
    //Prints that media is playing.
    void Play();
    
    //Prints that media is pausing.
    void Pause();
    
    //Prints that media is stopping.
    void Stop();
    
    //Prints that it is closed.
    void Close();
    
    //Those are pure virtual functions, It means derived classes have to contain the definition of them.
    virtual void Forward() = 0;
    virtual void BackWard() = 0;
    virtual void EjectMedia() = 0;
    virtual void MounthMedia(const string& mediaName) = 0;
    
    
    //Destructor Function of Player Class.
    //Virtual destructors ensure that all appropriate destructors run on an object.
    virtual ~Player();
};

#endif /* Player_h */
