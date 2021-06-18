#include <stdio.h>//standart input/output kütüphanesi ekleme

#define LINE 15 //satır değerinin global olarak değiştirilebilmesi için LINE sabit tanımı
#define COLUMN 14 //sutun değerinin global olarak değiştirilebilmesi için LINE sabit tanımı
// sutun sonu '\0' için artı olarak 2 karakterlik yer ayırın

void printPuzzle(char puzzle[COLUMN][LINE]); //printPuzzle fonksiyonu prototip tanımı
int computeLength(char *array); //computeLength fonksiyonu prototip tanımı
int findString(char puzzle[COLUMN][LINE],char *array,int ); //findString fonksiyonu prototip tanımı

int main()//ana fonksiyon
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

	char puzzle[COLUMN][LINE];//ana puzzle matrisini oluşturma
	int i;//döngüde kullanılacak olan iteratif değişken
	for (int i = 0; i < LINE; i++)//kullanıcıdan 15 satır için bilgi almak için tanımlanmış for döngüsü
	{
		printf("Enter the line %d of the puzzle:\n",i+1);//Kullanıcıya satır için bilgi girmesi adına ekrana yazdırma
		char line[30];//kullanının girdiği değeri tutacak olan dizi değişkeni
		scanf("%s",line);// kullanıcının girdiği değeri diziye atama
		if(computeLength(line)>12){//computeLenght fonksiyonu ile dizenin değerinin 12 den büyük olma durumu kontrolü
			printf("Entry must be 12 characters long - re-enter\n");//12 büyük bir değer girilmişe bilgi veriliyor
			i--;//12 den büyük bir değer girildiği için döngünün aynı adımı tekrar etmesi adına i değişkeni 1 azaltılıyor
		}
		else{//kullanıcı 12 karakterlik bir veri girdiyse
			sprintf(puzzle[i],"%s",line);//kullanıcıdan alınan veri puzzle matrisinin o anki satırına ekleniyor
		}
	}

	printPuzzle(puzzle);//printPuzzle fonksiyonu çağrılarak puzzle matrisi parametre olarak veriliyor

	while(1){//sonsuz bir döngü oluşturularak sürekli kullanıcıya soru sorması sağlanıyor
		printf("Enter the string to be searched in the puzzle:\n");//ekrana metin yazdırma
		char fvalue[16];//kullanıcının girdiği değeri tutan dizi değişkeni, dikeyde de veri bulunabileceği için sutun+1 yapılmıştır
		scanf("%s",fvalue);//kullanıcıdan alınan veri diziye atanıyor
		if(fvalue[0] == 'q' || fvalue[0] == 'Q')//kullanıcının Q veye q girip girmediği kontrol ediliyor ve girmişse programdan çıkılıyor
			return 0;//main fonksiyonundan geriye 0 döndürülerek program sorunsuz şekilde sonlandırılıyor
		int result = findString(puzzle,fvalue,0);//findString değişkeni çağrılarak puzzle matrisi ve aranacak olan dizi veriliyor ve sonuç "result" değişkenine atanıyor
		printf("%d\n",result);//sonuç ekrana bastırılıyor
	}

	return 0;
}
int findString(char puzzle[COLUMN][LINE],char *array,int fChar){//findString fonksiyonu, verilen değeri matris(puzzle) içerisinde arar
	
	int i,j,l;//döngülerde kullanılacak iteratif değişkenlerin tanımı
	for (i = 0; i < LINE; ++i)//satır bazında haraket etmek için döngü
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
						return j;//bulunan değer geriye döndürülüyor
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

int computeLength(char *array){//computeLength fonksiyonu, verilen dizinin uzunluğunu hesaplar
	int i= 0;//parametre olarak verilen dizinin uzunluğunu hesaplamada değer tutan değişkeb
	while(array[i] != '\0')//dizinin sonuna geline dek devam eden döngü
		i++;//dizinin son elemanına kadar artan değişken
	return i;//dizinin sonuna gelindiğinde i değişkeni dizinin uzunluğuna eşit olur ve geriye döndürülür
}

void printPuzzle(char puzzle[COLUMN][LINE]){//printPuzlle fonksiyonu, matrisi ekrana bastırır
	printf("THE PUZZLE:\n\n");//bilgi olarak ekrana metin yazdırma
	int i,j;//döngülerde kullanılacak iteratif değişkenler
	for (i = 0; i < LINE; ++i)//matrisin satirlarinda gezinmek için döngü
	{
		for (j = 0; j < COLUMN-2; ++j)//matrisin stunlarinda gezinmek için döngü
			printf("%c ",puzzle[i][j]);	//matrisin o anki satir-sütun değerini ekrana bastırma
		printf("\n");//bir satır boşluk
	}
}
