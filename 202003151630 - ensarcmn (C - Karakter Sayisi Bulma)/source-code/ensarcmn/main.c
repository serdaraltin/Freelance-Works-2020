#include <stdio.h>
#include <stdlib.h>

int main()
{
	while(1){


	int i = 0; 
	char ascii[255] = {};
	char sayilar[255] = {};
	for (int i = 0; i < 255; i++)
	{
		ascii[i] = '\0';
		sayilar[i] = 0;
	}
	
    char *girilen = (char *)malloc(sizeof(char)*50);

    printf("Karakterler girin: ");
    scanf("%s",girilen);

 	i=0;
    while(girilen[i] != '\0')
    {
    	char secilen = girilen[i];
    	if(sayilar[(int)secilen] != 0)
    	{
    		i++;
    		continue;
    	}

    	int j = i,sayi = 0;
    	while(girilen[j] != '\0'){
    		if(secilen == girilen[j]){
    			
    			sayi++;
    		}
    		j++;
    	}
    	ascii[(int)secilen] = secilen;
    	sayilar[(int)secilen] = sayi;
    	//printf("%d -> %c\n",sayilar[(int)secilen],ascii[(int)secilen]);
    	i++;
    }

	printf("Sonuc: ");
	for (i = 0; i < 255; i++)
	{
		if(sayilar[i] != 0){
			printf("%d%c",sayilar[i],ascii[i]);
		}
	}
	printf("\n");

	while(1){
	printf("Devam (d/D - b/B)?: ");
	char soru[2];
	scanf("%s",soru);
		if(soru[0] == 'd' || soru[0] == 'D'){
			break;
		}
		else if(soru[0] == 'b' || soru[0] == 'B')
		{
			printf("Program sonlandi....\n");
			return 0;
		}	
	}
	}
	system("pause");
    return 0;
}
