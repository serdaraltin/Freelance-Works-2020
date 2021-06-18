
public class Tabanca extends Silah {

    private int sarjorAdedi;
    private Sarjor mevcutSarjor;

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
        if (super.getMenzil() >= hedefMenzil && mevcutSarjor.MermiAtesle(1)) {
            System.out.println("Ates edildi ve hedef vuruldu");
            return true;
        } else if (!mevcutSarjor.MermiAtesle(1)) {
            System.out.println("Sarjor bos!!!");
            return false;
        } else if (super.getMenzil() < hedefMenzil) {
            System.out.println("Hedef menzil disinda!!!");
            return false;
        }
        return false;
    }

    public Tabanca(String marka, int menzil, int sarjorAdedi) {
        super.setMarka(marka);
        super.setMenzil(menzil);
        this.sarjorAdedi = sarjorAdedi;
        this.mevcutSarjor = new Sarjor(1);
        Doldur();
    }

    @Override
    public String toString() {
        return "Tur\t: Tabanca"
                + "\nMarka\t: " + super.getMarka()
                + "\nMenzil\t: " + super.getMenzil() + " mt"
                + "\nKapasite: " + mevcutSarjor.getMermiKapasitesi() + " mermi";
    }

}
