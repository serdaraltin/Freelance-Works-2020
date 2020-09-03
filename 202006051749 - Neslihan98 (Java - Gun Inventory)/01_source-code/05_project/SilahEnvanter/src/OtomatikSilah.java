
public class OtomatikSilah extends Silah {

    private int sarjorAdedi;
    private Sarjor mevcutSarjor;
    private int mermiAtisMiktari;
    private boolean seriAtma;

    public boolean Doldur() {
        if (sarjorAdedi > 0) {
            mevcutSarjor.SarjorDoldur();
            sarjorAdedi--;
            System.out.println("Sarjor doldu.");
            return true;
        }
        System.out.println("Sarjor yok!!!");
        return false;
    }

    public boolean AtesEt(int hedefMenzil) {
        if (mevcutSarjor.getAnlikMermiSayisi() == 0) {
            System.out.println("Yeni sarjore geciliyor...");
            Doldur();
        }
        if (super.getMenzil() >= hedefMenzil) {
            if (seriAtma) {
                while (mevcutSarjor.MermiAtesle(mermiAtisMiktari)) {
                    System.out.println("Seri atesleme yapiliyor. Kalan mermi [" + mevcutSarjor.getAnlikMermiSayisi() + "]");
                }
                System.out.println("Hedev vuruldu.");
                return true;
            } else {
                if (mevcutSarjor.MermiAtesle(1)) {
                    System.out.println("Tekli atesleme yapiliyor. Kalan mermi [" + mevcutSarjor.getAnlikMermiSayisi() + "]");
                    System.out.println("Hedev vuruldu.");
                    return true;
                }
            }
        } else {
            System.out.println("Hedef menzilde degil!!!");
            return false;
        }
        return false;
    }

    public OtomatikSilah(String marka, int menzil, int sarjorAdedi, int mermiKapasitesi, boolean seri, int mermiAM) {
        super.setMarka(marka);
        super.setMenzil(menzil);
        this.sarjorAdedi = sarjorAdedi;
        this.mevcutSarjor = new Sarjor(mermiKapasitesi);
        this.seriAtma = seri;
        this.mermiAtisMiktari = mermiAM;
    }

    @Override
    public String toString() {
        String mod = "Tekli";
        if (seriAtma) {
            mod = "Seri";
        }
        return "Tur\t: Otomatik Silah"
                + "\nMarka\t: " + super.getMarka()
                + "\nMenzil\t: " + super.getMenzil() + " mt"
                + "\nKapasite: " + mevcutSarjor.getMermiKapasitesi() + " mermi"
                + "\nMod\t: " + mod
                + "\nAtis\t: Seri modda " + mermiAtisMiktari + " mermi"
                + "\nSarjor\t: " + sarjorAdedi + " tane";

    }

    public int getSarjorAdedi() {
        return sarjorAdedi;
    }

    public void setSarjorAdedi(int sarjorAdedi) {
        this.sarjorAdedi = sarjorAdedi;
    }

    public boolean isSeriAtma() {
        return seriAtma;
    }

    public void setSeriAtma(boolean seriAtma) {
        if(seriAtma){
            System.out.println("Seri atim moduna gecildi.");
        }else{
            System.out.println("Tekli atim moduna gecildi.");
        }
        this.seriAtma = seriAtma;
    }
    
    

}
