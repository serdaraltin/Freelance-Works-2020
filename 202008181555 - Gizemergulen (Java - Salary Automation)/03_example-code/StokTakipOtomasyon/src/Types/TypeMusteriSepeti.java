package Types;

public class TypeMusteriSepeti {

    private String MusteriNo;
    private String UrunKodu;
    private int islemMiktari;
    private int islemTutari;
    private float KdvTutari;
    private int ToplamTutar;

    public TypeMusteriSepeti(String MusteriNo, String UrunKodu, int islemMiktari, int islemTutari, int KdvTutari, int ToplamTutar) {
        this.MusteriNo = MusteriNo;
        this.UrunKodu = UrunKodu;
        this.islemMiktari = islemMiktari;
        this.islemTutari = islemTutari;
        this.KdvTutari = KdvTutari;
        this.ToplamTutar = ToplamTutar;
    }

    public TypeMusteriSepeti() {
    }
    

    @Override
    public String toString() {

        return MusteriNo + "\t" + UrunKodu + "\t" + islemMiktari + "\t" + islemTutari + "\t" + KdvTutari;
    }

    public boolean veriKontrol(TypeMusteriSepeti musteriSepeti) {

        if (this.KdvTutari == musteriSepeti.getKdvTutari()
                || this.MusteriNo.equals(musteriSepeti.getMusteriNo())
                || this.UrunKodu.equals(musteriSepeti.getUrunKodu())
                || this.islemMiktari == musteriSepeti.getIslemMiktari()
                || this.islemTutari == musteriSepeti.getIslemTutari()) {
            return true;
        }
        return false;
    }

    public String getMusteriNo() {
        return MusteriNo;
    }

    public void setMusteriNo(String MusteriNo) {
        this.MusteriNo = MusteriNo;
    }

    public String getUrunKodu() {
        return UrunKodu;
    }

    public void setUrunKodu(String UrunKodu) {
        this.UrunKodu = UrunKodu;
    }

    public int getIslemMiktari() {
        return islemMiktari;
    }

    public void setIslemMiktari(int islemMiktari) {
        this.islemMiktari = islemMiktari;
    }

    public int getIslemTutari() {
        return islemTutari;
    }

    public void setIslemTutari(int islemTutari) {
        this.islemTutari = islemTutari;
    }

    public float getKdvTutari() {
        return KdvTutari;
    }

    public void setKdvTutari(float KdvTutari) {
        this.KdvTutari = KdvTutari;
    }

    public int getToplamTutar() {
        return ToplamTutar;
    }

    public void setToplamTutar(int ToplamTutar) {
        this.ToplamTutar = ToplamTutar;
    }

}
