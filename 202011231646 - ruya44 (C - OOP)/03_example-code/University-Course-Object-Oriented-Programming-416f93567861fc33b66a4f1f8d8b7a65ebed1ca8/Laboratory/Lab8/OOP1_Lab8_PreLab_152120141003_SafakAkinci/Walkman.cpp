/*****************************************
 * Walkman.cpp                           *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Walkman.h"        //To know function prototypes of Walkman Class.

//Constructor Function of Walkman Class.
//Walkman Class is derived from MusicPlayer Class, so this constructor function has to call the constructor of MusicPlayer Class.
Walkman::Walkman(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount):MusicPlayer(maxVolumeLevel,supportedFormats,supportedFormatCount)
{
    
}

//Destructor Function of Walkman Class.
Walkman::~Walkman()
{
    
}

//Prints that closing the carriage.
void Walkman::EjectMedia()
{
    MusicPlayer::EjectMedia();
    cout<<"Walkman:\tClosing the carriage"<<endl;
}
