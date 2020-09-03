package Types;

public class TypeUrun {

    private String urunkodu;
    private String adi;
    private int birimFiyati;
    private int KdvOrani;

    public String getUrunkodu() {
        return urunkodu;
    }

    public void setUrunkodu(String urunkodu) {
        this.urunkodu = urunkodu;
    }

    public String getAdi() {
        return adi;
    }

    public void setAdi(String adi) {
        this.adi = adi;
    }

    public int getBirimFiyati() {
        return birimFiyati;
    }

    public void setBirimFiyati(int birimFiyati) {
        this.birimFiyati = birimFiyati;
    }

    public int getKdvOrani() {
        return KdvOrani;
    }

    public void setKdvOrani(int KdvOrani) {
        this.KdvOrani = KdvOrani;
    }

    public TypeUrun(String urunkodu, String adi, int birimFiyati, int KdvOrani) {
        this.urunkodu = urunkodu;
        this.adi = adi;
        this.birimFiyati = birimFiyati;
        this.KdvOrani = KdvOrani;
    }

    public TypeUrun() {
    }

    @Override
    public String toString() {
        return urunkodu + "\t\t" + adi + "\t" + birimFiyati + "\t\t" + KdvOrani;
    }

    public boolean veriKontrol(TypeUrun urun) {

        if (this.urunkodu.equals(urun.getUrunkodu())
                || this.adi.equals(urun.getAdi()) 
                || this.KdvOrani == urun.getKdvOrani()
                || this.birimFiyati == urun.getBirimFiyati()){
            return true;
        }
        return false;
    }
}
