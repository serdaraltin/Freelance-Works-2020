
public class Scooter extends Motorbike {

    public Scooter() {
        super.setPrice(20000);
    }

    @Override
    public String toString() {
        int doub = 0;

        String output = "Scooter";
        if (super.isAbs() || super.isSeatHeating()) {
            output += " with";
        }
        if (super.isAbs()) {
            output += " ABS";
            doub++;
        }
        if (super.isSeatHeating()) {
            if (doub > 0) {
                output += ", Set Heating";
            } else {
                output += " Set Heating";
            }
            doub++;
        }

        output += " having a total price of " + super.getFinalPrice() + " TL\n";
        return output;
    }
}
