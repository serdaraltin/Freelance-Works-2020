//kutuphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//uye bilgilerinin saklanmasi icin struct tanimi
struct node{
	char tcno[12];
	char ad[20];
	char soyad[20];
	char mailAdres[30];
	char telefon[12];
	char dogumTarih[12];
	int medeniHal;
	int  kat;
	int daire;
	char baslangicTarih[12];

	//ikili yapıda oldugu icin onceki ve sonraki kayit bilgilerini gosteren struct tanimlari
	struct node *Onceki;
	struct node *Sonraki;
};
//struct node tanımını daha kolay kullanım adına Uye olarak kısaltma
typedef struct node Uye;

//Uye struct yapısından Uyeler adında bir struct oluşturma
Uye *Uyeler; 

//fonksiyonların prototipleri
void Menu();
void YeniUyeEkle();
void UyeEkle(char *tcno,char* ad,char* soyad,char* mailAdres,char * telefon,char* dogumTarih,int medeniHal,int kat,int daire,char *baslangicTarih);
void Listele();
void Ara(char tcno[12]);
void Guncelle(char tcno[12]);
Uye* Sil(char tcno[12]);
void Yazdir(Uye*);
void DosyaYaz();
void DosyaOku();

//ana fonksiyon
int main(){
	Uyeler = NULL;//Uyeler struct tanımı sıfırlanıyor
	DosyaOku();//program ilk açıldığında veri.txt dosyasından veriler okunuyor
	Menu();//menu fonksiyonu çağrılıyor
}

//menu fonksiyonu
void Menu(){
	DosyaYaz();//menu her çağrıldığında verilerde değişim ihtimaline karşı veriler dosyaya yazılıyor
	printf("\n=================================================\n");
	printf("1) Uyeleri Listele\n");
	printf("2) Yeni Uye Ekle\n");
	printf("3) Uye Guncelle\n");
	printf("4) Uye Sil\n");
	printf("5) Uye Ara\n");
	printf("0) Cikis\n");
	printf("=================================================\n");
	//seçim
	printf("\n\nSeciniz : ");
	int sec;
	scanf("%d",&sec);
	printf("\n");
	//seçeneğe göre işlem kısmı
	switch(sec){
		case 0:
			printf("Programdan cikiliyor...\n");
			exit(0);//programın sonlandırılması, hatasız olarak
			break;
		case 1:
			printf("------> LISTELE\n");
			Listele();//listeleme fonksiyonu çağrılarak veriler listeleniyor
			Menu();
			break;
		case 2:
			printf("------> EKLE\n");
			YeniUyeEkle();//yeni üye eklemek için fonksiyon çağrılıyor
			Menu();
			break;	
		case 3:
			printf("------> GUNCELLE\n");
			printf("Uye TcNo : ");
			//güncelleme için tcno bilgisi alınıyor
			char gtcno[12];
			scanf("%s",gtcno);
			Guncelle(gtcno);//alınan tcno bilgisine göre guncelle fonksiyonu çalışıyor
			Menu();
			break;	
		case 4:
			printf("------> SIL\n");
			printf("Uye TcNo : ");
			//silme için tcno bilgisi alınıyor
			char stcno[12];
			scanf("%s",stcno);
			Uyeler = Sil(stcno);//alınan tcno bilgisine göre sil fonksiyonu çalışıyor ve silme işlemineden sonra
			//döndürülen struct Uyeler struct yapısına atanıyor
			Menu();
			break;
		case 5:
			printf("------> ARA\n");
			printf("Uye TcNo : ");
			//arama için tcno bilgisi alınıyor
			char atcno[12];
			scanf("%s",atcno);//alınan tcno bilgisine göre ara fonksiyonu çalışıyor
			Ara(atcno);
			Menu();
			break;
			
	}
	
}

