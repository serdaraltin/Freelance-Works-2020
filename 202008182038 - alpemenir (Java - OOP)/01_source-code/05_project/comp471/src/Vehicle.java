
public abstract class Vehicle {

    private int Weight;
    private double Height;
    private int Fee = 5;

    public int GetWeight() {
        return Weight;
    }

    public void SetWeight(int Weight) {
        this.Weight = Weight;
    }

    public double GetHeight() {
        return Height;
    }

    public void SetHeight(double Height) {
        this.Height = Height;
    }

    public double RegistrationFee() {
        if (this instanceof Car) {
            return Fee * 1;
        }
        if (this instanceof Truck) {
            return Fee * 2;
        }
        return 0;
    }

    public Vehicle() {
    }

    
    
    public Vehicle(int Weight, double Height) {
        this.Weight = Weight;
        this.Height = Height;
    }

    @Override
    public String toString() {
        return "Vehicle{" + "Weight=" + Weight + ", Height=" + Height + ", Fee=" + Fee + '}';
    }

}
