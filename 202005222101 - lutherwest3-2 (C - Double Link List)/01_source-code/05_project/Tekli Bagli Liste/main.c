//kutuphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//uye bilgilerinin saklanmasi icin struct tanimi
struct Uye{
	char tcno[12];
	char Ad[20];
	char soyad[20];
	int daire;
	struct Uye *Sonraki;};
//struct Uye tanımını daha kolay kullanım adına Uye olarak kısaltma
typedef struct Uye Uye;
//Uye struct yapısından Uyeler adında bir struct oluşturma
Uye *Uyeler; 
//fonksiyonların prototipleri
void Menu();
void Listele();
void YeniUyeEkle();
void UyeEkle(char *tcno,char* Ad,char* soyad,int daire);
Uye* Sil(char tcno[12]);
void Ara(char tcno[12]);
void Yazdir(Uye*);
void DosyaYaz();
void DosyaOku();
//ana fonksiyon
int main(){
	Uyeler = NULL;//Uyeler struct tanımı sıfırlanıyor
	DosyaOku();//program ilk açıldığında veri.txt dosyasından veriler okunuyor
	Menu();}//menu fonksiyonu çağrılıyor

//menu fonksiyonu
void Menu(){
	DosyaYaz();//menu her çağrıldığında verilerde değişim ihtimaline karşı veriler dosyaya yazılıyor
	printf("\n=================================================\n");
	printf("1) Uyeleri Listele\n");
	printf("2) Yeni Uye Ekle\n");
	printf("3) Uye Sil\n");
	printf("4) Uye Ara\n");
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
			exit(0);break;//programın sonlandırılması, hatasız olarak
		case 1:
			Listele(Uyeler);break;//listeleme fonksiyonu çağrılarak veriler listeleniyor
		case 2:
			YeniUyeEkle();break;//yeni üye eklemek için fonksiyon çağrılıyor
		case 3:
			printf("Uye TcNo : ");
			//silme için tcno bilgisi alınıyor
			char stcno[12];
			scanf("%s",stcno);
			Uyeler = Sil(stcno);break;//alınan tcno bilgisine göre sil fonksiyonu çalışıyor ve silme işlemineden sonra döndürülen struct Uyeler struct yapısına atanıyor;
		case 4:
			printf("Uye TcNo : ");
			//arama için tcno bilgisi alınıyor
			char atcno[12];
			scanf("%s",atcno);//alınan tcno bilgisine göre ara fonksiyonu çalışıyor
			Ara(atcno);break;
	}Menu();}
void YeniUyeEkle(){//YeniUyeEkle fonksiyonu
	printf("============ Uye Ekle ============\n");
	//Yeni uye bilgileri alınıyor
	printf("TcNo\t: ");
	char tcno[12];
	scanf("%s",tcno);
	printf("Ad\t: ");
	char Ad[20];
	scanf("%s",Ad);
	printf("Soyad\t: ");
	char soyad[20];
	scanf("%s",soyad);
	printf("Daire [5,11...]\t: ");
	int daire;
	scanf("%d",&daire);
	//Yeni üyeye ait bilgiler UyeEkle fonksiyonuna gönderiliyor
	UyeEkle(tcno,Ad,soyad,daire);}
//UyeEkle fonksiyonu
void UyeEkle(char* tcno,char* Ad,char* soyad,int daire){
	if(Uyeler == NULL){//Uyeler içerisinde kayıt yok ise
		Uyeler = (Uye*)malloc(sizeof(Uye));//Yeni üye için bellekte alan ayrılıyor
		//Bilgiler ilgili alanlara atanıyor
		strcpy(Uyeler->tcno,tcno);
		strcpy(Uyeler->Ad,Ad);
		strcpy(Uyeler->soyad,soyad);
		Uyeler->daire = daire;
		Uyeler->Sonraki = NULL;		
		return;}
	Uye *iter = Uyeler;//Uyeler iter adında bir Uye structına atanıyor
	while(iter->Sonraki != NULL)//listenin sonuna kadar giden bir döngü oluşturuluyor
		iter = iter->Sonraki;
	Uye *yeni = (Uye*)malloc(sizeof(Uye));//Yeni üye için bellekte alan ayrılıyor
	//Bilgiler ilgili alanlara atanıyor
	strcpy(yeni->tcno,tcno);
	strcpy(yeni->Ad,Ad);
	strcpy(yeni->soyad,soyad);
	yeni->daire = daire;
	yeni->Sonraki = NULL;
	iter->Sonraki = yeni;//eklenen yeni veri önceki listenin son elemanının "Sonraki" si olarak kendini bağlıyor
}
void Ara(char tcno[12]){//Ara fonksiyonu
	Uye *liste = Uyeler;//Uyeler liste adında bir sturcta atanıyor
	if(liste == NULL)//liste boşsa
		return;
	printf("\n=============UYE ARAMASI=============\n");
	while(liste != NULL){//uye bulunana dek bir döngü oluşturuluyor
		if(strcmp(liste->tcno,tcno)==0){
			Yazdir(liste);//uye bilgileri yazdırılıyor
			return;}
		liste = liste->Sonraki;}//uyelerden sonraki elemana geçiliyor
	
	//döngü biter ve uye bulunamaz ise
	printf("\nAranan uye kayitlarda yok!!!\n");	
}
void Listele(){//Listele fonksiyonu
	Uye *liste = Uyeler;//Uyeler iter adında bir Uye structına atanıyor
	if(liste == NULL)//Liste boş ise
		return;
	printf("\n=============UYE LISTESI=============\n");
	while(liste != NULL){//Listenin sonuna kadar giden bir döngü oluşturuluyor
		Yazdir(liste);//Uye bilgileri yazdırılıyor
		liste = liste->Sonraki;}
	printf("\n");}
