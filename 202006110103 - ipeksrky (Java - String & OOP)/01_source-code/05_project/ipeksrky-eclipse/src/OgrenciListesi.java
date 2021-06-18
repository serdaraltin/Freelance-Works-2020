//ilgili kutuphanelerin dahil edilmesi
import java.util.ArrayList;

//ogrenci listesi sınıfı
public class OgrenciListesi {

    //ogrencilerin listesi, arraylist icerisinde tutulmakta
    private ArrayList<Ogrenci> ogrenciler = new ArrayList();

    //ogrencilerin listesi get methodu
    public ArrayList<Ogrenci> getOgrenciler() {
        return ogrenciler;
    }

    //ogrencilerin listesi set methodu
    public void setOgrenciler(ArrayList<Ogrenci> ogrenciler) {
        this.ogrenciler = ogrenciler;
    }

    //Ogrenci Ekele methodu, ogrenci turunde aldıgı nesneyi ogrenciler listesine ekler
    public void OgrenciEkle(Ogrenci ogrenci) {
        ogrenciler.add(ogrenci);
    }

    //Ogrenci Listele ogrenci listesindeki ogrencileri listeler
    public void OgrenciListele() {
        for (Ogrenci ogrenci : ogrenciler) {
            System.out.println(ogrenci + "\n");
        }
    }
}
