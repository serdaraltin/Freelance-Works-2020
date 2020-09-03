package Main;

import Controllers.ControllerMusteri;
import Controllers.ControllerUrun;
import Controllers.ControllerMusteriSepeti;
import Types.TypeMusteri;
import Types.TypeMusteriSepeti;
import Types.TypeUrun;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Run {

    static ControllerMusteri conMusteri = new ControllerMusteri();
    static ControllerUrun conUrun = new ControllerUrun();
    static ControllerMusteriSepeti conMusteriSepeti = new ControllerMusteriSepeti();

    static ArrayList<TypeMusteri> musteriler = new ArrayList<TypeMusteri>();
    static ArrayList<TypeUrun> urunler = new ArrayList<TypeUrun>();
    static ArrayList<TypeMusteriSepeti> sepetler = new ArrayList<TypeMusteriSepeti>();

    static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        
        Menu();

    }

    public static void Menu() {
        System.out.println("--------------------------------");
        System.out.println("1) Urun Listele");
        System.out.println("2) Urun Ekle");
        System.out.println("3) Urun Guncelle");
        System.out.println("4) Urun Sil");
        System.out.println("5) Urun Ara");

        System.out.println("6) Musteri Listele");
        System.out.println("7) Musteri Ekle");
        System.out.println("8) Musteri Guncelle");
        System.out.println("9) Musteri Sil");
        System.out.println("10) Musteri Ara");

        System.out.println("11) Sepet Listele");
        System.out.println("12) Sepet Ekle");
        System.out.println("13) Sepet Guncelle");
        System.out.println("14) Sepet Sil");
        System.out.println("15) Sepet Ara");

        System.out.println("16) Musteri Sepeti");

        System.out.println("0) Cikis");
        System.out.println("--------------------------------");

        System.out.print("Secim : ");
        int secim = scn.nextInt();
        System.out.println();
        switch (secim) {
            case 0:
                System.exit(0);
                break;
            case 1:
                conUrun.Listele(urunler);
                break;
            case 2:
                UrunEkle();
                break;
            case 3:
                UrunGuncelle();
                break;
            case 4:
                UrunSil();
                break;
            case 5:
                UrunAra();
                break;
            case 6:
                conMusteri.Listele(musteriler);
                break;
            case 7:
                MusteriEkle();
                break;
            case 8:
                MusteriGuncelle();
                break;
            case 9:
                MusteriSil();
                break;
            case 10:
                MusteriAra();
                break;
            case 11:
                if (sepetler.isEmpty()) {
                    System.out.println("Sepet tamamen boş!!!");
                    break;
                }
                System.out.println("MusteriKodu\tUrunKodu\tislemMiktari\tislemTutari\tKdvTutari\t\tToplamTutar");
                for (TypeMusteriSepeti typeMusteriSepeti : sepetler) {
                    SepetYazdir(typeMusteriSepeti);
                }
                break;
            case 12:
                SepetEkle();
                break;
            case 13:
                SepetGuncelle();
                break;
            case 14:
                SepetSil();
                break;
            case 15:
                SepetAra();
                break;
            case 16:
                MusteriSepeti();
                break;
        }
        EnterBas();
        Menu();

    }

    public static void EnterBas() {
        System.out.print("\nDevam etmek icin \"ENTER\" basin...");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void UrunEkle() {
        TypeUrun urun = new TypeUrun();
        System.out.print("Urun Kodu : ");
        urun.setUrunkodu(scn.next());
        System.out.print("Urun Adi : ");
        urun.setAdi(scn.next());
        System.out.print("Birim Fiyati : ");
        urun.setBirimFiyati(scn.nextInt());
        System.out.print("Kdv Orani : ");
        urun.setKdvOrani(scn.nextInt());
        if (conUrun.Ekle(urunler, urun)) {
            System.out.println("Urun eklendi.");
        }
    }

    private static void UrunGuncelle() {
        TypeUrun urun = new TypeUrun();
        System.out.print("Urun Kodu : ");
        urun.setUrunkodu(scn.next());
        System.out.print("Urun Adi : ");
        urun.setAdi(scn.next());
        System.out.print("Birim Fiyati : ");
        urun.setBirimFiyati(scn.nextInt());
        System.out.print("Kdv Orani : ");
        urun.setKdvOrani(scn.nextInt());
        if (conUrun.Guncelle(urunler, urun)) {
            System.out.println("Ürün güncellendi");
        } else {
            System.out.println("Ürün bulunamadı !!!");
        }
    }

    private static void UrunSil() {
        TypeUrun urun = new TypeUrun();
        System.out.print("Urun Kodu : ");
        urun.setUrunkodu(scn.next());
        if (conUrun.Sil(urunler, urun)) {
            System.out.println("Ürün silindi");
        } else {
            System.out.println("Ürün bulunamadı !!!");
        }
    }

    private static void UrunAra() {
        TypeUrun urun = new TypeUrun();
        System.out.print("Urun Kodu : ");
        urun.setUrunkodu(scn.next());

        TypeUrun bulunan = conUrun.Ara(urunler, urun);

        if (bulunan == null) {
            System.out.println("Ürün bulunamadı !!!");
        } else {
            conUrun.Yazdir(bulunan);
        }

    }

    private static void MusteriEkle() {
        TypeMusteri musteri = new TypeMusteri();
        System.out.print("Musteri Kodu : ");
        musteri.setMusterino(scn.next());
        System.out.print("Adi : ");
        musteri.setAd(scn.next());
        System.out.print("Soyadi : ");
        musteri.setSoyad(scn.next());

        if (conMusteri.Ekle(musteriler, musteri)) {
            System.out.println("Musteri eklendi.");
        }
    }

    private static void MusteriGuncelle() {
        TypeMusteri musteri = new TypeMusteri();
        System.out.print("Musteri Kodu : ");
        musteri.setMusterino(scn.next());
        System.out.print("Adi : ");
        musteri.setAd(scn.next());
        System.out.print("Soyadi : ");
        musteri.setSoyad(scn.next());

        if (conMusteri.Guncelle(musteriler, musteri)) {
            System.out.println("Musteri güncellendi");
        } else {
            System.out.println("Musteri bulunamadı !!!");
        }
    }

    private static void MusteriSil() {
        TypeMusteri musteri = new TypeMusteri();
        System.out.print("Musteri Kodu : ");
        musteri.setMusterino(scn.next());
        if (conMusteri.Sil(musteriler, musteri)) {
            System.out.println("Musteri silindi");
        } else {
            System.out.println("Musteri bulunamadı !!!");
        }
    }

    private static void MusteriAra() {
        TypeMusteri musteri = new TypeMusteri();
        System.out.print("Musteri Kodu : ");
        musteri.setMusterino(scn.next());

        TypeMusteri bulunan = conMusteri.Ara(musteriler, musteri);

        if (bulunan == null) {
            System.out.println("Musteri bulunamadı !!!");
        } else {
            conMusteri.Yazdir(bulunan);
        }
    }

    private static void SepetEkle() {
        TypeMusteriSepeti musteriSepeti = new TypeMusteriSepeti();
        System.out.print("Musteri Kodu : ");
        musteriSepeti.setMusteriNo(scn.next());
        System.out.print("Urun Kodu : ");
        musteriSepeti.setUrunKodu(scn.next());
        System.out.print("Islem Miktar : ");
        musteriSepeti.setIslemMiktari(scn.nextInt());

        TypeUrun urun = conUrun.Ara(urunler, new TypeUrun(musteriSepeti.getUrunKodu(), null, 0, 0));
       
        musteriSepeti.setIslemTutari(IslemTutar(musteriSepeti.getIslemMiktari(), urun.getBirimFiyati()));
        musteriSepeti.setKdvTutari(KdvTutar(musteriSepeti.getIslemTutari(), urun.getKdvOrani()));
        musteriSepeti.setToplamTutar((int)(ToplamTutar(musteriSepeti.getIslemTutari(), musteriSepeti.getKdvTutari())));

        if (conMusteriSepeti.Ekle(sepetler, musteriSepeti)) {
            System.out.println("Sepet eklendi.");
        }
    }

    private static void SepetGuncelle() {
        TypeMusteriSepeti musteriSepeti = new TypeMusteriSepeti();
        System.out.print("Musteri Kodu : ");
        musteriSepeti.setMusteriNo(scn.next());
        System.out.print("Urun Kodu : ");
        musteriSepeti.setUrunKodu(scn.next());
        System.out.print("Islem Miktar : ");
        musteriSepeti.setIslemMiktari(scn.nextInt());

        TypeUrun urun = conUrun.Ara(urunler, new TypeUrun(musteriSepeti.getUrunKodu(), null, 0, 0));

        musteriSepeti.setIslemTutari(IslemTutar(musteriSepeti.getIslemMiktari(), urun.getBirimFiyati()));
        musteriSepeti.setKdvTutari(KdvTutar(musteriSepeti.getIslemTutari(), urun.getKdvOrani()));
        musteriSepeti.setToplamTutar((int)ToplamTutar(musteriSepeti.getIslemTutari(), musteriSepeti.getKdvTutari()));

        if (conMusteriSepeti.Guncelle(sepetler, musteriSepeti)) {
            System.out.println("Sepet güncellendi");
        } else {
            System.out.println("Sepet bulunamadı !!!");
        }
    }

    private static void SepetSil() {
        TypeMusteriSepeti musteriSepeti = new TypeMusteriSepeti();
        System.out.print("Musteri Kodu : ");
        musteriSepeti.setMusteriNo(scn.next());
        System.out.print("Urun Kodu : ");
        musteriSepeti.setUrunKodu(scn.next());

        if (conMusteriSepeti.Sil(sepetler, musteriSepeti)) {
            System.out.println("Sepetteki eleman silindi");
        } else {
            System.out.println("Sepetten silinecek eleman bulunamadı !!!");
        }
    }

    private static void SepetAra() {
        TypeMusteriSepeti musteriSepeti = new TypeMusteriSepeti();
        System.out.print("Musteri Kodu : ");
        musteriSepeti.setMusteriNo(scn.next());
        System.out.print("Urun Kodu : ");
        musteriSepeti.setUrunKodu(scn.next());

        TypeMusteriSepeti bulunan = conMusteriSepeti.Ara(sepetler, musteriSepeti);

        if (bulunan == null) {
            System.out.println("Sepet elemani bulunamadı !!!");
        } else {
            SepetYazdir(bulunan);
        }
    }

    public static void SepetYazdir(TypeMusteriSepeti musteriSepeti) {
        TypeUrun urun = conUrun.Ara(urunler, new TypeUrun(musteriSepeti.getUrunKodu(), null, 0, 0));
        TypeMusteri musteri = conMusteri.Ara(musteriler, new TypeMusteri(musteriSepeti.getMusteriNo(), null, null));

        
        System.out.println(musteri.getMusterino() + "\t\t" + urun.getUrunkodu() + "\t\t"
                +musteriSepeti.getIslemMiktari()+"\t\t"
                + "(" + musteriSepeti.getIslemMiktari() + "*" + urun.getBirimFiyati() + ") = " + musteriSepeti.getIslemTutari() + "\t"
                + musteriSepeti.getIslemTutari() + " * (" + urun.getKdvOrani() + "/100)=" + (int)musteriSepeti.getKdvTutari() + "  \t"
                + "(" + musteriSepeti.getIslemTutari() + "+" + urun.getKdvOrani() + ") = " + musteriSepeti.getToplamTutar());
    }

    public static int IslemTutar(int islemMiktar, int UrunBirimFiyati) {
        return islemMiktar * UrunBirimFiyati;
    }

    public static float KdvTutar(int islemTutari, float KdvOrani) {
        return islemTutari*(KdvOrani/100);
    }

    public static float ToplamTutar(float islemTutari, float KdvTutari) {
        return islemTutari + KdvTutari;
    }

    private static void MusteriSepeti() {
        if (sepetler.isEmpty()) {
            System.out.println("Herhangi bir musteriye ait sepet yok!!!");
            return;
        }

        System.out.print("Musteri Kodu : ");
        String musteriNo = scn.next();
        System.out.println("MusteriKodu\tUrunKodu\tislemMiktari\tKdvTutari\tToplamTutar");

        for (TypeMusteriSepeti typeMusteriSepeti : sepetler) {
            if (typeMusteriSepeti.getMusteriNo().equals(musteriNo)) {
                SepetYazdir(typeMusteriSepeti);
            }
        }
        return;
    }
}
