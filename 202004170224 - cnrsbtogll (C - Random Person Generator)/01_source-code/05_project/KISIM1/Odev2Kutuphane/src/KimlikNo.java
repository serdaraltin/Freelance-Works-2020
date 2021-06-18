public class KimlikNo {
    int[] kimlikNo;
    public KimlikNo(String _KimlikNo) {
        kimlikNo = new int[_KimlikNo.length()];
        for (int i = 0; i < _KimlikNo.length(); i++) 
            kimlikNo[i] = Character.getNumericValue(_KimlikNo.charAt(i));     
    }
    private KimlikNo(int[] _KimlikNo) {
        kimlikNo = _KimlikNo;
    }
    public static KimlikNo RastgeleKimlikUret() {
        Rastgele rast = new Rastgele();
        int[] _KimlikNo = new int[11];
        _KimlikNo[0] = rast.tamsayi(9) + 1;
        for (int i = 1; i < 9; i++) 
            _KimlikNo[i] = rast.tamsayi(10);
        _KimlikNo[9] = (((_KimlikNo[0] + _KimlikNo[2] + _KimlikNo[4] + _KimlikNo[6] + _KimlikNo[8]) * 7) - (_KimlikNo[1] + _KimlikNo[3] + _KimlikNo[5] + _KimlikNo[7])) % 10;
        _KimlikNo[10] = (_KimlikNo[0] + _KimlikNo[1] + _KimlikNo[2] + _KimlikNo[3] + _KimlikNo[4] + _KimlikNo[5] + _KimlikNo[6] + _KimlikNo[7] + _KimlikNo[8] + _KimlikNo[9]) % 10;
        return new KimlikNo(_KimlikNo);
    }
    @Override
    public String toString() {
        String tost = "";
        for (int i = 0; i < kimlikNo.length; i++)
            tost += kimlikNo[i];
        return tost;
    }
    boolean GecerliMi() {
        if (kimlikNo.length > 11) 
            return false;
        int Hane9 = (((kimlikNo[0] + kimlikNo[2] + kimlikNo[4] + kimlikNo[6] + kimlikNo[8]) * 7) - (kimlikNo[1] + kimlikNo[3] + kimlikNo[5] + kimlikNo[7])) % 10;
        int Hane10 = (kimlikNo[0] + kimlikNo[1] + kimlikNo[2] + kimlikNo[3] + kimlikNo[4] + kimlikNo[5] + kimlikNo[6] + kimlikNo[7] + kimlikNo[8] + Hane9) % 10;
        if (kimlikNo[9] == Hane9 && kimlikNo[10] == Hane10) 
            return true;
        return false;
    }


}
