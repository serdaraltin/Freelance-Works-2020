package Types;


public class TypeDers {
    private int id;
    private String ad;
    private int kredi;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAd() {
        return ad;
    }

    public void setAd(String ad) {
        this.ad = ad;
    }

    public int getKredi() {
        return kredi;
    }

    public void setKredi(int kredi) {
        this.kredi = kredi;
    }

    @Override
    public String toString() {
        return "TypeDers{" + "id=" + id + ", ad=" + ad + ", kredi=" + kredi + '}';
    }
    
    
}
