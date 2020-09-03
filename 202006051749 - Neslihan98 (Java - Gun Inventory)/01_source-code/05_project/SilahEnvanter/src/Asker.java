
import java.util.ArrayList;

public class Asker {

    private String isim;
    private String rutbe;
    private ArrayList<Object> techizat;

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public String getRutbe() {
        return rutbe;
    }

    public void setRutbe(String rutbe) {
        this.rutbe = rutbe;
    }

    public ArrayList<Object> getTechizat() {
        return techizat;
    }

    public void setTechizat(ArrayList<Object> techizat) {
        this.techizat = techizat;
    }

    public Asker(String isim, String rutbe, ArrayList<Object> techizat) {
        this.isim = isim;
        this.rutbe = rutbe;
        this.techizat = techizat;
    }
}
