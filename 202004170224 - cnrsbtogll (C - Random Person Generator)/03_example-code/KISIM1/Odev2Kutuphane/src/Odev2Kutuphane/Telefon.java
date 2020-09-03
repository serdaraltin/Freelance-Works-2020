package Odev2Kutuphane;


public class Telefon {

    private final Rastgele rakamuret = new Rastgele();
    private String TelNumarasi = "";

    public String Telefon() {
        TelNumarasi = "";
        int TelDizi[] = new int[11];
        TelDizi[0] = 0;
        TelDizi[1] = 5;
        TelDizi[2] = rakamuret.random(5) + 2;
        while (TelDizi[2] < 3 || TelDizi[2] > 5) {
            TelDizi[2] = rakamuret.random(5) + 2;
        }
        for (int a = 3; a < 11; a++) {
            TelDizi[a] = rakamuret.random(9);
        }
        for (int a = 0; a < 11; a++) {
            TelNumarasi += TelDizi[a];
        }
        return TelNumarasi;
    }
}
