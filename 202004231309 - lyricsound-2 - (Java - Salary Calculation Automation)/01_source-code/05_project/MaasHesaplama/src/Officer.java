
public class Officer extends Personnel {

    private double baseSalary = 2600;
    private double ssBenefits = 65;
    private double overWorkSalary;
    private double overOfHour = 20;
    private double totalSalary;

    public Officer(Personnel personnel, int overWorkSalary) {
        super(personnel.getName(), personnel.getSurname(), personnel.getRegisterNumber(),
                personnel.getPosition(), personnel.getYearOfStart());
        this.overWorkSalary = overWorkSalary;
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }

    public double getSsBenefit() {
        return ssBenefits;
    }

    public void setSsBenefit(double ssBenefits) {
        this.ssBenefits = ssBenefits;
    }

    public double getOverworksalay() {
        this.overWorkSalary *= overOfHour;
        return overWorkSalary;
    }

    public void setOverworksalay(double overWorksalayr) {
        this.overWorkSalary = overWorksalayr;
    }

    public double getTotalSalary() {
        this.totalSalary = baseSalary + (getBaseSalary() / 100) * ssBenefits;
        this.totalSalary += getOverworksalay();
        return totalSalary;
    }

    public void setTotalSalary(double totalSalary) {
        this.totalSalary = totalSalary;
    }


    public double getSsBenefits() {
        return ssBenefits;
    }

    public void setSsBenefits(double ssBenefits) {
        this.ssBenefits = ssBenefits;
    }

    public double getOverWorkSalary() {
        return overWorkSalary;
    }

    public void setOverWorkSalary(double overWorkSalary) {
        this.overWorkSalary = overWorkSalary;
    }

    public double getOverOfHour() {
        return overOfHour;
    }

    public void setOverOfHour(double overOfHour) {
        this.overOfHour = overOfHour;
    }

    @Override
    public String toString() {
        return "Officer{" + "baseSalary=" + baseSalary + ", ssBenefits=" + ssBenefits + ", overWorkSalary=" + overWorkSalary + ", overOfHour=" + overOfHour + ", totalSalary=" + totalSalary + '}';
    }

    
}
