


public class Monitor {
    private String registerNumber;
    private int week1,week2,week3,week4;

    public Monitor(String registerNumber, int week1, int week2, int week3, int week4) {
        this.registerNumber = registerNumber;
        this.week1 = week1;
        this.week2 = week2;
        this.week3 = week3;
        this.week4 = week4;
    }


    @Override
    public String toString() {
        return registerNumber + "\t" + week1 + "\t" + week2 + "\t" + week3 + "\t" + week4;
    }

    public String getRegisterNumber() {
        return registerNumber;
    }

    public void setRegisterNumber(String registerNumber) {
        this.registerNumber = registerNumber;
    }

    public int getWeek1() {
        return week1;
    }

    public void setWeek1(int week1) {
        this.week1 = week1;
    }

    public int getWeek2() {
        return week2;
    }

    public void setWeek2(int week2) {
        this.week2 = week2;
    }

    public int getWeek3() {
        return week3;
    }

    public void setWeek3(int week3) {
        this.week3 = week3;
    }

    public int getWeek4() {
        return week4;
    }

    public void setWeek4(int week4) {
        this.week4 = week4;
    }
    
    
}
