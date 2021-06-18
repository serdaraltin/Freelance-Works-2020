/*****************************************
 * BugiVideoPlayer.h                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef BugiVideoPlayer_h
#define BugiVideoPlayer_h

#include "VideoPlayer.h"        //To derive BuigVideoPlayer Class from VideoPlayer Class.

//BugiVideoPlayer is derived from VideoPlayer Class.
class BugiVideoPlayer:public VideoPlayer
{

//Public variables can be accessed out of the class.
public:
    
    //Constructor Function of BugiVideoPlayer Class.
    BugiVideoPlayer(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount);
    
    //Destructor Function of BugiVideoPlayer Class.
    ~BugiVideoPlayer();
    
    //Prints that media player crushed!
    void EjectMedia();
    
};

#endif /* BugiVideoPlayer_h */
