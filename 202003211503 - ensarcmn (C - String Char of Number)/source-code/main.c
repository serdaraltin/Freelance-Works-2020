#include <stdio.h>
#include <stdlib.h>

int main()
{
	while(1)
	{
		
	int i = 0; 
	char ascii[255] = {};
	char sayilar[255] = {};
	for (i = 0; i < 255; i++)
	{
		ascii[i] = '\0';
		sayilar[i] = 0;
	}
	
    char *girilen = (char *)malloc(sizeof(char)*50);

    printf("Karakterler girin: ");
    scanf("%s",girilen);

	printf("Sonuc: ");
 	i=0;
    while(girilen[i] != '\0')
    {
    	char secilen = girilen[i];

    	int sayi = 1;
    	int j = i+1;
    	while(girilen[j] == secilen && girilen[j] != '\0')
    	{
    		sayi++;
    		i = j++;
    	}
  		printf("%d%c",sayi,secilen );
    	i++;
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
	//system("pause");
    return 0;
}

