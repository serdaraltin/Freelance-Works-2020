/*****************************************
 * VideoPlayer.h                         *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/
#ifndef VideoPlayer_h
#define VideoPlayer_h

#include "Player.h"         //To derive VideoPlayer Class from Player Class.

//VideoPlayer Class is derived from Player Class.
class VideoPlayer:public Player
{
//Public variables can be accessed out of the class.
public:
    int supportedFormatCount;
    string* supportedFormats;
    
/***Those are PURE virtual functions in PLAYER CLASS.***/
    
    //Prints that Video Player does not support the forward operation.
    void Forward();
    
    //Prints that Video Player does not support the backward operation.
    void BackWard();
    
    //Prints that media is ejecting.
    void EjectMedia();
    
    //Prints that Video Player supports the given mediaName and initialize mediaName which is the protected member of Player Class.
    void MounthMedia(const string& mediaName);
    
    //Constructor Function of VideoPlayer Class.
    VideoPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount);
    
    //Deconstructor Function of VideoPlayer Class.
    //Virtual destructors ensure that all appropriate destructors run on an object.
    virtual ~VideoPlayer();
};

#endif /* VideoPlayer_h */
