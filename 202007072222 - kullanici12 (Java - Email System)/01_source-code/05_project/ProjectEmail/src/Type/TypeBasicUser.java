package Type;

public class TypeBasicUser {
    private int KullaniciId;
    private String Ad;
    private String Soyad;
    private String Eposta;
    private String Parola;

    public int getKullaniciId() {
        return KullaniciId;
    }

    public void setKullaniciId(int KullaniciId) {
        this.KullaniciId = KullaniciId;
    }

    public String getAd() {
        return Ad;
    }

    public void setAd(String Ad) {
        this.Ad = Ad;
    }

    public String getSoyad() {
        return Soyad;
    }

    public void setSoyad(String Soyad) {
        this.Soyad = Soyad;
    }

    public String getEposta() {
        return Eposta;
    }

    public void setEposta(String Eposta) {
        this.Eposta = Eposta;
    }

    public String getParola() {
        return Parola;
    }

    public void setParola(String Parola) {
        this.Parola = Parola;
    }

    public TypeBasicUser(int KullaniciId, String Ad, String Soyad, String Eposta, String Parola) {
        this.KullaniciId = KullaniciId;
        this.Ad = Ad;
        this.Soyad = Soyad;
        this.Eposta = Eposta;
        this.Parola = Parola;
    }

    public TypeBasicUser() {
    }

    @Override
    public String toString() {
        return "TypeBasicUser{" + "KullaniciId=" + KullaniciId + ", Ad=" + Ad + ", Soyad=" + Soyad + ", Eposta=" + Eposta + ", Parola=" + Parola + '}';
    }
    
}
