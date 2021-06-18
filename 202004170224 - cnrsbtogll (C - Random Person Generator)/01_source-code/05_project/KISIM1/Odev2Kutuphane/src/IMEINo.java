public class IMEINo {
    int[] imei;
    private IMEINo(int[] _imei) {
        imei = _imei;
    }
    public IMEINo(String _imei) {
        imei = new int[15];
        for (int i = 0; i < _imei.length(); i++)
            imei[i] = Character.getNumericValue(_imei.charAt(i));
    }
    public static IMEINo ImeiUret() {
        Rastgele rast = new Rastgele();
        int[] imeiNO = new int[15];
        imeiNO[0] = rast.tamsayi(9) + 1;
        for (int i = 1; i < 14; i++) 
            imeiNO[i] = rast.tamsayi(10);
        int t = 0,c = 0;
        for (int i = 0; i < 7; i++) {
            t = t + imeiNO[i * 2];
            if (imeiNO[1 + i * 2] * 2 >= 10) {
                int onlar = imeiNO[1 + i * 2] * 2 / 10;
                int birler = imeiNO[1 + i * 2] * 2 % 10;
                c = c + onlar + birler;
            } else
                c = c + imeiNO[1 + i * 2] * 2;
        }
        imeiNO[14] = (10 - (t + c) % 10) % 10;
        return new IMEINo(imeiNO);
    }
    @Override
    public String toString() {
         String s = "";
        for (int i = 0; i < imei.length; i++)
            s += imei[i];
        return s;
    }
    boolean ImeiKontrol() {
       double a = 0, b = 0;
        int ImeiDizi[] = new int[imei.length];
        if (imei.length != 15) 
            return false;
        
        for (int i = 0; i < imei.length; i++) 
            ImeiDizi[i] = imei[i];
        for (int i = 0; i <= 12; i += 2) 
            a += ImeiDizi[i];
        for (int i = 1; i <= 13; i += 2) {
            if (ImeiDizi[i] * 2 > 9) 
                b += ImeiDizi[i] * 2 - 9;
             else 
                b += ImeiDizi[i] * 2;
        }
        double backup = ((Math.ceil((a + b) / 10)) * 10);
        if (backup - (a + b) == ImeiDizi[14]) 
            return true;
         else 
            return false;
    }
}

