/*****************************************
 * Walkman.h                             *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/
#ifndef Walkman_h
#define Walkman_h

#include "MusicPlayer.h"        //To derive Walkman Class from MusicPlayer Class.

//Walkman Class is derived from MusicPlayer Class.
//It inherits the members of MusicPlayer Class.
class Walkman:public MusicPlayer
{

//Public variables can be accessed out of the class.
public:
    //Constructor Function of Walkman Class.
    Walkman(int maxVolumeLevel, string supportedFormats[], int supportedFormatCount);
    
    //Destructor Function of Walkman Class.
    ~Walkman();
    
    //Prints that closing the carriage.
    void EjectMedia();
    
};

#endif /* Walkman_h */
