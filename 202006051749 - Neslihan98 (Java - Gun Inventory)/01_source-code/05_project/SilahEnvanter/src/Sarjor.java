
public class Sarjor {

    private int mermiKapasitesi;
    private int anlikMermiSayisi;

    public void SarjorDoldur() {
        anlikMermiSayisi = mermiKapasitesi;
    }

    public boolean MermiAtesle(int mermiMiktari) {
        if (anlikMermiSayisi == 0) {
            return false;
        } else if (anlikMermiSayisi >= mermiMiktari) {
            anlikMermiSayisi -= mermiMiktari;
            return true;
        }
        return false;
    }

    public int getMermiKapasitesi() {
        return mermiKapasitesi;
    }

    public void setMermiKapasitesi(int mermiKapasitesi) {
        this.mermiKapasitesi = mermiKapasitesi;
    }

    public int getAnlikMermiSayisi() {
        return anlikMermiSayisi;
    }

    public void setAnlikMermiSayisi(int anlikMermiSayisi) {
        this.anlikMermiSayisi = anlikMermiSayisi;
    }

    public Sarjor(int mermiKapasitesi) {
        this.mermiKapasitesi = mermiKapasitesi;
    }

    public Sarjor(int mermiKapasitesi, int anlikMermiSayisi) {
        this.mermiKapasitesi = mermiKapasitesi;
        this.anlikMermiSayisi = anlikMermiSayisi;
    }

}
