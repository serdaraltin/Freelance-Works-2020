package Test;

import Controller.ConSozluk;
import Types.TypeKelime;

public class Create {

    public static void main(String[] args) {
        try {
            CreateDataBase createDataBase = new CreateDataBase();
            createDataBase.Create();
        } catch (Exception ex) {
            System.err.println(ex);
        }
        ConSozluk conTurkce = new ConSozluk();
        TypeKelime kelime = new TypeKelime(0, "türkçe","dil", "ingilizce", "anlam");
        conTurkce.Ekle(kelime);
    }
}
