public class Kisi {
    KimlikNo _KimlikNo;
    String _Ad;
    String _Soyad;
    int _Yas;
    Telefon _T;
    private Kisi(KimlikNo _GKimlikNo, String _Ad, String _Soyad, int _Yas, Telefon _T) {
        this._KimlikNo = _GKimlikNo;
        this._Ad = _Ad;
        this._Soyad = _Soyad;
        this._Yas = _Yas;
        this._T = _T;
    }
    public static Kisi RastgeleKisiUret(String get) {
        Rastgele rast = new Rastgele();
        KimlikNo _GKimlikNo = KimlikNo.RastgeleKimlikUret();
        String[] _AdDizi = get.split(" ");
        String _Ad = _AdDizi[0];
        String _Soyad = _AdDizi[1];
        int _Yas = rast.tamsayi(100);
        Telefon _T = Telefon.TelefonOlustur();
        return new Kisi(_GKimlikNo, _Ad, _Soyad, _Yas, _T);
    }
    static Kisi StringToKisi(String get) {
        String[] bolum = get.split(" ");
        KimlikNo _GKimlikNo = new KimlikNo(bolum[0]);
        String _Ad = bolum[1];
        String _Soyad = bolum[2];
        int _Yas = Integer.valueOf(bolum[3]);
        Telefon _T = new Telefon(bolum[4], bolum[5].substring(1, 16));
        return new Kisi(_GKimlikNo, _Ad, _Soyad, _Yas, _T);
    }
    public Kisi() {/*cons*/ }
    @Override
    public String toString() {
        return _KimlikNo.toString() + " " + _Ad + " " + _Soyad + " " + _Yas + " " + _T.toString();
    }
}
