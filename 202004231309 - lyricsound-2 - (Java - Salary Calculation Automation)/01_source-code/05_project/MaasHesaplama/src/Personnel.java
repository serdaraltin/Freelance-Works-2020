

import java.time.Year;

public class Personnel {

    private int year = Year.now().getValue();
    private String name, surname;
    private String registerNumber;
    private String position;
    private int yearOfStart;
    private int severancePay;

    public Personnel(String name, String surname, String registerNumber, String position, int yearOfStart) {
        this.name = name;
        this.surname = surname;
        this.registerNumber = registerNumber;
        this.position = position;
        this.yearOfStart = yearOfStart;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getRegisterNumber() {
        return registerNumber;
    }

    public void setRegisterNumber(String registerNumber) {
        this.registerNumber = registerNumber;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public int getYearOfStart() {
        return yearOfStart;
    }

    public void setYearOfStart(int yearOfStart) {
        this.yearOfStart = yearOfStart;
    }

    public int getSeverancePay() {
        this.severancePay = (int) ((year - yearOfStart) * (20 * 0.8));
        return severancePay;
    }

    public void setSeverancePay(int severancePay) {
        this.severancePay = severancePay;
    }

    @Override
    public String toString() {
        return "Personnel{" + "year=" + year + ", name=" + name + ", surname=" + surname + ", registerNumber=" + registerNumber + ", position=" + position + ", yearOfStart=" + yearOfStart + ", severancePay=" + severancePay + '}';
    }

}
