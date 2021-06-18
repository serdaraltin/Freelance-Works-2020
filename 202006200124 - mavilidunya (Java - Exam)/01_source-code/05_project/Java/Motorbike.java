
class Motorbike {

    private int price;
    private int finalPrice;
    private boolean abs;
    private boolean seatHeating;

    public boolean isAbs() {
        return abs;
    }

    public void setAbs(boolean abs) {
        this.abs = abs;
    }

    public boolean isSeatHeating() {
        return seatHeating;
    }

    public void setSeatHeating(boolean seatHeating) {
        this.seatHeating = seatHeating;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getFinalPrice() {
        finalPrice = price;
        if (abs) {
            finalPrice += 5000;
        }
        if (seatHeating) {
            finalPrice += 2000;
        }
        return finalPrice;
    }

    public void setFinalPrice(int finalPrice) {
        this.finalPrice = finalPrice;
    }

}
