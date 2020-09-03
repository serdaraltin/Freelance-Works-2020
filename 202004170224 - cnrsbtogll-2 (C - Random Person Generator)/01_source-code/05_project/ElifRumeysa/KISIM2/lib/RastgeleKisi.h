#ifndef KISIURET_H
#define KISIURET_H
#include "Kisi.h"
#include "KimlikNo.h"
#include "Telefon.h"
#include "IMEINo.h"
#include "Rastgele.h"
typedef struct kisi {
    char KimlikNo[15];char AdSoyad[100]; int Yas; char Telefon[15]; char IMEINo[20];
}Kisi;
void kisiuret(Kisi* p) {TUret(p->Telefon);
    IMUret(p->IMEINo);tcUret(p->KimlikNo);
    p->Yas = rast(1,100);RastKisi(p->AdSoyad);}
#endif 

