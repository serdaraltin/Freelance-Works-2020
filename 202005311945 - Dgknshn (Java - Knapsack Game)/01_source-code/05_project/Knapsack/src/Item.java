
import java.util.ArrayList;
import java.util.Collections;

public class Item<E> implements Comparable {

    private double value;
    private double weight;

    public Item(double value, double weight) {
        this.value = value;
        this.weight = weight;
    }

    public ArrayList<Item> sort(ArrayList<Item> itemL) {
        Collections.sort(itemL);
        return itemL;
    }

    @Override
    public int compareTo(Object o) {
        Item item = (Item)o;
        if(this.getValue() < item.getValue())
            return -1;
        
        if(this.getValue() > item.getValue())
            return 1;
        if(this.getValue() == item.getValue())
        {
            if(this.getWeight() > item.getWeight()){
                return -1;
            }
             if(this.getWeight() < item.getWeight()){
                return 1;
            }
        }
        return 0;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

}