void Yazdir(Uye* uye){//Yazdır fonksiyonu
	//parametre olarak gelen uye bilgisine göre ekrana yazdırma işlemi yapılıyor
	printf("TcNo\t: %s\nAd\t: %s\nSoyad\t: %s\nDaire\t: %d\n",
	uye->tcno,uye->Ad,uye->soyad,uye->daire);	
	printf("=====================================\n");}
Uye* Sil(char tcno[12]){//Sil fonksiyonu
	Uye *iter = Uyeler;//Uyeler iter adında bir Uye structına atanıyor
	Uye *temp;//geçici veriyi tutmak için temp adında bir Uye structı tanımlanıyor
	if(strcmp(Uyeler->tcno,tcno) == 0){//listede tek veri varsa
		Yazdir(Uyeler);//üye bilgisi çağrılıyor
		printf("Uye silindi.\n");
		temp = Uyeler;//Uyeler geçiçi "temp" structına atanıyor
		Uyeler = Uyeler->Sonraki; //Uye siliniyor
		free(temp);//geçiçi "temp" temizleniyor
		return Uyeler;}//yeni Uyeler structı geri döndürülüyor
	
	while(iter->Sonraki != NULL && strcmp(iter->Sonraki->tcno,tcno) != 0)//aranan veri bulunana dek döngü oluşturuluyor
		iter = iter->Sonraki;
	if(iter->Sonraki == NULL){//silinecek üye listede yoksa
		printf("\nAranan uye kayitlarda yok!!!\n");	
		return Uyeler;}//yeni Uyeler structı geri döndürülüyor
	//Uye siliniyor
	temp = iter->Sonraki;
	iter->Sonraki = iter->Sonraki->Sonraki;
	Yazdir(temp);//üye bilgisi çağrılıyor
	printf("Uye silindi.\n");
	free(temp);//geçiçi "temp" temizleniyor
	return Uyeler;}//yeni Uyeler structı geri döndürülüyor
void DosyaYaz(){
	if(fopen("veri.txt","w")){//veri dosyası yazma modunda açılmaya çalışılıyor
		FILE *dosya;//dosya için gösterici tanımı
		dosya = fopen("veri.txt","w");//dosya "veri.txt" yazma modunda açılıyor ve içeriği siliniyor
		Uye *iter = Uyeler;//Uyeler, iter adında bir structa atanıyor
		while(iter->tcno != NULL){//sonuncu uyeye kadar döngü oluşturuluyor
			fprintf(dosya,"%s %s %s %d\n",//verilerin biçimine göre dizilim yapılıyor ve o anki uye verileri dosyaya yazılıyor
			iter->tcno,iter->Ad,iter->soyad,iter->daire);		
			iter = iter->Sonraki;
		}
		fclose(dosya);//dosya kapatılıyor	
	}}
void DosyaOku(){	
	if(fopen("veri.txt","r")){//veri dosyası okuma modunda açılmaya çalışılıyor
	FILE *dosya;//dosya için gösterici tanımı
	dosya = fopen("veri.txt","r");//dosya "veri.txt" okuma modunda açılıyor
		while(!feof(dosya)){//dosyanın sonuna gelene dek döngü oluşturuluyor
		//atanacak veriler için bellekte yer ayrılıyor ve tanımları yapılıyor
		char *tcno= (char*)malloc(sizeof(char)*100);
		char *Ad= (char*)malloc(sizeof(char)*100);
		char *soyad= (char*)malloc(sizeof(char)*100);
		int daire;
		fscanf(dosya,"%s %s %s %d",//verilerin okunacağı biçim belirleniyor
		tcno,Ad,soyad,&daire);//veriler okunuyor ve ilgili alana atanıyor
	   	if(strcmp(tcno,"")!=0)
	   		//okunan veriler atandıktan sonra UyeEkle fonksiyonu çağrılarak listeye ekleme yapılıyor
	   		UyeEkle(tcno,Ad,soyad,daire);
		}
		fclose(dosya);//dosya kapatılıyor
	}}