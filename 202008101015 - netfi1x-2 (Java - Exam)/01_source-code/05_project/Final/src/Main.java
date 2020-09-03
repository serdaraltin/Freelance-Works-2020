
import com.Islemler;
import com.Ogrenci;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        Islemler islemler = new Islemler();
        ArrayList<Ogrenci> ogrenciler = islemler.NotGir();
        float ortalama = islemler.OrtalamaHesapla(ogrenciler);
        System.out.println("Ogrencilerin not ortalamasi : " + ortalama);
    }
}
