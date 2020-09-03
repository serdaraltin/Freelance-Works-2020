
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Stack;

public class Islemler {

    //gerekli değişkenlerin tanımlanması, listeler ArrayList olarak String dizileri barındıracak şekilde tanımlanmıştır
    int gun_sayisi = 0, sirtCantasiElemanlar = 0;
    float sirtCantasiAgirlik = 0;
    ArrayList<String[]> elbise = new ArrayList<String[]>();
    ArrayList<String[]> yiyecekIcecek = new ArrayList<String[]>();
    ArrayList<String[]> saglik = new ArrayList<String[]>();
    ArrayList<String[]> arac = new ArrayList<String[]>();
    Stack<String[]> sirtCantasi = new Stack<String[]>();
    double elbiseToplamKg = 0, yiyecekIcecekToplamKg = 0, saglikToplamKg = 0, aracToplamKg = 0;

    //dosya okuma fonksiyonu verilen dosya yolundaki dosyadeki değerleri okuyup satırları bir String dizisine doldurarak geri döndürür
    public String[] DosyaOku(String yol) {
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

    public  void Isle() {
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
    }
    
    //verilen parametrelere göre ilgili listedeki ilgili eşyanın silinmesi
    public static String[] EsyaBul(ArrayList<String[]> esyalar, String esyaAdi) {
        for (String[] deger : esyalar) {
            if (esyaAdi.equals(deger[0])) {
                return deger;
            }
        }
        return null;
    }

}
