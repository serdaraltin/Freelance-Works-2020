/*****************************************
 * VLCVideoPlayer.h                      *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/
#ifndef VLCVideoPlayer_h
#define VLCVideoPlayer_h

#include "VideoPlayer.h"        //To derive VLCVideoPlayer Class from VideoPlayer Class.

//VLCVideoPlayer Class is derived from VideoPlayer Class.
class VLCVideoPlayer:public VideoPlayer
{

//Public variables can be accessed out of the class.
public:
    
    //Constructor Function of VLCVideoPlayer Class.
    VLCVideoPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount);
    
    //Prints that music is forwarding.
    void Forward();
    
    //Prints that music is backwarding.
    void BackWard();
    
    //Prints that equalizer is adjusting.
    void VolumeDown(int amount);
    
    //Prints that equalizer is adjusting.
    void VolumeUp (int amount);
    
    //Destructor Function of VLCVideoPlayer Class.
    ~VLCVideoPlayer();
};

#endif /* VLCVideoPlayer_h */
