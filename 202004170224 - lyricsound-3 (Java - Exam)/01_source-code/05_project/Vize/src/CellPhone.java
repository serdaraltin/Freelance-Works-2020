
public class CellPhone {

    private String model;
    private String marka;
    private Battery battery = null;
    private Screen screen = null;

    public CellPhone() {
    }

    public CellPhone(String model, String marka, Battery battery, Screen screen) {
        this.model = model;
        this.marka = marka;
        this.battery = battery;
        this.screen = screen;
    }

    String getInfo() {
        String info="Info: "+marka+" "+model.toUpperCase();
        if(!battery.isFastRecharge())
            info+="[The battery does not support fast recharge ";
                    
        info+="having max "+battery.getmAH()+" mAH - screen has max resolation of "+screen.getResulation()+"px at "+screen.getPpi()+"PPI]";
        return info;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getMarka() {
        return marka;
    }

    public void setMarka(String marka) {

        this.marka = marka;
    }

    public Battery getBattery() {
        return battery;
    }

    public void setBattery(Battery battery) {

        if (marka.toString().equals("Samsung".toString())
                && battery.getType().toString().equals("nimh".toString())) {
            System.out.println("Samsung phone connot have NiMHBattery");
            return;
        }
        this.battery = battery;
    }

    public Screen getScreen() {
        return screen;
    }

    public void setScreen(Screen screen) {

        if (marka.toString().equals("Apple".toString())
                && screen.getType().toString().equals("lcd".toString())) {
            System.out.println("Apple phone connot have LCDScreen");
            return;
        }
        if (marka.toString().equals("Nokia".toString())
                && screen.getType().toString().equals("amoled".toString())) {
            System.out.println("Apple phone connot have AMOLEDScreen");
            return;
        }
        this.screen = screen;
    }

    public boolean Control(){
        if(battery == null && screen == null)
            return false;
        return true;
    }
}
