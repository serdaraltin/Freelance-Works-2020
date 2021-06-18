#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sozcuk[100];
char cumle[200];

void menu();

void analiz()
{
    int n = 0;
    int m = 0;
    int adet = 0;
    int uzunluk = strlen(sozcuk);

    while (cumle[n] != '\0')
    {
        if (cumle[n] == sozcuk[m])
        {
            while (cumle[n] == sozcuk[m] && cumle[n] != '\0')
            {
                n++;
                m++;
            }
            if (m == uzunluk && (cumle[n] == ' ' || cumle[n] == '\0'))
            {
                adet++;
            }
        }
        else
        {
            while (cumle[n] != ' ')
            {
                n++;
                if (cumle[n] == '\0')
                    break;
            }
        }
        n++;
        m = 0;
    }

    printf("Analiz Sonucu: Girdiginiz cumlede %d tane %s sozcugu bulunmaktadir\n", adet, sozcuk);
}



int main()
{
    while(1){
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
            scanf("%s", sozcuk);
        }
        else if (secim == 2)
        {
            printf("Cumle giriniz:");
            scanf(" %[^\n]",cumle);
        }
        else if (secim == 3)
            analiz();
        else if (secim == 4)
        {
            printf("Programdan cikiliyor...\n");
            exit(0);
        }
        else 
            printf("Hatali secim, tekrar deneyiniz\n");
        
        printf("\n");
    }
}

