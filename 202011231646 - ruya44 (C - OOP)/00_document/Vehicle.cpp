/// Vehicle.cpp
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
	// Implement the function
}
bool Vehicle::Decelerate(double amount)
{
	// Implement the function
}
void Vehicle::StartEngine()
{
	// Implement the function
}
void Vehicle::StopEngine()
{
	// Implement the function
}
bool Vehicle::GetIn(int passengerNumber)
{
	// Implement the function
}
bool Vehicle::GetOut(int passengerNumber)
{
	// Implement the function
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