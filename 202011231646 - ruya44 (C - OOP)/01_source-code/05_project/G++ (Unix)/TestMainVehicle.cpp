//standart girdi cikti kutuphanesi
#include <iostream>
//ihtiyac yok
#include <string>
//baslik dosyasinda tanimli methodlari kullanmak icin                   
#include "Vehicle.h"
//windows sistemlerde bazý methodlarýn kullanýmý icin
#include <Windows.h>
//isim uzayinin belirlenmesi           
using namespace std;                

//ilgili parametreler ile arac nesnesinin degerinin degistirilmesi (hizlandirma)
void TEST_Acceleration(Vehicle& vehicle, double amount)
{
    double previousSpeed = vehicle.getCurrentSpeed();
    
    if (vehicle.Accelarate(amount))
    {
        cout << "SUCCESS : Accelerated " << endl;
        cout << "Previous Speed : "<< previousSpeed <<" Current Speed :  " << vehicle.getCurrentSpeed() << endl;
    }
    else
    {
        cout << "FAILURE : Could not accelerated" << endl;
    }
}

//ilgili parametreler ile arac nesnesinin degerinin degistirilmesi (yavaslatma)
void TEST_Deceleration(Vehicle& vehicle, double amount)
{
    double previousSpeed = vehicle.getCurrentSpeed();
    
    if (vehicle.Decelerate(amount))
    {
        cout << "SUCCESS : Decelerated " << endl;
        cout << "Previous Speed : "<< previousSpeed <<" Current Speed :  " << vehicle.getCurrentSpeed() << endl;
    }
    else
    {
        cout << "FAILURE : Could not decelerated" << endl;
    }
}

//ilgili parametreler ile arac nesnesinin degerinin degistirilmesi (araca yolcu ekleme)
void TEST_GetIn(Vehicle& vehicle, int passengerNumber)
{
    int previousPassengerNumber = vehicle.getCurrentPassengerNumber();
    
    if(vehicle.GetIn(passengerNumber))
    {
        cout << "SUCCESS : Got-In " << endl;
        cout << "Previous PassengerNumber : " << previousPassengerNumber << " Current PassengerNumber :  " << vehicle.getCurrentPassengerNumber() << endl;
    }
    else
    {
        cout << "FAILURE : Could not got-in" << endl;
    }
    
}

//ilgili parametreler ile arac nesnesinin degerinin degistirilmesi (aracatan yolcu cikarma)
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
    
}

//aracin motorunun baslatilmasi
void TEST_StartEngine(Vehicle& vehicle)
{
    vehicle.StartEngine();
}

//aracin motorunun durdurulmasi
void TEST_StopEngine(Vehicle& vehicle)
{
    vehicle.StopEngine();
}

//ana method - test verileri
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
	//herhangi bir tusa kadar bekleme
	system("pause");
    return 0;
}
