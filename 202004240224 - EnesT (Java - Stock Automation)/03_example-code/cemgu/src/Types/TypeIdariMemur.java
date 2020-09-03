package Types;


public class TypeIdariMemur{
    private int id;
    private String tcno;
    private String ad;
    private String soyad;
    private int yas;
    private String gorev;

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

    public String getGorev() {
        return gorev;
    }

    public void setGorev(String gorev) {
        this.gorev = gorev;
    }

    @Override
    public String toString() {
        return "IdariMemur{" + "id=" + id + ", tcno=" + tcno + ", ad=" + ad + ", soyad=" + soyad + ", yas=" + yas + ", gorev=" + gorev + '}';
    }
    
    

    
}
