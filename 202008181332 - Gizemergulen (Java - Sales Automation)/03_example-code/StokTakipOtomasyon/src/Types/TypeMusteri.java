package Types;

public class TypeMusteri {

    private String musterino;
    private String ad;
    private String soyad;

    public String getMusterino() {
        return musterino;
    }

    public void setMusterino(String musterino) {
        this.musterino = musterino;
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

    public TypeMusteri(String musterino, String ad, String soyad) {
        this.musterino = musterino;
        this.ad = ad;
        this.soyad = soyad;
    }

    public TypeMusteri() {
    }

    @Override
    public String toString() {
        return musterino + "\t\t" + ad + "\t" + soyad;
    }
    
    public String Yazdir() {
        return "MusteriNo: "+musterino + ", Adi: " + ad;
    }

    public boolean veriKontrol(TypeMusteri musteri) {

        if (this.musterino.equals(musteri.getMusterino()) || this.ad.equals(musteri.getAd()) || this.soyad.equals(musteri.getSoyad())) {
            return true;
        }
        return false;
    }

}
