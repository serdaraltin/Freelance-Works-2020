
public class Car extends Vehicle {

    private int kapi;

    public int getKapi() {
        return kapi;
    }

    public void setKapi(int kapi) {
        this.kapi = kapi;
    }

    @Override
    public String toString() {
        return "Tip\t: Car"
                + "\nPlaka\t: " + super.getPlaka()
                + "\nModel\t: " + super.getModel()
                + "\nMarka\t: " + super.getMarka()
                + "\nKapi\t: " + kapi + " Adet";
    }

    public Car(String plaka, String model, String marka, int kapi) {
        super(plaka, marka, model);
        this.kapi = kapi;
    }

}
