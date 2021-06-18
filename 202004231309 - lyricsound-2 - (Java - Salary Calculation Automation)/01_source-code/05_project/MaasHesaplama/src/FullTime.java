
public class FullTime extends Employee {
    private int dayOfWork;
    private int overWorkSalary;
    private double totalSalary;

    public FullTime(Personnel personnel, int dayOfWork, int overWorkSalary) {
        super(personnel.getName(), personnel.getSurname(), personnel.getRegisterNumber(),
                personnel.getPosition(), personnel.getYearOfStart());
        this.dayOfWork = dayOfWork;
        this.overWorkSalary = overWorkSalary;
    }

    public int getDayOfWork() {
        return dayOfWork;
    }

    public void setDayOfWork(int dayOfWork) {
        this.dayOfWork = dayOfWork;
    }

    public double getTotalSalary() {
        this.totalSalary = dayOfWork * 20;
        int daySalary = 15;
        if(super.getPosition().equals("WORKER"))
            daySalary = 11;
        this.totalSalary += overWorkSalary * daySalary;
        return totalSalary;
    }

    public void setTotalSalary(double totalSalary) {
        this.totalSalary = totalSalary;
    }

    public int getOverWorkSalary() {
        return overWorkSalary;
    }

    public void setOverWorkSalary(int overWorkSalary) {
        this.overWorkSalary = overWorkSalary;
    }

    @Override
    public String toString() {
        return "FullTime{" + "dayOfWork=" + dayOfWork + ", baseSalary=" + totalSalary + ", overWorkSalary=" + overWorkSalary + '}';
    }

}
