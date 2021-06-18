package RASTGELEKISIURET;

import java.util.Random;

/**
 *
 * @author Muhammed Erdinc(erdincmuhammed@gmail.com)
 * @since 30.03.2018
 * <p>
 *  Telefon sınıfında Türkiyedeki telefon numaralarına uygun üretilmektedir. 
 * </p>
 */
public class Telefon {

    private final Random rakamuret = new Random();
    private String TelNumarasi = "";

    public String Telefon() {
        TelNumarasi = "";
        int TelDizi[] = new int[11];
        TelDizi[0] = 0;
        TelDizi[1] = 5;
        TelDizi[2] = rakamuret.nextInt(5) + 2;
        while (TelDizi[2] < 3 || TelDizi[2] > 5) {
            TelDizi[2] = rakamuret.nextInt(5) + 2;
        }
        for (int a = 3; a < 11; a++) {
            TelDizi[a] = rakamuret.nextInt(9);
        }
        for (int a = 0; a < 11; a++) {
            TelNumarasi += TelDizi[a];
        }
        return TelNumarasi;
    }
}
