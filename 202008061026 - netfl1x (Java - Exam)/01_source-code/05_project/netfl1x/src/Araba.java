public class Araba extends Oyuncak{
    private int boyut;

    public Araba(int boyut, int secim) {
        super(secim);
        this.boyut = boyut;
    }

    public int getBoyut() {
        return boyut;
    }

    public void setBoyut(int boyut) {
        this.boyut = boyut;
    }

    @Override
    public String toString() {
        return "Araba{" + "boyut=" + boyut + '}';
    }
    
    
}
