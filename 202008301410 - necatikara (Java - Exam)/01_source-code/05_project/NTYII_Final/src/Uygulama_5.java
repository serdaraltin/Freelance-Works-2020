
import java.util.Random;
import java.util.Scanner;

public class Uygulama_5 {
    //adet değeri kadar belirlenen aralıkta rastgele sayı üreten method
    public void RastgeleSayilar() {
        //ilgili okuma sınıfından nesne üretilmesi
        Scanner scanner = new Scanner(System.in);
        //Random sınıfından nesne üretilmesi
        Random random = new Random();
        System.out.print("Kac adet sayi uretilecek: ");
        int adet = scanner.nextInt();
        System.out.print("Aralik baslangic: ");
        int baslangic = scanner.nextInt();
        System.out.print("Aralik bitis: ");
        int bitis = scanner.nextInt();
        System.out.println();
        //adet değeri kadar dönen döngü
        for (int i = 1; i <= adet; i++) {
            //başlangıç ve bitiş arasında rasgele sayı üreitilmesi
            int uretilen = random.nextInt(bitis-baslangic)+baslangic;
            System.out.println(i + ". uretilen sayi: " + uretilen);
        }
        return;
    }

}
