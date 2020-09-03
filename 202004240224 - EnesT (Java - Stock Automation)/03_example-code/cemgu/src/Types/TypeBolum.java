package Types;

public class TypeBolum {
    private int id;
    private String ad;
    private int dersProgrami_id;
    private int sure;

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

    public int getDersProgrami_id() {
        return dersProgrami_id;
    }

    public void setDersProgrami_id(int dersProgrami_id) {
        this.dersProgrami_id = dersProgrami_id;
    }

    public int getSure() {
        return sure;
    }

    public void setSure(int sure) {
        this.sure = sure;
    }

    @Override
    public String toString() {
        return "TypeBolum{" + "id=" + id + ", ad=" + ad + ", dersProgrami_id=" + dersProgrami_id + ", sure=" + sure + '}';
    }
    
    
}
