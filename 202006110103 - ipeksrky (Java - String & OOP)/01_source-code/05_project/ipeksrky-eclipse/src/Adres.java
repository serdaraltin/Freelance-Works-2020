
//Adres sınıfı
public class Adres {

	//degiskenler
    private String mahalle;
    private int sokak;
    private int daireNo;
    private String sehir;

    //mahalle degiskeni get methodu
    public String getMahalle() {
        return mahalle;
    }
    
    //mahalle degiskeni set methodu
    public void setMahalle(String mahalle) {
        this.mahalle = mahalle;
    }

    //sokak degiskeni get methodu
    public int getSokak() {
        return sokak;
    }

    //sokak degiskeni set methodu
    public void setSokak(int sokak) {
        this.sokak = sokak;
    }

    //daire no degiskeni get methodu
    public int getDaireNo() {
        return daireNo;
    }

    //daire no degiskeni set methodu
    public void setDaireNo(int daireNo) {
        this.daireNo = daireNo;
    }

    //sehir degiskeni get methodu
    public String getSehir() {
        return sehir;
    }

    //sehir degiskeni set methodu
    public void setSehir(String sehir) {
        this.sehir = sehir;
    }

    //override edilmis toString methodu
    @Override
    public String toString() {
        return "Mahalle\t: " + mahalle + "\nSokak\t: " + sokak + "\nDaire No: " + daireNo + "\nSehir\t: " + sehir;
    }

	//yapıcı method, ilgili parametreleri alarak atama yapmakta
    public Adres(String mahalle, int sokak, int daireNo, String sehir) {
        this.mahalle = mahalle;
        this.sokak = sokak;
        this.daireNo = daireNo;
        this.sehir = sehir;
    }

	//yapıcı method
    public Adres() {
    }
    
    
}
