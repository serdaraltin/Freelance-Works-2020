//gerekli kutuphanelerin dahil edilmesi
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class main {

    public static void main(String[] args) {
        //ilgili fonksiyondan geriye dondurulen dizinin ilgili diziye atanmasi
        int dizi[] = dosyayiOku("diziler.txt");

        //ilgili dizinin siralamaYap methoduna gonderilerek siralanmis halinin tekrar ilgili diziye atanmasi
        dizi = siralamaYap(dizi);

        //dosyaYaz methoduna belirlenen dosya adi ve ilgili dizi gonderilerek dizideki degerler dosyay yaziliyor
        dosyayiYaz("siralanmisDiziler.txt", dizi);

        //scanner sinifindan yeni bir nesne turetilerek kullanicidan veri alma islemi
        Scanner scanner = new Scanner(System.in);

        //Ekrana ilgili metnin basilmasi
        System.out.print("Aranacak Sayi : ");

        //kullanicinin girdigi deger bir tamsayi oldugu surece dongu devam ediyor
        while (scanner.hasNextInt()) {
            //aramaYap methoduna belirlenen dosya adi ve o an kullanicinin girdigi sayi degeri gonderiliyor
            aramaYap("siralanmisDiziler.txt", scanner.nextInt());
            //Ekrana ilgili metnin basilmasi
            System.out.print("Aranacak Sayi : ");
        }
        //kullanicinin tamsayi bir deger disinde deger girmesi sonucu donguden cikiliyor
        //Ekrana ilgili metnin basilmasi
        System.out.println("Program sonlandirildi.");
        //programin hatasiz bir sekilde sonlandirildigi bildiriliyor ve kapatiliyor
        System.exit(0);
    }

    //dosyaOku methodu, geriye tamsayi bir dizi dondurmekte ve parametre olarak dosya adini almakta
    public static int[] dosyayiOku(String dosyaAdi) {
        //try-catch  ile olusabilecek hatalar elimine ediliyor ve ilgili hata yazdiriliyor
        try {
            //dizi1 ve dizi2 boyutlarini tutmak icin degisken tanimlari
            int dizi1Boyut = 0, dizi2Boyut = 0;
            //File sinifindan bir nesne turetme ve dosya adini vererek bir dosya nesnesi olusturma
            File dosya = new File(dosyaAdi);
            //scn1 > dosyadaki dizilerin uzunluklarinin bulumasi icin dosyadan okumada kullanilacak
            //scn2 > dosyadaki dizilerin okunmasi icin dosyadan okumada kullanilacak
            Scanner scn1 = new Scanner(dosya);
            Scanner scn2 = new Scanner(dosya);

            //dosya okumasi sirasinda hangi dizinin isleme tabi tutulacagiyla ilgili bir bayrak belirlenmesi
            boolean dizi2Ekleme = false;

            //dosyada satir oldugu surece devam eden dongu
            while (scn1.hasNextLine()) {
                //o anki okunan satiri tutan degiskenin tanimlanmasi
                String satir = scn1.nextLine();

                //o anki satirin dizi1 olmasi durumunda dongunun o anki adimi atlaniyor
                if (satir.equals("dizi1")) {
                    continue;
                } //o anki satirin dizi2 olmasi durumunda dizi2Ekleme bayragi kaldiriliyor(deger true yapiliyor) dongunun o anki adimi atlaniyor
                else if (satir.equals("dizi2")) {
                    dizi2Ekleme = true;
                    continue;
                }
                //eger dizi2 ye ekleme durumu aktif ise dizi2Boyut deger 1 arttiriliyor
                if (dizi2Ekleme) {
                    dizi2Boyut++;
                } //eger dizi2 ye ekleme durumu aktif degil ise dizi2Boyut deger 1 arttiriliyor
                else {
                    dizi1Boyut++;
                }
            }
            
            //dizi1 ve dizi2 ilgili degerler boyutunda olusturuluyor
            int dizi1[] = new int[dizi1Boyut];
            int dizi2[] = new int[dizi2Boyut];

            
            dizi2Ekleme = false;
            int i = 0;
            while (scn2.hasNextLine()) {
                String satir = scn2.nextLine();
                
                if (satir.equals("dizi1")) {
                    continue;
                } else if (satir.equals("dizi2")) {
                    dizi2Ekleme = true;
                    i = 0;
                    continue;
                }
                //dizi2 ye o anki satirdaki deger ekleniyor
                if (dizi2Ekleme) {
                    dizi2[i] = Integer.parseInt(satir);
                } 
                 //dizi1 ye o anki satirdaki deger ekleniyor
                else {
                    dizi1[i] = Integer.parseInt(satir);
                }
                i++;
            }
            //ilgili diziler siralaniyor
            dizi1 = siralamaYap(dizi1);
            dizi2 = siralamaYap(dizi2);

            //ilgili diziler tek bir dizide birlestiriliyor
            int dizi3[] = dizileriBirlestir(dizi1, dizi2);
            
            //birlestirilmis dizi geriye donduruluyor
            return dizi3;
        } catch (FileNotFoundException ex) {
            Logger.getLogger(main.class.getName()).log(Level.SEVERE, null, ex);
        }

        return null;
    }

    //siralamaYap methodu, parametre olarak bir tamsayi dizi alip geriye bir tamsayi dizi donduruyor
    public static int[] siralamaYap(int dizi[]) {
        //ic ice iki dongu ile her bir eleman icin diger tum elemanlar gezilere karsilastirma yapiliyor
        //ilgili karsilastirma gecerli ise dizideki ilgili elemanlar icin yer degisimi yapiliyor
        for (int j = 0; j < dizi.length; j++) {
            for (int k = 0; k < dizi.length; k++) {
                if (dizi[j] < dizi[k]) {
                    int gecici = dizi[j];
                    dizi[j] = dizi[k];
                    dizi[k] = gecici;
                }
            }
        }
        //siralanmis dizi geriye donduruluyor
        return dizi;
    }

    //dizileriBirlestir methodu, parametre olarak iki tamsayi dizisi alip, geriye iki dizinin birlesimi olan bir dizi donduruyor
    public static int[] dizileriBirlestir(int dizi1[], int dizi2[]) {
        //iki dizinin toplam uzunlugunda yeni bir dizi tanimlaniyor
        int dizi[] = new int[dizi1.length + dizi2.length];

        //dizi1 deki tum elemanlar gezilerek ilgili diziye degerler ataniyor
        for (int j = 0; j < dizi1.length; j++) {
            dizi[j] = dizi1[j];
        }
        //dizi2 deki tum elemanlar gezilerek ilgili diziye degerler ataniyor
        for (int j = dizi1.length; j < dizi.length; j++) {
            dizi[j] = dizi2[j - dizi1.length];
        }
        //birlestirilmis dizi geriye donduruluyor
        return dizi;
    }

    //dosyayiYaz methodu, parametre olarak dosya adini ve bir tamsayi diziyi aliyor ve islemin olumlu olmasi durumuna gore geriye boolean bir deger donduruyor
    public static boolean dosyayiYaz(String dosyaAdi, int dizi[]) {
        //FileWriter sinifindan bir nesne turetiliyor
        FileWriter dosyaYaz = null;
        try {
            File dosya = new File(dosyaAdi);
            //ilgili dosya zaten var ise icerisi temizleniyor
            if (dosya.exists()) {
                PrintWriter pwriter = new PrintWriter(dosya);
                pwriter.print("");
                pwriter.close();
            } 
            //ilgili dosya yok ise olusturuluyor
            else {
                dosya.createNewFile();
            }
            //dosyaYaz nesnesin ilgili dosya nesnesine yazacagi bilgisi veriliyor
            dosyaYaz = new FileWriter(dosya, true);
            //bufferWriter nesnesi olusturularak ilgili nesne parametre olarak veriliyor
            try (BufferedWriter bufferWriter = new BufferedWriter(dosyaYaz)) {
                //dizideki tum elemanlar geziliyor
                for (int i : dizi) {
                    //o anki eleman dosyaya yaziliyor
                    bufferWriter.write(String.valueOf(i));
                    //dosyaya yeni bir satir ekleniyor
                    bufferWriter.newLine();
                }
                return true;
            }
        } catch (IOException ex) {
            //hata mesaji ekrana bastiriliyor
            System.err.println(ex);
            return false;
        }
    }

    //aramaYap methodu, parametre olaran bir dosya adi ve sayi aliyor
    public static void aramaYap(String dosyaAdi, int sayi) {
        try {
            File dosya = new File(dosyaAdi);
            //dosyanin mevcut olmamasi durumu
            if (!dosya.exists()) {
                System.out.println("Dosya mevcut degil!");
            }
            Scanner scanner = new Scanner(dosya);

            int i = 1;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                //ilgili sayi o anki satirda bulunursa 
                if (line.equals(String.valueOf(sayi))) {
                    //ilgili satir bilgisi yazdiriliyor
                    System.out.println("Aradiginiz sayi dosyada " + i + ". satirda bulunmaktadir.");
                    return;
                }
                i++;
            }
            //dongu tamamlaniyor ve geriye donulmuyor ise deger bulunamamistir ve bilgi metni yazdiriliyor
            System.out.println("Aradiginiz sayi bulunamadi.");
        } catch (FileNotFoundException ex) {
            System.err.println(ex);
        }
    }

}