void DosyaYaz(){
	if(!fopen("veri.txt","w")){//veri dosyası yazma modunda açılmaya çalışılıyor
		printf("\nVeri dosyasi yazilamadi !!!\n\a");
		return;
	}
	else{
		FILE *dosya;//dosya için gösterici tanımı
		dosya = fopen("veri.txt","w");//dosya "veri.txt" yazma modunda açılıyor ve içeriği siliniyor
	
		Uye *iter = Uyeler;//Uyeler, iter adında bir structa atanıyor
		while(iter->tcno != NULL){//sonuncu uyeye kadar döngü oluşturuluyor
			fprintf(dosya,"%s %s %s %s %s %s %d %d %d %s\n",//verilerin biçimine göre dizilim yapılıyor ve o anki uye verileri dosyaya yazılıyor
			iter->tcno,iter->ad,iter->soyad,iter->mailAdres,iter->telefon,iter->dogumTarih,iter->medeniHal,iter->kat,iter->daire,iter->baslangicTarih);		
			iter = iter->Sonraki;
		}
		fclose(dosya);//dosya kapatılıyor	
	}
}

void DosyaOku(){	
	if(!fopen("veri.txt","r")){//veri dosyası okuma modunda açılmaya çalışılıyor
		printf("\nVeri dosyasi okunamadi !!!\n\a");
		return;
	}
	else{
	FILE *dosya;//dosya için gösterici tanımı
	dosya = fopen("veri.txt","r");//dosya "veri.txt" okuma modunda açılıyor
	
		while(!feof(dosya)){//dosyanın sonuna gelene dek döngü oluşturuluyor
		
		//atanacak veriler için bellekte yer ayrılıyor ve tanımları yapılıyor
		char *tcno= (char*)malloc(sizeof(char)*100);
		char *ad= (char*)malloc(sizeof(char)*100);
		char *soyad= (char*)malloc(sizeof(char)*100);
		char *mailAdres= (char*)malloc(sizeof(char)*100);
		char *telefon= (char*)malloc(sizeof(char)*100);
		char *dogumTarih= (char*)malloc(sizeof(char)*100);
		char *baslangicTarih= (char*)malloc(sizeof(char)*100);
		int medeniHal;
		int  kat;
		int daire;
		
		fscanf(dosya,"%s %s %s %s %s %s %d %d %d %s",//verilerin okunacağı biçim belirleniyor
		tcno,ad,soyad,mailAdres,telefon,dogumTarih,&medeniHal,&kat,&daire,baslangicTarih);//veriler okunuyor ve ilgili alana atanıyor
	   	if(strcmp(tcno,"")!=0)
	   		//okunan veriler atandıktan sonra UyeEkle fonksiyonu çağrılarak listeye ekleme yapılıyor
	   		UyeEkle(tcno,ad,soyad,mailAdres,telefon,dogumTarih,medeniHal,kat,daire,baslangicTarih);
		}
		fclose(dosya);//dosya kapatılıyor
	}
}
void Yazdir(Uye* uye){//Yazdır fonksiyonu
		//parametre olarak gelen uye bilgisine göre ekrana yazdırma işlemi yapılıyor
		printf("TcNo\t: %s\nAd\t: %s\nSoyad\t: %s\nMail\t: %s\nTelefon\t: %s\nDogum Tarih\t: %s\nMedeni Hal\t: %d\nKat\t\t: %d\nDaire\t\t: %d\nBaslangic Tarih\t: %s\n",
		uye->tcno,uye->ad,uye->soyad,uye->mailAdres,uye->telefon,uye->dogumTarih,uye->medeniHal,uye->kat,uye->daire,uye->baslangicTarih);	
		printf("=====================================\n");
}

