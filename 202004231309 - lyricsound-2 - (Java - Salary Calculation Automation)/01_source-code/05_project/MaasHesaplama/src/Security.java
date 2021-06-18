public class Security extends Personnel {

    private int hourOfWork;
    private int foodMoney = 10;
    private int transMoney = 5;
    private double totalSalary;
    public Security(Personnel personnel, int hourOfWork) {
        super(personnel.getName(), personnel.getSurname(), personnel.getRegisterNumber(), personnel.getPosition(), personnel.getYearOfStart());
        this.hourOfWork = hourOfWork;
    }

    public int getHourOfWork() {
        return hourOfWork;
    }

    public void setHourOfWork(int hourOfWork) {
        this.hourOfWork = hourOfWork;
    }

    public int getFoodMoney() {
        return foodMoney;
    }

    public void setFoodMoney(int foodMoney) {
        this.foodMoney = foodMoney;
    }

    public int getTransMoney() {
        return transMoney;
    }

    public void setTransMoney(int transMoney) {
        this.transMoney = transMoney;
    }

    public double getTotalSalary() {
        totalSalary = this.hourOfWork*10;
        totalSalary += foodMoney*24;
        totalSalary += transMoney*24;
        return totalSalary;
    }

    public void setTotalSalary(double totalSalary) {
        this.totalSalary = totalSalary;
    }

    @Override
    public String toString() {
        return "Security{" + "hourOfWork=" + hourOfWork + ", foodMoney=" + foodMoney + ", transMoney=" + transMoney + ", totalSalary=" + totalSalary + '}';
    }

    
}
