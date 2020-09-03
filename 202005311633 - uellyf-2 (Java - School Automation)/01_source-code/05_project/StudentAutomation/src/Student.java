
import java.util.ArrayList;

public class Student extends Person {

    private ArrayList<Student> studentList;
    private int studentNo;
    private int entranceYear;

    public Student(int studentNo, String nameSurname, int age, int entranceYear) {
        super(nameSurname, age);
        this.studentNo = studentNo;
        this.entranceYear = entranceYear;
    }

    public Student(int studentNo, String nameSurname, int entranceYear) {
        super(nameSurname);
        this.studentNo = studentNo;
        this.entranceYear = entranceYear;
    }

    public void getStudentInfo() {
        System.out.println("Student Info  : " + studentNo);
        System.out.println("**************************************");
        System.out.println("Name Surname  : " + super.getNameSurname());
        System.out.println("Age           : " + super.getAge());
        System.out.println("Entrance Year : " + entranceYear);
    }

    public ArrayList<Student> getStudentList() {
        return studentList;
    }

    public void setStudentList(ArrayList<Student> studentList) {
        this.studentList = studentList;
    }

    public int getStudentNo() {
        return studentNo;
    }

    public void setStudentNo(int studentNo) {
        this.studentNo = studentNo;
    }

    public int getEntranceYear() {
        return entranceYear;
    }

    public void setEntranceYear(int entranceYear) {
        this.entranceYear = entranceYear;
    }

    public void getStudents() {
        for (Student student : studentList) {
            student.getStudentInfo();
        }
    }

    public void removeStudent(int studentNo) {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList.get(i).getStudentNo() == studentNo) {
                studentList.remove(i);
                return;
            }
        }
        return;
    }

    @Override
    public String toString() {
        return studentNo + " - " + super.getNameSurname();
    }

}
