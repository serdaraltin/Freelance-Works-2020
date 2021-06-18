#include "Zaman.h"
#include <iostream>

Zaman::Zaman() {
	simdi = time(0);
	guncelle();
	std::cout << "Zaman Constructor" << std::endl;
}

Zaman::~Zaman()
{
	std::cout << "Zaman Destructor" << std::endl;
}

void Zaman::guncelle() {
	zaman = localtime(&simdi);
	saat = 1 + zaman->tm_hour;
	dakika = 1 + zaman->tm_min;
	saniye = 1 + zaman->tm_sec;
}

void Zaman::goster()
{
	std::cout << saat << ":" << dakika << ":" << saniye;
}
