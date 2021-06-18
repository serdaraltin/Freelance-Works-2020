#include "KolaMakinesi.h"

int main() {
	{
		KolaMakinesi makine;

		makine.ilkYukleme(1.5, 50);

		makine.goster();

		makine.kolaVerme();

		makine.goster();
	}
	return 0;
}