Uye* Sil(char tcno[12]){//Sil fonksiyonu
	Uye *iter = Uyeler;//Uyeler iter adında bir Uye structına atanıyor
	Uye *temp;//geçici veriyi tutmak için temp adında bir Uye structı tanımlanıyor

	if(strcmp(Uyeler->tcno,tcno) == 0){//listede tek veri varsa
		Yazdir(Uyeler);//üye bilgisi çağrılıyor
		printf("Uye silindi.\n");
		temp = Uyeler;//Uyeler geçiçi "temp" structına atanıyor
		Uyeler = Uyeler->Sonraki; //Uye siliniyor
		free(temp);//geçiçi "temp" temizleniyor
		return Uyeler;//yeni Uyeler structı geri döndürülüyor
	}

	while(iter->Sonraki != NULL && strcmp(iter->Sonraki->tcno,tcno) != 0)//aranan veri bulunana dek döngü oluşturuluyor
		iter = iter->Sonraki;
	
	if(iter->Sonraki == NULL)//silinecek üye listede yoksa
	{
		printf("\nAranan uye kayitlarda yok!!!\n");	
		return Uyeler;//yeni Uyeler structı geri döndürülüyor
	}

	//Uye siliniyor
	temp = iter->Sonraki;
	iter->Sonraki = iter->Sonraki->Sonraki;
	Yazdir(temp);//üye bilgisi çağrılıyor
	printf("Uye silindi.\n");
	free(temp);//geçiçi "temp" temizleniyor

	if(iter->Sonraki != NULL)
		iter->Sonraki->Onceki = iter;

	return Uyeler;//yeni Uyeler structı geri döndürülüyor
}

void Guncelle(char tcno[12]){//Guncelle fonksiyonu
	Uye *liste = Uyeler;//Uyeler liste adında bir Uye structına atanıyor
	if(liste == NULL){//liste boşsa 
		printf("\nHic uye kaydi yok !!!\n");
		return;
	}
	printf("\n=============UYE GUNCELLEME=============\n");

	while(liste != NULL){//guncellenecek uye bulunana dek döngü oluşturuluyor
		if(strcmp(liste->tcno,tcno)==0){//tcno ya göre üye aranıyor
			Yazdir(liste);//uye ekrana bastırılıyor
			printf("YENI BILGILER >>\n\n");
			//yeni bilgiler alınıyor
			printf("TcNo\t: ");
			char tcno[12];
			scanf("%s",tcno);

			printf("Ad\t: ");
			char ad[20];
			scanf("%s",ad);

			printf("Soyad\t: ");
			char soyad[20];
			scanf("%s",soyad);

			printf("Telefon\t: ");
			char telefon[12];
			scanf("%s",telefon);

			printf("Mail\t: ");
			char mailAdres[30];
			scanf("%s",mailAdres);

			printf("Dogum Tarih\t: ");
			char dogumTarih[12];
			scanf("%s",dogumTarih);

			printf("Medeni Hal\t: ");
			int medeniHal;
			scanf("%d",&medeniHal);

			printf("Kat [0,1,2...]\t: ");
			int kat;
			scanf("%d",&kat);

			printf("Daire [5,11...]\t: ");
			int daire;
			scanf("%d",&daire);

			printf("Baslangic Tarih\t: ");
			char baslangicTarih[12];
			scanf("%s",baslangicTarih);

			//yeni bilgiler atanıyor
			strcpy(liste->tcno,tcno);
			strcpy(liste->ad,ad);
			strcpy(liste->soyad,soyad);
			strcpy(liste->mailAdres,mailAdres);
			strcpy(liste->telefon,telefon);
			strcpy(liste->dogumTarih,dogumTarih);
			strcpy(liste->baslangicTarih,baslangicTarih);
			liste->medeniHal = medeniHal;
			liste->kat = kat;
			liste->daire = daire;

			return;
		}
		liste = liste->Sonraki;//liste bir ileri gidiyor
	}
	printf("\nAranan uye kayitlarda yok!!!\n");	
}

void Ara(char tcno[12]){//Ara fonksiyonu
	Uye *liste = Uyeler;//Uyeler liste adında bir sturcta atanıyor
	if(liste == NULL){//liste boşsa
		printf("\nHic uye kaydi yok !!!\n");
		return;
	}
	printf("\n=============UYE ARAMASI=============\n");

	while(liste != NULL){//uye bulunana dek bir döngü oluşturuluyor
		if(strcmp(liste->tcno,tcno)==0){
			Yazdir(liste);//uye bilgileri yazdırılıyor
			return;
		}
		liste = liste->Sonraki;//uyelerden sonraki elemana geçiliyor
	}
	//döngü biter ve uye bulunamaz ise
	printf("\nAranan uye kayitlarda yok!!!\n");	
}

