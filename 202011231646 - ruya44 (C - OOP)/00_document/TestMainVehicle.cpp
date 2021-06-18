/// VehicleTestMain.cpp
#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"

/// <summary>
/// Acceleration Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="amount">The amount.</param>
void TEST_Acceleration(Vehicle& vehicle, double amount)
{
	double previousSpeed = vehicle.getCurrentSpeed();
	if (vehicle.Accelarate(amount))
	{
		cout << "SUCCESS : Accelerated " << endl;
		cout << "Previous Speed : " << previousSpeed << " Current Speed : " <<
			vehicle.getCurrentSpeed() << endl;
	}
	else
	{
		cout << "FAILURE : Could not accelerated" << endl;
	}
}

/// <summary>
/// Deceleration Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="amount">The amount.</param>
void TEST_Deceleration(Vehicle& vehicle, double amount)
{
	// Implement the function
}

/// <summary>
/// GetIn Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="passengerNumber">The passenger number.</param>
void TEST_GetIn(Vehicle& vehicle, int passengerNumber)
{
	// Implement the function
}

/// <summary>
/// Get Out Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="passengerNumber">The passenger number.</param>
void TEST_GetOut(Vehicle& vehicle, int passengerNumber)
{
	// Implement the function
}

/// <summary>
/// Start Engine Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
void TEST_StartEngine(Vehicle& vehicle)
{
	// Implement the function
}

/// <summary>
/// Stop Engine Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
void TEST_StopEngine(Vehicle& vehicle)
{
	// Implement the function
}

/// <summary>
/// Main function.
/// </summary>
/// <returns></returns>
int main()
{
	cout << "+-----------------------+" << endl
		<< "| TEST OF FIRST VEHICLE |" << endl
		<< "+-----------------------+" << endl;
	Vehicle vehicle1(4, 220);
	vehicle1.StartEngine();
	TEST_Acceleration(vehicle1, 30);
	TEST_Deceleration(vehicle1, 20);
	TEST_GetIn(vehicle1, 2);
	TEST_GetOut(vehicle1, 1);
	vehicle1.StopEngine();

	cout << "+------------------------+" << endl
		<< "| TEST OF SECOND VEHICLE |" << endl
		<< "+------------------------+" << endl;
	Vehicle vehicle2(5, 180);
	TEST_Acceleration(vehicle2, 30);
	TEST_Deceleration(vehicle2, 20);
	TEST_GetIn(vehicle2, 2);
	TEST_GetOut(vehicle2, 1);
	return 0;
}