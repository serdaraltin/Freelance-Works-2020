import java.io.IOException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class test {

    public static void Menu() throws IOException {

        RastgeleKisi KisiUret = new RastgeleKisi();
        Scanner oku = new Scanner(System.in);
        System.out.println("\n1- Rastgele Kisi Uret\n2- Uretilmis Dosyayi Kontrol Et\n3- Cikis\n");
        System.out.print("Secim : ");
        int sec = oku.nextInt();
        switch (sec) {
            case 1:
                System.out.print("\nUretilecek Kisi Sayisi: ");
                int adet = oku.nextInt();
                KisiUret.KisileriOlustur(adet);
                Menu();
                break;
            case 2:
                KisiUret.DosyayiKontrolEt();
                Menu();
                break;
            case 3:
                System.out.println("Programdan cikiliyor...");
                System.exit(0);
                break;
        }
    }

    public static void main(String[] args) {
        try {
            Menu();
        } catch (IOException ex) {
            Logger.getLogger(test.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
