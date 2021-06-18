#include "Tarih.h"
#include <iostream>

Tarih::Tarih() {
	simdi = time(0);
	guncelle();
	std::cout << "Tarih Constructor" << std::endl;
}

Tarih::~Tarih()
{
	std::cout << "Tarih Destructor" << std::endl;
}

void Tarih::guncelle() {
	zaman = localtime(&simdi);
	yil = 1900 + zaman->tm_year;
	ay = 1 + zaman->tm_mon;
	gun = zaman->tm_mday;
}

void Tarih::goster()
{
	std::cout << gun << "/" << ay << "/" << yil;
}
