/**
 * @author G161210113 - Hümeyra AY g161210113@sakarya.edu.tr B121210125 - Damla KARAGÖZ b121210125@sakarya.edu.tr
 * @since 1.4.2018
 * <p> Rastgele IMEI üreten ve üretilen numarayı kontrol eden sınıf </p>
 */


public class IMEINo {
    int[] imeiNO;

    private IMEINo(int[] tempIMEI) {
        imeiNO = tempIMEI;
    }

    public IMEINo() {

    }

    public IMEINo(String imei) {
        imeiNO = new int[15];
        for (int i = 0; i < imei.length(); i++)
            imeiNO[i] = Character.getNumericValue(imei.charAt(i));
    }

    public static IMEINo RastgeleIMEIUret() {
        RandomC rst = new RandomC();
        int[] tempIMEI = new int[15];
        tempIMEI[0] = rst.randomint(9) + 1;
        for (int i = 1; i < 14; i++) {
            tempIMEI[i] = rst.randomint(10);
        }
        int tekhanetoplam = 0;
        int cifthanetoplam = 0;
        for (int i = 0; i < 7; i++) {
            tekhanetoplam = tekhanetoplam + tempIMEI[i * 2];
            if (tempIMEI[1 + i * 2] * 2 >= 10) {
                int onlar = tempIMEI[1 + i * 2] * 2 / 10;
                int birler = tempIMEI[1 + i * 2] * 2 % 10;
                cifthanetoplam = cifthanetoplam + onlar + birler;
            } else
                cifthanetoplam = cifthanetoplam + tempIMEI[1 + i * 2] * 2;
        }
        tempIMEI[14] = (10 - (tekhanetoplam + cifthanetoplam) % 10) % 10;
        return new IMEINo(tempIMEI);
    }

    String Getir() {
        String s = "";
        for (int i = 0; i < imeiNO.length; i++)
            s += imeiNO[i];
        return s;
    }

    boolean GecerliMi() {
        if (imeiNO.length > 15)
            return false;
        int tekhanetoplam = 0;
        int cifthanetoplam = 0;
        for (int i = 0; i < 7; i++) {
            tekhanetoplam = tekhanetoplam + imeiNO[i * 2];
            if (imeiNO[1 + i * 2] * 2 >= 10) {
                int onlar = imeiNO[1 + i * 2] * 2 / 10;
                int birler = imeiNO[1 + i * 2] * 2 % 10;
                cifthanetoplam = cifthanetoplam + onlar + birler;
            } else
                cifthanetoplam = cifthanetoplam + imeiNO[1 + i * 2] * 2;
        }
        int i15 = (10 - (tekhanetoplam + cifthanetoplam) % 10) % 10;
        if (imeiNO[14] == i15)
            return true;
        return false;
    }
}

