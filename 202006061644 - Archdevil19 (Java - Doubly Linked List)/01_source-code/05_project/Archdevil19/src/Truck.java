
public class Truck extends Vehicle {

    private int yukKapasite;

    public int getYukKapasite() {
        return yukKapasite;
    }

    public void setYukKapasite(int yukKapasite) {
        this.yukKapasite = yukKapasite;
    }

    @Override
    public String toString() {
        return "Tip\t: Truck"
                + "\nPlaka\t: " + super.getPlaka()
                + "\nModel\t: " + super.getModel()
                + "\nMarka\t: " + super.getMarka()
                + "\nKapasite: " + yukKapasite + " Ton";
    }

    public Truck(String plaka, String model, String marka, int yukKapasite) {
        super(plaka, marka, model);
        this.yukKapasite = yukKapasite;
    }

}
