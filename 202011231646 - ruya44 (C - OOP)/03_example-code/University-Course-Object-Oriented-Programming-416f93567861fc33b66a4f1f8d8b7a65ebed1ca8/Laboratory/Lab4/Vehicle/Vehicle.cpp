/*****************************************
 * Vehicle.cpp                           *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/


#include "Vehicle.h"                        //To know function prototypes of Vehicle class.

//Constructor function of Vehicle class. Initializes member variables (private).
Vehicle::Vehicle(int maxPassengerNumber, double maxSpeed)
{
    this->maxSpeed = maxSpeed;
    this->maxPassengerNumber = maxPassengerNumber;
    this->engineStarted = false;
    this->currentSpeed = 0;
    this->currentPassengerNumber = 0;
    //this->airConditionDegree = 22;
}//end Vehicle ()

//Destructor function of Vehicle class.
Vehicle::~Vehicle()
{
    
}//end ~Vehicle ()

//Acceleration of the car depends on the engine status, if engine is not started, accelerate function returns false.
bool Vehicle::Accelarate(double amount)
{
    //Acceleration limit also depends on the maxSpeed of the vehicle.
    
    if(IsEngineStarted() && currentSpeed<maxSpeed)
    {
        //If any attempt to increase the speed of the vehicle to a higher value than maxSpeed,
        //just set the currentSpeed to maxSpeed value.
        if(amount>=maxSpeed || (currentSpeed+amount >= maxSpeed) )
            this->currentSpeed = maxSpeed;
        
        else
            this->currentSpeed = currentSpeed + amount;
        
        return true;
    }//end if
    
    return false;
    
}//end Vehicle::Accelarate ()

//Deceleration of the car depends on the engine status, if engine is not started, decelerate function returns false.
bool Vehicle::Decelerate(double amount)
{
    //Deceleration limit also depends on the currentSpeed of the vehicle.
    
    if(IsEngineStarted() && currentSpeed>0)
    {
        //If any attempt to decrease the speed of the vehicle to a higher value than currentSpeed,
        //just set the currentSpeed to 0 value.
        if(amount>=currentSpeed || (currentSpeed-amount <= 0) )
            this->currentSpeed = 0;
        
        else
            this->currentSpeed = currentSpeed - amount;
        
        return true;
    }//end if
    
    return false;
}//end Vehicle::Decelerate ()

//Prints a message on the screen and set the bool member variable called engineStarted true.
void Vehicle::StartEngine()
{
    cout<<"Engine Started."<<endl;
    engineStarted = true;
}//end Vehicle::StartEngine ()

//Prints a message on the screen and set the bool member variable called engineStarted false.
void Vehicle::StopEngine()
{
    cout<<"Engine Stopped."<<endl;
    engineStarted = false;
}//end Vehicle::StopEngine ()

//GetIn function depends on the currentSpeed and passengerCount.
bool Vehicle::GetIn(int passengerNumber)
{
    
    //If current speed is non-zero value, function returns false.
    //If the currentPassenger number is not enough to GetIn, prints an error message and returns false.
    if( currentSpeed==0 && currentPassengerNumber+passengerNumber <= maxPassengerNumber )
    {
        currentPassengerNumber = currentPassengerNumber + passengerNumber;
        //        cout<<"SUCCESS : Got-In"<<endl;
        return true;
    }
    
    cout<<"ERROR : Cannot Get-In the vehicle while moving."<<endl;
    return false;
}//end Vehicle::GetIn ()

//GetOut function depends on the currentSpeed and passengerCount.
bool Vehicle::GetOut(int passengerNumber)
{
    
    //If current speed is non-zero value, function returns false.
    //If the currentPassenger number is not enough to GetOut, prints an error message and returns false.
    if( currentSpeed==0 && currentPassengerNumber != 0 && currentPassengerNumber >= passengerNumber )
    {
        currentPassengerNumber = currentPassengerNumber - passengerNumber;
        //        cout<<"SUCCESS : Got-Out"<<endl;
        return true;
    }

    cout<<"ERROR : Cannot Get-Out the vehicle while moving."<<endl;
    return false;
}//end Vehicle::GetOut ()

//Returns currentSpeed(double) private member.
//(Accessor function, it should be const to don't change class's member.)
double Vehicle::getCurrentSpeed()
{
    return currentSpeed;
}//end Vehicle::getCurrentSpeed ()

//Returns currentPassengerNumber(double) private member.
//(Accessor function, it should be const to don't change class's member.)
double Vehicle::getCurrentPassengerNumber()
{
    return currentPassengerNumber;
}//end Vehicle::getCurrentPassengerNumber ()

//Returns engineStarted(bool) private member.
//(Accessor function, it should be const to don't change class's member.)
bool Vehicle::IsEngineStarted()
{
    return engineStarted;
}//end Vehicle::IsEngineStarted ()
