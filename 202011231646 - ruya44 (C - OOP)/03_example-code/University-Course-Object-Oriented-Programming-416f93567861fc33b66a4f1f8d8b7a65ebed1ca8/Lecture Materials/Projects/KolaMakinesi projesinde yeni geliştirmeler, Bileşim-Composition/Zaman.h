#ifndef  ZAMAN
#define ZAMAN
#include <ctime>

class Zaman {
public:
	Zaman();
	~Zaman();
	void guncelle();
	void goster();
	
private:
	int saat;
	int dakika;
	int saniye;
	time_t simdi;
	tm *zaman;
};

#endif

