#include <stdio.h>
// Daha kolay test icin
#define LINE 15 
#define COLUMN 14 
// sutun sonu '\0' icin 2 karakter

void printPuzzle(char puzzle[COLUMN][LINE]){
	printf("THE PUZZLE:\n\n");
	int i,j;
	for (i = 0; i < LINE; ++i)// satir
	{
		for (j = 0; j < COLUMN-2; ++j)// sutun 
			printf("%c ",puzzle[i][j]);	
		printf("\n");
	}
}
int computeLength(char array[]){
	int i= 0;
	while(array[i] != '\0')
		i++;
	return i;
}
int findString(char puzzle[COLUMN][LINE],char array[],int fChar){
	int i,j,l;
	for (i = 0; i < LINE; ++i)
	{
		for (j = 0; j < COLUMN-2; ++j)//sütun bazında haraket etmek için döngü
		{
			if(array[0] == puzzle[i][j]){//aranan verinin ilk karakteri ile o an puzzle matrisinden seçilen karakter karşılaştırılıyor
				int flagxp = 1,flagxn = 1,flagyp = 1,flagyn = 1;//eksenler x,-x,y,-y için flag(bayrak) tanımlaması
				for (l=0; l< computeLength(array); ++l)//x ekseninde pozitif yonde verilen değerin aranması için döngü
					if(puzzle[i][j+l] != array[l])//aranan değer yoksa bayrak indiriliyor
						flagxp = 0;
				for (l=0; l< computeLength(array); ++l)//x ekseninde negatif yonde verilen değerin aranması için döngü
					if(puzzle[i][j-l] != array[l])//aranan değer yoksa bayrak indiriliyor
						flagxn = 0;
				for (l=0; l< computeLength(array); ++l)//y ekseninde pozitif yonde verilen değerin aranması için döngü
					if(puzzle[i+l][j] != array[l])//aranan değer yoksa bayrak indiriliyor
						flagyp = 0;
				for (l=0; l< computeLength(array); ++l)//x ekseninde negatif yonde verilen değerin aranması için döngü
					if(puzzle[i-l][j] != array[l])//aranan değer yoksa bayrak indiriliyor
						flagyn = 0;
				if(flagxp || flagxn || flagyp || flagyn){//herhangi bir eksende aranan değer bulunursa matris içerisindeki başlangı. değeri geriye döndürülüyor
					if(i==0){//matrisin ilk satırı ise
						return j;
					}
					else{//matrisin ilk satırı değilse
						return j+(12*i);//bulunan değer geriye döndürülüyor
					}
				}
			}
		}
	}
	return -1; //aranan değer bulunamaz ise geriye -1 değeri döndürülüyor
}
int main()
{
		 /*"XTZMQYKCECFH"
		 "SHOUTEXOEAPI"
		 "XGTLQBELTNFK"
		 "AIRIDZALIODM"
		 "MEIETYSEHRTI"
		 "AWBRNETCWOHX"
         "NOUIRUZTSCCT"
    	 "UDTPECJIEHRU"
    	 "ALEMCSYONIUR"
    	 "LVKEREMNIPHE"
		 "EANBUREJONCY"
         "AWIIIJNJRUYF"
		 "DWTNTHENPJYT"	
		 "EQLZDILEMMAB"	
		 "RCITENGAMTPC"*/

	char puzzle[COLUMN][LINE];
	int i;
	char line[30];
	for (int i = 0; i < LINE; i++)
	{
		printf("Enter the line %d of the puzzle:\n",i+1);
		scanf("%s",line);
		if(computeLength(line)>12){
			printf("Entry must be 12 characters long - re-enter\n");
			i--;
		}
		else{
			sprintf(puzzle[i],"%s",line);
		}
	}

	printPuzzle(puzzle);

	while(1){
		printf("Enter the string to be searched in the puzzle:\n");
		char fvalue[16];// dikeyde de veri icin sutun+1
		scanf("%s",fvalue);
		if(fvalue[0] == 'q' || fvalue[0] == 'Q')// programdan exit
			return 0;
		int result = findString(puzzle,fvalue,0);
		printf("%d\n",result);
	}

	return 0;
}