void YeniUyeEkle(){//YeniUyeEkle fonksiyonu
	printf("============ Uye Ekle ============\nTarih > gg-aa-yyyy\nMedeni Hal > Evli(1),Bekar(0)\n\n");
	//Yeni uye bilgileri alınıyor
	printf("TcNo\t: ");
	char tcno[12];
	scanf("%s",tcno);

	printf("Ad\t: ");
	char ad[20];
	scanf("%s",ad);

	printf("Soyad\t: ");
	char soyad[20];
	scanf("%s",soyad);

	printf("Telefon\t: ");
	char telefon[12];
	scanf("%s",telefon);

	printf("Mail\t: ");
	char mailAdres[30];
	scanf("%s",mailAdres);

	printf("Dogum Tarih\t: ");
	char dogumTarih[12];
	scanf("%s",dogumTarih);

	printf("Medeni Hal\t: ");
	int medeniHal;
	scanf("%d",&medeniHal);

	printf("Kat [0,1,2...]\t: ");
	int kat;
	scanf("%d",&kat);

	printf("Daire [5,11...]\t: ");
	int daire;
	scanf("%d",&daire);

	printf("Baslangic Tarih\t: ");
	char baslangicTarih[12];
	scanf("%s",baslangicTarih);
	//Yeni üyeye ait bilgiler UyeEkle fonksiyonuna gönderiliyor
	UyeEkle(tcno,ad,soyad,mailAdres,telefon,dogumTarih,medeniHal,kat,daire,baslangicTarih);
}

//UyeEkle fonksiyonu
void UyeEkle(char* tcno,char* ad,char* soyad,char* mailAdres,char * telefon,char* dogumTarih,int medeniHal,int kat,int daire,char *baslangicTarih){
	
	if(Uyeler == NULL){//Uyeler içerisinde kayıt yok ise

		Uyeler = (Uye*)malloc(sizeof(Uye));//Yeni üye için bellekte alan ayrılıyor
		//Bilgiler ilgili alanlara atanıyor
		strcpy(Uyeler->tcno,tcno);
		strcpy(Uyeler->ad,ad);
		strcpy(Uyeler->soyad,soyad);
		strcpy(Uyeler->mailAdres,mailAdres);
		strcpy(Uyeler->telefon,telefon);
		strcpy(Uyeler->dogumTarih,dogumTarih);
		strcpy(Uyeler->baslangicTarih,baslangicTarih);
		Uyeler->medeniHal = medeniHal;
		Uyeler->kat = kat;
		Uyeler->daire = daire;
		Uyeler->Onceki = NULL;
		Uyeler->Sonraki = NULL;		
		return;
	}
	Uye *iter = Uyeler;//Uyeler iter adında bir Uye structına atanıyor

	while(iter->Sonraki != NULL)//listenin sonuna kadar giden bir döngü oluşturuluyor
		iter = iter->Sonraki;

	Uye *yeni = (Uye*)malloc(sizeof(Uye));//Yeni üye için bellekte alan ayrılıyor
	//Bilgiler ilgili alanlara atanıyor
	strcpy(yeni->tcno,tcno);
	strcpy(yeni->ad,ad);
	strcpy(yeni->soyad,soyad);
	strcpy(yeni->mailAdres,mailAdres);
	strcpy(yeni->telefon,telefon);
	strcpy(yeni->dogumTarih,dogumTarih);
	strcpy(yeni->baslangicTarih,baslangicTarih);
	yeni->medeniHal = medeniHal;
	yeni->kat = kat;
	yeni->daire = daire;
	yeni->Onceki = iter;//eklenen yeni veri önceki listenin son elemanının "Onceki" olarak kendine bağlıyor
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;//eklenen yeni veri önceki listenin son elemanının "Sonraki" si olarak kendini bağlıyor
	return;		
}

void Listele(){//Listele fonksiyonu
	Uye *liste = Uyeler;//Uyeler liste adında bir Uye structına atanıyor
	if(liste == NULL){//Liste boş ise
		printf("\nHic uye kaydi yok !!!\n");
		return;
	}
	printf("\n=============UYE LISTESI=============\n");
	while(liste != NULL){//Listenin sonuna kadar giden bir döngü oluşturuluyor
		Yazdir(liste);//Uye bilgileri yazdırılıyor
		liste = liste->Sonraki;
	}
	printf("\n");
}