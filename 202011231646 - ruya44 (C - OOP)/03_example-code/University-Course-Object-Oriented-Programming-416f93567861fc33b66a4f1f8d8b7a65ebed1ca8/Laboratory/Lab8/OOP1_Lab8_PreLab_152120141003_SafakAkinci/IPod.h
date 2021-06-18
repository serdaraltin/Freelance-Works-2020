/*****************************************
 * Ipod.h                                *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef IPod_h
#define IPod_h

#include "MusicPlayer.h"            //To derive IPod Class from MusicPlayer Class.

//IPod Class is derived from MusicPlayer Class.
class IPod:public MusicPlayer
{

//Public variables can be accessed out of the class.
public:
    //Constructor Function of IPod Class.
    IPod(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount);
    
    //Destructor Function of IPod Clas.
    ~IPod();
    
    //Prints that music is forwarding.
    void Forward();
    
    //Prints that music is backwarding.
    void BackWard();
    
    //Prints that equalizer is adjusting.
    void VolumeUp(int amount);
    
    //Prints that equalizer is adjusting.
    void VolumeDown(int amount);
};


#endif /* IPod_h */
