
public class Sivic extends Car {

    public Sivic() {
        super.setPrice(50000);
    }

    @Override
    public String toString() {
        int doub = 0;

        String output = "Sivic";
        if (super.isAbs() || super.isMusicSystem() || super.isAirBag() || super.isSunRoof()) {
            output += " with";
        }
        if (super.isAbs()) {
            output += " ABS";
            doub++;
        }
        if (super.isMusicSystem()) {
            if (doub > 0) {
                output += ", Music System";
            } else {
                output += " Music System";
            }
            doub++;
        }
        if (super.isAirBag()) {
            if (doub > 0) {
                output += ", AirBag optional";
            } else {
                output += " AirBag optional";
            }
            doub++;
        }
        if (super.isSunRoof()) {
            if (doub > 0) {
                output += ", SunRoof";
            } else {
                output += " SunRoof";
            }

            doub++;
        }
        output += " having a total price of " + super.getFinalPrice() + " TL\n";
        return output;
    }
}
