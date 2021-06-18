/*****************************************
 * BugiVideoPlayer.cpp                   *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "BugiVideoPlayer.h"        //To know function prototypes of BugiVideoPlayer Class.

//Constructor Function of BugiVideoPlayer Class.
//BugiVideoPlayer Class is derived from VideoPlayer Class, so this constructor function has to call the constructor of VideoPlayer Class.
BugiVideoPlayer::BugiVideoPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount):VideoPlayer(maxVolumeLevel,supportedFormats,supportedFormatCount)
{
    volumeLevel = 50;
}

//Prints that media player crushed!
void BugiVideoPlayer::EjectMedia()
{
    cout<<"BugiVideoPlayer:\tMedia player crushed!"<<endl;
}

//Destructor Function of BugiVideoPlayer Class.
BugiVideoPlayer::~BugiVideoPlayer()
{
    
}
