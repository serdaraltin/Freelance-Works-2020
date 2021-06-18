

public class PartTime extends Employee {
    private int hourOfWork;
    private double totalSalary;

    public PartTime(Personnel personnel,int hourOfWork ) {
        super(personnel.getName(), personnel.getSurname(), personnel.getRegisterNumber(),
                personnel.getPosition(), personnel.getYearOfStart());
        this.hourOfWork = hourOfWork;
    }

    public int getHourOfWork() {
        return hourOfWork;
    }

    public void setHourOfWork(int hourOfWork) {
        this.hourOfWork = hourOfWork;
    }

    public double getTotalSalary() {
        this.totalSalary = hourOfWork*18;
        return totalSalary;
    }

    public void setTotalSalary(double totalSalary) {
        this.totalSalary = totalSalary;
    }

    @Override
    public String toString() {
        return "PartTime{" + "hourOfWork=" + hourOfWork + ", totalSalary=" + totalSalary + '}';
    }

    
    
}
