public class Telefon {
    int[] _Telefon;
    IMEINo _IMEINo;
    public Telefon(String tel, String _IMEINo) {
        _Telefon = new int[_IMEINo.length()];
        for (int i = 0; i < tel.length(); i++)
            _Telefon[i] = Character.getNumericValue(tel.charAt(i));
        this._IMEINo = new IMEINo(_IMEINo);
    }
    private Telefon(int[] telefonNo, IMEINo _IMEINo) {
        this._Telefon = telefonNo;
        this._IMEINo = _IMEINo;
    }
    static Telefon TelefonOlustur() {
        int[] telefonNo = new int[11];
        telefonNo[0] = 0;
        telefonNo[1] = 5;
        Rastgele rast = new Rastgele();
        for (int i = 2; i < 11; i++) {
            telefonNo[i] = rast.tamsayi(10);
        }
        IMEINo _IMEINo = IMEINo.ImeiUret();
        return new Telefon(telefonNo, _IMEINo);
    }
    @Override
    public String toString() {
        String s = "";
        for (int i = 0; i < _Telefon.length; i++)
            s += _Telefon[i];
        return s + " (" + _IMEINo.toString() + ")";
    }


}
