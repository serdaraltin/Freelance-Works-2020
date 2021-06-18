/**
 * @author G161210113 - Hümeyra AY g161210113@sakarya.edu.tr B121210125 - Damla KARAGÖZ b121210125@sakarya.edu.tr
 * @since 1.4.2018
 * <p> Kişinin tanımlandığı sınıf </p>
 */


public class Kisi {

    KimlikNo kimlik;
    String ad, soyAd;
    int yas;
    Telefon tel;

    public Kisi() {

    }

    private Kisi(KimlikNo tempKimlik, String ad, String soyAd, int yas, Telefon tel) {
        this.kimlik = tempKimlik;
        this.ad = ad;
        this.soyAd = soyAd;
        this.yas = yas;
        this.tel = tel;
    }

    public static Kisi RastgeleKisiUret(String get) {
        RandomC rng = new RandomC();
        KimlikNo tempKimlik = KimlikNo.RastgeleKimlikUret();
        String[] adDizi = get.split(" ");
        String ad = adDizi[0];
        String soyAd = adDizi[1];
        int yas = rng.randomint(100);
        Telefon tel = Telefon.TelefonOlustur();

        return new Kisi(tempKimlik, ad, soyAd, yas, tel);
    }

    static Kisi StringToKisi(String get) {
        String[] bolum = get.split(" ");
        KimlikNo tempKimlik = new KimlikNo(bolum[0]);
        String ad = bolum[1];
        String soyAd = bolum[2];
        int yas = Integer.valueOf(bolum[3]);
        Telefon tel = new Telefon(bolum[4], bolum[5].substring(1, 16));
        return new Kisi(tempKimlik, ad, soyAd, yas, tel);
    }

    public String Getir() {
        return kimlik.Getir() + " " + ad + " " + soyAd + " " + yas + " " + tel.Getir();
    }

}
