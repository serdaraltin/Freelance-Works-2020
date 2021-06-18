
public class Vehicle implements Comparable<Vehicle> {

    private String plaka;
    private String marka;
    private String model;

    @Override
    public int compareTo(Vehicle t) {
        return this.plaka.compareTo(t.getPlaka());
    }

    public String getPlaka() {
        return plaka;
    }

    public void setPlaka(String plaka) {
        this.plaka = plaka;
    }

    public String getMarka() {
        return marka;
    }

    public void setMarka(String marka) {
        this.marka = marka;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public Vehicle(String plaka, String model, String marka) {
        this.plaka = plaka;
        this.marka = marka;
        this.model = model;
    }

}
