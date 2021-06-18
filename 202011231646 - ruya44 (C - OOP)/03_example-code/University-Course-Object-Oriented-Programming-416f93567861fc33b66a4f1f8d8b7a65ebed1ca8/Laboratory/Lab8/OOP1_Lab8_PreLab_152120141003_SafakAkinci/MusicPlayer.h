/*****************************************
 * MusicPlayer.h                         *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef MusicPlayer_h
#define MusicPlayer_h

#include "Player.h"     //To derive MusicPlayer Class from Player Class.

//MusicPlayer Class is derived from Player Class.
class MusicPlayer:public Player
{
//Protected variables can be accessed out of the class.
protected:
    string* supportedFormats;
    int supportedFormatCount;
    
//Public variables can be accessed out of the class.
public:
    //Constructor Function of MusicPlayer Class.
    MusicPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount);
    
    //Destructor Function of MusicPlayer Class.
    //Virtual destructors ensure that all appropriate destructors run on an object.
    virtual ~MusicPlayer();
    
    
/***Those are PURE virtual functions in PLAYER CLASS.***/
    
    //Prints that Music Player does not support the forward operation.
    void Forward();
    
    //Prints that Music Player does not support the backward operation.
    void BackWard();
    
    //Prints that media is ejecting.
    void EjectMedia();
    
    //Prints that Music Player supports the given mediaName and initialize mediaName which is the protected member of Player Class.
    void MounthMedia(const string& mediaName);
};


#endif /* MusicPlayer_h */
