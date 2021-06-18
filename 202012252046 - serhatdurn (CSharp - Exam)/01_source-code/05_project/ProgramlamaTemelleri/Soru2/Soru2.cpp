#include <stdio.h>
#include <string.h>

using namespace std;

char kelime[100];
char cumleDizisi[200];

void analiz()
{
	int a = 0;
	int b = 0;
	int adet = 0;
	int kelimeUzunlugu = strlen(kelime);

	while (cumleDizisi[a] != '\0')
	{
		if (cumleDizisi[a] == kelime[b])
		{
			while (cumleDizisi[a] == kelime[b] && cumleDizisi[a] != '\0')
			{
				a++;
				b++;
			}
			if (b == kelimeUzunlugu && (cumleDizisi[a] == ' ' || cumleDizisi[a] == '\0'))
			{
				adet++;
			}
		}
		else
		{
			while (cumleDizisi[a] != ' ')
			{
				a++;
				if (cumleDizisi[a] == '\0')
					break;
			}
		}
		a++;
		b = 0;
	}

	printf("Analiz Sonucu: Girdiginiz cumlede %d tane %s sozcugu bulunmaktadir\n", adet, kelime);
}

int main()
{
	while (1) {
		printf("1-Sozcuk gir\n");
		printf("2-Cumle gir\n");
		printf("3-Analiz\n");
		printf("4-Cikis\n\n");
		printf("Seciminiz:");
		int secim;
		scanf("%d", &secim);
		if (secim == 1)
		{
			printf("Sozcuk giriniz:");
			scanf("%s", kelime);
		}
		else if (secim == 2)
		{
			printf("Cumle giriniz:");
			scanf(" %[^\n]", cumleDizisi);
		}
		else if (secim == 3)
			analiz();
		else if (secim == 4)
		{
			printf("Programdan cikiliyor...\a");
			return 0;
		}
		else
			printf("Hatali secim, tekrar deneyiniz\a");

		printf("\a");
	}
	return 0;
}

