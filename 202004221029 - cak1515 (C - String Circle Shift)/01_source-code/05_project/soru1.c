#include <stdio.h>
#include <string.h>

void cevir(char *metin, size_t bas, size_t son) {
	while (bas < son) {
		son--;
		char gecici = metin[bas];
		metin[bas] = metin[son];
		metin[son] = gecici;
		bas++;
	}
}

void kaydir(char *metin, size_t amt) {
	size_t metin_sz = strlen(metin);
	amt %= metin_sz;
	cevir(metin, 0, amt);
	cevir(metin, amt, metin_sz);
	cevir(metin, 0, metin_sz);
}

static char girdi[512];

int main(void) {
	printf("Metni Giriniz : ");

	while (scanf("%s", girdi) == 1) {
		size_t amt;
		printf("Kaydirma Sayisi : ");
		scanf("%zu", &amt);
		kaydir(girdi, amt);
		printf("Sonuc : %s\n", girdi);
	}

	return 0;
}