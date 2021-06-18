#include "ClockExample.h"
#include <iostream>
using namespace std;

void Clock::setTime(int forHour,int forMinute, int forSecond)                //Zamanı atama işlemi
{
    //Clock sınıfından bir fonksiyondur setTime, sınıfın içindeki üyelere erişebilir (hour, minute, second)
    
    //SECOND
    if(forSecond<60)
        second = forSecond;
    else
    {
        second = 0;
        incrementMinutes();
    }
    
    //MINUTE
    if(forMinute<60)
        minute = forMinute;
    else
    {
        minute = 0;
        incrementHours();
    }
    
    //HOUR
    if(forHour<24)
        hour = forHour;
    else
        hour = 0;
    
}//end setTime ()

void Clock::getTime(int &forHour, int &forMinute, int &forSecond) const
{
    forHour = hour;
    forMinute = minute;
    forSecond = second;
}

void Clock::printTime()const                //Zamanı gösterme
{
    //Sadece zamanı ekrana bastırır.
    
    cout<<hour<<" hours "<<minute<<" minutes "<<second<<" seconds .\n";
}

void Clock::incrementHours()
{
    //Saati birer artıracak.
    
    //Saat 25 olamaz.
    //Saat 23 ise, bir artıracak.
    
    hour++;
    
    if(hour == 24)
        hour = 0;
}//end incrementHours()

void Clock::incrementMinutes()
{
    minute++;
    
    if(minute==60)
    {
        minute=0;
        incrementHours();
    }
}//end incrementMinutes()

void Clock::incrementSeconds()
{
    second++;
    
    if(second == 60)
    {
        second = 0;
        incrementMinutes();
    }
}//end incrementSeconds()

bool Clock::equalTime(const Clock& comparingClock)const         //İki zamanın eşitlik durumunu karşılaştırma işlemi
{
    if( (comparingClock.hour == hour) && (comparingClock.minute == minute) && (comparingClock.second == second) )
        return true;
    
    return false;
}//end equalTime()
