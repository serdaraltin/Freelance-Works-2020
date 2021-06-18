
import java.util.ArrayList;

class Inventory {

    private ArrayList<Car> carList = new ArrayList();
    private ArrayList<Motorbike> motoList = new ArrayList();

    void add(Car car) {
        carList.add(car);
    }

    void add(Motorbike mBike) {
        motoList.add(mBike);
    }

    public ArrayList<Car> getCars() {
        return carList;
    }

    public void setCars(ArrayList<Car> carList) {
        this.carList = carList;
    }

    public ArrayList<Motorbike> getMotorbikes() {
        return motoList;
    }

    public void setMotorbikes(ArrayList<Motorbike> motoList) {
        this.motoList = motoList;
    }


    @Override
    public String toString() {
        int totalPrice = 0;
        String output = "";
        for (Car car : carList) {
            output += car;
            totalPrice += car.getFinalPrice();
        }
        for (Motorbike motorbike : motoList) {
            output += motorbike;
            totalPrice += motorbike.getFinalPrice();
        }
        output += "TOTAL : " + (carList.size() + motoList.size()) + " Vehicles including ";
        int doub = 0;
        if (carList.size() > 0) {
            output += carList.size() + " Cars";
            doub++;
        }
        if (motoList.size() > 0) {
            if (doub > 0) {
                output += " and ";
            }
            output += motoList.size() + " Motorbikes";
        }
        output += " having a total price of " + totalPrice + " TL";
        return output;
    }

}
