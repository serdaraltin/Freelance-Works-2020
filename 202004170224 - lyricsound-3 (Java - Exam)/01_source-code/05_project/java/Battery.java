
public class Battery {
    private int mAH;
    private boolean fastRecharge;
    private String type;

    public Battery(int mAH, boolean fastRecharge, String type) {
        this.mAH = mAH;
        this.fastRecharge = fastRecharge;
        this.type = type;
    }
    

    

    public int getmAH() {
        return mAH;
    }

    public void setmAH(int mAH) {
        this.mAH = mAH;
    }

    public boolean isFastRecharge() {
        return fastRecharge;
    }

    public void setFastRecharge(boolean fastRecharge) {
        this.fastRecharge = fastRecharge;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    
}

public class LiONBattery extends Battery {

    public LiONBattery(int mAH, boolean fastRecharge) {
        super(mAH, fastRecharge,"lion");
    }

}


public class NiMHBattery extends Battery {
    public NiMHBattery(int mAH, boolean fastRecharge) {
        super(mAH, fastRecharge,"nimh");
    }
}
