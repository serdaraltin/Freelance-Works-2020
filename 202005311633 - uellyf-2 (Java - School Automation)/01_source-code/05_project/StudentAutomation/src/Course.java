
import java.util.ArrayList;

public class Course {

    private ArrayList<Course> courseList;
    private String courseName;
    private Instructor instructor;
    private int courseCode;
    private int numberOfStudents;
    private ArrayList<Integer> participants;
    

    public Course(String courseName, int courseCode, Instructor instructor) {
        this.courseName = courseName;
        this.instructor = instructor;
        this.courseCode = courseCode;
    }

    public Course(String courseName, int courseCode) {
        this.courseName = courseName;
        this.courseCode = courseCode;
    }

    public void addStudent(int studentNo) {
        participants.add(studentNo);
    }

    public void dropStudent(int studentNo) {
        for (int i = 0; i < participants.size(); i++) {
            if (participants.get(i) == studentNo) {
                participants.remove(i);
                return;
            }
        }
        return;
    }

    public void getStudents() {

    }

    public void getCourses() {
        for (Course course : courseList) {
            System.out.println("----------------------------------------");
            System.out.println(course.toString());
            System.out.println(course.getInstructor().getNameSurname());
            System.out.println("----------------------------------------");
        }
    }

    public void removeCourse(int courseCode) {
        for (int i = 0; i < courseList.size(); i++) {
            if (courseList.get(i).courseCode == courseCode) {
                courseList.remove(i);
                return;
            }
        }
        return;
    }

    public ArrayList<Course> getCourseList() {
        return courseList;
    }

    public void setCourseList(ArrayList<Course> courseList) {
        this.courseList = courseList;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public Instructor getInstructor() {
        return instructor;
    }

    public void setInstructor(Instructor instructor) {
        this.instructor = instructor;
    }

    public int getCourseCode() {
        return courseCode;
    }

    public void setCourseCode(int courseCode) {
        this.courseCode = courseCode;
    }

    public int getNumberOfStudents() {
        return numberOfStudents;
    }

    public void setNumberOfStudents(int numberOfStudents) {
        this.numberOfStudents = numberOfStudents;
    }

    @Override
    public String toString() {
        return "courseName : " + courseName + "\n courseCode : " + courseCode + "\n numberOfStudents : " + numberOfStudents;
    }

    public ArrayList<Integer> getParticipants() {
        return participants;
    }

    public void setParticipants(ArrayList<Integer> participants) {
        this.participants = participants;
    }

    
}
