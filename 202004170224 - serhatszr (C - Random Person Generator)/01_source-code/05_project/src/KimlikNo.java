/**
 * @author G161210113 - Hümeyra AY g161210113@sakarya.edu.tr B121210125 - Damla KARAGÖZ b121210125@sakarya.edu.tr
 * @since 1.4.2018
 * <p> Rastgele T.C. kimlik no üreten ve üretilen numarayı kontrol eden sınıf </p>
 */

public class KimlikNo {

    int[] kimlikNo;

    public KimlikNo(String tc) {
        kimlikNo = new int[tc.length()];
        for (int i = 0; i < tc.length(); i++) {
            kimlikNo[i] = Character.getNumericValue(tc.charAt(i));
        }
    }

    private KimlikNo(int[] tempKimlikNo) {
        kimlikNo = tempKimlikNo;
    }

    public static KimlikNo RastgeleKimlikUret() {
        RandomC rast = new RandomC();
        int[] tempKimlikNo = new int[11];
        tempKimlikNo[0] = rast.randomint(9) + 1;
        for (int i = 1; i < 9; i++) {
            tempKimlikNo[i] = rast.randomint(10);
        }
        tempKimlikNo[9] = (((tempKimlikNo[0] + tempKimlikNo[2] + tempKimlikNo[4] + tempKimlikNo[6] + tempKimlikNo[8]) * 7) - (tempKimlikNo[1] + tempKimlikNo[3] + tempKimlikNo[5] + tempKimlikNo[7])) % 10;
        tempKimlikNo[10] = (tempKimlikNo[0] + tempKimlikNo[1] + tempKimlikNo[2] + tempKimlikNo[3] + tempKimlikNo[4] + tempKimlikNo[5] + tempKimlikNo[6] + tempKimlikNo[7] + tempKimlikNo[8] + tempKimlikNo[9]) % 10;
        return new KimlikNo(tempKimlikNo);
    }

    String Getir() {
        String s = "";
        for (int i = 0; i < kimlikNo.length; i++)
            s += kimlikNo[i];
        return s;
    }


    boolean GecerliMi() {
        if (kimlikNo.length > 11) {
            return false;
        }
        int k9 = (((kimlikNo[0] + kimlikNo[2] + kimlikNo[4] + kimlikNo[6] + kimlikNo[8]) * 7) - (kimlikNo[1] + kimlikNo[3] + kimlikNo[5] + kimlikNo[7])) % 10;
        int k10 = (kimlikNo[0] + kimlikNo[1] + kimlikNo[2] + kimlikNo[3] + kimlikNo[4] + kimlikNo[5] + kimlikNo[6] + kimlikNo[7] + kimlikNo[8] + k9) % 10;
        //System.out.println(k9+" "+k10);
        if (kimlikNo[9] == k9 && kimlikNo[10] == k10) {
            return true;
        }
        return false;
    }


}
