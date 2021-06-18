#pragma once
#include <iostream>
using namespace std;
class Vehicle
{
public:

	Vehicle(int maxPassengerNumber = 4, double maxSpeed = 180);

	virtual ~Vehicle();

	bool Accelarate(double amount);

	bool Decelerate(double amount);

	void StartEngine();

	void StopEngine();

	bool GetIn(int passengerNumber);

	bool GetOut(int passengerNumber);

	double getCurrentSpeed();

	double getCurrentPassengerNumber();

	bool IsEngineStarted();

private:

	bool engineStarted;

	double currentSpeed;

	int currentPassengerNumber;

	int maxPassengerNumber;

	double maxSpeed;
};
