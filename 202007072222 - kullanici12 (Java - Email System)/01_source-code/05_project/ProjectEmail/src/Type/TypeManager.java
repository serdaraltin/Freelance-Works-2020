package Type;

public class TypeManager {
    private String KullaniciAd;
    private String Parola;

    public String getKullaniciAd() {
        return KullaniciAd;
    }

    public void setKullaniciAd(String KullaniciAd) {
        this.KullaniciAd = KullaniciAd;
    }

    public String getParola() {
        return Parola;
    }

    public void setParola(String Parola) {
        this.Parola = Parola;
    }

    public TypeManager(String KullaniciAd, String Parola) {
        this.KullaniciAd = KullaniciAd;
        this.Parola = Parola;
    }

    public TypeManager() {
    }

    @Override
    public String toString() {
        return "TypeManager{" + "KullaniciAd=" + KullaniciAd + ", Parola=" + Parola + '}';
    }
    
    
}
