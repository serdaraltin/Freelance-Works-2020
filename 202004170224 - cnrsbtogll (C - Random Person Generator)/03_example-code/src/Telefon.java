/**
 * @author G161210113 - Hümeyra AY g161210113@sakarya.edu.tr B121210125 - Damla KARAGÖZ b121210125@sakarya.edu.tr
 * @since 1.4.2018
 * <p> Rastgele telefon üreten ve imei ile bağlantısı olan sınıf </p>
 */


public class Telefon {

    int[] telNo;
    IMEINo imei;

    public Telefon(String tel, String imei) {
        telNo = new int[imei.length()];
        for (int i = 0; i < tel.length(); i++)
            telNo[i] = Character.getNumericValue(tel.charAt(i));
        this.imei = new IMEINo(imei);
    }

    private Telefon(int[] telefonNo, IMEINo imei) {
        this.telNo = telefonNo;
        this.imei = imei;
    }

    static Telefon TelefonOlustur() {

        int[] telefonNo = new int[11];
        telefonNo[0] = 0;
        telefonNo[1] = 5;
        RandomC rng = new RandomC();
        for (int i = 2; i < 11; i++) {
            telefonNo[i] = rng.randomint(10);
        }
        IMEINo imei = IMEINo.RastgeleIMEIUret();
        return new Telefon(telefonNo, imei);
    }

    String Getir() {
        String s = "";
        for (int i = 0; i < telNo.length; i++)
            s += telNo[i];
        return s + " (" + imei.Getir() + ")";
    }

}
