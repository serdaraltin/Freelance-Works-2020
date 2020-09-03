package Main;

import Controller.ConBolum;
import Controller.ConDers;
import Controller.ConDersProgrami;
import Controller.ConOgrenci;
import Controller.ConOgretimUyesi;
import Controller.Connotlar;
import Core.ObjectHelper;
import Types.TypeBolum;
import Types.TypeDers;
import Types.TypeDersProgrami;
import Types.TypeOgrenci;
import Types.TypeOgretimUyesi;
import Types.Typenotlar;
import java.util.Scanner;

public class Main extends ObjectHelper {

    public static void main(String[] args) {
        MainMenu();
    }

    public static void Baslik(String baslik) {
        System.out.println("==== [" + baslik.toUpperCase() + "] =====");
    }

    public static void SecenekEkle(int no, String sik) {
        System.out.println(no + ") " + sik.toUpperCase());
    }

    public static String VeriGirString(String soru) {
        Scanner oku = new Scanner(System.in);
        System.out.print(soru.toUpperCase() + " : ");
        return oku.nextLine();
    }

    public static int VeriGirInt(String soru) {
        Scanner oku = new Scanner(System.in);
        System.out.print(soru.toUpperCase() + " : ");
        return oku.nextInt();
    }

    public static void MainMenu() {
        Baslik("ana menü");
        SecenekEkle(1, "idari işlemler");
        SecenekEkle(2, "öğretim üyesi işlemler");
        SecenekEkle(3, "öğrenci işlemler");
        SecenekEkle(4, "çıkış");
        int secim;
        System.out.print("Seçiniz : ");
        Scanner oku = new Scanner(System.in);
        secim = oku.nextInt();

        switch (secim) {
            case 1:
                IdariIslemler();
                break;
            case 2:
                OgretimUyesiIslemler();
                break;
            case 3:
                OgrenciIslemler();
            case 4:
                System.out.println("Programdan çıkılıyor...");
                break;
            default:
                System.out.println("Hatalı seçim yaptınız!!! Tekrar deneyin");
                MainMenu();
                break;
        }
    }

    public static void IdariIslemler() {
        Baslik("idari işlemler");
        SecenekEkle(1, "öğrenci ekle");
        SecenekEkle(2, "öğretim üyesi ekle");
        SecenekEkle(3, "ders ekle");
        SecenekEkle(4, "ders programı ekle");
        SecenekEkle(5, "ana menüye dön");
        int secim;
        System.out.print("Seçiniz : ");
        Scanner oku = new Scanner(System.in);
        secim = oku.nextInt();

        switch (secim) {
            case 1://öğrenci ekle
                OgrenciEkle();
                break;
            case 2://öğretim üyesi ekle
                OgretimUyesiEkle();
                break;
            case 3://ders ekle
                DersEkle();
            case 4://ders programı ekle
                DersProgramiEkle();
                break;
            case 5:
                MainMenu();
                break;
            default:
                System.out.println("Hatalı seçim yaptınız!!! Tekrar deneyin");
                IdariIslemler();
                break;

        }
    }

    public static void OgrenciEkle() {
        Baslik("öğrenci ekleme");
        TypeOgrenci ogrenci = new TypeOgrenci();
        ogrenci.setTcno(VeriGirString("tc no"));
        ogrenci.setAd(VeriGirString("ad"));
        ogrenci.setSoyad(VeriGirString("soyad"));
        ogrenci.setYas(VeriGirInt("yas"));
        ogrenci.setBaba_adi(VeriGirString("baba adı"));
        ogrenci.setAna_adi(VeriGirString("ana adı"));
        ogrenci.setUyruk(VeriGirString("uyruk"));

        System.out.println("========= BÖLÜMLER =========");
        ConBolum bolumler = new ConBolum();
        bolumler.Listele().forEach((bolum) -> {
            System.out.print("No : [" + bolum.getId() + "] " + bolum.getAd() + "\n");
        });
        System.out.println("========= BÖLÜMLER =========");
        ogrenci.setBolum_id(VeriGirInt("bolum no"));

        ConOgrenci conOgrenci = new ConOgrenci();
        if (conOgrenci.Ekle(ogrenci)) {
            System.out.println("ÖĞRENCİ EKLENDİ");
        } else {
            System.err.println("İŞLEM BAŞARISIZ !!!");
        }
        IdariIslemler();
    }

