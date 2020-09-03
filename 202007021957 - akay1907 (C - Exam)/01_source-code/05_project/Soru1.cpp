#include <iostream>

using namespace std; 

//gerekli dugum icin struct tanımı
struct node { 
    int sayi; 
    struct node* onceki, *sonraki; 
}; 
//daha kolay yazım için typedef ile "struct node" nin "Dugum" şeklinde yeniden isimlendirilmesi
typedef struct node Dugum;
  
//yeni bir düğümü oluşturup geriye döndüren fonksiyon, aldığı parametredeki değeri barındıran bir düğüm oluşturur
Dugum* DugumOlustur(int sayi) 
{ 
    Dugum* yeniDugum = (Dugum*)malloc(sizeof(Dugum)); 
  
    yeniDugum->sayi = sayi; 
    yeniDugum->onceki = NULL;
    yeniDugum->sonraki = NULL; 
    return yeniDugum; 
} 
  
//verilen bağlı listeyi tersine çeviren fonksiyon
void TersCevir(Dugum **ilk_dugum)  
{  
	//gecici degerlerin tutulacagı degisken
    Dugum *temp = NULL;  
    Dugum *mevcut = *ilk_dugum;  
    
    //liste boştan farklı ise
    while (mevcut != NULL)  
    {  
        temp = mevcut->onceki;  
        mevcut->onceki = mevcut->sonraki;  
        mevcut->sonraki = temp;              
        mevcut = mevcut->onceki;  
    }  
    //eğer geçici değeri boştan farklı ise
    if(temp != NULL )  
        *ilk_dugum = temp->onceki;  
} 

//parametre olarak verilen listeyi baştan sona yazdıran fonksiyon
void ListeyiYazdir(Dugum* ilk) 
{ 
    while (ilk != NULL) { 
        cout << ilk->sayi << " "; 
        //o anki liste elemanından bir sonraki elemana geçiş
        ilk = ilk->sonraki; 
    } 
} 
 
//parametre olarak gelen degeri ilgili listeye sıralı bir şekilde ekleyen fonksiyon
void SiraliEkleme(Dugum** ilk_dugum, Dugum* yeniDugum) 
{ 
	//varolan listenin bilgisini tutacak değişken
    Dugum* mevcut; 

    //başlangıçın boş olması durumu kontrolü
    if (*ilk_dugum == NULL) 
        *ilk_dugum = yeniDugum; 
    //ilk duğum değerinin yeni eklenecek değere eşit veya büyük olmasu durumu
    else if ((*ilk_dugum)->sayi >= yeniDugum->sayi) { 
        yeniDugum->sonraki = *ilk_dugum; 
        yeniDugum->sonraki->onceki = yeniDugum; 
        *ilk_dugum = yeniDugum; 
    } 
  	//yukarıdaki iki koşul dışındaki koşulların olması durumu
    else { 
        mevcut = *ilk_dugum; 
  
        while (mevcut->sonraki != NULL &&  
               mevcut->sonraki->sayi < yeniDugum->sayi) 
            mevcut = mevcut->sonraki; 

        yeniDugum->sonraki = mevcut->sonraki; 
  
        if (mevcut->sonraki != NULL) 
            yeniDugum->sonraki->onceki = yeniDugum; 
  
        mevcut->sonraki = yeniDugum; 
        yeniDugum->onceki = mevcut; 
    } 

} 

//ana fonksiyon
int main() 
{ 
	//listenin başlangıç düğümü için bir pointer(işaretçi) tanımlanıp değeri boş veriliyor
    Dugum* ilk = NULL; 
  	
  	//FILE structından dosya adında bir pointer tanımlanıp ilgili dosya okuma modunda açılıyor
    FILE *dosya = fopen("sayilar.txt","r");

    //o an okunan sayi değerini tutacak olan değişken
    int sayi; 	
    //okunan dosya son satıra gelmediği sürece devam eden döngü
    while(!feof(dosya)){
    	//dosyadan bir sayi değeri okunuyor ve "sayi" değişkenine atanıyor, burada dosya imleci otomatik haraket edip diğer değere yani alt satıra geçiyor
        fscanf(dosya,"%d\n",&sayi);
        //Sirali olarak ekleme fonksiyonuna listenin başlangıç elemanı ve düğüm oluştur fonsiyonundan geri dönen (sayi değişkeni verilerek) değer veriliyor
        SiraliEkleme(&ilk,  DugumOlustur(sayi)); 
    }
    //sıralı olan liste yazdırılıyor
    cout << "Sirali Liste : ";
    ListeyiYazdir(ilk); 
    printf("\n");
    //liste ters çevriliyor
    TersCevir(&ilk);
    //ters çevrilmiş liste ilgili dosyaya yazılıyor
    //dosya yazma modunda açılıyor
    dosya = fopen("sayilarters.txt","w");
    //listenin son elemanına gelene dek dönen döngü
    while (ilk != NULL) { 
    	//dosyaya bir satıra denk gelecek şekilde o anki sayının yazılması
        fprintf(dosya, "%d\n",ilk->sayi );
        ilk = ilk->sonraki; 
    } 

    return 0; 
} 