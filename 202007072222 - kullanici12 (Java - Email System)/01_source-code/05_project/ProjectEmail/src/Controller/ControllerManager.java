package Controller;

import IO.IOFileOperation;
import Type.TypeManager;
import java.util.ArrayList;

public class ControllerManager {

    IOFileOperation fileOperation = new IOFileOperation();
    String dosyaAdi = "Admin.txt";

    public boolean Giris(String KullaniciAd, String Parola) {
        ArrayList<String[]> veriler = fileOperation.DosyaOku(dosyaAdi);
        TypeManager manager = new TypeManager(veriler.get(0)[0], veriler.get(0)[1]);

        if (manager.getKullaniciAd().equals(KullaniciAd) && manager.getParola().equals(Parola)) {
            return true;
        }
        
        return false;
    }
}
