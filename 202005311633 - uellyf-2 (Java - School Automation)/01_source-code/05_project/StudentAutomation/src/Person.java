
public class Person {
    private String nameSurname;
    private int age;

    public String getNameSurname() {
        return nameSurname;
    }

    public void setNameSurname(String nameSurname) {
        this.nameSurname = nameSurname;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Person(String nameSurname, int age) {
        this.nameSurname = nameSurname;
        this.age = age;
    }

    public Person(String nameSurname) {
        this.nameSurname = nameSurname;
    }
    
    
}
