
import java.util.ArrayList;
import java.util.Scanner;


public class Test {
    static ArrayList<Oyuncak> oyuncakListesi = new ArrayList<Oyuncak>();
    
    public static void OyuncakEkle(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Bir oyuncak seçiniz >>>");
        System.out.println("1-Araba");
        System.out.println("2-Peluş Ayı");
        System.out.println("3-Çıkış");
        System.out.print("Seçim : ");
        int secim = scanner.nextInt();
        switch(secim){
            case 1:
                System.out.print("Araba boyutu : ");
                int boyut = scanner.nextInt();
                Araba araba = new Araba(boyut, 1);
                oyuncakListesi.add(araba);
                OyuncakEkle();
                break;
            case 2:
                System.out.print("Peluş Ayı kumaş tipi : ");
                String kumasTipi = scanner.next();
                PelusAyi pelusAyi = new PelusAyi(kumasTipi, 2);
                oyuncakListesi.add(pelusAyi);
                System.out.println(pelusAyi.getKumasTipi());
                OyuncakEkle();
                break;
            case 3:
                return;
            default:
                System.out.println("Hatalı bir seçim yaptınız!");
                OyuncakEkle();
                break;
        }
    }
    public static void main(String[] args) {
        OyuncakEkle();
       
        int arabaAdet=0,pelusAyiAdet=0;
        for (Oyuncak oyuncak : oyuncakListesi) {
            if(oyuncak.getSecim() == 1)
                arabaAdet++;
            else if(oyuncak.getSecim() == 2)
                pelusAyiAdet++;
        }
        System.out.println("Listede "+arabaAdet+" adet Araba ve "+pelusAyiAdet+" adet Peluş Ayı oyuncağı vardır.");
    }
}
