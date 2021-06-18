
import java.util.ArrayList;

public class Instructor extends Person {

    private ArrayList<Instructor> instructorsList;

    
    public Instructor(String nameSurname, int age) {
        super(nameSurname, age);
    }

    public void removeInstructor(int id) {
        instructorsList.remove(id);
        return;
    }

    public void getInstructor() {
        System.out.println("Name Surname : " + super.getNameSurname());
        System.out.println("Age : " + super.getAge());
    }


    public ArrayList<Instructor> getInstructorsList() {
        return instructorsList;
    }

    public void setInstructorsList(ArrayList<Instructor> instructorsList) {
        this.instructorsList = instructorsList;
    }

    @Override
    public String toString() {
        return "Name Surname : " + super.getNameSurname() + "\nAge : " + super.getAge();
    }

}
