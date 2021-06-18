
public class TestVehicle {

    public static void main(String[] args) {
        // Create a red Honda with a motor power, 20 use variable name c1 for the object
        Car c1 = new Car("red", "Honda", 20);

        //create c2 object of a car which is 1600 kg and 2-meter-high in type of Vehicle  
        Vehicle c2 = new Car(1600, 2);

        // Create a Truck t1 which can carry “sand”
        Truck t1 = new Truck();
        t1.Material.add("sand");

        //Create t2 object of a truck which carries “gravel” so that it allows you to only print the city and calculate fare but not able to set the capacity
        Truck t2 = new Truck();
        t2.City = "İstanbul";
        t2.Material.add("gravel");

        //print the  registration fee for c2 object. 
        System.out.println("registration fee for c2 : " + c2.RegistrationFee());

        //print the material carried by t1 object
        System.out.println("material carried by t1 : "+t1.Material.get(0));
        
        // assign the weight of t1 object as 3000
        t1.SetWeight(3000);
        
        //print the weight of the t1 object
        System.out.println("weight of the t1 : "+t1.GetWeight());
        
        //print the city information of t2 object 
        System.out.println("city information of t2 : "+t2.City());
    }
}
