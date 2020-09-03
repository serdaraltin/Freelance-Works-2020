

public class Output {

    private Personnel personnel;
    private double totalSalary;

    public Output(Personnel personnel, double totalSalary) {
        this.personnel = personnel;
        this.totalSalary = totalSalary;
    }

    public double getTotalSalary() {
        return totalSalary;
    }

    public void setTotalSalary(double totalSalary) {
        this.totalSalary = totalSalary;
    }

    public Personnel getPersonnel() {
        return personnel;
    }

    public void setPersonnel(Personnel personnel) {
        this.personnel = personnel;
    }

    @Override
    public String toString() {
        return "Name : " + personnel.getName()
                + "\nSurname : " + personnel.getSurname()
                + "\nRegistiration Number : " + personnel.getRegisterNumber()
                + "\nPosition : " + personnel.getPosition()
                + "\nYear of Start : " + personnel.getYearOfStart()
                + "\nTotal Salary: " + this.totalSalary + " TL";
    }

}
