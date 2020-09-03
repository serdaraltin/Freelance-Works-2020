#include <stdio.h>
#include <time.h>

int ZarlariAt();

int main(){
	srand(time(NULL));

	while(1){

		int zarToplam = ZarlariAt();
		printf("Zarlar atiliyor... %d ",zarToplam);

		if(zarToplam == 11 || zarToplam == 7){
			printf("Kazandiniz\n");
		}
		else if (zarToplam == 2 || zarToplam == 3 || zarToplam == 12){
			 printf("Kaybettiniz\n");	
		}
		else{
			printf(" Sonuc belirsiz, tekrar zar atilacak. At (a/A)? ");
			char secim[2];
			scanf("%s",secim);
			if(secim[0] == 'A' || secim[0] == 'a'){	
				int tekrarAtma = 1;
				while(tekrarAtma == 1){

					int zarToplamTekrar = ZarlariAt();
					printf("Zarlar atiliyor... %d ",zarToplamTekrar);
					if(zarToplamTekrar == 7){
						 printf(" Kaybettiniz\n");
						 tekrarAtma = 0;
					}
					else if(zarToplamTekrar == zarToplam)
					{
						printf(" Kazandiniz\n");	
						tekrarAtma = 0;
					}
					else{
						printf(" Sonuc belirsiz, tekrar zar atilacak. At (a/A)? ");
						char secim[2];
						scanf("%s",secim);
						if(secim[0] == 'A' || secim[0] == 'a'){	
							continue;
						}
					}
				}

			}
		}
		

		printf("Yeni oyun oynansin mi (e/E - h/H)? ");
		char secim[2];
		scanf("%s",secim);
		if(secim[0] == 'h' || secim[0] == 'H')
			break;
		else if(!(secim[0] == 'e' || secim[0] == 'E'))
			break;
	}
	printf("CRAPS sona erdi.\n");
	system("pause");
	return 0;
} 

int ZarlariAt(){
	int zar1 = rand() % 6 + 1;
	int zar2 = rand() % 6 + 1;
	return (zar1+zar2);
}
