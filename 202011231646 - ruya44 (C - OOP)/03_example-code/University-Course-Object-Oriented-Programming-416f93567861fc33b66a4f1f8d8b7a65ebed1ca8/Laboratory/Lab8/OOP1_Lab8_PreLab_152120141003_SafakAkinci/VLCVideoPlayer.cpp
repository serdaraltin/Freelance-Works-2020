/*****************************************
 * VLCVideoPlayer.cpp                    *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "VLCVideoPlayer.h"         //To know function prototypes of VLCVideoPlayer Class.

//Constructor Function of VLCVideoPlayer Class.
//VLCVideoPlayer Class is derived from VideoPlayer Class, so this constructor function has to call the constructor of VideoPlayer Class.
VLCVideoPlayer::VLCVideoPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount):VideoPlayer(maxVolumeLevel,supportedFormats,supportedFormatCount)
{
    volumeLevel = 50;
}

//Prints that music is forwarding.
void VLCVideoPlayer::Forward()
{
    cout<<"VLCVideoPlayer:\tForward the music"<<mediaName<<endl;
}

//Prints that music is backwarding.
void VLCVideoPlayer::BackWard()
{
    cout<<"VLCVideoPlayer:\tBackward the music"<<mediaName<<endl;
}

//Prints that equalizer is adjusting.
void VLCVideoPlayer::VolumeUp(int amount)
{
    cout<<"VLCVideoPlayer:\tAdjusting the equalizer..."<<endl;
    
    //Given amount is added to the current volumeLevel.
    VideoPlayer::VolumeUp(amount);
}

//Prints that equalizer is adjusting.
void VLCVideoPlayer::VolumeDown(int amount)
{
    cout<<"VLCVideoPlayer:\tAdjusting the equalizer..."<<endl;
    
    //Given amount is subtracted from the current volumeLevel.
    VideoPlayer::VolumeDown(amount);
}

//Destructor Function of VLCVideoPlayer Class.
VLCVideoPlayer::~VLCVideoPlayer()
{
    
}
