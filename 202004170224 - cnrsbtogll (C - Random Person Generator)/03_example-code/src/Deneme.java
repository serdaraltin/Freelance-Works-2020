/**
 * @author G161210113 - Hümeyra AY g161210113@sakarya.edu.tr B121210125 - Damla KARAGÖZ b121210125@sakarya.edu.tr
 * @since 1.4.2018
 * <p> Yapılan kütüphanenin test edildiği uygulama </p>
 */



import java.io.IOException;
import java.util.Scanner;

public class Deneme {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        RastgeleKisi rstgele = new RastgeleKisi();
        Scanner oku = new Scanner(System.in);
        do {
            System.out.println("1- Rastgele Kişi Üret\n2- Üretilmiş Dosyayı Kontrol Et\n3- Çıkış");
            int num = oku.nextInt();
            if (num == 1) {
                System.out.println("Kaç kişi üretmek istiyorsunuz?");
                int adet = oku.nextInt();
                rstgele.KisileriOlustur(adet);
            } else if (num == 2) {
                rstgele.DosyayiKontrolEt();
            } else if (num == 3)
                break;
        } while (true);


    }

}
