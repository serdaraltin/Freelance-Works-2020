
import java.util.Scanner;

public class Uygulama_4 {
    //sayı tahmin oyunu methodu
    public void TahminOyun() {
        //ilgili okuma sınıfından nesne üretilmesi
        Scanner scanner = new Scanner(System.in);
        //isim değerlerinin tutulduğu dizi
        String[] isimler = new String[5];
        //isim değerlerinin alınması için döngü
        for (int i = 0; i < 5; i++) {
            System.out.print((i+1)+". isim: ");
            isimler[i] = scanner.next();
        }
        System.out.println();
        //kullanıcı sonlandırana dek sonsuza dek devam eden döngü
        while(true){
            boolean tahminSonuc = false;
            System.out.print("Tahmin: ");
            String tahmin = scanner.next();
            //dizideki tüm değerlerin gezilmesi
            for (String isim : isimler) {
                //o anki değerin karakterlerinin küçültülmesi ve tahmin değerinin karakterlerinin küçültülmesi ardından aynı olma kontrolü
                if(isim.toLowerCase().equals(tahmin.toLowerCase())){
                    System.out.println("Sonuc: Tahminiz dogru");
                    tahminSonuc = true;
                    break;
                }
            }
            //o anki tahminin yanlış olması kontrolü
            if(!tahminSonuc)
                System.out.println("Sonuc: Tahmininiz yanlis");
            System.out.println();
            System.out.println("1) Devam Et");
            System.out.println("2) Sonlandir");
            //devam etme veya sonlandırma kontrolü
            int secim = scanner.nextInt();
            if(secim == 2)
                return;
        }
    }
    
}
