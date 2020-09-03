
public class main {

    public static void main(String[] args) {
        //test
        
        //OgrenciListesi sınıfından yeni bir nesne uretilmesi
        OgrenciListesi ogrenciListesi = new OgrenciListesi();

        //ornek verilerin listeye eklenemesi
        ogrenciListesi.OgrenciEkle(new Ogrenci("mEhMet","YuRdAKuL","56987456321",1990,new Adres("Ali Osman", 1028, 56, "Kirikkale")));
        ogrenciListesi.OgrenciEkle(new Ogrenci("aHMet","SASMAZ","10987654321",1990,new Adres("Ali Osman", 1028, 56, "Kirikkale")));
        ogrenciListesi.OgrenciEkle(new Ogrenci("SELIN","sEVIM", "25487963211",1990,new Adres("Ali Osman", 1028, 56, "Kirikkale")));
        ogrenciListesi.OgrenciEkle(new Ogrenci("pelin","soZen", "87652432546",1990,new Adres("Ali Osman", 1028, 56, "Kirikkale")));
        
        //ornek verilerin listelenmesi
        ogrenciListesi.OgrenciListele();
    }
}
