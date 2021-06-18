public class Main {

    static ReadFile readFile = new ReadFile();
    static WriteFile writeFile = new WriteFile();
    static Output output;
    static boolean TEST_OUTPUT = true;

    public static void main(String[] args) {
        String filePersonnel = args[0];
        String fileMonitor = args[1];

        for (Personnel personnel : readFile.ReadPersonel(filePersonnel)) {

            Monitor monitor = readFile.ReadMonitor(personnel.getRegisterNumber(),fileMonitor);
            double totalSalary;
            int week1 = monitor.getWeek1();
            int week2 = monitor.getWeek2();
            int week3 = monitor.getWeek3();
            int week4 = monitor.getWeek4();
            int weekTotal;

            switch (personnel.getPosition()) {
                case "FACULTY_MEMBER":
                    weekTotal = weekCalc(week1, week2, week3, week4, 40, 50);
                    FacultyMembers facultyMembers = new FacultyMembers(personnel, weekTotal, 20);
                    totalSalary = facultyMembers.getTotalSalary();
                    totalSalary += facultyMembers.getSeverancePay();
                    output = new Output(personnel, totalSalary);
                    writeFile.WritePersonnel(output);
                    if (TEST_OUTPUT) {
                        System.out.println(output.toString() + "\n");
                    }
                    break;
                case "OFFICER":
                    weekTotal = weekCalc(week1, week2, week3, week4, 40, 50);
                    Officer officer = new Officer(personnel, weekTotal);
                    totalSalary = officer.getTotalSalary();
                    totalSalary += officer.getSeverancePay();
                    output = new Output(personnel, totalSalary);
                    writeFile.WritePersonnel(output);
                    if (TEST_OUTPUT) {
                        System.out.println(output.toString() + "\n");
                    }
                    break;
                case "SECURITY":
                    weekTotal = week1 + week2 + week3 + week4;
                    Security security = new Security(personnel, weekTotal);
                    totalSalary = security.getTotalSalary();
                    totalSalary += security.getSeverancePay();
                    output = new Output(personnel, totalSalary);
                    writeFile.WritePersonnel(output);
                    if (TEST_OUTPUT) {
                        System.out.println(output.toString() + "\n");
                    }
                    break;
                case "CHIEF":
                    weekTotal = weekCalc(week1, week2, week3, week4, 40, 48);
                    FullTime chief = new FullTime(personnel, 125, weekTotal);
                    totalSalary = chief.getTotalSalary();
                    totalSalary += chief.getSeverancePay();
                    output = new Output(personnel, totalSalary);
                    writeFile.WritePersonnel(output);
                    if (TEST_OUTPUT) {
                        System.out.println(output.toString() + "\n");
                    }
                    break;
                case "WORKER":
                    weekTotal = weekCalc(week1, week2, week3, week4, 40, 50);
                    FullTime worker = new FullTime(personnel, 105, weekTotal);
                    totalSalary = worker.getTotalSalary();
                    totalSalary += worker.getSeverancePay();
                    output = new Output(personnel, totalSalary);
                    writeFile.WritePersonnel(output);
                    if (TEST_OUTPUT) {
                        System.out.println(output.toString() + "\n");
                    }
                    break;
                case "PARTTIME_EMPLOYEE":
                    weekTotal = hourCalc(week1, week2, week3, week4, 10, 20);
                    PartTime partTime = new PartTime(personnel, weekTotal);
                    totalSalary = partTime.getTotalSalary();
                    totalSalary += partTime.getSeverancePay();
                    output = new Output(personnel, totalSalary);
                    writeFile.WritePersonnel(output);
                    if (TEST_OUTPUT) {
                        System.out.println(output.toString() + "\n");
                    }
                    break;
            }

        }

    }

    public static int hourCalc(int week1, int week2, int week3, int week4, int standart, int max) {

        if (week1 >= max) {
            week1 = max;
        } else if (week1 < standart) {
            week1 = 0;
        }
        if (week2 >= max) {
            week2 = max;
        } else if (week2 < standart) {
            week2 = 0;
        }
        if (week3 >= max) {
            week3 = max;
        } else if (week3 < standart) {
            week3 = 0;
        }
        if (week4 >= max) {
            week4 = max;
        } else if (week4 < standart) {
            week4 = 0;
        }
        return (week1 + week2 + week3 + week4);
    }

    public static int weekCalc(int week1, int week2, int week3, int week4, int standart, int max) {
        if (week1 >= max) {
            week1 = max;
        }
        if (week2 >= max) {
            week2 = max;
        }
        if (week3 >= max) {
            week3 = max;
        }
        if (week4 >= max) {
            week4 = max;
        }
        return (week1 + week2 + week3 + week4) - (4 * standart);
    }
}
