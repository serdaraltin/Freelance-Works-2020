
public class Adres {

    private String mahalle;
    private int sokak;
    private int daireNo;
    private String sehir;


    public String getMahalle() {
        return mahalle;
    }

    public void setMahalle(String mahalle) {
        this.mahalle = mahalle;
    }

    public int getSokak() {
        return sokak;
    }

    public void setSokak(int sokak) {
        this.sokak = sokak;
    }

    public int getDaireNo() {
        return daireNo;
    }

    public void setDaireNo(int daireNo) {
        this.daireNo = daireNo;
    }

    public String getSehir() {
        return sehir;
    }

    public void setSehir(String sehir) {
        this.sehir = sehir;
    }

    @Override
    public String toString() {
        return "Mahalle\t: " + mahalle + "\nSokak\t: " + sokak + "\nDaire No: " + daireNo + "\nSehir\t: " + sehir;
    }

    public Adres(String mahalle, int sokak, int daireNo, String sehir) {
        this.mahalle = mahalle;
        this.sokak = sokak;
        this.daireNo = daireNo;
        this.sehir = sehir;
    }

    public Adres() {
    }
    
    
}
