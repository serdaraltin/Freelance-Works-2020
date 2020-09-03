
public class Screen {
    private int ppi;
    private String resulation;
    private String type;

    public Screen(int ppi, String resulation, String type) {
        this.ppi = ppi;
        this.resulation = resulation;
        this.type = type;
    }


    public String getResulation() {
        return resulation;
    }

    public void setResulation(String resulation) {
        this.resulation = resulation;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getPpi() {
        return ppi;
    }

    public void setPpi(int ppi) {
        this.ppi = ppi;
    }
    
    
}


public class AMOLEDScreen extends Screen {
    public AMOLEDScreen(int dpi, String resulation) {
        super(dpi, resulation, "amoled");
    }
}


public class LCDScreen extends Screen {

    public LCDScreen(int dpi, String resulation) {
        super(dpi, resulation, "lcd");
    }
}
