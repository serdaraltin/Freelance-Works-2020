/*****************************************
 * Player.cpp                            *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Player.h"         //To know function prototypes of Player Class.

//Constructor Function of Player Class.
Player::Player(int maxVolumeLevel):maxVolumeLevel(maxVolumeLevel)
{
    volumeLevel = 35;
}

//Prints that player is opened.
void Player::Open()
{
    cout<<"Player:\tOpened..."<<endl;
}

//Adds given amount to volumeLevel and prints it.
void Player::VolumeUp(int amount)
{
    cout<<"Player:\tVolume Level:\t"<<(volumeLevel += amount)<<endl;
}

//Subtracts given amount from volumeLevel and prints it.
void Player::VolumeDown(int amount)
{
    cout<<"Player:\tVolume Level:\t"<<(volumeLevel -= amount)<<endl;
}

//Prints that media is playing.
void Player::Play()
{
    cout<<"Player:\tPlaying the media "<<mediaName<<endl;
}

//Prints that media is pausing.
void Player::Pause()
{
    cout<<"Player:\tPausing the media "<<mediaName<<endl;
}

//Prints that media is stopping.
void Player::Stop()
{
    cout<<"Player:\tStopping the media "<<mediaName<<endl;
}

//Prints that player is closed.
void Player::Close()
{
    cout<<"Player:\tClosed..."<<endl;
}

//Destructor Function of Player Class.
Player::~Player()
{
    
}
