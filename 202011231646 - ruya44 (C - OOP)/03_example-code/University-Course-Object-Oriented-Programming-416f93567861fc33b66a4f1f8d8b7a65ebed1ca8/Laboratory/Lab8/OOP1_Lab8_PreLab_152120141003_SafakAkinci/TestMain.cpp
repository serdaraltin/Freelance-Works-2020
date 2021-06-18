/*****************************************
 * TestMain.cpp                          *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Ipod.h"                   //To create Ipod type variables.
#include "Walkman.h"                //To create Walkman type variables.
#include "BugiVideoPlayer.h"        //To create BugiVideoPlayer type variables.
#include "VLCVideoPlayer.h"         //To create VLCVideoPlayer type variables.


void TEST_ForAll(Player* player, const string& mediaName)
{
    //Open player!
    player->Open();
    
    //Try to mount given media.
    player->MounthMedia(mediaName);
    
    //Try to increase volume level.
    player->VolumeUp(20);
    
    //Try to decrease volume level.
    player->VolumeDown(10);
    
    //Play player!
    player->Play();
    
    //Pause player!
    player->Pause();
    
    //Stop player!
    player->Stop();
    
    //Play player!
    player->Play();
    
    //Try to forward!
    player->Forward();
    
    //Try to backward.
    player->BackWard();
    
    //Eject the media!
    player->EjectMedia();
    
    //Close player!
    player->Close();
    
}

int main()
{
    
    cout<< "+---------+" << endl
    << "| WALKMAN |" << endl
    << "+---------+" << endl;
    string walkmanFormats[] = { "mp3" };
    
    //walkman is a pointer that normally should point a Player type object but, Player Class is an ABSTRACT CLASS.(We can not create any object from Player Class.)

    //A Walkman type object is created in HEAP MEMORY, and its address will be kept in walkman pointer.
    //This situation is called UPCASTING.(A base class pointer points to derived class object.)
    Player* walkman = new Walkman(70, walkmanFormats, 1);
    
    //Walkman's functions will test.
    TEST_ForAll(walkman, "test.mp3");
    
    
    cout<< "+------+" << endl
    << "| IPOD |" << endl
    << "+------+" << endl;
    string iPodFormats[] = { "mp3","wav" };
    
    //ipod is a pointer that normally should point a MusicPlayer type object but, it points an object the type of IPod.
    //An IPod type object is created in HEAP MEMORY, and its address will be kept in ipod pointer(MusicPlayer*).
    //This situation is called UPCASTING.(A base class pointer points to derived class object.)
    MusicPlayer* ipod  = new IPod(100, iPodFormats, 2);
 
    //IPod's functions will test.
    TEST_ForAll(ipod, "test.mp3");
    
    
    cout << "+-------------------+" << endl
    << "| BUGI VIDEO PLAYER |" << endl
    << "+-------------------+" << endl;
    string bugiVideoFormats[] = { "mp4" };
    
    
    //bugiVideoPlayer is a pointer that points an object the type of BugiVideoPlayer. (Object is created in Heap Memory)
    BugiVideoPlayer* bugiVideoPlayer = new BugiVideoPlayer(100, bugiVideoFormats, 1);
    
    //bugiVideoPlayer's functions will test.
    TEST_ForAll(bugiVideoPlayer, "test.mp4");
 
    
    cout << "+------------------+" << endl
    << "| VLC VIDEO PLAYER |" << endl
    << "+------------------+" << endl;
    string vlcVideoFormats[] = { "mp4","avi" };
    
    //vlcVideoPlayer is a pointer that points an object the type of VLCVideoPlayer. (Object is created in Heap Memory)
    Player* vlcVideoPlayer = new VLCVideoPlayer(100, vlcVideoFormats, 2);
    
    //vlcVideoPlayer's functions will test.
    TEST_ForAll(vlcVideoPlayer, "test.mp4");
    
    //Indicates that program ended successfully.
    return 0;

}//end main()
