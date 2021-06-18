/*****************************************
 * MusicPlayer.cpp                       *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "MusicPlayer.h"        //To know function prototypes of MusicPlayer.h

//Constructor Function of MusicPlayer Class.
//MusicPlayer Class is derived from Player Class, so this constructor function has to call the constructor of Player Class.
MusicPlayer::MusicPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount):Player(maxVolumeLevel)
{
    (*this).supportedFormats = supportedFormats;
    (*this).supportedFormatCount = supportedFormatCount;
}

//Prints that Music Player does not support the forward operation.
void MusicPlayer::Forward()
{
    cout<<"Music Player:\tDoes not support the forward operation."<<endl;
}

//Prints that Music Player does not support the backward operation.
void MusicPlayer::BackWard()
{
    cout<<"Music Player:\tDoes not support the backward operation."<<endl;
}

//Prints that media is ejecting.
void MusicPlayer::EjectMedia()
{
    cout<<"Music Player:\tEjecting the media : "<<mediaName<<endl;
}

//Prints that Music Player supports the given mediaName and initialize mediaName which is the protected member of Player Class.
void MusicPlayer::MounthMedia(const string &mediaName)
{
    (*this).mediaName = mediaName;
    cout<<"Music Player:\tTrying to mount the media..."<<endl;
    cout<<"Music Player:\tMedia is supported and playable..."<<endl;
}

//Destructor Function of MusicPlayer Class.
MusicPlayer::~MusicPlayer()
{
    
}
