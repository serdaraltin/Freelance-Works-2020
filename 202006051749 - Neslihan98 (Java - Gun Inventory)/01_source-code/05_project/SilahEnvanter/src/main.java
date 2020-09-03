
public class main {

    public static void main(String[] args) {

        Tabanca tabanca1 = new Tabanca("Glock", 500, 2);
        System.out.println(tabanca1 + "\n");
        tabanca1.AtesEt(300);
        tabanca1.Doldur();
        tabanca1.AtesEt(300);
        tabanca1.Doldur();
        tabanca1.AtesEt(700);

        System.out.println();

        OtomatikSilah otomatikSilah1 = new OtomatikSilah("M416", 1000, 5, 25, false, 3);
        System.out.println(otomatikSilah1 + "\n");
        otomatikSilah1.AtesEt(700);
        otomatikSilah1.setSeriAtma(true);
        otomatikSilah1.AtesEt(500);
        otomatikSilah1.Doldur();
    }
}
