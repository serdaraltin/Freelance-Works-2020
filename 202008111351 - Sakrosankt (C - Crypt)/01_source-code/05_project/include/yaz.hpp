
void ListPrint(struct Dugum* bas_dugum){
	struct Dugum *gecici = bas_dugum; 
  
    printf("Sifre: "); 
    while (gecici->soltaraf != bas_dugum) 
    { 

        printf("%c", gecici->sayi); 
        gecici = gecici->soltaraf; 
    } 
    printf("%c\n", gecici->sayi); 
} 
