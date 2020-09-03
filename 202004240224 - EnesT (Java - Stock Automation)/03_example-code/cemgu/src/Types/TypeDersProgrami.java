
package Types;

public class TypeDersProgrami {
    private int id;
    private String ad;
    private int pazartesi;//ders_id
    private int sali;//ders_id
    private int carsamba;//ders_id
    private int persembe;//ders_id
    private int cuma;//ders_id

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

    public int getPazartesi() {
        return pazartesi;
    }

    public void setPazartesi(int pazartesi) {
        this.pazartesi = pazartesi;
    }

    public int getSali() {
        return sali;
    }

    public void setSali(int sali) {
        this.sali = sali;
    }

    public int getCarsamba() {
        return carsamba;
    }

    public void setCarsamba(int carsamba) {
        this.carsamba = carsamba;
    }

    public int getPersembe() {
        return persembe;
    }

    public void setPersembe(int persembe) {
        this.persembe = persembe;
    }

    public int getCuma() {
        return cuma;
    }

    public void setCuma(int cuma) {
        this.cuma = cuma;
    }

    @Override
    public String toString() {
        return "TypeDersProgrami{" + "id=" + id + ", ad=" + ad + ", pazartesi=" + pazartesi + ", sali=" + sali + ", carsamba=" + carsamba + ", persembe=" + persembe + ", cuma=" + cuma + '}';
    }
    
    
}
