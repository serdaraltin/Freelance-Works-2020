
public class Academician extends Personnel {
    private double baseSalary = 2600;
    private int addCourseFee = 0;
    private int overWorkSalary = 0;

    public Academician(String name, String surname, String registerNumber, String position, int yearOfStart, int addCourseFee,int overWorkSalary) {
        super(name, surname, registerNumber, position, yearOfStart);
        this.addCourseFee = addCourseFee;
        this.overWorkSalary = overWorkSalary;
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }

    public int getAddCourseFee() {
        return addCourseFee;
    }

    public void setAddCourseFee(int addCourseFee) {
        this.addCourseFee = addCourseFee;
    }

    public int getOverWorkSalary() {
        this.overWorkSalary *= this.addCourseFee;
        return overWorkSalary;
    }

    public void setOverWorkSalary(int overWorkSalary) {
        this.overWorkSalary = overWorkSalary;
    }

    @Override
    public String toString() {
        return "Academician{" + "baseSalary=" + baseSalary + ", addCourseFee=" + addCourseFee + ", overWorkSalary=" + overWorkSalary + '}';
    }
    
    
}
