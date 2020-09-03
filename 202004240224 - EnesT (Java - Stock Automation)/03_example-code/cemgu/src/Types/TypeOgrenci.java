package Types;



public class TypeOgrenci{
    private int id;
    private String tcno;
    private String ad;
    private String soyad;
    private int yas;
    private String baba_adi;
    private String ana_adi;
    private String uyruk;
    private int bolum_id;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTcno() {
        return tcno;
    }

    public void setTcno(String tcno) {
        this.tcno = tcno;
    }

    public String getAd() {
        return ad;
    }

    public void setAd(String ad) {
        this.ad = ad;
    }

    public String getSoyad() {
        return soyad;
    }

    public void setSoyad(String soyad) {
        this.soyad = soyad;
    }

    public int getYas() {
        return yas;
    }

    public void setYas(int yas) {
        this.yas = yas;
    }

    public String getBaba_adi() {
        return baba_adi;
    }

    public void setBaba_adi(String baba_adi) {
        this.baba_adi = baba_adi;
    }

    public String getAna_adi() {
        return ana_adi;
    }

    public void setAna_adi(String ana_adi) {
        this.ana_adi = ana_adi;
    }

    public String getUyruk() {
        return uyruk;
    }

    public void setUyruk(String uyruk) {
        this.uyruk = uyruk;
    }

    public int getBolum_id() {
        return bolum_id;
    }

    public void setBolum_id(int bolum_id) {
        this.bolum_id = bolum_id;
    }

    @Override
    public String toString() {
        return "OgrenciType{" + "id=" + id + ", tcno=" + tcno + ", ad=" + ad + ", soyad=" + soyad + ", yas=" + yas + ", baba_adi=" + baba_adi + ", ana_adi=" + ana_adi + ", uyruk=" + uyruk + ", bolum_id=" + bolum_id + '}';
    }

    
    
    
}
