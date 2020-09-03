
import java.util.ArrayList;

public class OgrenciListesi {

    private ArrayList<Ogrenci> ogrenciler = new ArrayList();

    public ArrayList<Ogrenci> getOgrenciler() {
        return ogrenciler;
    }

    public void setOgrenciler(ArrayList<Ogrenci> ogrenciler) {
        this.ogrenciler = ogrenciler;
    }

    public void OgrenciEkle(Ogrenci ogrenci) {
        ogrenciler.add(ogrenci);
    }

    public void OgrenciListele() {
        for (Ogrenci ogrenci : ogrenciler) {
            System.out.println(ogrenci + "\n");
        }
    }
}
