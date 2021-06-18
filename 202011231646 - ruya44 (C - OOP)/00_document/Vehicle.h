// Vehicle.h
#pragma once
#include <iostream>
using namespace std;
class Vehicle
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Vehicle"/> class.
	/// </summary>
	/// <param name="maxPassengerNumber">The maximum passenger number.</param>
	/// <param name="maxSpeed">The maximum speed.</param>
	Vehicle(int maxPassengerNumber = 4, double maxSpeed = 180);


	/// <summary>
	/// Finalizes an instance of the <see cref="Vehicle"/> class.
	/// </summary>
	virtual ~Vehicle();


	/// <summary>
	/// Accelarates by specified amount.
	/// </summary>
	/// <param name="amount">The amount.</param>
	/// <returns></returns>
	bool Accelarate(double amount);


	/// <summary>
	/// Decelerates by specified amount.
	/// </summary>
	/// <param name="amount">The amount.</param>
	/// <returns></returns>
	bool Decelerate(double amount);


	/// <summary>
	/// Starts the engine.
	/// </summary>
	void StartEngine();


	/// <summary>
	/// Stops the engine.
	/// </summary>
	void StopEngine();


	/// <summary>
	/// Gets the in.
	/// </summary>
	/// <param name="passengerNumber">The passenger number.</param>
	/// <returns></returns>
	bool GetIn(int passengerNumber);


	/// <summary>
	/// Gets the out.
	/// </summary>
	/// <param name="passengerNumber">The passenger number.</param>
	/// <returns></returns>
	bool GetOut(int passengerNumber);


	/// <summary>
	/// Gets the current speed.
	/// </summary>
	/// <returns></returns>
	double getCurrentSpeed();


	/// <summary>
	/// Gets the current passenger number.
	/// </summary>
	/// <returns></returns>
	double getCurrentPassengerNumber();


	/// <summary>
	/// Determines whether [is engine started].
	/// </summary>
	/// <returns></returns>
	bool IsEngineStarted();

private:

	/// <summary>
	/// The engine started
	/// </summary>
	bool engineStarted;

	/// <summary>
	/// The current speed
	/// </summary>
	double currentSpeed;

	/// <summary>
	/// The current passenger number
	/// </summary>
	int currentPassengerNumber;

	/// <summary>
	/// The maximum passenger number
	/// </summary>
	int maxPassengerNumber;

	/// <summary>
	/// The maximum speed
	/// </summary>
	double maxSpeed;
};

