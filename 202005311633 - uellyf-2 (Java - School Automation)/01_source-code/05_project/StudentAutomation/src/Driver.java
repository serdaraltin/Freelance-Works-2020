
import java.util.ArrayList;
import java.util.Scanner;

public class Driver {

    static ArrayList<Student> students = new ArrayList<Student>();
    static ArrayList<Course> courses = new ArrayList<Course>();
    static ArrayList<Instructor> instructors = new ArrayList<Instructor>();

    static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println("Student Automation Project (Enter the Coice)");
        System.out.println("********************************************");
        Menu();

    }

    public static void Menu() {

        System.out.println("1. Courses List");
        System.out.println("2. Add/Remove Course");
        System.out.println("3. Course Students (<courseCode>)");
        System.out.println("4. Intructors List");
        System.out.println("5. Add/Remove Instructor");
        System.out.println("6. Students List");
        System.out.println("7. Add/Remove Student");
        System.out.println("8. Student Info (<studentNo>)");
        System.out.println("9. Add/Remove Student to/from the Course");
        System.out.println("Press 0 for exit.\n");

        int choice;

        choice = scn.nextInt();
        switch (choice) {
            case 0:
                System.exit(0);
                break;
            case 1:
                CourseList(); // +
                break;
            case 2:
                AddRemoveCourse(); // +
                break;
            case 3:
                CourseStudents(); // +
                break;
            case 4:
                InstructorsList(); // +
                break;
            case 5:
                AddRemoveInstructor(); // +
                break;
            case 6:
                StudentsList(); // +
                break;
            case 7:
                AddRemoveStudent(); // +
                break;
            case 8:
                StudentInfo(); // +
                break;
            case 9:
                AddRemoveStudentToCourse(); // +
                break;
            default:
                System.out.println("Choice is not true !\nTry again.");
                break;
        }
        System.out.println("\n");
        Menu();
    }

    public static void CourseList() {
        System.out.println("ALL COURSES");
        System.out.println("***********");
        for (Course course : courses) {
            System.out.print(course.getCourseCode() + " - " + course.getCourseName());
            if (course.getInstructor() != null) {
                System.out.print("(" + course.getInstructor().getNameSurname() + ")");
            }

        }
    }

    public static void AddRemoveCourse() {
        System.out.println("Add Course    : add # <courseCode> # <courseName>");
        System.out.println("Add Course    : add # <courseCode> # <courseName> # <instructor ID>");
        System.out.println("Remove Course : remove # <courseCode>");

        System.out.print("Comman [add/remove] : ");
        String command = scn.next();

        if (command.equals("add")) {
            System.out.print("Course Code : ");
            int courseCode = scn.nextInt();

            System.out.print("Course Name : ");
            scn.nextLine();
            String courseName = scn.nextLine();

            System.out.print("Will it be added instructor [Y/N] : ");

            String choice = scn.next();

            int instructorID = -1;
            if (choice.equals("Y")) {
                System.out.print("Instructor ID : ");
                instructorID = scn.nextInt();
            }
            if (instructorID != -1) {
                courses.add(new Course(courseName, courseCode, FindInstructor(instructorID)));
                return;
            }
            courses.add(new Course(courseName, courseCode));
            return;
        } else if (command.equals("remove")) {
            System.out.print("Course Code : ");
            int courseCode = scn.nextInt();
            for (int i = 0; i < courses.size(); i++) {
                if (courses.get(i).getCourseCode() == courseCode) {
                    courses.remove(i);
                    return;
                }
            }
        }

    }

    public static Instructor FindInstructor(int ID) {
        return instructors.get(ID - 1);
    }

    public static void RemoveCourse() {

    }

    public static void CourseStudents() {
        System.out.println("Enter course code : ");
        int courseCode = scn.nextInt();

        for (Course course : courses) {
            if (course.getCourseCode() == courseCode) {
                System.out.println(course.getCourseName());
                System.out.println("*******************************************");
                for (int studentNo : course.getParticipants()) {
                    System.out.println(FindStudent(studentNo).getNameSurname());
                }
                System.out.println("------------------------------------------*");
                System.out.println("Total " + course.getParticipants().size() + " students at this course.");
            }
        }
    }

    public static Student FindStudent(int studentNo) {
        for (Student student : students) {
            if (student.getStudentNo() == studentNo) {
                return student;
            }
        }
        return null;
    }

    public static void InstructorsList() {
        System.out.println("ALL INSTRUCTORS");
        System.out.println("***************");
        System.out.println("ID Name Surname");
        for (int i = 0; i < instructors.size(); i++) {
            System.out.println((i + 1) + " " + instructors.get(i).getNameSurname());
        }
    }

    public static void AddRemoveInstructor() {
        System.out.println("Add Instructor\t  : add # <nameSurname> # <age>");
        System.out.println("Remove Instructor : remove # <instructor ID>");

        System.out.print("Comman [add/remove] : ");
        String command = scn.next();

        if (command.equals("add")) {
            System.out.print("Name : ");
            String nameSurname = scn.next();
            System.out.print("Surnmae : ");
            nameSurname += " " + scn.next();

            System.out.print("Age : ");
            int age = scn.nextInt();

            instructors.add(new Instructor(nameSurname, age));
            return;
        } else if (command.equals("remove")) {
            System.out.print("instructor ID : ");
            int instructorID = scn.nextInt();
            instructors.remove(instructorID - 1);
            return;
        }

    }

    public static void StudentsList() {
        System.out.println("ALL STUDENTS");
        System.out.println("************");

        for (Student student : students) {
            System.out.println(student);
        }
    }

    public static void AddRemoveStudent() {
        System.out.println("Add Student : add # <student number> # <name surname> # <entrance year>");
        System.out.println("Add Student : add # <student number> # <name surname> # <age> # <entrance year>");
        System.out.println("Remove Student : remove # <studentNo>");

        System.out.print("Comman [add/remove] : ");
        String command = scn.next();

        if (command.equals("add")) {

            System.out.print("Student No : ");
            int studenNo = scn.nextInt();

            System.out.print("Name : ");
            String nameSurname = scn.next();
            System.out.print("Surnmae : ");
            nameSurname += " " + scn.next();

            System.out.print("Entrance Year : ");
            int entranceYear = scn.nextInt();

            System.out.print("Will it be added age [Y/N] : ");
            String choice = scn.next();

            int age = -1;
            if (choice.equals("Y")) {
                System.out.print("Age : ");
                age = scn.nextInt();
            }
            if (age != -1) {
                students.add(new Student(studenNo, nameSurname, age, entranceYear));
            } else {
                students.add(new Student(studenNo, nameSurname, entranceYear));
            }

            return;
        } else if (command.equals("remove")) {
            System.out.print("Student No : ");
            int studentNo = scn.nextInt();
            
            for (int i = 0; i < students.size(); i++) {
                if(students.get(i).getStudentNo() == studentNo){
                    students.remove(i);
                    return;
                }
            }
            return;
        }

    }

    public static void StudentInfo() {
        System.out.println("Enter student no : ");
        int studentNo = scn.nextInt();

        for (Student student : students) {
            if (student.getStudentNo() == studentNo) {
                student.getStudentInfo();
                return;
            }
        }
        System.out.println("Not found student");
        return;
    }

    public static void AddRemoveStudentToCourse() {
        System.out.println("Add Student to Course       : add # <student number> # <courseCode>");
        System.out.println("Remove Student from the Course : remove # <student number> # <courseCode>");

        System.out.print("Comman [add/remove] : ");
        String command = scn.next();

        System.out.print("Student No : ");
        int studenNo = scn.nextInt();

        System.out.print("Course Code: ");
        int courseCode = scn.nextInt();

        if (command.equals("add")) {
            for (int i = 0; i < courses.size(); i++) {
                if (courses.get(i).getCourseCode() == courseCode) {
                    courses.get(i).addStudent(studenNo);
                }
            }
        } else if (command.equals("remove")) {
            for (int i = 0; i < courses.size(); i++) {
                if (courses.get(i).getCourseCode() == courseCode) {
                    for (int j = 0; j < courses.get(i).getParticipants().size(); j++) {
                        if (courses.get(i).getParticipants().get(j) == studenNo) {
                            courses.get(i).getParticipants().remove(j);
                            return;
                        }
                    }
                }
            }
        }
    }

}
