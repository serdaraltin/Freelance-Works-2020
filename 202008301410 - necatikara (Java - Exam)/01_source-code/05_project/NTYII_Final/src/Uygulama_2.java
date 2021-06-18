
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Uygulama_2 {
    //parametre olarak gelen listeye oluşturulan zar değerinin eklenmesi
    public void ZarAtma(ArrayList<Integer> zarlar) {
        //Random sınıfından yeni bir nesne üretilmesi
        Random random = new Random();
        //1-6 dahil 1 ile 6 arası rastgele sayı üretme
        int rasgeleSayi = random.nextInt(7 - 1) + 1;
        //listeye ekleme
        zarlar.add(rasgeleSayi);
        System.out.println("Sonuc: " + rasgeleSayi);
    }
    //parametre olarak gelen listenin ilgili dosyaya yazılması
    public void ZarYaz(ArrayList<Integer> zarlar) {
        //ilgili sınıftan nesne üretme
        FileWriter fileWriter = null;
        try {
            //dosyanın ilgili nesneye atanması
            fileWriter = new FileWriter("zarlar.txt");
            //listedeki tüm değerlerin gezilmesi
            for (Integer zar : zarlar) {
                //o anki değerin dosyaya yazılması
                fileWriter.write(String.valueOf(zar)+"\n");
            }
            //dosyanın kapatılması
            fileWriter.close();
        } catch (IOException ex) {
            Logger.getLogger(Uygulama_2.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fileWriter.close();
            } catch (IOException ex) {
                Logger.getLogger(Uygulama_2.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
