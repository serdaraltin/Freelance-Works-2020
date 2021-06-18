#include <iostream>
using namespace std;

class CClock				//Declaration of class CClock
{
public:
	void setTime(int, int, int);
	void getTime(int &hours, int &minutes, int &seconds) const{
		hours = hr;
		minutes = min;
		seconds = sec;
	}
	void printTime() const;
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime (const CClock&) const;

//	CClock(){
//		hr=0;
//		min=0;
//		sec=0;
//	}
	CClock(int hours=0, int minutes=0, int seconds=0){
		setTime(hours,minutes,seconds);
	}
	
	~CClock(){
		cout<<"";
		cout<<endl<<"Destructor:";
		printTime();
	}
	
private:
	int hr;
	int min;
	int sec;
};
