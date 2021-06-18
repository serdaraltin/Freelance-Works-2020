#include <iostream>
#include "Clock.h"
using namespace std;

void CClock::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
	
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}

void CClock::incrementHours()
{
	hr++;
	if (hr > 23)
		hr=0;
}

void CClock::incrementMinutes()
{
	min++;
	if (min > 59){
		min=0;
		incrementHours(); //increment hours
	}
}

void CClock::incrementSeconds()
{
	sec++;
	if (sec > 59){
		sec=0;
		incrementMinutes(); //increment minutes
	}
}

bool CClock::equalTime(const CClock& otherClock) const
{
	return (hr == otherClock.hr
		&& min == otherClock.min
		&& sec == otherClock.sec);

}

void CClock::printTime() const
{
	if (hr <10)
		cout << "0";
	cout << hr <<":";
	if (min <10)
		cout << "0";
	cout << min <<":";
	if (sec <10)
		cout << "0";
	cout << sec ;
}
