package Types;

public class Typenotlar {
    private int id;
    private int ogrenci_id;
    private int ders_id;
    private int puan;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getOgrenci_id() {
        return ogrenci_id;
    }

    public void setOgrenci_id(int ogrenci_id) {
        this.ogrenci_id = ogrenci_id;
    }

    public int getDers_id() {
        return ders_id;
    }

    public void setDers_id(int ders_id) {
        this.ders_id = ders_id;
    }

    public int getPuan() {
        return puan;
    }

    public void setPuan(int puan) {
        this.puan = puan;
    }

    @Override
    public String toString() {
        return "Typenotlar{" + "id=" + id + ", ogrenci_id=" + ogrenci_id + ", ders_id=" + ders_id + ", puan=" + puan + '}';
    }

    
    
    
}
