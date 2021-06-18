#pragma once
//standart girdi cikti kutuphanesi
#include <iostream>
//isim uzayinin belirlenmesi                      
using namespace std;                

//Vehicle sinifi
class Vehicle
{

public:
//kurucu methodunun tanimlanmasi
    Vehicle(int maxPassengerNumber = 4, double maxSpeed = 180);

//ilgili methodlarin tanimlanmasi
    bool Accelarate(double amount);

    bool Decelerate(double amount);

    double getCurrentPassengerNumber();

    double getCurrentSpeed();

    bool GetIn(int passengerNumber);

    bool GetOut(int passengerNumber);

    void StartEngine();
    
    void StopEngine();

    bool IsEngineStarted();

//yikici methodunun sanal olarak tanimlanmasi
    virtual ~Vehicle();
    
//ozel degiskenlerin tanimlanmasi
private:

    int currentPassengerNumber;

    double currentSpeed;

    bool engineStarted;

    int maxPassengerNumber;

    double maxSpeed;
};
