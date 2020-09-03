#include "node.hpp"

//Dosyadan okuma işlemlerinin yapıldığı fonksiyon
void fileRead(){
	//yeni boş bir düğüm üretme
 	Node *root = NULL;  

 	//okunacak dosyanın belirlenmesi
    ifstream myfile("Kisiler.txt");

    //dosyanın açık olma durumu kontrolü
    if(myfile.is_open())
    {
        string ad;
        string sdogum;
        string skilo;

        //dosyanın sonuna gelinmediği sürece dönen döngü
        while(!myfile.eof())
        {
        	//okunan satırdaki ilk "#" sembolüne kadar olan bölümünde ilgili değişkene atanması
            getline(myfile,ad,'#');
         	//okunan satırdaki ikinci "#" sembolüne kadar olan bölümünde ilgili değişkene atanması
            getline(myfile,sdogum,'#');
            //okunan satırdaki son "\n" sembolüne kadar olan bölümünde ilgili değişkene atanması
            getline(myfile,skilo,'\n');

            //ilgili değerlerin çevrimi
            int dogum = stoi(sdogum);
            int kilo = stoi(skilo);	

			//o anki satırdaki bilgilerin listeye eklenmesi
            root = insert(root, yeniKisi(ad,dogum,kilo));
        }
        //dosyanın kapatılması
        myfile.close();

    }
    //listenin postorder olarak listelenmesi
    postOrder(root);   
} 