/*****************************************
 * TestMain.cpp                          *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 7: Inheritence QUIZ        *
 *****************************************/

//Only Derived Classes are included, we don't have the include the header where the base class defined.
//Because, derived classes' header files have already included them, there is no need to do it again.
#include "Dog.h"
#include "Cat.h"
#include "Snake.h"
#include "Crocodile.h"

void TEST_Animal()
{
    cout <<"+-------------+" << endl
    << "| ANIMAL TEST |" << endl
    << "+-------------+" << endl;
    
    
    //animal is created from Animal Class. It should take name and age parameters.
    Animal animal("Mouse",10);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("FARE");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
}

void TEST_Mammal()
{
    cout <<"+-------------+" << endl
    << "| MAMMAL TEST |" << endl
    << "+-------------+" << endl;
    
    //animal is created from Mammal Class. It should take name and age parameters.
    Mammal animal("Dolphin",10);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("DOLPHIN");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //Prints that, animal is breeding.
    animal.Breed();
}

void TEST_Reptile()
{
    cout <<"+--------------+" << endl
    << "| REPTILE TEST |" << endl
    << "+--------------+" << endl;
    
    //animal is created from Reptile Class. It should take name and age parameters.
    Reptile animal("Reptile Crocodile",10);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("REPTILE CROCODILE");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //Prints that animal is ovulating.
    animal.Ovulate();
}

void TEST_Dog()
{
    cout <<"+----------+" << endl
    << "| DOG TEST |" << endl
    << "+----------+" << endl;
    
    //animal is created from Dog Class. It should take name, age and soundLevel parameters.
    Dog animal("Little Dog",10,90);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("LITTLE DOG");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //Prints that animal is barking.
    animal.Bark();
}

void TEST_Cat()
{
    cout <<"+----------+" << endl
    << "| CAT TEST |" << endl
    << "+----------+" << endl;
    
    //animal is created from Cat Class. It should take name, age and soundLevel parameters.
    Cat animal("Panthera Tulliana Pardus",10,90);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("PANTHERA TULLIANA PARDUS");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //Prints that animal is miaowing.
    animal.Miaow();
}

void TEST_Snake()
{
    cout <<"+------------+" << endl
    << "| SNAKE TEST |" << endl
    << "+------------+" << endl;
    
    //animal is created from Snake Class. It should take name, age and soundLevel parameters.
    Snake animal("Black Mamba",10,90);
    
    //animal's name will change as the given parameter.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("BLACK MAMBA");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //Prints that animal is sizzling.
    animal.Sizzle();
}

void TEST_Crocodile()
{
    cout <<"+----------------+" << endl
    << "| CROCODILE TEST |" << endl
    << "+----------------+" << endl;
    
    //animal is created from Crocodile Class. It should take name, age and soundLevel parameters.
    Crocodile animal("Komodo Dragon",10,90);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //animal's name will change as the given parameter.
    animal.setName("KOMODO DRAGON");
    
    //animal's age will change as the given parameter.
    animal.setAge(11);
    
    //animal's name and age will print to console.
    cout<<animal.getName()<<" is "<<animal.getAge()<<" years"<<endl;
    
    //Prints that animal is roaring.
    animal.Roar();
}

int main ()
{
    TEST_Animal();
    TEST_Mammal();
    TEST_Reptile();
    TEST_Dog();
    TEST_Cat();
    TEST_Snake();
    TEST_Crocodile();
    
    
    //Indicates that function ended succesfully.
    return 0;
}//end main ()
