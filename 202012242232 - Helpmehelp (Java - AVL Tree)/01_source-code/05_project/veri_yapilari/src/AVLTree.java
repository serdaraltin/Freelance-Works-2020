
import java.util.Scanner;

class Dugum {

    String sozcuk;
    int yukseklik;
    Dugum left, right;

    Dugum(String deger) {
        sozcuk = deger;
        yukseklik = 1;
    }
}

class AVLTree {

    Dugum kok;

    int yukseklik(Dugum N) {
        if (N == null) {
            return 0;
        }
        return N.yukseklik;
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    String buyukOlan(String a, String b) {
        int compare = a.compareTo(b);

        if (compare > 0) {
            return b;
        } else if (compare < 0) {
            return a;
        } else {
            return "";
        }
    }
     
    Dugum enKucukDeger(Dugum dugum) {
        Dugum current = dugum;

        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    Dugum sagaKaydir(Dugum y) {
        Dugum x = y.left;
        Dugum T2 = x.right;

        x.right = y;
        y.left = T2;

        y.yukseklik = max(yukseklik(y.left), yukseklik(y.right)) + 1;
        x.yukseklik = max(yukseklik(x.left), yukseklik(x.right)) + 1;

        return x;
    }

    Dugum solaKaydir(Dugum x) {
        Dugum y = x.right;
        Dugum T2 = y.left;

        y.left = x;
        x.right = T2;

        x.yukseklik = max(yukseklik(x.left), yukseklik(x.right)) + 1;
        y.yukseklik = max(yukseklik(y.left), yukseklik(y.right)) + 1;

        return y;
    }

    int dengeDurumu(Dugum N) {
        if (N == null) {
            return 0;
        }
        return yukseklik(N.left) - yukseklik(N.right);
    }

    Dugum ekle(Dugum dugum, String sozcuk) {

        if (dugum == null) {
            return (new Dugum(sozcuk));
        }

        if (buyukOlan(dugum.sozcuk, sozcuk).equals(dugum.sozcuk)) {
            dugum.left = ekle(dugum.left, sozcuk);
        } else if (buyukOlan(dugum.sozcuk, sozcuk).equals(sozcuk)) {
            dugum.right = ekle(dugum.right, sozcuk);
        } else {
            return dugum;
        }

        dugum.yukseklik = 1 + max(yukseklik(dugum.left), yukseklik(dugum.right));

        int denge = dengeDurumu(dugum);

        if (denge > 1 && buyukOlan(dugum.left.sozcuk, sozcuk).equals(dugum.left.sozcuk)) {
            return sagaKaydir(dugum);
        }

        if (denge < -1 && buyukOlan(dugum.right.sozcuk, sozcuk).equals(dugum.right.sozcuk)) {
            return solaKaydir(dugum);
        }

        if (denge > 1 && buyukOlan(dugum.left.sozcuk, sozcuk).equals(sozcuk)) {
            dugum.left = solaKaydir(dugum.left);
            return sagaKaydir(dugum);
        }

        if (denge < -1 && buyukOlan(dugum.right.sozcuk, sozcuk).equals(dugum.right.sozcuk)) {
            dugum.right = sagaKaydir(dugum.right);
            return solaKaydir(dugum);
        }

        return dugum;
    }

    Dugum sil(Dugum kok, String sozcuk) {

        if (kok == null) {
            return kok;
        }

        if (buyukOlan(kok.sozcuk, sozcuk).equals(kok.sozcuk)) {
            kok.left = sil(kok.left, sozcuk);
        } else if (buyukOlan(kok.sozcuk, sozcuk).equals(sozcuk)) {
            kok.right = sil(kok.right, sozcuk);
        } else {

            if ((kok.left == null) || (kok.right == null)) {
                Dugum temp = null;
                if (temp == kok.left) {
                    temp = kok.right;
                } else {
                    temp = kok.left;
                }

                if (temp == null) {
                    temp = kok;
                    kok = null;
                } else {
                    kok = temp;
                }
            } else {

                Dugum temp = enKucukDeger(kok.right);

                kok.sozcuk = temp.sozcuk;

                kok.right = sil(kok.right, temp.sozcuk);
            }
        }

        if (kok == null) {
            return kok;
        }
        kok.yukseklik = max(yukseklik(kok.left), yukseklik(kok.right)) + 1;

        int denge = dengeDurumu(kok);

        if (denge > 1 && dengeDurumu(kok.left) >= 0) {
            return sagaKaydir(kok);
        }

        if (denge > 1 && dengeDurumu(kok.left) < 0) {
            kok.left = solaKaydir(kok.left);
            return sagaKaydir(kok);
        }

        if (denge < -1 && dengeDurumu(kok.right) <= 0) {
            return solaKaydir(kok);
        }

        if (denge < -1 && dengeDurumu(kok.right) > 0) {
            kok.right = sagaKaydir(kok.right);
            return solaKaydir(kok);
        }

        return kok;
    }

    Dugum ata(Dugum kok, String s1, String s2) {
        kok = sil(kok, s1);
        kok = ekle(kok, s2);
        return kok;
    }
    
    void siralaPreOrder(Dugum dugum) {
        if (dugum != null) {
            System.out.print(dugum.sozcuk + " ");
            siralaPreOrder(dugum.left);
            siralaPreOrder(dugum.right);
        }
    }

    public static void main(String[] args) {
        AVLTree agac = new AVLTree();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1) Ekle");
            System.out.println("2) Sil");
            System.out.println("3) Ata");
            System.out.println("0) Cik");
            int secim;
            System.out.print("\nSecim : ");
            secim = scanner.nextInt();

            String deger,deger2;
            switch (secim) {
                case 0:
                    System.out.println("Cikiliyor...");
                    System.exit(0);
                    break;
                case 1:
                    System.out.print("Deger : ");
                    deger = scanner.next();
                    agac.kok = agac.ekle(agac.kok, deger);
                    System.out.println();
                    agac.siralaPreOrder(agac.kok);
                    System.out.println("\n");
                    break;
                case 2:
                    System.out.print("Deger : ");
                    deger = scanner.next();
                    agac.kok = agac.sil(agac.kok, deger);
                    System.out.println();
                    agac.siralaPreOrder(agac.kok);
                    System.out.println("\n");
                    break;
                case 3:
                    System.out.print("Deger(1) : ");
                    deger = scanner.next();
                    System.out.print("Deger(2) : ");
                    deger2 = scanner.next();
                    agac.kok = agac.ata(agac.kok, deger,deger2);
                    System.out.println();
                    agac.siralaPreOrder(agac.kok);
                    System.out.println("\n");
                    break;
            }
        }
    }

}