    public static void OgretimUyesiEkle() {
        Baslik("öğretim üyesi ekleme");
        TypeOgretimUyesi uye = new TypeOgretimUyesi();
        uye.setTcno(VeriGirString("tc no"));
        uye.setAd(VeriGirString("ad"));
        uye.setSoyad(VeriGirString("soyad"));
        uye.setYas(VeriGirInt("yas"));

        System.out.println("========= BÖLÜMLER =========");
        ConBolum bolumler = new ConBolum();
        bolumler.Listele().forEach((bolum) -> {
            System.out.print("No : [" + bolum.getId() + "] " + bolum.getAd() + "\n");
        });
        System.out.println("========= BÖLÜMLER =========");
        uye.setBolum_id(VeriGirInt("bolum no"));

        ConOgretimUyesi conogretimUyesi = new ConOgretimUyesi();
        if (conogretimUyesi.Ekle(uye)) {
            System.out.println("ÖĞRETİM ÜYESİ EKLENDİ");
        } else {
            System.err.println("İŞLEM BAŞARISIZ !!!");
        }

        IdariIslemler();
    }

    public static void DersEkle() {
        Baslik("ders ekleme");
        TypeDers ders = new TypeDers();
        ders.setAd(VeriGirString("ad"));
        ders.setKredi(VeriGirInt("kredi"));

        ConDers conDers = new ConDers();
        if (conDers.Ekle(ders)) {
            System.out.println("DERS EKLENDİ");
        } else {
            System.err.println("İŞLEM BAŞARISIZ !!!");
        }
        IdariIslemler();
    }

    public static void DersProgramiEkle() {
        Baslik("ders programı ekleme");
        TypeDersProgrami dersProgrami = new TypeDersProgrami();
        dersProgrami.setAd(VeriGirString("ad"));

        ConDersProgrami conDersProgrami = new ConDersProgrami();
        System.out.println("========= DERSLER =========");
        conDersProgrami.Listele().forEach((ders) -> {
            System.out.print("No : [" + ders.getId() + "] " + ders.getAd() + "\n");
        });
        System.out.println("========= DERSLER =========");
        dersProgrami.setPazartesi(VeriGirInt("pazartesi [ders no]"));
        dersProgrami.setSali(VeriGirInt("salı [ders no]"));
        dersProgrami.setCarsamba(VeriGirInt("çarsamba [ders no]"));
        dersProgrami.setPersembe(VeriGirInt("perşembe [ders no]"));
        dersProgrami.setCuma(VeriGirInt("cuma [ders no]"));
        if (conDersProgrami.Ekle(dersProgrami)) {
            System.out.println("DERS EKLENDİ");
        } else {
            System.err.println("İŞLEM BAŞARISIZ !!!");
        }

        for (TypeDersProgrami y : conDersProgrami.Listele()) {
            System.out.println(y.toString());
        }
        IdariIslemler();
    }

    public static void OgretimUyesiIslemler() {
        Baslik("öğretim üyesi işlemler");
        SecenekEkle(1, "not gir");
        SecenekEkle(2, "öğrenci listele");
        SecenekEkle(3, "ders programı listele");
        SecenekEkle(4, "ana menüye dön");
        int secim;
        System.out.print("Seçiniz : ");
        Scanner oku = new Scanner(System.in);
        secim = oku.nextInt();

        switch (secim) {
            case 1://not gir
                NotGir();
                break;
            case 2://öğrenci listele
                OgrenciListele();
                break;
            case 3://ders programı listele
                DersProgramiListele();
            case 4://ana menüye dön
                MainMenu();
                break;
            default:
                System.out.println("Hatalı seçim yaptınız!!! Tekrar deneyin");
                OgretimUyesiIslemler();
                break;

        }
    }

