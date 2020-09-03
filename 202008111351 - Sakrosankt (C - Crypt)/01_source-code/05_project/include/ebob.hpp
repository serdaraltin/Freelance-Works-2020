int Ebob(int sayi1, int sayi2){
	while(sayi1 != sayi2){
		if(sayi1 > sayi2)
			sayi1 -= sayi2;
		else
			sayi2 -= sayi1;
	}
	return sayi1;
} 
