#include "Student.h"
#include "Clock.h"

#include <iostream>
using namespace std;

int main(){

	CClock myClock;

	CClock yourClock(3,50);

	{
		CClock clock(1,1,1);

	}

	Student student;

	student.setStudent("Ali",123456);

	student.print();
	myClock.setTime(7,15,25);
}
