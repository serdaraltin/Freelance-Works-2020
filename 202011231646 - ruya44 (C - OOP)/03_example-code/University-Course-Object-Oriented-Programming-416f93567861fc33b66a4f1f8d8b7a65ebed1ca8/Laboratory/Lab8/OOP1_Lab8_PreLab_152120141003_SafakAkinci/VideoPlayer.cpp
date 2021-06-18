/*****************************************
 * VideoPlayer.cpp                       *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "VideoPlayer.h"        //To know function prototypes of VideoPlayer Class.

//Constructor Function of VideoPlayer Class.
//VideoPlayer Class is derived from Player Class, so this constructor function has to call the constructor of Player Class.
VideoPlayer::VideoPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount):Player(maxVolumeLevel)
{
    (*this).supportedFormatCount = supportedFormatCount;
    (*this).supportedFormats = supportedFormats;
}


//Prints that Video Player does not support the forward operation.
void VideoPlayer::Forward()
{
    cout<<"Video Player:\tDoes not support the forward operation."<<endl;
}

//Prints that Video Player does not support the backward operation.
void VideoPlayer::BackWard()
{
    cout<<"Video Player:\tDoes not support the backward operation."<<endl;
}

//Prints that media is ejecting.
void VideoPlayer::EjectMedia()
{
    cout<<"Video Player:\tEjecting the media : "<<mediaName<<endl;
}


//Prints that Video Player supports the given mediaName and initialize mediaName which is the protected member of Player Class.
void VideoPlayer::MounthMedia(const string& mediaName)
{
    (*this).mediaName = mediaName;
    cout<<"Video Player:\tTrying to mount the media..."<<endl;
    cout<<"Video Player:\tMedia is supported and playable..."<<endl;
}

//Deconstructor Function of VideoPlayer Class.
VideoPlayer::~VideoPlayer()
{
    
}
