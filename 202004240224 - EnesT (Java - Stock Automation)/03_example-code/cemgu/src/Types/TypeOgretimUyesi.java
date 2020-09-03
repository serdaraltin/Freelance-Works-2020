package Types;



public class TypeOgretimUyesi{
    private int id;
    private String tcno;
    private String ad;
    private String soyad;
    private int yas;
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

    public int getBolum_id() {
        return bolum_id;
    }

    public void setBolum_id(int bolum_id) {
        this.bolum_id = bolum_id;
    }

    @Override
    public String toString() {
        return "TypeOgretimUyesi{" + "id=" + id + ", tcno=" + tcno + ", ad=" + ad + ", soyad=" + soyad + ", yas=" + yas + ", bolum_id=" + bolum_id + '}';
    }

   
    
}
