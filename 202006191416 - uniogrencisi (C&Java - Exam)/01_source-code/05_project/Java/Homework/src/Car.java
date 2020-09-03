class Car {
    private int price;
    private int finalPrice;
    private boolean airBag;
    private boolean musicSystem;
    private boolean abs;
    private boolean sunRoof;
    

    public boolean isAirBag() {
        return airBag;
    }

    public void setAirBag(boolean airBag) {
        this.airBag = airBag;
    }

    public boolean isMusicSystem() {
        return musicSystem;
    }

    public void setMusicSystem(boolean musicSystem) {
        this.musicSystem = musicSystem;
    }

    public boolean isAbs() {
        return abs;
    }

    public void setAbs(boolean abs) {
        this.abs = abs;
    }

    public boolean isSunRoof() {
        return sunRoof;
    }

    public void setSunRoof(boolean sunRoof) {
        this.sunRoof = sunRoof;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getFinalPrice() {
        finalPrice = price;
        if(abs)
            finalPrice += 5000;
        if(musicSystem)
            finalPrice += 1000;
        if(airBag)
            finalPrice += 3000;
        if(sunRoof)
            finalPrice += 2000;
        return finalPrice;
    }

    public void setFinalPrice(int finalPrice) {
        this.finalPrice = finalPrice;
    }

    public Car(int price, int finalPrice, boolean airBag, boolean musicSystem, boolean abs, boolean sunRoof) {
        this.price = price;
        this.finalPrice = finalPrice;
        this.airBag = airBag;
        this.musicSystem = musicSystem;
        this.abs = abs;
        this.sunRoof = sunRoof;
    }

    public Car() {
    }

     

    
}
