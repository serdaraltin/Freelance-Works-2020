/**
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author yazar adı ve mail adresi
*/

import java.util.Scanner;

public class Main {
    //dokümandaki örneğin program başlangıcında tanımlanması > değerler
    static int[] array = {5, 5, -1, 100, 2};
    //dokümandaki örneğin program başlangıcında tanımlanması > matris
    static int[][] matris = {
        {56, 12, 8, 90, 40},
        {87, 76, 99, 1, 32},
        {34, 43, 25, 78, 6},
        {39, 55, 65, 88, 3},
        {44, 75, 77, 14, 10},};

    //matris üzerindeki kenar değerlerini alarak bir dizi halinde geriye döndüren method
    public static int[] kenarAl() {
        int m = array[0];
        int n = array[1];
        int sayac = 0;
        int tempMatris[] = new int[(m * 2) + (n * 2) - 4];
        for (int j = 0; j < n; j++) {
            tempMatris[sayac++] = matris[0][j];
        }
        for (int i = 1; i < m - 1; i++) {
            tempMatris[sayac++] = matris[i][n - 1];
        }
        for (int j = n - 1; j >= 0; j--) {
            tempMatris[sayac++] = matris[m - 1][j];
        }
        for (int i = m - 2; i > 0; i--) {
            tempMatris[sayac++] = matris[i][0];
        }
        /*for (int i = 0; i < tempMatris.length; i++) {
            System.out.printf("%d ", tempMatris[i]);
        }*/
        return tempMatris;
    }

    //parametre olarak gelen diziyi sağa kaydıran method
    public static void sagaKaydir(int[] kenarDizi) {
        for (int i = 0; i < array[4]; i++) {
            int j, son;
            son = kenarDizi[kenarDizi.length - 1];
            for (j = kenarDizi.length - 1; j > 0; j--) {
                kenarDizi[j] = kenarDizi[j - 1];
            }
            kenarDizi[0] = son;
        }
    }

    //parametre olarak gelen diziyi sola kaydıran method
    public static void solaKaydir(int[] kenarDizi) {
        for (int i = 0; i < array[4]; i++) {
            int j, bas;
            bas = kenarDizi[0];

            for (j = 0; j < kenarDizi.length - 1; j++) {
                kenarDizi[j] = kenarDizi[j + 1];
            }

            kenarDizi[kenarDizi.length - 1] = bas;
        }
    }

    //parametre olarak gelen kenar değerleri ile matris üzerindeki kenar değerlerini değiştiren method
    public static void matrisDuzenle(int[] kenarDizi) {
        int m = array[0];
        int n = array[1];
        int sayac = 0;

        for (int j = 0; j < n; j++) {
            matris[0][j] = kenarDizi[sayac++];
        }
        for (int i = 1; i < m - 1; i++) {
            matris[i][n - 1] = kenarDizi[sayac++];
        }
        for (int j = n - 1; j >= 0; j--) {
            matris[m - 1][j] = kenarDizi[sayac++];
        }
        for (int i = m - 2; i > 0; i--) {
            matris[i][0] = kenarDizi[sayac++];
        }
    }

    //matrisi belirlenen yönde kaydıran method
    public static void matrisKaydir() { 
        int kenarDizi[] = kenarAl();

        if (array[2] == -1) {
            sagaKaydir(kenarDizi);
        } else if (array[2] == 1) {
            solaKaydir(kenarDizi);
        }
        matrisDuzenle(kenarDizi);
    }

    //değer bilgilerini yazdıran ve matrisin önceki ile sonraki halini yazdıran method
    public static void uygulamayiCalistir() {
        System.out.println("Degerler :");
        System.out.println("mxn  : " + array[0] + "x" + array[1]);
        System.out.println("Yon  : " + array[2]);
        System.out.println("Max  : " + array[3]);
        System.out.println("Adim : " + array[4]);
        System.out.println("\nMatris Onceki Durumu :");
        matrisYazdir();
       
        System.out.println("\nMatris Sonraki Durumu :");
        matrisKaydir();
        matrisYazdir();
    }

    //belirlenen değer ile 0 arasında rastgele değerler üreterek matrise dolduran method
    public static void matrisUret() {
        int max = array[3];
        for (int i = 0; i < array[0]; i++) {
            for (int j = 0; j < array[1]; j++) {
                matris[i][j] = (int) (Math.random() * (max));
            }
        }
    }

    //mevcut satir ve sutun değerlerine göre matrisi yazdıran method
    public static void matrisYazdir() {
        for (int i = 0; i < array[0]; i++) {
            for (int j = 0; j < array[1]; j++) {
                System.out.printf("%3d", matris[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    //main methodu
    public static void main(String[] args) {
        /*matris = new int[array[0]][array[1]];
        matrisUret();*/
        menu();
    }

    //program yönergelerinin bildirildiği ve seçimlerin yapıldığı method
    public static void menu() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("1. Uygulamayi calistir");
        System.out.println("2. Matris olustur");
        System.out.println("3. Direction");
        System.out.println("4. Step number");
        System.out.println("5. Exit\n");
        System.out.print("Secim : ");
        int secim = scanner.nextInt();
        if (secim != 1 && array[0] == 0) {
            System.out.println("\nOncelikle uygulama calistirilmalidir !\n");
            menu();
        }
        switch (secim) {
            case 1:
                System.out.println();
                uygulamayiCalistir();
                break;
            case 2:
                System.out.print(" \nVarsayilan matris degerleri ile mi (E/H) : ");
                String cevap = scanner.next();

                if (cevap.equals("H") || cevap.equals("h")) {
                    System.out.print("Matris satir sayisi : ");
                    array[0] = scanner.nextInt();
                    System.out.print("Matris sutun sayisi : ");
                    array[1] = scanner.nextInt();
                    System.out.print("Rastgele sayi maximum degeri : ");
                    array[3] = scanner.nextInt();
                }

                matris = new int[array[0]][array[1]];
                matrisUret();
                matrisYazdir();

                break;
            case 3:
                System.out.print("\nYon (saat yonu 1, tersi -1) : ");
                array[2] = scanner.nextInt();
                break;
            case 4:
                System.out.print("\nAdim degeri : ");
                array[4] = scanner.nextInt();
                break;
            case 5:
                System.err.println("\nProgramdan cikiliyor...");
                System.exit(0);
                break;
            default:
                System.out.println("\nHatali secim !\n");
                break;
        }
        System.out.println();
        menu();
    }
}
