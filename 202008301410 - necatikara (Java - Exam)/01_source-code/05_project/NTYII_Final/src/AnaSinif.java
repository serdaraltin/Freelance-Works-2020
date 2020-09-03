
import java.util.ArrayList;
import java.util.Scanner;

public class AnaSinif {
	//zar değerlerinin sağlandığı liste
    static ArrayList<Integer> zarlar = new ArrayList<Integer>();

    public static void main(String[] args) {
        Menu();
    }
    //ana menü
    public static void Menu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("1) Uygulama 1 (Kok Alma,Kup Alma, Kuvvet Alma...)");
        System.out.println("2) Uygulama 2 (Zar Atma)");
        System.out.println("3) Uygulama 3 (Dongu islemi)");
        System.out.println("4) Uygulama 4 (Tahmin Oyunu)");
        System.out.println("5) Uygulama 5 (Rastgele Sayi)");
        System.out.println("0) Cikis");
        System.out.print("Seciminiz : ");
        int secim = scanner.nextInt();
        System.out.println();
        switch (secim) {
            case 0:
           		//programdan çıkış esnasında zar sayısının kontrolü ve dosyaya yazdırılması
                if (zarlar.size() > 0) {
                    System.out.print("Zarlar yazilsin mi[E/H]: ");
                    String cevap = scanner.next();
                    if(cevap.equals("E") || cevap.equals("e")){
                        Uygulama_2 uygulama_2 = new Uygulama_2();
                        uygulama_2.ZarYaz(zarlar);
                    }
                }
                System.exit(0);
                break;
            case 1:
                Uygulama1();
                break;
            case 2:
                Uygulama2();
                break;
            case 3:
                Uygulama3();
                break;
            case 4:
                Uygulama4();
                break;
            case 5:
                Uygulama5();
                break;
            default:
                System.out.println("Hatali bir secim yaptiniz !");
                break;
        }
        System.out.println();
        Menu();
    }	
    //uygulama 1 çözümleri
    private static void Uygulama1() {
    	//ilgili sınıftan nesne üretilmesi
        Uygulama_1 uygulama_1 = new Uygulama_1();
        Scanner scanner = new Scanner(System.in);

        System.out.println("1) Kok Alma");
        System.out.println("2) Kup Alma");
        System.out.println("3) Kuvvet Alma");
        System.out.println("4) Ortalama Alma");
        System.out.println("5) Faktoriyel Alma");
        System.out.println("0) Ana Menu");
        System.out.print("Seciminiz : ");
        int secim = scanner.nextInt();
        System.out.println();
        switch (secim) {
            case 0:
                return;
            case 1:
                uygulama_1.KokAlma();
                break;
            case 2:
                uygulama_1.KupAlma();
                break;
            case 3:
                uygulama_1.KuvvetAlma();
                break;
            case 4:
                uygulama_1.OrtalamaAlma();
                break;
            case 5:
                uygulama_1.FaktoriyelALma();
                break;
            default:
                System.out.println("Hatali bir secim yaptiniz !");
                break;
        }
        System.out.println();
        Uygulama1();
    }
    //uygulama 2 çözümleri
    private static void Uygulama2() {
    	//ilgili sınıftan nesne üretilmesi
        Uygulama_2 uygulama_2 = new Uygulama_2();
        Scanner scanner = new Scanner(System.in);

        System.out.println("1) Zar At");
        System.out.println("0) Ana Menu");
        System.out.print("Seciminiz : ");
        int secim = scanner.nextInt();
        System.out.println();
        switch (secim) {
            case 0:
                return;
            case 1:
                uygulama_2.ZarAtma(zarlar);
                break;
            default:
                System.out.println("Hatali bir secim yaptiniz !");
                break;
        }
        System.out.println();
        Uygulama2();
    }
    //uygulama 3 çözümü
    private static void Uygulama3() {
    	//ilgili sınıftan nesne üretilmesi
        Uygulama_3 uygulama_3 = new Uygulama_3();
        uygulama_3.Ucgen();
        return;
    }
    //uygulama 4 çözümü
    private static void Uygulama4() {
    	//ilgili sınıftan nesne üretilmesi
        Uygulama_4 uygulama_4 = new Uygulama_4();
        uygulama_4.TahminOyun();
        return;
    }
    //uygulama 5 çözümü
    private static void Uygulama5() {
    	//ilgili sınıftan nesne üretilmesi
        Uygulama_5 uygulama_5 = new Uygulama_5();
        uygulama_5.RastgeleSayilar();
        return;
    }

}
