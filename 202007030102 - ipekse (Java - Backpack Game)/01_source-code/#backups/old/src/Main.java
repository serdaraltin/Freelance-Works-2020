//ilgili kütüphanelerin eklenmesi
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    //gerekli değişkenlerin tanımlanması, listeler ArrayList olarak String dizileri barındıracak şekilde tanımlanmıştır
    static int gun_sayisi = 0, sirtCantasiElemanlar = 0;
    static float sirtCantasiAgirlik = 0;
    static Scanner scn = new Scanner(System.in);
    static ArrayList<String[]> elbise = new ArrayList<String[]>();
    static ArrayList<String[]> yiyecekIcecek = new ArrayList<String[]>();
    static ArrayList<String[]> saglik = new ArrayList<String[]>();
    static ArrayList<String[]> arac = new ArrayList<String[]>();
    static Stack<String[]> sirtCantasi = new Stack<String[]>();
    static double elbiseToplamKg = 0, yiyecekIcecekToplamKg = 0, saglikToplamKg = 0, aracToplamKg = 0;

    //dosya okuma fonksiyonu verilen dosya yolundaki dosyadeki değerleri okuyup satırları bir String dizisine doldurarak geri döndürür
    public static String[] DosyaOku(String yol) {

        int i = 0;
        int uzunluk;

        try {
            uzunluk = Files.readAllLines(Paths.get(yol)).size();

            String[] sonuc = new String[uzunluk];

            for (String satir : Files.readAllLines(Paths.get(yol))) {
                sonuc[i++] = satir;
            }
            return sonuc;

        } catch (IOException ex) {
            ex.printStackTrace();
            return null;
        }

    }

    //ana fonksiyon
    public static void main(String[] args) {

        //proje dizinindeki "esyalar.txt" dosyasını dosya oku fonksiyonuna gönderip dönen dizideki elemaları tek tek gezerek ilgili listeye ekleme
        for (String satir : DosyaOku("esyalar.txt")) {
            switch (satir.split(",")[1]) {
                case "0":
                    elbise.add(satir.split(","));
                    break;
                case "1":
                    yiyecekIcecek.add(satir.split(","));
                    break;
                case "2":
                    saglik.add(satir.split(","));
                    break;
                case "3":
                    arac.add(satir.split(","));
                    break;
            }
        }
        
        System.out.println(">>> Hayatta Kalma Oyununa Hoş Geldiniz <<<");
        //eşya listelerinin hepsi boş olana dek dönen döngü
        while (!(elbise.size() == 0 && yiyecekIcecek.size() == 0 && saglik.size() == 0 && arac.size() == 0)) {
            //her döngüde yeni bir oyun başladığı için ilgili değerlerin sıfırlanması
            elbiseToplamKg = 0;
            yiyecekIcecekToplamKg = 0;
            saglikToplamKg = 0;
            aracToplamKg = 0;
            sirtCantasi.clear();
            
            System.out.println("*********************************");
            //listelerdeki eşyaların toplam ağırlıklarının ilgili değişkenelere atanması için tüm değerleri gezip ağırlıklarını ilgili değişkene atama
            for (String[] deger : elbise) {
                elbiseToplamKg += Double.parseDouble(deger[2]);
            }
            for (String[] deger : yiyecekIcecek) {
                yiyecekIcecekToplamKg += Double.parseDouble(deger[2]);
            }
            for (String[] deger : saglik) {
                saglikToplamKg += Double.parseDouble(deger[2]);
            }
            for (String[] deger : arac) {
                aracToplamKg += Double.parseDouble(deger[2]);
            }
            
            //menu fonksiyonu çağırımı
            Menu();

            //zorluk seçeneklerinin sunulması
            System.out.println("[0] Hacı\t[1] Gezgin\n[2] İzci\t[3] Savaşçı\n[9] Çıkış");
            System.out.print("Zorluk Seviyesi : ");
            int secim = scn.nextInt();

            System.out.println("\n\n");
            float toplamKg = 0, enCokKg = 0;
            //eşyarıgöster fonksiyonun çağrımı
            EsyalariGoster();
            //secime göre çantanın maximum ağırlığının belirlenmesi
            switch (secim) {
                case 0:
                    enCokKg = 9;
                    break;
                case 1:
                    enCokKg = 7;
                    break;
                case 2:
                    enCokKg = 5;
                    break;
                case 3:
                    enCokKg = 3;
                    break;
                case 9:
                    System.out.println("Programdan çıkılıyor...");
                    System.exit(0);
                    break;
            }
            System.out.println("\n\nKapasite : " + enCokKg + " kg \n");
            //listede çantadaki o anki boş alana sığacak eleman olana dek dönen döngü
            while (toplamKg < enCokKg || (enCokKg - toplamKg) > 0.09) {
                //ilgili listelerin içerisinde elemanlarının kontrolü eleman yoksa oyunun bitirilmesi
                if (elbise.size() == 0 && yiyecekIcecek.size() == 0 && saglik.size() == 0 && arac.size() == 0) {
                    SırtCantasiGoster();
                    Menu();
                    break;
                }
                //kategori bilgisinin alınması
                System.out.print("Kategori : ");
                int kategoriId = scn.nextInt();
                //secilen kategoriye gore esyaların yeni bir listeye doldurulması
                ArrayList<String[]> esyalar = new ArrayList<String[]>();
                switch (kategoriId) {
                    case 0:
                        esyalar = elbise;
                        break;
                    case 1:
                        esyalar = yiyecekIcecek;
                        break;
                    case 2:
                        esyalar = saglik;
                        break;
                    case 3:
                        esyalar = arac;
                        break;
                }
                scn.nextLine();
                //esya adı seçimi
                System.out.print("Ad : ");
                String esyaAdi = scn.nextLine();
                String[] esya;
                //seçilen eşyanın listeden silinip çantaya eklenemesi
                if (EsyaSil(esyalar, esyaAdi) != null) {
                    //eşyasil fonksiyonu çağrılıp eşya listesi ve eşya adı verilerek listeden eşyanın silinmesi
                    esya = EsyaSil(esyalar, esyaAdi);
                    //sırt çantasına ilgili eşyanın eklenmesi
                    if (Float.parseFloat(esya[2]) + toplamKg <= 9) {
                        toplamKg += Float.parseFloat(esya[2]);
                        sirtCantasi.push(esya);
                        esyalar.remove(esya);
                        System.out.println("Bilgi : Boş Alan : " + new DecimalFormat("##.##").format((enCokKg - toplamKg)));
                        EsyalariGoster();
                    } else {
                        System.err.println("Uyarı : Seçilen öğe sırt çantasına sığmıyor!!!");
                        continue;
                    }

                } else {
                    System.out.println("Uyarı : Bulunamadı!!!");
                    continue;
                }

            }
            //listelerde eşya kalmadığında sırt çantasındaki eşyaların gösterilmesi
            SırtCantasiGoster();
        }
        System.out.println("Uyarı : Boş yer kalmadı!");

    }
    
    //sırt çantasındaki eşyaları listeleyen fonksiyon
    public static void SırtCantasiGoster() {
        sirtCantasiAgirlik =0;
        sirtCantasiElemanlar = sirtCantasi.size();
        System.out.println("Sırt Çantasındaki Eşyalar");
         String leftAlignFormat = "| %-18s | %-8s | %-11s | %-7s|%n";
        System.out.format("+--------------------+----------+-------------+--------+%n");
        System.out.format("| Eşya Adı           | Kategori | Ağırlık(kg) | Kazanç |%n");
        System.out.format("+--------------------+----------+-------------+--------+%n");
        for (String[] strings : sirtCantasi) {
            System.out.format(leftAlignFormat, strings[0], strings[1], strings[2], strings[3]);
            gun_sayisi += Integer.parseInt(strings[3]);
            sirtCantasiAgirlik += Float.parseFloat(strings[2]);
        }
        System.out.format("+--------------------+----------+-------------+--------+%n");

    }
    //menuyu yazdıran fonksiyon
    public static void Menu() {

        System.out.println("Elbise\t\t" + elbise.size() + " eşya\t|  " + new DecimalFormat("##.##").format(elbiseToplamKg) + " kg");
        System.out.println("Yiyecek İçeçek\t" + yiyecekIcecek.size() + " eşya\t|  " + new DecimalFormat("##.##").format(yiyecekIcecekToplamKg) + " kg");
        System.out.println("Sağlık\t\t" + saglik.size() + " eşya\t|  " + new DecimalFormat("##.##").format(saglikToplamKg) + " kg");
        System.out.println("Araç\t\t" + arac.size() + " eşya\t|  " + new DecimalFormat("##.##").format(aracToplamKg) + " kg");
        if (gun_sayisi != 0) {
            System.out.println("Sırt Çantası\t" + sirtCantasiElemanlar + " eşya\t|  " + new DecimalFormat("##.##").format(sirtCantasiAgirlik) + " kg");
            System.out.println("Yaşam Süresi\t" + gun_sayisi + " gün\t|");
            sirtCantasiAgirlik = 0;
            sirtCantasiElemanlar = 0;
            gun_sayisi = 0;
        }
        System.out.println("*********************************");
    }
    //tüm listelerdeki tüm eşyaları yazdıran fonksiyon
    public static void EsyalariGoster() {

        String leftAlignFormat = "| %-18s | %-8s | %-11s | %-7s|%n";
        System.out.println("Elbise > 0    Yiyecek İçeçek> 1    Sağlık > 2   Araç >3");
        System.out.format("+--------------------+----------+-------------+--------+%n");
        System.out.format("| Eşya Adı           | Kategori | Ağırlık(kg) | Kazanç |%n");
        System.out.format("+--------------------+----------+-------------+--------+%n");
        for (String[] deger : elbise) {
            System.out.format(leftAlignFormat, deger[0], deger[1], deger[2], deger[3]);
        }

        for (String[] deger : yiyecekIcecek) {
            System.out.format(leftAlignFormat, deger[0], deger[1], deger[2], deger[3]);
        }

        for (String[] deger : saglik) {
            System.out.format(leftAlignFormat, deger[0], deger[1], deger[2], deger[3]);
        }

        for (String[] deger : arac) {
            System.out.format(leftAlignFormat, deger[0], deger[1], deger[2], deger[3]);
        }
        System.out.format("+--------------------+----------+-------------+--------+%n");
    }
    //verilen parametrelere göre ilgili listedeki ilgili eşyanın silinmesi
    public static String[] EsyaSil(ArrayList<String[]> esyalar, String esyaAdi) {
        for (String[] deger : esyalar) {
            if (esyaAdi.equals(deger[0])) {
                return deger;
            }
        }
        return null;
    }

}
