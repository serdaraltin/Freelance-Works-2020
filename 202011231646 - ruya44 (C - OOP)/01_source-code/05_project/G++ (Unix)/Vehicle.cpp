//method bildirimlerinin bulundugu baslik dosyasinin dahil edilmesi
#include "Vehicle.h"

//kurucu method - maksimum yolcu sayisi ve maksimum hiz degerlerini alarak araci yapilandirma
Vehicle::Vehicle(int maxPassengerNumber, double maxSpeed)
{
    this->maxSpeed = maxSpeed;
    this->maxPassengerNumber = maxPassengerNumber;
    this->engineStarted = false;
    this->currentSpeed = 0;
    this->currentPassengerNumber = 0;
    //this->airConditionDegree = 22;
}

//yikici method - kullanima ihtiyac yok
Vehicle::~Vehicle()
{
    
}

//hizlandirici method - ilgili parametreden gelen deger ile aracin hizlandirimasi
bool Vehicle::Accelarate(double amount)
{	
	//aracin calisma durumunun kontrolu ve maksimumum hizda olmama durumlarinin kontrolu
    if(IsEngineStarted() && currentSpeed<maxSpeed)
    {
        //eger eklenecek hizlanma degeri ile arac maksimum hizi gecmiyorsa
        if(amount>=maxSpeed || (currentSpeed+amount >= maxSpeed) )
        	//mevcut hizin maksimuma cikarilmasi
            this->currentSpeed = maxSpeed;
        //ustteki kosul saglanmiyorsa
        else 
        	//mevcut hiz degeri uzerinde hizlanma degerinin eklenmesi
            this->currentSpeed = currentSpeed + amount;
        return true;
    }
    
    return false;
    
}

//yavaslatici method - ilgili parametreden gelen deger ile aracin yavaslatilmasi
bool Vehicle::Decelerate(double amount)
{
    //aracin calisma durumunun kontrolu ve aracin hiz degeririn 0 dan buyuk olma durumu kontrolu
    if(IsEngineStarted() && currentSpeed>0)
    {
        //eger cikarilacak hiz degeri sonucu sifir degilse
        if(amount>=currentSpeed || (currentSpeed-amount <= 0) )
        	//mevcut hizin 0 yapilmasi
            this->currentSpeed = 0;
        //ustteki kosul saglanmiyosa
        else
        	//mevcut hiz degerinden yavaslama degerinin cikarilmasi
            this->currentSpeed = currentSpeed - amount;
        return true;
    }
    return false;
}

//motor baslatma method - aracin motorunun calistirilmasi
void Vehicle::StartEngine()
{
    cout << "Engine Started." << endl;
    //motor calisma degerinin aktif edilmesi
    engineStarted = true;
}

//motor durdurma method - aracin motorunun durdurulmasi
void Vehicle::StopEngine()
{
    cout << "Engine Stopped." << endl;
    //motor calisma degerinin pasif edilmesi
    engineStarted = false;
}

//yolcu ekleme method - ilgili parametredeki deger kadar yolcuyu araca ekleme
bool Vehicle::GetIn(int passengerNumber)
{
    //eger arac hareket ediyor ve eklenecek yolcu sayisi maksimum yolcu sayisini gecmiyorsa
    if( currentSpeed==0 && currentPassengerNumber+passengerNumber <= maxPassengerNumber )
    {
    	//mevcut yolcu degerine yeni yolcu degerinin eklenmesi
        currentPassengerNumber = currentPassengerNumber + passengerNumber;
        return true;
    }
    //ustteki kosul saglanmamasi durumunda bilgi metninin yazdirilmasi
    cout<<"ERROR : Cannot Get-In the vehicle while moving."<<endl;
    return false;
}

//yolcu cikarma method - ilgili parametredeki deger kadar yolcuyu aractan cikarma
bool Vehicle::GetOut(int passengerNumber)
{
    
    //eger arac hareket ediyor ve mevcut yolcu sayisi 0 dan farkli ve cikarilacak yolcu sayisi mevcut yolcu sayisindan buyuk degilse
    if( currentSpeed==0 && currentPassengerNumber != 0 && currentPassengerNumber >= passengerNumber )
    {
    	//mevcut yolcu degerinden ilgili yolcu degerinin cikarilmasi
        currentPassengerNumber = currentPassengerNumber - passengerNumber;
        return true;
    }
    //ustteki kosul saglanmamasi durumunda bilgi metninin yazdirilmasi
    cout<<"ERROR : Cannot Get-Out the vehicle while moving."<<endl;
    return false;
}//end Vehicle::GetOut ()

//aracin mevcut hiz degerinin dondurulmesi (cagrilan yere)
double Vehicle::getCurrentSpeed()
{
    return currentSpeed;
}

//aracin mevcut yolcu degerinin dondurulmesi (cagrilan yere)
double Vehicle::getCurrentPassengerNumber()
{
    return currentPassengerNumber;
}

//aracin motorunun calisma durumunun dondurulmesi (cagrilan yere) - calisiyorsa true / degilse false 
bool Vehicle::IsEngineStarted()
{
    return engineStarted;
}
