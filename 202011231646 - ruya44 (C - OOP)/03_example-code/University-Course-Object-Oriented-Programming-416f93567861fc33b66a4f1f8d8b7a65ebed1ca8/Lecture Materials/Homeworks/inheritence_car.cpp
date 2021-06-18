#include <iostream>
using namespace std;

class Vehicle           //Base Class
{
    int wheelNum;       //only base class can access
    float weight;       //only base class can access
    
public:
    Vehicle (int );     //Constructor Function of Vehicle class.
    ~Vehicle()          //Destructor Function of Vehicle class.
    {
        cout<<"Destructor of Vehicle!\n";
    }
    void setWheelNum(int wheel){        //All can access, because it is public function.
        wheelNum = wheel;
    }
    void print() const {                //All can access, because it is public function.
        cout<<"wheelNum=\t"<<wheelNum<<"\n";
    }
    
    void setWeight (float w){           //All can access, because it is public function.
        weight = w;
    }
};//end Class Vehicle



class Car:public Vehicle            //Derived class from Vehicle(Base Class)
{
    int passengerNum;
public:
    Car (int, int );                     //Constructor Function of Car Class.
    ~Car()                               //Destructor Function of Car Class.
    {
        cout<<"Destructor of Car!\n";
    }
    void setPassengerNum (int passenger){
        passengerNum = passenger;
    }
    void print () const{
        Vehicle::print();           //Overrides print()
        cout<<"passengerNum=\t"<<passengerNum<<"\n";
    }
    
};

Vehicle::Vehicle(int wheel)
{
    wheelNum = wheel;
    cout<<"Vehicle constructor is called!\n";
}

Car::Car(int wheel, int passen):Vehicle(wheel)
{
    passengerNum = passen;
    cout<<"Car constructor is called!\n";
}

int main ()
{
    Car car1(3,4);
    
    
    return 0;
}
