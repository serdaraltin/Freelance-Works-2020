/*****************************************
 * RandomNumberGenerator.h               *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/

#include "Circle.h"             //To declare a function that is able to return Circle object (or its adrres).

class RandomNumberGenerator
{
//Public members are accessible from anywhere where the object is visible.
public:
    
    //Enums are used to don't define constans for each parameter.
    //  The idea is that instead of using an int to represent a set of values,
    //  a type(enum) with a restricted set of values in used instead.
    //If we didn't define enums we must define " const int ONE=1; " or " const int TWO=2 "
    // *** it can be integer value respectively 1,2,3,4 ***
    enum Precision { ONE, TWO, THREE, FOUR };
    enum CharacterType { UPPER_LETTER, LOWER_LETTER, DIGIT };
    
    //Constructor function of RandomNumberGenerator class, when a new object is created, it will be called.
    RandomNumberGenerator();
    
    //A virtual function or virtual method is a function whose behavior can be overridden
    //within an inheriting class by a function with the same signature.
    //Destructor function of RandomNumberGenerator class, when object is removed, it will be called.
    virtual ~RandomNumberGenerator();

//Those are member functions. They can call from an object that is created from RandomNumberGenerator class.
    
    //Generates integer number randomly between lowerBound and upperBound.
    int getRandomInteger(int lowerBound, int upperBound);
    
    //Generates float number randomly between lowerBound and upperBound
    //and its fractional part is defined by precision (it can be integer value respectively 1,2,3,4).
    float getRandomFloat(float lowerBound, float upperBound, Precision precision);
    
    //Generates double number randomly between lowerBound and upperBound
    //and its fractional part is defined by precision (it can be integer value respectively 1,2,3,4).
    double getRandomDouble(double lowerBound, double upperBound, Precision precision);
    
    //Generates a character randomly intended character type (it is defined by CharacterType enum).
    char getRandomCharacter(CharacterType characterType);
    
    //Generates a circle whose radius will be between given parameters minRadius and maxRadius
    //and its fractional part is defined by precision (it can be integer value respectively 1,2,3,4).
    Circle getRandomCircle(float minRadius, float maxRadius, Precision precision);
};
