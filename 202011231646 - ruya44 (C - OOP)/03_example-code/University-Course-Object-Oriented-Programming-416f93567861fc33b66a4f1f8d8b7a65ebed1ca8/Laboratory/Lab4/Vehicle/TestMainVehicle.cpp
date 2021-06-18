/*****************************************
 * VehicleTestMain.cpp                   *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/

#include <iostream>                 //To use standart input output
#include <string>                   //Was not used.
#include "Vehicle.h"                //To use functions which are declared in Vehicle.h.
using namespace std;                //To use standart input and output functions under the "std" namespace.

/// <summary>
/// Acceleration Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="amount">The amount.</param>
    //Checks whether the vehicle accelerated or not.
void TEST_Acceleration(Vehicle& vehicle, double amount)
{
    double previousSpeed = vehicle.getCurrentSpeed();
    
    if (vehicle.Accelarate(amount))
    {
        cout << "SUCCESS : Accelerated " << endl;
        cout << "Previous Speed : "<< previousSpeed <<" Current Speed :  "<<
        vehicle.getCurrentSpeed() << endl;
    }
    
    else
    {
        cout << "FAILURE : Could not accelerated" << endl;
    }
}//end TEST_Acceleration()

/// <summary>
/// Deceleration Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
    //Checks whether the vehicle decelerated or not.
void TEST_Deceleration(Vehicle& vehicle, double amount)
{
    double previousSpeed = vehicle.getCurrentSpeed();
    
    if (vehicle.Decelerate(amount))
    {
        cout << "SUCCESS : Decelerated " << endl;
        cout << "Previous Speed : "<< previousSpeed <<" Current Speed :  "<<
        vehicle.getCurrentSpeed() << endl;
    }
    else
    {
        cout << "FAILURE : Could not decelerated" << endl;
    }
}//end TEST_Deceleration()

/// <summary>
/// GetIn Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="passengerNumber">The passenger number.</param>
    //Checks whether the passengers get in car or not.
void TEST_GetIn(Vehicle& vehicle, int passengerNumber)
{
    int previousPassengerNumber = vehicle.getCurrentPassengerNumber();
    
    if(vehicle.GetIn(passengerNumber))
    {
        cout << "SUCCESS : Got-In " << endl;
        cout << "Previous PassengerNumber : "<< previousPassengerNumber <<" Current PassengerNumber :  "<<
        vehicle.getCurrentPassengerNumber() << endl;
    }
    else
    {
        cout << "FAILURE : Could not got-in" << endl;
    }
    
}//end TEST_GetIn()

/// <summary>
/// Get Out Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
/// <param name="passengerNumber">The passenger number.</param>
    //Checks whether the passengers get out car or not.
void TEST_GetOut(Vehicle& vehicle, int PassengerNumber)
{
    int previousPassengerNumber = vehicle.getCurrentPassengerNumber();
    
    if(vehicle.GetOut(PassengerNumber))
    {
        cout << "SUCCESS : Got-In " << endl;
        cout << "Previous PassengerNumber : "<< previousPassengerNumber <<" Current PassengerNumber :  "<<
        vehicle.getCurrentPassengerNumber() << endl;
    }
    else{
        cout << "FAILURE : Could not got-out" << endl;
    }
    
}//end TEST_GetOut ()

/// <summary>
/// Start Engine Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
void TEST_StartEngine(Vehicle& vehicle)
{
    
}//end TEST_StartEngine()

/// <summary>
/// Stop Engine Test.
/// </summary>
/// <param name="vehicle">The vehicle.</param>
void TEST_StopEngine(Vehicle& vehicle)
{
    
}//end TEST_StopEngine

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
}//end main ()
