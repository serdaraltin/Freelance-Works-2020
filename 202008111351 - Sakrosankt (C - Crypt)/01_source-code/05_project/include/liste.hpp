
struct Dugum 
{ 
    int sayi; 
    struct Dugum *soltaraf; 
    struct Dugum *sagtaraf; 
}; 

void EnsonEkle(struct Dugum** bas_dugum, int sayi) { 
  
    if (*bas_dugum == NULL) { 
        struct Dugum* dugum_yeni = new Dugum; 
        dugum_yeni->sayi = sayi; 
        dugum_yeni->soltaraf = dugum_yeni->sagtaraf = dugum_yeni; 
        *bas_dugum = dugum_yeni; 
        return; 
    } 

    Dugum *enson_dugum = (*bas_dugum)->sagtaraf; 

    struct Dugum* dugum_yeni = new Dugum; 
    dugum_yeni->sayi = sayi; 
    dugum_yeni->soltaraf = *bas_dugum; 
    (*bas_dugum)->sagtaraf = dugum_yeni; 
    dugum_yeni->sagtaraf = enson_dugum; 
    enson_dugum->soltaraf = dugum_yeni; 
} 
  

void EnbasaEkle(struct Dugum** bas_dugum, int sayi) { 
    
    struct Dugum *enson_dugum = (*bas_dugum)->sagtaraf; 
  
    struct Dugum* dugum_yeni = new Dugum; 
    dugum_yeni->sayi = sayi;  
    dugum_yeni->soltaraf = *bas_dugum; 
    dugum_yeni->sagtaraf = enson_dugum; 
  
    enson_dugum->soltaraf = (*bas_dugum)->sagtaraf = dugum_yeni; 

    *bas_dugum = dugum_yeni; 
} 
  

void ArdindanEkle(struct Dugum** bas_dugum, int sayi1,int sayi2) { 
    struct Dugum* dugum_yeni = new Dugum; 
    dugum_yeni->sayi = sayi1;
    
    struct Dugum *gecici = *bas_dugum; 
    while (gecici->sayi != sayi2) 
        gecici = gecici->soltaraf; 
    struct Dugum *soltaraf = gecici->soltaraf; 
  
    gecici->soltaraf = dugum_yeni; 
    dugum_yeni->sagtaraf = gecici; 
    dugum_yeni->soltaraf = soltaraf; 
    soltaraf->sagtaraf = dugum_yeni; 
} 
  
  
void SifreGoster(struct Dugum* bas_dugum) 
{ 
    struct Dugum *gecici = bas_dugum; 
  
    printf("\n--------------------------\n"); 
    while (gecici->soltaraf != bas_dugum) 
    { 
        printf("|%d|<->", gecici->sayi); 
        gecici = gecici->soltaraf; 
    } 
    printf("|%d|\n", gecici->sayi); 
}  
