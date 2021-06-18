#include "HataYoneticisi.h"
#include <iostream>

HataYoneticisi::HataYoneticisi(KAYITTURU kayitTur) :kayitTuru(kayitTur) {
	std::cout << "HataYoneticisi Constructor" << std::endl;
}

HataYoneticisi::~HataYoneticisi()
{
	std::cout << "Hata Destructor" << std::endl;

}
void HataYoneticisi::kaydet(std::string msg) {

	if (kayitTuru == DOSYA) {
		std::cout << "(DOSYA)";
	}
	else {
		std::cout << "(EKRAN)";
	}
	tarih.goster();
	std::cout << ", ";
	zaman.goster();
	std::cout << "->" << msg << std::endl;

}
