
import java.util.ArrayList;

class Inventory {

    private ArrayList<Car> cars = new ArrayList();
    private ArrayList<Motorbike> motorbikes = new ArrayList();

    void add(Car car) {
        cars.add(car);
    }

    void add(Motorbike mBike) {
        motorbikes.add(mBike);
    }

    public ArrayList<Car> getCars() {
        return cars;
    }

    public void setCars(ArrayList<Car> cars) {
        this.cars = cars;
    }

    public ArrayList<Motorbike> getMotorbikes() {
        return motorbikes;
    }

    public void setMotorbikes(ArrayList<Motorbike> motorbikes) {
        this.motorbikes = motorbikes;
    }

    public Inventory() {
    }

    @Override
    public String toString() {
        int totalPrice = 0;
        String output = "";
        for (Car car : cars) {
            output += car;
            totalPrice += car.getFinalPrice();
        }
        for (Motorbike motorbike : motorbikes) {
            output += motorbike;
            totalPrice += motorbike.getFinalPrice();
        }
        output += "TOTAL : " + (cars.size() + motorbikes.size()) + " Vehicles including ";
        int doub = 0;
        if (cars.size() > 0) {
            output += cars.size() + " Cars";
            doub++;
        }
        if (motorbikes.size() > 0) {
            if (doub > 0) {
                output += " and ";
            }
            output += motorbikes.size() + " Motorbikes";
        }
        output += " having a total price of " + totalPrice + " TL";
        return output;
    }

}
