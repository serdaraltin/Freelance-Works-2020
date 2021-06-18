#ifndef  HATAYONETICISI
#define HATAYONETICISI

#include "Zaman.h"
#include "Tarih.h"
#include <string>

enum KAYITTURU {
	DOSYA = 0,
	EKRAN
};

class HataYoneticisi {
public:
	HataYoneticisi(KAYITTURU kayitTur=EKRAN);
	void kaydet(std::string msg);
	~HataYoneticisi();
private:
	Tarih tarih;
	Zaman zaman;
	KAYITTURU kayitTuru;
};

#endif