    public static void NotGir() {
        Baslik("not girişi");
        System.out.println("ÖĞRENCİLER LİSTELENSİN Mİ ?");
        ConOgrenci conOgrenci = new ConOgrenci();
        ConBolum conBolum = new ConBolum();
        if (VeriGirString("Evet[e]/Hayır[h]").equals("e")) {
            System.out.println("===== ÖĞRENCİLER =====");
            conOgrenci.Listele().forEach((ogrenci) -> {
                TypeBolum obolum = new TypeBolum();
                for (TypeBolum bolum : conBolum.GetirId(ogrenci.getBolum_id())) {
                    obolum = bolum;
                }
                System.out.println("No : " + ogrenci.getId() + " / Ad : " + ogrenci.getAd() + " / Soyad : " + ogrenci.getSoyad() + " / Bölüm : " + obolum.getAd());
            });
        }
        Typenotlar not = new Typenotlar();
        not.setOgrenci_id(VeriGirInt("öğrenci no"));

        TypeOgrenci ogrenci = new TypeOgrenci();
        TypeBolum ogrBolum = new TypeBolum();
        TypeDersProgrami ogrDersProgrami = new TypeDersProgrami();
        ConDersProgrami conDersProgrami = new ConDersProgrami();
        ConDers conDers = new ConDers();
        for (TypeOgrenci to : conOgrenci.GetirId(not.getOgrenci_id())) {
            ogrenci = to;
        }
        for (TypeBolum tb : conBolum.GetirId(ogrenci.getBolum_id())) {
            ogrBolum = tb;
        }
        for (TypeDersProgrami tdp : conDersProgrami.GetirId(ogrBolum.getDersProgrami_id())) {
            ogrDersProgrami = tdp;
        }
        System.out.println("===== DERSLER =====");
        for (TypeDers ders : conDers.GetirId(ogrDersProgrami.getPazartesi())) {
            System.out.println("Ders No : " + ders.getId() + " / Ad : " + ders.getAd() + "");
        }
        for (TypeDers ders : conDers.GetirId(ogrDersProgrami.getSali())) {
            System.out.println("Ders No : " + ders.getId() + " / Ad : " + ders.getAd() + "");
        }
        for (TypeDers ders : conDers.GetirId(ogrDersProgrami.getCarsamba())) {
            System.out.println("Ders No : " + ders.getId() + " / Ad : " + ders.getAd() + "");
        }
        for (TypeDers ders : conDers.GetirId(ogrDersProgrami.getPersembe())) {
            System.out.println("Ders No : " + ders.getId() + " / Ad : " + ders.getAd() + "");
        }
        for (TypeDers ders : conDers.GetirId(ogrDersProgrami.getCuma())) {
            System.out.println("Ders No : " + ders.getId() + " / Ad : " + ders.getAd() + "");
        }

        not.setDers_id(VeriGirInt("ders no"));

        not.setPuan(VeriGirInt("not"));

        Connotlar connotlar = new Connotlar();
        for (Typenotlar notl : connotlar.Listele()) {
            System.out.println(notl.toString());
        }
        if (connotlar.Ekle(not)) {
            System.out.println("NOT EKLENDİ");
        } else {
            System.err.println("İŞLEM BAŞARISIZ !!!");
        }
        OgretimUyesiIslemler();

    }

    public static void OgrenciListele() {
        Baslik("öğrenci listesi");
        ConOgrenci conOgrenci = new ConOgrenci();
        ConBolum conBolum = new ConBolum();
        for (TypeOgrenci ogrenci : conOgrenci.Listele()) {
            TypeBolum obolum = new TypeBolum();
            for (TypeBolum bolum : conBolum.GetirId(ogrenci.getBolum_id())) {
                obolum = bolum;
            }
            System.out.println("No : " + ogrenci.getId() + " / Ad : " + ogrenci.getAd() + " / Soyad : " + ogrenci.getSoyad() + " / Bölüm : " + obolum.getAd());
        }
    }

