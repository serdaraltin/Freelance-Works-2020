/*****************************************
 * Ipod.cpp                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "IPod.h"       //To know function prototypes of IPod Class.


//Constructor Function of IPod Class.
//IPod Class is derived from MusicPlayer Class, so this constructor function has to call the constructor of MusicPlayer Class.
IPod::IPod(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount):MusicPlayer(maxVolumeLevel,supportedFormats,supportedFormatCount)
{
    volumeLevel = 50;
}

//Destructor Function of IPod Clas.
IPod::~IPod()
{
    
}

//Prints that music is forwarding.
void IPod::Forward()
{
    cout<<"IPod:\tForward the music "<<mediaName<<endl;
}

//Prints that music is backwarding.
void IPod::BackWard()
{
    cout<<"IPod:\tBackward the music "<<mediaName<<endl;
}

//Prints that equalizer is adjusting.
void IPod::VolumeUp(int amount)
{
    Player::VolumeUp(amount);
    cout<<"IPod:\tAdjusting the equalizer"<<endl;
}

//Prints that equalizer is adjusting.
void IPod::VolumeDown(int amount)
{
    Player::VolumeDown(amount);
    cout<<"IPod:\tAdjusting the equalizer"<<endl;
}
