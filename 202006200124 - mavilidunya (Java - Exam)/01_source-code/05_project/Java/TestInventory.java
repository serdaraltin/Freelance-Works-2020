
public class TestInventory {

    public static void main(String[] args) {
        Inventory inventory = new Inventory();
        
        Car car = new Sivic();
        car.setAbs(true);
        car.setMusicSystem(true);
        car.setAirBag(true);
        inventory.add(car);
        
        car = new Sivic();
        car.setAbs(true);
        car.setSunRoof(true);
        inventory.add(car);
        
        car = new Sity();
        car.setMusicSystem(true);
        car.setSunRoof(true);
        inventory.add(car);
        
        Motorbike mBike = new Racer();
        mBike.setAbs(true);
        mBike.setSeatHeating(true);
        inventory.add(mBike);
        
        mBike = new Scooter();
        mBike.setSeatHeating(true);
        inventory.add(mBike);
        
        System.out.println(inventory);
    }
}
