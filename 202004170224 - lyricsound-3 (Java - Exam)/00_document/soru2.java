
import java.util.ArrayList;
class takim {
    private String ad;
    private boolean defance;

    public String getAd() {
        return ad;
    }

    public void setAd(String ad) {
        this.ad = ad;
    }

    public boolean isDefance() {
        return defance;
    }

    public void setDefance(boolean defance) {
        this.defance = defance;
    }
}
public class takimlar {

    public static void main(String[] args) {
        ArrayList<takim> takimlar = new ArrayList<takim>(10);
        for (int i = 0; i < 10; i++) {
            takim t = new takim();
            t.setAd(Character.getName(i));
            if (i % 2 == 0) {
                t.setDefance(true);
            } else {
                t.setDefance(false);
            }
            takimlar.add(t);
        }
    }
}
