
public class Uygulama_3 {
    
    //* karakterlerinden üçren oluşturan method
    public void Ucgen() {
        //ilgili değerlerin tanımlanması
        int sayi = 1;
        boolean ters = false;
        //sayı değeri 0 olana dek dönen döngü
        while (sayi > 0) {
            //sayı değeri kadar ekrana * karakteri yazdırma
            switch (sayi) {
                case 1:
                    System.out.println("*");
                    break;
                case 2:
                    System.out.println("**");
                    break;
                case 3:
                    System.out.println("***");
                    break;
                case 4:
                    System.out.println("****");
                    break;
                case 5:
                    System.out.println("*****");
                    break;
            }
            //sayı değeri 5 olduğunda ters kontrolü değeri true yapılması
            if(sayi == 5)
                ters = true;
            //ters değeri true ise sayı değerinin 1 eksiltilmesi
            if(ters)
                sayi--;
            //ters değeri false ise sayı değerinin 1 arttırılması
            else
                sayi++;
        }

    }
}
