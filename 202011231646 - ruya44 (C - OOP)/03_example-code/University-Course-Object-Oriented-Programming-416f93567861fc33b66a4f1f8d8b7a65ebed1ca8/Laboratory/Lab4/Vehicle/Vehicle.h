/*****************************************
 * Vehicle.h                             *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/

/*
    In the C and C++ programming languages, " #pragma once " is a non-standard
 but widely supported preprocessor directive designed
 to cause the current source file to be included ONLY ONCE IN A SINGLE COMPILATION.
    " #pragma once " has several advantages, including:
 less code, avoidance of name clashes, and sometimes improvement in compilation speed.
 
 *** In this case, because of the #pragma once preprocessor directive (it works for Visual Studio),
 *** Vehicle.h file will compile just for once.
 */

#pragma once
#include <iostream>                 //To use standart input output
using namespace std;                //To use standart input and output functions under the "std" namespace.

class Vehicle
{
//Public members are accessible from anywhere where the object is visible.
public:
    
    /// <summary>
    /// Initializes a new instance of the <see cref="Vehicle"/> class.
    /// </summary>
    /// <param name="maxPassengerNumber">The maximum passenger number.</param>
    /// <param name="maxSpeed">The maximum speed.</param>
//Constructor function of Circle class, when a new object is created, it will be called.
    Vehicle(int maxPassengerNumber = 4, double maxSpeed = 180);
    
    /// <summary>
    /// </summary>
    /// <param name="amount">The amount.</param>
    /// <returns></returns>
//Acceleration of the car depends on the engine status, if engine is not started, accelerate function returns false.
    bool Accelarate(double amount);
    
    /// <summary>
    /// Decelerates by specified amount.
    /// </summary>
    /// <param name="amount">The amount.</param>
    /// <returns></returns>
//Deceleration of the car depends on the engine status, if engine is not started, decelerate function returns false.
    bool Decelerate(double amount);
    
    /*
     ***Private members of a class are accessible only from within other members of the same class.
     -->  That's why we create getter functions(also called accessor functions) to reach private members of an object
     -->  via these functions.
                +getCurrentPassengerNumber()
                +getCurrentSpeed()
                +IsEngineStarted()
     -->  (Private members will be returned but they shouldn't be changed).
     */
    
    /// <summary>
    /// Gets the current passenger number.
    /// </summary>
    /// <returns></returns>
//Returns currentPassengerNumber(double) private member.
//(Accessor function, it should be const to don't change class's member.)
    double getCurrentPassengerNumber();
    
    /// <summary>
    /// Gets the current speed.
    /// </summary>
    /// <returns></returns>
//Returns currentSpeed(double) private member.
//(Accessor function, it should be const to don't change class's member.)
    double getCurrentSpeed();
    
    /// <summary>
    /// Gets the in.
    /// </summary>
    /// <param name="passengerNumber">The passenger number.</param>
//GetIn function depends on the currentSpeed and passengerCount. Changes the passengerNumber. (Mutator function)
    bool GetIn(int passengerNumber);
    
    /// <summary>
    /// Gets the out.
    /// </summary>
    /// <param name="passengerNumber">The passenger number.</param>
    /// <returns></returns>
//GetOut function depends on the currentSpeed and passengerCount. Changes the passengerNumber. (Mutator function)
    bool GetOut(int passengerNumber);
    
    /// <summary>
    /// Starts the engine.
    /// </summary>
//Prints a message on the screen and set the bool member variable called engineStarted. (Mutator function)
    void StartEngine();
    
    /// <summary>
    /// Stops the engine.
    /// </summary>
//Prints a message on the screen and set the bool member variable called engineStarted. (Mutator function)
    void StopEngine();
    
    /// <summary>
    /// Determines whether [is engine started].
    /// </summary>
    /// <summary>
    /// The engine started
    /// </summary>
//Returns engineStarted(bool) private member.
//(Accessor function, it should be const to don't change class's member.)
    bool IsEngineStarted();
    
    /// <summary>
    /// Finalizes an instance of the <see cref="Vehicle"/> class.
    /// </summary>
//Destructor function of Vehicle class, when object is removed, it will be called.
    virtual ~Vehicle();
    
//Private members of a class are accessible only from within other members of the same class.
private:
    /// <summary>
    /// The current passenger number
    /// </summary>
    int currentPassengerNumber;
    
    /// <summary>
    /// The current speed
    /// </summary>
    double currentSpeed;
    
    /// <summary>
    /// The engine started
    /// </summary>
    bool engineStarted;
    
    /// <summary>
    /// The maximum passenger number
    /// </summary>
    int maxPassengerNumber;
    
    /// <summary>
    /// The maximum speed
    /// </summary>
    double maxSpeed;
};
