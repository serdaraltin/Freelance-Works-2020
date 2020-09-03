void DosyaIslem(char dosya_adi[20]){
	FILE* dosya_isretcisi;
	int onbellek_uzunluk = 8000;
	char onbellek[onbellek_uzunluk];

	dosya_isretcisi = fopen(dosya_adi, "r");

	while(fgets(onbellek, onbellek_uzunluk, dosya_isretcisi)) {
		int *array = (int*)malloc(sizeof(int)*512);
		
		char bosluk_karakter[2] = " ";
		char *strtoken;
		strtoken = strtok(onbellek,bosluk_karakter);

		int i = 0;
		while(strtoken != NULL){
			array[i++] = atoi(strtoken);
			strtoken = strtok(NULL,bosluk_karakter);
		}

		int maxEbob = 0;
		struct Dugum* bas_dugum = NULL;
		
	    int j;

	    for(j=0; j<i; j++){

	    	if(j==0){
	    		EnsonEkle(&bas_dugum, array[0]); 
				continue;
	    	}

	    	if(maxEbob < Ebob(bas_dugum->sayi,array[j])){

	    		maxEbob = Ebob(bas_dugum->sayi,array[j]);

	    		int mod;
	    		if(array[j] > bas_dugum->sayi)
	    			mod = array[j] % bas_dugum->sayi;
	    		else
	    			mod = bas_dugum->sayi % array[j];
	    		
	    		if(mod == 0){
	    			ArdindanEkle(&bas_dugum,array[j],bas_dugum->sayi);
	    			continue;
	    		}
	    		else{
	    			int i=0;
	    			struct Dugum *gecici = bas_dugum;
	    			while(i++<mod)
	    				gecici = gecici->sagtaraf;
	    			if(gecici == bas_dugum){
	    				EnbasaEkle(&bas_dugum,array[j]);
	    				continue;
	    			}
	    		}
	    	}
	    	else{
	    		
	    		struct Dugum *gecici = bas_dugum;
	    		while(Ebob(gecici->sayi,array[j]) < maxEbob && gecici->soltaraf != bas_dugum){
	    			gecici = gecici->soltaraf;
	    		}
	    		int mod;
	    		if(array[j] > gecici->sayi)
	    			mod = array[j] % gecici->sayi;
	    		else
	    			mod = gecici->sayi % array[j];
	    		
	    		int i=0,flag=0;
	    		while(i++<mod){
	    			if(gecici == bas_dugum){
	    				flag =1;
	    				EnbasaEkle(&bas_dugum,array[j]);
	    				break;
	    			}
	    			gecici = gecici->sagtaraf;
	    		}
	    		if(flag==0)
	    			ArdindanEkle(&gecici,array[j],gecici->sayi);
	    	}
	    }
	    ListPrint(bas_dugum);
	    free(bas_dugum);

	}
	fclose(dosya_isretcisi);
} 

