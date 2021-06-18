#include <iostream>
#include "ClockExample.h"
using namespace std;

int main()
{
    {
        Clock firstClock("firstClock");
        
        firstClock.printTime();
        firstClock.incrementSeconds();
        firstClock.printTime();
        firstClock.incrementMinutes();
        firstClock.printTime();
        firstClock.incrementHours();
        firstClock.printTime();
        
        for(int i=0; i<59; i++)
            firstClock.incrementMinutes();
        
        firstClock.printTime();
        
        firstClock.incrementMinutes();
        firstClock.printTime();
        
    }//Kapsama alanı burada bitiyor.
    
    Clock firstClock("firstClock");
    firstClock.setTime(23, 60, 60);
    firstClock.printTime();
    Clock secondClock("secondClock");
    secondClock.printTime();
    
    cout<<firstClock.equalTime(secondClock)<<endl;
    
}
