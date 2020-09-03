
import java.util.ArrayList;

public class Knapsack {

    private double capacity;
    private ArrayList<Item> items;

    public Knapsack(double capacity) {
        this.capacity = capacity;
    }

    public double getCapacity() {
        return this.capacity;
    }

    public ArrayList<Item> getItems() {
        return this.items;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    public void setItems(ArrayList<Item> items) {
        items = this.items;
        this.items = items;
    }

    public boolean pushItem(Item item) {
        double kalan = this.capacity;

        for (Item item1 : items) {
            kalan -= item1.getWeight();
        }
        if (kalan < item.getWeight()) {
            return false;
        }
        if (kalan >= item.getWeight()) {
            items.add(item);
            return true;
        }

        return false;
    }

    public double getMaximumValue(ArrayList<Item> newItems) {
        
        
        double maximum = 0;
        for (Item item : items) {
            maximum +=item.getValue();
        }
        return maximum;
    }

    public ArrayList<Item> getMaximalItemSet(ArrayList<Item> newItems) {
        return this.items;
    }

}
