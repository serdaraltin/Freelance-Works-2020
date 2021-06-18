#ifndef  TARIH
#define TARIH

#include <ctime>

//Tarih adında bir sınıf var.
class Tarih {
public:
	Tarih();
	~Tarih();
	void guncelle();
	void goster();

private:
	int yil;
	int ay;
	int gun;
    
    //  time_t sayısal bir tip (genllikle long int) olup zaman bilgisini temsil eder.
	time_t simdi;
	tm *zaman;
};

#endif

