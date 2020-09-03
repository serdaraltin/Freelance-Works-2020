
public class Car extends Vehicle {

    String Color;
    String Make;
    private int Motor;
    String CMaterial;

    public void SetMotorPower(int motor) {
        this.Motor = motor;
    }

    public int GetMotorPower() {
        return this.Motor;
    }

    public Car(String Color, String Make, int Motor, String CMaterial, int Weight, double Height) {
        super(Weight, Height);
        this.Color = Color;
        this.Make = Make;
        this.Motor = Motor;
        this.CMaterial = CMaterial;
    }

    public Car(String Color, String Make, int Motor, String CMaterial) {
        this.Color = Color;
        this.Make = Make;
        this.Motor = Motor;
        this.CMaterial = CMaterial;
    }

    public Car(String Color, String Make, int Motor) {
        this.Color = Color;
        this.Make = Make;
        this.Motor = Motor;
    }

    public Car(int Weight, double Height) {
        super(Weight, Height);
    }

    public Car() {
    }

}
