
import java.util.Scanner;

public class Uygulama_1 {

    Scanner scanner = new Scanner(System.in);

    //karakök hesaplama methodu
    public void KokAlma() {
        System.out.print("Koku alinacak sayi: ");
        double sayi = scanner.nextDouble();
        //Math kütüphanesi sqrt methodundan gelen değer ile karakök hesaplanması
        System.out.println("Sonuc: " + Math.sqrt(sayi));
    }
    //küp hesaplama methodu
    public void KupAlma() {
        System.out.print("Kupu alinacak sayi: ");
        double sayi = scanner.nextDouble();
        //gelen değerin küpü için kendi ile 3 defa çarpılması
        System.out.println("Sonuc: " + (sayi * sayi * sayi));
    }
    //kuvvet hesaplama methodu
    public void KuvvetAlma() {
        System.out.print("Kuvveti alinacak sayi: ");
        double sayi = scanner.nextDouble();
        System.out.print("Kuvvet degeri: ");
        double kuvvet = scanner.nextDouble();
        //kuvvet değeri kadar sayı değerinin kendi ile çarpılması
        double sonuc = 1;
        for (int i = 0; i < kuvvet; i++) {
            sonuc *= sayi;
        }
        System.out.println("Sonuc: " + sonuc);
    }
    //ortalama hesaplama methodu
    public void OrtalamaAlma() {
        System.out.print("Kac adet sayi girilecek: ");
        int adet = scanner.nextInt();
        //klavyeden okunan değerlerin toplanması, adet kadar
        int toplam = 0;
        for (int i = 1; i <= adet; i++) {
            System.out.print(i + ". sayi: ");
            int sayi = scanner.nextInt();
            toplam += sayi;
        }
        //ortalama alınması, toplamın adete bölümü
        double ortalama = (double) toplam / (double) adet;
        System.out.println("Sonuc: " + ortalama);
    }
    //faktöriyel hesaplama methodu
    public void FaktoriyelALma() {
        System.out.print("Faktoriyeli alinacak sayi: ");
        int sayi = scanner.nextInt();
        //2 den başlayıp sayı değerine kadar devam eden döngü
        int faktoriyel = 1;
        for (int i = 2; i <= sayi; i++) {
            faktoriyel *= i;
        }
        System.out.println("Sonuc: " + faktoriyel);
    }
    
}
