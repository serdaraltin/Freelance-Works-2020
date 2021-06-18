
import java.util.ArrayList;

public class Truck extends Vehicle implements Transport,Constraction{
    
    private int Capacity;
    int Year;
    ArrayList<String> Material = new ArrayList<String>();
    String City;

    public Truck(int Capacity, int Year, ArrayList<String> Material, int Weight, double Height) {
        super(Weight, Height);
        this.Capacity = Capacity;
        this.Year = Year;
        this.Material = Material;
    }

    public Truck() {
    }

    public void SetCapacity(int j){
        this.Capacity = j;
    }
    
    public int GetCapacity(){
        return this.Capacity;
    }

    @Override
    public String City() {
        return this.City;
    }

    @Override
    public double Fare() {
        //hangi formülün kullanılacağı belirtilmediğinden 2 değer çarpılmıştır
        return this.Year * this.Capacity;
    }

    @Override
    public ArrayList<String> GetMaterial() {
        return this.Material;
    }

    @Override
    public String Compose() {
        return "Truck{" + "Capacity=" + Capacity + ", Year=" + Year + ", Material=" + Material + ", City=" + City + '}';
    }

}
