public class ResearchAssistans extends Academician {

    private double ssBenefits = 105;
    private double totalSalary;

    public ResearchAssistans(Personnel personnel, int addCourseFee, int overWorkSalary) {
        super(personnel.getName(), personnel.getSurname(), personnel.getRegisterNumber(),
                personnel.getPosition(), personnel.getYearOfStart(), addCourseFee, overWorkSalary);
    }

    public double getSsBenefits() {
        return ssBenefits;
    }

    public void setSsBenefits(double ssBenefits) {
        this.ssBenefits = ssBenefits;
    }

    public double getTotalSalary() {
        this.totalSalary = super.getBaseSalary() + (super.getBaseSalary() / 100) * ssBenefits;
        this.totalSalary += super.getOverWorkSalary();
        return totalSalary;
    }

    public void setTotalSalary(double totalSalary) {
        this.totalSalary = totalSalary;
    }

    @Override
    public String toString() {
        return "ResearchAssistans{" + "ssBenefits=" + ssBenefits + ", totalSalary=" + totalSalary + '}';
    }

}
