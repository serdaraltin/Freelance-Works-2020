
#include "Vehicle.h"
Vehicle::Vehicle(int maxPassengerNumber, double maxSpeed)
{
	this->maxSpeed = maxSpeed;
	this->maxPassengerNumber = maxPassengerNumber;
	this->engineStarted = false;
	this->currentSpeed = 0;
	this->currentPassengerNumber = 0;
}
Vehicle::~Vehicle()
{
}

bool Vehicle::Accelarate(double amount)
{
	if (engineStarted == false || currentSpeed == maxSpeed)
	{
		return false;
	}
	else
		currentSpeed += amount;
		return true;
}
bool Vehicle::Decelerate(double amount)
{
	if (engineStarted == false || currentSpeed == 0)
	{
		return false;
	}
	else
		currentSpeed -= amount;
		return true;
}
void Vehicle::StartEngine()
{

	cout << "Engine Started"<<endl;
	engineStarted = true;
	currentSpeed = 0;
}
void Vehicle::StopEngine()
{
	cout << "Engine Stopped"<<endl;
	engineStarted = false;
	currentSpeed = 0;
}
bool Vehicle::GetIn(int passengerNumber)
{
	if (currentSpeed > 0)
	{
		cout << "ERROR : Cannot Get-In the vehicle while moving "<<endl;
		return false;
	}
	else
		currentPassengerNumber += passengerNumber;
		return true;
}
bool Vehicle::GetOut(int passengerNumber)
{
	if (currentSpeed > 0)
	{
		cout << "ERROR : Cannot Get-Out the vehicle while moving "<<endl;
		return false;
	}
	else
		currentPassengerNumber -= passengerNumber;
	return true;
}

double Vehicle::getCurrentSpeed()
{
	return currentSpeed;
}

double Vehicle::getCurrentPassengerNumber()
{
	return currentPassengerNumber;
}

bool Vehicle::IsEngineStarted()
{
	return engineStarted;
}