    public static TypeDers DersGetir(int id) {
        TypeDers ders = new TypeDers();
        ConDers conDers = new ConDers();
        for (TypeDers td : conDers.GetirId(id)) {
            ders = td;
        }
        return ders;
    }

    public static void DersProgramiListele() {
        Baslik("ders programi listesi");
        ConDersProgrami conDersProgrami = new ConDersProgrami();
        ConDers conDers = new ConDers();
        for (TypeDersProgrami dersProgrami : conDersProgrami.Listele()) {
            System.out.println("===================\n" + "Ad : " + dersProgrami.getAd() + "\n"
                    + "Pazartesi : " + DersGetir(dersProgrami.getPazartesi()).getAd() + "\n"
                    + "Salı : " + DersGetir(dersProgrami.getPazartesi()).getAd() + "\n"
                    + "Çarşamba : " + DersGetir(dersProgrami.getPazartesi()).getAd() + "\n"
                    + "Perşembe : " + DersGetir(dersProgrami.getPazartesi()).getAd() + "\n"
                    + "Cuma : " + DersGetir(dersProgrami.getPazartesi()).getAd() + "\n"
            );
        }
        OgretimUyesiIslemler();
    }

    public static void OgrenciIslemler() {

        int ogrNo = VeriGirInt("öğrenci no");
        ConOgrenci conOgrenci = new ConOgrenci();
        if (conOgrenci.GetirId(ogrNo) == null) {
            System.err.println("Öğrenci No yanlış !!!");
            OgrenciIslemler();
        }

        Baslik("öğrenci işlemler");
        SecenekEkle(1, "not bilgisi");
        SecenekEkle(2, "kişisel bilgiler");
        SecenekEkle(3, "ana menüye dön");
        int secim;
        System.out.print("Seçiniz : ");
        Scanner oku = new Scanner(System.in);
        secim = oku.nextInt();

        switch (secim) {
            case 1://not gir
                NotBilgisi(ogrNo);
                break;
            case 2://kişisel bilgiler
                Bilgiler(ogrNo);
                break;
            case 3://bilgiler
                MainMenu();
                break;
            default:
                System.out.println("Hatalı seçim yaptınız!!! Tekrar deneyin");
                OgrenciIslemler();
                break;

        }
    }

    public static void NotBilgisi(int no) {
        Connotlar connotlar = new Connotlar();
        for (Typenotlar t : connotlar.GetirOgrenciId(no)) {
            TypeDers ders = new TypeDers();
            ConDers conDers = new ConDers();
            for (TypeDers td : conDers.GetirId(t.getDers_id())) {
                ders = td;
            }
            System.out.println("Ders : " + ders.getAd() + "\nNot : " + t.getPuan());
        }
    }

    public static void Bilgiler(int no) {
        TypeOgrenci ogrenci = new TypeOgrenci();
        ConOgrenci conOgrenci = new ConOgrenci();
        for (TypeOgrenci to : conOgrenci.GetirId(no)) {
            ogrenci = to;
        }
        TypeBolum bolum = new TypeBolum();
        ConBolum conBolum = new ConBolum();
        for (TypeBolum tb : conBolum.GetirId(ogrenci.getBolum_id())) {
            bolum = tb;
        }
        System.out.println("Öğrenci No : " + ogrenci.getId() + "\n"
                + "Tc No\t: " + ogrenci.getTcno() + "\n"
                + "Ad\t: " + ogrenci.getAd() + "\n"
                + "Soyad\t: " + ogrenci.getSoyad() + "\n"
                + "Yaş\t: " + ogrenci.getYas() + "\n"
                + "Ana Adı\t: " + ogrenci.getAna_adi() + "\n"
                + "Baba Adı : " + ogrenci.getBaba_adi() + "\n"
                + "Uyruk\t: " + ogrenci.getUyruk() + "\n"
                + "Bölüm\t: " + bolum.getAd() + "\n"
        );
    }
}
