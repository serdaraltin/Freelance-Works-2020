#ifndef KOLAMAKINESI
#define KOLAMAKINESI
#include "HataYoneticisi.h"

class KolaMakinesi{
public:
	KolaMakinesi(KAYITTURU kayit=DOSYA);
	KolaMakinesi(float, int, KAYITTURU kayit = DOSYA);
	~KolaMakinesi();
	//void ilkYukleme(float fiyati, int kolaSayisi);
	void ilkYukleme(float fiyati, int kolaSayisi);
	void kolaVerme();
	void goster() const;
private:
	//const 
	float fiyat;
	int sayi;
	HataYoneticisi  hata;
};

#endif
